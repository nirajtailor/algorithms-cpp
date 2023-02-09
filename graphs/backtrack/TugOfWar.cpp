#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


void tugOfWarUtil(int arr[], int n, vector<bool> &visited, vector<bool> &soln, 
	int curr, int currSum, int selected,  int sum, int &min_diff) {

	if(curr == n) return;
	
	if ((n/2 - selected) > (n-curr)) return;

// exclude current
	tugOfWarUtil(arr, n, visited, soln, curr+1, currSum, selected, sum, min_diff);

// include current 
	visited[curr] = true;
	selected++;
	currSum += arr[curr];

	if(selected == n/2) {

		if(abs(sum/2 - currSum) < min_diff) {
			min_diff = abs(sum/2 - currSum) ;

			cout<<"min_diff "<<min_diff<<endl;
			// current solution
			for(int i=0; i<n; i++) {
				soln[i] = visited[i];
			}
		}
	}
	else {
		tugOfWarUtil(arr, n, visited, soln, curr + 1, currSum, selected, sum, min_diff); // included
	}
	
	visited[curr] = false;
}


void tugOfWar(int arr[], int n) {

	vector<bool > visited(n, false);
	vector<bool > soln(n, false);
	int sum = 0;

	for( int i=0; i< n; i++) {
		sum += arr[i];
	}

	cout<<"sum : "<<sum<<endl;

	int min_diff = INF;
	tugOfWarUtil(arr, n, visited, soln, 0, 0, 0, sum, min_diff);

	for(int i=0; i<n; i++) {
		if(soln[i]) {
			cout<<" "<<arr[i];
		}
	}
}

int main() {

	int arr[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};

	int n = sizeof(arr)/sizeof(arr[0]);

	tugOfWar(arr, n);
}