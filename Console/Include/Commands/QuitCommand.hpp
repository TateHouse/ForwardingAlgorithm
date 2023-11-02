#pragma once

#include "Command.hpp"

namespace Console::Commands {
/**
 * @class QuitCommand
 *
 * @brief A command for quitting the application. It also allows the user to optionally save the forwarded ports to a
 * file before quitting.
 */
class QuitCommand final : public Command {
public:
    /**
     * @brief Construct a new QuitCommand instance.
     *
     * @param context The shared application context.
     */
    explicit QuitCommand(Context& context) noexcept;
    virtual ~QuitCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    [[nodiscard]] virtual const std::string getName() const noexcept override;
    [[nodiscard]] virtual const std::string getDescription() const noexcept override;
};
}