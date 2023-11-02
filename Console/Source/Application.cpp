#include "Application.hpp"

#include <iostream>

#include "Utility/StringUtility.hpp"

namespace Console {
void Application::initialize() noexcept {
    std::cout << Core::Utility::StringUtility::getHeaderBar() << '\n';
    std::cout << "Forwarding Algorithm" << '\n';
    std::cout << Core::Utility::StringUtility::getHeaderBar() << '\n';
    std::cout << "Please enter 'help' for a list of commands." << '\n';
}

void Application::update() noexcept {
    std::cout << Core::Utility::StringUtility::getHeaderBar() << '\n';

    std::cout << "Please enter a command: ";
    std::string input {};
    std::cin >> input;

    if (const auto result {commandRepository.execute(input)}; !result) {
        std::cout << "Invalid command. Please enter 'help' for a list of commands." << '\n';
    }

    std::cout << Core::Utility::StringUtility::getHeaderBar() << '\n';
}

void Application::shutdown() noexcept {
    std::cout << Core::Utility::StringUtility::getHeaderBar() << '\n';
    std::cout << "Shutting down..." << '\n';
    std::cout << Core::Utility::StringUtility::getHeaderBar() << '\n';
}

[[nodiscard]] const bool Application::getIsRunning() const noexcept {
    return context.getIsRunning();
}
}