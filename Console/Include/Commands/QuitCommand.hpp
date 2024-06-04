#pragma once

#include "ICommand.hpp"

namespace Console::Commands
{
/**
 * @class QuitCommand
 *
 * @brief A command for quitting the application. It also allows the user to optionally save the forwarded ports to a
 * file before quitting.
 */
class QuitCommand final : public ICommand
{
public:
	/**
	 * @brief Construct a new QuitCommand instance.
	 *
	 * @param context The shared application context.
	 */
	explicit QuitCommand(Context& context) noexcept;
	QuitCommand(const QuitCommand& other) = default;
	QuitCommand(QuitCommand&& other) noexcept = default;
	~QuitCommand() noexcept override = default;

public:
	QuitCommand& operator=(const QuitCommand& other) = delete;
	QuitCommand& operator=(QuitCommand&& other) noexcept = delete;

public:
	void Execute() override;
	[[nodiscard]] std::string GetName() const noexcept override;
	[[nodiscard]] std::string GetDescription() const noexcept override;
};
}
