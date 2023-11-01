#include "CommandRepository.hpp"

#include "GetForwardingPortCommand.hpp"
#include "QuitCommand.hpp"
#include "SelectRoutingTableCommand.hpp"

namespace Console {
CommandRepository::CommandRepository(Context& context) : context {context} {
    auto getForwardingPortCommand {std::make_unique<GetForwardingPortCommand>(context)};
    auto selectRoutingTableCommand {std::make_unique<SelectRoutingTableCommand>(context)};
    auto quitCommand {std::make_unique<QuitCommand>(context)};

    commands.try_emplace(getForwardingPortCommand->getName(), std::move(getForwardingPortCommand));
    commands.try_emplace(selectRoutingTableCommand->getName(), std::move(selectRoutingTableCommand));
    commands.try_emplace(quitCommand->getName(), std::move(quitCommand));
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