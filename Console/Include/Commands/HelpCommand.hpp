#pragma once

#include <vector>

#include "Command.hpp"

namespace Console::Commands {
class HelpCommand final : public Command {
public:
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