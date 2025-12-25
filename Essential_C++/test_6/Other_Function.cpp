#include "ClassDeclaration.h"
void fill_stack(Stack &stack, istream &is){
    string str;
    while(is >> str && ! stack.full()){
        stack.push(str);
    }
    cout << "read in" << stack.size() << "elements\n";
}

int sum(const Triangular &trian){
    if(!trian.length())
        return 0;
    int val, sum = 0;
    trian.next_resert();
    while (trian.next(val))
    {
        sum += val;
    }
    return sum;
}

void use_sum(){
    Triangular tri(4);
    cout << "-- sum of ellements: " << sum(tri) << endl;
    /*
        Triangular tri1(4,3);
        cout << "-- sum of ellements: " << sum(tri1) << endl;
    */

    /*
        Triangular tri2(4,8);
        cout << "-- sum of ellements: " << sum(tri2) << endl;
    */

}

void use_copy(){
    Triangular t1(2, 3);
    cout << t1.length() << ' ' << t1.beg_pos() << endl;
    Triangular t2;
    t2.copy(t1);
    cout << t2.length() << ' ' << t2.beg_pos() << endl;
}

void use_is_elem(){
    char ch;
    bool more = true;

    while (more)
    {
        cout << "Enter value: ";
        int ival;
        cin >> ival;
        bool is_elem = Triangular::is_elem(ival);//独立使用必须事先在类中声明static
        cout << ival << (is_elem ? " is " : " is not ") << "an element in the Triangular series.\n" << "Another value?(y/n) ";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
        {
            more = false;
        }
    }
}

void IteratorClass_demon(){
    Triangular trian(1, 8);
    Triangular::Iterator it = trian.begin(), end = trian.end();
    while (it != end)
    {
        cout << *it << ' ';
        ++it;
    }
}