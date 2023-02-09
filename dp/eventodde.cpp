#include<iostream>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(int argc, char const *argv[])
{
	
	// int arr[] = {2,5,3,4,8,9};
	int arr[] = {3,5,7,9,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i=0, j=0;

	while(j<n){

		if ( arr[j]%2 == 0)
		{
			swap(arr[i], arr[j]);
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