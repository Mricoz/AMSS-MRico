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
    void addPlayer(C value){
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

template<class C, class Function>
void find_if(Collection<C> coll, Function f){
    Iterator<C>* it = coll.getIterator();
    while(it->hasNext()){
        f(it->next());
    }
}

template<class C>
void even(C n){
    if (n % 2 == 0){
        cout << n << endl;
    }
}

int main(){
    Collection<int> i;
    i.addElement(45);
    i.addElement(22);
    i.addElement(4);
    i.addElement(89);
    Iterator<int>* it = i.getIterator();
    find_if<int, void(*)(int)> (i, even);
    delete it;
}
