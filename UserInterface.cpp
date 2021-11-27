#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include "Header_file"
using namespace std;

Human::Human(string name){
    this->name=name;
}
string Human::get_player_name(){return this->name;}
void Human::take_input(){
    bool done=false;
    while(!done) {
        cout<<"Enter the pile-number and number of Stone(s) you want to remove..."<<'\n';
        cin>>Human::row;
	    cin>>Human::num;
        if(Human::row < 0 || Human::row > GAME_SIZE ||
                                    Human::num< 0 || Human::num > curr[Human::row-1]){
        	cout<<"[FAILED] Please Enter possible move: ";
        	continue;
        }
        else{done=true;}
    }
}

void Human::next_move(vector<int> &v){
    Human::curr=v;
    Human::take_input();
    v.at(row-1) -= Human::num;
    return;
}
