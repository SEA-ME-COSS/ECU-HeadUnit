cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(
    src-gen-desproject
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
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(SpeedClient CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(PiracerClient
        src/PiracerClient/PiracerClient.cpp
        src/PiracerClient/piracerClass.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(PiracerClient ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(IPCManager
        src/IPCManager/IPCManager.cpp
        src/IPCManager/IPCManagerStubImpl.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(IPCManager CommonAPI CommonAPI-SomeIP vsomeip3)
