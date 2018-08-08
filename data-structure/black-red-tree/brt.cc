#include <iostream>
#include "BRTs.h"
using namespace std;

int main ()
{
    BRTs::node n1(23,44), n2(11,24), n3(17,87), n4(53,12), n5(32,14), n6(76,25),
            n7(18,9), n8(42,37), n9(9,10), n10(19,33);
    BRTs::tree T;
    T.ins (n1); T.ins(n2); T.ins(n3); T.ins(n4); T.ins(n5);
    T.ins (n6); T.ins(n7); T.ins(n8); T.ins(n9); T.ins(n10);
    T.inshow();
   // T.del (n2); T.del(n6); T.del(n4);
   // cout << "After deletel some nodes" << endl;
   // T.inshow();
    return 0;
}
