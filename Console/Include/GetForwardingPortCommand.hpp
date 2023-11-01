#pragma once

#include "Command.hpp"

namespace Console {
class GetForwardingPortCommand : public Command {
public:
    explicit GetForwardingPortCommand(Context& context) noexcept;
    virtual ~GetForwardingPortCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    [[nodiscard]] virtual const std::string getName() const noexcept override;
    [[nodiscard]] virtual const std::string getDescription() const noexcept override;
};
}