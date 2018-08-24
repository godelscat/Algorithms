#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

unordered_map<int, int> greedy_activity_selector ( map<int, int> act ) {
	auto m  = act.begin();
	unordered_map<int, int> result;
	//resutl first is start time and second is end time
	result.insert( {m->second, m->first} );	
	//map::iterator is BidirectionalIterator
	//vector::iterator is RandomAccessIterator
	auto it = act.begin(); 
	//only RandomAccessIterator can use +n or -n
	advance(it, 1); 
	for ( ; it != act.end(); ++it ) {
		if ( it->second >= m->first ) {
			result.insert ( {it->second, it->first} );
			m = it;
		}
	}
	return result;
}

int main ()
{
	//key is end time, value is start time 
	//map sorted by key
	map<int, int> act = { {10, 6}, {9, 5}, {7, 5}, {11, 8}, {13, 2},
			      {6, 0}, {4, 1}, {5, 3}, {8, 3}, {14, 12}, {12, 8} };
	unordered_map<int, int> sub = greedy_activity_selector (act);
	for ( auto it = sub.cbegin(); it != sub.cend(); ++it ) {
		cout << "start at : " << it->first << ", and end at : " 
			<< it->second << "\n";
	}
	return 0;
}
