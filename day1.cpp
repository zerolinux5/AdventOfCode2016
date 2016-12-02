#include <iostream>
#include <string.h>
using namespace std;

char LEFT  = 'L';
char RIGHT = 'R';

enum DIRECTION {NORTH, EAST, SOUTH, WEST};

int main ()
{
	int totalx = 0;
	int totaly = 0;
	int steps;
	char direction, comma;
	bool leftRight = true;
	DIRECTION currentDirection = NORTH;

	while (cin >> direction >> steps) {
		switch (currentDirection) {
			case NORTH:
				if (direction == LEFT) {
					totalx -= steps;
					currentDirection = WEST;
				}
				else {
					totalx += steps;
					currentDirection = EAST;
				}
				break;
			case EAST:
				if (direction == LEFT) {
					totaly += steps;
					currentDirection = NORTH;
				}
				else {
					totaly -= steps;
					currentDirection = SOUTH;
				}
				break;
			case WEST:
				if (direction == LEFT) {
					totaly -= steps;
					currentDirection = SOUTH;
				}
				else {
					totaly += steps;
					currentDirection = NORTH;
				}
				break;
			case SOUTH:
				if (direction == LEFT) {
					totalx += steps;
					currentDirection = EAST;
				}
				else {
					totalx -= steps;
					currentDirection = WEST;
				}
				break;
		}
		cin.ignore(1,',');
	}

	cout << totalx << ":" << totaly << "|" << (abs(totalx) + abs(totaly));

  return 0;
 }