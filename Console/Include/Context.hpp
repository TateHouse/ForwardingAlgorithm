#pragma once

#include <memory>
#include <vector>
#include <utility>

#include "IPv4.hpp"
#include "Router.hpp"
#include "RoutingTableLoader.hpp"

namespace Console {
/**
 * @class Context
 *
 * @brief A class that holds the shared state of the application.
 */
class Context final {
public:
    [[nodiscard]] const bool getIsRunning() const noexcept;
    void setIsNotRunning() noexcept;
    [[nodiscard]] const std::unique_ptr<Core::Router>& getRouter() const;
    void setRouter(const Core::RoutingTableLoader& routingTableLoader) noexcept;
    void addForwardedPort(const Core::IPv4& ip, const unsigned int port) noexcept;
    [[nodiscard]] const std::vector<std::pair<Core::IPv4, unsigned int>>& getForwardedPorts() const noexcept;

private:
    bool isRunning {true};
    std::unique_ptr<Core::Router> router {nullptr};
    std::vector<std::pair<Core::IPv4, unsigned int>> routedPorts {};
};
}