#pragma once

#include <filesystem>

#include "RouteMapping.hpp"
#include "RoutingTableLoader.hpp"

namespace Core {
class CSVRoutingTableLoader final : public RoutingTableLoader {
public:
    explicit CSVRoutingTableLoader(const std::filesystem::path& path, const bool hasHeaderRow);
    virtual ~CSVRoutingTableLoader() override = default;

public:
    virtual const std::vector<RouteMapping> load() const override;

private:
    static std::filesystem::path validatePath(const std::filesystem::path& path);

private:
    const bool hasHeaderRow;
    const std::filesystem::path path;
};
}