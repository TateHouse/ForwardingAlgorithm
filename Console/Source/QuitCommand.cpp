#include "QuitCommand.hpp"

#include <iostream>
#include <memory>

#include "TextForwardedPortsWriter.hpp"

namespace Console {
QuitCommand::QuitCommand(Context& context) noexcept: Command {context} {

}

void QuitCommand::execute() noexcept {
    try {
        context.setIsNotRunning();

        std::cout << "Enter the path to the file where the forwarded ports will be saved: ";
        std::string path {};
        std::cin >> path;

        std::unique_ptr<Core::ForwardedPortsWriter> forwardedPortsWriter {
                std::make_unique<Core::TextForwardedPortsWriter>(path, context.getForwardedPorts())};

        forwardedPortsWriter->write();

    } catch (const std::invalid_argument& exception) {
        std::cout << "--------------------------------------------------" << '\n';
        std::cout << exception.what() << '\n';
        std::cout << "--------------------------------------------------" << '\n';
    } catch (const std::filesystem::filesystem_error& exception) {
        std::cout << "--------------------------------------------------" << '\n';
        std::cout << exception.what() << '\n';
        std::cout << "--------------------------------------------------" << '\n';
    }
}

const std::string QuitCommand::getName() const noexcept {
    return "quit";
}

const std::string QuitCommand::getDescription() const noexcept {
    return "Quits the console application.";
}
}