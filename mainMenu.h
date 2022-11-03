#ifndef MAINMENU_H
#define MAINMENU_H

// to set indexes of players algotithms
typedef struct {
    int player1;
    int player2;
}Players;

void mainMenu();
void newGame(int player1, int player2);
Players menuPlayers();
void displayRating();
void displayRules();
void about();

#endif // MAINMENU_H
