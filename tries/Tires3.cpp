// trie 2 nd way

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int n = 26;

typedef struct Tnode{
	struct Tnode *child[n];
	bool isEnd;
	int freq;
	int heapIndex;
}*Tptr;

typedef struct MinHeapNode{
	struct  Tnode *ptr;
	char *word;
	int freq;
}*Hptr;

typedef struct MinHeap{
	int capacity;
	int count;
	// struct MinHeapNode *array;
	Hptr array;
}*Mptr;

/*
struct MinHeap{
	int capcity;
	int count;
	struct MinHeapNode **array;
};
	MinHeap* minHeap = new MinHeap;
	minHeap->capcity = capcity;
	minHeap->array = new Hptr[minHeap->capcity];
	for(int i=0; i< minHeap->capacity; i++){
		minHeap->array[i] = new MinHeapNode;
	}
	
	cout<<"freq : "<<minHeap->array[0]->freq<<endl;
*/

Tptr getTrieNode(){
	Tptr T = new Tnode;
		T->isEnd = false;
		T->freq = 0;
		T->heapIndex = -1;
		for( int i=0; i<n; i++){
			T->child[i] = NULL;
		}
	return T;
}
MinHeap* createMinHeap(int capacity){
	Mptr minHeap = new MinHeap;
	minHeap->capacity = capacity;
	minHeap->count = 0;
	minHeap->array = new MinHeapNode[minHeap->capacity];
	return minHeap;
}

void swap(Hptr a, Hptr b){
	Hptr temp = a;
	a = b;
	b = temp ;
}
void minHeapify(Mptr minHeap, int index){

	int left = 2*index + 1;
	int right = 2*index + 2;

	int smallest = index;
	// cout<<"i "<<minHeap->array[smallest].freq<<endl;
	// cout<<"l "<<minHeap->array[left].freq<<endl;
	if(left < minHeap->count && 
		minHeap->array[left].freq < minHeap->array[smallest].freq){
		smallest = left;
	}
	else if(right < minHeap->count && 
		minHeap->array[right].freq < minHeap->array[smallest].freq){
		smallest = right;
	}
//	update corresponding nodes in trie also
	if(smallest != index){
		cout<<"heapified "<<endl;
		// swap heap index of trie node
		minHeap->array[smallest].ptr->heapIndex = index;
		minHeap->array[index].ptr->heapIndex = smallest;
		// cout<<"before swap : "<<minHeap->array[index].freq;
		// cout<<", "<<minHeap->array[smallest].freq;
		swap(minHeap->array[smallest] , minHeap->array[index]);
		// cout<<" afer swap : "<<minHeap->array[index].freq;
		// cout<<" , "<<minHeap->array[smallest].freq<<endl;
		minHeapify(minHeap , smallest);
	}

}

void buildMinHeap(Mptr minHeap){
	int n = minHeap->count - 1;
	for(int i = (n-1)/2 ; i>=0 ; i--){
		minHeapify(minHeap , i);
	}	

}

void insertInminHeap(Tptr T, string word, Mptr minHeap){
	//1. word already present in heap
	if( T->heapIndex != -1){
		cout<<" 1st case !!"<<endl;
		minHeap->array[T->heapIndex].freq++;
		// cout<<"f : "<<minHeap->array[T->heapIndex].freq<<endl;
		minHeapify(minHeap , T->heapIndex);

	}
	// 2. word not present in heap and heap is not full
	else if (minHeap->count < minHeap->capacity){
		// cout<<"count : "<<minHeap->count;
		cout<<" 2nd case !"<<endl;

		int index = minHeap->count;
		minHeap->array[index].freq = T->freq;

		minHeap->array[index].word = new char[ word.length() + 1];
		//convert string to a char array and copy
		strcpy(minHeap->array[index].word , word.c_str());

		minHeap->array[index].ptr = T;
		T->heapIndex = index;

		minHeap->count++;
		buildMinHeap(minHeap);
		// cout<<minHeap->array[index].word<<minHeap->array[index].ptr->isEnd;
		cout<<endl;
	}
	// 3. word not present in heap and heap is full
	else if(T->freq > minHeap->array[0].freq){
		cout<<"3rd case !!"<<endl;
		// remove the index number from 0th minheap node
		minHeap->array[0].ptr->heapIndex = -1;
		// replace with new
		minHeap->array[0].ptr = T;
		minHeap->array[0].ptr->heapIndex = 0;
		minHeap->array[0].freq = T->freq;
		// delete previous allocated memory
		delete [] minHeap->array[0].word;

		minHeap->array[0].word = new char[ word.length() + 1];
		strcpy(minHeap->array[0].word , word.c_str());

		minHeapify(minHeap , 0);
	}
}

void insert(Tptr &T, string word, Mptr minHeap){
	if(T==NULL){
		T = getTrieNode();
		cout<<T->freq<<endl;
		cout<<T->isEnd<<endl;
	}
	Tptr temp = T;
	for( int i=0; i<word.length() ; i++){
		int j = word[i] - 'a' + 1;
		if(temp->child[j] == NULL){
			temp->child[j] = getTrieNode();
		}
		temp = temp->child[j];
	}
	if(temp->isEnd){
		temp->freq++;
	}
	else{
		temp->isEnd = true;
		temp->freq = 1;
	}

	insertInminHeap(temp, word, minHeap);
	
}

bool search(Tptr &T , string word){
	Tptr temp = T;
	for( int i=0; i<word.length() ; i++){
		int j = word[i] - 'a' + 1;
		if(temp->child[j] == NULL){
			return false;
		}
		
		temp = temp->child[j];
	}
	//cout<<"freq = "<<temp->freq<<endl;
	return (temp && temp->isEnd );
}

void print(Tptr T, char *word, int &k){
	if(T==NULL) return ;
	if(T->isEnd){
		// cout<<"k="<<k;
		for(int i=0 ; i<k ; i++)
			cout<<word[i];
		cout<<endl;
	}
	for(int i = 1; i<n; i++){
		if(T->child[i]){
				word[k] = 'a' + i - 1 ;
				// cout<<word[k];
				k++;
				print(T->child[i], word , k);
				k--;
			}
	}
}

void printHeap(Mptr minHeap){
	for(int i=0; i<minHeap->count ; i++){
		cout<<minHeap->array[i].word<<" : "<<minHeap->array[i].freq<<endl;
	}
}

int main(){
	Tptr root = NULL;

	string str[20] = {"aab","abbbc","baa","bccaa","bc","bca","cabb"};
	int i=0;
	
	Mptr minHeap = createMinHeap(3);

	// insert(root,"abb", minHeap);
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;
	// insert(root,"abb", minHeap);
	// insert(root,"abb", minHeap);	
	// insert(root,"abbb", minHeap);
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;
	// insert(root,"abc", minHeap);
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;
	// insert(root,"abbb", minHeap);	
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;
	// insert(root,"cabb", minHeap);
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;
	// insert(root,"cabb", minHeap);
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;
	// insert(root,"cabb", minHeap);
	// insert(root,"cabb", minHeap);
	// insert(root,"cabb", minHeap);
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;
	// insert(root,"abc", minHeap);
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;
	// insert(root,"abc", minHeap);
	// cout<<minHeap->array[0].word<<minHeap->array[0].freq<<endl;

	fstream file; 
	file.open("words.txt");
    // FILE *fp = fopen ("vector.cpp", "r");

    string word;
	while(file>>word){
		//cout<<word<<" ";
		insert(root,word,minHeap);
	}

	file.close();

	while(str[i]!="\0"){
		insert(root,str[i],minHeap);
		i++;
	}

	cout<<"Search : ? "<<search(root, "abbbc")<<endl;

	printHeap(minHeap);

	// cout<<"sorted order -> "<<endl;
	// char word[30];
	// int k = 0;
	// print(root, word, k);
	cout<<"The End !!!!";
	return 0;
}