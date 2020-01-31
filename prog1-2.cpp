#include <iostream>
#include <cstdlib>
using namespace std;

//min
int min(int arr[], int size);
//max
int max(int arr[], int size){
  	int temp=arr[0];
  	int i=1;
	  for (;i<20;i++){
	  //while (i<20){
	  	if (arr[i]>temp){
	  		temp=arr[i];
		  }
	  	//i++;
	  }
	  return temp;	
}
//average
void average(int arr[], int size);
//sum
void sum(int arr[], int size){
	int sum=0;
	for (int k=0;k<size;++k){
		sum+=arr[k];
	}
	cout<<"The sum is: "<<sum<<endl;
	/*int a=1;
	int b=++a;
	cout<<"a="<<a<<"\tb="<<b<<endl;
	a=1;
	b=a++;
	cout<<"a="<<a<<"\tb="<<b<<endl;*/
	
}
void fill(int arr[], int size){
	for (int i=0; i<size; i++){
		arr[i]=1+rand()%(100);
	}
}
void print(int arr[], int size){
	for (int k=0; k<size; k++){
		cout<<arr[k]<<"\t";
		if (k%5==4) cout<<"\n";
	}
}
int main(){
	int table[20];
	//cout<<sizeof(int)<<endl;
	fill(table, 20);
	print(table, 20);
	cout<<min(table,20)<<endl;
	cout<<max(table,20)<<endl;
	sum(table,20);
	average(table,20);
	return 0;
}
inline int min(int arr[], int size){
  	int temp=arr[0];
  	int i=1;
	  for (;i<20;i++){
	  //while (i<20){
	  	if (arr[i]<temp){
	  		temp=arr[i];
		  }
	  	//i++;
	  }
	  return temp;	
}
void average(int arr[], int size){
	int sum=0;
	for (int k=0;k<size;++k){
		sum+=arr[k];
	}
	
	cout<<"The average is: "<<(double) sum/size<<endl;	
}













