#ifndef REFEREE_H
#define REFEREE_H

#define N 3
const char markerX;
const char marker0;
const char markerEmpty;


int referee(int (*playerX)(char marker, char* board_copy), int (*player0)(char marker, char* board_copy));
int playerX(char marker, char* copyboard); //(for test)
int player0(char marker, char* copyboard); //(for test)
void copyBoard(char* board, char* copyboard);
void initializeBoard(char* board);  // fill board with empties
void showBoard(char* board); //(for test)
int putMarker(char* board, char marker, int coord); //put x or 0 on board as a result of moving
int checkBoard(char* board, char marker);  // check whether win or not (for test)
void whoMoves(char marker);  //show who moves

#endif // REFEREE_H
