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
lptr getTail(lptr head){
	if(head == NULL) return NULL;
	while(head->next){
		head = head->next;
	}
	return head;
}

void addAtEnd(lptr &head, lptr &tail,int key){
	if(head == NULL){
		head = new Lnode;
		head->val = key;
		head->next = NULL;
		tail = head;
		return ;
	}
	if(tail == NULL) 
		tail = getTail(head);

	tail->next = new Lnode;
	tail = tail->next;
	tail->val = key;
	tail->next = NULL;

}

lptr partition(lptr &head, lptr &tail){
	lptr pivot = tail;
	lptr curr = head;
	lptr newHead = NULL;
	lptr prevCurr = NULL;
	while(curr != pivot){
		if(curr->val <= pivot->val){
			if(newHead==NULL)
				newHead = curr;
			prevCurr = curr;
			curr = curr->next;
		}
		else{
			lptr temp = curr;
			curr = curr->next;
			temp->next = NULL;
			tail->next = temp;
			tail = tail->next;
			if(prevCurr)
				prevCurr->next = curr;
		}
	}

	if(newHead==NULL)
		newHead = curr;
	if(prevCurr)
		prevCurr->next = NULL;
	head = newHead;
	return pivot;
}

lptr quickSort(lptr &head,lptr &tail){
	//lptr tail = getTail(head);

	if(head==NULL || head->next == NULL) return head;

	lptr pivot = partition(head, tail);

	print(head);
	cout<<"head: "<<head->val;
	cout<<" pivot: "<<pivot->val;
	cout<<" tail: "<<tail->val<<endl;
	print(pivot);

	if(head!=pivot){
		lptr tmp = getTail(head);
		head = quickSort(head,tmp);

		getTail(head)->next = pivot;
	}
	pivot->next = quickSort(pivot->next,tail);

	return head;
}

int main(int argc, char const *argv[])
{
	int arr[] = {100,20,13,40,50,30};
	int i = 0;
	int n = sizeof(arr)/sizeof(arr[0]);
	lptr head = NULL;
	lptr tail = NULL;
	while(i<n){
		addAtEnd(head,tail,arr[i++]);
		// insert(head,arr[i++]);
		// cout<<"head of the list : "<<head->val<<endl;
		// cout<<"tail of the list : "<<tail->val<<endl;
	}
	quickSort(head,tail);
	cout<<"\nSorted list"<<endl;
	print(head);
	return 0;
}