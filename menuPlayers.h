
struct Players menuPlayers(){
	struct Players integer;
	char* gameItems[2]=["Human","Algorinms"]
	int option=displayMenu(gameItems,2);
	if (option ==0){
		integer.player1 =0;
	}else{
		printf("Choose algoritm:")
		option = displayMenu(Algoritms,N);
		integer.player1 = option+1; // player2, option+1, because 0 human (в одному масиві будуть)
	}
	return integer;
}

