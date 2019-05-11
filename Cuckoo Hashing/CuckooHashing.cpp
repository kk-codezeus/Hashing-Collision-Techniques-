#include<bits/stdc++.h>
using namespace std;

class CuckooHashing
{
    private:
        vector<pair<int,int> > hashTable;
        int sizeOfTable;
        int noOfElements;
        int hashFn1(int key,int a = 51,int b = 31)
        {
            //return (a + b*key) % (sizeOfTable/2);
            return key % (sizeOfTable/2);
        }
        int hashFn2(int key)
        {
            //return hashFn1(key,31,51) + sizeOfTable/2;
            return (key/(sizeOfTable/2)) % (sizeOfTable/2) + sizeOfTable/2;
        }
        void printHalfTable(int start,int fin)
        {
            for(int i = start;i < fin;i++)
            {
                cout<<"------";
            }
            cout<<endl;
            for(int i = start;i < fin;i++)
            {
                if(hashTable[i].first == INT_MIN)
                    cout<<"|"<<"  e  ";
                else
                    cout<<"|"<<hashTable[i].first<<":"<<hashTable[i].second;
            }
            cout<<endl;
            for(int i = start;i < fin;i++)
            {
                cout<<"------";
            }
            cout<<endl;
        }
        int kIndex(int key)
        {
            int index = hashFn1(key);
            if(hashTable[index].first == key)
                return index;
            index = hashFn2(key);
            if(hashTable[index].first == key)
                return index;
            return INT_MIN;
        }
    public:
        CuckooHashing(int size):sizeOfTable(2 * size),noOfElements(0)
        {
            hashTable.assign(2 * size,make_pair(INT_MIN,INT_MIN));
        }
        int Search(int key)
        {
            int index = hashFn1(key);
            if(hashTable[index].first == key)
                return hashTable[index].second;
            index = hashFn2(key);
            if(hashTable[index].first == key)
                return hashTable[index].second;
            return INT_MIN;
        }
        int Delete(int key)
        {
            int index1 = hashFn1(key), index2 = hashFn2(key);
            int val,index;
            if(hashTable[index1].first == key || hashTable[index2].first == key)
            {
                noOfElements--;
                if(hashTable[index1].first == key)
                    index = index1;
                else
                    index = index2;
                val = hashTable[index].second;
                hashTable[index].first = INT_MIN;
                hashTable[index].second = INT_MIN;
                return val;
            }
            return INT_MIN;
        }
        void Set(int key,int value = 10)
        {
            //Check whether the key already exists in the table
            int keyIndex;
            if((keyIndex = kIndex(key)) != INT_MIN)
            {
                hashTable[keyIndex].second = value;
                return;
            }
            int index = hashFn1(key), t = 1,temp_key,temp_val;
            //cout<<index<<endl;
            int loopCount = 0;
            while(loopCount <= 4 * noOfElements && hashTable[index].first != INT_MIN && hashTable[index].first != key)
            {
                loopCount++;
                temp_key = hashTable[index].first;
                temp_val = hashTable[index].second;
                hashTable[index].first = key;
                hashTable[index].second = value;
                key = temp_key;
                value = temp_val;
                if(t == 1)
                    index = hashFn2(key);
                else
                    index = hashFn1(key);
                t = 1 - t;
                //cout<<key<<value<<index;
            }
            if(noOfElements != 0 && loopCount > 4 * noOfElements)
            {
                //cout<<"Cycle detected... \n";
                return;
            }
            else
            {
                if(hashTable[index].first == INT_MIN)
                noOfElements++;
                hashTable[index].first = key;
                hashTable[index].second = value;
            }
        }
        void printhashtable()
        {
            printHalfTable(0,sizeOfTable/2);
            printHalfTable(sizeOfTable/2,sizeOfTable);
        }
};

