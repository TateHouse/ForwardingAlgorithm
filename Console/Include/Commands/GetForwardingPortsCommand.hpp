#pragma once

#include "ICommand.hpp"

namespace Console::Commands
{
/**
 * @class GetForwardingPortsCommand
 *
 * @brief A command for getting the forwarding ports for a collection of IPv4 addresses.
 */
class GetForwardingPortsCommand final : public ICommand
{
public:
	/**
	 * @brief Construct a new GetForwardingPortsCommand instance.
	 *
	 * @param context The shared application context.
	 */
	explicit GetForwardingPortsCommand(Context& context) noexcept;
	GetForwardingPortsCommand(const GetForwardingPortsCommand& other) = default;
	GetForwardingPortsCommand(GetForwardingPortsCommand&& other) noexcept = default;
	~GetForwardingPortsCommand() noexcept override = default;

public:
	GetForwardingPortsCommand& operator=(const GetForwardingPortsCommand& other) = delete;
	GetForwardingPortsCommand& operator=(GetForwardingPortsCommand&& other) noexcept = delete;

public:
	void Execute() override;
	[[nodiscard]] std::string GetName() const noexcept override;
	[[nodiscard]] std::string GetDescription() const noexcept override;
};
}
