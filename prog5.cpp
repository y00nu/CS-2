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