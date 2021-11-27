#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<unistd.h> //for limiting speed of game
#include "Header_file"
using namespace std;

int toss(){
    cout<<">>>Tossing..."<<endl;
    usleep(1200000);
    int raw=time(0)%10;
    int ret= raw<5 ? 0:1; 
    if(ret==0){cout<<">>> You won the toss!"<<endl;}
    else{cout<<">>> Jared won the toss!"<<endl;}
    return(ret);
}

void printVector(vector<int>& values){
    for(int i=0;i<values.size();i++){
        cout<<i+1<<":\t";
        for(int j=0;j<values.at(i);j++)
	        cout<<"#"<<" ";
        cout<<'\n';
    }
}

int main(){
	Game game_instance;
    string playerName;
    cout<<"Hi... Enter your name: ";
    cin>>playerName;
    usleep(1200000);
    cout<<"Jared (Computer) is your opponent :)"<<endl;
    Human player(playerName);
    Jared his_instance;
    bool finished=false;
    int turn=toss();
    usleep(1200000);
    cout<<"Game started"<<endl<<endl;
    usleep(1200000);
    while(!finished){
        vector<int> status=game_instance.getState();
        printVector(status);
        cout<<"------------------------------------"<<endl<<endl;
        if(turn==0){cout<<">>> Your turn"<<endl;usleep(900000);player.next_move(status);}
        else{cout<<">>> Jared's turn"<<endl;usleep(900000);his_instance.next_move(status);}
        finished=game_instance.updateState(status);
        turn=(turn+1)%2;
    }
    usleep(1200000);
    cout<<endl<<"\t\t\t|+++++|+++++|+++++|Game Over|+++++|++++++|++++++|"<<endl;
    usleep(1200000);
    if(turn==0){cout<<"Congrats! "<<player.get_player_name()<<", You  won!!"<<endl;}
    else{cout<<"Sorry "<<player.get_player_name()<<", Jared won!!"<<endl;}
    return(0);  
}


