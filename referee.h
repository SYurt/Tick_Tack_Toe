#ifndef REFEREE_H
#define REFEREE_H

#define N 3  //in common file
const char markerX;
const char marker0;
const char markerEmpty;

/* function referee accept two arguments: indexes that points on algorithms will be playing
    referee initializes and shows board, checks moves, passes the turn from one player to another,
    put marker on board
    return game outcome: WIN_PLAYER1: 1,  WIN_PLAYER2: -1, DRAW: 0, BREAK: 2 */
int referee(int algorithmIndex1, int algorithmIndex2);
int algorithm1(char marker, char* copyboard); //(for test)
int algorithm2(char marker, char* copyboard); //(for test)
void copyBoard(char* board, char* copyboard);
void initializeBoard(char* board);  // fill board with empties
void showBoard(char* board); //(for test)
int putMarker(char* board, char marker, int coord); //put x or 0 on board as a result of moving
int checkBoard(char* board, char marker);  // check whether win or not (for test)
void whoMoves(char marker);  //show who moves
int getMove( int algorithmIndex, char* copyboard, char marker ); //(in common file,for test)

#endif // REFEREE_H
