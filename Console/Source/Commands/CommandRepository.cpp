#include "Commands/CommandRepository.hpp"

#include "Commands/GetForwardingPortCommand.hpp"
#include "Commands/GetForwardingPortsCommand.hpp"
#include "Commands/HelpCommand.hpp"
#include "Commands/QuitCommand.hpp"
#include "Commands/LoadRoutingTableCommand.hpp"

namespace Console::Commands
{
CommandRepository::CommandRepository(Context& context) :
	context{context}
{
	auto getForwardingPortCommand{std::make_unique<GetForwardingPortCommand>(context)};
	auto getForwardingPortsCommand{std::make_unique<GetForwardingPortsCommand>(context)};
	auto selectRoutingTableCommand{std::make_unique<LoadRoutingTableCommand>(context)};
	auto quitCommand{std::make_unique<QuitCommand>(context)};

	commands.try_emplace(getForwardingPortCommand->GetName(), std::move(getForwardingPortCommand));
	commands.try_emplace(getForwardingPortsCommand->GetName(), std::move(getForwardingPortsCommand));
	commands.try_emplace(selectRoutingTableCommand->GetName(), std::move(selectRoutingTableCommand));
	commands.try_emplace(quitCommand->GetName(), std::move(quitCommand));

	std::vector<std::reference_wrapper<ICommand>> commandReferences{};
	commandReferences.reserve(commands.size());

	for (const auto& command : commands)
	{
		commandReferences.emplace_back(*command.second);
	}

	auto helpCommand{std::make_unique<HelpCommand>(context, commandReferences)};
	commands.try_emplace(helpCommand->GetName(), std::move(helpCommand));
}

bool CommandRepository::Execute(const std::string_view command) const noexcept
{
	const auto iterator{commands.find(command.data())};

	if (iterator == commands.end())
	{
		return false;
	}

	iterator->second->Execute();

	return true;
}
}
