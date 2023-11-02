#pragma once

#include <filesystem>

#include "RouteMapping.hpp"
#include "RoutingTableLoader.hpp"

namespace Core {
/**
 * @class CSVRoutingTableLoader
 *
 * @brief Loads a routing table from a CSV file.
 */
class CSVRoutingTableLoader final : public RoutingTableLoader {
public:
    /**
     * @brief Construct a new CSVRoutingTableLoader instance.
     *
     * @param path The path to the CSV file.
     * @param hasHeaderRow Whether the CSV file has a header row.
     *
     * @throw std::invalid_argument If the path is invalid.
     * @throw std::filesystem::filesystem_error If the file cannot be opened.
     */
    explicit CSVRoutingTableLoader(const std::filesystem::path& path, const bool hasHeaderRow);

    virtual ~CSVRoutingTableLoader() override = default;

public:
    [[nodiscard]] virtual const std::vector<RouteMapping> load() const override;

private:
    const std::filesystem::path path;
    const bool hasHeaderRow;
};
}