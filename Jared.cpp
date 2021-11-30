#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include "Header_file"
using namespace std;


void Jared::makeNim_sum_zero(vector<int>& values,int nimsum){
    for(int i=31;i>=0;i--){
    	for(int j=0;j<values.size();j++){
    		if((values.at(j) & (1<<i))!=0 && (nimsum & (1<<i))!=0){
                int temp=values.at(j);
    			values.at(j) = nimsum ^ values.at(j);
                cout<<"Jared's move:\t row="<<j+1<<" num="<<temp-values.at(j)<<endl;
    			return;
    		}
    	}
    }
}

int Jared::nimsum(vector<int>& values){
    int nimsum=0;
    for(int i=0;i<values.size();i++)
        {nimsum=nimsum ^ values.at(i);}
    return nimsum;
}

bool Jared::win_move(vector<int>& stone_piles){
    int index,more_stone;
    int one_stoned=false;
    int i=0;
    for(auto it : stone_piles){
        if(it==1){one_stoned++;}
        else if(it>1){index=i;more_stone++;}
        i++;
    }

    if(more_stone==1){
        int temp=stone_piles[index];
        if(one_stoned%2==0){
            stone_piles[index]=1;
            cout<<"Jared's move:\t row="<<index+1<<" num="<<temp-1<<endl;
        }
        else{
            stone_piles[index]=0;
            cout<<"Jared's move:\t row="<<index+1<<" num="<<temp<<endl;
            }
        return true;
    }
    else{return false;}
}

void Jared::next_move(vector<int>& stone_piles){
    if(!Jared::win_move(stone_piles)){   //achieving winning config is not possible in this configuration.
        int sum=Jared::nimsum(stone_piles);
        if(sum!=0){Jared::makeNim_sum_zero(stone_piles, sum);}
        else{   // random move
            bool done=false;
            srand(time(0));
            while(!done){
                int index=rand()%(stone_piles.size());
                if(stone_piles[index]!=0){
                    int max=stone_piles[index];
                    int sub=1+(rand()%max);
                    cout<<"Jared's move:\t row="<<index+1<<" num="<<sub<<endl;
                    stone_piles[index] = stone_piles[index] - sub;  //Move taken
                    done=true;
                }
            }

        }
    }

}







