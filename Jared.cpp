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
    			values.at(j) = nimsum ^ values.at(j);
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

int Jared::can_finish(vector<int>& stone_piles){
    int index,empty=0;
    bool one_stoned=false;
    int i=0;
    for(auto it : stone_piles){
        if(it==0){empty++;}
        else if(it==1){one_stoned=true;}
        else{index=i;}
        i++;
    }

    if((empty==stone_piles.size()-2) && one_stoned){return index;}
    else{return -1;}
}

void Jared::next_move(vector<int>& stone_piles){
    srand(time(0));
    int suggested_pile=Jared::can_finish(stone_piles);
    if(suggested_pile<0){   //Finishing move not possible in this configuration.
        int sum=Jared::nimsum(stone_piles);
        if(sum!=0){Jared::makeNim_sum_zero(stone_piles, sum);}
        else{   // random move
            bool done=false;
            while(!done){
                int index=rand()%(stone_piles.size());
                if(stone_piles[index]!=0){
                    int max=stone_piles[index];
                    int sub=1+(rand()%max);
                    stone_piles[index] = stone_piles[index] - sub;  //Move taken
                    done=true;
                }
            }

        }
    }
    else{
        stone_piles[suggested_pile]=0;
    }
}







