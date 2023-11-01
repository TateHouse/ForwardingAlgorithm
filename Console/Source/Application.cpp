#include "Application.hpp"

#include <iostream>

namespace Console {
void Application::initialize() noexcept {
    std::cout << "==================================================" << '\n';
    std::cout << "Forwarding Algorithm" << '\n';
    std::cout << "==================================================" << '\n';

    std::cout << "Please enter 'help' for a list of commands." << '\n';
}

void Application::update() noexcept {
    std::cout << "==================================================" << '\n';

    std::cout << "Please enter a command: ";
    std::string input {};
    std::cin >> input;

    if (const auto result {commandRepository.execute(input)}; !result) {
        std::cout << "Invalid command. Please enter 'help' for a list of commands." << '\n';
    }

    std::cout << "==================================================" << '\n';
}

void Application::shutdown() noexcept {
    std::cout << "==================================================" << '\n';
    std::cout << "Shutting down..." << '\n';
    std::cout << "==================================================" << '\n';
}

[[nodiscard]] const bool Application::getIsRunning() const noexcept {
    return context.getIsRunning();
}
}