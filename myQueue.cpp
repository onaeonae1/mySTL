#include<iostream>
using namespace std;

template<class T>
class myQueue{
    public:
    struct Node{
        T val; Node *next;
        Node() {}
        Node(T val):val(val),next(0){}
    };
    Node *head, *tail;
    int _size;
    
    myQueue(){
        head=tail=0;
        _size=0;
    }

    ~myQueue(){
        
    }

    void push(T val){
        Node* temp = new Node(val);
        if(head==0) head=tail=temp;
        else{
            tail->next = temp;
            tail=temp;
        }
        _size++;
    }

    void pop(){
        Node* temp=head;
        head = head->next;
        delete temp;
        _size--;
    }

    bool empty() const{
        return head->val;
    }

    T front(){
        return head->val;
    }

    T back(){
        return tail->val;
    }
};