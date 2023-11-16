#include "IVICompositorQtClass.hpp"
#include <iostream>

// Constructor for IVICompositorQtClass
IVICompositorQtClass::IVICompositorQtClass(QObject *parent) : QObject(parent) { }

// Getter for gear
quint16 IVICompositorQtClass::gear() const
{
    return Qgear;
}

// Setter for gear
void IVICompositorQtClass::setGear(uint16_t _gear)
{
    Qgear = _gear;
    // Emit the signal to notify changes to QML
    
    std::cout<<"************************************************************"<<_gear<<"************************************************************"<<std::endl;
    
    emit gearChanged();
}

// Create an instance of IVICompositorQtClass named carinfo
IVICompositorQtClass carinfo;

