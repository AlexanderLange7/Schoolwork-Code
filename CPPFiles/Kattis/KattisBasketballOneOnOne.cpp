#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string game;
    cin >> game;
    int apoints = 0;
    int bpoints = 0;
    //Who scored, and how much
    //Increment
    for(int i = 0; i < game.length(); i++){
        if (game[i]=='A'){
            apoints+=(int)game[i+1];
        }else if(game[i]=='B'){
            bpoints+=(int)game[i+1];
        }else{}
    i++;
        
    }
    if(apoints > bpoints){
        cout<< 'A';
    }else{
        cout<< 'B';
    }

    return 0;
}