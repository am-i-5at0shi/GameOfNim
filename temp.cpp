#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

void print(vector<int>& values) // print the piles
{
    	for(int i=0;i<values.size();i++)
    	{
    		for(int j=0;j<values.at(i);j++)
    			 cout<<"#"<<" ";
            cout<<'\n';
    	}

}

void foo(vector<int> &v){
    for(auto &it : v){
        it=it*2;
    }
    cout<<"\n\n\n"<<endl;
    cout<<"Inside foo:"<<endl;
    print(v);
    cout<<"\n\n\n"<<endl;
    
}

class name{
    public:
        int bar(int a);
};

int name::bar(int a){
    return 2*a;
}
int main(){
    long t=time(0)%10;
    srand(t);
    name n1;
    //cout<<n1.bar(5)<<endl;
    for(int i=0;i<1;i++)
        cout<<"\t t="<<t<<endl;

    return(0);
}