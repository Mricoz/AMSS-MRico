// Mauricio Rico Zavala
#include <iostream>
using namespace std;

class Product {
public:
    void operation(){
        std::cout << "Estoy en operacion" << endl;
    }
    void operation2(){
        std::cout << "Estoy en operacion 2" << endl;
    }
};

class Creator{
private:
    virtual Product* createProduct(int type) = 0;
public:
    Product* factoryMethod(int type){
        Product *p = createProduct(type);
        p -> operation();
        return p;
    }
};

class CreatorA : public Creator{
public:
    Product* createProduct(int type){
        if(type == 1){
            return new Product;
        }
        return new Product;
    }
};

int main(int argr, char** argv){
    // Creator deberia de ser singleton
    // Creator concretos son constructor privado
    Creator* c = new CreatorA;
    Product* p = c->factoryMethod(1);
    p->operation2();

    delete p;
    delete c;
}
