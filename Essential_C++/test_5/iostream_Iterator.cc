#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;

void v1(){
    
    istream_iterator<string> is(cin);
    //EOF应该用eof对象（默认构造的空迭代器）来表示。
    istream_iterator<string> eof;

    vector<string> text;
    //输入ctrl+Z结束输入流
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());
 
    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);
}

int v2(){
    ifstream in_file("input_file.txt");
    ofstream out_file("output_file.txt");

    if(! in_file || ! out_file){
        cerr << "File could not be opened!" << endl;
        return -1;
    }

    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());
 
    ostream_iterator<string> os(out_file, " ");
    copy(text.begin(), text.end(), os);

    return 0;
}

int main(){
    //v1();
    return v2();
}