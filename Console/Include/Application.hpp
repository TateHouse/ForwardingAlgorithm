#pragma once

#include <memory>

#include "CommandRepository.hpp"

namespace Console {
class Application final {
public:
    void initialize() noexcept;
    void update() noexcept;
    void shutdown() noexcept;

    [[nodiscard]] const bool getIsRunning() const noexcept;

private:
    Context context {};
    CommandRepository commandRepository {context};
};
}