#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include "Header_file"
using namespace std;


Game::Game(){
    this->state = new vector<int>();
    this->empty=0;
    this->numberOfPiles=GAME_SIZE;
    srand(time(0));
    for(int i=0;i<GAME_SIZE;i++){
        int temp=2*i + 1;
        this->state->push_back(temp);
    }
}

vector<int> Game::getState(){
    return (*(this->state));
}

bool Game::updateState(vector<int> & v){
    this->empty=0;
    int i=0;
    for(auto it : v){
        this->state->at(i++)=it;
        if(it==0){empty++;}
   }
    if(this->numberOfPiles==this->empty){return true;}
    else{return false;}
}
