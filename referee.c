#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include "referee.h"

//#define N 3 //in common file

//#define WIN_PLAYER1 1 //in common file
//#define WIN_PLAYER2 -1 //in common file
//#define DRAW 0 //in common file
//#define BREAK 2 //in common file

//const char markerX = 'X'; //in common file
//const char marker0 ='0'; //in common file
//const char markerEmpty = ' '; //in common file

int referee(int algorithmIndex1, int algorithmIndex2 ){

    int movesCounter = 0;
    char marker;  //who is playing now: x or 0
    char board[N*N];
    char board_copy[N*N];
    int coord;  //coordinate of moving
    int algorithmIndex;

    initializeBoard(board);

    showBoard(board);
    while ( movesCounter < N*N ){
        if ( !(movesCounter%2) ){
            marker = markerX;
            algorithmIndex = algorithmIndex1;
        }
        else{
            marker = marker0;
            algorithmIndex = algorithmIndex2;
        }

        whoMoves(marker);
        copyBoard(board, board_copy);
        Sleep(100);

        int countboner = 0;   //count faulty moves
        int put;  // result of putMarker (0 - marker put on board, -1 - wrong move)
        int attempt = 2; //how much player can do faulty moves
        do {
            coord = getMove(algorithmIndex, board_copy, marker);
            put = putMarker(board, marker, coord);
            if ( put == -1 ){
                ++countboner;
                (countboner < attempt) ? printf("Cell is occupied. Try once again!\n") : printf("You should to read rules. Buy!\n");
            }
        } while ( (put == -1) && (countboner < attempt) );
        if ( put == -1 ){
            return BREAK;                                       //error
        }
        showBoard(board);
        if (movesCounter > 2*N-3){
            if ( checkBoard(board, marker, coord) ){
                if ( marker == markerX){
                    return WIN_PLAYER1;
                }
                return WIN_PLAYER2;
            }
        }
        ++movesCounter;
    }
    return DRAW;
}


// (for test)
/*int algorithm1(char marker, char* copyboard){
    int moving;
    printf("Make your move: \n");
    scanf("%d", &moving);
    return moving;
}
*/
void whoMoves(char marker){
    printf("\n%c moves\n", marker);
}

void initializeBoard(char* board){
    for (int i = 0; i < N*N; ++i ){
        board[i] = markerEmpty ;
    }
}

void copyBoard(char* board, char* copyboard){
    for (int i = 0; i < N*N; ++i ){
        copyboard[i] = board[i];
    }
}
// (for test)
int checkBoard(char* board, char marker, int cell){   //check win
    int count;
    for ( int i = 0; i < N; ++i){    //horizontal
        count = 0;
        for ( int j = 0; j < N; ++j){
            if( board[N*i + j] != marker) {
                break;
            }
            ++count;
            if ( count == N ){
                    return 1;
                }
            }
    }
    for ( int i = 0; i < N; ++i){   //vertical
        count = 0;
        for ( int j = 0; j < N; ++j ){
            if( board[i + N*j] != marker ){
                break;
            }
            ++count;
            if ( count == N ){
                return 1;
                }
            }
    }
    count = 0;
    for ( int i = 0; i < N*N ; i = i + N + 1){    //main diagonal
        if( board[i] != marker ){
                break;
        }
        ++count;
        if ( count == N ){
            return 1;
        }
    }
    count = 0;
    for ( int i = N-1, j = 0;   j < N  ; ++j, i = i + N - 1){    //diagonal
        if( board[i] != marker ){
            break;
        }
        ++count;
        if ( count == N ){
           return 1;
        }
    }

    return 0;
}

int putMarker(char* board, char marker, int coord){
    if ( board[coord] == markerEmpty ){
        board[coord] = marker;
        return 0;
    }
    return -1;
}
// (for test)
void showBoard(char* board){     //It is for testing only. Substitute other function
    system("cls");
    for (int i = 0; i < N*N; ++i){
        if ( i%N == 0){
            printf("\n");
            printf(" ___________\n");
    }
        printf("| %c ", board[i]);
    }
    puts("");
}

// (for test)
/*int getMove( int algorithmIndex, char* copyboard, char marker ){
    switch ( algorithmIndex ){
        case 1: return algorithm1(marker, copyboard);
        case 2: return algorithm2(marker, copyboard);
        default: return algorithm1(marker, copyboard);
    }
}
*/
