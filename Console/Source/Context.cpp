#include "Context.hpp"

namespace Console {
const bool Context::getIsRunning() const noexcept {
    return isRunning;
}

void Context::setIsNotRunning() noexcept {
    isRunning = false;
}
}