#include <iostream>
#include "BRTs.h"
using namespace std;

int main ()
{
    BRTs::node n1(41,24), n2(38,14), n3(31,87), n4(12,27), n5(19,54), n6(8,25);
    BRTs::tree T;
    T.ins(n1);  T.ins(n2);  T.ins(n3); 
    T.ins(n4);  T.ins(n5);  T.ins(n6);
    T.inshow();
    T.del (n6); 
    cout << "After deletel node 6" << endl;
    T.inshow();
    T.del (n4); 
    cout << "After deletel node 4" << endl;
    T.inshow();
    T.del (n5); 
    cout << "After deletel node 5" << endl;
    T.inshow();
    T.del (n3); 
    cout << "After deletel node 3" << endl;
    T.inshow();
    T.del (n2); 
    cout << "After deletel node 2" << endl;
    T.inshow();
    T.del (n1); 
    cout << "After deletel node 1" << endl;
    T.inshow();
    return 0;
}
