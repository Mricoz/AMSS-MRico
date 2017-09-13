/*
    Mauricio Rico
    A01370874
    13/09/17
    " iterator templates "
*/

#include <iostream>
using namespace std;
template<class I>
class Iterator;

template<class C>
class Collection{
protected:
    C* array;
    int size;
    int cont;
public:
    friend class Iterator<C>;
    Collection(){
        size = 10;
        array = new C[10];
        cont = 0;
    }
    void addElement(C value){
        if(cont <= size){
            array[cont++] = value;
            return;
        } else{
            cout << "ya no hay espacio para agregar elementos" << endl;
        }
    }
    Iterator<C>* getIterator();
    C at(int pos){
        return array[pos];
    }
};
template <class I>
class Iterator{
protected:
    Collection<I> coll;
    int cont = 0;
public:
    Iterator(const Collection<I>& coll) : coll(coll){}
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
template<class I>
Iterator<I>* Collection<I>::getIterator(){
    return new Iterator<I>(*this);
}

int main(){
    Collection<string> i;
    i.addElement("lo");
    i.addElement("que");
    i.addElement("sea");
    i.addElement("lol");
    Iterator<string>* it = i.getIterator();
    while(it->hasNext()){
        cout << it->next() << endl;
    }
    delete it;
}
