#pragma once

#include "Command.hpp"

namespace Console::Commands {
class QuitCommand final : public Command {
public:
    explicit QuitCommand(Context& context) noexcept;
    virtual ~QuitCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    [[nodiscard]] virtual const std::string getName() const noexcept override;
    [[nodiscard]] virtual const std::string getDescription() const noexcept override;
};
}