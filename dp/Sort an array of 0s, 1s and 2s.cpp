// Sort an array of 0s, 1s and 2s
// Problem Statement: Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// [0,0,0]

// {
// 	nzeros,
// 	nones,
// 	ntwos
// }


// 	   i, 	 k
// 0 ,0, 1, 1, 2 ,2
// 	         j


#include<iostream>

using namespace std;


void util(int nums[], int n){
	int x=0, y=0, z=0;

	int i=0;
	while(i<n){
		if(nums[i] == 0){
			x++;
		}
		else if(nums[i] == 1){
			y++;
		}
		else{
			z++;
		}
		i++;
	}
	i=0;

	while(i<x){
		nums[i++] = 0;
	}
	while(i<x+y){
		nums[i++] = 1;
	}
	while(i<x+y+z){
		nums[i++] = 2;
	}

	i = 0;
	while(i<n){
		cout<<nums[i++]<<" ";
	}

}
int main(int argc, char const *argv[])
{
	int nums[] = {2,0,2,1,1,0};

	int n = sizeof(nums)/sizeof(nums[0]);

	int i=0, j=0, k=n-1;

	util(nums, n);
	// while(j != k && j < n && k>=0){

	// 	if(nums[k] == 2){
	// 		k--;
	// 	}
	// 	else if(nums[i] == 0){
	// 		i++;
	// 		j = i;
	// 	}
	// 	else if(nums[j] == 0){

	// 		swap(nums[i], nums[j]);
	// 		i++;
	// 		j++;
	// 	}
	// 	else if (nums[j] == 2)
	// 	{
	// 		swap(nums[i], nums[k]);
	// 		i++;
	// 		k--;
	// 	}
	// }





	return 0;
}

