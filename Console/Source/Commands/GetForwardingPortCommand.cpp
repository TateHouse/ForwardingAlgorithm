#include "Commands/GetForwardingPortCommand.hpp"

#include "Utility/StringUtility.hpp"
#include "IPv4.hpp"

namespace Console::Commands {
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
    } catch (const std::invalid_argument& exception) {
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
        std::cout << exception.what() << '\n';
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
    } catch (const std::runtime_error& exception) {
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
        std::cout << exception.what() << '\n';
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
    }
}

const std::string GetForwardingPortCommand::getName() const noexcept {
    return "port";
}

const std::string GetForwardingPortCommand::getDescription() const noexcept {
    return "Gets the port to forward the given IPv4 address to.";
}
}