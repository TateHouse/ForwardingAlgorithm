#pragma once

#include <memory>

#include "CommandRepository.hpp"
#include "Router.hpp"

namespace Console {
class Application final {
public:
    void initialize() noexcept;
    void update() noexcept;
    void shutdown() noexcept;

    [[nodiscard]] const bool getIsRunning() const noexcept;

    [[nodiscard]] const CommandRepository& getCommandRepository() const noexcept;

private:
    bool isRunning {true};
    CommandRepository commandRepository {};
    std::unique_ptr<Core::Router> router {nullptr};
};
}