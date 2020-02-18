// Feb 13, Feb 18 Linked List
/*
    저번 dynamic array는 사이즈가 다 찰때마다 옮겨야되서 비효율적이었다.
    Linked List로 조금더 효율적으로 구현.
    객체(노드)에 값과, 다음 객체(노드)의 주소가 들어간다.
    메모리에 0값은 NULL이라고 함. (물론 0 써도 인식함)
*/
// 왜 포인터로 할수밖에 없는지? 그냥 객체 자체를 또 다른 객체안에 넣을수 없는건가?
#include <iostream>
using namespace std;
class Node{
	private:
		int element;
		Node* next; // Node's pointer
	public:
		Node(int x=0, Node* p=NULL){
			element=x;
			next=p;
		}
		int getElement(){return element;}
		void setElement(int x){element=x;}
		Node* getNext(){return next;}
		void setNext(Node* x){next=x;}
};

class List{
	private:
		Node* front;
		int size;

	public:
		Node* getFront(){return front;}
		void setFront(Node* x){front=x;}
		int getSize(){return size;}
		void setSize(int x){size=x;}
		List(){
            size = 0;
            front = NULL;
		}
		void addFront(int x){
            Node *temp = new Node(x, front);
            front = temp;
            size++;
		} 

		void addLast(int x){
            // create new node
            Node* last = new Node(x);

            Node* temp = front;

            // Move to last node
            for(int i = 1; i < size; i++){
                temp = (*temp).getNext();
            }

            // link last node
            (*temp).setNext(last);
            size++;
		}

		void addBefore(int x, Node* p){
                // error
                if(p == NULL){
                    cout << "Can't add" << endl;
                }
                else{
                    //create node
                    Node *currentNode  = new Node(x);

                    Node *nodeBefore = front;
                    Node *nodeAfter;

                    for(int i = 0; i<size; i++){
                        if((*nodeBefore).getNext() == p){
                            nodeAfter = (*nodeBefore).getNext();
                            break;
                        }
                         nodeBefore = (*nodeBefore).getNext();
                    }
                    
                    (*nodeBefore).setNext(currentNode);
                    (*currentNode).setNext(nodeAfter);
                    size++;
                }

		}

		void addAfter(int x, Node* p){
            if(p == NULL){
                addFront(x);
            }
            else{
                // create new node
                Node *temp = new Node;

                (*temp).setNext((*p).getNext());
                (*temp).setElement(x);
                (*p).setNext(temp);
                size++;
            }
		}

		void remove(int x){
		}

		void removeFront(){
		}

		void removeLast(){
		}

		void print(){
            Node* temp;
            temp = front;

            for(int i = 0; i < size; i++){
                cout << (*temp).getElement() << endl;
                temp = (*temp).getNext();
            }
		}

};
int main(){
	List obj1;
	for (int i = 0; i<4; i++){
        obj1.addFront(10+i*100);
        obj1.addLast(20 + 100 * i);
    }  
    obj1.print();
    Node* temp=obj1.getFront();
    for (int j=0; j<4; j++){
        temp=(*temp).getNext();
    }
    obj1.addAfter(5000,temp);
    obj1.print();
	return 0;
}











