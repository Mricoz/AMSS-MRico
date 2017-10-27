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

#define SIZE 10 // constante de SIZE

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
    string getType(){
        return type;
    }
    int getPosX(){
        return posX;
    }
    int getPosY(){
        return posY;
    }
    int getID(){
        return id;
    }
    void erase(){
        id = 0;
    }
    void setCoord(int x, int y){
      posX = x;
      posY = y;
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
// Singleton instance
template<typename G>
G* Galaxia<G>::instance = NULL;

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
        value->setCoord(posX, posY);
    }
};
// Iterator
template<class I>
class Iterator;
// Collection class
template<class C>
class Collection{
protected:
    C* array;
    int size;
    int cont;
public:
    friend class Iterator<C>;
    Collection(){
        size = 10;
        array = new C[10];
        cont = 0;
    }
    void addElement(C value){
        if(cont <= size){
            array[cont++] = value;
            return;
        } else{
            cout << "ya no hay espacio para agregar elementos" << endl;
        }
    }
    Iterator<C>* getIterator();
    C at(int pos){
        return array[pos];
    }
};
// Iterator class
template <class I>
class Iterator: public Tablero {
protected:
    Collection<I> coll;
    int cont = 0;
public:
    Iterator(const Collection<I>& coll) : coll(coll){}
    bool hasNext(){
        if(cont < coll.cont){
            return true;
        } else {
            return false;
        }
    }
    I next(){
        return coll.at(cont++);
    }
};
// getIterator
template<class I>
Iterator<I>* Collection<I>::getIterator(){
    return new Iterator<I>(*this);
}
// find_if function
template<class C, class Function>
void find_if(Collection<C> coll, Function f){
    Iterator<C>* it = coll.getIterator();
    while(it->hasNext()){
        f(it->next());
    }
}

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
    srand(time(NULL)); // rand

    Collection<Dios* > col; // Declaracion collection

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

    col.addElement(explore);
    col.addElement(colonize);
    col.addElement(observe);
    col.addElement(stony);
    col.addElement(iron);
    col.addElement(desert);
    col.addElement(earth);

    char answ = 'y';
    while(answ == 'y'){
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

        cout << "Repetir? (y/n)" << endl;
        cin >> answ;
    }
}
