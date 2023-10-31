#include "CSVRoutingTableLoader.hpp"

#include <format>
#include <fstream>
#include <sstream>
#include <string>

namespace Core {
CSVRoutingTableLoader::CSVRoutingTableLoader(const std::filesystem::path& path, const bool hasHeaderRow) :
        path {validatePath(path)}, hasHeaderRow {hasHeaderRow} {
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

std::filesystem::path CSVRoutingTableLoader::validatePath(const std::filesystem::path& path) {
    if (!std::filesystem::exists(path)) {
        const auto message {
                std::format("CSV Routing Table Loader: The specified path does not exist. Path: {}", path.string())};
        throw std::invalid_argument {message};
    }

    if (!std::filesystem::is_regular_file(path)) {
        const auto message {
                std::format("CSV Routing Table Loader: The specified path is not a regular file. Path: {}",
                            path.string())};
        throw std::invalid_argument {message};
    }

    if (path.extension() != ".csv") {
        const auto message {
                std::format("CSV Routing Table Loader: The specified path does not point to a CSV file. Path: {}",
                            path.string())};
        throw std::invalid_argument {message};
    }

    return path;
}
}