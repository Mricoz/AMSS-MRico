#include <iostream>
#include <string>

using namespace std;
// Motor class
class Motor {
    int potencia;
    int numSerie;
public:
    Motor() = default;
    Motor(int pot, int nS) : potencia(pot), numSerie(nS){} // lo que se le olvida a luis
    int getPotencia() { return potencia; }
    int getNumSerie() { return numSerie; }
};
//A las class
class Alas {
    string marca;
    int numSerie;
    int hyper;
    int spoilers;
public:
    Alas() = default;
    Alas(string m, int n, int h, int s) : marca(m), numSerie(n), hyper(h), spoilers(s){} // lo que se le olvida a luis
    string getMarca(){ return marca; }
    int getNumSerie(){ return numSerie; }
    int getHyper(){ return hyper; }
    int getSpoiler(){ return spoilers; }

};
class Builder;
// Avion class
class Avion {
    friend class Builder;
    friend class BoeingBuilder;
    Alas* alas;
    Motor* motor;
    string marca;
    string modelo;
    int numSerie;
    void setAlas(Alas* a){ alas = a;}
    void setMotor(Motor* m){ motor = m;}
    void setMarca(string ma){ marca = ma;}
    void setModelo(string mod){ modelo = mod;}
    void setNumSerie(int num){ numSerie = num;}
public:
    string getMarca(){ return marca; }
    string getModelo(){ return modelo; }
    int getNumSerie(){ return numSerie; }
    Alas* getAlas() { return alas; }
    Motor* getMotor() { return motor; }
};
// Builder class
class Builder {

protected:
    Avion* avion;
public:
    Avion* getAvion(){ return avion; }
    void createAvion(){
        avion = new Avion();
    }
    virtual Motor* buildMotor() = 0;
    virtual Alas* buildAlas() = 0;
    virtual string buildMarca() = 0;
    virtual string buildModelo() = 0;
    virtual int buildNumSerie() = 0;
};
// BoeingBuilder class
class BoeingBuilder : public Builder {
public:
    Motor* buildMotor(){
        Motor* motor = new Motor(10000, 11111);
        avion->setMotor(motor);
        return motor;
    }
    Alas* buildAlas(){
        Alas* alas = new Alas("boeing", 101010, 10, 10);
        avion->setAlas(alas);
        return alas;
    }
    string buildMarca(){
        avion->setMarca("Boeing");
        return avion->getMarca();
    }
    string buildModelo(){
        avion->setModelo("722");
        return avion->getModelo();;
    }
    int buildNumSerie(){
        return 234453;
    }
};
// Director class
class Director{
    Builder* builder;
public:
    void setBuilder(string tipoAvion){
        if (tipoAvion == "Boeing"){
            builder = new BoeingBuilder;
        }
    }
    Avion* getAvion(){
        return builder->getAvion();
    }
    void construct(){
        builder->createAvion();
        builder->buildAlas();
        builder->buildModelo();
        builder->buildMarca();
        builder->buildNumSerie();
        builder->buildMotor();
    }
};

int main(){
    Director d;
    d.setBuilder("Boeing");
    d.construct();
    Avion* a = d.getAvion();
    cout << a->getModelo() << endl;

    return 0;
}
