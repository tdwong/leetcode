/*
//https://leetcode.com/contest/leetcode-weekly-contest-11/problems/number-of-segments-in-a-string/
#
# 434. Number of Segments in a String
#
#	Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
#	
#	Please note that the string does not contain any non-printable characters.
#	
#	Example:
#	
#		Input: "Hello, my name is John"
#	
#		Output: 5
#
*/

/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
	// strip & compress white spaces
		// note that //g
	s1 = s.replace(/^\s+|\s+$/g,'').replace(/\s+/g,' ');
	return (s1.length==0) ? 0 : s1.split(' ').length
};

function checkSolution(s, expected)
{
	var ret = countSegments(s);
	var retstr = (ret == expected) ? "ok" : "<-- wrong";
	console.log( "s=\'" + s + "\', ret: " + ret + ", expected: " + expected + "  " + retstr );
//	console.log( "s=\'" + s + "\', ret: " + ret + ", expected: " + expected + "\t" );
//	console.log( (ret == expected) ? "ok" : "<-- wrong" );
}

checkSolution("Hello, my name is John", 5);
checkSolution("   leading spaces line", 3);
checkSolution("trailing spaces line  ", 3);
checkSolution("  spaces on both ends ", 4);
checkSolution("extra  spaces in between  words  ", 5);
checkSolution("  combination  in word   spacing ", 4);
checkSolution("", 0);
checkSolution("                       ", 0);

