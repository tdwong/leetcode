#!/bin/bash
#
#https://leetcode.com/problems/word-frequency/
#	
#	Write a bash script to calculate the frequency of each word in a text file words.txt.
#	
#	For simplicity sake, you may assume:
#	
#	- words.txt contains only lowercase characters and space ' ' characters.
#	- Each word must consist of lowercase characters only.
#	- Words are separated by one or more whitespace characters.
#
#	For example, assume that words.txt has the following content:
#	
#	the day is sunny the the
#	the sunny is is
#
#	Your script should output the following, sorted by descending frequency:
#
#	the 4
#	is 3
#	sunny 2
#	day 1
#	

if [ ! -f words.txt ]; then
cat > words.txt <<_end_
the day is sunny the the
the sunny is is
_end_
fi

	# <wong>
	#	1. cat file into built-in for to dissect input into words
	#	2. sort (for awk)
	#	3. awk  (for frequency counting)
	#		a. z!=$1 - new word detected
	#		b. END - print last word frequency
	#	4. sort (to order by decending frequency)
	#

for x in $(cat words.txt); do echo $x; done | sort | awk '{ if (z!=$1) { if (count) { print z,count; }; z=$1; count=1 } else { count++; } } END { print z,count; } ' | sort -rnk2

	# fancy solution to use bash associative array, but it is VERY slow

	# each element is {key, count} pair
declare -A wordsFreq
## for x in $(cat words.txt); do echo $x, ${wordsFreq[$x]}; let wordsFreq[$x]=wordsFreq[$x]+1; done
## for i in "${!wordsFreq[@]}"; do echo "wordsFreq[$i]: ${wordsFreq[$i]}"; done
for x in $(cat words.txt); do let wordsFreq[$x]=wordsFreq[$x]+1; done
for i in "${!wordsFreq[@]}"; do echo "$i ${wordsFreq[$i]}"; done | sort -rnk2

	# use associative arry in awk.  the fastest solution so far

	# ++z[$i]         - automatically create the z[] using $i as key and increment its value
	# for (var in z)  - traverse every key in z[]
## cat words.txt | awk -e '{ for (i=1;i<=NF;i++) { print $i; ++z[$i] }} END { print "end"; for (var in z) { print var,z[var] }}'
cat words.txt | awk -e '{ for (i=1;i<=NF;i++) { ++z[$i] }} END { for (var in z) { print var,z[var] }}' | sort -rnk2

#
## experiment with sorting awk associative arry
#

echo "----experiment-"
cat words.txt | awk -e '{ for (i=1;i<=NF;i++) { ++z[$i] }} END { for (var in z) { print var,z[var] }}'
### cat words.txt | awk -e '{ for (i=1;i<=NF;i++) { ++z[$i] }} END { n=asorti(z,nz); for (i=1;i<=n;i++) { print nz[i],z[nz[i]] }}'
echo "----experiment-asort-"
cat words.txt | awk -e '{ for (i=1;i<=NF;i++) { ++z[$i] }} END { n=asort(z,nz); for(i=1;i<=n;i++) print nz[i]; for (var in nz) print var,nz[var] }'
echo "----experiment-asorti-"
cat words.txt | awk -e '{ for (i=1;i<=NF;i++) { ++z[$i] }} END { n=asorti(z,nz); for(i=1;i<=n;i++) print nz[i]; for (var in nz) print var,nz[var] }'
echo "----experiment-gawk-PROCINFO-"
	# https://www.gnu.org/software/gawk/manual/html_node/Controlling-Scanning.html
cat words.txt | awk -e '{ for (i=1;i<=NF;i++) { ++z[$i] }} END { PROCINFO["sorted_in"] = "@val_num_desc"; for (var in z) print var,z[var] }'


rm -f words.txt
