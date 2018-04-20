#include "Map.h"

using namespace std;


int main()
{
	Map map;
	bool play = true;
	bool choice;
	while (play) {
		map.Play();
		cout << "You lost! Your score is " << map.GetScore() << ", Play again? y/n" << endl;
		cin >> choice;
		if (choice != 'y')
			play = false;
	}
	
	return 0;
}