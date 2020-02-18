// Feb 11, 2020 Dynamic Array
/*
  Dynamic Arrays
  동적 배열이라는게 초기에는 디폴트값으로 배열 설정하고
  공간 부족할때마다 공간을 늘린 새로운 메모리에 모든걸 옮기고 기존 메모리 삭제하는거임.
  기존메모리공간도 delete []로 지우고.
*/
/*
    Explicit Constructor 관련해서

    DyanmicArray(int n = 10){} 이거 자체가 디폴트 생성자를 가지고 있는거임 (이렇게 가지고 있는거는 따로 안 써줘도됨)
    DynamicArray(int n){} 만약 이렇게 한다면
    DyanmicArray(){} 이렇게 디폴트 생성자를 써줘야됨. 그래야 나중에 DynamicArray obj1 = arr[3]; 이렇게 할당할때 문제가 안생긴다고함

    동일한 객체의 인스턴스는 private value 접근가능.
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
                delete [] storage; // memory delete
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

// move all element to the left after the element I wanted to delete.
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










