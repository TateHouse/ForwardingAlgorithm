#pragma once

#include "Command.hpp"

namespace Console {
class GetForwardingPortsCommand final : public Command {
public:
    explicit GetForwardingPortsCommand(Context& context) noexcept;
    virtual ~GetForwardingPortsCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    [[nodiscard]] virtual const std::string getName() const noexcept override;
    [[nodiscard]] virtual const std::string getDescription() const noexcept override;
};
}