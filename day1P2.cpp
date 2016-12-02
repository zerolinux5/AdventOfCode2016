#include <iostream>
#include <string.h>
#include <set>
using namespace std;

char LEFT  = 'L';
char RIGHT = 'R';

enum DIRECTION {NORTH, EAST, SOUTH, WEST};

int main ()
{
	set<pair<int,int> > visited;
	int totalx = 0;
	int totaly = 0;
	int steps;
	int walk = 0;
	char direction, comma;
	bool notHit = true;
	pair<int, int> point = make_pair(0, 0);
	DIRECTION currentDirection = NORTH;
	visited.insert(point);

	while (notHit && (cin >> direction >> steps)) {
		switch (currentDirection) {
			case NORTH:
				if (direction == LEFT) {
					currentDirection = WEST;
				}
				else {
					currentDirection = EAST;
				}
				break;
			case EAST:
				if (direction == LEFT) {
					currentDirection = NORTH;
				}
				else {
					currentDirection = SOUTH;
				}
				break;
			case WEST:
				if (direction == LEFT) {
					currentDirection = SOUTH;
				}
				else {
					currentDirection = NORTH;
				}
				break;
			case SOUTH:
				if (direction == LEFT) {
					currentDirection = EAST;
				}
				else {
					currentDirection = WEST;
				}
				break;
		}
		for (int i = 0; i < steps; i++) {
			switch (currentDirection) {
				case NORTH:
					totaly++;
					break;
				case EAST:
					totalx++;
					break;
				case WEST:
					totalx--;
					break;
				case SOUTH:
					totaly--;
				break;
			}
			point.first = totalx;
			point.second = totaly;
			if (visited.find(point) != visited.end()) {
				notHit = false;
				break;
			}
			else {
				visited.insert(point);
			}
		}

		cin.ignore(1,',');
	}

	cout << totalx << " : " << totaly << " | " << (abs(totalx) + abs(totaly));

  return 0;
 }