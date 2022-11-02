
// this function will check the winnings ( return : 1- win, 0 - no win)

int checkBoard(char board[],char marker,int cell) {      	       	
// cell
//   0   1   2
//   3   4   5
//   6   7   8

//  cell 0  1 2  3 4 5   6 7 8 
// rowN  0  0 0  1 1 1   2 2 2
// colN  0  1 2  0 1 2   0 1 2

// for cheking line 
// i =   0  0 0  3 3 3   2 2 2

	int rowN = cell/N;
	int colN = cell%N;
	int countMarker = 0;
	int i = rowN*N;
	int k;
	for (k=0; k<N; k++){
		if (board[i+k]==marker){
			countMarker+1;
		}
	}
	if  (countMarker == N){
		return 1;
	}
//for cheking colum 
	int stop =N*N;         //9
	countMarker = 0;
	for (k=0;k<stop; k+=N ){
		if (board[colN+k]==marker){
			countMarker++;
		}		
	}
	if (countMarker==N){
		return 1;
	}
//for cheking diagonals
	if (rowN==colN ){
		countMarker =0 ;
		int stop = N*N;
		for (i=0;i<stop;i+=(N+1)){
			if (board[i]==marker){
				countMarker++;
			}
		}
		if (countMarker==N){
			return 1;
		}
		stop = N*N-N;
		for (i=(N-1);i<stop;i+=(N-1)){
			if (board[i]==marker){
				countMarker++;
			}
		}
		if (countMarker==N){
			return 1;
		}
		
	}

	
	return 0;
}
