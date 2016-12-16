"""
https://leetcode.com/contest/leetcode-weekly-contest-11/problems/unique-substrings-in-wraparound-string/
#
# 467. Unique Substrings in Wraparound String
#
# Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz",
# so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
# 
# Now we have another string p. Your job is to find out how many unique non-empty substrings of
# p are present in s. In particular, your input is the string p and you need to output the number
# of different non-empty substrings of p in the string s.
# 
# Note: p consists of only lowercase English letters.
# 
# Example 1:
# 
# 	Input: "a"
# 	Output: 1
# 
# Explanation: Only the substring "a" of string "a" is in the string strings.
# 
# Example 2:
# 
# 	Input: "cac"
# 	Output: 2
# 
# Explanation: There are two substrings "a", "c" of string "cac" in the string s.
# 
# Example 3:
# 
# 	Input: "zab"
# 	Output: 6
# 
# Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
# 
"""

class Solution(object):
	def findSubstringInWraproundString(self,  p):
		"""
		:type p: str
		:rtype: int
		"""
		self.gCount = {}
#		print "p=", p, "len(p)=", len(p)
		return self.allCombi(p)

	def addToUniqueStrs(self, uStrs, str):
		"""
		input:  uStrs[]: array of unique strings
		        str:     string to be added to uStrs[] if not in already	
		output: boolean: True if uStrs[] is updated
		                 latest uStrs[]
		"""
		# search unique string list
#		print ">>> ", str
		popList = []
		for idx, ss in enumerate(uStrs):
			if ss.find(str) != -1:
				# given str is a sub-string, give up
				return False, uStrs
			else:
				if str.find(ss) != -1:
					# given str is a super-string, drop the one in the list
					popList.append(idx)
		# pop all substrings	
		popList.reverse()
		for idx in popList:
			spop = uStrs.pop(idx)
#			print spop, "is removed from uStrs[]"
		# append if not already in the list
#		print str, "is appended to uStrs[]"
		uStrs.append(str);
		return True, uStrs

	def uniqueStrs(self, p):
		""" find all unique string(s)
		"""
		uStrs=[]
		cmpStr = alphabets * (2+(len(p)/len(alphabets)))
#		print "len(p)=", len(p), "p=", p, "cmpStr=", cmpStr
		puStr=None
		for s in xrange(len(p)):			# start from index 0

			# additional check
			if puStr!=None and puStr.find(p[s:len(p)]) != -1: break

			#""
			for e in xrange(len(p),s,-1):	# start with len(p)
#				print "[",s,":",e,"]", p[s:e], cmpStr.find(p[s:e]), "puStr=", puStr
				if cmpStr.find(p[s:e]) != -1:
					# found a match
					if puStr != None and puStr.find(p[s:e]) != -1:
						# don't bother... this is a substr of previous unique str
						# break (as future iteration will be just shorter and substr of previous unique str
						break
					# save to unique string
#					print "found ", p[s:e]
					added, uStrs = self.addToUniqueStrs(uStrs, p[s:e])
					if added == True:
						# successfully added to uStrs[]
						puStr = p[s:e]
					# break out inner for
					break
			#""

		return uStrs

	def uniqueStrs_v2(self, p):
		""" find all unique string(s)
		"""
		uStrs=[]
		#
		""" here is the thinking:
				s = [0..(len(p)-1)]
				using two pointers, x = s, to walk the str continue until p[x]+1 != p[x+1]
				- handle boundary condition when p[x] == 'z'
				- p[s:x] is a candidate string -> check for substr condition
				- s = x+1 and repeat
			* note the corner case (e.g. end-of-string)
		"""
		# corner case
		if len(p) == 1:
			uStrs.append(p)

		# general case
		else:
			s = 0
			while s < len(p):
				# sanity check
				if p[s] not in alphabets: return []
				x = s
				#
				while True:
					if x == len(p)-1:
						# check whatever left-over p[s:x]
						self.addToUniqueStrs(uStrs, p[s:x])
						break
					if ord(p[x]) == ord('z') and ord(p[x+1]) == ord('a'):
						x += 1
					elif ord(p[x])+1 == ord(p[x+1]):
						x += 1
					else:
						self.addToUniqueStrs(uStrs, p[s:x])
						break

				# check p[s:x]
				self.addToUniqueStrs(uStrs, p[s:x+1])
				s = x + 1

		#
		return uStrs

	#!! ------------------------------------------------------
	def longestStr(self, p):
		#"" https://en.wikipedia.org/wiki/Longest_common_substring_problem
		""" TODO: fine longest matching string
			e.g.  ac -> a
				  zabc -> zab
		"""
		sofar=[]
		if len(p) < len(alphabets):
			cmpStr = alphabets * 2
#			print "p=", p, "cmpStr=", cmpStr
			for s in xrange(len(p)):			# start from index 0
				for e in xrange(len(p),s,-1):	# start with len(p)
#					print "[",s,":",e,"]", p[s:e], cmpStr.find(p[s:e]),
						# quick check to save a string comparison
					if sofar!=[] and (e-s)<(sofar[1]-sofar[0]): continue
					if cmpStr.find(p[s:e]) != -1:
						# found a match
						if sofar==[]: sofar = [ s, e ]
						else:
							if (e-s) > (sofar[1]-sofar[0]): sofar = [ s, e ]
#					print "sofar=", sofar
						# break out inner for
						break
			if sofar!=[]: return p[sofar[0]:sofar[1]]
			else: return ""
		else:
			return p

	def strCombiCount(self, p):
		"""
		"""
		loopN = totalC = count = 0
		#
		# all possible substr length [1..len(p)]
		#
		for sublen in xrange(1, len(p)+1):
			###print "sublen=",sublen,"len(p)-sublen=",len(p)-sublen
			#
			# all possible starting index of the substr
			#
			for jx in xrange(0,(len(p)-sublen)+1):
				###print jx, sublen, p[jx:(jx+sublen)], ","+p[(jx+sublen):len(p)-sublen+1]
				try:
					self.gCount[p[jx:(jx+sublen)]] += 1 
				except:
					self.gCount[p[jx:(jx+sublen)]] = 1 
				count += 1
			#
			adjC = len(alphabets) if count > len(alphabets) else count
			totalC += adjC
			# print "adjC=",adjC,"totalC=",totalC
			count = 0
		return totalC

	# return len(p) + (len(p)-1) + ... + 1
	def strCombiCount_loop(self, p):
		fsum = 0
		count = len(p)
		while count > 0:
			fsum += count
			count -= 1
		return fsum

	# return len(p) + (len(p)-1) + ... + 1
	def strCombiCount_reduce(self, p):
		#                                <-------------> range() returns a LIST
		fsum = reduce( lambda x,y: x+y , range(len(p)+1) )
		return fsum

	def allCombi(self, p):
		# initialization
		matched = []
		count = totalCount = 0

		# generalized
#		print "len(p)=", len(p), "p=", p

		ar = self.uniqueStrs(p)
		print "uniqueStrs   =", ar
		ar = self.uniqueStrs_v2(p)
		print "uniqueStrs_v2=", ar
		if len(ar)==1:
			if len(ar[0]) <= len(alphabets): return self.strCombiCount_loop(ar[0]), 0
			else: return self.strCombiCount_loop(alphabets) + (len(alphabets)*(len(ar[0])-len(alphabets))), 0
		else:
			for p in ar:
				totalCount += self.strCombiCount(p)
		return len(self.gCount), totalCount

# -------------------------------------------------------------------------------
#
alphabets = "abcdefghijklmnopqrstuvwxyz"
#alphabets = "abc"

def testAllCombi(s, expected):
	gcount, n = Solution().findSubstringInWraproundString(s)
	if expected!=None:
		print "ret: ", n, "gCount:", gcount, "expected: ", expected, "ok" if gcount==expected else "<-- wrong"
	else:
		print "ret: ", n, "expected: TBD"

if __name__ == '__main__':

	# print Solution().findSubstringInWraproundString("a");

	if alphabets == "abc":
		#allCombi("abcabcabc")
		#allCombi("bcabcabc")
		#allCombi("cabcabc")
		allCombi("abc"*5)
		#allCombi("ab")

	#
#	testAllCombi("cdeab", 9)		# count=9
#	testAllCombi("abcde", 15)		# count=15
#	testAllCombi("bcdef", 15)		# count=15
#	testAllCombi("abcdef", 21)		# count=21
#	testAllCombi("bcde", 10)		# count=10
#	testAllCombi("abbc", 5)
	#
	testAllCombi("a", 1)		# count=1
	testAllCombi("ab", 3)		# count=3
	testAllCombi("ac", 2)		# count=2
	testAllCombi("cac", 2)		# count=2
	testAllCombi("zab", 6)		# count=6
	testAllCombi("abc", 6)		# count=6
	testAllCombi("aabb", 3)		# count=6
	testAllCombi("12467", 0)	# count=0
	testAllCombi("uvwxyzabcdefg", 91)		# count= 91
#	testAllCombi("cdefghefghijklmnopqrstuvwxmnijklmnopqrstuvbcdefghijklmnopqrstuvwabcddefghijklfghijklmabcdefghijklmnopqrstuvwxymnopqrstuvwxyz", 339)		# count= 33475
#	testAllCombi("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", 33475)
		# count= 33475
#	testAllCombi("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", 34151)
		# count= 34151
	testAllCombi("ijkwxyrstuvghijklmnopqrstghijklmnopqrstuvwbcdefghijklmnopstuvnopqrghidefghihijklmnopqrghijklmnopqrstuabcdmnuvwpqabcdefghijklmnopqrstuvwfghijklmnopqhijklmklmnopqabhijklmnopqrstuvopqrabcdefghijkldefghijklmnopqrstuvcdefghcdefghijklmnopjklaijklmnojklmnoabcdefghijklmnopqrstughijklmnopqcdefghvwxijklmnopqrstuvxyklmtuvwqrstuvoplmnopqrstuvwxyopqrstqrstuvwxynopqrstuvwhijklmfghijfghijklmnopqrstuvfghijklmbcdefghijklmnopqrsnopqrstuvdefghijklmnopqrcdefghijklmnfghijklmnopqrstuvwxyzefghijklmnopijklmnopqrsnopqrstuvwxycmnopqrstcdefghijklmnopqrtabcdeffghijklmndefghijkvwxyzxyopqvwabcdefgefghijklmnopqrstumnopqrstuvwxjklmnopqabcdefdefghijklmnopqrstuhijklmnopqrstuvijklmnopqrstucdefghijklmnopqrstuvwxabcdefghijklmnoopqrstuvlmnopqrstuvwxypqrstuvwcdabcdefghijklopqrstuvwxcdefghijklmnopqrstumnopqrstuvwxyzbcdefghijklmnopqrsqefghijklmnhijklmnopqrstuvwbcdefghijklmnoijklmnopqrstuvwnefghijefghijklmnopefghdefghiaklmnopqrstuvwefghijklmnopqrst", 339)
		# count= 339


