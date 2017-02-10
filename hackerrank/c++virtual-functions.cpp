//https://www.hackerrank.com/challenges/virtual-functions
/*
# 
# All Domains >> C++ >> Introduction >> Virtual Functions
# Virtual Functions
# 
# This problem is to get you familiar with virtual functions. Create three classes Person,
# Professor and Student. The class Person should have data members name and age. The classes
# Professor and Student should inherit from the class Person.
# 
# The class Professor should have two integer members: publications and cur_id. There will be two
# member functions: getdata and putdata. The function getdata should get the input from the user:
# the name, age and publications of the professor. The function putdata should print the name,
# age, publications and the cur_id of the professor.
# 
# The class Student should have two data members: marks, which is an array of size 6 and cur_id. It
# has two member functions: getdata and putdata. The function getdata should get the input from
# the user: the name, age, and the marks of the student in 6 subjects. The function putdata should
# print the name, age, sum of the marks and the cur_id of the student.
# 
# For each object being created of the Professor or the Student class, sequential id's should be
# assigned to them starting from 1.
# 
# Solve this problem using virtual functions, constructors and static variables. You can create
# more data members if you want.
# 
# Input Format
# 
# There are two types of input. If the object being created is of the Professor class, you will
# have to input the name, age and publications of the professor.
# 
# If the object is of the Student class, you will have to input the name, age and the marks of the student in 6 subjects.
# 
# Constraints
# 
# 	* 1 <= len(name) <= 100, where len(name) is the length of the name. 
# 	* 1 <= age <= 80
# 	* 1 <= publications <= 1000
# 	* 0 <= marks <= 100, where marks is the marks of the student in each subject.
# 
# Output Format
# 
# There are two types of output depending on the object.
# 
# If the object is of type Professor, print the space separated name, age, publications and id on a new line.
# 
# If the object is of the Student class, print the space separated name, age, the sum of the
# marks in 6 subjects and id on a new line.
# 
# Sample Input
# 
# 	4
# 	1
# 	Walter 56 99
# 	2
# 	Jesse 18 50 48 97 76 34 98
# 	2
# 	Pinkman 22 10 12 0 18 45 50
# 	1
# 	White 58 87
# 
# Sample Output
# 
# 	Walter 56 99 1
# 	Jesse 18 403 1
# 	Pinkman 22 135 2
# 	White 58 87 2
# 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ---------------------------- locked code above ------------------------------


class Person {
protected:
    string name;
    int age;
public:
    virtual void getdata(void) = 0;    
    virtual void putdata(void) = 0;    
};

static int profId=0;
class Professor : public Person {
    int publications, cur_id;
public:
    virtual void getdata(void) {
        cin>>name>>age>>publications;
        cur_id = ++profId;
    }
    virtual void putdata(void) {
        cout << name <<" " << age <<" " << publications <<" " << cur_id << endl;
    }
    
};

static int studId=0;
class Student : public Person {
    int marks[6];
    int totalmarks;
    int cur_id;
public:
    virtual void getdata(void) {
        cin>>name>>age;
        cin >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
        totalmarks = marks[0] + marks[1] + marks[2] + marks[3] + marks[4] + marks[5];
        cur_id = ++studId;
    }
    virtual void putdata(void) {
        cout << name <<" " << age <<" " << totalmarks <<" " << cur_id << endl;        
    }
 
};


// ---------------------------- locked code below ------------------------------

int main(){

//###################################################################
cout << "to run: ./c++virtual-functions < c++virtual-functions.txt" << endl;
//###################################################################

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

