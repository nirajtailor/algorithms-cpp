#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


// ceil of str[i] in the right
int findCeilIndex(string str, char first , int l){

	int ceilIndex = l;   // this is default one
	for (int i = l+1; i < str.size(); ++i)
	{
		if (str[i] > first && str[i] < str[ceilIndex])
		{
			ceilIndex = i;
		}
	}
	return ceilIndex;
}

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}
void permutation(string str){

	int size = str.size();

	sort(str.begin(), str.end());
	int i = 0;
	while(true) {
		cout<<str<<endl;
		// find right most char which is smaller its next char like aabc --> bc
		for (i= str.size()-2; i>=0; --i)
		{
			if (str[i] < str[i+1])
				break;
		}
		// when string is got reversed completely ( no such char found )
		if (i == -1)
			break;
		// find the ceil index
		int ceil = findCeilIndex(str, str[i], i+1);
		swap(&str[i], &str[ceil]);
		// sort the string in right of first 
		sort(str.begin()+i+1 , str.end());
	}
}

void permute(string a , int l, int r){
	if ( l == r)
	{
		cout<<a<<endl;
		return; 
	}
	for (int i = l; i <= r; ++i)
	{
		// swap
		swap(a[i] , a[l]);
		// recurr call for l+1
		permute(a, l+1, r);
		// back track
		swap(a[i], a[l]);
	}
}

void permuteSTL(string str)
{
    // Sort the string in lexicographically
    // ascending order
    sort(str.begin(), str.end());
 
    // Keep printing next permutation while there
    // is next permutation
    do {
       cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

int main(int argc, char const *argv[])
{
	string str = "ABCA";

	permutation(str);
	cout<<"without duplicate --> \n";
	permute("ABC" , 0, 2);
	cout<<"without duplicate using stl --> \n";
	permuteSTL("AABC");
	return 0;
}