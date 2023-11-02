#include "Utility/PathUtility.hpp"

#include <format>
#include <fstream>

namespace Core::Utility {
std::filesystem::path PathUtility::validatePath(const std::filesystem::path& path, const std::string_view extension) {
    if (extension.empty() || extension.front() != '.') {
        throw std::invalid_argument("The extension must start with a dot.");
    }

    if (!std::filesystem::exists(path)) {
        const auto message {
                std::format("The specified path does not exist. Path: {}", path.string())};
        throw std::invalid_argument {message};
    }

    if (!std::filesystem::is_regular_file(path)) {
        const auto message {
                std::format("The specified path is not a regular file. Path: {}", path.string())};
        throw std::invalid_argument {message};
    }

    if (path.extension() != extension) {
        throw std::invalid_argument("Path has invalid extension.");
    }

    return path;
}

std::filesystem::path PathUtility::createFile(const std::filesystem::path& path, const std::string_view extension) {
    if (extension.empty() || extension.front() != '.') {
        throw std::invalid_argument("The extension must start with a dot.");
    }

    if (std::filesystem::exists(path)) {
        if (std::ofstream fileStream {path, std::ios::trunc}; !fileStream.is_open()) {
            throw std::filesystem::filesystem_error {"Failed to create file.",
                                                     path,
                                                     std::make_error_code(std::errc::io_error)};
        }

        return path;
    }

    const auto parentPath {path.parent_path()};
    if (!parentPath.empty() && !std::filesystem::exists(parentPath)) {
        std::filesystem::create_directories(parentPath);
    }

    if (std::ofstream fileStream {path, std::ios::out}; !fileStream.is_open()) {
        throw std::filesystem::filesystem_error {"Failed to create file.",
                                                 path,
                                                 std::make_error_code(std::errc::io_error)};
    }

    return path;
}
}