#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    

    /*
        [OuterVar捕获变量](int x, int y参数列表) -> int返回类型 {
            return OuterVar + x + y;函数主体
        }
    */

    /*lambda表达式(隐式函数) 作为排序算法的比较标准

        vector<int> vec {0, 11, 3, 19, 22, 7, 1, 5};

        auto f = [](int a, int b){
            return a < b;
        };

        cout << "before sort: ";

        for(const auto &e : vec){
            cout << e << " ";
        }

        cout << endl;

        sort(vec.begin(), vec.end(), f);

        cout << "after sort: ";

        for(const auto &e : vec){
            cout << e << " ";
        }

        cout << endl;
    */

    /*
        auto f = [](int a, int b) -> int{
            return a + b;
        };
        cout << "Lambda function result: " << f(3, 5) << endl;
    */

    /*变量捕获
        int N = 100, M = 10;
        auto g = [N, &M](int i){
            M = 20;//修改引用捕获的变量
            return N * i;
        };
        cout << g(10) << endl;
        cout << M << endl;
    */
    return 0;
}