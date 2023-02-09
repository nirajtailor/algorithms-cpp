#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef
struct BT{
	char data;
	struct BT *lchild;
	struct BT *rchild;
}*bptr;

void BTcreat(bptr &T, char d){
	if(T==NULL){
		T = new BT;
		T->lchild = NULL;
		T->rchild = NULL;
		T->data = d;
	}
	cout<<"Enter left child "<<T->data<<" : ";
	cin>>d;
	if(d!= '0')
	BTcreat(T->lchild,d);
	cout<<"Enter Rchild child of "<<T->data<<" : ";
	cin>>d;
	if(d!= '0')
	BTcreat(T->rchild,d);
}
int max(int a, int b){
	if(a>b)
	return a;
	else 
	return b;
}
int hight(bptr &T){
	if(T==NULL)
	return -1;
	else
	return max(hight(T->lchild),hight(T->rchild)) + 1;
	
}
void levelprint(bptr &T){
	queue<bptr> Q;
	int h = hight(T);
	int x = 1;
	for(int i =0 ;i<h; i++)
		x = x*2;
	x = x-1;					//x for left space
	int y = x*2 + 1;			//y for middle space
	bptr curr;
	Q.push(T);
	cout<<"H"<<h<<" X"<<x<<endl;
	int n = Q.size();
	while(h>=0){
		n = Q.size();
		for(int i=0; i<x; i++)
				cout<<" ";
			
		while(n--){
			curr = Q.front();
			Q.pop();
			if(curr == NULL){
			cout<<" ";
			Q.push(NULL);
			Q.push(NULL);
			}
			else{
			cout<<curr->data;
			Q.push(curr->lchild);
			Q.push(curr->rchild);
			}
			for(int i=0; i<y; i++)
				cout<<" ";
		}
		cout<<endl<<endl;
		y = y/2;
		x =  x/2;
		
		h--;
	}
}
int main(){
	bptr T= NULL;
	cout<<"Enter root node : ";
	char root;
	cin>>root;
	BTcreat(T,root);
	levelprint(T);
	return 0;
}
