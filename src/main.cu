#include <cstdlib>
#include <iostream>
#include "planet.hpp"

int main(){
    srand(time(NULL));
    int numPlanets = 10;
    Planet *galaxy1 = (Planet*)malloc(numPlanets * sizeof(Planet));
 
    std::stack<Planet> planets = initPlanets(10, 10, 100);

    while(planets.size() != 0){
        Planet planet = planets.top();
        std::cout << planet.name << " mass of " << planet.mass << " velocity: " << planet.velocity << std::endl;
        planets.pop();
    }

    free(galaxy1);
    return 0;
}