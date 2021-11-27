#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include "Header_file"
using namespace std;

class Game{
    private:
        vector<int> * state;
        int empty=0;
        int numberOfPiles=5;
    public:
        Game(){
            this->state = new vector<int>();
            this->empty=0;
            this->numberOfPiles=5;
            srand(time(0));
            for(int i=0;i<5;i++){
                int temp=1+(i-1)*2;
                this->state->push_back(temp);
                this->empty=0;
                this->numberOfPiles=GAME_SIZE;
            }
        }

        vector<int> getState(){
            return (*(this->state));
        }
        bool updateState(vector<int> & v){
            int i=0;
            for(auto it : v){
                this->state->at(i++)=it;
                if(it==0){empty++;}
            }
            if(this->numberOfPiles==this->empty){return true;}
            else{return false;}

        }
        

};
