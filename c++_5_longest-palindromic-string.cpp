//https://leetcode.com/problems/longest-palindromic-substring/
/*
#
# 5. Longest Palindromic Substring
#
#	Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
#	
#	Example:
#	
#		Input: "babad"
#	
#		Output: "bab"
#	
#		Note: "aba" is also a valid answer.
#	
#	Example:
#	
#		Input: "cbbd"
#	
#		Output: "bb"
#	
*/

// test cases:  babad cbbd xyz xyzy xyzz ccd aaabaaaa

#include <cstdio>
#include <string>

//* const std::string & swap(std::string & str)
void swap(std::string & str)
{
	int ix = 0, iy = str.size()-1;
	while (ix < iy) {
		char tmp = str[iy];
		str[iy] = str[ix];
		str[ix] = tmp;
		ix++; iy--;
	}
//*	return str;
}

// incomplete: cannot handle superLong case
std::string twoStrsPalindromic(const std::string & str, const std::string &swapped)
{
	int lms, llen;
	const int end = (str.size() / 2) + (str.size() % 2);

		lms = llen = -1;
		for (int jx=0, jy=0; jx <= end; /**/)
///		for (int jx=0, jy=0; jx < str.size(); /**/)
		{
			if (str[jx] != swapped[jy]) {
				// move ahead until a match
				for (/**/; jy <= end && (str[jx]!=swapped[jy]); jy++) /**/;
///				for (/**/; jy < str.size() && (str[jx]!=swapped[jy]); jy++) /**/;
				if (jy > end)
///				if (jy == str.size())
				{
					// no match found, continue with next character in original
					jx++; jy=0;
					continue;
				}
			}
			// a match found. try to stretch the match
			int kx = jx, ky = jy;
			while (str[kx] == swapped[ky]) {
				kx++; ky++;
			}
			//** if ((lms < 0) || ((kx-jx) > llen))
			if (lms < 0) {
				// no match before
				lms = jx; llen = kx-jx;
			}
			else if ((kx-jx) > llen) {
				// longer match found
				lms = jx; llen = kx-jx;
			}
			jx++; jy=0;
		}
		printf("%s: lms=%d, llen=%d, match=%s\n", __FUNCTION__, lms, llen, (lms>=0) ? str.substr(lms, llen).c_str() : "");		

	return (lms>=0) ? str.substr(lms, llen).c_str() : "";
}

/*
 * this approach is to reverse the original string and 
 * compare original and reversed string BOTH from the beginning of the string
 *
    302ms for all test leetcode cases
    14.23% leetcode ranking
 */
std::string twoStrsPalindromic_v2(const std::string & str, const std::string &swapped)
{
	int lms, llen;
	const int end = (str.size() / 2) + (str.size() % 2);

		lms = llen = -1;
		for (int jx=0, jy=0; jx < str.size(); /**/) {

			do {

				if (str[jx] != swapped[jy]) {
					// move ahead until a match
					for (/**/; jy < str.size() && (str[jx]!=swapped[jy]); jy++) /**/;
					if (jy == str.size())
					{
						// no match found, continue with next character in original
						break;
					}
				}
				// a match found. try to stretch the match
				int kx = jx, ky = jy;
				while (str[kx] == swapped[ky]) {
					kx++; ky++;
				}
				//** if ((lms < 0) || ((kx-jx) > llen))
				if (lms < 0) {
					// no match before
					lms = jx; llen = kx-jx;
				}
				else if ((kx-jx) > llen) {
					// longer match found
					lms = jx; llen = kx-jx;
				}
				jy = ky;	// continue with last mis-matched character as the first character

			} while (jy < (str.size() - jx));

			// no match found, continue with next character in original
			jx++; jy=0;

		}
		printf("%s: lms=%d, llen=%d, match=%s\n", __FUNCTION__, lms, llen, (lms>=0) ? str.substr(lms, llen).c_str() : "");		

	return (lms>=0) ? str.substr(lms, llen).c_str() : "";
}

/*
 * this approach is to 
 * walk the original from the HEAD and the TAIL of the string
 *
    189ms for all test leetcode cases
    21.61% leetcode ranking
 */
std::string sameStrPalindromic_v2(const std::string & str)
{
	int lms, llen;
	const int end = (str.size() / 2) + (str.size() % 2);

		lms = llen = -1;
		for (int jx=0, jy=str.size()-1; jx <= end; /**/) {

			do {

				if (str[jx] != str[jy]) {
					// move ahead until a match
					for (/**/; jy > jx && (str[jx]!=str[jy]); jy--) /**/;
					if (jy <= jx) {
						// break out do-while
						break;
					}
				}
				// a match found. try to stretch the match
				int kx = jx, ky = jy;
				while (str[kx] == str[ky]) {
					kx++; ky--;
				}
				//** if ((lms < 0) || ((kx-jx) > llen))
				if (lms < 0) {
					// no match before
					lms = jx; llen = kx-jx;
				}
				else if ((kx-jx) > llen) {
					// longer match found
					lms = jx; llen = kx-jx;
				}
				jy = ky;	// continue with last mis-matched character as the first character

			} while (jy > jx);

			// no match found, continue with next character in original
			jx++; jy=str.size()-1;
		}
		printf("%s: lms=%d, llen=%d, match=%s\n", __FUNCTION__, lms, llen, (lms>=0) ? str.substr(lms, llen).c_str() : "");		

	return (lms>=0) ? str.substr(lms, llen).c_str() : "";
}

std::string superLong = 
"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
std::string superLong2 =
"ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";

int main(int argc, char **argv)
{
	int ix;

	for (ix = 1; ix < argc; ix++) {

		printf("-------\n");
		printf("before: %s\n", argv[ix]);
		std::string str = argv[ix];
//*		std::string swapped = swap(str);
		swap(str);
	#if 0	// str = original
		std::string swapped = str;
		printf("after : %s\n", swapped.c_str());
		// restore changed str
		str = argv[ix];
	#else	// swapped = original
		printf("after : %s\n", str.c_str());
		std::string swapped = argv[ix];
	#endif

		int lms, llen;
		const int end = (str.size() / 2) + (str.size() % 2);

#define _do_swap_	1
#ifdef _do_swap_

		std::string ds1 = twoStrsPalindromic_v2(str, swapped);
		std::string ds2 = twoStrsPalindromic_v2(swapped, str);
		printf("_do_swap_: match=%s\n", ds1.size()>ds2.size() ? ds1.c_str() : ds2.c_str());

#endif	//_do_swap_

		std::string ns1 = sameStrPalindromic_v2(str);
		std::string ns2 = sameStrPalindromic_v2(swapped);
		printf("_no_swap_: match=%s\n", ns1.size()>ns2.size() ? ns1.c_str() : ns2.c_str());

	}

	std::string swapped;
	//
	printf("superLong size=%ld\n", superLong.size());
	printf("     superLong: %s\n", superLong.c_str());
	swapped = superLong;
	swap(swapped);
	printf("swap superLong: %s\n", swapped.c_str());
	std::string s11=sameStrPalindromic_v2(superLong);
	std::string s12=twoStrsPalindromic_v2(superLong, swapped);

	//
	printf("superLong2 size=%ld\n", superLong2.size());
	printf("     superLong2: %s\n", superLong2.c_str());
	swapped = superLong2;
	swap(swapped);
	printf("swap superLong2: %s\n", swapped.c_str());
	std::string s21=sameStrPalindromic_v2(superLong2);
	std::string s22=twoStrsPalindromic_v2(superLong2, swapped);

	return 0;
}
