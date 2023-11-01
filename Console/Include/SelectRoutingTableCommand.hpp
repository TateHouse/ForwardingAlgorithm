#pragma once

#include "Command.hpp"

namespace Console {
class SelectRoutingTableCommand final : public Command {
public:
    explicit SelectRoutingTableCommand(Context& context) noexcept;
    virtual ~SelectRoutingTableCommand() noexcept override = default;

public:
    virtual void execute() noexcept override;
    virtual const std::string getName() const noexcept override;
    virtual const std::string getDescription() const noexcept override;
};
}