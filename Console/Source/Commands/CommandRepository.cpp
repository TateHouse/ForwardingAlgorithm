#include "Commands/CommandRepository.hpp"

#include "Commands/GetForwardingPortCommand.hpp"
#include "Commands/GetForwardingPortsCommand.hpp"
#include "Commands/HelpCommand.hpp"
#include "Commands/QuitCommand.hpp"
#include "Commands/LoadRoutingTableCommand.hpp"

namespace Console::Commands {
CommandRepository::CommandRepository(Context& context) : context {context} {
    auto getForwardingPortCommand {std::make_unique<GetForwardingPortCommand>(context)};
    auto getForwardingPortsCommand {std::make_unique<GetForwardingPortsCommand>(context)};
    auto selectRoutingTableCommand {std::make_unique<LoadRoutingTableCommand>(context)};
    auto quitCommand {std::make_unique<QuitCommand>(context)};

    commands.try_emplace(getForwardingPortCommand->getName(), std::move(getForwardingPortCommand));
    commands.try_emplace(getForwardingPortsCommand->getName(), std::move(getForwardingPortsCommand));
    commands.try_emplace(selectRoutingTableCommand->getName(), std::move(selectRoutingTableCommand));
    commands.try_emplace(quitCommand->getName(), std::move(quitCommand));

    std::vector<std::reference_wrapper<Command>> commandReferences {};
    commandReferences.reserve(commands.size());

    for (const auto& command : commands) {
        commandReferences.emplace_back(*command.second);
    }

    auto helpCommand {std::make_unique<HelpCommand>(context, commandReferences)};
    commands.try_emplace(helpCommand->getName(), std::move(helpCommand));
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