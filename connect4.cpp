#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

char arr[7][6] = {' '};

void boardGame();
int checkwin();

void main() {
	srand(time(0));
	cout << "######### Connect 4 #########" << endl << endl;
	
	int turn=rand(), check=0, choice;
	int i[7] = {5,5,5,5,5,5,5};
	char player;
	while (check==0)
	{
		boardGame();
		if(turn%2 != 0){
			player = 'X';
			cout << "Your turn----------------------------" << endl << "Please insert column(1-7) : ";
			cin >> choice;
			cout << endl;
		}
		else {
			cout << "Computer's turn----------------------" << endl ;
			player = 'O';
			choice = rand()%7 +1;
			cout << endl;
		}

		if(choice==1 && (arr[0][i[0]]==NULL || arr[0][i[0]] == ' ') && i[0] >-1) {
			arr[0][i[0]] = player;
			i[0] -= 1;
		}
		else if(choice==2 && arr[1][i[1]]==NULL && i[1] >-1) {
			arr[1][i[1]] = player;
			i[1] -= 1;
		}
		else if(choice==3 && arr[2][i[2]]==NULL && i[2] >-1) {
			arr[2][i[2]] = player;
			i[2] -= 1;
		}
		else if(choice==4 && arr[3][i[3]]==NULL && i[3] >-1) {
			arr[3][i[3]] = player;
			i[3] -= 1;
		}
		else if(choice==5 && arr[4][i[4]]==NULL && i[4] >-1) {
			arr[4][i[4]] = player;
			i[4] -= 1;
		}
		else if(choice==6 && arr[5][i[5]]==NULL && i[5] >-1) {
			arr[5][i[5]] = player;
			i[5] -= 1;
		}
		else if(choice==7 && arr[6][i[6]]==NULL && i[6] >-1) {

			arr[6][i[6]] = player;
			i[6] -= 1;
		}
		else {
			if(turn%2 != 0) {
				cout << "Please insert again, press number 1-7 : ";
				cin >> choice;
				cout << endl;
			}
			else {
				continue;
			}
		}
		check = checkwin();
		turn++;
	}

	boardGame();
	
	if(check == 1) {
		if(turn%2 == 0) {
			cout << endl << "####### THE PLAYER WON!! #######" << endl;
		}
		else {
			cout << endl << "####### THE PLAYER LOSE!! #######" << endl;
		}
	}
	else if(check == 2) {
		cout << "######## DRAW!! #########";
	}
	cout << endl;
	system("pause");
}

void boardGame() {
	for (int i=0; i<6; i++) {
		cout << "| " << arr[0][i] << " | " << arr[1][i] << " | " << arr[2][i] << " | " << arr[3][i] << " | " << arr[4][i] << " | "<< arr[5][i] << " | " << arr[6][i] << " |" << endl;
		cout << "+---+---+---+---+---+---+---+" << endl ;
	}
	cout << endl;
}

int checkwin() {
	for(int i=5; i>-1; i--) {
		for(int j=0; j<7; j++) {
			if(arr[i][j] != NULL) {
				if(arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2] && arr[i][j+2]==arr[i][j+3]) {
					return 1;
				}
				else if(arr[i][j]==arr[i-1][j] && arr[i-1][j]==arr[i-2][j] && arr[i-2][j]==arr[i-3][j]) {
					return 1;
				}
				else if(arr[i][j]==arr[i-1][j+1] && arr[i-1][j+1]==arr[i-2][j+2] && arr[i-2][j+2]==arr[i-3][j+3]){
					return 1;
				}
				else if(arr[i][j]==arr[i-1][j-1] && arr[i-1][j-1]==arr[i-2][j-2] && arr[i-2][j-2]==arr[i-3][j-3]){
					return 1;
				}
				else {
					continue;
				}
			}	
		}
	}
	return 0;
}
