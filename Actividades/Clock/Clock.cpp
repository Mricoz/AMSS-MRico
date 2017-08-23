// Mauricio Rico Zavala
#include <iostream>
#include <ctime>
using namespace std;

class Clock {
private:
  // Constructor
  Clock() = default;
public:
  // Funciones
  static Clock* getInstance(){
    if(!instance){
        instance = new Clock;
    }
    return instance;
  }
  void operation(){
    time_t rawtime;
    time (&rawtime);
    std::cout << "Time" << ctime(&rawtime) << endl;
  }
protected:
  // Variable
  static Clock* instance;
};

Clock* Clock::instance = 0;

int main(int argr, char** argv){
  // Singleton 1
  Clock* instance = Clock::getInstance();
  instance -> operation();
  // Singleton 2
  Clock* instance2 = Clock::getInstance();
  instance2 -> operation();
  // Singleton 3
  Clock* instance3 = Clock::getInstance();
  instance3 -> operation();
}
