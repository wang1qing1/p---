#define _CRT_SECURE_NetO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int* add(int* arr, int ret, int a,int* num)
{
	int count = 1;
	int A = a;
	while (A)
	{
		A /= 10;
		count++;
	}
	int tmp = count > ret ? count : ret;
	int* array = (int*)malloc(sizeof(int) * (tmp+1));
	int arraysize = 0;
	int arrsize = ret - 1;
	int nextnum = 0;
	while (tmp--)
	{
		int b = 0;
		if (arrsize >= 0)
		{
			b = arr[arrsize];
			arrsize--;
		}
		int doo = b + a % 10 + nextnum;
		a /= 10;
		if (doo > 9)
		{
			doo = doo - 10;
			nextnum = 1;
		}
		else
		{
			nextnum = 0;
		}
		array[arraysize] = doo;
		arraysize++;
	}
	if (nextnum == 1)
	{
		array[arraysize] = 1;
		arraysize++;
	}
	int lift = 0;
	int right = arraysize - 1;
	while (lift < right)
	{
		int waa = array[lift];
		array[lift] = array[right];
		array[right] = waa;
		lift++;
		right--;
	}
	*num = arraysize;
	return array;

}
int main()
{
	int arr[] = { 1,3,4,5 };
	int a = 456;
	int num = 0;
	int ret = sizeof(arr) / sizeof(int);
	int* p = add(arr, ret, a, &num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", p[i]);
	}
	return 0;
}