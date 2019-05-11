#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class QuadraticProbing
{
    private:
        vector<pair<int,int> > hashTable;
        int sizeOfTable;
        int noOfElements;
        int hashFn(int key)
        {
            return key % sizeOfTable;
        }
    public:
        QuadraticProbing(int size):sizeOfTable(size),noOfElements(0)
        {
            hashTable.assign(size,make_pair(INT_MIN,INT_MIN));          //INT_MIN signifies empty
        }

        int Search(int key)
        {
            int index = hashFn(key);
            int loopCount = 0;
            while(loopCount <= 10 * sizeOfTable && hashTable[index].first != INT_MIN && hashTable[index].first != key)
            {
                loopCount++;
                index = (index + ((loopCount * loopCount) - ((loopCount - 1) * (loopCount - 1)))) % sizeOfTable;
            }
            if(loopCount > 10*sizeOfTable)
                return INT_MIN;
            return hashTable[index].second;
        }
        void Set(int key,int value)
        {
            if(noOfElements == sizeOfTable)
            {
                cout<<"Table is full could not insert key :"<<key<<endl;
                return;
            }
            int index = hashFn(key);
            int loopCount = 0;
            while(loopCount <= 10 * sizeOfTable && hashTable[index].first != INT_MIN && hashTable[index].first != key && hashTable[index].first != INT_MAX)
            {
                loopCount++;
                index = (index + ((loopCount * loopCount) - ((loopCount - 1) * (loopCount - 1)))) % sizeOfTable;
            }
            if(loopCount > 10 * sizeOfTable)
            {
                cout<<"Element with key :"<<key<<" not inserted because of bad luck\n";
                return;
            }
            if(hashTable[index].first == INT_MIN || hashTable[index].first == INT_MAX)
            {
                hashTable[index].first = key;
                noOfElements++;
            }
            hashTable[index].second = value;
        }
        int Delete(int key)
        {
            if(noOfElements == 0)
            {
                cout<<"No elements left in the hashtable to delete...\n";
                return INT_MIN;
            }
            int index = hashFn(key);
            int loopCount = 0;
            while(loopCount <= 10 * sizeOfTable && hashTable[index].first != INT_MIN && hashTable[index].first != key)
            {
                loopCount++;
                index = (index + ((loopCount * loopCount) - ((loopCount - 1) * (loopCount - 1)))) % sizeOfTable;
            }
            if(loopCount > 10 * sizeOfTable || hashTable[index].first == INT_MIN)
                return INT_MIN;
            noOfElements--;
            hashTable[index].first = INT_MAX;
            int val = hashTable[index].second;
            hashTable[index].second = INT_MAX;
            return val;
        }
        void printhashtable()
        {
            for(int i = 0;i < sizeOfTable;i++)
                cout<<"______";
            cout<<endl;
            for(int i = 0;i < sizeOfTable;i++)
            {
                cout<<"|";
                if(hashTable[i].first == INT_MIN)
                    cout<<"  "<<"e  ";
                else if(hashTable[i].first == INT_MAX)
                    cout<<"  "<<"u  ";
                else
                    cout<<hashTable[i].first<<":"<<hashTable[i].second;
            }
            cout<<"|\n";
            for(int i = 0;i < sizeOfTable;i++)
                cout<<"------";
            cout<<endl;
        }
};

//    QuadraticProbing hashTable(13);
//    hashTable.Set(18,10);
//    hashTable.Set(41,10);
//    hashTable.Set(22,10);
//    hashTable.Set(44,10);
//    hashTable.Set(59,10);
//    hashTable.Set(31,10);
//    hashTable.Set(57,10);
//    hashTable.Set(32,10);
//    hashTable.Set(31,10);
//    hashTable.Set(73,10);
//    hashTable.Set(1,10);
//    hashTable.Set(2,10);
//    hashTable.Set(3,10);
//    hashTable.Set(4,10);
//    hashTable.Set(4,11);
//    hashTable.Set(5,10);
//    hashTable.printhashtable();
//    int del_val;
//    if((del_val = hashTable.Delete(5)) == INT_MIN)
//        cout<<"Element with key :"<<5<<" not found to delete\n";
//    else
//        cout<<"Element with key :"<<5<<" with value :"<<del_val<<" deleted\n";
//    hashTable.printhashtable();

//    int val;
//    if((val = hashTable.Search(4)) == INT_MIN)
//        cout<<"Element with key :"<<23<<" not found\n";
//    else
//        cout<<"Element with key :"<<23<<" found with value :"<<val<<endl;
