#!/bin/bash
#
#https://leetcode.com/problems/transpose-file/
#	
#	Given a text file file.txt, transpose its content.
#	
#	You may assume that each row has the same number of columns and each field is separated by the ' ' character.
#	
#	For example, if file.txt has the following content:
#	
#		name age
#		alice 21
#		ryan 30
#	
#	Output the following:
#	
#		name alice ryan
#		age 21 30
#	

cat > file.txt <<_end_
name age
alice 21
ryan 30
_end_

#cat file.txt | awk -e '{ for (i=1;i<=NF;i++) { z[NR][i]=$i ; print NR,i,z[NR][i]; if (NF>maxNF) { maxNF=NF;} } } END { for(i=1;i<=NR;i++) { for(j=1;j<=maxNF;j++) { print z[i][j]; line=(line " " z[i][j])}; print line; line="" }  }'

cat file.txt | awk -e '{ for (i=1;i<=NF;i++) { z[NR][i]=$i; if (NF>maxNF){maxNF=NF;} } } END { for (i=1;i<=maxNF;i++) { for (j=1;j<=NR;j++) { if(j==1) { line=z[j][i]; } else { line=(line " " z[j][i]); }}; print line; line="" } }'

rm -f file.txt
