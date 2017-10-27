template <class I>
Iterator<I>* Collection<I>::getIterator(){
  return new Iterator<I>(*this);
}

template<class C, class Function, class T >
void find_if(Collection<C> coll, Function func, T object2){
  Iterator<C>* it = coll.getIterator();
  while (it->hasNext())
    func(it->next(), object2);
}

template<class C, class T>
void collision(C object, T object2 ){
  if (object->getX() == object2->getX() && object->getY() ==  object2->getY() && object->getID() != object2->getID()
  && object->getID()!=0 && object2->getID()!=0){
    std::cout << object2->getType()<< " collisioned with " << object->getType() << " and it was killed!" <<'\n';
    object2->kill();
  }
}

typedef void(*funcion)(General *, General *);

int main (){

    find_if<General*, funcion, General*> (i, collision, ship);

    find_if<General*, funcion, General*> (i, collision, asteroid);

    find_if<General*, funcion, General*> (i, collision, planet);

    find_if<General*, funcion, General*> (i, collision, g1);

    find_if<General*, funcion, General*> (i, collision, g2);

    find_if<General*, funcion, General*> (i, collision, g3);

    find_if<General*, funcion, General*> (i, collision, g4);
