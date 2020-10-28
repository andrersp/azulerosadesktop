cmake_minimum_required(VERSION 3.8)
project(ERP)

# Project 
set(PROJECT_COMPANY "RSP INFOTEC")
set(PROJECT_COPYRIGHT "Copyright (c) 2020 Awesome Company. All rights reserved.")
set(PROJECT_DOMAIN "azulerorsapersonalizados.com.br")
set(PROJECT_VERSION 0.1)
set(PROJECT_BUNDLE_NAME AppName)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Qt
# Set this to your Qt installation
set(ICON_NAME AppIcon)
SET(CMAKE_PREFIX_PATH "/Media/Qt/5.15.0/gcc_64")
SET(Qt5_DIR "/Media/Qt/5.15.0/gcc_64/lib/cmake/Qt5/Qt5Config.cmake")
set(CMAKE_AUTOMOC ON) # For meta object compiler 
set(CMAKE_AUTOUIC ON) # Resource files
set(CMAKE_AUTORCC ON) # UI Files
set(RESOURCE_FILES 
	resources/media.qrc 
)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Charts REQUIRED)


# macOS Bundle building
set(OS_BUNDLE "")
if(CMAKE_BUILD_TYPE STREQUAL "Release")
set(OS_BUNDLE "MACOSX_BUNDLE")
set(MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_BUNDLE_NAME})
set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})
set(MACOSX_BUNDLE_LONG_VERSION_STRING ${PROJECT_VERSION})
set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION})
set(MACOSX_BUNDLE_COPYRIGHT ${PROJECT_COPYRIGHT})
set(MACOSX_BUNDLE_GUI_IDENTIFIER ${PROJECT_DOMAIN})
set(MACOSX_BUNDLE_ICON_FILE ${ICON_NAME})
else(CMAKE_BUILD_TYPE STREQUAL "Release")
set(CMAKE_BUILD_TYPE Debug)
endif()

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
include_directories(${PROJECT_SOURCE_DIR})

# source files
file(GLOB TARGET_SRC
    view/*.cpp
    view/*.h
    control/*.cpp
    control/*.h
    "model/*.cpp"
    "model/*.h"    
    
    ${RESOURCE_FILES} )

# executable
add_executable(ERP main.cpp ${TARGET_SRC})
if(CMAKE_BUILD_TYPE STREQUAL "Release")
set_target_properties(${PROJECT_NAME} PROPERTIES 
	MACOSX_BUNDLE TRUE 
	RESOURCE "${RESOURCE_FILES}"
	OUTPUT_NAME "${PROJECT_BUNDLE_NAME}"
)
endif()

# expose values to c++ files
target_compile_definitions(${PROJECT_NAME} PRIVATE 
	CMAKE_DEF_PROJECT_VERSION="${PROJECT_VERSION}"
	CMAKE_DEF_APP_NAME="${PROJECT_BUNDLE_NAME}"
	CMAKE_DEF_ORG_COMPANY="${PROJECT_COMPANY}"
	CMAKE_DEF_ORG_DOMAIN="${PROJECT_DOMAIN}"
)

# Link Libs
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network Qt5::Charts)
