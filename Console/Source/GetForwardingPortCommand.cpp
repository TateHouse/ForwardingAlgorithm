#include "GetForwardingPortCommand.hpp"

#include "IPv4.hpp"

namespace Console {
GetForwardingPortCommand::GetForwardingPortCommand(Context& context) noexcept: Command {context} {

}

void GetForwardingPortCommand::execute() noexcept {
    try {
        std::cout << "Enter the IPv4 address to forward: ";
        std::string addressInput {};
        std::cin >> addressInput;

        const Core::IPv4 address {addressInput};
        const auto port {context.getRouter()->getForwardingPort(address)};

        std::cout << "Port: " << port << '\n';
        context.addForwardedPort(address, port);
    } catch (std::invalid_argument& exception) {
        std::cout << "--------------------------------------------------" << '\n';
        std::cout << exception.what() << '\n';
        std::cout << "--------------------------------------------------" << '\n';
    }
}

const std::string GetForwardingPortCommand::getName() const noexcept {
    return "get-forwarding-port";
}

const std::string GetForwardingPortCommand::getDescription() const noexcept {
    return "Gets the port to forward the given IPv4 address to.";
}
}