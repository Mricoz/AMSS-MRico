// Mauricio Rico Zavala
#include <iostream>
#include <string>
using namespace std;

class Mundo{
public:
    // Constructor
    Mundo(string nombreMundo) : nombreMundo(nombreMundo){}
    // Variables
    string nombreMundo;
};


class Personaje {
public:
    // Constructor
    Personaje() = default;
    Personaje(string nombre) : nombre(nombre){}
    // Variables
    string nombre;
    int telefono;
    string correo;
    Mundo* mundo;
    // Funciones
    virtual Personaje* clone() = 0;

};

class Princesa : public Personaje {
public:
    // Constructor
    Princesa(string n) : Personaje(n){}
    Princesa(const Princesa& p){
        nombre = p.nombre;
        telefono = p.telefono;
        mundo = new Mundo(p.mundo -> nombreMundo);
        correo = p.correo;
    }
    // Funciones
    void grita() { cout << "aaaaaa" << endl;}
    Personaje* clone(){
        return new Princesa(*this);
    }
};

class Villano : public Personaje {
public:
    // Constructor
    Villano(string n) : Personaje(n){}
    Villano(const Villano& p){
        nombre = p.nombre;
        telefono = p.telefono;
        mundo = new Mundo(p.mundo -> nombreMundo);
        correo = p.correo;
    }
    // Funciones
    void secuestra() { cout << "te atrape!" << endl;}
    Personaje* clone(){
        return new Villano(*this);
    }
};

class Heroe : public Personaje {
public:
    // Constructor
    Heroe(string n) : Personaje(n){}
    Heroe(const Heroe& p){
        nombre = p.nombre;
        telefono = p.telefono;
        mundo = new Mundo(p.mundo -> nombreMundo);
        correo = p.correo;
    }
    // Funciones
    void salvar() { cout << "yo te rescatare!" << endl;}
    Personaje* clone(){
        return new Heroe(*this);
    }
};

int main(){
    Princesa* pri = new Princesa("Rapunzel");
    pri -> correo = "princesaunp@tec.mx";
    pri -> telefono = 55293;
    pri -> mundo = new Mundo("Paleta");
    Princesa* p = dynamic_cast<Princesa*> (pri -> clone());
    cout << p -> nombre << endl;
    cout << p -> correo << endl;
    cout << p -> telefono << endl;
    cout << p -> mundo -> nombreMundo << endl;
}
