// Mar 12
// Tower of Hanoi
#include <iostream>
using namespace std;

void hanoi(int n, char start, char dest, char bridge){
    if(n == 0){
    
    }
    else{
        hanoi(n-1, start, bridge, dest);
         cout << "Move disk" << n << " from " << start << " to " << bridge << endl;
        hanoi(n-1, bridge, dest, start);
    }
}

int main(){
    hanoi(3, 'A', 'B', 'C');
    return 0;
}