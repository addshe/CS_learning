#include"GenericProgramming.h"
using namespace std;
int main(){
    /*const elemType* find(const std::vector<elemType> &vec, const elemType &value)

    vector<string> words = {"apple", "banana", "cherry", "date"};
    const string* result = find(words, string("well"));

    if (result != nullptr){
        std::cout << "找到元素: " << *result << std::endl;
    } else {
        std::cout << "未找到元素" << std::endl;
    }
    */

    /*const elemType* find(const elemType* array, int size, const elemType &value)

    int arr[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    const int* res = find(arr, 14, 10);
    if (res != nullptr){
        std::cout << "找到元素: " << *res << std::endl;
    } else {
        std::cout << "未找到元素" << std::endl;
    }
    */

    /* const elemType* find_1(const elemType* begin, const elemType* end, const elemType &value)

    int arr[14] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    const int* res = find_1st(arr, arr+14, 10);
    if (res != nullptr){
        std::cout << "找到元素: " << *res << std::endl;
    } else {
        std::cout << "未找到元素" << std::endl;    
    }
    */

    //vector<string> svec;

    /*错误写法
    const string* res = find_1st(&svec[0], &svec[svec.size()], string(""));
    svec.size()试图访问越界元素
    应该用 &svec[0] + svec.size() 或 svec.data() + svec.size()
    */

    /*vector<string> svec

    svec.push_back("hello123");
    svec.push_back("world123");

    ps:使用vector<string>::要加std::
    vector<string>::const_iterator iter = svec.begin();
    vector<string>::const_iterator iter1 = (svec.end()-1);
    cout << *iter << endl;
    cout << "(" << iter->size() << "): " << *iter << endl;
    cout << *iter1 << endl;
    cout << "(" << iter1->size() << "): " << *iter1 << endl;
    */

    /* iterator+template
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};
    vector<int> ivec(ia, ia+asize);
    list<int> ilist(ia, ia+asize);

    int *pia = find(ia, ia+asize, 3);
    if(pia != ia+asize){
        cout << "找到元素: " << *pia << endl;
    } else {
        cout << "未找到元素" << endl;
    }
    
    vector<int>::iterator it;
    it = find(ivec.begin(), ivec.end(), 1024);
    if(it != ivec.end()){
        cout << "找到元素: " << *it << endl;
    } else {
        cout << "未找到元素" << endl;
    }

    list<int>::iterator iter;
    iter = find(ilist.begin(), ilist.end(), 5);
    if(iter != ilist.end()){
        cout << "找到元素: " << *iter << endl;
    } else {
        cout << "未找到元素" << endl;
    }
    */
   
    return 0;
}