#pragma once

#include <memory>

#include "Router.hpp"
#include "RoutingTableLoader.hpp"

namespace Console {
class Context final {
public:
    [[nodiscard]] const bool getIsRunning() const noexcept;
    void setIsNotRunning() noexcept;
    [[nodiscard]] const std::unique_ptr<Core::Router>& getRouter() const noexcept;
    void setRouter(const Core::RoutingTableLoader& routingTableLoader) noexcept;

private:
    bool isRunning {true};
    std::unique_ptr<Core::Router> router {nullptr};
};
}