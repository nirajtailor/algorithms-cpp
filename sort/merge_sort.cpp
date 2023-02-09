
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


typedef struct Lnode{
	int val;
	Lnode *next;
}*lptr;


void insert(lptr &head , int key){
	if(head == NULL){
		head = new Lnode;
		head->val = key;
		head->next = NULL;
		return ;
	}
	lptr temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = new Lnode;
	temp = temp->next;
	temp->val = key;
	temp->next = NULL;
}

// void print(lptr &head){		head will move in while loop
void print(lptr head){
	// cout<<"in function "<<&head<<endl;
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
}

void splitInTwo(lptr head ,lptr &a, lptr &b){
	lptr slow = head;
	lptr fast = head->next;

	while(fast){
		fast = fast->next;
		if(fast){
			fast = fast->next;
			slow = slow->next;
		}
	}
	a = head;
	b = slow->next ;
	slow->next = NULL;
}

lptr merge(lptr a, lptr b){
	lptr result = NULL;

	if(a==NULL) return b;
	else if(b==NULL) return a;


	if(a->val > b->val){
		result = b;
		result->next = merge(a,b->next);
	}
	else{
		result = a;
		result->next = merge(a->next,b);
	}

	return result;
	
}

void mergeSort(lptr &head){
	if(head == NULL || head->next == NULL) return;

	lptr a = NULL;
	lptr b = NULL;

	splitInTwo(head , a , b);
	// cout<<"\na : ";
	// print(a);
	// cout<<" b : ";
	// print(b);

	mergeSort(a);
	mergeSort(b);
	cout<<"\na : ";
	print(a);
	cout<<" b : ";
	print(b);

	head = merge(a,b);
	cout<<"\nhead : ";
	print(head);
}

// void print(lptr &head){
void print1(lptr &head){
	cout<<"in function start"<<&head<<" val "<<head->val<<endl;
	while(head){
		cout<<head->val<<" ";
		head = head->next;
		cout<<"in while loop "<<&(*head)<<endl;			// address of head pointer which is moving
	}
	cout<<"in function end "<<&head<<endl;
}

void pointerTest(lptr head){
	cout<<"in function head address "<<&head<<endl;
	// while(head){
	// 	cout<<head->val<<" ";
	// 	head = head->next;
	// }
}

int main(int argc, char const *argv[])
{
	int arr[] = {100,20,13,40,50,30};
	int i = 0;
	int n = sizeof(arr)/sizeof(arr[0]);
	lptr head = NULL;
	while(i<n){
		insert(head,arr[i++]);
	}
	mergeSort(head);
	cout<<"before "<<&head<<" val "<<head->val<<endl;
	print1(head);
	//cout<<"\npointer test - > "<<&head<<" value "<<head->val<<endl;
	pointerTest(head);
	return 0;
}
