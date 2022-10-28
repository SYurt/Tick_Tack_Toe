#include <stdio.h>
int putMarker (char board[], char marker, int m) {

	if (board[m]==0) {
		board[m]==marker;
		return 0;	
	}
	return -1;		
}
