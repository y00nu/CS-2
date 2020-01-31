#include <iostream>
#include <cstdlib>
using namespace std;

int min(int arr[], int size);
int max(int arr[], int size);
double average(int arr[], int size);

int sum(int arr[], int size){
	int sum = 0;
	for (int i = 0; i < size; i++){
		sum += arr[i];
	}
	return sum;
}
void fill(int arr[], int size){
	
	for (int i=0; i<size; i++){
		arr[i] = 1 + rand() % (100); 
	} 
}


void print(int arr[], int size){
	for (int k=0; k<size; k++){
		cout << arr[k] << "\t";
		if (k % 5 == 4) cout << "\n";
	}
}


int main(){

	srand(time(0));

	int table[20];
	//cout<<sizeof(int)<<endl;
	fill(table, 20);
	print(table, 20);

	cout << endl;

	cout << "Sum     : " << sum(table, 20) << endl;
	cout << "Average : " << average(table, 20) << endl;
	cout << "Max     : " << max(table, 20) << endl;
	cout << "Min     : " << min(table, 20) << endl;

	return 0;
}

int min(int arr[], int size){
	int min = arr[0];
	for(int i = 1; i < size; i++){
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}
int max(int arr[], int size){
	int max = arr[0];
	for(int i = 1; i < size; i++){
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
double average(int arr[], int size){
	return sum(arr, size) / double(size);
}