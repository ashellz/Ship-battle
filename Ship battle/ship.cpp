#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;

void the_game();
void shooting(int* player, int* bot, int shoot, int& player_shots);
void enemy(int* player, int& bot_shots);

int main() {
	int choose;

	cout << "This is a Ship Battle game!\nType 1 to start or 0 to exit." << endl;
	cin>>choose;

	switch (choose)
	{
	case 0:
		break;
	
	case 1:
		the_game();
		break;

	default:
		cout << "That is not a valid option!" << endl;
		break;
	}
}

void the_game() {
	int player[3] = { };
	int bot[3] = { };

	srand(time(NULL));

	for (int pos = 0; pos < 3; pos++) {

		bot[pos] = (rand() % 9 + 1);
		
	}

	int place, shoot;
	int player_shots = 0;
	int bot_shots = 0;
	int count=0;
	int counting=0;

	cout << "Where do you want to place your 3 little boats?" << endl;
	cout << "1 2 3\n4 5 6\n7 8 9" << endl;
	while (count <= 2) {
		cin >> place;
		player[count] = place;
		count += 1;
	}

	cout << "You have placed your boats on:" << endl;
	for (int i = 1; i <= 9; i++) {

		for (int j = 0; j < 3; j++) {
			if (player[j] == i) {
				cout << "B ";
				break;
			}
			else {
				counting += 1;
				if (counting == 3) {
					cout << i << " "; break;
				}
			}
		}
		counting = 0;

		if(i % 3 == 0) { cout << endl; }
	}

	cout << "Your enemy is now preparing his boats..."<<endl;
	Sleep(2000);
	cout <<"one of it: " << bot[0] << endl;
	cout << "one of it: " << bot[1] << endl;
	cout << "one of it: " << bot[2] << endl;

	while (player_shots < 3 && bot_shots < 3) {
		cout << "Your turn! Shoot your cannons to one of the 9 positions: ";
		cin >> shoot;

		shooting(player, bot, shoot, player_shots);
		if (player_shots == 3) { break; }
		enemy(player, bot_shots);
	}

b:	if (player_shots == 3) {
		cout << "CONGRATS! You have won the game!!!";
	}
	else {
		cout << "The enemy has sunk all of your ships, sorry to tell you but you have lost...";
	}
	

}

void shooting(int* player, int* bot, int shoot, int& player_shots) {

	for (int i = 0; i < 3; i++) {
		if (bot[i] == shoot) {
			cout << "You have shot one of the enemies boats!" << endl;
			player_shots++;
		}
		else if (i%2==0) {
			cout << "The enemy didn't have a ship on the position " << shoot <<endl;
		}
	}
}

void enemy(int* player, int& bot_shots) {
	cout << "The enemy is shooting..." << endl;
	Sleep(2000);
	int count = 0;
	int list[8] = { };

a:	int number = (rand() % 9 + 1);

	cout << "Random number is " << number << endl;
	
	for (int j = 0; j < 10; j++) {
		if (list[j] == number) {
			goto a;
		}
	}
	count++;



	for (int i = 0; i < 3; i++) {

		if (player[i] == number) {
			cout << "Enemy has got one of your boats, precisely, the boat on the " << number << " position" << endl;;
			bot_shots++;
		}
		else if (i % 2 == 0) {
			cout << "The enemy bombed a position " << number << " but you had no boats placed there." << endl;
		}
	}

}