#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// lps indicates longest proper prefix which is also suffix

void computeLPS(string pat, int lps[]) {
	int M = pat.size();
	int len =0 ;
	int i = 1;
	lps[0] = 0;
	// lps[i] = the longest proper prefix of pat[0..i] 
 //              which is also a suffix of pat[0..i]. 
	while(i<M){
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len !=0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		cout<<lps[i]<<" ";
	}
}

void patternSearch(string text, string pat){
	int N = text.size();
	int M = pat.size();
	cout<<N<<" "<<M<<endl;

	int lps[M];
	computeLPS(pat, lps);

	int i=0;
	int j=0;
	while(i<N){
		if (text[i] == pat[j])
		{
			i++;
			j++;
		}
		if (j == M)
		{
			cout<<"pattern found at "<<i-M<<endl;
			j = lps[j-1];
		}
		// Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
		else if(i<N && text[i] != pat[j]){
			if( j != 0){
				j = lps[j-1];
			}
			else {
				// j is 0, so it will start maching from 0th char
				i++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	patternSearch("abaacaabaabaaacabaabaabaaa", "aabaabaaa");
	return 0;
}