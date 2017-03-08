//#https://www.hackerrank.com/challenges/30-regex-patterns
/*
# Day 28: RegEx, Patterns, and Intro to Databases
# 
# Objective 
# 
# Today, we're working with regular expressions. Check out the Tutorial tab for learning materials
# and an instructional video!
# 
# Task 
# 
# Consider a database table, Emails, which has the attributes First Name and Email ID. Given N
# rows of data simulating the Emails table, print an alphabetically-ordered list of people whose
# email address ends in @gmail.com.
# 
# Input Format
# 
# The first line contains an integer, N, total number of rows in the table. 
# Each of the N subsequent lines contains 2 space-separated strings denoting a person's first name and email ID, respectively.
# 
# Constraints
# 
#     * 2 <= N <= 30
#     * Each of the first names consists of lower case letters [a-z] only.
#     * Each of the email IDs consists of lower case letters [a-z], @ and . only.
#     * The length of the first name is no longer than 20.
#     * The length of the email ID is no longer than 50.
# 
# Output Format
# 
# Print an alphabetically-ordered list of first names for every user with a gmail account. Each
# name must be printed on a new line.
# 
# Sample Input
# 
#     6
#     riya riya@gmail.com
#     julia julia@julia.me
#     julia sjulia@gmail.com
#     julia julia@gmail.com
#     samantha samantha@gmail.com
#     tanya tanya@gmail.com
# 
# Sample Output
# 
#     julia
#     julia
#     riya
#     samantha
#     tanya
# 
*/


package main
import (
	"fmt"
	//"regexp"
	"strings"
	"sort"
)


	type Person struct {
		name, email	string
	}

	type GmailUsers []Person


// Interfaces (for GmailUsers)
func (slice GmailUsers) Len() int {
	return len(slice)
}
//
func (slice GmailUsers) Less(i,j int) bool {
	return slice[i].name < slice[j].name
}
//
func (slice GmailUsers) Swap(i,j int) {
	slice[i],slice[j] = slice[j],slice[i]
}

func main() {
 //Enter your code here. Read input from STDIN. Print output to STDOUT

	var n int
	fmt.Scanf("%v\n", &n)

	//
	var gmailusers GmailUsers

	//type Person struct {
	//	name, email	string
	//}

	var persons,gmpersons []Person
	for ix:=0;ix<n;ix++ {

		// read stdin into Person struct
		var s Person
		fmt.Scanf("%v %v\n", &s.name, &s.email)

		persons = append(persons, s)

		/*-- regexp solution
		re := regexp.MustCompile("@gmail.com")
		////fmt.Printf("%q\n", re.FindString(s.email))		// either "" or "@gmail.com"
		if re.FindString(s.email)!="" {
			gmpersons = append(gmpersons, s)
		}
		--*/
		/*-- substring solution --*/
		if strings.Contains(s.email, "@gmail.com") {
			gmpersons = append(gmpersons, s)
			gmailusers = append(gmailusers, s)
		}
		
	}

	///fmt.Println("persons  :",persons)
	///fmt.Println("gmpersons:",gmpersons)

	//
	sort.Sort(gmailusers)
	//
	///fmt.Println("gmailusers:",gmailusers)

	for _,v := range(gmailusers) {
		fmt.Println(v.name)
	}

}

