"""
https://leetcode.com/contest/leetcode-weekly-contest-12/problems/validate-ip-address/
#
# 468. Validate IP Address
#
#	In this problem, your job to write a function to check whether a input string is a valid IPv4
#	address or IPv6 address or neither.
#	
#	IPv4 addresses are canonically represented in dot-decimal notation, which consists of four
#	decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
#	
#	Besides, you need to keep in mind that leading zeros in the IPv4 is illegal. For example,
#	the address 172.16.254.01 is illegal.
#	
#	IPv6 addresses are represented as eight groups of four hexadecimal digits, each group
#	representing 16 bits. The groups are separated by colons (":"). For example, the address
#	2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a legal one. Also, we could omit some leading zeros
#	among four hexadecimal digits and some low-case characters in the address to upper-case ones,
#	so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using
#	upper cases).
#	
#	However, we don't replace a consecutive group of zero value with a single empty group using
#	two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334
#	is an invalid IPv6 address.
#	
#	Besides, you need to keep in mind that extra leading zeros in the IPv6 is also illegal. For
#	example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is also illegal.
#	
#	Note: You could assume there is no extra space in the test cases and there may some special
#	characters in the input string.
#	
#	Example 1:
#	
#	    Input: "172.16.254.1"
#	
#	    Output: "IPv4"
#	
#	Explanation: This is a valid IPv4 address, return "IPv4".
#	
#	Example 2:
#	
#	    Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
#	
#	    Output: "IPv6"
#	
#	    Explanation: This is a valid IPv6 address, return "IPv6".
#	
#	Example 3:
#	
#	    Input: "256.256.256.256"
#	
#	    Output: "Neither"
#	
#	    Explanation: This is neither a IPv4 address nor a IPv6 address.
#	
"""

#/* testcases
# *
testcases = [
    [ "172.16.254.1"      , "IPv4" ],
    [ "192.168.100.1"     , "IPv4" ],
    [ "192.168.100.01"    , "Neither" ],
    [ "256.256.266.256"   , "Neither" ],
    [ "192.0.0.1"         , "IPv4" ],
    [ "2001:0db8:85a3:0:0:8A2E:0370:7334"         , "IPv6" ],
    [ "2001:0db8:85a3:0000:0000:8A2E:0370:7334"   , "IPv6" ],
    [ "2001:0db8:85a3:0:0000:8A2E:0370:7334"      , "IPv6" ],
    [ "2001:0db8:85a3:00:0000:8A2E:0370:7334"     , "IPv6" ],
    [ "2001:0db8:85a3:000:00:8A2E:0370:7334"      , "IPv6" ],
    [ "2001:0db8:85a3:0000:00000:8A2E:0370:7334"  , "IPv6" ],
    [ "2001:0db8:85a3:033:0:8A2E:0370:7334"       , "IPv6" ],
    [ "2001:0db8:85a3:00000:0:8A2E:0370:7334"     , "Neither" ],
    [ "2001:db8:85a3:0::8a2E:0370:7334"           , "Neither" ],
]
# *
# */

class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        sIPv4="0123456789"
        sIPv6="0123456789abcdefABCDEF"
        #
        cIPv4 = IP.split('.')
        if len(cIPv4) == 4:
            # possible IPv4
            bIPv4 = True
                # invalid leading zero
            for i in range(0,4):
                if len(cIPv4[i])>1 and cIPv4[i][0] not in "123456789":
                    bIPv4 = False
                    break
            if bIPv4==True:
                    # first octet must be between 1..255
                try:
                    #print "cIPv4[0]=", int(cIPv4[0])
                    if 0<int(cIPv4[0]) and int(cIPv4[0])<256:
                        for i in range(1,4):
                            #print "cIPv4[", i, "]=", int(cIPv4[i])
                            if not (0<=int(cIPv4[i]) and int(cIPv4[i])<256):
                                #print "bIPv4=False"
                                bIPv4 = False
                                break
                    else: bIPv4 = False
                except:
                    bIPv4 = False
            if bIPv4==True: return "IPv4"
        # not an IPv4 address
        cIPv6 = IP.split(':')
        if len(cIPv6) == 8:
            # possible IPv6
            bIPv6 = True
            for i in range(0,8):
                # validate individual field
                if cIPv6[i]=='0' or cIPv6[i]=='00' or cIPv6[i]=='000' or cIPv6[i]=='0000':
                    # ok
                    pass
                elif len(cIPv6[i])==0 or len(cIPv6[i])>4:
                    bIPv6 = False
                    break
                else:
                    for j in range(len(cIPv6[i])):
                        if cIPv6[i][j] not in sIPv6:
                            bIPv6 = False
                            break
                # continue to next field?
                if bIPv6 != True: break
            if bIPv6==True: return "IPv6"
        #
        return "Neither"

#--- main ---
s = Solution()
for tcase in testcases:
    print tcase[0], ": ", s.validIPAddress(tcase[0]), "expected:", tcase[1]

