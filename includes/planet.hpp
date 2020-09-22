#ifndef PLANET_H
#define PLANET_H

#include <stack>
#include <string>


struct Planet{
    std::string name;
    unsigned int mass;
    int velocity;
};

std::stack<Planet> initPlanets(int numPlanets, int minMass, int maxMass);


#endif