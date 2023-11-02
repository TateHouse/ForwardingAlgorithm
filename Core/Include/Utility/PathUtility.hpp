#pragma once

#include <filesystem>
#include <string_view>

namespace Core::Utility {
class PathUtility final {
public:
    PathUtility() noexcept = delete;
    ~PathUtility() noexcept = delete;

public:
    static std::filesystem::path validatePath(const std::filesystem::path& path, const std::string_view extension);
};
}