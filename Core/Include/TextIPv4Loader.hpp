#pragma once

#include <filesystem>
#include <vector>

#include "IPv4Loader.hpp"

namespace Core {
/**
 * @class TextIPv4Loader
 *
 * @brief Loads IPv4 addresses from a text file.
 */
class TextIPv4Loader final : public IPv4Loader {
public:
    /**
     * @brief Constructs a TextIPv4Loader instance.
     *
     * @param path The path to the text file.
     *
     * @throws std::invalid_argument If the path or extension is invalid.
     * @throws std::filesystem::filesystem_error If the file cannot be opened.
     */
    explicit TextIPv4Loader(const std::filesystem::path& path);
    virtual ~TextIPv4Loader() override = default;

public:
    virtual const std::vector<IPv4> load() const override;

private:
    const std::filesystem::path path;
};
}