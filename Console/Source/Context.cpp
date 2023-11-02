#include "Context.hpp"

namespace Console {
const bool Context::getIsRunning() const noexcept {
    return isRunning;
}

void Context::setIsNotRunning() noexcept {
    isRunning = false;
}

const std::unique_ptr<Core::Router>& Context::getRouter() const {
    if (!router) {
        throw std::runtime_error {"The router has not been set"};
    }

    return router;
}

void Context::setRouter(const Core::RoutingTableLoader& routingTableLoader) noexcept {
    router = std::make_unique<Core::Router>(routingTableLoader);
}

void Context::addForwardedPort(const Core::IPv4& ip, const unsigned int port) noexcept {
    routedPorts.emplace_back(ip, port);
}

const std::vector<std::pair<Core::IPv4, unsigned int>>& Context::getForwardedPorts() const noexcept {
    return routedPorts;
}
}
