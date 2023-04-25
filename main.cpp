#include <iostream>
using namespace std;
#include "NodeLL.cpp"

int main(int argc, char **argv){
    int i;
    cout << "The argc is " << argc << endl;
    for(i = 0; i < argc ; i++){
        cout << "argv[" << i << "] is " << argv[i] << endl;
    }
    LL test;
    NODE *t;
        for(i = 0; i < argc-1; i++){
            t = new NODE;
            test.add_node(t);
    }
    test.show_all();
    return 0;
}