#pragma once

#include <memory>

#include "Router.hpp"

namespace Console {
class Context final {
public:
    [[nodiscard]] const bool getIsRunning() const noexcept;
    void setIsNotRunning() noexcept;

private:
    bool isRunning {true};
    std::unique_ptr<Core::Router> router {nullptr};
};
}