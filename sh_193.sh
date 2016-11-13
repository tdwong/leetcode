#!/bin/bash
#
#https://leetcode.com/problems/valid-phone-numbers/
#	
#	Given a text file file.txt that contains list of phone numbers (one per
#	line), write a one liner bash script to print all valid phone numbers.
#	
#	You may assume that a valid phone number must appear in one of the
#	following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)
#	
#	You may also assume each line in the text file must not contain leading or trailing white spaces.
#	
#	For example, assume that file.txt has the following content:
#	
#		987-123-4567
#		123 456 7890
#		(123) 456-7890
#	
#	Your script should output the following valid phone numbers:
#	
#		987-123-4567
#		(123) 456-7890
#	

cat > file.txt <<_end_
123-456-7890
(123) 456-7890
(1a3) 456-7890
(123) 4-6-7890
(001) 345-00001
_end_

	# not fast enough
cat file.txt | egrep "^([[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}|\([[:digit:]]{3}\) [[:digit:]]{3}-[[:digit:]]{4})$"

	# slower
cat file.txt | egrep "^([[:digit:]]{3}-|\([[:digit:]]{3}\) )[[:digit:]]{3}-[[:digit:]]{4}$"

	# even slower
cat file.txt | egrep "^(...-|\(...\) )...-....$" | egrep "^([[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}|\([[:digit:]]{3}\) [[:digit:]]{3}-[[:digit:]]{4})$"

			# WRONG, as [:punct:] includes '-'
		cat file.txt | egrep "^(...-|\(...\) )...-....$" | egrep -v "[[:alpha:]|[:punct:]]"

	# sed is faster than egrep
#
## fastest solution so far
#
cat file.txt | sed -ne "/^[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$/p" -e "/^([0-9][0-9][0-9]) [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$/p"

	# condensed code size, but slower
cat file.txt | sed -ne "/^[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}$/p" -e "/^([0-9]\{3\}) [0-9]\{3\}-[0-9]\{4\}$/p"

rm -f file.txt
