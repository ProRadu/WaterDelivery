//
// Created by radun on 15.11.2021.
//

#ifndef PROIECT1_WATERDELIVERY_H
#define PROIECT1_WATERDELIVERY_H


#include <iostream>
using namespace std;
class WaterDelivery {
    double weight, maxCapacity, avgConsumption;
public:
    WaterDelivery();
    WaterDelivery(double weight, double maxCapacity, double avgConsumption);
    WaterDelivery(WaterDelivery &A);
    WaterDelivery & operator=(const WaterDelivery &A);

    int getWeight() const;

    int getMaxCapacity() const;

    int getAvgConsumption() const;

    void setWeight(double weight);

    void setMaxCapacity(double maxCapacity);

    void setAvgConsumption(double avgConsumption);

    friend ostream &operator<<(ostream &os, const WaterDelivery &delivery);
    friend istream &operator>>(istream &is, WaterDelivery &A);

    void runTests(double lenght, double fuelPrice, double waterPrice);
};


#endif //PROIECT1_WATERDELIVERY_H
