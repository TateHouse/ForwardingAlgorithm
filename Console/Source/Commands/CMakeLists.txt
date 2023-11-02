CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		Command.cpp
		CommandRepository.cpp
		GetForwardingPortCommand.cpp
		GetForwardingPortsCommand.cpp
		HelpCommand.cpp
		QuitCommand.cpp
		LoadRoutingTableCommand.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})