#include <iostream>
#include <string>
using namespace std;

const char LEFT  = 'L';
const char RIGHT = 'R';
const char UP    = 'U';
const char DOWN  = 'D';

enum STATE {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D};

char addToString(STATE currentState){
	char state;
	switch (currentState) {
		case ONE:
			state = '1';
			break;
		case TWO:
			state = '2';
			break;
		case THREE:
			state = '3';
			break;
		case FOUR:
			state = '4';
			break;
		case FIVE:
			state = '5';
			break;
		case SIX:
			state = '6';
			break;
		case SEVEN:
			state = '7';
			break;
		case EIGHT:
			state = '8';
			break;
		case NINE:
			state = '9';
			break;
		case A:
			state = 'A';
			break;
		case B:
			state = 'B';
			break;
		case C:
			state = 'C';
			break;
		case D:
			state = 'D';
			break;
	}
	return state;
}

int main()
{
	STATE currentState = FIVE;
	string password = "";
	string command;
	char token;
	getline(cin, command);

	while(command.length() > 1) {

		for(int j = 0; j < command.length(); j++) {
			token = command[j];

			switch (currentState){
				case ONE:
					switch (token) {
						case LEFT:
						case UP:
						case RIGHT:
							break;
						case DOWN:
							currentState = THREE;
							break;
					}
					break;
				case TWO:
					switch (token) {
						case UP:
						case LEFT:
							break;
						case RIGHT:
							currentState = THREE;
							break;
						case DOWN:
							currentState = SIX;
							break;
					}
					break;
				case THREE:
					switch (token) {
						case UP:
							currentState = ONE;
							break;
						case RIGHT:
							currentState = FOUR;
							break;
						case LEFT:
							currentState = TWO;
							break;
						case DOWN:
							currentState = SEVEN;
							break;
					}
					break;
				case FOUR:
					switch (token) {
						case RIGHT:
						case UP:
							break;
						case LEFT:
							currentState = THREE;
							break;
						case DOWN:
							currentState = EIGHT;
							break;
					}
					break;
				case FIVE:
					switch (token) {
						case UP:
						case LEFT:
						case DOWN:
							break;
						case RIGHT:
							currentState = SIX;
							break;
					}
					break;
				case SIX:
					switch (token) {
						case UP:
							currentState = TWO;
							break;
						case LEFT:
							currentState = FIVE;
							break;
						case RIGHT:
							currentState = SEVEN;
							break;
						case DOWN:
							currentState = A;
							break;
					}
					break;
				case SEVEN:
					switch (token) {
						case LEFT:
							currentState = SIX;
							break;
						case DOWN:
							currentState = B;
							break;
						case UP:
							currentState = THREE;
							break;
						case RIGHT:
							currentState = EIGHT;
							break;
					}
					break;
				case EIGHT:
					switch (token) {
						case DOWN:
							currentState = C;
							break;
						case UP:
							currentState = FOUR;
							break;
						case LEFT:
							currentState = SEVEN;
							break;
						case RIGHT:
							currentState = NINE;
							break;
					}
					break;
				case NINE:
					switch (token) {
						case RIGHT:
						case DOWN:
						case UP:
							break;
						case LEFT:
							currentState = EIGHT;
							break;
					}
					break;
				case A:
					switch (token) {
						case LEFT:
						case DOWN:
							break;
						case UP:
							currentState = SIX;
							break;
						case RIGHT:
							currentState = B;
							break;
					}
					break;
				case B:
					switch (token) {
						case LEFT:
							currentState = A;
							break;
						case DOWN:
							currentState = D;
							break;
						case UP:
							currentState = SEVEN;
							break;
						case RIGHT:
							currentState = C;
							break;
					}
					break;
				case C:
					switch (token) {
						case RIGHT:
						case DOWN:
							break;
						case UP:
							currentState = EIGHT;
							break;
						case LEFT:
							currentState = B;
							break;
					}
					break;
				case D:
					switch (token) {
						case RIGHT:
						case DOWN:
						case LEFT:
							break;
						case UP:
							currentState = B;
							break;
					}
					break;
			}
		}
		password.append(1, addToString(currentState));
		getline(cin, command);
	}
	cout << password << endl;

	return 0;
}