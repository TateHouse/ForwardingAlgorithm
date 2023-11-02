CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		Command.hpp
		CommandRepository.hpp
		GetForwardingPortCommand.hpp
		GetForwardingPortsCommand.hpp
		HelpCommand.hpp
		QuitCommand.hpp
		LoadRoutingTableCommand.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})