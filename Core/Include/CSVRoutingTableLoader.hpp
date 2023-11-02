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
    [[nodiscard]] virtual const std::vector<RouteMapping> load() const override;

private:
    const std::filesystem::path path;
    const bool hasHeaderRow;
};
}