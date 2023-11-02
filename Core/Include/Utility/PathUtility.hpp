#pragma once

#include <filesystem>
#include <string_view>

namespace Core::Utility {
/**
 * @class PathUtility
 *
 * @brief Provides utility functions for paths.
 */
class PathUtility final {
public:
    PathUtility() noexcept = delete;
    ~PathUtility() noexcept = delete;

public:
    /**
     * @brief Validates the path and extension.<br><br>
     *
     * A path is not valid if it does not exist, is not a regular file, or has an invalid extension.
     *
     * An extension is not valid if it is empty or does not start with a dot.
     *
     * @param path The path to validate.
     * @param extension The extension to validate.
     *
     * @return The validated path.
     *
     * @throws std::invalid_argument If the path or extension is invalid.
     */
    static std::filesystem::path validatePath(const std::filesystem::path& path, const std::string_view extension);

    /**
     * @brief Creates or overrides a file.<br><br>
     *
     * @param path The path to create or override.
     * @param extension The extension of the file.
     *
     * @return The path of the created or overridden file.
     *
     * @throws std::invalid_argument If the extension is invalid.
     * @throws std::filesystem::filesystem_error If the file could not be created or overridden.
     */
    static std::filesystem::path createFile(const std::filesystem::path& path, const std::string_view extension);
};
}