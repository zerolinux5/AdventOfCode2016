#include <iostream>
using namespace std;

int main()
{
	int firstSide, secondSide, thirdSide, count = 0;
	bool first, second, third;
	while (cin >> firstSide >> secondSide >> thirdSide) {
		first  = firstSide + secondSide > thirdSide;
		second = firstSide + thirdSide > secondSide;
		third  = secondSide + thirdSide > firstSide;
		if (first && second && third) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}