// Mar 5
// Recursion
/*
    Template
    recursiveFunction(parameter){
        if(stopping case){
            do the job
        }
        else { 
            recursiveFunction(a parameter moving in direction of stopping case)
        }
    }
*/
#include <iostream>
using namespace std;

void print(int n){
    cout << n << endl;
    if(n<228){
        print(n*2);
    }
    cout << n << endl; 
}

int factorial(int n){
    if(n==1)
        return 1;
    return n * factorial(n-1);
}

int bunnyEars(int bunnies) {
  if(bunnies == 0)
    return 0;
  return 2+bunnyEars(bunnies-1);
}

int fibonacci(int n) {
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}

int bunnyEars2(int bunnies) {
  if(bunnies == 0)
    return 0;
  if(bunnies % 2 == 0)
    return 3 + bunnyEars2(bunnies - 1);
  return 2 + bunnyEars2(bunnies - 1);
}

int triangle(int n){
    if(n == 0){
        return 0;
    }
    else{
         return n + triangle(n-1);
    }
}

int sumDigits(int n) {
  if(n / 10 == 0)
    return n;
  return (n % 10) + sumDigits(n / 10);
}

int count7(int n) {
  if(n / 10 == 0){
    if(n % 7 == 0)
      return 1;
    else
      return 0;
  }
  if((n % 10) % 7 == 0 && n % 10 != 0)
    return 1 + count7(n/10);
  else
    return count7(n/10);
}

int array11(int num[], int index, int size) {

    if(index == size)
        return 0;
    if(num[index] ==  11)
        return 1 + array11(num, ++index, size);
    return array11(num, ++index, size);
}

int powerN(int base, int n) {
  if(n == 1)
    return base;
  return base * powerN(base, n-1);
}

// Recursion 2
bool groupSumClump(int start, int nums[], int target, int size) {
    if(start != size){
        int x = nums[start]!=nums[size/2] ? nums[start] : 0;
        return groupSumClump(start+1, nums, target-x, size);
    }
    else
    {
        return target == 0 || (target-nums[size/2] == 0);
    }
}


bool groupSum6(int index, int arr[], int target, int size) {
    if(index == size){
        if(target == 0)
            return true;
        else
            return false;
    }
    else{
        if(arr[index] == 6)
            return groupSum6(index + 1, arr, target - 6, size);
        else
            return groupSum6(index + 1, arr, target, size) || groupSum6(index + 1, arr, target - arr[index], size);
    }
}


void groupSum6Loop(int index, int arr[], int target, int size){
    // 바이너리 숫자 얻는법 %2, /2로
    
}

int main(){
    int arr[9] = {5, 7, 6, 1, 2, 4, 6, 6, 6};

    groupSum6Loop(0, arr, 9, 9);



    return 0;
}