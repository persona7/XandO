#include<iostream>
#include<conio.h>
using namespace std;
char num;
bool player;
char arry[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'}};
void draw() {
	system("cls");
	for (int i = 0; i < 3; i++) {
		cout << "                ";
		for (int j = 0; j < 3; j++) {
			cout << arry[i][j];
			cout << " ";
		}
		cout << endl;
	}
	if (player == false) {
		cout << "now player 1" << endl;
	}
	else {
		cout << "now player 2" << endl;
	}
}
void input() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
			if (arry[i][j] == num) {
				if (player == false) {
					arry[i][j] = 'O';
					player = true;
				}
			else {
				arry[i][j] = 'X';
				player = false;
			}
			break;
		}
	draw();

}
int theGameOver() {
	if (arry[0][0] == arry[0][1] && arry[0][1] == arry[0][2])
		return 1;
	else if (arry[1][0] == arry[1][1] && arry[1][1] == arry[1][2])
		return 1;
	else if (arry[2][0] == arry[2][1] && arry[2][1] == arry[2][2])
		return 1;
	else if (arry[0][0] == arry[1][0] && arry[1][0] == arry[2][0])
		return 1;
	else if (arry[0][1] == arry[1][1] && arry[1][1] == arry[2][1])
		return 1;
	else if (arry[0][2] == arry[1][2] && arry[1][2] == arry[2][2])
		return 1;
	else if (arry[0][0] == arry[1][1] && arry[1][1] == arry[2][2])
		return 1;
	else if (arry[0][2] == arry[1][1] && arry[1][1] == arry[2][0])
		return 1;
	else if (arry[0][0] != '1' && arry[0][1] != '2' && arry[0][2] != '3' && arry[1][0] != '4' && arry[1][1] != '5' && arry[1][2] != '6' && arry[2][0] != '7' && arry[2][1] != '8' && arry[2][2] != '9')
		return 0;
	else
		return 2;
}

int main() {
	draw();
	while (1) {
		if (_kbhit()) {
			num = _getch();
			input();
			if (theGameOver() == 1 || theGameOver() == 0 )
				break;
		}

	}
	draw();
	if (theGameOver() == 0) {
		cout << "the gameover";
	}
		else if(player == true) {
		cout << "*****the winner player 1******" << endl;
	}
	else {
		cout << "*****the winner player 2******" << endl;
	}
	cin >> num;
	
}