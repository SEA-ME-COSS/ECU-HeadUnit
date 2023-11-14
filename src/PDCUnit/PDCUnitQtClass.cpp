#include "PDCUnitQtClass.hpp"

// Constructor for PDCUnitQtClass
PDCUnitQtClass::PDCUnitQtClass(QObject *parent) : QObject(parent)
{
    // Initialize distance to 50
    Qdistance = 50;
}

// Getter for distance
quint16 PDCUnitQtClass::distance() const
{
    return Qdistance;
}

// Setter for distance
void PDCUnitQtClass::setDistance(uint16_t _distance)
{
    Qdistance = _distance;
    // Emit the signal to notify changes to QML
    emit distanceChanged();
}

// Create an instance of PDCUnitQtClass named carinfo
PDCUnitQtClass carinfo;

