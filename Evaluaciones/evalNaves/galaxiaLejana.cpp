/*
    Mauricio Rico
    A01370874
    25/10/17
    " segundo parcial "
*/
#include <iostream>
#import <string>
#import <stdlib.h>
#import <time.h>

#define SIZE 30 // constante de SIZE

using namespace std;

// Clase general Dios
class Dios{
protected:
    // Variables
    string type;
    int posX, posY, id;
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
        return posY;
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
        // cout << "Nave config" << endl;
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
// Iterador
template<class I>
class Iterador;
// Collection class
template<class C>
class Collection{
protected:
    C* array;
    int size;
    int cont;
public:
    friend class Iterador<C>;
    Collection(){
        size = 10;
        array = new C[10];
        cont = 0;
    }
    void addPlayer(C value){
        if(cont <= size){
            array[cont++] = value;
            return;
        } else{
            cout << "ya no hay espacio para agregar elementos" << endl;
        }
    }
    Iterador<C>* getIterador();
    C at(int pos){
        return array[pos];
    }
};
// Iterador class
template <class I>
class Iterador: public Tablero {
protected:
    Collection<I> coll;
    int cont = 0;
public:
    Iterador(const Collection<I>& coll) : coll(coll){}
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
// getIterador
template<class I>
Iterador<I>* Collection<I>::getIterador(){
    return new Iterador<I>(*this);
}
// find_if function
template<class C, class Function, class D >
void find_if(Collection<C> coll, Function f, D secondPlay){
  Iterador<C>* it = coll.getIterador();
  while (it->hasNext())
    f(it->next(), secondPlay);
}
// Funcion que compara coordenadas para la colision
template<class C, class D>
void crash(C firstPlay, D secondPlay){
    if(firstPlay->getPosX() == secondPlay->getPosX()){
        if(firstPlay->getPosY() == secondPlay->getPosY()){
                cout << firstPlay->getType() << " just crashed with " << secondPlay->getType() << endl;
        }
    }
}
typedef void(*func)(Dios *, Dios *);

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
    // Spacecraft 2
    SpacecraftColo* colonize = SpacecraftColo::getInstance();
    // Spacecraft 3
    SpacecraftObs* observe = SpacecraftObs::getInstance();
    // Asteroid 1
    AsteroidStony* stony = AsteroidStony::getInstance();
    // Asteroid 2
    AsteroidIron* iron = AsteroidIron::getInstance();
    // Planet 1
    PlanetDesert* desert = PlanetDesert::getInstance();
    // Planet 2
    PlanetEarth* earth = PlanetEarth::getInstance();
    // Configuracion de los elementos
    explore->configElement("Planet exploration ships");
    colonize->configElement("Colonization ships");
    observe->configElement("Planet observation ships");
    stony->configElement("Stony Meteorites");
    iron->configElement("Iron Meteorites");
    desert->configElement("Desert planet");
    earth->configElement("Earth analog");
    // Tablero
    Tablero* juego = Tablero::getInstance();
    // se añaden elementos a collection
    col.addPlayer(explore);
    col.addPlayer(colonize);
    col.addPlayer(observe);
    col.addPlayer(stony);
    col.addPlayer(iron);
    col.addPlayer(desert);
    col.addPlayer(earth);

    char answ = 'y';
    while(answ == 'y'){
        // Spacecraft 1
        juego->resetElement(explore->getPosX(), explore->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, explore);
        find_if<Dios*, func, Dios*> (col, crash, explore);
        // Spacecraft 2
        juego->resetElement(colonize->getPosX(), colonize->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, colonize);
        find_if<Dios*, func, Dios*> (col, crash, colonize);
        // Spacecraft 3
        juego->resetElement(observe->getPosX(), observe->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, observe);
        find_if<Dios*, func, Dios*> (col, crash, observe);
        // Asteroid 1
        juego->resetElement(stony->getPosX(), stony->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, stony);
        find_if<Dios*, func, Dios*> (col, crash, stony);
        // Asteroid 2
        juego->resetElement(iron->getPosX(), iron->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, iron);
        find_if<Dios*, func, Dios*> (col, crash, iron);
        // Planet 1
        juego->resetElement(desert->getPosX(), desert->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, desert);
        find_if<Dios*, func, Dios*> (col, crash, desert);
        // Planet 2
        juego->resetElement(earth->getPosX(), earth->getPosY());
        juego->placeElement(rand() % 10, rand() % 10, earth);
        find_if<Dios*, func, Dios*> (col, crash, earth);

        cout << "Repetir? (y/n)" << endl;
        cin >> answ;
    }
    return 0;
}
