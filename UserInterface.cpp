#include<iostream>
#include<bits/stdc++.h>
#include "Header_file"
using namespace std;


void UserInterface::take_input(){
    bool done=false;
    while(!done) {
        cout<<"Enter the pile-number and number of Stone(s) you want to remove..."<<'\n';
        cin>>UserInterface::row;
	    cin>>UserInterface::num;
        if(UserInterface::row < 0 || UserInterface::row > GAME_SIZE ||
                                    UserInterface::num< 0 || UserInterface::num > curr[UserInterface::row-1]){
        	cout<<"[FAILED] Please Enter possible move: ";
        	continue;
        }
        else{done=true;}
    }
}

void UserInterface::next_move(vector<int> &v){
    UserInterface::curr=v;
    UserInterface::take_input();
    v.at(row-1) -= UserInterface::num;
    return;
}
