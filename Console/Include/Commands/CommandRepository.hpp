#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Command.hpp"
#include "Context.hpp"

namespace Console::Commands {
class CommandRepository final {
public:
    explicit CommandRepository(Context& context);

public:
    [[nodiscard]] const bool execute(const std::string_view command) const noexcept;

private:
    Context& context;
    std::unordered_map<std::string, std::unique_ptr<Command>> commands {};
};
}