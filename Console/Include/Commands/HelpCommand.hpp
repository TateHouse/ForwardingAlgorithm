#pragma once

#include <vector>

#include "ICommand.hpp"

namespace Console::Commands
{
/**
 * @class HelpCommand
 *
 * @brief A command for displaying information about all commands.
 */
class HelpCommand final : public ICommand
{
public:
	/**
	 * @brief Construct a new HelpCommand instance.
	 *
	 * @param context The shared application context.
	 * @param commands The commands to display information about.
	 */
	HelpCommand(Context& context, const std::vector<std::reference_wrapper<ICommand>>& commands);
	HelpCommand(const HelpCommand& other) = default;
	HelpCommand(HelpCommand&& other) noexcept = default;
	~HelpCommand() noexcept override = default;

public:
	HelpCommand& operator=(const HelpCommand& other) = delete;
	HelpCommand& operator=(HelpCommand&& other) noexcept = delete;

public:
	void Execute() noexcept override;
	[[nodiscard]] std::string GetName() const noexcept override;
	[[nodiscard]] std::string GetDescription() const noexcept override;

private:
	std::vector<std::reference_wrapper<ICommand>> commands;
};
}
