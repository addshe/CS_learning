#include"ClassDeclaration.h"

void myendl() {cout << "---------------------------\n";}

int main(){

/*  ps: 局部对象的生命周期在离开其作用域时结束，析构顺序与创建顺序相反。全局/静态对象的生命周期持续到程序结束。

    {
        Object A;   // 1. 创建
        Object B;   // 2. 创建
        Object C;   // 3. 创建
        // ...
    }   // 离开作用域时：C析构 → B析构 → A析构

*/

    Stack s;

    s.push("hello");
    s.push("world");
    s.push("c++");
    s.push("c++");
    s.push("c++");
    cout << "Stack size: " << s.size() << endl;

    string top;
    if(s.peek(top)) {
        cout << "Top element: " << top << endl;
    }

    /* 弹出栈中所有元素

        while(!s.empty()){
        string elem;
        s.pop(elem);
        cout << "Popped: " << elem << endl;

    }
    */

    string str1("hello");
    if(s.find(str1)){
        cout << "find: " << str1 << endl;
    }else{
        cout << "find: none" << endl;
    }

    string str2("c++");
    int cnt = s.count(str2);
    cout << "cnt: " << cnt << endl;

    myendl();

    Matrix m(3, 8);
    Matrix m2(m);

    myendl();

    use_sum();

    myendl();

    use_copy();

    myendl();

    use_is_elem();

    return 0;
}