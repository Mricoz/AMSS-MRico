#include <iostream>
using namespace std;

class Singleton {
public:
    // Constructor
    Singleton() = default;
  // Funciones
  static Singleton* getInstance(){
    if(!instance){
        instance = new Singleton;
    }
    return instance;
  }
  void operation(){
    cout << "Dir de Sing:" << instance << endl;
  }
protected:
  // Variable
  static Singleton* instance;
};

Singleton* Singleton::instance = 0;

int main(int argr, char** argv){
  Singleton s;
  s.operation();
  // Singleton 1
  Singleton* instance = Singleton::getInstance();
  instance -> operation();
  // Singleton 2
  Singleton* instance2 = Singleton::getInstance();
  instance2 -> operation();
  // Singleton 3
  Singleton* instance3 = Singleton::getInstance();
  instance3 -> operation();
}
