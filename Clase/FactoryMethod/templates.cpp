// Mauricio Rico Zavala
#include <iostream>
using namespace std;
// Clase padre
class FactoryProduct{
public:
    template <class Prod>
    Prod* factoryMethod(){
        return new Prod;
    }
};
// Clase hijo
class ProductA : public FactoryProduct{
public:
    void operation(){
        std::cout << "Estoy en el producto A" << endl;
    }
};

int main(){
    FactoryProduct* p = new FactoryProduct;
    ProductA *a = p-> factoryMethod<ProductA>();
    a->operation();
}
