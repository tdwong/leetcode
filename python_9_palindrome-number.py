"""
//https://leetcode.com/problems/palindrome-number/
#
# 9. Palindrome Number
#
#	Determine whether an integer is a palindrome. Do this without extra space.
#
#	palindrome
#	A word, phrase, or sequence that reads the same backward as forward, e.g., madam or nurses run
#
"""

class Solution(object):
	""" not quite satisfy the requirement - a list[] is used
		229ms for all test leetcode cases
		77.65% leetcode ranking
	"""
	def isPalindrome(self, x):
		"""
		:type x: int
		:rtype: bool
		"""
#		 print "x=", x
		if x < 0:  return False
		res=[]
		while x > 0:
			res += [ x % 10]
			x /= 10
#		 print res
#		 print "len(res)", len(res)
		yes=True
		f=0
		b=len(res)-1
		while f<b:
#			print "f=", f, "b=", b, "res[f]=", res[f], "res[b]=", res[b]
			if res[f] != res[b]:
				yes=False
				break
			f += 1
			b -= 1
#		 print "yes=", yes
		return yes


class Solution2(object):
	""" not quite satisfy the requirement - a list[] is used
		262ms for all test leetcode cases
		43.60% leetcode ranking
	"""
	def isPalindrome(self, x):
		"""
		:type x: int
		:rtype: bool
		"""
		if x < 0:  return False
		res=[]
		while x > 0:
			res += [ x % 10]
			x /= 10
		rres=res[:]
		rres.reverse()
		return res==rres

class SolutionR(object):
	""" not quite satisfy the requirement - a list[] is used
	"""
	""" recursive solution
		slowest amongest all my python submissions
		302ms for all test leetcode cases
		22.75% leetcode ranking
	"""

	def isPalindrome(self, x):
		"""
		:type x: int
		:rtype: bool
		"""
		if x < 0: return False
		if x ==0: return True
#		print "rev=", reverse(x, 0)
		return x == self.reverse(x)

	def reverse(self, val, rev=0):
		"""
			val: value to be reversed
			rev: reversed value so far
		"""
#		print "---val=", val, "rev=", rev
		if val < 10: return rev*10 + val
#		ret = reverse(val/10, rev*10+val%10)
#		print "val=", val, "ret=", ret
#		return ret
		return self.reverse(val/10, rev*10+val%10)

import math
class SolutionM(object):
	""" use only one temporary variable to hold a duplicate of input value
		246ms for all test leetcode cases
		57.70% leetcode ranking
	"""
	def isPalindrome(self, x):
		"""
		:type x: int
		:rtype: bool
		"""
		if x < 0: return False
		if x ==0: return True
		y = int(math.floor(math.log(x,10)))
		z = 0
		while z < y:
#			 print "y:", x / pow(10,y) % 10, "z:", x / pow(10,z) % 10
			if x / pow(10,y) % 10 != x / pow(10,z) % 10:
				return False
			z += 1
			y -= 1
		return True


# ----------------------------------------------------------------------

input=[0, 10, 121, 12345, 112211]
input=[121, 12345]
input=[456, ]
input=[0, 10, 121, 12345, 112211, 456]
for x in input:
	print "x=", x

	s = Solution()
	print "Solution:  ", s.isPalindrome(x)
	s2 = Solution2()
	print "Solution2: ", s2.isPalindrome(x)
	sm = SolutionM()
	print "SolutionM: ", sm.isPalindrome(x)
	sr = SolutionR()
	print "SolutionR: ", sr.isPalindrome(x)

