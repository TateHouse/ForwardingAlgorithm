#pragma once

#include <string>

#include "Context.hpp"

namespace Console {
class Command {
public:
    explicit Command(Context& context) noexcept;
    virtual ~Command() noexcept = default;

public:
    virtual void execute() noexcept = 0;
    virtual const std::string getName() const noexcept = 0;
    virtual const std::string getDescription() const noexcept = 0;

protected:
    Context& context;
};
}