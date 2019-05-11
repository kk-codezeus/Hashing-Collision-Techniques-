#include "HashChaining.cpp"
//#include<time.h>
#include<chrono>
using namespace chrono;

void individualTestCase()
{
    ifstream in;
    in.open("keys.txt",  ifstream::in);
    int sizeOfTable = 10000;
//    cout<<"Enter the size of HashTable\n";
    HashChain hashTable(sizeOfTable);
    steady_clock::time_point t1,t2;
    ofstream out("hc_times.txt");
    for(int i = 0; i < 10;i++)
    {
        t1 = steady_clock::now();
        for(int j = 0;j < 1000;j++)
        {
            int key;
            in>>key;
            hashTable.Set(key,10);
        }
        t2 = steady_clock::now();
        auto duration = duration_cast<microseconds>((t2 - t1));
        out<<duration.count()<<",";
    }
}
void testCasewithNoCollisions()
{
    ifstream in("../keys_NC.txt",  ifstream::in);
    int sizeOfTable = 1000;
    HashChain hashTable(sizeOfTable);
    steady_clock::time_point t1,t2;

    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Set(key,10);
    }
    t2 = steady_clock::now();
    auto duration = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration.count()<<"\n";
    in.close();

    in.open("../keys_NC.txt",  ifstream::in);
    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Search(key);
    }
    t2 = steady_clock::now();
    auto duration2 = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration2.count()<<"\n";
    in.close();

    in.open("../keys_NC.txt",  ifstream::in);
    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Delete(key);
    }
    t2 = steady_clock::now();
    auto duration3 = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration3.count()<<"\n";

}

void testCasewithSequentialCollisions()
{
    ifstream in("../keys_collision.txt",  ifstream::in);
    int sizeOfTable = 1000;
    HashChain hashTable(sizeOfTable);
    steady_clock::time_point t1,t2;

    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Set(key,10);
    }
    t2 = steady_clock::now();
    auto duration = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration.count()<<"\n";
    in.close();

    in.open("../keys_collision.txt",  ifstream::in);
    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Search(key);
    }
    t2 = steady_clock::now();
    auto duration2 = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration2.count()<<"\n";
    in.close();

    in.open("../keys_collision.txt",  ifstream::in);
    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Delete(key);
    }
    t2 = steady_clock::now();
    auto duration3 = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration3.count()<<"\n";
}

void testCasewithRandomCollisions()
{
    ifstream in("../keys_randcollision.txt",  ifstream::in);
    int sizeOfTable = 1000;
    HashChain hashTable(sizeOfTable);
    steady_clock::time_point t1,t2;

    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Set(key,10);
    }
    t2 = steady_clock::now();
    auto duration = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration.count()<<"\n";
    in.close();

    in.open("../keys_randcollision.txt",  ifstream::in);
    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Search(key);
    }
    t2 = steady_clock::now();
    auto duration2 = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration2.count()<<"\n";
    in.close();

    in.open("../keys_randcollision.txt",  ifstream::in);
    t1 = steady_clock::now();
    for(int j = 0;j < 1000;j++)
    {
        int key;
        in>>key;
        hashTable.Delete(key);
    }
    t2 = steady_clock::now();
    auto duration3 = duration_cast<nanoseconds>((t2 - t1));
    cout<<duration3.count()<<"\n";
}

void manualRun()
{
    int sizeOfTable;
    cout<<"Enter the size of the table\n";
    cin>>sizeOfTable;
    HashChain hashTable(sizeOfTable);
    char command;
    cout<<"Now enter a command : i for insert, s for search, p for printing the hashTable, d for delete, e for exit\n";
    cin>>command;
    while(command != 'e')
    {
        switch(command)
        {
            int key,value;
            case 'i':
                cout<<"enter the key and the value to insert\n";
                cin>>key>>value;
                hashTable.Set(key,value);
                break;
            case 'p':
                hashTable.printHashTable();
                break;
            case 's':
                cout<<"Enter the key to search\n";
                cin>>key;
                if((value = hashTable.Search(key)) != INT_MIN)
                    cout<<"Key: "<<key<<" found with value :"<<value<<endl;
                else
                    cout<<"Key: "<<key<<" not present in the table\n";
                break;
            case 'd':
                cout<<"Enter the key to delete\n";
                cin>>key;
                if((value = hashTable.Delete(key)) != INT_MIN)
                    cout<<"Key: "<<key<<" with value: "<<value<<" deleted\n";
                else
                    cout<<"Key: "<<key<<" not found in the table\n";
                break;
            default:
                cout<<"Enter a correct command please\n";
                break;
        }
        cout<<"Now enter a command : i for insert, s for search, p for printing the hashTable, d for delete, e for exit\n";
        cin>>command;
    }
}

int main()
{
    //individualTestCase();
    //testCasewithNoCollisions();
    //testCasewithSequentialCollisions();
    //testCasewithRandomCollisions();
    manualRun();
    return 0;
}
