// Include necessary header
#include <iostream>
#include <stdint.h>
#include <string>
#include <unistd.h>
#include <Python.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>


using namespace v1_0::commonapi;

int main(int argc, char *argv[]) {
    Py_Initialize();
    PyObject* pModule = PyImport_ImportModule("piracer.vehicles");
    PyObject* pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    PyObject* pInstance = PyObject_CallObject(pClass, NULL);
    
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<IPCManagerProxy<>> myProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    
    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable())
        usleep(10);
    std::cout << "Available!" << std::endl;
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
        PyObject* result = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
	double voltageLevel = PyFloat_AsDouble(result);
        
        //PyObject* str = PyObject_Str(result);
	//const char* cstr = PyUnicode_AsUTF8(str);
	
	//double voltageLevel = (double)std::stoi(cstr);
	uint16_t batteryLevel = (uint16_t)((voltageLevel - 2.8 * 3.0) / (12.3 - 2.8 * 3.0) * 100.0);
        
	myProxy->setBatteryLevel(batteryLevel, callStatus, returnMessage);
        usleep(500000);
    }

    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();

    return 0;
}

