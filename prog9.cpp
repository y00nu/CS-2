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
            if(size == 0){
                DNode* newNode = new DNode;
                newNode->setElement(x);
                front = newNode;
                last = newNode;
                size++;
            }
            else{
                DNode* prevFront = front;
                DNode* newNode = new DNode(prevFront, last);
                newNode->setElement(x);
                front = newNode;
                prevFront->setPrev(newNode);
                last->setNext(front);
                size++;
            }
        }
        void addLast(int x){

        }
        void print(){
            DNode* currentNode = front;
            cout << "Print forward  : ";
            for (int i = 0; i < size; i++)
            {
                cout << (*currentNode).getElement() << "\t";
                currentNode = currentNode->getNext();
            }
            cout << endl;
        }
        void printReverse(){
            DNode* currentNode = last;
            cout << "Print backward : ";
            for (int i = 0; i < size; i++)
            {
                cout << (*currentNode).getElement() << "\t";
                currentNode = currentNode->getPrev();
            }
            cout << endl;
        }
        void remove(int x){
            // DNode* currentNode;
            // for(int i = 0; i < size; i++){
                
            // }
        }
};

int main(){
    CircularList list;

    for(int i = 0; i<10; i++){
        list.addFront((1 + rand() % 100));
    }

    list.print();
    list.printReverse();

    return 0;
}