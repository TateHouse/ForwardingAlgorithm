#pragma once

#include <filesystem>
#include <vector>

#include "IPv4Loader.hpp"

namespace Core {
class TextIPv4Loader final : public IPv4Loader {
public:
    explicit TextIPv4Loader(const std::filesystem::path& path);
    virtual ~TextIPv4Loader() override = default;

public:
    virtual const std::vector<IPv4> load() const override;

private:
    const std::filesystem::path path;
};
}