#include <stdio.h>

int checkBoard(char board[],char marker) {      	       
	int i,res;
//   0   1   2
//   3   4   5
//   6   7   8
	if (marker=='X'){
		res=1;
	}else{
		res=-1;
	}
	for (i=0; i<=8; i++) {
        if (board[i]==marker && board[i+1]==marker && board[i+2]==marker ) {   
			return res;
		} 
		i+2;
	}

	for (i=6; i<8; i++) {
      	if (board[i]==marker && board[i-3]==marker && board[i-6]==marker ) {    
				return res;
		}
	}

	if (board[0]==marker && board[4]==marker && board[8]==marker ){
		return res; 
	}
   	if (board[6]==marker && board[4]==marker && board[2]==marker ){
		return res;
	}
	
	int count=0;
	for (i=0; i<=8; i++) {
        if (board[i] != 0 ) {   
		    count ++;	
		} 
	}
	if (count ==9)	{
		return 0; 
	}
	
	return 2;
}
