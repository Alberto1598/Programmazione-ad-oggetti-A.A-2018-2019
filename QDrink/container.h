#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
template <typename T>
class container{
private:
    T* info;
    unsigned int size;
    unsigned int capacity;
    void reserve(); // funzione che raddoppia la capacity del vector
    T* copy() const;
public:
    class iterator{
    friend class container;
    private:
        T*p;
        iterator( T* =0);
    public:
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        bool operator < (const iterator&) const;
        bool operator <=(const iterator&) const;
        bool operator > (const iterator&) const;
        bool operator >=(const iterator&) const;
        iterator& operator +(int) const;
        iterator& operator -(int) const;
        iterator& operator +=(int);
        iterator& operator -=(int);
        T& operator* () const;
        T* operator-> () const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);

    };
    class const_iterator{
    friend class container;
    private:
        const T*ptr;
        const_iterator(const T* =0);
    public:
        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
        bool operator < (const const_iterator&) const;
        bool operator <=(const const_iterator&) const;
        bool operator > (const const_iterator&) const;
        bool operator >=(const const_iterator&) const;
        const_iterator& operator +(int) const;
        const_iterator& operator -(int) const;
        const T& operator* () const;
        const T* operator->() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
    };
    container (const T&, unsigned int=5);// costruisce un container con size=capacity e con size occorrenze del parametro T& passato per riferimento costante. Mette di default size=capacity=5
    container( unsigned int=5); // costruisce un container vuoto con size=0 e capacity= parametro passato per valore. Mette di default capacity=5
    ~container();
    container (const container&);
    container& operator= (const container&);
    unsigned int getSize() const;
    unsigned int getCapacity() const;
    T& operator [] (unsigned int) const;
    bool isEmpty() const;
    void clear();
    T& at(unsigned int) const;
    void insert(iterator, const T&);
    void erase( iterator);
    void erase(unsigned int);
    void push_back( const T&);
    void pop_back();
    iterator begin() const;
    iterator end()const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    T& front();
    T& back();
    int search(const T&) const;
};
// iteratori
template <typename T>
container<T> :: iterator :: iterator(T*v): p(v) {};
template <typename T>
bool container<T> :: iterator :: operator ==(const iterator& it) const{
    return p==it.p;
}
template <typename T>
bool container<T> :: iterator :: operator!=(const iterator& it) const{
    return p!=it.p;
}
template <typename T>
bool container<T> :: iterator :: operator<(const iterator& it) const{
    return p<it.p;
}
template <typename T>
bool container<T> :: iterator :: operator<=(const iterator& it) const{
    return p<=it.p;
}
template <typename T>
bool container<T> :: iterator :: operator>(const iterator& it) const{
    return p>it.p;
}
template <typename T>
bool container<T> :: iterator :: operator>=(const iterator& it) const{
    return p>=it.p;
}
template <typename T>
typename container<T> :: iterator&  container<T>:: iterator:: operator +(int x) const{
    return p+x;
}
template <typename T>
typename container<T> :: iterator&  container<T>:: iterator:: operator -(int x) const{
    return p-x;
}
template <typename T>
typename container<T> :: iterator&  container<T>:: iterator:: operator +=(int x) {
    p+=x;
    return *this;
}
template <typename T>
typename container<T> :: iterator&  container<T>:: iterator:: operator -=(int x){
    p-=x;
    return *this;
}
template <typename T>
T& container<T>:: iterator:: operator *() const{
    return *p;
}
template <typename T>
T* container<T>:: iterator:: operator ->() const{
    return p;
}
template <typename T>
typename container<T> :: iterator&  container<T>:: iterator:: operator ++(){
    if(p) ++p;
    return *this;
}
template <typename T>
typename container<T> :: iterator  container<T>:: iterator:: operator ++(int){
    if(p) p++;
    return *this;
}
template <typename T>
typename container<T> :: iterator&  container<T>:: iterator:: operator --(){
    if(p)  --p;
    return *this;
}
template <typename T>
typename container<T> :: iterator  container<T>:: iterator:: operator --(int){
    if(p) p--;
    return *this;
}
// iteratori costanti
template <typename T>
container<T> :: const_iterator :: const_iterator(const T*v): ptr(v) {};
template <typename T>
bool container<T> :: const_iterator :: operator ==(const const_iterator& it) const{
    return ptr==it.ptr;
}
template <typename T>
bool container<T> :: const_iterator :: operator!=(const const_iterator& it) const{
    return ptr!=it.ptr;
}
template <typename T>
bool container<T> :: const_iterator :: operator<(const const_iterator& it) const{
    return ptr<it.ptr;
}
template <typename T>
bool container<T> :: const_iterator :: operator<=(const const_iterator& it) const{
    return ptr<=it.ptr;
}
template <typename T>
bool container<T> :: const_iterator :: operator>(const const_iterator& it) const{
    return ptr>it.ptr;
}
template <typename T>
bool container<T> :: const_iterator :: operator>=(const const_iterator& it) const{
    return ptr>=it.ptr;
}
template <typename T>
typename container<T> :: const_iterator&  container<T>:: const_iterator:: operator +(int x) const{
    return ptr+x;
}
template <typename T>
typename container<T> :: const_iterator&  container<T>:: const_iterator:: operator -(int x) const{
    return ptr-x;
}
template <typename T>
const T& container<T>:: const_iterator:: operator *() const{
    return *ptr;
}
template <typename T>
const T* container<T>:: const_iterator:: operator ->() const{
    return ptr;
}
template <typename T>
typename container<T> :: const_iterator&  container<T>:: const_iterator:: operator ++(){
    if(ptr) ++ptr;
    return *this;
}
template <typename T>
typename container<T> :: const_iterator  container<T>:: const_iterator:: operator ++(int){
    if(ptr) ptr++;
    return *this;
}
template <typename T>
typename container<T> :: const_iterator&  container<T>:: const_iterator:: operator --(){
    if(ptr)  --ptr;
    return *this;
}
template <typename T>
typename container<T> :: const_iterator  container<T>:: const_iterator:: operator --(int){
    if(ptr) ptr--;
    return *this;
}
// metodi del container
template <typename T>
T* container<T>::  copy() const
{
    T*b= new T[capacity];
    if(size) for(int i=0; i<size; i++) b[i]=info[i];
    return b;

}
template <typename T>
void container<T>:: reserve()
{
    unsigned int newcapacity=capacity*2;
    T*b= new T[newcapacity];
    for(unsigned int i=0; i<size; i++) b[i]=info[i];
    if(info) delete [] info;
    capacity=newcapacity;
    info=b;
}
template <typename T>
container<T> :: container(const T& p, unsigned int c): info(new T[c]), size(c), capacity(c) {
    for(unsigned int i=0; i<capacity; i++){
        info[i]=p;
    }
};
template <typename T>
container<T> :: container(unsigned int c): info(new T[c]), size(0), capacity(c) {};
template <typename T>
container<T> :: ~container()  {if (info) delete[] info; };
template <typename T>
container<T> :: container (const container& c) : info(c.copy()), size(c.size), capacity(c.capacity){};
template <typename T>
container<T>& container<T>:: operator=(const container& c){
    if(this != &c){
    if(info) delete[] info;
     info= c.copy();
     size=c.size;
     capacity=c.capacity;
    }
    return *this;
}
template <typename T>
unsigned int container<T> :: getSize() const{
    return size;
}
template <typename T>
unsigned int container<T> :: getCapacity() const{
    return capacity;
}
template <typename T>
T& container<T>::operator[] (unsigned int x) const{
    return info[x];
}
template <typename T>
bool container<T> :: isEmpty() const{
    return size==0;
}
template <typename T>
void container<T>:: clear(){
    if(info) delete[] info;
    info= new T[capacity];
    size=0;
}
template <typename T>
T& container<T> :: at (unsigned int i) const{
    if((i<0) || (i>size-1)) throw std::out_of_range ("indice fuori dal vettore");
    return info[i];
}
template <typename T>
void container<T> :: insert (iterator it, const T& t){
    if(size==capacity) reserve();
    unsigned int index=it.p-info; // differenza tra puntatori che restituisce un intero che è la distanza tra l'iteratore e l'elemento inziale del container
    if ((index<0) || (index>size-1)) throw std::out_of_range("Impossibile effettuare l'inserimento, indice fuori range");
    for(unsigned int i=size; i>index; i--){
        info[i]=info[i-1];
    }
    info[index]=t;
    size=size+1;
}
template <typename T>
void container<T> :: erase(iterator it){
    unsigned int index=it.p-info;
    if(index>size-1) throw std::out_of_range("Impossibile effettuare la cancellazione, iteratore fuori dal range");
    for(unsigned int j=index; j<size-1; j++){
        info[j]=info[j+1];
    }
    size--;
}
template <typename T>
void container<T> :: erase(unsigned int index){
    if(index>size-1) throw std::out_of_range("Impossibile effettuare la cancellazione, indice fuori dal range");
    for(unsigned int j=index; j<size-1; j++){
        info[j]=info[j+1];
    }
    size--;
}
template <typename T>
void container<T>:: push_back(const T& t){
    if(size>=capacity) reserve();
    info[size++]= t;
}
template <typename T>
void container<T>:: pop_back(){
    size>0? --size: 0;
}
template <typename T>
typename container<T>:: iterator container<T> :: begin() const {
    return iterator(info);
}
template <typename T>
typename container<T>:: iterator container<T> :: end() const {
    return iterator(info+size);
}
template <typename T>
typename container<T>:: const_iterator container<T> :: cbegin() const {
    return const_iterator(info);
}
template <typename T>
typename container<T>:: const_iterator container<T> :: cend() const {
    return const_iterator(info+size);
}
template <typename T>
T& container<T>:: front(){
    return *info;
}
template <typename T>
T& container<T>:: back(){
    return info[size-1];
}
template <typename T>
int container<T>:: search( const T& p) const{             // ritorna l'indice dell'elemento ricercato altrimenti ritorna -1
    if(size==0) std::cout<< "container vuoto" << std::endl;
    else{
        int index=-1;
        bool trovato= false;
        for(int i=0; i<size && !trovato; i++){
            if(p==info[i]){
                index=i;
                trovato=true;
            }
        }
        return index;
    }

}
#endif // VECTOR_H
