// Feb 11, 2020
/*
  Dynamic Arrays
*/
#include <iostream>
#include <cstdlib>
using namespace std;

class DynamicArray{
	private:
		int* storage;
		int capacity;
		int nbOfElements;
	public:
		DynamicArray(int c = 10){
			capacity=c;
			nbOfElements=0;
			storage = new int[capacity];
		}
		void print(){
			cout<<"****************************\n";
			for (int i=0; i<nbOfElements; i++){
				cout<<*(storage+i)<<"\t"; //cout<<storage[i]<<"\t";
				if (i%4==3) cout<<endl;
			}
			cout<<"****************************\n";
		}

        // 공간을 늘려버리고 새로운 배열을 정의, 옮기고 기존 배열 메모리 초기화, 주소 가리키는곳 바꾸기. 
		void addElement(int x){
            if(capacity == nbOfElements){
                capacity *= 2;
                int *newStorage = new int[capacity];
                for (int i = 0; i < nbOfElements; i++){
                    *(newStorage+i) = *(storage+i);
                }
                delete [] storage; // 메모리 초기화
                storage = newStorage;
            }
			*(storage+nbOfElements) = x;
            nbOfElements++;
		}
        
		void removeElement(int x);  

        DynamicArray merge(DynamicArray obj){
            int totalCapacity = obj.capacity + capacity;
            DynamicArray newObj(totalCapacity);
            for (int i = 0; i < nbOfElements + obj.nbOfElements; i++){
                if (i >= nbOfElements){
                 *(newObj.storage+i) = *(obj.storage+i - nbOfElements);
                }
                else *(newObj.storage+i) = *(storage+i);
            }
            newObj.nbOfElements = nbOfElements + obj.nbOfElements;
            return newObj;
        }
};

// 찾은위치 다음꺼부터 왼쪽으로 옮기는거임 그냥 덮어쓰기 개념
void DynamicArray::removeElement(int x){
    for(int i = 0; i < nbOfElements; i++){
        if(x == storage[i]){
            for (int j = i; j < nbOfElements-1; j++)
            {
                *(storage+j) = *(storage+j+1);
            }
        }
    }
    nbOfElements--;
}

int main(){
	DynamicArray obj1;
	DynamicArray obj2;
	DynamicArray obj3;
	for (int i=0; i<5; i++){
		obj1.addElement(rand()%50);
		obj2.addElement(rand()%50);
	}
	for (int i=0; i<7; i++){
		obj1.addElement(rand()%50);
        obj2.addElement(rand()%50);
	}
	obj1.print();
    obj2.print();
    
    obj3 = obj1.merge(obj2);

    obj3.print();
    
	return 0;
}










