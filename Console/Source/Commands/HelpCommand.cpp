#include "Commands/HelpCommand.hpp"

#include "Utility/StringUtility.hpp"

namespace Console::Commands
{
HelpCommand::HelpCommand(Console::Context& context,
						 const std::vector<std::reference_wrapper<ICommand>>& commands):
	ICommand{context}
{
	this->commands.reserve(commands.size() + 1);
	this->commands.emplace_back(*this);
	this->commands.insert(this->commands.end(), commands.begin(), commands.end());
}

void HelpCommand::Execute() noexcept
{
	std::cout << Core::Utility::StringUtility::GetPrimaryHeaderBar() << '\n';

	for (auto index{0}; index < commands.size(); ++index)
	{
		const auto name{commands[index].get().GetName()};
		const auto description{commands[index].get().GetDescription()};
		std::cout << name << ": " << description << '\n';

		if (index != commands.size() - 1)
		{
			std::cout << '\n';
		}
	}
}

std::string HelpCommand::GetName() const noexcept
{
	return "help";
}

std::string HelpCommand::GetDescription() const noexcept
{
	return "Displays all available commands and their descriptions";
}
}
