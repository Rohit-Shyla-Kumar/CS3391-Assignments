//#include <string>
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//string arr[100] = { "I","II","III", "IV", "V", "VI", "VII", "VIII", "IX", "X","XI" ,"XII","XIII","XIV" ,"XV","XVI","XVII" ,"XVIII","XIX","XX" ,"XXI","XXII" ,"XXIII","XXIV" ,"XXV","XXVI" ,"XXVII","XXVIII" ,"XXIX","XXX" ,"XXXI","XXXII" ,"XXXIII","XXXIV" ,"XXXV","XXXVI" ,"XXXVII","XXXVIII" ,"XXXIX","XL","XLI","XLII","XLIII","XLIV","XLV","XLVI","XLVII","XLVIII","XLIX","L","LI","LII","LIII","LIV","LV","LVI","LVII","LVIII","LIX","LX","LXI","LXII","LXIII","LXIV","LXV","LXVI","LXVII","LXVIII","LXIX","LXX","LXXI","LXXII","LXXIII","LXXIV","LXXV","LXXVI","LXXVII","LXXVIII","LXXIX","LXXX","LXXXI","LXXXII","LXXXIII","LXXXIV","LXXXV","LXXXVI","LXXXVII","LXXXVIII","LXXXIX","XC","XCI","XCII","XCIII","XCIV","XCV","XCVI","XCIVII","XCVIII","XCIX","C" };
//void count(int &i, int &v, int &l, int &c,int &x,string s)
//{
//	for (register int a = 0; a < s.length(); a++)
//	{
//		if (s[a] == 'I')
//			i++;
//		else if (s[a] == 'C')
//			c++;
//		else if (s[a] == 'V')
//			v++;
//		else if (s[a] == 'L')
//			l++;
//		else
//			x++;
//	}
//}
//int main()
//{
//	int n;
//	int x1[101], l1[101], c1[101], v1[101], i1[101];
//	x1[0] = 0;
//	l1[0] = 0;
//	c1[0] = 0;
//	v1[0] = 0;
//	i1[0] = 0;
//	for (register int a = 1; a <= 100; a++)
//	{
//		int i = 0, v = 0, l = 0, c = 0, x = 0;
//		count(i, v, l, c, x, arr[a-1]);
//		x1[a] = x1[a - 1] + x;
//		v1[a] = v1[a - 1] + v;
//		l1[a] = l1[a - 1] + l;
//		i1[a] = i1[a - 1] + i;
//		c1[a] = c1[a - 1] + c;
//	}
//	while (~scanf("%d", &n))
//	{
//		if (n == 0)
//			return 0;
//		
//		if(n>=97)
//			printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i1[n]-1, v1[n], x1[n], l1[n], c1[n]);
//		else
//			printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i1[n] , v1[n], x1[n], l1[n], c1[n]);
//	}
//	return 0;
//}