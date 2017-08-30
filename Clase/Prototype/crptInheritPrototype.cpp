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

template <class Base, class SubClass>
class Clon : public Base{
public:
    Base* clone(){
        return new SubClass(dynamic_cast<SubClass&>(*this));
    }
};

class Princesa : public Clon<Personaje, Princesa> {
public:
    // Constructor
    Princesa(string n){
        nombre = n;
    }
    Princesa(const Princesa& p){
        nombre = p.nombre;
        telefono = p.telefono;
        mundo = new Mundo(p.mundo -> nombreMundo);
        correo = p.correo;
    }
    // Funciones
    void grita() { cout << "aaaaaa" << endl;}
};

class Villano : public Clon<Personaje, Villano> {
public:
    // Constructor
    Villano(string n){
        nombre = n;
    }
    Villano(const Villano& p){
        nombre = p.nombre;
        telefono = p.telefono;
        mundo = new Mundo(p.mundo -> nombreMundo);
        correo = p.correo;
    }
    // Funciones
    void secuestra() { cout << "te atrape!" << endl;}
};

class Heroe : public Clon<Personaje, Heroe> {
public:
    // Constructor
    Heroe(string n){
        nombre = n;
    }
    Heroe(const Heroe& p){
        nombre = p.nombre;
        telefono = p.telefono;
        mundo = new Mundo(p.mundo -> nombreMundo);
        correo = p.correo;
    }
    // Funciones
    void salvar() { cout << "yo te rescatare!" << endl;}
};

int main(){
    Princesa* pri = new Princesa("Rapunzel");
    pri -> correo = "princesaunp@tec.mx";
    pri -> telefono = 55293;
    pri -> mundo = new Mundo("Paleta");
    Princesa* p = dynamic_cast<Princesa*> (pri -> clone());
    pri -> nombre = "RAPUNZEL";
    pri -> mundo -> nombreMundo = "Paleton";
    cout << pri -> nombre << endl;
    cout << pri -> correo << endl;
    cout << pri -> telefono << endl;
    cout << pri -> mundo -> nombreMundo << endl;
    cout << p -> nombre << endl;
    cout << p -> correo << endl;
    cout << p -> telefono << endl;
    cout << p -> mundo -> nombreMundo << endl;

    Princesa* pp = dynamic_cast<Princesa*> (p -> clone());
    pp -> mundo -> nombreMundo = "Paletita";
    cout << pp -> nombre << endl;
    cout << pp -> correo << endl;
    cout << pp -> telefono << endl;
    cout << pp -> mundo -> nombreMundo << endl;

}
