#pragma once

#include "Commands/CommandRepository.hpp"

namespace Console {
class Application final {
public:
    void initialize() noexcept;
    void update() noexcept;
    void shutdown() noexcept;

    [[nodiscard]] const bool getIsRunning() const noexcept;

private:
    Context context {};
    Commands::CommandRepository commandRepository {context};
};
}