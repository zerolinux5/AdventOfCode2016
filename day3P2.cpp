#include <iostream>
using namespace std;

const int SECOND = 3;
const int THIRD  = 6;
const int TRIANGLESIZE = 9;

int threeTriangles[TRIANGLESIZE];

int getSides(){
	int result;
	for (int i = 0; i < TRIANGLESIZE; i++) {
		result = (cin >> threeTriangles[i]);
	}
	return result;
}

bool isTriangle(int startPoint){
	bool result = true;
	int secondPoint = startPoint + SECOND;
	int thirdPoint  = startPoint + THIRD;
	result &= (threeTriangles[startPoint] + threeTriangles[secondPoint] > threeTriangles[thirdPoint]);
	result &= (threeTriangles[startPoint] + threeTriangles[thirdPoint] > threeTriangles[secondPoint]);
	result &= (threeTriangles[thirdPoint] + threeTriangles[secondPoint] > threeTriangles[startPoint]);

	return result;
}

int main()
{
	int count = 0;
	bool first, second, third;
	while (getSides()) {
		if (isTriangle(0)) {
			count++;
		}
		if (isTriangle(1)) {
			count++;
		}
		if (isTriangle(2)) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}