//https://www.hackerrank.com/challenges/cpp-class-template-specialization
/*
# 
# You are given a main function which reads the enumeration values for two different types as
# input, then prints out the corresponding enumeration names. Write a class template that can
# provide the names of the enumeration values for both types. If the enumeration value is not
# valid, then print "unknown".
# 
# Input Format
# 
# The first line contains T, the number of test cases. 
# Each of the T subsequent lines contains 2 space-separated integers. The first integer is a color value, C, and the second integer is a fruit value, F.
# 
# Constraints
# 
# 	* 1 <= T <= 100
# 	* -2 * 10**9 <= C <= 2 * 10**9
# 	* -2 * 10**9 <= F <= 2 * 10**9
# 
# Output Format
# 
# The locked stub code in your editor prints T lines containing the color name and the fruit name
# corresponding to the input enumeration index.
# 
# Sample Input
# 
# 	2
# 	1 0
# 	3 3
# 
# Sample Output
# 
# 	green apple
# 	unknown unknown
# 
# Explanation
# 
# Since T = 2, there are two lines of output.
# 
# The two input index values, 1 and 0, correspond to green in the color enumeration and apple in
# the fruit enumeration. Thus, we print green apple.
# The two input values, 3 and 3, are outside of the range of our enums. Thus, we print unknown unknown.
# 
*/


#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;


//
// ---------------------------- locked code above ------------------------------


// Define specializations for the Traits class template here.

template <> struct Traits<Fruit> {
	static string name(int f) {
		switch(f) {
			case static_cast<std::underlying_type<Fruit>::type>( Fruit::apple ): return "apple";
			case static_cast<std::underlying_type<Fruit>::type>( Fruit::orange ): return "orange";
			case static_cast<std::underlying_type<Fruit>::type>( Fruit::pear ): return "pear";
			default: return "unknown";
		}
	}
};
template <> struct Traits<Color> {
	static string name(int c) {
		switch(c) {
			case static_cast<std::underlying_type<Color>::type>( Color::red ): return "red";
			case static_cast<std::underlying_type<Color>::type>( Color::green ): return "green";
			case static_cast<std::underlying_type<Color>::type>( Color::orange ): return "orange";
			default: return "unknown";
		}
	}
};


// ---------------------------- locked code below ------------------------------
//


int main ()
{

//###################################################################
cout << "to run: ./c++class-template-specialization < c++class-template-specialization.txt" << endl;
//###################################################################

int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}

