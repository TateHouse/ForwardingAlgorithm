#include "Context.hpp"

namespace Console {
const bool Context::getIsRunning() const noexcept {
    return isRunning;
}

void Context::setIsNotRunning() noexcept {
    isRunning = false;
}

const std::unique_ptr<Core::Router>& Context::getRouter() const noexcept {
    return router;
}

void Context::setRouter(const Core::RoutingTableLoader& routingTableLoader) noexcept {
    router = std::make_unique<Core::Router>(routingTableLoader);
}
}