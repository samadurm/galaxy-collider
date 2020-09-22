#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <stack>
#include <string>


struct Planet{
    std::string name;
    unsigned int mass;
    int velocity;
    bool initialized = false;
};

std::stack<Planet> initPlanets(int numPlanets, int minMass, int maxMass, int totalSize);
Planet initializePlanet(int idx, int mass, int velocity);
void initGalaxy(Planet *galaxy, std::stack<Planet> planets, int numPlanets, int dimX, int dimY);

#endif