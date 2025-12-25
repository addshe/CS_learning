#include <iostream>
using namespace std;
int main()
{
    int* pi = new int(1024);
    cout << pi[1];
    delete [] pi;
    return 0;
}