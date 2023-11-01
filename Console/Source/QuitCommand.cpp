#include "QuitCommand.hpp"

namespace Console {
QuitCommand::QuitCommand(Context& context) noexcept: Command {context} {

}

void QuitCommand::execute() noexcept {
    context.setIsNotRunning();
}

const std::string QuitCommand::getName() const noexcept {
    return "quit";
}

const std::string QuitCommand::getDescription() const noexcept {
    return "Quits the console application.";
}
}