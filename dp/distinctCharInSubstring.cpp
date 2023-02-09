#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

void uniqueCharInAllSubString(string str){

	int count = 0;

	set <string> items;

	for (int i = 0; i < str.length(); ++i)
	{
		set <char> unique;
		string temp = "";
		for (int j = i; j < str.length(); ++j)
		{
			temp = temp + str[j];

			unique.insert(str[j]);

			// if (items.find(temp) == items.end())
			// {
				/* code */
				items.insert(temp);
				count += unique.size();
				cout<<unique.size()<<" ";
			// }
		}
		cout<<temp;
		cout<<endl;
	}

	cout<<"\n"<<str<<" : "<<count<<endl;
}

void uniqueCharInAllSubString1(string str){

	int prevcount = 0, newcount, toalcount=0;
	vector< int > lastcount(26);
	vector< int > lastseen(26, -1);

	for (int i = 0; i < str.length(); ++i)
	{
		/* code */
		const int c = str[i] - 'a';  // ending with ith char
		const int currentcount = i - lastseen[c];

		newcount = prevcount + currentcount;
		// lastcount[c] = currentcount;
		lastseen[c] = i;
		prevcount = newcount;
		cout<<newcount<<" ";
		toalcount+=newcount;
	}

	cout<<"\n"<<str<<" : "<<toalcount<<endl;

}

int main(int argc, char const *argv[])
{
	uniqueCharInAllSubString("abca");
	uniqueCharInAllSubString("good");
	uniqueCharInAllSubString1("good");
	return 0;
}