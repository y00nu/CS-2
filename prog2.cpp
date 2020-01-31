#include <iostream>
#include <cstdlib>
using namespace std;

int table[5][4];

void fill(int nbOfRows, int nbOfColumns){
	/*for (int i=0; i<nbOfColumns; i++){
		for (int j=0; j<nbOfRows; j++){
			table[j][i]=10 +rand()%991;
		}
	}*/
	for (int k=0;k<nbOfRows*nbOfColumns;k++){
		table[k/nbOfColumns][k%nbOfColumns]=10 +rand()%991;
	}
}

void print1(int nbOfRows, int nbOfColumns){
	for (int i=0; i<nbOfColumns; i++){
		for (int j=0; j<nbOfRows; j++){
			cout<<table[j][i]<<"\t";
		}
		cout<<endl;
	}
}

void print2(int nbOfRows, int nbOfColumns){
	for (int i=0; i<nbOfRows; i++){
		for (int j=0; j<nbOfColumns; j++){
			cout<<table[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int min(int currentPosition, int nbOfColumns, int endPosition){
	int minimum = table[currentPosition / nbOfColumns][currentPosition % nbOfColumns];
	int minLocation = currentPosition;
	for (int i = currentPosition + 1; i < endPosition; i++)
	{
		if(minimum > table[i/nbOfColumns][i%nbOfColumns]){
			minimum = table[i/nbOfColumns][i%nbOfColumns];
			minLocation = i;
		}
	}	
	return minLocation;
}

void swap(int i, int minLocation, int nbOfColumns){
	int temp;
	temp = table[i/nbOfColumns][i%nbOfColumns];
	table[i/nbOfColumns][i%nbOfColumns] = table[minLocation/nbOfColumns][minLocation%nbOfColumns];
	table[minLocation/nbOfColumns][minLocation%nbOfColumns] = temp;
}

void sort(int nbOfRows, int nbOfColumns){
	int endPostion = nbOfRows * nbOfColumns;
	int row, col;
	for (int i = 0; i < endPostion; i++)
	{
		swap(i, min(i, nbOfColumns, endPostion), nbOfColumns);
	}
}

int total(int nbOfRows, int nbOfColumns){
	int sum = 0;
	for (int i = 0; i < nbOfRows; i++)
	{
		for(int j=0; j<nbOfColumns; j++){
			sum += table[i][j];
		}
	}
	return sum;
}

int odd(int nbOfRows, int nbOfColumns){
	int sum = 0;
	for (int i = 0; i < nbOfRows; i++)
	{
		for(int j=0; j<nbOfColumns; j++){
			if(table[i][j] % 2 != 0)
				sum += table[i][j];
		}
	}
	return sum;
}

int even(int nbOfRows, int nbOfColumns){
	int sum = 0;
	for (int i = 0; i < nbOfRows; i++)
	{
		for(int j=0; j<nbOfColumns; j++){
			if(table[i][j] % 2 == 0)
				sum += table[i][j];
		}
	}
	return sum;
}

int main(){
	fill(5,4);
	print1(5,4);
	cout<<"*****************************************\n";
	print2(5,4);
    cout<<"*****************************************\n";
	sort(5,4);
	print2(5,4);
    cout<<"*****************************************\n";
	cout << "Total : " << total(5,4) << endl;
	cout << "Sum of even numbers : " << even(5,4) << endl;
	cout << "Sum of odd numbers : " << odd(5,4) << endl;
	cout << "even numbers + odd numbers : " << even(5,4) + odd(5,4) << endl;
    
	return 0;
}