#import <iostream>
#import <vector>
#import <string>
using namespace std;
// Subject class
class Subject{
public:
    string nombre;
    vector<Observer> observers;
    void newObserver(Observer o){
        observers.push_back(o);
    }
};
// Observer class
class Observer{
public:
    string name;
    void newNews(string news){
        cout << name << endl;
        cout << news << endl;
    }
};
// Trump class
class Trump: public Subject{
public:
    nombreTrump(){
        nombre = "Trump";
    }
};
// Kim class
class Kim: public Subject{
public:
    nombreKim(){
        nombre = "Kim";
    }
};
// Penia class
class Penia: public Subject{
public:
    nombrePenia(){
        nombre = "Penia";
    }
};
// MVS class
class MVS: public Observer{
public:
    nombreMVS(){
        nombre = "MVS";
    }
};
// Televisa class
class Televisa: public Observer{
public:
    nombreTelevisa(){
        nombre = "Televisa";
    }
};
//RadioR class
class RadioRed: public Observer{
public:
    nombreRadioRed(){
        nombre = "Radio Red";
    }
};
//IntNews class
class IntNews: public Observer{
public:
    nombreIntNews(){
        nombre = "Noticias Internacionales";
    }
};
// main
int main() {
    Trump trump;
    Penia penia;
    Kim kim;
    MVS mvs;
    RadioRed radio;
    IntNews intNews;
    Televisa televisa;

    penia.newObserver(televisa);
    kim.newObserver(intNews);
    trump.newObserver(mvs);

    return 0;
}
