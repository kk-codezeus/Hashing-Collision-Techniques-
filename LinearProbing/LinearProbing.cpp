#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class LinearProbe
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
        LinearProbe(int size):sizeOfTable(size),noOfElements(0){

            hashTable.assign(size,make_pair(INT_MIN,INT_MIN));   //INT_MIN signifies empty
        }

        int Search(int key)
        {
            int index = hashFn(key);
            int loopCount = 0;
            while(loopCount <= sizeOfTable && hashTable[index].first != INT_MIN && hashTable[index].first != key)
                index = (index + 1) % sizeOfTable, loopCount++;
            if(loopCount > sizeOfTable)
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
            while(hashTable[index].first != INT_MIN && hashTable[index].first != key && hashTable[index].first != INT_MAX)
                index = (index + 1) % sizeOfTable;
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
            while(loopCount <= sizeOfTable && hashTable[index].first != INT_MIN && hashTable[index].first != key)
                index = (index + 1) % sizeOfTable, loopCount++;
            if(loopCount > sizeOfTable || hashTable[index].first == INT_MIN)
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
