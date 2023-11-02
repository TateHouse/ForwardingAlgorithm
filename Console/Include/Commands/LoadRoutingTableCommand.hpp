#pragma once

#include "Command.hpp"

namespace Console::Commands {
/**
 * @class LoadRoutingTableCommand
 *
 * @brief A command for loading the routing table. If the router already contains a routing table, the router will be
 * reset and a new router will be instantiated with the new routing table.
 */
class LoadRoutingTableCommand final : public Command {
public:
    /**
     * @brief Construct a new LoadRoutingTableCommand instance.
     *
     * @param context The shared application context.
     */
    explicit LoadRoutingTableCommand(Context& context) noexcept;
    virtual ~LoadRoutingTableCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    virtual const std::string getName() const noexcept override;
    virtual const std::string getDescription() const noexcept override;
};
}