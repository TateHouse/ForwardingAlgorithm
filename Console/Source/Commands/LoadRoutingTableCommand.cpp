#include "Commands/LoadRoutingTableCommand.hpp"

#include <memory>

#include "Utility/StringUtility.hpp"
#include "CSVRoutingTableLoader.hpp"

namespace Console::Commands {
LoadRoutingTableCommand::LoadRoutingTableCommand(Console::Context& context) noexcept: Command {context} {

}

void LoadRoutingTableCommand::execute() noexcept {
    try {
        std::cout << "Enter the path to the routing table (must contain .csv extension): ";
        std::string pathInput {};
        std::cin >> pathInput;

        std::cout << "Does the routing table have a header row? (y/n): ";
        std::string hasHeaderRowInput {};
        std::cin >> hasHeaderRowInput;

        std::cout << Core::Utility::StringUtility::getPrimaryHeaderBar() << '\n';

        while (hasHeaderRowInput != "y" && hasHeaderRowInput != "n") {
            std::cout << "Invalid input. Please enter 'y' or 'n': ";
            std::cin >> hasHeaderRowInput;
        }

        const auto hasHeaderRow {hasHeaderRowInput == "y"};

        const std::unique_ptr<Core::RoutingTableLoader> routingTableLoader {
                std::make_unique<Core::CSVRoutingTableLoader>(pathInput, hasHeaderRow)};

        context.setRouter(*routingTableLoader);

        std::cout << "Routing table loaded successfully." << '\n';

    } catch (const std::invalid_argument& exception) {
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
        std::cout << exception.what() << '\n';
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
    } catch (const std::filesystem::filesystem_error& exception) {
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
        std::cout << exception.what() << '\n';
        std::cout << Core::Utility::StringUtility::getSecondaryHeaderBar() << '\n';
    }
}

const std::string LoadRoutingTableCommand::getName() const noexcept {
    return "load";
}

const std::string LoadRoutingTableCommand::getDescription() const noexcept {
    return "Loads a routing table into the router. If a router already exists, it will be replaced.";
}
}