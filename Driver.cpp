#include<iostream>
#include<bits/stdc++.h>
#include "Header_file"
using namespace std;



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


