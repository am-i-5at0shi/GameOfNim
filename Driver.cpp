#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>
#include "Header_file"
using namespace std;

int toss(){
    srand(time(0));
    int temp=rand()%2;
    return(temp);
}

void printVector(vector<int>& values){
    for(int i=0;i<values.size();i++){
        for(int j=0;j<values.at(i);j++)
	        cout<<"#"<<" ";
        cout<<'\n';
    }
}

int main(){
	Game game_instance;
    UserInterface player;
    Jared his_instance;
    bool finished=false;
    int turn=toss();
    while(!finished){
        vector<int> status=game_instance.getState();
        printVector(status);
        if(turn==0){player.next_move(status);}
        else{his_instance.next_move(status);}
        finished=game_instance.updateState(status);
        toss=(toss+1)%2;
    }

     
        
}


