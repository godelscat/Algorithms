//unordered_map implemented internally using Hash Table
#include <iostream>
#include <unordered_map>
using namespace std;

int main ()
{
	unordered_map<int, int> u = { 
		{10,7}, {22,3}, {31,18},
		{4,23}, {15,17}, {28,1},
		{17,33}, {88,77}, {59,46}
	};
	auto s = u.find(22);
	if ( s != u.end() ) {
		cout << "Key found\n";
		cout << "Key " << s->first << " Value " << s->second << "\n";
	} else {
		cout << "Key NOT found! \n";
	}
	//erase: void or iterator following the last removed element
	//erase(iterator)
	u.erase(u.find(31));
	for ( auto &c : u ) {
		cout << c.first << " " << c.second << "\n";
	}
	return 0;
}
