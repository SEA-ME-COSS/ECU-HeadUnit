cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(
    src-gen-manager
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
)
link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)


add_executable(SpeedClient
        src/SpeedClient/SpeedClient.cpp
        src/SpeedClient/readCANThread.c
        src/SpeedClient/CANbuffer.c
        src/SpeedClient/sendSomeipThread.cpp
        src/SpeedClient/kalmanFilter.c
        src-gen-manager/v1/commonapi/ManagerSomeIPProxy.cpp
        src-gen-manager/v1/commonapi/ManagerSomeIPDeployment.cpp
)
target_link_libraries(SpeedClient CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(BatteryClient
        src/BatteryClient/BatteryClient.cpp
        src-gen-manager/v1/commonapi/ManagerSomeIPProxy.cpp
        src-gen-manager/v1/commonapi/ManagerSomeIPDeployment.cpp
)
target_link_libraries(BatteryClient ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(ManagerService
        src/ManagerService/ManagerService.cpp
        src/ManagerService/ManagerStubImpl.cpp
        src-gen-manager/v1/commonapi/ManagerSomeIPStubAdapter.cpp
        src-gen-manager/v1/commonapi/ManagerSomeIPDeployment.cpp
)
target_link_libraries(ManagerService CommonAPI CommonAPI-SomeIP vsomeip3)
