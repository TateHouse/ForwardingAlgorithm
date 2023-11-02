#pragma once

#include "Command.hpp"

namespace Console::Commands {
/**
 * @class GetForwardingPortCommand
 *
 * @brief A command for getting the forwarding port for a single IPv4 address.
 */
class GetForwardingPortCommand final : public Command {
public:
    /**
     * @brief Construct a new GetForwardingPortCommand instance.
     *
     * @param context The shared application context.
     */
    explicit GetForwardingPortCommand(Context& context) noexcept;
    virtual ~GetForwardingPortCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    [[nodiscard]] virtual const std::string getName() const noexcept override;
    [[nodiscard]] virtual const std::string getDescription() const noexcept override;
};
}