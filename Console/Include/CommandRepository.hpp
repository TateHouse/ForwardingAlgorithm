#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Command.hpp"

namespace Console {
class CommandRepository final {
public:
    CommandRepository();

public:
    [[nodiscard]] const bool execute(const std::string_view command) const noexcept;

private:
    std::unordered_map<std::string, std::unique_ptr<Command>> commands {};
};
}