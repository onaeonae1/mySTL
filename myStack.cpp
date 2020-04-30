#include<iostream>
using namespace std;

template<class T>
class myStack{
public:
    struct Node{
        T val; Node *next;
        Node() {}
        Node(T val):val(val),next(0){}
    };
    Node *head;
    int _size;
    
    myStack(){
        head=0;
        _size=0;
    }

    ~myStack(){
        if(_size!=0){
            Node *temp, *n_temp;
            temp = head;
            n_temp = temp->next;
            while(temp!=0){
                delete temp;
                temp = n_temp;
                if(temp!=0) n_temp = temp->next;
            }
        }
    }

    void clear(){
        if(_size!=0){
            Node *temp, *n_temp;
            temp = head;
            n_temp = temp->next;
            while(temp!=0){
                delete temp;
                temp = n_temp;
                if(temp!=0) n_temp = temp->next;
            }
        }
        head=0;
        _size=0;
    }

    void push(T val){
        Node *temp = new Node(val);
        if(head==0){
            head = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        _size++;
    }

    void pop(){
        Node *temp = head;
        head = head -> next;
        delete temp;
        _size--;
    }

    T top(){
        return head->val;
    }

    int size() const{
        return _size;
    }

    bool empty(){
        return _size==0;
    }
};