#include <iostream>
#include "WaterDelivery.h"

using namespace std;

int main() {

    WaterDelivery simulator {1500, 750, 12}; // constructor cu masa masinii, capacitatea maxima si consumul mediu
    simulator.runTests(100, 6, 1.2); // ne va afisa informatii despre costuri in cazul unui drum de 100km, pretul carburantului de 6 RON si pretul apei de 1.2 RON

    cin >> simulator;
    cout << simulator;

    simulator.runTests(1000, 6.2, 1.5); // ceea ce afiseaza va conta in functie de datele citite, dar sigur rezultatul va fi interesant

    // folosind ceea ce am implementat, deja vom putea raspunde la intrebari de tipul:
    //  dar daca am "creste" capacitatea maxima cu 10%, calculele cum se vor modifica
    simulator.setMaxCapacity(simulator.getMaxCapacity() * 1.1);
    simulator.runTests(100, 6.2, 1.5); // pastram aceleasi date ca pe randul 20, pentru a sesiza diferenta

    return 0;
}

