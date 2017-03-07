//https://www.hackerrank.com/challenges/30-dictionaries-and-maps
/*
# Day 8: Dictionaries and Maps
# 
# Objective 
# 
# Today, we're learning about Key-Value pair mappings using a Map or Dictionary data structure. Check
# out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# Given n names and phone numbers, assemble a phone book that maps friends' names to their
# respective phone numbers. You will then be given an unknown number of names to query your phone
# book for. For each name queried, print the associated entry from your phone book on a new line
# in the form "name=phoneNumber"; if an entry for name is not found, print "Not found" instead.
# 
# Note: Your phone book should be a Dictionary/Map/HashMap data structure.
# 
# Input Format
# 
# The first line contains an integer, n, denoting the number of entries in the phone book. 
# Each of the n subsequent lines describes an entry in the form of 2 space-separated values on a
# single line. The first value is a friend's name, and the second value is an 8-digit phone number.
# 
# After the n lines of phone book entries, there are an unknown number of lines of queries. Each
# line (query) contains a name to look up, and you must continue reading lines until there is no
# more input.
# 
# Note: Names consist of lowercase English alphabetic letters and are first names only.
# 
# Constraints
# 
# 	* 1 <= n <= 10**5
# 	* 1 <= queries <= 10**5
# 
# Output Format
# 
# On a new line for each query, print "Not found" if the name has no corresponding entry in the
# phone book; otherwise, print the full name and phone Number in the format "name=phoneNumber".
# 
# Sample Input
# 
# 	3
# 	sam 99912222
# 	tom 11122222
# 	harry 12299933
# 	sam
# 	edward
# 	harry
# 
# Sample Output
# 
# 	sam=99912222
# 	Not found
# 	harry=12299933
# 
# Explanation
# 
# We add the following n = 3 (Key,Value) pairs to our map so it looks like this:
# 
# 	phoneBooks = { (sam,99912222), (tom,11122222), (harry,12299933) }
# 
# We then process each query and print "key=value" if the queried key is found in the map; otherwise, we print "Not found".
# 
# Query 0: sam 
# 	Sam is one of the keys in our dictionary, so we print "sam=99912222".
# 
# Query 1: edward 
# 	Edward is not one of the keys in our dictionary, so we print "Not found".
# 
# Query 2: harry 
# 	Harry is one of the keys in our dictionary, so we print "harry=12299933".
# 
*/


package main
import ( 
	"fmt"
	"runtime"
)

func main() {

// ---------------------------- locked code above ------------------------------

 //Enter your code here. Read input from STDIN. Print output to STDOUT
    
    var n int
    fmt.Scanf("%v\n", &n)		// use fmt.Scanf() to read single value

    ///fmt.Println(n)
    
		//// map types are reference types, like pointers or slices, and so the value of map variable is nil
    var phonebook map[string]string
		//// the make function allocates and initializes a hash map data structure and returns a map value that points to it
    phonebook = make(map[string]string)

    var name,number string
    // build phone book
    for i:=0;i<n;i++ {
        fmt.Scanf("%v %v",&name,&number)
        phonebook[name] = number
    }

    ///fmt.Println(phonebook)
    
    // query phone book
	for {
		_,err := fmt.Scanf("%v",&name)
		if err != nil {
			break
		}
		if phonebook[name]=="" {
			fmt.Println("Not found")
		} else {
			fmt.Printf("%v=%v\n",name,phonebook[name])
		}
	}

	chop()

// ---------------------------- locked code below ------------------------------

}


// ---------------------------- personal addition code below ------------------------------
func chop() {
		// only for Windows environment
		// eat up the final new line (\n\r)
		if runtime.GOOS == "windows" {
			var z string
			fmt.Scanln(&z)
		}
}

