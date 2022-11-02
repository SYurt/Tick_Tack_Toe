#include <stdio.h>
//put marker if the cell is free
int putMarker (char board[], char marker, int m) {

	if (board[m]==markerEmpty) {
		board[m]==marker;
		return 0;	
	}
	return -1;		
}
