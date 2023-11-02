#pragma once

#include <vector>

#include "Command.hpp"

namespace Console::Commands {
/**
 * @class HelpCommand
 *
 * @brief A command for displaying information about all commands.
 */
class HelpCommand final : public Command {
public:
    /**
     * @brief Construct a new HelpCommand instance.
     *
     * @param context The shared application context.
     * @param commands The commands to display information about.
     */
    HelpCommand(Context& context, const std::vector<std::reference_wrapper<Command>>& commands) noexcept;
    virtual ~HelpCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    [[nodiscard]] virtual const std::string getName() const noexcept override;
    [[nodiscard]] virtual const std::string getDescription() const noexcept override;

private:
    std::vector<std::reference_wrapper<Command>> commands;
};
}