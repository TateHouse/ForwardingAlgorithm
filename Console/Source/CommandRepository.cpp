#include "CommandRepository.hpp"

#include "QuitCommand.hpp"

namespace Console {
CommandRepository::CommandRepository(Context& context) : context {context} {
    commands.emplace("quit", std::make_unique<QuitCommand>(context));
}

const bool CommandRepository::execute(const std::string_view command) const noexcept {
    const auto iterator {commands.find(command.data())};

    if (iterator == commands.end()) {
        return false;
    }

    iterator->second->execute();

    return true;
}
}