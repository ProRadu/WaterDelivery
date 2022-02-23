//
// Created by radun on 15.11.2021.
//

#include "WaterDelivery.h"

WaterDelivery::WaterDelivery(): weight(0), maxCapacity(0),avgConsumption(0){}

WaterDelivery::WaterDelivery(double weight, double maxCapacity, double avgConsumption) :weight(weight),
                                                                                        maxCapacity(maxCapacity),
                                                                                        avgConsumption(avgConsumption) {}


WaterDelivery::WaterDelivery(WaterDelivery &A) :weight(A.weight),
                                                maxCapacity(A.maxCapacity),
                                                avgConsumption(A.avgConsumption) {}

WaterDelivery &WaterDelivery::operator=(const WaterDelivery &A) {
    this->weight=A.weight;
    this->maxCapacity=A.maxCapacity;
    this->avgConsumption=A.avgConsumption;
    return (*this);
}

std::ostream &operator<<(ostream &os, const WaterDelivery &delivery) {
    os << "weight: " << delivery.weight << ", maxCapacity: " << delivery.maxCapacity << ", avgConsumption: "
       << delivery.avgConsumption<<endl;
    return os;
}

istream &operator>>(istream &is, WaterDelivery &A) {
    cout<< "weight: \n";
    is>>A.weight;
    cout<< "maxCapacity: \n";
    is>>A.maxCapacity;
    cout<< "avgConsumption: \n";
    is>>A.avgConsumption;
    return is;
}

int WaterDelivery::getWeight() const {
    return weight;
}

int WaterDelivery::getMaxCapacity() const {
    return maxCapacity;
}

int WaterDelivery::getAvgConsumption() const {
    return avgConsumption;
}

void WaterDelivery::setWeight(double weight) {
    WaterDelivery::weight = weight;
}

void WaterDelivery::setMaxCapacity(double maxCapacity) {
    WaterDelivery::maxCapacity = maxCapacity;
}

void WaterDelivery::setAvgConsumption(double avgConsumption) {
    WaterDelivery::avgConsumption = avgConsumption;
}

void WaterDelivery::runTests(double lenght, double fuelPrice, double waterPrice) {
    int i;
    double mApa, procentMasaApa, x, consumReal, costCarburant, costApa, costTotal, procentCarburant;
    for(i=25;i<=100;i=i+25)
    {
        mApa=((float)i/100)*maxCapacity;
        procentMasaApa=(mApa/(mApa+weight))*100;
        if(procentMasaApa<15)
        {
            x=(procentMasaApa*4.1)/10;
            consumReal=(avgConsumption*(100+x))/100;
            costCarburant=consumReal*(lenght/100)*fuelPrice;
            costApa=mApa*waterPrice;
            costTotal=costApa+costCarburant;
            procentCarburant=100/(costTotal/costCarburant);
        }
        else
        {
            x=(procentMasaApa*8.4)/20;
            consumReal=(avgConsumption*(100+x))/100;
            costCarburant=consumReal*(lenght/100)*fuelPrice;
            costApa=mApa*waterPrice;
            costTotal=costApa+costCarburant;
            procentCarburant=100/(costTotal/costCarburant);
        }
        cout<<"Pentru drumul cu "
            <<i
            <<"% din capacitate:\n"
            <<"Cost carburant= "
            <<costCarburant<<"RON, Cost apa= "
            <<costApa<<"RON. Prin urmare "
            <<procentCarburant<<"% din fapta buna a reprezentat carburantul.\n";
    }

}
