/*
    Mauricio Rico Zavala
    A01370874
    06-09-17
    Primera Evaluacion Parcial
*/

#include <iostream>
#include <string>
using namespace std;
// Clase padre de donde se deriva el resto de las computadoras
class Computadora {
public:
    // Funcion de creacion de computadora
    template<class Comp>
    Comp* nuevaComp(){
        return new Comp;
    }

    // Proceso de cada computadora
    void seleccionComponentes(){
        cout << "Proceso de seleccion de componentes" << endl;
    }
    void ensambladoComponentes(){
        cout << "Proceso de ensamblado de componentes" << endl;
    }
    void instalConfigSoftware(){
        cout << "Proceso de instalacion y configuracion de software" << endl;
    }
    void empaquetadoComp(){
        cout << "Proceso de empaquedado del computador" << endl;
    }
};
// Desktop class
class Desktop : public Computadora{
    friend class Computadora;
public:
    void tipoComp(){
        cout << "HAZ CREADO UNA DESKTOP" << endl;
    }
private:
    Desktop():Computadora(){}
};
// Laptop class
class Laptop : public Computadora {
    friend class Computadora;
public:
    void tipoComp(){
        cout << "HAZ CREADO UNA LAPTOP" << endl;
    }
private:
    Laptop():Computadora(){}
};
// Netbook class
class Netbook : public Computadora {
    friend class Computadora;
public:
    void tipoComp(){
        cout << "HAZ CREADO UNA NETBOOK" << endl;
    }
private:
    Netbook():Computadora(){}
};
// Tablet class
class Tablet : public Computadora{
    friend class Computadora;
public:
    void tipoComp(){
        cout << "HAZ CREADO UNA TABLET" << endl;
    }
private:
    Tablet():Computadora(){}
};
// ServerRack class
class ServerRack : public Computadora {
    friend class Computadora;
public:
    void tipoComp(){
        cout << "HAZ CREADO UNA SERVER RACK" << endl;
    }
private:
    ServerRack():Computadora(){}
};
// ServerTower class
class ServerTower : public Computadora {
    friend class Computadora;
public:
    void tipoComp(){
        cout << "HAZ CREADO UNA SERVER TOWER" << endl;
    }
private:
    ServerTower():Computadora(){}
};
// main
int main(){
    int seleccion;
    Computadora* c = new Computadora;
    cout << "---------------------BIENVENIDO---------------------" << endl;
    cout << "Ingresar una de las siguientes computadoras a crear (Numero):" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "1. Desktop" << endl;
    cout << "2. Laptop" << endl;
    cout << "3. Netbook" << endl;
    cout << "4. Tablet" << endl;
    cout << "5. ServerRack" << endl;
    cout << "6. ServerTower" << endl;
    cout << "----------------------------------------------------" << endl;
    cin >> seleccion;
    if (seleccion == 1){
        Desktop *a = c-> nuevaComp<Desktop>();
        cout << "-----------------------" << endl;
        a->tipoComp();
        cout << "-----------------------" << endl;
        cout << "Procesos de la computadora: " << endl;
        cout << endl;
        a->seleccionComponentes();
        a->ensambladoComponentes();
        a->instalConfigSoftware();
        a->empaquetadoComp();
    } else if(seleccion == 2){
        Laptop *a = c-> nuevaComp<Laptop>();
        cout << "-----------------------" << endl;
        a->tipoComp();
        cout << "-----------------------" << endl;
        cout << "Procesos de la computadora: " << endl;
        cout << endl;
        a->seleccionComponentes();
        a->ensambladoComponentes();
        a->instalConfigSoftware();
        a->empaquetadoComp();
    } else if(seleccion == 3){
        Netbook *a = c-> nuevaComp<Netbook>();
        cout << "-----------------------" << endl;
        a->tipoComp();
        cout << "------------------------" << endl;
        cout << "Procesos de la computadora: " << endl;
        cout << endl;
        a->seleccionComponentes();
        a->ensambladoComponentes();
        a->instalConfigSoftware();
        a->empaquetadoComp();
    } else if (seleccion == 4){
        Tablet *a = c-> nuevaComp<Tablet>();
        cout << "------------------------" << endl;
        a->tipoComp();
        cout << "------------------------" << endl;
        cout << "Procesos de la computadora: " << endl;
        cout << endl;
        a->seleccionComponentes();
        a->ensambladoComponentes();
        a->instalConfigSoftware();
        a->empaquetadoComp();
    } else if(seleccion == 5){
        ServerRack *a = c-> nuevaComp<ServerRack>();
        cout << "-----------------------------" << endl;
        a->tipoComp();
        cout << "-----------------------------" << endl;
        cout << "Procesos de la computadora: " << endl;
        cout << endl;
        a->seleccionComponentes();
        a->ensambladoComponentes();
        a->instalConfigSoftware();
        a->empaquetadoComp();
    } else if (seleccion == 6){
        ServerTower *a = c-> nuevaComp<ServerTower>();
        cout << "-----------------------------" << endl;
        a->tipoComp();
        cout << "-----------------------------" << endl;
        cout << "Procesos de la computadora: " << endl;
        cout << endl;
        a->seleccionComponentes();
        a->ensambladoComponentes();
        a->instalConfigSoftware();
        a->empaquetadoComp();
    } else{
        cout << "Numero invalido" << endl;
    }
}
