#pragma once

#include "Commands/CommandRepository.hpp"

namespace Console {
/**
 * @class Application
 *
 * @brief The console application.
 */
class Application final {
public:
    /**
     * @brief Initializes the application.
     */
    void initialize() noexcept;

    /**
     * @brief Runs the application.
     */
    void update() noexcept;

    /**
     * @brief Shuts down the application.
     */
    void shutdown() noexcept;

    [[nodiscard]] const bool getIsRunning() const noexcept;

private:
    Context context {};
    Commands::CommandRepository commandRepository {context};
};
}