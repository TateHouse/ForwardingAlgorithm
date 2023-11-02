#pragma once

#include "Command.hpp"

namespace Console::Commands {
/**
 * @class GetForwardingPortsCommand
 *
 * @brief A command for getting the forwarding ports for a collection of IPv4 addresses.
 */
class GetForwardingPortsCommand final : public Command {
public:
    /**
     * @brief Construct a new GetForwardingPortsCommand instance.
     *
     * @param context The shared application context.
     */
    explicit GetForwardingPortsCommand(Context& context) noexcept;
    virtual ~GetForwardingPortsCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    [[nodiscard]] virtual const std::string getName() const noexcept override;
    [[nodiscard]] virtual const std::string getDescription() const noexcept override;
};
}