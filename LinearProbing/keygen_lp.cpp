#include<bits/stdc++.h>
using namespace std;

int main()
{
    ofstream out("keys.txt");
    srand(time(0));
    int temp = 1;
    for(int i = 0;i < 200000;i++,temp++)
    {
        if(i != 0 && i % 100 == 0)
            temp += 100000 - 100;
        out<<temp<<"\n";
    }
}
