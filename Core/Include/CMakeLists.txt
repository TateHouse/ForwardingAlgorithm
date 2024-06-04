CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
    CSVRoutingTableLoader.hpp
    IForwardedPortsWriter.hpp
    IPv4.hpp
    IIPv4Loader.hpp
    RouteMapping.hpp
    Router.hpp
    IRoutingTableLoader.hpp
    TextForwardedPortsWriter.hpp
    TextIPv4Loader.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})

ADD_SUBDIRECTORY(Utility)