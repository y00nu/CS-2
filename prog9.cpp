// Feb 25
// Circular List
#include <iostream>
#include <cstdlib>

using namespace std;

class DNode{
    private:
        DNode* prev;
        DNode* next;
        int element;
    
    public:
        DNode(DNode* x = NULL, DNode* y = NULL){
            next = x;
            prev = y;
            element = 0;
        }
        void setElement(int x){
            element = x;
        }
        int getElement(){
            return element;
        }
        void setNext(DNode* x){
            next = x;
        }
        DNode* getNext(){
            return next;
        }
        void setPrev(DNode* x){
            prev = x;
        }
        DNode* getPrev(){
            return prev;
        }
};

class CircularList{
    private:
        DNode* front;
        DNode* last;
        int size;

    public:
        CircularList(){
            size = 0;
            front = NULL;
            last = front;
        }

        void addFront(int x){
            // In case there's no node in the list
            if(size == 0){
                DNode* newNode = new DNode;
                (*newNode).setElement(x);
                front = newNode;
                last = newNode;
                size++;
            }
            else{
                DNode* prevFront = front;
                // DNode(next, prev)
                DNode* newNode = new DNode(prevFront, last);
                (*newNode).setElement(x);
                front = newNode;
                (*prevFront).setPrev(newNode);
                (*last).setNext(front);
                size++;
            }
        }

        void addLast(int x){
            // In case there's no node in the list
            if(size == 0){
                DNode* newNode = new DNode;
                (*newNode).setElement(x);
                front = newNode;
                last = newNode;
                size++;
            }
            else{
                DNode* lastNode = last;
                DNode* newNode = new DNode;
                (*newNode).setElement(x);
                (*lastNode).setNext(newNode);
                (*newNode).setPrev(lastNode);
                (*newNode).setNext(front);
                (*front).setPrev(newNode);
                last = newNode;
                size++;
            }
        }

        void print(){
            DNode* currentNode = front;
            for (int i = 0; i < size; i++)
            {
                cout << (*currentNode).getElement() << "\t";
                currentNode = currentNode->getNext();
            }
            cout << endl;
        }

        void printReverse(){
            DNode* currentNode = last;
            for (int i = 0; i < size; i++)
            {
                cout << (*currentNode).getElement() << "\t";
                currentNode = currentNode->getPrev();
            }
            cout << endl;
        }

        void remove(int x){
            DNode* temp = front;
            // for identifying the case
            int c = 0;
            for (int i = 0; i < size; i++)
            {
                if((*temp).getElement() == x){
                    c = i + 1;
                    break;
                }
                temp = (*temp).getNext();
            }

            if(c == 0){
                cout << x << " is not in the list" << endl;
            }
            // case 1 : if x was the first node ( c == 0 )
            else if (c == 1) 
            {
                DNode* nextNode;
                nextNode = (*front).getNext();
                last->setNext(nextNode);
                nextNode->setPrev(last);
                delete front;
                front = nextNode;
                size--;
            }
            // case 2 : if x was the last node ( c == size )
            else if(c == size){
                DNode* prevNode;
                prevNode = last->getPrev();
                prevNode->setNext(front);
                front->setPrev(prevNode);
                delete last;
                last = prevNode;
                size--;
            }
            // case 3 : located in the middle
            else{
                DNode* prevNode;
                DNode* nextNode;
                prevNode = (*temp).getPrev();
                nextNode = (*temp).getNext();

                prevNode->setNext(nextNode);
                nextNode->setPrev(prevNode);
                
                delete temp;
            }
        }
};

int main(){
    CircularList list;

    for(int i = 0; i<10; i++){
        list.addFront((1 + rand() % 100));
    }
    cout << "print forward" << endl;
    list.print();
    cout << endl;

    cout << "print reverse" << endl;
    list.printReverse();
    cout << endl;

    cout << "Add last" << endl;
    list.addLast(100);
    list.print();
    cout << endl;

    cout << "Remove last node" << endl;
    list.remove(100);
    list.print();
    cout << endl;

    cout << "Remove first node" << endl;
    list.remove(10);
    list.print();
    cout << endl;
    
    cout << "Try to remove a node which doesn't exists" << endl;
    list.remove(1);
    cout << endl;

    cout << "Remove a node in the middle" << endl;
    list.remove(45);
    list.print();
    cout << endl;

    return 0;
}