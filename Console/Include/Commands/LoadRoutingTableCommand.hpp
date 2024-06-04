#pragma once

#include "ICommand.hpp"

namespace Console::Commands
{
/**
 * @class LoadRoutingTableCommand
 *
 * @brief A command for loading the routing table. If the router already contains a routing table, the router will be
 * reset and a new router will be instantiated with the new routing table.
 */
class LoadRoutingTableCommand final : public ICommand
{
public:
	/**
	 * @brief Construct a new LoadRoutingTableCommand instance.
	 *
	 * @param context The shared application context.
	 */
	explicit LoadRoutingTableCommand(Context& context) noexcept;
	LoadRoutingTableCommand(const LoadRoutingTableCommand& other) = default;
	LoadRoutingTableCommand(LoadRoutingTableCommand&& other) noexcept = default;
	~LoadRoutingTableCommand() noexcept override = default;

public:
	LoadRoutingTableCommand& operator=(const LoadRoutingTableCommand& other) = delete;
	LoadRoutingTableCommand& operator=(LoadRoutingTableCommand&& other) noexcept = delete;

public:
	void Execute() override;
	[[nodiscard]] std::string GetName() const noexcept override;
	[[nodiscard]] std::string GetDescription() const noexcept override;
};
}
