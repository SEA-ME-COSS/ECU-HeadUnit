cmake_minimum_required(VERSION 3.15)
project(DESproject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/opt/Qt/5.15.0/gcc_64")

find_package(Qt5 COMPONENTS Core Quick Gui Multimedia REQUIRED)

add_executable(InstrumentCluster
        src/InstrumentCluster/InstrumentCluster.cpp
        src/InstrumentCluster/qml.qrc
)
target_compile_definitions(InstrumentCluster
PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(InstrumentCluster
PRIVATE Qt5::Core Qt5::Quick Qt5::Gui)


add_executable(HeadUnit
        src/HeadUnit/HeadUnit.cpp
        src/HeadUnit/qml.qrc
)
target_compile_definitions(HeadUnit
PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(HeadUnit
PRIVATE Qt5::Core Qt5::Quick Qt5::Gui Qt5::Multimedia)
