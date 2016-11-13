"""
#
#       Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
#
#       Output: 7 -> 0 -> 8
#
"""

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

a=ListNode(3)
b=ListNode(4)
b.next=a
c=ListNode(2)
c.next=b

def printList(x):
	while x:
		print x.val,
		x = x.next
	print

def buildList(nums):
	head = None
	prev = None
	for n in nums:
##		print n
		node = ListNode(n)
		if head == None: head = node
		if prev != None: prev.next = node
		prev = node
##		print "prev", prev.val
##	printList(head)
	return head

#class Solution(object):
#    def addTwoNumbers(self, l1, l2):
#        """
#        :type l1: ListNode
#        :type l2: ListNode
#        :rtype: ListNode
#        """

def addLists(l1,l2):
#	print "L1", printList(l1)
#	print "L2", printList(l2)
	carryOver = 0
	z = []
	while l1 != None or l2 != None:
### n1 & n2 not set if l1 or l2 is None
###		if l1 != None: n1 = l1.val
###		if l2 != None: n2 = l2.val
### the better solution that set n1 or n2 to 0
		n1 = l1.val if l1 != None else 0
		n2 = l2.val if l2 != None else 0
		sum = n1 + n2 + carryOver
		if sum > 9:
			sum = sum - 10
			carryOver = 1
		else:
			carryOver = 0
		z.append(sum)
		if l1 != None: l1 = l1.next
		if l2 != None: l2 = l2.next
	if carryOver != 0: z.append(carryOver)
	return buildList(z)


n1=buildList([2,4,3])
n2=buildList([5,6,4])
printList(addLists(n1,n2))

n1=buildList([0])
n2=buildList([0])
printList(addLists(n1,n2))

n1=buildList([5])
n2=buildList([5])
printList(addLists(n1,n2))

n1=buildList([1,8])
n2=buildList([0])
printList(addLists(n1,n2))

n1=buildList([9,8])
n2=buildList([1])
printList(addLists(n1,n2))

n1=buildList([9,9])
n2=buildList([1])
printList(addLists(n1,n2))
