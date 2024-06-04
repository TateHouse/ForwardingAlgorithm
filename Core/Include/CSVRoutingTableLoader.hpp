#pragma once

#include <filesystem>

#include "RouteMapping.hpp"
#include "RoutingTableLoader.hpp"

namespace Core
{
/**
 * @class CSVRoutingTableLoader
 *
 * @brief Loads a routing table from a CSV file.
 */
class CSVRoutingTableLoader final : public RoutingTableLoader
{
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
	CSVRoutingTableLoader(const CSVRoutingTableLoader& other) = default;
	CSVRoutingTableLoader(CSVRoutingTableLoader&& other) = default;
	~CSVRoutingTableLoader() override = default;

public:
	CSVRoutingTableLoader& operator=(const CSVRoutingTableLoader& other) = default;
	CSVRoutingTableLoader& operator=(CSVRoutingTableLoader&& other) noexcept = default;

public:
	[[nodiscard]] std::vector<RouteMapping> load() const override;

private:
	std::filesystem::path path;
	bool hasHeaderRow;
};
}
