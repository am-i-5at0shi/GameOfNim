#include<iostream>
#include<bits/stdc++.h>
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
    name n1;
    cout<<n1.bar(5)<<endl;

    return(0);
}