#include "Commands/SelectRoutingTableCommand.hpp"

#include <memory>

#include "CSVRoutingTableLoader.hpp"

namespace Console::Commands {
SelectRoutingTableCommand::SelectRoutingTableCommand(Console::Context& context) noexcept: Command {context} {

}

void SelectRoutingTableCommand::execute() noexcept {
    try {
        std::cout << "Enter the path to the routing table: ";
        std::string pathInput {};
        std::cin >> pathInput;

        std::cout << "Does the routing table have a header row? (y/n): ";
        std::string hasHeaderRowInput {};
        std::cin >> hasHeaderRowInput;

        std::cout << "==================================================" << '\n';

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
        std::cout << "--------------------------------------------------" << '\n';
        std::cout << exception.what() << '\n';
        std::cout << "--------------------------------------------------" << '\n';
    } catch (const std::filesystem::filesystem_error& exception) {
        std::cout << "--------------------------------------------------" << '\n';
        std::cout << exception.what() << '\n';
        std::cout << "--------------------------------------------------" << '\n';
    }
}

const std::string SelectRoutingTableCommand::getName() const noexcept {
    return "select-routing-table";
}

const std::string SelectRoutingTableCommand::getDescription() const noexcept {
    return "Selects a routing table to load into the router. If a routing table is already loaded, it will be unloaded and replaced with the new one.";
}
}