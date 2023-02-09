#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
	int temp;
	if (a < b)
	{
		temp = a;
	}
	else{
		temp = b;
	}
	if (temp < c)
	{
		return temp;
	}
	else
		return c;
}
int utilUgly(int n){

	std::vector<int> ugly;
	ugly.push_back(1);
	int multipleOf2 = 2;
	int multipleOf3 = 3;
	int multipleOf5 = 5;

	int nextUglyNum = 1;;

	int i2 = 0, i3 = 0, i5 = 0;
	for (int i = 1; i < n; ++i)
	{
		nextUglyNum = min(multipleOf2, multipleOf3, multipleOf5);
		ugly.push_back(nextUglyNum);
		if (nextUglyNum == multipleOf2)
		{
			i2++;
			multipleOf2 = ugly[i2]*2;
		}
		if (nextUglyNum == multipleOf3)
		{
			i3++;
			multipleOf3 = ugly[i3]*3;
		}
		if (nextUglyNum == multipleOf5)
		{
			i5++;
			multipleOf5 = ugly[i5]*5;
		}
		cout<<nextUglyNum<<" ";
	}

	return ugly[n-1];
}

int main(){

	int n = 150;

	utilUgly(n);

	return 0;
}