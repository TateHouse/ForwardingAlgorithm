#pragma once

#include "ICommand.hpp"

namespace Console::Commands
{
/**
 * @class GetForwardingPortCommand
 *
 * @brief A command for getting the forwarding port for a single IPv4 address.
 */
class GetForwardingPortCommand final : public ICommand
{
public:
	/**
	 * @brief Construct a new GetForwardingPortCommand instance.
	 *
	 * @param context The shared application context.
	 */
	explicit GetForwardingPortCommand(Context& context) noexcept;
	GetForwardingPortCommand(const GetForwardingPortCommand& other) = default;
	GetForwardingPortCommand(GetForwardingPortCommand&& other) noexcept = default;
	~GetForwardingPortCommand() noexcept override = default;

public:
	GetForwardingPortCommand& operator=(const GetForwardingPortCommand& other) = delete;
	GetForwardingPortCommand& operator=(GetForwardingPortCommand&& other) noexcept = delete;

public:
	void Execute() noexcept override;
	[[nodiscard]] std::string GetName() const noexcept override;
	[[nodiscard]] std::string GetDescription() const noexcept override;
};
}
