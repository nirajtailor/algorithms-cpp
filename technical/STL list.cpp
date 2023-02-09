// C++ code to demonstrate the working of 
// merge() and remove_if()
#include<iostream>
#include<iterator>
#include<list> // for list functions
#include <bits/stdc++.h> 
using namespace std;
int main()
{
    // Initializing list1
    list<int> gqlist1 = {1, 2, 3};
     list<int> :: iterator it1, it2 ;
     for(int i= 1; i<=5 ;i ++ )
     	gqlist1.push_back(i*10) ;//gqlist1.emplace_back(i*10);
     
    // Initializing list2
    list<int> gqlist2 ; //= {2, 4, 6};
     for(int i= 1; i<=5 ;i++ )
     	gqlist2.push_back(i*20) ; //gqlist2.emplace_back(i*10);
     	
     cout << "list1 is : ";
    for (it1 = gqlist1.begin() ; it1 != gqlist1.end() ; it1++) cout << *it1 << " ";
    cout << endl;
    cout << "list2 is : ";
    for (it2 = gqlist2.begin() ; it2 != gqlist2.end() ; it2++) cout << *it2 << " ";
    cout << endl;
    
    // using merge() to merge list1 with list2
    gqlist1.merge(gqlist2);
     
    // Displaying list elements 
    cout << "list1 after merge operation is : ";
    for (it1 = gqlist1.begin() ; it1 != gqlist1.end() ; it1++) cout << *it1 << " ";
    cout << endl;
    cout << "list2 after merge operation is : ";
    for (it2 = gqlist2.begin() ; it2 != gqlist2.end() ; it2++) cout << *it2 << " ";
    cout << endl;
     
    gqlist1.swap(gqlist2);
    
	cout << "list1 after swap operation is : ";
    for (it1 = gqlist1.begin() ; it1 != gqlist1.end() ; it1++) cout << *it1 << " ";
    cout << endl;
    cout << "list2 after swap operation is : ";
    for (it2 = gqlist2.begin() ; it2 != gqlist2.end() ; it2++) cout << *it2 << " ";
    cout << endl;
    return 0;
     
}

