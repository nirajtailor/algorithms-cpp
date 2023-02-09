#include <iostream>
#include<algorithm>
#include<stack>

using namespace std;

void enque(stack< int > &s1, stack< int > &s2, int key){
    
        s1.push(key);
}

// s1 =[]
// s2 = [30 , 20]

int Deque(stack< int > &s1, stack < int> &s2){
    
    int ret;
    if(s1.empty() && s2.empty()){
        return -1;
    }
    
    else if(s2.size()>0){
        ret = s2.top();
        s2.pop();
    } 
    else if(s1.size()>0){

        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        ret = s1.top();
        s1.pop();
    }
    return ret;
}

void util(){
    
    std::stack<int > s1;
    stack<int> s2;
    
    enque(s1, s2, 10);
    enque(s1, s2, 20);
    enque(s1, s2, 30);
    cout<<Deque(s1,s2)<<endl;
    enque(s1, s2, 40);
    cout<<Deque(s1,s2)<<endl;
    enque(s1, s2, 50);
    cout<<Deque(s1,s2)<<endl;
    cout<<Deque(s1,s2)<<endl;
    cout<<Deque(s1,s2)<<endl;
    
}

int main()
{
    cout<<"Hello World\n";

    util();
    return 0;
}


// s1 =[]
// s2 =[70, 60, 50, ]


wh

write();

read();

u2, u2(t1), u3(t2)



data : 1
data2 : A

u2 : 3
u1

Get 200, 202 post
500 , 502
404
