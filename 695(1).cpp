//#include <iostream>
//#include <string>
//#include <stdlib.h>
//#include <string.h>
//#include <algorithm>
//	
//using namespace std;
// 
////bigint as string operations 
//string add(string str, string str1);
//string sub(string str, string str1);
//string karatsuba(string str, string str1);
//string divide(string str, string str1);
//string multiply(string a, string b);
//string getPow(string str, int str1);
//string getPow1(string str, int str1);
//inline int getDotLoc(string num)
//{
//	int d = 0;
//	for (register int a = 0; a < 6; a++)
//	{
//		if (num[a] == '.')
//		{
//			d = a;
//			break;
//		}		
//	}
//	return 5-d;
//}
//void getAns(int a,string ans,int p)
//{
//	
//	//cout << ans << endl << endl;
//	string ans1;
//	int p1 = p;
//	//cout << ans.length() - ans.length() - p1 * a;
//	if ((ans.length() - ans.length() - p1 * a))
//	{
//		for (register int b = ans.find_first_not_of('0'); b < ans.length() - a * p1; b++)
//		{
//			ans1 += ans[b];
//		}
//		ans1 += '.';
//		for (register int b = ans.length() - a * p1; b < ans.length(); b++)
//		{
//			ans1 += ans[b];
//		}
//
//		ans1.erase(ans1.find_last_not_of('0') + 1);
//		if(ans1[ans1.length()-1]=='.')
//			ans1[ans1.length() - 1] = '\0';
//		else
//			ans1[ans1.length()] = '\0';
//		cout << ans1 << endl;
//	}
//	else
//		cout << ans << endl;
//}
//int main()
//{
//	string n;
//	int p;
//	while (cin >> n >> p)
//	{
//		bool flag = true;
//		string res;
//		double d = stod(n);
//		int b = getDotLoc(n);
//		//cout << n << "," << b << endl;
//		string n1;
//		for (register int a = 0; a < 6; a++)
//		{
//			if (n[a] == '.');
//			else
//				n1 += n[a];
//
//		}
//		//n1[5] = '\0';
//		//cout << n1 << "," << b << endl;
//		//cout << sub(p, "1")<< endl;
//		/*if (d < 1)
//		{
//			getAns(b, getPow1(n1, p), p);
//		}
//		else
//		{
//			getAns(b, getPow1(n1, p),p);
//		}*/
//		getAns(b, getPow1(n1, p), p);
//	}
//	return 0;
//}
//
//string add(string str, string str1)
//{
//	string res;
//	int len1 = str.length();
//	int len2 = str1.length();
//	int len = max(len1, len2);
//	for (register int a = len2; a < len; a++)
//		str1 = '0' + str1;
//	for (register int a = len1; a < len; a++)
//		str = '0' + str;
//	
//	/*cout << str << endl << str1;*/
//
//	int c = 0,temp = 0;
//	//find sum
//	for (register int a = len - 1; a > -1; a -= 1)
//	{
//		temp = c + (str[a] - 48) + (str1[a] - 48);
//		res.insert(0, to_string(temp%10));
//		c = temp / 10;
//	}
//
//	if (c)
//	{
//		res.insert(0, to_string(c));
//	}
//
//	int n = res.find_first_not_of('0');
//	if (n != 0)
//		res.erase(0, n);
//
//	if (res.length() == 0)
//		return "0";
//	return res;
//}
//
//string sub(string str, string str1)
//{
//	int len1 = str.length();
//	int len2 = str1.length();
//	int len = max(len1, len2);
//	for (register int a = len2; a < len; a++)
//		str1 = '0' + str1;
//	for (register int a = len1; a < len; a++)
//		str = '0' + str;
//	//cout << str << endl << str1;
//
//	int temp; 
//	string res;
//	--len;
//	//find difference
//	for (; len > -1; len-=1)
//	{
//		temp = (str[len] - 48) - (str1[len] - 48);
//		if (temp >= 0)
//		{
//			res.insert(0, to_string(temp));
//		}
//		else
//		{
//			register int b = len - 1;
//			for(;b>-1;b--)
//			{
//				str[b] = ((str[b] - 48) - 1) % 10 + 48;
//				if (str[b] != '9')
//					break;
//			}
//			res.insert(0, to_string(temp + 10));
//		}
//		
//	}
//
//	int n = res.find_first_not_of('0');
//	if (n != 0)
//		res.erase(0, n);
//
//	if (res.length() == 0)
//		return "0";
//	return res;
//}
//
//string karatsuba(string str,string str1)
//{
//	string res;
//	char diff = 0;
//	int len1 = str.length();
//	int len2 = str1.length();
//	if (len1 != len2)
//	{
//		if (len1 - len2 > 0)
//			diff = 1;
//		else
//			diff = 2;
//	}
//	if (diff)
//	{
//		if (diff == 1) {
//			for (register int a = 0; a < len1 - len2; a++)
//				str1 = '0' + str1;
//			len2 = len1;
//		}
//		else {
//			for (register int a = 0; a < len2 - len1; a++)
//				str = '0' + str;
//			len1 = len2;
//		}
//	}
//	//cout << str << endl << str1;
//
//	if (len1 == 1)
//		res = to_string((str[0] - 48)*(str1[0] - 48));
//	else
//	{
//		int mid = len1 / 2;
//		int s = len1 - len1 / 2;
//		string l0 = str.substr(0, mid);
//		string l1 = str.substr(mid, s);
//		string r0 = str1.substr(0, mid);
//		string r1 = str1.substr(mid, s);
//
//		string a = karatsuba(l0, r0);
//		string b = karatsuba(l1, r1);
//		string c = karatsuba(add(l1, l0), add(r1, r0));
//		string d = sub(c, add(a, b));
//
//		for (register int k = 0; k < 2 * s; k++)
//		{
//			a.append("0");
//		}
//		for (register int k = 0; k < s; k++)
//		{
//			d.append("0");
//		}
//
//		res = add(add(a, b), d);
//	}
//	int n = res.find_first_not_of('0');
//	if (n != 0)
//		res.erase(0, n);
//
//	if (res.length() == 0)
//		return "0";
//	return res;
//}
//
//string divide(string str, string str1)
//{
//	int a = stoi(str1);
//	double b = 1 / a;
//	str1 = to_string(b);
//	return multiply(str, str1);
//}
//
//inline bool isEven(string str)
//{
//	if (stoi(str) & 1 == 0)
//		return true;
//	return false;
//}
//inline bool isMod3(string str)
//{
//	if (stoi(str) % 3 == 0)
//		return true;
//	return false;
//}
//
//string getPow(string str, int str1)
//{
//	string ans;
//	//recursively compute power off two string as if they were ints by calling karatsuba
//	if (str1 == 0)
//		return "1";
//	else if (str1 == 0)
//		return str;
//	//else if (isEven(str1))
//	//{
//	//	ans = getPow(str, multiply(str1, "0.5"));
//	//	return karatsuba(ans, ans);
//	//}
//	/*else if (isMod3(str1))
//	{
//	ans = getPow1(str, karatsuba(str1, "0.33"));
//	return karatsuba(karatsuba(ans, ans), ans);
//	}*/
//
//	else if (str1 == 2)
//		return karatsuba(str, str);
//	else if (str1 & 1)
//	{
//		return karatsuba(str, getPow(getPow(str, str1 >> 1), 2));
//	}
//	/*else if (isMod3(str1))
//	{
//	ans = getPow1(str, multiply(str1, "0.33"));
//	return multiply(multiply(ans, ans), ans);
//	}*/
//	else
//		return getPow(getPow(str, str1 >> 1), 2);
//
//	//too slow
//	/*else
//		return karatsuba(str,getPow(str, str1-1));*/
//}
//
//string multiply(string str, string str1)
//{
//	int shaata[2 << 15];
//	int c = 0;
//	int len = str.length();
//	int len1 = str1.length();
//	for (register int a = 0; a < 2 << 15; a++)
//		shaata[a] = 0;
//
//	for (register int a = 0; a < len1; a++)
//	{
//		for (register int b = 0; b < len; b++)
//		{
//			shaata[b + 1 + a] += (int)((str1[a] - 48)*(str[b] - 48));
//		}
//	}
//
//	for (register int a = len1 + len ; a >= 1; a--)
//	{
//		int s = shaata[a] + c;
//		shaata[a] = s% 10;
//		c = s / 10;
//	}
//
//	shaata[0] = c;
//
//
//	string ans = "";
//	for (register int a = 0; a <= len1 + len-1 ; a++)
//	{
//		if (shaata[a] == 0 && a == 0)
//		{
//			continue;
//		}
//		else
//		{
//			ans += (char)(shaata[a] + 48);
//		}
//	}
//
//	return ans;
//}
//
//
//string getPow1(string str, int str1)
//{
//	//recursively compute power off two string as if they were ints by calling karatsuba
//	
//	if (str1 == 1)
//		return str;
//	else if (str1 == 0)
//			return "1";
//	else if (str1 == 2)
//		return multiply(str, str);
//	else if (str1&1)
//	{
//		return multiply(str,getPow1(getPow1(str, str1>>1), 2));
//	}
//	/*else if (isMod3(str1))
//	{
//		ans = getPow1(str, multiply(str1, "0.33"));
//		return multiply(multiply(ans, ans), ans);
//	}*/
//	else
//		return getPow1(getPow1(str,str1>>1),2);
//}