#include "planet.hpp"

/*
    Function: initPlanets
    Description: creates a stack of numPlanets with mass between minMass and maxMass,
        and ensures more planets are not created than spots to put them in the galaxy
*/
std::stack<Planet> initPlanets(int numPlanets, int minMass, int maxMass, int totalSize){
    int minVelocity = 1, maxVelocity = 100;
    std::stack<Planet> planets;

    if(numPlanets >= totalSize){
        std::cerr << "Selected " << numPlanets << " planets but there are only " << totalSize << " spaces to fill. Updated to numPlanets to " << totalSize << "\n";
        numPlanets = totalSize - 1;
    }

    for(int i = 0; i < numPlanets; i++){
        planets.push( initializePlanet(i, rand() % maxMass + minMass, rand() % maxVelocity + minVelocity) );
    }
    return planets;
}

/*
    Function: initializePlanet
    Description: returns a single planet with given mass and velocity
*/
Planet initializePlanet(int idx, int mass, int velocity){
    Planet planet;
    planet.name = "Planet " + std::to_string(idx);
    planet.mass = mass;
    planet.velocity = velocity;
    planet.initialized = true;

    return planet;
}

/*
    Function: initGalaxy
    Description: builds a galaxy matrix up by adding planets to unfilled squares. If a 
        square is filled, the function will roll a new random square until an unfilled
        square is found or after 100 tries (to prevent infinite loops)
*/
void initGalaxy(Planet *galaxy, std::stack<Planet> planets, int numPlanets, int dimX, int dimY){
    while(planets.size()){
        Planet planet = planets.top();

        int randX = rand() % dimX, randY = rand() % dimY;
        int counter = 0;
        while(galaxy[randX * dimY + randY].initialized){
            randX = rand() % dimX, randY = rand() % dimY;
            counter++;
            if(counter > 100) break; // this prevents an infinite loop if galaxy is full
        }
        galaxy[randX * dimY + randY] = planet;
        planets.pop();
    }
}
