CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		CSVRoutingTableLoader.hpp
		IPv4.hpp
		IPv4Loader.hpp
		RouteMapping.hpp
		Router.hpp
		RoutingTableLoader.hpp
		TextIPv4Loader.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})

ADD_SUBDIRECTORY(Utility)