#include <iostream>

using namespace std;

int main()
{
	double v0, height = 0, g = 9.8, max = 0, maxt = 0;
	cout << "Enter Intitial V0: ";
	int t = 0;
	cin >> v0;
	cout << "Initial Velocity of Object: " << v0 << "-m/s" << endl;
	cout << "Time" << '\t' << "Height" << endl;
	while (height >= 0) {
		height = v0 * t - 0.5*g*t*t;
		max = max > height ? max : height;
		maxt = max > height ? maxt : t;
		cout << t << '\t' << (height > 0 ? height : 0) << endl;
		t++;
		if (v0 == 0)
			break;
	}
	cout << endl << "Total Time: " << t - 1 << "-seconds" << endl;
	cout << "Maximum Height: " << max << " @ " << maxt << "-seconds" << endl;
	return 0;
}
