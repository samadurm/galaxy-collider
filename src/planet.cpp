#include "planet.hpp"

std::stack<Planet> initPlanets(int numPlanets, int minMass, int maxMass){
    int minVelocity = 1, maxVelocity = 100;
    std::stack<Planet> planets;
    for(int i = 0; i < numPlanets; i++){
        Planet planet;

        planet.name = "Planet " + std::to_string(i);
        planet.mass = rand() % maxMass + minMass;
        planet.velocity = rand() % maxVelocity + minVelocity;
        
        planets.push(planet);
    }
    return planets;
}
