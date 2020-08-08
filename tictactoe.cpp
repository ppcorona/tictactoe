#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

char current_marker;
int current_player;

void drawBoard() {
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "------------\n";
	
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "------------\n";
	
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
	int row = slot / 3;
	int col;
	
	if(slot % 3 == 0) {
		row = row - 1;
		col = 2;
	}
	else {
		col = (slot % 3) - 1;
	}
	
	if(board[row][col] != 'X' && board[row][col] != 'O') {
		board[row][col] = current_marker;
		return true;
	}
	else {
		return false;
	}
}

int winner() {
	for(int i = 0; i < 3; i++) {
		//netting rows
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return current_player;
		}
		
		//netting columns
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return current_player;
		}
	}
	
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return current_player;
	}
	
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return current_player;
	}
	
	return 0;
}

//swaps the players and markers; Ex: player 1 = X, player 2 = O
void swap_player_and_marker() {
	if(current_marker == 'X') {
		current_marker = 'O';
	}
	else {
		current_marker = 'X';
	}
	
	if(current_player == 1) {
		current_player = 2;
	}	
	else {
		current_player = 1;
	}
	
}

//ror tis game
void game() {
	char marker_p1;
	cout << "player one choose thou marker(X or O): ";
	cin >> marker_p1;
	
	current_player = 1;
	current_marker = marker_p1;
	
	drawBoard();
	
	int player_won;
	
	for(int i = 0; i < 9; i++) {
		int slot;
		cout << "it's now player " << current_player << "'s turn. enter your slot: ";
		cin >> slot;
		
		if(slot < 1 || slot > 9) {
			cout << "does that look like a slot???? now retry bruh\n";
			i--;
			continue;
		}
		
		if(!placeMarker(slot)) {
			cout << "that slot is taken. retry :l\n";
			i--;
			continue;
		}
		drawBoard();
		
		player_won = winner();
		
		if(player_won == 1) {
			cout << "player 1 has won";
			break;
		}
		else if(player_won == 2) {
			cout << "player 2 has won";
			break;
		}

		
		swap_player_and_marker();
	}
	if(player_won == 0) {
		cout << "its a tie";
	}
	
}

int main() {
	game();
}










