//https://www.hackerrank.com/challenges/operator-overloading
/*
# 
# All Domains >> C++ >> Other Concepts >> Operator Overloading
# Operator Overloading
# 
# Classes define new types in C++. Types in C++ not only interact by means of constructions and
# assignments but also via operators. For example:
# 
# 	int a=2, b=1, c;
# 	c = b + a;
# 
# The result of variable c will be 3. 
# 
# Similarly, classes can also perform operations using operator overloading. Operators are overloaded
# by means of operator functions, which are regular functions with special names. Their name
# begins with the operator keyword followed by the operator sign that is overloaded. The syntax is:
# 
# 	type operator sign (parameters) { //... body ...// }
# 
# You are given a main() function which takes a set of inputs to create two matrices and prints
# the result of their addition. You need to write the class Matrix which has a member a of type
# vector<vector<int> >. You also need to write a member function to overload the operator +. The
# function's job will be to add two objects of Matrix type and return the resultant Matrix.
# 
# Input Format
# 
# First line will contain the number of test cases T. For each test case, there are three lines of input.
# 
# The first line of each test case will contain two integers N and M which are the sizes of the
# rows and columns respectively of the two matrices that will follow on the next two lines. These
# next two lines will each contain N * M elements of both the matrices in a row-wise format.
# 
# Constraints 
#  
# 	* 1 <= T <= 1000
# 	* 1 <= N <= 100
# 	* 1 <= M <= 100
# 	* 1 <= A[ij] <= 10, where A[ij] is the element in the i-th row and j-th column of the matrix.
# 
# Output Format
# 
# The code provided in the editor will use your class Matrix and overloaded operator function to
# add the two matrices and give the output.
# 
# Sample Input
# 
# 	1
# 	2 2
# 	2 2 2 2
# 	1 2 3 4
# 
# Sample Output
# 
# 	3 4 
# 	5 6
# 
*/

//Operator Overloading

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//
// ---------------------------- locked code above ------------------------------


//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

class Matrix {
	public:
		vector< vector<int> > a;
		Matrix & operator = (const Matrix &rhs) ;
		Matrix operator + (const Matrix &rhs) const;
};

Matrix Matrix::operator + (const Matrix &rhs) const {
	Matrix m;
	m.a = a;
	//cout << "a.size=" << a.size() << endl;
	for (int i=0; i<a.size(); i++) {
		//cout << "(*(a.begin())).size=" << (*(a.begin())).size() << endl;
		for (int j=0; j<(*(a.begin())).size(); j++) {
			//cout << "m.a=" << m.a[i][j] << ",rhs.a=" << rhs.a[i][j] << endl;
			m.a[i][j] += rhs.a[i][j];
		}
	}
	return m;
}

Matrix & Matrix::operator = (const Matrix &rhs) {
	if (this != &rhs) {
		this->a = rhs.a;		// no deep copy needed 'cause std::vector<std::vector<int> >
	}
	return *this;
}

	//
	// non-member operatpr overloading for <<
	//
std::ostream & operator<< (std::ostream & o, const Matrix & m) {
	return o << m.a.size();    
}


// ---------------------------- locked code below ------------------------------
//

int main () {

//###################################################################
cout << "to run: ./c++operator-overloading < c++operator-overloading.txt" << endl;
//###################################################################

   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }

		// my addition to test operator =
		cout << "=========---------------" << endl;
		Matrix nm = result;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				cout << nm.a[i][j] << " ";
			}
			cout << endl;
		}

   } 

   return 0;
}

