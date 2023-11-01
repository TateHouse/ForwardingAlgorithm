CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(HEADER_FILES
		Application.hpp
		Command.hpp
		CommandRepository.hpp
		Context.hpp
		QuitCommand.hpp
		SelectRoutingTableCommand.hpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${HEADER_FILES})