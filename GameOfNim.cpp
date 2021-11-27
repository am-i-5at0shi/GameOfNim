#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Nimsum(vector<int>& values);
void MakeNim_sum_zero(vector<int>& values,int nimsum);
void print(vector<int>& values);
int main()
{
         int rows ;
         cin >> rows;
         int remaining =0 ;
         vector<int> values ;
         for(int i=0;i<rows;i++)
        	 { int temp;
        	   cin>>temp;
               values.push_back(temp);
        	   remaining = remaining + values.at(i);
        	 }
         int nimsum = Nimsum(values);
         if(nimsum == 0)
         {
        	 int r,v;
        	 print(values);
        	 while(remaining!=0) {
        	 cout<<"Enter the row number and value you want to remove..."<<'\n';
        	 cin>>r;
        	 cin>>v;
        	 if(r < 0 || r > rows || v < 0 || v > values[r-1])
        		 {
        		   cout<<"Please enter the correct row or value....";
        		    continue;
        		 }
        	 values.at(r-1) = values.at(r-1) - v;

        	 print(values);
        	 cout<<"Now its computer turn..."<<'\n';
        	 int nimsum = Nimsum(values);
        	 MakeNim_sum_zero(values,nimsum);
             print(values);
        	 remaining=0;
        	 for(int i=0;i<rows;i++)
        		remaining = remaining + values.at(i);

        	 }
        	 cout<<"Player two won!!!!";
         }
         else
         {

             int r,v,flag=-1;
        	 print(values);
        	 while(remaining!=0) {
        	 cout<<"Enter the row number and value you want to remove..."<<'\n';
        	 cin>>r>>v;
        	 if(r < 0 || r > rows || v < 0 || v > values.at(r-1))
        		 {
        		    cout<<"Please enter the correct row or value...."<<'\n';
        		    continue;
        		 }
        	 values.at(r-1) = values.at(r-1) - v;

        	 print(values);
             cout<<"Now its computer turn..."<<'\n';
        	 int nimsum = Nimsum(values);

        	 if(nimsum !=0 ) {
             flag=1;
        	 MakeNim_sum_zero(values,nimsum);
             print(values);
        	 remaining=0;
        	 for(int i=0;i<rows;i++)
        		remaining = remaining + values.at(i);

        	 }
        	 else
        	 {
        		 remaining=0;
        		 for(int i=0;i<rows;i++)
        		 {
        			 if(values.at(i)!=0)
        			 { values.at(i)=values.at(i)-1;// We can take random moves if Nimsum is zero
        			   break;
        			 }
        		 }
        		 print(values);
        		 for(int i=0;i<rows;i++)
        			 remaining = remaining + values.at(i);
        	 }
            }
        	  if(flag==1)
        	  {
        		  cout<<"Player2 won.....";
        	   }
        	  else
        	  {
        		  cout<<"Player1 won....";
        	  }
        	 }
}

int Nimsum(vector<int>& values) // Calculate the nimsum
 {
    	int nimsum=0;
    	for(int i=0;i<values.size();i++)
    		nimsum=nimsum ^ values.at(i);
        return nimsum;
}
void print(vector<int>& values) // print the piles
{
    	for(int i=0;i<values.size();i++)
    	{
    		for(int j=0;j<values.at(i);j++)
    			 cout<<"#"<<" ";
            cout<<'\n';
    	}

}
void MakeNim_sum_zero(vector<int>& values,int nimsum) // Make_sum_zero
    {
    	for(int i=31;i>=0;i--)
    	{
    		for(int j=0;j<values.size();j++)

    		{
    			if((values.at(j) & (1<<i))!=0 && (nimsum & (1<<i))!=0)
    			{
    				values.at(j) = nimsum ^ values.at(j);
    				return;
    			}
    		}
    	}
    }
