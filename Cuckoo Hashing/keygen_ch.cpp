#include<bits/stdc++.h>
using namespace std;

int main()
{

    ofstream out("keys.txt");
    srand(time(0));
    int temp = 1;
    for(int i = 0;i < 100000;i++,temp++)
    {
        out<<temp<<"\n";
    }
}
