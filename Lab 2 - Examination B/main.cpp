#include <iostream>
#include "List.hpp"

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	List<int> l;

	l.insertLast(5);
	l.insertLast(52);
	l.insertLast(53);
	l.insertLast(51);
	// 51 53 52 5
	for (int i = 0; i < l.size(); i++) {
		cout << l.removeLast() << " ";
	}
	return 0;
}