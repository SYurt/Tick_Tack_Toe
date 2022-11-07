#ifndef PLAYERS_ALGORITHMS_H
#define PLAYERS_ALGORITHMS_H

//algorithm prototype name example
//int algorithm_Number(char* copyboard, char marker); // algorithms names (algorithm0 - human player algorithm, then algorithm1,.. etc.)
//algorithm returns number of the board[N*N] cell to put marker on, so to make a move
//algorith accepts copy of the board and marker of the player ('X' or 'O').

//constants and variables:
// N 3
// const char markerX = 'X';
// const char marker0 = '0';
// const char markerEmpty = ' ';
// char board[N*N];


int algorithm0(char* copyboard, char marker);
int algorithm1(char* copyboard, char marker);
int algorithm2(char* copyboard, char marker);

// function is invoked by referee to get next move

int getMove( int algorithmIndex, char* copyboard, char marker);

#endif // PLAYERS_ALGORITHMS_H
