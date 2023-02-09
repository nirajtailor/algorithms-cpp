// array = [345, 76, 9,98, 87,213]

// output -> 9988776345213

// 9 98 87 76 345 213


// 8 89

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
	
	string temp1 = a + b;
	string temp2 = b + a;

	if(temp1>temp2){ return true;}
	else return false;
}


int main()
{
	string arr[] = {"345", "76", "9" ,"98", "87", "213"};

	sort(arr, arr + 6, compare);

	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<endl;
		
	}

	return 0;
}