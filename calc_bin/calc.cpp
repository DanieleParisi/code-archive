#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

inline bool calc() {
	cout << "Operation? " << flush;
	char op;
	string n1, n2;
	cin >> op;
	if (op == 'q')
		return false;
	cout << "n1: ";
	cin >> n1;
	cout << "n2: ";
	cin >> n2;
	stringstream n;
	switch (op) {
	case '+':
		cout << static_cast<bitset<8>> (stoi(n1,0,2) + stoi(n2,0,2)) << " (" << stoi(n1,0,2) + stoi(n2,0,2) << ")" <<endl;
		break;
	case '-':
		cout << static_cast<bitset<8>> (stoi(n1,0,2) - stoi(n2,0,2)) << " (" << stoi(n1,0,2) - stoi(n2,0,2) << ")" << endl;
		break;
	default:
		cout << "!@f3";
		return false;
	}
	return true;
}
main() {
	while(true) 
		if (!calc()) break;
}
	
	
