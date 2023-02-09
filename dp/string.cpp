#include<iostream>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(int argc, char const *argv[])
{
	
	string str = "Hello My name is sweta"
	int i=0, j=0;
	int n = str.length();

	while(j<n){

		if ( str[j] == ' ')
		{
			swap(str[i], str[j]);
			j++;
			i++;
		}
		else{
			j++;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}