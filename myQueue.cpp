#include<iostream>
using namespace std;
template<class T>
class myQueue {
private:
	struct Node {
		T val;  //값
		Node *next; //다음
		//노드 생성시 초기화
		Node() {
			val = (int)0; 
			next = (int)0;
		}
		~Node() {
			if (val == 0) {
				
			}
			else {
			
			}
		}
		Node(T val) :val(val), next(0) {}
	};
	Node* head;
	Node* tail;
	int _size;
public:
	myQueue() {
		//생성과 동시에 Node, head, tail 초기화
		head = tail = 0;
		_size = 0;
		
	}

	~myQueue() {
		//모든 노드들을 삭제해야 한다.
		while (this->getSize() > 0) {
			pop();
		}
		delete head;
	}

	void push(T val) {
		Node* temp = new Node(val);
		if (head == 0) head = tail = temp;
		else {
			tail->next = temp;
			tail = temp;
		}
		_size++;
	}

	void pop() {
		Node* temp = head;
		head = head->next;
		delete temp;
		_size--;
	}
	int getSize() {
		return this->_size;
	}
	bool empty() const {
		return head->val;
	}

	T front() {
		return head->val;
	}

	T back() {
		return tail->val;
	}
};
