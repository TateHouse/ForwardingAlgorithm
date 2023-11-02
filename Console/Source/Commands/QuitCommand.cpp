#include "Commands/QuitCommand.hpp"

#include <iostream>
#include <memory>

#include "Utility/StringUtility.hpp"
#include "TextForwardedPortsWriter.hpp"

namespace Console::Commands {
QuitCommand::QuitCommand(Context& context) noexcept: Command {context} {

}

void QuitCommand::execute() noexcept {
    try {
        context.setIsNotRunning();

        std::cout << "Do you want to save the forwarded ports? (y/n): ";
        char answer {};
        std::cin >> answer;

        if (answer != 'y') {
            return;
        }

        std::cout
                << "Enter the path to the file where the forwarded ports will be saved (must contain .txt extension): ";
        std::string path {};
        std::cin >> path;

        std::unique_ptr<Core::ForwardedPortsWriter> forwardedPortsWriter {
                std::make_unique<Core::TextForwardedPortsWriter>(path, context.getForwardedPorts())};

        forwardedPortsWriter->write();

    } catch (const std::invalid_argument& exception) {
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
        std::cout << exception.what() << '\n';
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
    } catch (const std::filesystem::filesystem_error& exception) {
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
        std::cout << exception.what() << '\n';
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
    }
}

const std::string QuitCommand::getName() const noexcept {
    return "quit";
}

const std::string QuitCommand::getDescription() const noexcept {
    return "Quits the console application and allows the user to save the forwarded ports to a file.";
}
}