#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
#include <iterator>
#include <set>
#include <iostream>
#include "algoritm.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		unsigned __int64 oll_mask = 0;
		oll_mask = (oll_mask | atoi(argv[1]));
		oll_mask = (oll_mask << 32);
		oll_mask = (oll_mask | atoi(argv[2]));

		if ((oll_mask < 0)) {
			cout << "Incorrect arguments!\n" << endl;
		}

		else
		{
			if (algoritm(oll_mask) != 0)
			{
				cout << "key is not found!";
			}
		}
	}
	else
	{
		cout << "Wrong quantity of arguments!\n" << endl;
	}
	cout << "Complete\n";
	std::system("pause");
	return 0;

}