#include "FunctionDeclaration.h"

using namespace std;

int main(){
/*
    long long max_int = numeric_limits<long long>::max();
    double min_dbl = numeric_limits<double>::min();
    cout  << "max: " << max_int << "\n" << "min: " << min_dbl;
*/
    int arr[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(arr, arr+8);
    ofstream ofil("data3.txt");
//冒泡排序
    cout << "vector before sort: ";
    
    display(vec);
    bubble_sort(vec, ofil);

    cout << "vector after sort: ";

    display(vec);

    cout << endl;
//斐波那契数列
    vector<int> res = *fibon_seq(10);
    display(res, ofil);

    cout << endl;

    int position = 5;
    int value = 0;
    if(seq_elem(position, value, fibon_seq)){
        cout << "Fibonacci数列中第 " << position << "个元素是: " << value << endl;
    }else{
        cout << "无法获取第 " << position << " 个fibonacci数" << endl;
    }
//模板函数使用
/*
    vector<int> q = {1,2,3,4,5};
    string q_msg("This is a test message for display_message(): ");
    display_message(q_msg, q);
    cout << endl;
    vector<string> s = {"Hello", "world", "this", "is", "C++"};
    string s_msg("This is a test message for display_message() with string vector: ");
    display_message(s_msg, s);
*/
    return 0;
}