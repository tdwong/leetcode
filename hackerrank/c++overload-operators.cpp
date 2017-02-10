//https://www.hackerrank.com/challenges/overload-operators
/*
# 
# All Domains >> C++ >> Other Concepts >> Overload Operators 
# Overload Operators
# 
# You are given a class - Complex.
# 
# 	class Complex
# 	{
# 	public:
# 		int a,b;
# 	};
# 
# Operators are overloaded by means of operator functions, which are regular functions with special names. Their name begins with the operator keyword followed by the operator sign that is overloaded. The syntax is:
# 
# 	type operator sign (parameters) { //... body ...// }
# 
# You need to overload operators + and << for the Complex class.
# 
# The operator + should add complex numbers according to the rules of complex addition:
# 
# 	(a+ib)+(c+id) = (a+c) + i(b+d)  
# 
# Overload the stream insertion operator << to add "a+ib" to the stream:
# 
# 	cout<<c<<endl;
# 
# The above statement should print "a+ib" followed by a newline where a=c.a and b=c.b.
# 
# Input Format
# 
# The overloaded operator + should receive two complex numbers (a+ib and c+id) as parameters. It
# must return a single complex number.
# 
# The overloaded operator << should add "a+ib" to the stream where a is the real part and b is
# the imaginary part of the complex number which is then passed as a parameter to the overloaded
# operator.
# 
# Sample Input
# 
# 	3+i4
# 	5+i6
# 
# Sample Output
# 
# 	8+i10
# 
*/

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//
// ---------------------------- locked code above ------------------------------


//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

// Complex::Complex(int a, int b) { a=a; b=b; }

	//
	// non-member operatpr overloading...
	//

Complex operator + (const Complex &lhs, const Complex &rhs) {
	Complex c;
		//
		// must use existing input() method to construct Complex object
		//
	c.input( to_string(lhs.a+rhs.a)+"+i"+to_string(lhs.b+rhs.b) );
	return c;
}

	//
	// non-member operatpr overloading for <<
	//
std::ostream & operator<< (std::ostream & o, const Complex & c) {
	return o << c.a <<"+i"<< c.b;    
}


// ---------------------------- locked code below ------------------------------
//

int main()
{

//###################################################################
cout << "to run: ./c++overload-operators < c++overload-operators.txt" << endl;
//###################################################################

    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}

