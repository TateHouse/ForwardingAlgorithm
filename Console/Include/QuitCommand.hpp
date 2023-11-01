#pragma once

#include "Command.hpp"

namespace Console {
class QuitCommand final : public Command {
public:
    explicit QuitCommand(Context& context) noexcept;
    virtual ~QuitCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    virtual const std::string getName() const noexcept override;
    virtual const std::string getDescription() const noexcept override;
};
}