#include "GenericAlgorithms.h"

using namespace std;

extern bool grow_vec(std::vector<int> &vec, int elem);
extern void Use_Filter();
extern void Use_Filter2();

bool is_elem(std::vector<int>& vec, int elem){
    //auto max_value = max_element(vec.begin(), vec.end());
    int max_value = 0;
    if(!vec.empty()){
        max_value = *max_element(vec.begin(), vec.end());
    }
    if(max_value < elem){
        return grow_vec(vec, elem);
    }
    if(max_value == elem){
        return true;
    }
    return binary_search(vec.begin(), vec.end(), elem);
}

int main(){

    /* ..........

    const std::vector<int>* fb_seq = fibon_seq(10);
    if(is_elem(*fb_seq, 210)){
        cout << "Value is in the Fibonacci sequence." << endl;
    } else {
        cout << "Value is not in the Fibonacci sequence." << endl;
    }
    */


    /* bool is_elem(std::vector<int>& vec, int elem)

    std::vector<int> vec;
    if(is_elem(vec, 8)){
        cout << "Value is in the vector." << endl;
    } else {                                                                                            
        cout << "Value is not in the vector." << endl;
    }
    */

    //Use_Filter();
    Use_Filter2();

    return 0;
}