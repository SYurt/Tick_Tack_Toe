#include <stdio.h>
#include "common.h"

//#define N 3 //in common file

//const char markerX = 'X'; //in common file
//const char marker0 ='0'; //in common file
//const char markerEmpty = ' '; //in common file


int algorithm_tar(char marker, char* board){
    int startcoordinate = (N/2)+N*(N/2);  //to start from board's center
    if ( board[startcoordinate] == markerEmpty ){
        return startcoordinate;
    }
    int countmarker; //to count own marker in line
    int countrival;//to count markers of rival in line
    int coordinate = -1; //to catch and return move
    int coordinate2 = -1;  //to catch the coordinate in line where N-1 rival's markers
    for ( int i = 0; i < N; ++i){    //horizontal
        countmarker = 0;
        countrival = 0;
        for ( int j = 0; j < N; ++j){
            if( board[N*i + j] == marker) {
                ++countmarker;
            }
            else{
                if( (board[N*i + j] != markerEmpty) ) {
                    ++countrival;
                }
                else
                    coordinate = N*i + j;
            }
            if ( (countmarker>0)&&(countrival>0))
                break;
        }
        if ( (countmarker == (N - 1))&&(coordinate !=-1) ){  //if 1 Empty and N-1 own markers in line
            return coordinate;
        }
        if ( (countrival == (N - 1))&&(coordinate !=-1) ){ //if 1 Empty and N-1 rival's markers in line
            coordinate2 = coordinate;
        }
    }
    for ( int i = 0; i < N; ++i){   //vertical
        countmarker = 0;
        countrival = 0;
        for ( int j = 0; j < N; ++j ){
            if( board[i + N*j] == marker ){
                ++countmarker;
            }
            else{
                if( (board[i + N*j] != markerEmpty) ) {
                    ++countrival;
                }
                else
                    coordinate = i + N*j;
        }
            if ( (countmarker>0)&&(countrival>0))
                break;
        }
        if ( (countmarker == (N - 1))&&(coordinate !=-1) ){
            return coordinate;
        }
        if ( (countrival == (N - 1))&&(coordinate !=-1) ){
            coordinate2 = coordinate;
        }
    }
    countmarker = 0;
    countrival = 0;
    for ( int i = 0; i < N*N ; i = i + N + 1){    //main diagonal
        if( board[i] == marker ){
            ++countmarker;
        }
        else{
            if( (board[i] != markerEmpty) ) {
               ++countrival;
            }
            else
               coordinate = i;
        }
        if ( (countmarker>0)&&(countrival>0))
            break;
        if ( (countmarker == (N - 1))&&(coordinate !=-1) ){
            return coordinate;
        }
        if ( (countrival == (N - 1))&&(coordinate !=-1) ){
            coordinate2 = coordinate;
        }
    }
    countmarker = 0;
    countrival = 0;
    for ( int i = N-1, j = 0;   j < N  ; ++j, i = i + N - 1){    //diagonal
        if( board[i] == marker ){
            ++countmarker;
            }
        else{
            if( (board[i] != markerEmpty) ) {
               ++countrival;
            }
            else
               coordinate = i;
        }
        if ( (countmarker>0)&&(countrival>0))
            break;
        if ( (countmarker == (N - 1))&&(coordinate !=-1) ){
            return coordinate;
        }
        if ( (countrival == (N - 1))&&(coordinate !=-1) ){
            coordinate2 = coordinate;
        }

    }
    if ( coordinate2 != -1){  //if there is a line where 1 Empty and N-1 rival's markers
        return coordinate2;
    }
    for (int i = 0; i < N*N; ++i){ // if previous cases didn't occur return the first Empty
        if ( board[i] == markerEmpty ){
            return coordinate;
        }
    }
    return coordinate;
}
