#include <iostream>
#include <cmath>
using namespace std;

class Point{
    private:
        float coord1;
        float coord2;
        static int nbOfPoints;
    public:
        Point(float x = 0, float y = 0){
            coord1 = x;
            coord2 = y;
            nbOfPoints++;
        }
        float getCoord1(){
            return coord1;
        }
        float getCoord2(){
            return coord2;
        }
        void setCoord1(float x){
            coord1 = x;
        }
        void setCoord2(float y){
            coord2 = y;
        }
        void print(){
            cout << '(' << coord1 << ", " << coord2 << ") " << "number of points : " << nbOfPoints << endl;
        }
        float distanceTo(Point p){
            return sqrt(pow(p.coord1-coord1,2)+pow(p.coord2 - coord2, 2));
        }
        float slope(Point p);
        static int getNbOfPoints(){
            return nbOfPoints;
        }
};

int Point::nbOfPoints = 0;

class Student{
    private:
        string name;
        string id;
        static string univAddress;
    public:
       // static methods should always access only static values.
        // it can be called before any creation of instances.
        static string getUnivAddress(){
            return univAddress;
        }
};

// How to set value of an static variable
string Student::univAddress = "2800 W Gore Blvd";

// To import a function outside of a class.
// Any function implemented inside of a class is inline function.
// Inline Function - paste code itself when it's called. File gets bigger but faster.
float Point::slope(Point p){
    return (p.coord2 - coord2)/(p.coord1 - coord1);
}

int main(){
    Point p1;
    p1.print();

    Point p2(10);
    p2.print();

    Point p3(20,20);
    p3.print();


    return 0;
}