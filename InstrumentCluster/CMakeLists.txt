cmake_minimum_required(VERSION 3.15)
project(DESproject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/opt/Qt/5.15.0/gcc_64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(Qt5 COMPONENTS Core Quick Gui REQUIRED)
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


add_executable(CANSender
        src/CANSender/CANSender.cpp
        src/CANSender/readCANThread.c
        src/CANSender/CANbuffer.c
        src/CANSender/sendSomeipThread.cpp
        src/CANSender/kalmanFilter.c
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(CANSender CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(PiracerSender
        src/PiracerSender/PiracerSender.cpp
        src/PiracerSender/PiracerClass.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(PiracerSender ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(PiracerOperator
        src/PiracerOperator/PiracerOperator.cpp
        src/PiracerOperator/ControllerClass.cpp
        src/PiracerOperator/PiracerOperatorStubImpl.cpp
        src/PiracerOperator/PiracerClass.cpp
        src-gen-desproject/v1/commonapi/PiracerOperatorSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/PiracerOperatorSomeIPDeployment.cpp
)
target_link_libraries(PiracerOperator ${PYTHON_LIBRARIES} CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(IPCManager
        src/IPCManager/IPCManager.cpp
        src/IPCManager/IPCManagerStubImpl.cpp
        src-gen-desproject/v1/commonapi/PiracerOperatorSomeIPProxy.cpp
        src-gen-desproject/v1/commonapi/PiracerOperatorSomeIPDeployment.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/IPCManagerSomeIPDeployment.cpp
)
target_link_libraries(IPCManager CommonAPI CommonAPI-SomeIP vsomeip3)


add_executable(InstrumentCluster
	src/InstrumentCluster/InstrumentCluster.cpp
	src/InstrumentCluster/InstrumentClusterStubImpl.cpp
        src/InstrumentCluster/CarInformation.cpp
	src/InstrumentCluster/qml.qrc
	src-gen-desproject/v1/commonapi/InstrumentClusterSomeIPStubAdapter.cpp
        src-gen-desproject/v1/commonapi/InstrumentClusterSomeIPDeployment.cpp
)
target_compile_definitions(InstrumentCluster
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(InstrumentCluster
  PRIVATE Qt5::Core Qt5::Quick Qt5::Gui CommonAPI CommonAPI-SomeIP vsomeip3)

