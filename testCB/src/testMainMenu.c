#include <stdio.h>
#include "mainMenu.h"
#include "displayMenu.h"
#include "PlayersAlgorithms.h"

//to test
void newGame(int player1, int player2){
    printf("Player1 - %d\n", player1);
    printf("Player2 - %d\n", player2);
}

//to test
Players menuPlayers(Players players){
    // ALGORITHMS_NUMBER      //number of algorithms in PlayersAlgorithms.h
    // presettings of players are applied if only one player to be changed
//	Players playerChoice;
//	playerChoice.player1 = players.player1;
//	playerChoice.player2 = players.player2;
	// current player that is being changed
	Players * playersPtr = &players;
	int* myplayer;
	//char answer = 1;
	int option;
	char* selectPlayer[2] = {"Player_1","Player_2"};
	char* gameItems[2] = {"Human","Algorithm"};
	char* levels[ALGORITHMS_NUMBER - 1] = {"Level_1","Level_2"};
	//puts("To confirm your choice and return to main menu enter 0");
	option = displayMenu(selectPlayer, 2);
	myplayer = (option == 0) ? (int*)playersPtr : ((int*)playersPtr + 1);
	option = displayMenu(gameItems, 2);
	if (option == 0){
		*myplayer = 0;
	}else{
		printf("Choose level:");
		option = displayMenu(levels, ALGORITHMS_NUMBER - 1);
		*myplayer = option + 1; // player-algorithm, option+1, because 0 human
	}
	return players;
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

