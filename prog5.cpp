// Friend Keyword
// 함수안에 타입만 쓰고 인자값 이름 안쓰고 선언해도된다.
/* 컴퓨터는 바이트단위인데 비트단위로 접근하려면 비트연산으로 필터 처리를 한다.
   인덱스는 비트단위기 때문에 비트단위 접근을 해야할때가 있음 */
// &연산자는 변수의 주소를 반환하는 연산자임
#include <iostream>
#include <cstdlib>

using namespace std;

class SimplePoint{
    private:
        int num1;
        int num2;

    public:
        SimplePoint(){
            num1  = 10 + rand() % 41; 
            num2  = 10 + rand() % 41; 
        }

        SimplePoint(int x, int y){
            num1 = x;
            num2 = y;
        }

        void print(){
            cout << num1 << " " << num2 << endl;
        }

        void min();
        friend void max(SimplePoint obj);
};

void SimplePoint::min(){
    if (num1 <= num2){
        cout << num1 << endl;
    }
    else{
        cout << num2 << endl;
    }
}

void max(SimplePoint obj){
    if (obj.num1 >= obj.num2){
        cout << obj.num1 << endl;
    }
    else{
        cout << obj.num2 << endl;
    }
}
int main(){
    SimplePoint obj1;
    obj1.print();
    obj1.min();
    max(obj1);
    SimplePoint obj2(10,50);
    obj2.print();
    obj2.min();
    max(obj2);
    return 0;
}