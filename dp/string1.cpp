
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


void util(string str){
	
	

	int n = str.length();

	int count[26];

	for (int i = 0; i < 26; ++i)
	{
		count[i] = 0;
	}

	int maxlength = 0;
	int currlength = 0;
	int i=0;
	int j =0;
	while(j<n){

		cout<<str[j]<<" ";
		
		count[str[j] - 'a']++;

		if(count[str[j] - 'a'] > 1){

			currlength = j - i;
			count[str[i] - 'a']--;
			i++;
		}
		else{
			j++;
		}

		if (currlength > maxlength)
		{
			maxlength = currlength;
		}

	}

	cout<<maxlength<<endl;
	
}


int main(int argc, char const *argv[])
{
	string str = "abcabcbb";

	util(str);

	return 0;
}


