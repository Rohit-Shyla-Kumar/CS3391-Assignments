//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <algorithm>
//
//#define MAX_DIGITS 1000
//#define PLUS 1
//#define MINUS -1
//
//using namespace std;
//
//class bignum
//{
//public:
//	char digits[MAX_DIGITS];
//	short signbit;
//	short lastDigit;
//};
//void initialize_bignum(bignum* a)
//{
//	for (int i = 0; i < MAX_DIGITS; i++)
//		a->digits[i] = '0';
//}
//void zero_justify(bignum* a)
//{
//	while ((a->lastDigit > 0) && (a->digits[a->lastDigit] == 0))
//		a->lastDigit--;		
//
//	if ((a->lastDigit == 0) && (a->digits[0] == 0))
//		a->signbit = PLUS;
//}
//void subtract_bignum(bignum*, bignum*, bignum*);
//void add_bignum(bignum* a,bignum *b,bignum *c)
//{
//	int carry;
//	int i;
//
//	initialize_bignum(c);
//
//	if (a->signbit == b->signbit)
//	{
//		c->signbit = a->signbit; //if both are the same sign, even their addition will have the same sign
//	}
//
//	else
//	{
//		if (a->signbit == MINUS)
//		{
//			a->signbit = PLUS;
//			subtract_bignum(b, a, c);
//			a->signbit = MINUS;
//		}
//		else
//		{
//			b->signbit = PLUS;
//			subtract_bignum(a, b, c);
//			b->signbit = MINUS;
//		}
//		return;
//	}
//
//	c->lastDigit = max(a->lastDigit, b->lastDigit) + 1;
//	carry = 0;
//	
//	for (i = 0; i <= c->lastDigit; i++)
//	{
//		c->digits[i] = (char)(carry + a->digits[i] + b->digits[i]) % 10;
//		carry = (carry + a->digits[i] + b->digits[i]) / 10;
//	}
//
//	zero_justify(c);
//}
//int compare_bignum(bignum* a, bignum* b)
//{
//	if ((a->signbit == MINUS) && (b->signbit == PLUS))	return PLUS;
//	if ((a->signbit == PLUS) && (b->signbit == MINUS))	return MINUS;
//
//	if (b->lastDigit > a->lastDigit)	return PLUS * a->signbit;
//	if (a->lastDigit > b->lastDigit)	return MINUS * a->signbit;
//
//	for (int i = 0; i < a->lastDigit; i++)
//	{
//		if (a->digits[i] > b->digits[i])
//			return MINUS * a->signbit;
//		else if(a->digits[i] < b->digits[i])
//			return PLUS * a->signbit;
//	}
//
//	return 0;
//}
//void subtract_bignum(bignum*a, bignum* b, bignum* c)
//{
//	int borrow, v, i;
//
//	if ((a->signbit == MINUS) || (b->signbit == MINUS))
//	{
//		b->signbit = -1 * b->signbit;
//		add_bignum(a, b, c);
//		b->signbit = -1 * b->signbit;
//		return;
//	}
//
//	if (compare_bignum(a, b) == PLUS)
//	{
//		subtract_bignum(b, a, c);
//		c->signbit = MINUS;
//		return;
//	}
//
//	c->lastDigit = max(a->lastDigit, b->lastDigit);
//	borrow = 0;
//
//	for (int i = 0; i <= (c->lastDigit); i++)
//	{
//		v = (a->digits[i] - borrow - b->digits[i]);
//		if (a->digits[i] > 0)
//			borrow = 0;
//		if (v < 0)
//		{
//			v += 10;
//			borrow = 1;
//		}
//		c->digits[i] = (char)v%10;
//	}
//
//	zero_justify(c);
//}
//void digit_shift(bignum* a,int d)
//{
//	if ((a->lastDigit == 0) && (a->digits[0] = 0))
//		return;
//
//	for (int i = a->lastDigit; i >= 0; i--)
//	{
//		a->digits[i + d] = a->digits[i];
//	}
//
//	for (int i = 0; i < d; i++)
//	{
//		a->digits[i] = 0;
//	}
//
//	a->lastDigit += d;
//}
//void multiply_bignum(bignum* a, bignum* b, bignum* c)
//{
//	bignum row;
//	bignum tmp;
//	int i, j;
//
//	initialize_bignum(c);
//
//	row = *a;
//
//	for (i = 0; i <= b->lastDigit; i++)
//	{
//		for (j = 1; j <= b->lastDigit; j++)
//		{
//			add_bignum(c, &row, &tmp);
//			*c = tmp;	
//		}
//		digit_shift(&row, 1);
//	}
//	c->signbit = a->signbit*b->signbit;
//	zero_justify(c);
//}
//void int_to_bignum(int s, bignum* a)
//{
//	int i, t;
//
//	if (s >= 0)
//		a->signbit = PLUS;
//	else
//		a->signbit = MINUS;
//
//	for (int i = 0; i < MAX_DIGITS; i++)
//	{
//		a->digits[i] = (char)0;
//	}
//
//	a->lastDigit = -1;
//
//	t = abs(s);
//
//	while (t > 0)
//	{
//		a->lastDigit++;
//		a->digits[a->lastDigit] = (t % 10);
//		t = t / 10;
//	}
//
//	if (s == 0)	a->lastDigit = 0;
//}
//inline void stringTostring(char a[6],char num[5])
//{
//	int j = 0;
//	for (int i = 0; i < 6; i++)
//	{
//		if (a[i] != '.')
//		{
//			num[j] = a[i];
//			j++;
//		}
//	}
//	num[j] = '\0';
//}
//inline void printBigNum(bignum* n)
//{
//	if(n->signbit==MINUS)
//		printf("-");
//	for (int i = 0; i <=n->lastDigit; i++)
//		printf("%d",n->digits[i]);
//
//	printf("\n");
//}
//int main()
//{
//	char R[6];
//	//double R;
//	int n = 0;
//	while (~scanf("%s%d", &R, &n))
//	{
//		char num1[5];
//		stringTostring(R,num1);
//		int num = stoi(num1);
//		//cout << num;
//		bignum n1;
//		initialize_bignum(&n1);
//		bignum n2;
//		initialize_bignum(&n2);
//		int_to_bignum(num, &n1);
//		int_to_bignum(n, &n2);
//		bignum n3;
//		add_bignum(&n1, &n2, &n3);
//		printBigNum(&n1);
//		printBigNum(&n2);
//		//cout << n3.lastDigit;
//		printBigNum(&n3);
//	}
//	return 0;
//}