#ifndef PDCUNITQTCLASS_HPP
#define PDCUNITQTCLASS_HPP

#include <QObject>

class PDCUnitQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 distance READ distance WRITE setDistance NOTIFY distanceChanged)

private:
    quint16 Qdistance;   // Distance property.

public:
    explicit PDCUnitQtClass(QObject *parent = nullptr);

    quint16 distance() const;

    void setDistance(uint16_t _distance);
    
signals:
    void distanceChanged();
};

extern PDCUnitQtClass carinfo;  // Create a global instance of PDCUnitQtClass named 'carinfo'

#endif

