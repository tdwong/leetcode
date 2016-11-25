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

// test cases:  babad cbbd xyz xyzy xyzz ccd aaabaaaa a bb


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
extern char *strdup (char *str);

void reverse(char *str)
{
	int ix = 0, iy = strlen(str)-1;
	while (ix < iy) {
		char tmp = str[iy];
		str[iy] = str[ix];
		str[ix] = tmp;
		ix++; iy--;
	}
}

/*
 * this approach is to reverse the original string and 
 * compare original and reversed string BOTH from the beginning of the string
 *
    Time Limit Exceeded
 */
char *twoStrsPalindromic_v2(char *str, char *swapped)
{
	int lms, llen;
	const int end = (strlen(str) / 2) + (strlen(str) % 2);

	// corner case
	if (strlen(str)==1) {  return strdup(str); }

		lms = llen = -1;
		for (int jx=0, jy=0; jx < strlen(str); /**/) {

			int sy = jy;
			int matched = 0;
			do {

				if (str[jx] != swapped[jy]) {
					// move ahead until a match
					for (/**/; jy < strlen(str) && (str[jx]!=swapped[jy]); jy++) /**/;
					if (jy == strlen(str))
					{
						// no match found, continue with next character in original
						break;
					}
				}
				// a match found. try to stretch the match
				int kx = jx, ky = jy;
				while ((str[kx] == swapped[ky]) && (kx < strlen(str)) && (ky < strlen(swapped))) {
					kx++; ky++;
				}
				/*** sanity check ***/
				if ((kx-jx)==2 && str[kx-2]!=str[kx-1]) {
					// len=2 palindromic string must have same character
					jy = ky;
					continue;
				}
				/*** sanity check ***/
				if ((strlen(str)-ky) != jx) {
					/* matched strings in str & swapped must be adjacent
					 * str:     [][]<[jx][m][m]>[][][]
					 * swapped: [][][]<[m][m][m]>[ky][]
					 */
					jy = ky;
					continue;
				}

				//** if ((lms < 0) || ((kx-jx) > llen))
				if (lms < 0) {
					matched++;
					// no match before
					lms = jx; llen = kx-jx;
				}
				else if ((kx-jx) > llen) {
					matched++;
					// longer match found
					lms = jx; llen = kx-jx;
/* // debug-only
char *sofar = malloc(llen+1);
strncpy(sofar, &str[jx], llen);
sofar[llen] = 0;
printf("lms=%d, llen=%d, sofar=%s\n", lms, llen, sofar);
free(sofar);
*/ // debug-only
				}
				jy = ky;	// continue with last mis-matched character as the first character

			} while (jy < (strlen(str) - jx));

			if (matched == 0) {
				// no match found, continue with next character in original
				jx++; jy=0;
			}
			else {
				jy=sy+1;
			}

		}
// printf("lms=%d, llen=%d\n", lms, llen);
	char *sstr = malloc(llen+1);
	strncpy(sstr, &str[lms], llen);
	sstr[llen] = 0;

		printf("%s: lms=%d, llen=%d, match=%s\n", __FUNCTION__, lms, llen, (lms>=0) ? sstr : "");		

	return (lms>=0) ? sstr: "";
}

/*
 * this approach is to 
 * walk the original from the HEAD and the TAIL of the string
 *
    223ms for all test leetcode cases
    5.83% leetcode ranking
 */
char *sameStrPalindromic_v2(char *str)
{
	int lms, llen;
	const int end = (strlen(str) / 2) + (strlen(str) % 2);

	// corner case
	if (strlen(str)==1) {  return strdup(str); }

		lms = llen = -1;
//		for (int jx=0, jy=strlen(str)-1; jx <= end; /**/) {
		for (int jx=0, jy=strlen(str)-1; jx < strlen(str); /**/) {

			int sy = jy;
			int matched = 0;
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
				while ((str[kx] == str[ky]) && (kx < strlen(str))) {
					kx++; ky--;
				}

/* // debug-only
if ((kx-jx) >= 2) printf("%s: jx=%d [%c], kx=%d [%c], ky=%d [%c], jy=%d [%c], len=%d\n", __FUNCTION__, jx, str[jx], kx, str[kx], ky, str[ky], jy, str[jy], (int)strlen(str));
*/ // debug-only

				/*** sanity check ***/
				if (((kx-jx) >= 2) && ((ky+1) != jx)) {
					/* matched strings must be overlapped
					 * str_forward:  [][]<[jx][m][m]>[][][]
					 * str_backward: [][ky]<[m][m][m]>[][][]
					 */
					jy = ky;
					continue;
				}

				//** if ((lms < 0) || ((kx-jx) > llen))
				if (lms < 0) {
					matched++;
					// no match before
					lms = jx; llen = kx-jx;
				}
				else if ((kx-jx) > llen) {
					matched++;
					// longer match found
					lms = jx; llen = kx-jx;
/* // debug-only
char *sofar = malloc(llen+1);
strncpy(sofar, &str[jx], llen);
sofar[llen] = 0;
printf("lms=%d, llen=%d, sofar=%s\n", lms, llen, sofar);
free(sofar);
*/ // debug-only
				}
				jy = ky;	// continue with last mis-matched character as the first character

			} while (jy > jx);

			if (matched == 0) {
				// no match found, continue with next character in original
				jx++; jy=strlen(str)-1;
			}
			else {
				jy=sy-1;
			}

		}
// printf("lms=%d, llen=%d\n", lms, llen);
	char *sstr = malloc(llen+1);
	strncpy(sstr, &str[lms], llen);
	sstr[llen] = 0;

		printf("%s: lms=%d, llen=%d, match=%s\n", __FUNCTION__, lms, llen, (lms>=0) ? sstr : "");		

	return (lms>=0) ? sstr: "";
}

char * superLongs[] =
{
"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"
,
"ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy"
,
"tuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq"
,
"esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq"
,
"fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
,
"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
,
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
,
};

int main(int argc, char **argv)
{
	int ix;

	for (ix = 1; ix < argc; ix++) {

		printf("-------\n");
		printf("before: %s\n", argv[ix]);
		char * str = argv[ix];
		char * swapped = strdup(argv[ix]);
		reverse(swapped);
		printf("after : %s\n", swapped);

		int lms, llen;
		const int end = (strlen(str) / 2) + (strlen(str) % 2);

#define _do_swap_	1
#ifdef _do_swap_

		char * ds1 = twoStrsPalindromic_v2(str, swapped);
		//char * ds2 = twoStrsPalindromic_v2(swapped, str);
		//printf("_do_swap_: match=%s\n", strlen(ds1)>strlen(ds2) ? ds1 : ds2);

#endif	//_do_swap_

		char * ns1 = sameStrPalindromic_v2(str);
		//char * ns2 = sameStrPalindromic_v2(swapped);
		//printf("_no_swap_: match=%s\n", strlen(ns1)>strlen(ns2) ? ns1 : ns2);

		//
		free(swapped);
	}

	// done with all provided cases (on command line)
	if (argc > 1) { return 0; }

	char * swapped;
	for (int isl = 0; isl < (sizeof(superLongs)/sizeof(char *)); isl++) {
		printf("superLongs[%d].size=%ld: %s\n", isl, strlen(superLongs[isl]), superLongs[isl]);
		//
		char *str = superLongs[isl];
		char *swapped = strdup(superLongs[isl]);
		reverse(swapped);
		printf("swap superLongs[%d]: %s\n", isl, swapped);
		char * s01=sameStrPalindromic_v2(str);
		char * s02=twoStrsPalindromic_v2(str, swapped);
		free(swapped);
	}

#if 0
	//
	printf("superLong1 size=%ld\n", strlen(superLong1));
	printf("     superLong1: %s\n", superLong1);
	swapped = strdup(superLong1);
	reverse(swapped);
	printf("swap superLong1: %s\n", swapped);
	char * s11=sameStrPalindromic_v2(superLong1);
	char * s12=twoStrsPalindromic_v2(superLong1, swapped);
	free(swapped);

	//
	printf("superLong2 size=%ld\n", strlen(superLong2));
	printf("     superLong2: %s\n", superLong2);
	swapped = strdup(superLong2);
	reverse(swapped);
	printf("swap superLong2: %s\n", swapped);
	char * s21=sameStrPalindromic_v2(superLong2);
	char * s22=twoStrsPalindromic_v2(superLong2, swapped);
	free(swapped);

	//
	printf("superLong3 size=%ld\n", strlen(superLong3));
	printf("     superLong3: %s\n", superLong3);
	swapped = strdup(superLong3);
	reverse(swapped);
	printf("swap superLong3: %s\n", swapped);
	char * s31=sameStrPalindromic_v2(superLong3);
	char * s32=twoStrsPalindromic_v2(superLong3, swapped);
	free(swapped);

	//
	printf("superLong4 size=%ld\n", strlen(superLong4));
	printf("     superLong4: %s\n", superLong4);
	swapped = strdup(superLong4);
	reverse(swapped);
	printf("swap superLong4: %s\n", swapped);
	char * s41=sameStrPalindromic_v2(superLong4);
	char * s42=twoStrsPalindromic_v2(superLong4, swapped);
	free(swapped);

	//
	printf("superLong5 size=%ld\n", strlen(superLong5));
	printf("     superLong5: %s\n", superLong5);
	swapped = strdup(superLong5);
	reverse(swapped);
	printf("swap superLong5: %s\n", swapped);
	char * s51=sameStrPalindromic_v2(superLong5);
	char * s52=twoStrsPalindromic_v2(superLong5, swapped);
	free(swapped);
#endif

	return 0;
}
