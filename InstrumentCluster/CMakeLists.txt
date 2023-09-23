cmake_minimum_required(VERSION 3.14)

project(DESproject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/5.15.0/gcc_64")

find_package(Qt5 COMPONENTS Core Quick Gui REQUIRED)

add_executable(InstrumentCluster
	main.cpp
	qml.qrc
)
target_compile_definitions(InstrumentCluster
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(InstrumentCluster
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

