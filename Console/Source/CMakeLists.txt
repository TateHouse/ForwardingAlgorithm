CMAKE_MINIMUM_REQUIRED(VERSION 3.26)

SET(SOURCE_FILES
		Application.cpp
		Command.cpp
		CommandRepository.cpp
		Context.cpp
		GetForwardingPortCommand.cpp
		QuitCommand.cpp
		SelectRoutingTableCommand.cpp)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})