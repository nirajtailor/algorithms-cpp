#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int global = 40;

void fun1(int *ptr){
	cout<<"&ptr in function "<<&ptr<<endl;

	ptr = &global;
	cout<<"*ptr "<<*ptr<<endl;
}

void fun2(int **ptr){
	cout<<"ptr "<<ptr<<endl;
	cout<<"&ptr in function "<<&ptr<<endl;
	cout<<"*ptr "<<*ptr<<endl;
	cout<<"**ptr "<<**ptr<<endl;
	*ptr = &global;
}

void fun3(int *&ptr){
	cout<<"ptr "<<ptr<<endl;
	cout<<"&ptr in function "<<&ptr<<endl;
	cout<<"*ptr "<<*ptr<<endl;
	int b = 50;
	ptr = &b;
}

// static int myCompare(const void* a, const void* b)
int myCompare(const char* a, const char* b)
{ 
    // setting up rules for comparison 
    // return strcmp(*(const char**)a, *(const char**)b);
    cout<<strcmp(a,b)<<endl;
    if(strcmp(a,b) < 0){
    	return 1;
    }
    else return 0;
} 
  
// Function to sort the array 
void stringsort(const char* arr[], int n) 
{ 
    // calling qsort function to sort the array 
    // with the help of Comparator
    sort(arr, arr+n, myCompare); 
    for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
} 
int main(int argc, char const *argv[])
{
	int a = 20;
	int *ptr;
	ptr = &a;

	cout<<"Passing pointer to a function"<<endl;
	cout<<"&ptr before function "<<&ptr<<endl;
	fun1(ptr);
	cout<<*ptr<<endl;

	cout<<"\n\n\n\nPassing “pointer to a pointer” as a parameter to function"<<endl;
	cout<<"&a "<<&a<<endl;
	cout<<"&ptr "<<&ptr<<endl;
	fun2(&ptr);
	cout<<"*ptr "<<*ptr<<endl;

	cout<<"\n\n\nPassing a Reference to a pointer to function"<<endl;
	cout<<"&ptr in function "<<&ptr<<endl;
	fun3(ptr);
	cout<<*ptr<<endl;

	const char *arr[] = {"const arr","abbbc","baa","bca","bc","bca","cabb"};
	cout<<arr[0]<<endl;
	cout<<sizeof(arr[0])<<endl;
	cout<<sizeof(arr)/sizeof(arr[0])<<endl;
	cout<<sizeof(arr[0][1])<<endl;
	cout<<strlen(arr[1])<<endl;
	// cout<<arr[0].length();
	// cout<<size(arr)
	stringsort(arr, sizeof(arr)/sizeof(arr[0]));
	cout<<endl;
	char arr2[][10] = {"arr2","abbbc","baa","bccaa","bc","bca","cabb"};

	cout<<arr2[0]<<endl;
	cout<<sizeof(arr2[0])<<endl;
	cout<<sizeof(arr2)/sizeof(arr2[0])<<endl;


	return 0;
}