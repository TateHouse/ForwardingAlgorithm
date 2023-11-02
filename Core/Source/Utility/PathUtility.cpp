#include "Utility/PathUtility.hpp"

#include <format>

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
}