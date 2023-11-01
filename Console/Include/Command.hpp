#pragma once

#include <string>

namespace Console {
class Command {
public:
    virtual ~Command() noexcept = default;

public:
    virtual void execute() noexcept = 0;
    virtual std::string getName() const noexcept = 0;
    virtual std::string getDescription() const noexcept = 0;
};
}