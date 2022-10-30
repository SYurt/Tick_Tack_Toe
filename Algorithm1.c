#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

const char markerX = 'X';
const char marker0 = '0';
const char markerEmpty = ' ';
char board[N*N];

int algorithm(char* copyboard, char marker);
int checkCellRow(char* board, char marker, int row);
int checkCellColumn(char* board, char marker, int column);
int checkCellDiagonal(char* board, char marker, int diagonal);
int randomCell(char* board);


int algorithm(char* copyboard, char marker){
    static int movescounter = 0;
    int cell;
  // for the first move
    if (!movescounter){
        //cell = N*(N/2)+ N/2;
        cell = randomCell(copyboard);
        movescounter++;
        return cell;
    }
    // index and coordinates of empty cell
    int rowN;
    int colN;
    // arrays store indexes of rows/columns that has been already checked
    int rows[N];
    int colms[N];
    for (int i = 0; i < N; i++){
        rows[i] = -1;
        colms[i] = -1;
    }
    int diagonal[2];  // (N-2)*2
        for (int i = 0; i < 2; i++){
        diagonal[i] = -1;
    }
    // cell to move if there is no win, but lose combination
    int possibleMove = -1;
    // if win or lose for the cell is possible
    int cellChecker;
    for(cell = 0; cell < N*N; cell++){
        if (copyboard[cell] == markerEmpty){
            rowN = cell/N;
            colN = cell%N;
            if (rows[rowN] == -1){
                cellChecker = checkCellRow(copyboard, marker, rowN);
                if (cellChecker == N-1) {
                    movescounter++;
                    return cell;
                }
                if (cellChecker == -(N-1)) possibleMove = cell;
                rows[rowN] = cellChecker;
            }
            if (colms[colN] == -1){
                cellChecker = checkCellColumn(copyboard, marker, colN);
                if (cellChecker == N-1) {
                    movescounter++;
                    return cell;
                }
                if (cellChecker == -(N-1)) possibleMove = cell;
                colms[colN] = cellChecker;
            }
            // check main diagonal
            if ((diagonal[0] == -1)&&(rowN == colN)){
                cellChecker = checkCellDiagonal(copyboard, marker, 0);
                if (cellChecker == N-1) {
                    movescounter++;
                    return cell;
                }
                if (cellChecker == -(N-1)) possibleMove = cell;
                diagonal[0] = cellChecker;
            }
            // check secondary diagonal
            if ((diagonal[1] == -1)&&(colN == N-rowN-1)){
                cellChecker = checkCellDiagonal(copyboard, marker, 1);
                if (cellChecker == N-1) {
                    movescounter++;
                    return cell;
                }
                if (cellChecker == -(N-1)) possibleMove = cell;
                diagonal[1] = cellChecker;
            }
        }
    }
    if (possibleMove != -1){
        movescounter++;
        return possibleMove;
    }
    movescounter++;
    return randomCell(copyboard);
}

int checkCellRow(char* board, char marker, int row){
    int myMarkerCounter = 0;
    int opponentMarkerCounter = 0;
    int i = row*N;
    for(int j = 0; j < N; j++){
        if(board[i + j] == marker){
           ++myMarkerCounter;
        }
        if((board[i + j] != marker)&&(board[i + j] != markerEmpty)){
           --opponentMarkerCounter;
        }
    }
    if (myMarkerCounter == N-1) return myMarkerCounter;
    if (opponentMarkerCounter == -(N-1)) return opponentMarkerCounter;
    return myMarkerCounter;
}

int checkCellColumn(char* board, char marker, int column){
    int myMarkerCounter = 0;
    int opponentMarkerCounter = 0;
    int stop = N*N;
    for(int j = 0; j < stop; j += N){
        if(board[column + j] == marker){
           ++myMarkerCounter;
        }
        if((board[column + j] != marker)&&(board[column + j] != markerEmpty)){
           --opponentMarkerCounter;
        }
    }
    if (myMarkerCounter == N-1) return myMarkerCounter;
    if (opponentMarkerCounter == -(N-1)) return opponentMarkerCounter;
    return myMarkerCounter;
}

int checkCellDiagonal(char* board, char marker, int diagonal){
    int myMarkerCounter = 0;
    int opponentMarkerCounter = 0;
    int stop;
    if (diagonal == 0){
        stop = N*N;
        for(int i = 0; i < stop; i += N+1){
            if(board[i] == marker){
                ++myMarkerCounter;
            }
            if((board[i] != marker)&&(board[i] != markerEmpty)){
                --opponentMarkerCounter;
            }
        }
    } else {
        stop = N*(N-1)+1;
        for(int i = N-1; i < stop; i += N-1){
            if(board[i] == marker){
                ++myMarkerCounter;
            }
            if((board[i] != marker)&&(board[i] != markerEmpty)){
                --opponentMarkerCounter;
            }
        }
    }
    if (myMarkerCounter == N-1) return myMarkerCounter;
    if (opponentMarkerCounter == -(N-1)) return opponentMarkerCounter;
    return myMarkerCounter;
}
// choose coordinate randomly
int randomCell(char* board){
    srand(time(NULL));
    int limit = N*N;
    int cell;
    do{
        cell = rand()%limit;
        } while (board[cell] != markerEmpty);
    return cell;
}




