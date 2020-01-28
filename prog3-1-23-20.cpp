#include <iostream>
#include <cstdlib>

using namespace std;

class Phone
{
private:
    int areaCode;
    string phoneNumber;

public:
    Phone(){}
    Phone(int a = 580, string b = "123-4567"){
        areaCode = a;
        phoneNumber = b;
    }
    int getAreaCode(){
        return areaCode;
    }
    string getPhoneNumber(){
        return phoneNumber;
    }
    void print(){
        cout << "(" << areaCode << ")" << phoneNumber << endl;
    }
};


class Student
{
private:
    string name;
    int id;
    string major;
    string email;
    Phone gPhone;

public:
    Student(){}
    Student(Phone p, string n = "Kim", int i = 123456, string e = "cam@cameron.edu", string m = "CS"){
        name = n;
        id = i;
        email = e;
        major = m;
        gPhone = p;
    }

    void print(){
        cout<<"Name        : "<<name<<"\n";
        cout<<"ID          : "<<id<<"\n";
        cout<<"Email       : "<<email<<"\n";
        cout<<"Major       : "<<major<<"\n";
        cout<<"PhoneNumber : ";
        gPhone.print();
    }
};

int main()
{
    // Phone gPhone(580,"123-4567");
    // Student s("George", 345678, "george@cameron.edu", "CS", gPhone);
    
    Phone dPhone;
    Student d(dPhone);

    d.print();

    return 0;
}
