#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include "referee.h"

//#define N 3
const char markerX = 'X';
const char marker0 ='0';
const char markerEmpty = ' ';


int referee(int (*playerX)(char marker, char* board_copy), int (*player0)(char marker, char* board_copy) ){
    int movesCounter = 0;
    char marker;  //who is playing now: x or 0
    char board[N*N];
    char board_copy[N*N];
    int coord;  //coordinate of moving

    initializeBoard(board);
    int (*player)(char, char*);

    showBoard(board);
    while ( movesCounter < N*N ){
        //showBoard(board);
        if ((movesCounter%2) == 0){
            marker = markerX;
        }
        else
            marker = marker0;

        whoMoves(marker);
        copyBoard(board, board_copy);
        Sleep(100);
        if (marker == markerX){
            player = playerX;
        }
        else
           player = player0;
        int countboner = 0;   //count faulty moves
        int put;  // result of putMarker (0 - marker put on board, -1 - wrong move)
        int attempt = 2; //how much player can do faulty moves
        do {
            coord = player(marker, board_copy);
            put = putMarker(board, marker, coord);
            if ( put == -1 ){
                ++countboner;
                (countboner < attempt) ? printf("Cell is occupied. Try once again!\n") : printf("You should to read rules. Buy!\n");
            }
        } while ( (put == -1) && (countboner < attempt) );
        if ( put == -1 ){
            return 2;                                       //error
        }
        showBoard(board);
        if (movesCounter > 2*N-3){
            if ( checkBoard(board, marker) ){
                if ( marker == markerX){
                    return 1;
                }
                return -1;
            }
        }
        ++movesCounter;
    }
    return 0;   //draw
}

// (for test)
int playerX(char marker, char* copyboard){
    int moving;
    printf("Make your move: ");
    scanf("%d", &moving);
    return moving;
}
// (for test)
int player0(char marker, char* copyboard){
   int moving; //= 0;
    do{
        srand(time(NULL));
        moving = rand()%9;
        if ( copyboard[moving] == ' ' ){
            return moving;
        }
    }while(1);
    /*for (int i = 0 ; i < N*N; ++i)
        if (copyboard[i] == markerEmpty){
            return i;
    }
    return moving;  */
}

void whoMoves(char marker){
    printf("\n%c moves\n", marker);
}

void initializeBoard(char* board){
    for (int i = 0; i < N*N; ++i ){
        board[i] = markerEmpty ;                         //markerEmpty
    }
}

void copyBoard(char* board, char* copyboard){
    for (int i = 0; i < N*N; ++i ){
        copyboard[i] = board[i];
    }
}
// (for test)
int checkBoard(char* board, char marker){   //check win
    int count;
    for ( int i = 0; i < N; ++i){    //horizontal
        count = 0;
        for ( int j = 0; j < N; ++j){
            if( board[N*i + j] == marker) {
                ++count;
                if ( count == N ){
                    return 1;
                }
            }
            else
                break;
        }
    }
    for ( int i = 0; i < N; ++i){   //vertical
        count = 0;
        for ( int j = 0; j < N; ++j ){
            if( board[i + N*j] == marker ){
                ++count;
                if ( count == N ){
                    return 1;
                }
            }
            else
                break;
        }
    }
    count = 0;
    for ( int i = 0; i < N*N ; i = i + N + 1){    //main diagonal
        if( board[i] == marker ){
            ++count;
            if ( count == N ){
                return 1;
            }
        }
        else
            break;
        }
    count = 0;
    for ( int i = N-1, j = 0;   j < N  ; ++j, i = i + N - 1){    //diagonal
        if( board[i] == marker ){
            ++count;
            if ( count == N ){
                return 1;
            }
        }
        else
            break;
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
