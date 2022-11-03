#include <stdio.h>
#include "mainMenu.h"
#include "displayMenu.h"

//to test
void newGame(int player1, int player2){
    printf("Player1 - %d\n", player1);
    printf("Player2 - %d\n", player2);
}

//to test
Players menuPlayers(){
    Players pl;

    pl.player1 = 0;
    pl.player2 = 1;

    printf("Players are set\n");

    return pl;
}

//to test
void displayRating(){

    printf("This is rating\n");
}
//to test
void displayRules(){
    printf("These are rules\n");
}
void about(){
    printf("This is 'about'\n");
}

