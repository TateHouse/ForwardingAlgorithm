#pragma once

#include <string>

#include "Context.hpp"

namespace Console::Commands {
/**
 * @class Command
 *
 * @brief An interface for commands.
 */
class Command {
public:
    /**
     * @brief Constructs a Command instance.
     *
     * @param context The shared application context.
     */
    explicit Command(Context& context) noexcept;
    virtual ~Command() noexcept = default;

public:
    /**
     * @brief Executes the command.
     */
    virtual void execute() noexcept = 0;
    [[nodiscard]] virtual const std::string getName() const noexcept = 0;
    [[nodiscard]] virtual const std::string getDescription() const noexcept = 0;

protected:
    Context& context;
};
}