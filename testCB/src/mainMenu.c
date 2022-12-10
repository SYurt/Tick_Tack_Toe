#include <stdio.h>
#include <stdlib.h>
#include "mainMenu.h"
#include "displayMenu.h"
//
//typedef struct {
//    int player1;
//    int player2;
//}Players;

//void displayLogo();
//int displayMenu(char** menuItems, int len);
//void newGame(int player1, int player2);
//Players menuPlayers();
//void displayRating();
//void displayRules();
//void about();

void mainMenu(){

    int itemsN = 6;
    Players players;
    players.player1 = -1;
    players.player2 = -1;

    char* menuItems[6] = {"New Game", "Players", "Rating", "Rules", "About", "Exit"};
    int menu_item;

    displayLogo();

    while((menu_item = displayMenu(menuItems, itemsN))!= 5){

        switch(menu_item){
            case 0:
                system("cls");
                while ((players.player1 == -1)||(players.player2 == -1)){
                    players = menuPlayers(players);
                }
                newGame(players.player1, players.player2);
                break;
            case 1: system("cls"); players = menuPlayers(players); break;
            case 2: system("cls"); displayRating(); break;
            case 3: system("cls"); displayRules(); break;
            case 4: system("cls"); about(); break;
            case 5:
                system("cls");
                int ans;
                puts("Do you want to quit the game?\n");
                puts("1- Yes, 0 - No\n");
                scanf("%d", &ans);
                if (ans == 1) return;
                break;
            default:
                system("cls");
                puts("Incorrect choice\n");

        }
    }
}


