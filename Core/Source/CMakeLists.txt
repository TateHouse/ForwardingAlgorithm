CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		CSVRoutingTableLoader.cpp
		IPv4.cpp
		RouteMapping.cpp
		Router.cpp
		TextForwardedPortsWriter.cpp
		TextIPv4Loader.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

ADD_SUBDIRECTORY(Utility)