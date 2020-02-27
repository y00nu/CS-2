// Feb 27
// Circular List we did in class.
#include <iostream>

using namespace std;
class DNode{
	private:
		int element;
		DNode* next;
		DNode* prev;	
	public:
		DNode(int x=0, DNode* n=NULL,DNode* p=NULL){
			element=x;
			next=n;
			prev=p;
		}
		int getElement(){return element;}
		void setElement(int x){element=x;}
		DNode* getNext(){return next;}
		void setNext(DNode* n){next=n;}
		DNode* getPrev(){return prev;}
		void setPrev(DNode* n){prev=n;}
		
};
class CircularList{
	private:
		int size;
		DNode* front;
		DNode* rear;
	public:
		CircularList(){
			size=0;
			front=NULL;
			rear=NULL;
		}
		void addFront(int x){
			if (size==0){
				front=new DNode(x);
				rear=front;
				front->setNext(front);
				front->setPrev(front);
			}else{
				DNode* temp=new DNode(x,front, rear);
				front->setPrev(temp);
				rear->setNext(temp);
				front=temp;
			}
			size++;
		}
		void addrear(int x){
			if (size==0){
				front=new DNode(x);
				rear=front;
				front->setNext(front);
				front->setPrev(front);
			}else{
				DNode* temp=new DNode(x,front, rear);
				front->setPrev(temp);
				rear->setNext(temp);
				rear=temp;
			}
			size++;
		}
		void remove(int x){
			if (size>0){
				DNode* temp=front;
				int cnt = 0;
				for (int i=0; i<size; i++){
					if (temp->getElement()==x){
						 cnt = i + 1;
						break;
					}
					else{
						temp=temp->getNext();
					}
				}
				if (temp->getElement()==x){
					if (size==1){
						front=rear=NULL;
						delete temp;
					}else{
						// first node
						if(cnt == 1){
							DNode* nextNode = temp->getNext();
							rear->setNext(nextNode);
                    		nextNode->setPrev(rear);
							delete front;
							front = nextNode;
						}
						// last node
						else if(cnt == size){
							DNode* prevNode = rear->getPrev();
							prevNode->setNext(front);
							front->setPrev(prevNode);
							delete rear;
							rear = prevNode;
						}
						// node in the middle
						else{
							DNode* prevNode = temp->getPrev();
							DNode* nextNode = temp->getNext();
							prevNode->setNext(nextNode);
							nextNode->setPrev(prevNode);
							delete temp;
						}
					}
					size--;
				}
			}
		}
		void print(int rep=1){
			cout<<"************************\n";
			DNode* temp=front;
			for (int i=0; i<rep*size; i++){
				cout<<temp->getElement()<<endl;
				temp=temp->getNext();
			}
		}
		void removeRear(){
			if(size > 0){
				if(size == 1){
					delete rear;
					front = rear = NULL;
				}
				else{
					DNode* prevNode = rear->getPrev();
					prevNode->setNext(front);
					front->setPrev(prevNode);
					delete rear;
					rear = prevNode;
				}
				size--;
			}
		}
		void removeFront(){
			if (size > 0){
				if(size == 1){
					delete front;
					front = rear = NULL;
				}
				else{
					DNode* nextNode = front->getNext();
					nextNode->setPrev(rear);
					rear->setNext(nextNode);
					delete front;
					front = nextNode;
				}
				size --;
			}
		}
		
};
int main(){
	CircularList obj1;
	for (int i=0; i<5; i++){
		obj1.addFront(20+i*100);
		obj1.addrear(50+i*1000);
	}
	// obj1.addFront(100); test for the case : only 1 element in the list
	
	obj1.print();

	obj1.removeRear();
	obj1.print();

	obj1.remove(120); // node in the middle 
	obj1.print();

	obj1.remove(420); // node in the front
	obj1.print();

	obj1.remove(3050); // node in the last
	obj1.print();


	
	return 0;
}