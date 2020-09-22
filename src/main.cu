#include <cstdlib>
#include <iostream>
#include "planet.hpp"

int main(){
    srand(time(NULL));

    int numPlanets = 10;
    int minMass, maxMass;
    int dimX, dimY;
    minMass = 10, maxMass = 100;

    dimX = 50, dimY = 50;

    Planet *galaxy1 = new Planet[dimX * dimY];

    initGalaxy(galaxy1, initPlanets(numPlanets, minMass, maxMass, dimX * dimY), numPlanets, dimX, dimY);

    delete [] galaxy1;
    return 0;
}