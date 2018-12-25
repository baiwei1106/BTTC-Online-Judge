#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream op;
    string str1,str2;
    op.open("out.txt");
    while(!op.eof())
        str1+=op.get();
    op.close();
    op.open("out1.txt");
    while(!op.eof())
        str2+=op.get();
    op.close();
    if(str1==str2)
        puts("YES");
    else
        puts("NO");
    return 0;
}
