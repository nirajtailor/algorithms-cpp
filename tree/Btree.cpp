 

#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int k = 1 ;

typedef
struct bdtree{
int count ;
int key[2*k+1];
struct bdtree *ptr[2*k+2];
}*bdptr;

void addkey(bdptr&T,int d);
void add(bdptr &T, int d);
void insert(bdptr&T,int d);
void rootoverflow(bdptr &T);
void overflow(bdptr &T, bdptr &q );
void left_distribution(bdptr &T, int x);
void right_distribution(bdptr &T, int x);
int find_key(bdptr &T,int d);
void delete_key(bdptr &T, int d);
void del(bdptr &T, int d);
int find_max(bdptr &T);
void node_combine(bdptr &T, int n);
void del_leaf(bdptr &T,int d);

void print(bdptr &T);

int main(){
     bdptr T= NULL ;
     int choose,d;
     cout<<"Welcome to BD_tree program!!";
     while(true){
        cout<<"\nChoose \n1 for add !\n2 for delete !\n3  for exit !\n";
        cin>>choose;
        switch(choose){
        case 1 : cout<<"Enter key for addition :";
                 cin>>d;
                 addkey(T,d);
                    break;
        case 2 : cout<<"Enter key to Delete :";
                 cin>>d;
                 d = find_key(T,d);
                 if(d == 0){
                 	cout<<"Key not found !!"<<endl;
                 	break;
                 }
                   	delete_key(T,d);
                    break;
        default : break;
        }
        cout<<"Printed in level order !";
        print(T);
        if(choose == 3) break;
     }
        cout << "thankyou !!!" << endl;
    return 0;
}
void addkey(bdptr &T,int d){
    add(T, d);
    if(T->count == 2*k+1){
            rootoverflow(T);
            cout << "-addkey" << endl;
            }
    return;
}

void add(bdptr &T, int d){
    if(T==NULL){
        T = new bdtree;
        for(int i=0; i<2*k+1; i++ )
            T->key[i] = -1;
         for(int i=0; i<2*k+2; i++)
            T->ptr[i] = NULL;
         T->key[0] = d;
         T->count = 1;
    }
    else if(T->ptr[0]){
        int i;
        for(i=0; i<2*k; i++)
            if(T->key[i]>d || T->key[i]==-1)
                break;
        add(T->ptr[i],d);
        //over flow occur
        if(T->ptr[i]->key[2*k]!=-1){
            if(i>0){
                if(T->ptr[i-1]->count < 2*k){
                    left_distribution(T,i);
                    goto esc;
                }
            }
            if(i<T->count){
                if(T->ptr[i+1]->count<2*k){
                    right_distribution(T,i);
                    goto esc;
                }
            }
                overflow(T,T->ptr[i]);
          esc : ;
        }
    }
    else
        insert(T,d);
        //cout << "-add" << endl;
}
void insert(bdptr&T,int d){
    int i;
    for(i=0; i<2*k+1; i++)
        if(T->key[i]>d || T->key[i]==-1)
            break;
    for(int j=T->count; j>i ; j--)
        T->key[j] = T->key[j-1];
    T->key[i] = d;
    T->count++;
    //cout << "-insert"<<T->count<< endl;
}
void rootoverflow(bdptr &T){
    bdptr p = new bdtree;
    p->count = 0;
    for(int i=0; i<2*k+1; i++)
        p->key[i] = -1;
    for(int i=0; i<2*k+2; i++)
        p->ptr[i] = NULL;
    p->ptr[0] = T;
    overflow(p,T);
    T = p;
   // cout << "-rootoverflow" << endl;
}
void overflow(bdptr &T, bdptr &q ){
    bdptr p = new bdtree;
    p->count = 0;
    for(int i=0; i<2*k+1; i++)
        p->key[i] = -1;
    for(int i=0; i<2*k+2; i++)
        p->ptr[i] = NULL;

    int temp = q->key[(2*k+1)/2];
    q->key[(2*k+1)/2] = -1;
    q->count--;
    for(int i=0; i<(2*k+1)/2 ; i++){
        p->key[i] = q->key[(2*k+1)/2+1+i];
        p->ptr[i] = q->ptr[(2*k+1)/2+1+i];
        q->key[(2*k+1)/2+1+i] = -1;
        q->ptr[(2*k+1)/2+1+i] = NULL;
        p->count++;
        q->count--;
    }
    if(q->ptr[2*k+1]){
        p->ptr[(2*k+1)/2] = q->ptr[2*k+1];
        q->ptr[2*k+1] = NULL;
    }
    int i=0;
    if(T->key[0]!=-1){
        for(i=0 ; i<2*k+1 ; i++)
            if(T->key[i]>temp || T->key[i]==-1)
                break;
        for(int j=T->count; j>i; j--){
            T->key[j] = T->key[j-1];
            T->ptr[j+1] = T->ptr[j];
        }
	}
    T->key[i] = temp;
    T->ptr[i+1] = p;
    T->count++;
}
void left_distribution(bdptr &T, int x){
    int i = T->ptr[x-1]->count ;  //left side
    T->ptr[x-1]->key[i] = T->key[x-1];
    T->key[x-1] = T->ptr[x]->key[0];
    T->ptr[x-1]->ptr[i+1] = T->ptr[x]->ptr[0];
    T->ptr[x-1]->count++;
    int j;
    for(j=1; j<T->ptr[x]->count; j++){
        T->ptr[x]->key[j-1] = T->ptr[x]->key[j];
        T->ptr[x]->ptr[j-1] = T->ptr[x]->ptr[j];
        }
     T->ptr[x]->ptr[j-1] = T->ptr[x]->ptr[j];
     T->ptr[x]->key[j-1] = -1;
     T->ptr[x]->ptr[j] = NULL;
     T->ptr[x]->count--;
}
void right_distribution(bdptr &T, int x){
    int i = T->ptr[x+1]->count;
    for(int j = i; j>0; j--){
        T->ptr[x+1]->key[j] = T->ptr[x+1]->key[j-1];
        T->ptr[x+1]->ptr[j+1]= T->ptr[x+1]->ptr[j];
    }
	int tmp = T->ptr[x]->count;
    T->ptr[x+1]->ptr[1] = T->ptr[x+1]->ptr[0];
    T->ptr[x+1]->ptr[0] = T->ptr[x]->ptr[tmp];
    T->ptr[x]->ptr[tmp] = NULL;
    
    T->ptr[x+1]->key[0] = T->key[x];
    T->ptr[x+1]->count++;
    T->key[x] = T->ptr[x]->key[tmp-1];
    T->ptr[x]->key[tmp-1] = -1;
    T->ptr[x]->count--;
}
int find_key(bdptr &T, int d){
	int i;
	if(T == NULL)
		return 0;
	for(i=0; i<T->count; i++)
		if(T->key[i] == d || T->key[i]>d || T->key[i]==-1)
			break;
	if(T->key[i]==d)
			return T->key[i];
	else
	return find_key(T->ptr[i],d);
		
}
void delete_key(bdptr &T, int d){
	del(T,d);
	
	if(T->count==0){
		bdptr temp = T->ptr[0];
		delete T;
		T = temp;
	}
	
}
void del(bdptr &T, int d){
	if(T==NULL)
		return ;
	else if(T->ptr[0]){
		int i;
		for(i=0; i<T->count; i++)
			if(T->key[i]>d || T->key[i]==d || T->key[i]==-1)
				break;
		if(T->key[i]==d){
			d = find_max(T->ptr[i]);
			cout<<"max : "<<d<<endl;
			T->key[i] = d;
		}
		del(T->ptr[i],d);
		if(T->ptr[i]->count < k){
			if(i>0){
				if(T->ptr[i-1]->count > k){
					right_distribution(T,i-1); //
					goto abc ;
				}
			}
			if(i<T->count){
				if(T->ptr[i+1]->count >k){
					left_distribution(T,i+1); // 
					goto abc ;
				}
			}
			if(i>0)
			node_combine(T,i-1);
			else
			node_combine(T,i);   //i = 0;
			abc : ;
		}
	}
	else 
	del_leaf(T,d);
}
int find_max(bdptr &T){
	if(T->ptr[0]==NULL)
		return T->key[T->count-1];
	else
		return find_max(T->ptr[T->count]);
}
void node_combine(bdptr &T, int n){
	bdptr R = T->ptr[n+1];
	int c1 = T->ptr[n]->count;
	int c2 = R->count;
	T->ptr[n]->key[c1] = T->key[n];
	T->ptr[n]->count++; 
	int i,j;
	for(i =n; i<T->count-1; i++){
		T->key[i] = T->key[i+1];
		T->ptr[i+1] = T->ptr[i+2];
	}
	T->key[i] = -1;
	T->ptr[i+1] = NULL;
	T->count--;
	 for(i=T->ptr[n]->count, j = 0; i<2*k, j < c2; i++, j--){
	 	T->ptr[n]->key[i] = R->key[j];
	 	T->ptr[n]->ptr[i] = R->ptr[j];
	 	T->ptr[n]->count++;
	 }
	 T->ptr[n]->ptr[i] = R->ptr[j];
}
void del_leaf(bdptr &T,int d){
	int i;
	for(i=0; i<T->count; i++)
		if(T->key[i]==d)
			break;
	for( ; i<T->count ; i++)
		T->key[i] = T->key[i+1];
		T->count--;	
}
void print(bdptr &T){
    queue<bdptr> Q;
    bdptr curr;
    Q.push(T);
    int n;
    while(!Q.empty()){
        n = Q.size();
        while(n--){
          curr  = Q.front();
          Q.pop();
          if(curr==NULL)
            break;
          for(int i=0; i<curr->count;i++){
            cout<<":"<<curr->key[i];
            if(curr->ptr[i])
                Q.push(curr->ptr[i]);
          }
          if(curr->ptr[curr->count])
            Q.push(curr->ptr[curr->count]);
          for(int i = curr->count ; i<2*k+1;i++)
            cout<<":";
          cout<<"       ";
        }
        cout<<endl;
    }
}


