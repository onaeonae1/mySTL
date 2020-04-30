#include<iostream>
using namespace std;

template<class T>
class myVector{
public:
    int _size;
    int capacity;
    T *arr;
    myVector(){
        _size=0;
        capacity=32;
        arr=new T[capacity];
    }

    myVector(int n){
        _size=n;
        capacity=n;
        arr=new T[n];
    }

    ~myVector(){
        delete[] arr;
    }

    void clear(){
        _size = 0;
        capacity = 32;
        delete[] arr;
        arr = new T[capacity];
    }

    void resize(int n){
        T *temp = new T[n];
        for(int i=0;i<n;i++){
            temp[i]=arr[i];
        }
        delete[] arr;
        arr=temp;
        //If size is bigger than changed size
        if(n<_size){
            _size=n;
        }
        capacity = n;
    }

    void push_back(T val){
        if(_size==capacity){
            resize(_size*2);
        }
        arr[_size++]=val;
    }

    void pop_back(){
        _size--;
    }

    int size(){
        return _size;
    }

    T* begin(){
        return &arr[0];
    }

    T* end(){
        return &arr[0]+_size;
    }

    T& operator [](int idx){
        return arr[idx];
    }
};