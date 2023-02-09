

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void util(string str){
	
	int i = 0;
	int j =0;

	int n = str.length();

	std::vector<int > count(26,0);
	int maxlength = 0;
	int currlength = 0;
	while(j<n){

		count[str[j] - 'a']++;
		if(count[str[j] - 'a'] > 1){

			currlength = j - i;
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
	string str = ”abcabcbb”;

	util(str);

	return 0;
}


