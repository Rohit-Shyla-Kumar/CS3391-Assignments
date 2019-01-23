//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <string.h>
//#include <iomanip>
//#include <unordered_map>
//using namespace std;
//int getSingle(int arr[], int n)
//{
//	int ones = 0, twos = 0;
//
//	int common_bit_mask;
//
//	// Let us take the example of {3, 3, 2, 3} to understand this
//	for (int i = 0; i< n; i++)
//	{
//		/* The expression "one & arr[i]" gives the bits that are
//		there in both 'ones' and new element from arr[].  We
//		add these bits to 'twos' using bitwise OR
//
//		Value of 'twos' will be set as 0, 3, 3 and 1 after 1st,
//		2nd, 3rd and 4th iterations respectively */
//		twos = twos | (ones & arr[i]);
//
//
//		/* XOR the new bits with previous 'ones' to get all bits
//		appearing odd number of times
//
//		Value of 'ones' will be set as 3, 0, 2 and 3 after 1st,
//		2nd, 3rd and 4th iterations respectively */
//		ones = ones ^ arr[i];
//
//
//		/* The common bits are those bits which appear third time
//		So these bits should not be there in both 'ones' and 'twos'.
//		common_bit_mask contains all these bits as 0, so that the bits can
//		be removed from 'ones' and 'twos'
//
//		Value of 'common_bit_mask' will be set as 00, 00, 01 and 10
//		after 1st, 2nd, 3rd and 4th iterations respectively */
//		common_bit_mask = ~(ones & twos);
//
//
//		/* Remove common bits (the bits that appear third time) from 'ones'
//
//		Value of 'ones' will be set as 3, 0, 0 and 2 after 1st,
//		2nd, 3rd and 4th iterations respectively */
//		ones &= common_bit_mask;
//
//
//		/* Remove common bits (the bits that appear third time) from 'twos'
//
//		Value of 'twos' will be set as 0, 3, 1 and 0 after 1st,
//		2nd, 3rd and 4th itearations respectively */
//		twos &= common_bit_mask;
//
//		// uncomment this code to see intermediate values
//		//printf (" %d %d n", ones, twos);
//	}
//
//	return ones;
//}
//
//
//string input;
//int main()
//{
//	int n;
//	//memset(arr, 0, sizeof(arr));
//	while (~scanf("%d",&n))
//	{
//		getline(cin, input);
//		unordered_map<string,int> map;
//		for (register int i = 0; i < 2 * n - 1; i++)
//		{
//			getline(cin, input);
//			if (map[input] == 1)
//				map[input] = 2;
//			else
//				map[input] = 1;
//		}
//		string ans;
//		// Iterate and print keys and values of unordered_map
//		for (const auto& n : map) {
//			if (n.second == 1)
//			{
//				ans = n.first;
//				break;
//			}
//		}
//
//		cout << ans << endl;
//
//		/*printf("The element with single occurrence is %d ",getSingle(arr, n));*/
//	}
//	
//	
//	return 0;
//}