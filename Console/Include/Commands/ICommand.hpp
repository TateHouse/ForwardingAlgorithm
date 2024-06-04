#pragma once

#include <string>

#include "Context.hpp"

namespace Console::Commands
{
/**
 * @class ICommand
 *
 * @brief An interface for commands.
 */
class ICommand
{
public:
	/**
	 * @brief Constructs a Command instance.
	 *
	 * @param context The shared application context.
	 */
	explicit ICommand(Context& context) noexcept;
	ICommand(const ICommand& other) = default;
	ICommand(ICommand&& other) noexcept = default;
	virtual ~ICommand() noexcept = default;

public:
	ICommand& operator=(const ICommand& other) = delete;
	ICommand& operator=(ICommand&& other) noexcept = delete;

public:
	/**
	 * @brief Executes the command.
	 */
	virtual void Execute() = 0;
	[[nodiscard]] virtual std::string GetName() const noexcept = 0;
	[[nodiscard]] virtual std::string GetDescription() const noexcept = 0;

protected:
	Context& context;
};
}
