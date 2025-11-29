#include "work.h"
using namespace std;
int main() {
    //P64练习
    //法一：
    //添加const
    //const vector<int> *vec = pentagonal_seq(10);
    //display_message(*vec, "int");
    //法二：
    //直接调用函数，但是要加*
    display_message(*pentagonal_seq(10), "int");
    search(5, pentagonal_seq);
    return 0;
}