#include "CSVRoutingTableLoader.hpp"

#include <fstream>
#include <sstream>
#include <string>

#include "Utility/PathUtility.hpp"

namespace Core {
CSVRoutingTableLoader::CSVRoutingTableLoader(const std::filesystem::path& path, const bool hasHeaderRow) :
        path {Utility::PathUtility::validatePath(path, ".csv")}, hasHeaderRow {hasHeaderRow} {
}

const std::vector<RouteMapping> CSVRoutingTableLoader::load() const {
    std::ifstream fileStream {path};
    std::string line {};

    if (!fileStream.is_open()) {
        throw std::filesystem::filesystem_error {"CSV Routing Table Loader: Failed to open file.",
                                                 path,
                                                 std::make_error_code(std::errc::io_error)};
    }

    if (hasHeaderRow) {
        fileStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (fileStream.peek() == std::ifstream::traits_type::eof()) {
        return {};
    }

    std::vector<RouteMapping> routeMappings {};

    while (std::getline(fileStream, line)) {
        if (line.empty()) {
            continue;
        }

        std::istringstream lineStream {line};
        std::string address {};
        std::string prefixLength {};
        std::string port {};

        std::getline(lineStream, address, ',');
        std::getline(lineStream, prefixLength, ',');
        std::getline(lineStream, port);

        const auto ip {IPv4 {address}};
        routeMappings.emplace_back(ip, std::stoi(prefixLength), std::stoi(port));
    }

    return routeMappings;
}
}