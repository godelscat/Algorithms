//exercise 16.1-4 CLRS third edition
//suppose that we have a set of activities to schedule among a large number of 
//lecture halls, where any activity can take place in any lecture hall.
//We wish to schedule all the activities using as few lecture halls as p.
//Give an greedy-algorithms to determine which activity should use which hall
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> interal_graph ( const map<int, int>& act, int& hall_num ) {
	vector<int> hall = {0};
	vector<int> close_time = {0};
	auto p = act.begin();
	close_time[0] = p->first;
	advance(p ,1);
	for ( ; p != act.end(); ++p ) {
		bool flag = 0;
		int num = 0;
		for ( int j = 0; j < close_time.size(); ++j ) {
			if ( p->second >= close_time[j] ) {
				flag = 1;
				num = j;
				close_time[j] = p->first;
				break;
			}
		}
		if ( !flag ) {
			close_time.push_back ( p->first );
			num = close_time.size() - 1;
		}
		hall.push_back(num);
	}
	hall_num = close_time.size();
	return hall;
}
					
int main ()
{
	
	//key is end time, value is start time 
	//map sorted by key
	map<int, int> act = { {10, 6}, {9, 5}, {7, 5}, {11, 8}, {13, 2},
			      {6, 0}, {4, 1}, {5, 3}, {8, 3}, {14, 12}, {12, 8} };
	int hall_num = 0;
	vector<int> hall = interal_graph ( act, hall_num );
	cout << "after sort the activities by ending time \n";
	for ( int i = 0; i < hall.size(); ++i ) {
		cout << "activity " << i << " in lecture hall number: " << hall[i] << "\n";
	}
	cout << "total lecture halls number is : " << hall_num << "\n";
	return 0;
}	
