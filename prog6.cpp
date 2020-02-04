// Feb 4, 2020
 /* 
    *(ptr2+1) = 20; // pointer notation
    ptr2[2] = 30; // array notation
    포인터와 배열이 근본적으로 동일하기때문에 어떤 표기방식을 사용하던 접근이 가능하다.

    배열은 메모리상에서 오름차순으로 증가, 일반 변수는 감소되면서 메모리 주소에 들어감.
    (들어가는 공간은 순차적, 연속적임, 랜덤으로 아무대나 받아오는게아님)

    array[10]에서 array = array[0]의 주소와 같은값임. (address of the first element)

    ***Pointer 개념***
    새로운 메모리 Location에 다른 메모리 주소값을 저장하는것 indirect address라고한다.
    int *p 
    (타입 지정을 해서 알아서 메모리 바이트에 해당하는 값만큼 할당할수있음 int는 4바이트씩 자동으로 할당)
    p는 주소값이고 *p는 주소의 있는 값을 의미한다 (give me a value what you are poining)

    int *ptr2 = new int[4]; // using dynamic memory
    다이나믹 메모리로 할당할때 사용하는 new int 키워드

    static memory랑 dynamic memory랑 저장되는 곳이 다름. */
#include <iostream>
#include <cstdlib>

using namespace std;

void print(int *p, int size){
    for(int i = 0; i < size; i++){
        cout << *(p+i) << " ";
    }
    cout << endl;
}

void fill(int *p, int size){
    for (int i = 0; i < size; i++)
    {
        *(p+i) = 1 + rand() % 99;
    }
}

void move(int *p, int *q, int size){
    for (int i = 0; i < size; i++)
    {
         *(q+i) = *(p+i);
    }
}


int main()
{   

    int *p = new int[10];
    int *q = new int;


    fill(p, 10);
    print(p, 10);
    cout << endl;

    q = p;

    cout << *q << endl;
    cout << *(q+1) << endl;

    // move(p,p2, 10);


    return 0;
}