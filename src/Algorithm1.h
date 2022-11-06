#ifndef ALGORITHM1_H
#define ALGORITHM1_H

int algorithm1(char* copyboard, char marker);
int checkCellRow(char* board, char marker, int row);
int checkCellColumn(char* board, char marker, int column);
int checkCellDiagonal(char* board, char marker, int diagonal);
int randomCell(char* board);

#endif // ALGORITHM1_H
