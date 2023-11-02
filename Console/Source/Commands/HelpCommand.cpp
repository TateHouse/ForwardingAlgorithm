#include "Commands/HelpCommand.hpp"

namespace Console::Commands {
HelpCommand::HelpCommand(Console::Context& context,
                         const std::vector<std::reference_wrapper<Command>>& commands) noexcept:
        Command {context} {
    this->commands.reserve(commands.size() + 1);
    this->commands.emplace_back(*this);
    this->commands.insert(this->commands.end(), commands.begin(), commands.end());
}

void HelpCommand::execute() noexcept {
    std::cout << "==================================================" << '\n';

    for (auto index {0}; index < commands.size(); ++index) {
        const auto name {commands[index].get().getName()};
        const auto description {commands[index].get().getDescription()};
        std::cout << name << ": " << description << '\n';

        if (index != commands.size() - 1) {
            std::cout << '\n';
        }
    }
}

const std::string HelpCommand::getName() const noexcept {
    return "help";
}

const std::string HelpCommand::getDescription() const noexcept {
    return "Displays all available commands and their descriptions";
}
}