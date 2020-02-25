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
        DNode(){
            prev = NULL;
            next = NULL;
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
        DNode* rear;
        int size;

    public:
        CircularList(){
            size = 0;
            front = NULL;
            rear = front;
        }

        void addFront(int x){
            DNode* target = front;
            DNode* newNode = new DNode;

            newNode->setElement(x);
            newNode->setNext(target);
            front = newNode;
            
            target->setPrev(newNode);
            rear->setNext(newNode);
            
            size++;
        }
        void addLast(int x){

        }
        void print(){
            DNode* currentNode = front;
            for (int i = 0; i < size; i++)
            {
                cout << (*currentNode).getElement() << endl;
                currentNode = currentNode->getNext();
            }
            cout << endl;
        }
        void remove(int x){
            
        }
};

int main(){
    CircularList list;

    list.addFront(9);
    list.print();
    list.addFront(10);
    list.addFront(20);
    list.print();

    return 0;
}