#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Command.hpp"
#include "Context.hpp"

namespace Console::Commands {
/**
 * @class CommandRepository
 *
 * @brief The repository of commands.
 */
class CommandRepository final {
public:
    /**
     * @brief Constructs a CommandRepository instance.
     *
     * @param context The shared application context.
     */
    explicit CommandRepository(Context& context);

public:
    /**
     * @brief Executes a command.
     *
     * @param command The command to execute.
     */
    [[nodiscard]] const bool execute(const std::string_view command) const noexcept;

private:
    Context& context;
    std::unordered_map<std::string, std::unique_ptr<Command>> commands {};
};
}