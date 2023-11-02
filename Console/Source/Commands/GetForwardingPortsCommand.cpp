#include "Commands/GetForwardingPortsCommand.hpp"

#include <algorithm>
#include <random>

#include "IPv4.hpp"
#include "TextIPv4Loader.hpp"

namespace Console::Commands {
GetForwardingPortsCommand::GetForwardingPortsCommand(Context& context) noexcept: Command {context} {

}

void GetForwardingPortsCommand::execute() noexcept {
    try {
        std::cout << "Enter the path to the text file containing the IPv4 addresses to forward: ";
        std::string path {};
        std::cin >> path;

        std::unique_ptr<Core::IPv4Loader> loader {std::make_unique<Core::TextIPv4Loader>(path)};
        auto addresses {loader->load()};

        std::cout << "Do you want to shuffle the addresses loaded from the file? (y/n): ";
        std::string shuffleInput {};
        std::cin >> shuffleInput;

        while (shuffleInput != "y" && shuffleInput != "n") {
            std::cout << "Invalid input. Please enter either y or n: ";
            std::cin >> shuffleInput;
        }

        if (shuffleInput == "y") {
            std::random_device randomDevice {};
            std::mt19937 randomEngine {randomDevice()};
            std::ranges::shuffle(addresses, randomEngine);
        } else {
            std::cout << "The addresses loaded from the file will not be shuffled." << '\n';
        }

        std::vector<unsigned int> ports {};
        for (const auto& address : addresses) {
            const auto port {context.getRouter()->getForwardingPort(address)};
            ports.emplace_back(port);
            context.addForwardedPort(address, port);
        }

        std::cout << "Ports: " << '\n';
        for (const auto& port : ports) {
            std::cout << port << '\n';
        }
    } catch (std::invalid_argument& exception) {
        std::cout << "--------------------------------------------------" << '\n';
        std::cout << exception.what() << '\n';
        std::cout << "--------------------------------------------------" << '\n';
    }
}

const std::string GetForwardingPortsCommand::getName() const noexcept {
    return "ports";
}

const std::string GetForwardingPortsCommand::getDescription() const noexcept {
    return "Gets the ports to forward the given IPv4 addresses from a text file to.";
}
}