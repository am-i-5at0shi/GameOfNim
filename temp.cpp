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
int main(){
   vector<int> * temp=new vector<int>();
   for(int i=0;i<5;i++){
       temp->push_back(i);
   }
   for(int i=0;i<5;i++){
       temp->at(i)=10+i;
   }
    for(int i=0;i<5;i++){
       cout<<temp->at(i)<<endl;
   }

    return(0);
}