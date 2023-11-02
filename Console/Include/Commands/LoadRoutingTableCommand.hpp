#pragma once

#include "Command.hpp"

namespace Console::Commands {
class LoadRoutingTableCommand final : public Command {
public:
    explicit LoadRoutingTableCommand(Context& context) noexcept;
    virtual ~LoadRoutingTableCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    virtual const std::string getName() const noexcept override;
    virtual const std::string getDescription() const noexcept override;
};
}