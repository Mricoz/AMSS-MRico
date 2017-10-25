/*
    Mauricio Rico
    A01370874
    25/10/17
    " segundo parcial "
*/
#include <iostream>
#import <string>
#import <vector>
#import <stdlib.h>
#import <time.h>

#define SIZE 10

using namespace std;


// Clase general Dios
class Dios{
protected:
    // Variables
    string type;
    int posX;
    int posY;
    int id;
public:
    // Funciones
    int getPosX(){
        return posX;
    }
    int getPosY(){
        return posY;
    }
    int getID(){
        return id;
    }
};
// Galaxia class (Singleton)
template<typename G>
class Galaxia: public Dios {
protected:
    static G* instance;

public:
    // Constructor
    Galaxia() = default;
    // Funciones
    static G* getInstance(){
        if(!instance){
            instance = new G;
        }
        return instance;
    }
    void operation(){
        cout << "Funciono!" << endl;
    }
    void configElement(string t){
        type = t;
        posX = rand() % 10; // Random pos
        posY = rand() % 10; // Random pos
        cout << "Nave config" << endl;
    }
};
// Observer class (Tablero)
class Tablero: public Galaxia<Tablero>{
public:
    int tablero[SIZE][SIZE];
    // Pone el elemento dentro del tablero inicialmente en 0
    void resetElement(int x, int y){
        tablero[x][y] = 0;
    }
    // Pone el elemento dentro del tablero con su valor
    void placeElement(int posX, int posY, Dios* value ){
        tablero[posX][posY] = value->getID();
    }
    // Imprime el tablero
    void printTablero(){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                cout << tablero[i][j] << endl << ' ';
            }
            cout << endl;
        }
    }
};
// Singleton instance
template<typename G>
G* Galaxia<G>::instance = NULL;

// Spacecraft class 1
class SpacecraftExplore: public Galaxia<SpacecraftExplore>{
public:
    // Constructor
    SpacecraftExplore(){
        id = 0;
    }
};
// Spacecraft class 2
class SpacecraftColo: public Galaxia<SpacecraftColo>{
public:
    // Constructor
    SpacecraftColo(){
        id = 1;
    }
};
// Spacecraft class 3
class SpacecraftObs: public Galaxia<SpacecraftObs>{
public:
    // Constructor
    SpacecraftObs(){
        id = 2;
    }
};
// Asteroid class 1
class AsteroidStony: public Galaxia<AsteroidStony>{
public:
    // Constructor
    AsteroidStony(){
        id = 3;
    }

};
// Asteroid class 2
class AsteroidIron: public Galaxia<AsteroidIron>{
public:
    // Constructor
    AsteroidIron(){
        id = 4;
    }

};
// Planet class 1
class PlanetDesert: public Galaxia<PlanetDesert>{
public:
    // Constructor
    PlanetDesert(){
        id = 5;
    }

};
// Planet class 2
class PlanetEarth: public Galaxia<PlanetEarth>{
public:
    // Constructor
    PlanetEarth(){
        id = 6;
    }

};

// main()
int main(int argr, char** argv){
    srand(time(NULL));

    // Spacecraft 1
    SpacecraftExplore* explore = SpacecraftExplore::getInstance();
    explore -> configElement("Planet exploration ships");
    // Spacecraft 2
    SpacecraftColo* colonize = SpacecraftColo::getInstance();
    colonize -> configElement("Colonization ships");
    // Spacecraft 3
    SpacecraftObs* observe = SpacecraftObs::getInstance();
    observe -> configElement("Planet observation ships");
    // Asteroid 1
    AsteroidStony* stony = AsteroidStony::getInstance();
    stony -> configElement("Stony Meteorites");
    // Asteroid 2
    AsteroidIron* iron = AsteroidIron::getInstance();
    iron -> configElement("Iron Meteorites");
    // Planet 1
    PlanetDesert* desert = PlanetDesert::getInstance();
    desert -> configElement("Desert planet");
    // Planet 2
    PlanetEarth* earth = PlanetEarth::getInstance();
    earth -> configElement("Earth analog");

    // Tablero
    Tablero* juego = Tablero::getInstance();
    char rep = 'y';
    while(rep == 'y'){
        // Spacecraft 1
        juego->resetElement(explore->getPosX(), explore->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, explore->getID());
        // Spacecraft 2
        juego->resetElement(colonize->getPosX(), colonize->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, colonize->getID());
        // Spacecraft 3
        juego->resetElement(observe->getPosX(), observe->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, observe->getID());
        // Asteroid 1
        juego->resetElement(stony->getPosX(), stony->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, stony->getID());
        // Asteroid 2
        juego->resetElement(iron->getPosX(), iron->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, iron->getID());
        // Planet 1
        juego->resetElement(desert->getPosX(), desert->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, desert->getID());
        // Planet 2
        juego->resetElement(earth->getPosX(), earth->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, earth->getID());

        // Imprime el tablero
        juego->printTablero();
        cout << "Repetir? (y/n)" << endl;
        cin >> rep;
    }
}
