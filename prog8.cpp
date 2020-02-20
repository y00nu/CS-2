// Feb 13, Feb 18, Feb 20 Linked List
/*
    저번 dynamic array는 사이즈가 다 찰때마다 옮겨야되서 비효율적이었다.
    Linked List로 조금더 효율적으로 구현.
    객체(노드)에 값과, 다음 객체(노드)의 주소가 들어간다.
    메모리에 0값은 NULL이라고 함. (물론 0 써도 인식함)
*/
/*
    포인터로 하는 이유는 프로그램이 실행중일때 새로운 객체, 변수할당 등을 할 수 있는 방법이 포인터 밖에 없어서 그렇다.
*/

#include <iostream>
#include <cstdlib>
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
            Node* currentNode = front;
            Node* nodeBefore;
            Node* nodeAfter;

            for(int i = 0; i < size; i++){
                if((*currentNode).getElement() == x){
                    nodeAfter = (*currentNode).getNext();
                    (*nodeBefore).setNext(nodeAfter);
                    delete currentNode;
                    break;
                }
                nodeBefore = currentNode;
                currentNode = (*currentNode).getNext();
            }
		}

		void removeFront(){
            Node* frontNode = front;
            Node* secondNode = frontNode -> getNext(); // How to access to the element of the pointer (Pointer notation)

            delete frontNode;

            front = secondNode;
            size --;
		}

		void removeLast(){
            Node* lastNode;
            Node* nodeBefore = front;

            for(int i = 0; i<size-2; i++){
                nodeBefore = nodeBefore -> getNext();
            }
            nodeBefore->setNext(NULL);
            lastNode = nodeBefore->getNext();
            delete lastNode;
            size --;
        }

		void print(){
            Node* temp;
            temp = front;
            for(int i = 0; i < size; i++){
                cout << (*temp).getElement() << endl;
                temp = (*temp).getNext();
            }
            cout << "************" << endl;
		}

};

class MultiList{
    private:
        List** hook;
        int size;
        int nbOfLists;
    public:  
        int getSize(){ return size; }
        void setSize(int x){ size = x; }
        int getNbOfLists(){ return nbOfLists; }
        void setNbOfLists(int x){ nbOfLists = x;}
        List** getHook(){return hook;}
        void setHook(List** p){hook = p;}
        MultiList(int x = 2){
            size = 0;
            nbOfLists = x;
            hook = new List*[nbOfLists]; // nbOfLists 만큼의 list를 할당할 메모리를 만들겠다라는 의미
            
        }

        void addElement(int x){

        }

        void removeElement(int x){

        }

        void print(){

        }
};
int main(){
	List obj1;
    // Add 5 nodes to node list
	for (int i = 5; i>=1; i--){
        obj1.addFront(i);
    } 
    obj1.print();

    Node* temp=obj1.getFront();
    // Hold the 4th node
    for (int j=0; j<3; j++){
        temp=(*temp).getNext();
    }

    // Add after 4th node
    obj1.addAfter(5000,temp);
    obj1.print();

    // Add before 4th node
    obj1.addBefore(1000,temp);
    obj1.print();

    // remove last node
    obj1.removeLast();
    obj1.print();

    // remove front node
    obj1.removeFront();
    obj1.print();

    // remove 4
    obj1.remove(4);
    obj1.print();


    MultiList obj2(4);
    for (int i = 0; i < 20; i++)
    {
        obj2.addElement(rand()%501);
    }

    obj2.print();
	return 0;
}











