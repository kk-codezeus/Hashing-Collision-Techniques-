#include<bits/stdc++.h>
using namespace std;

typedef list<pair<int,int> >::iterator iter;

class HashChain{
    private:
        vector<list<pair<int,int> > > hashTable;
        int sizeOfTable;
        //int currentNoOfElements;
            iter searchForKey(int key)
        {
            int index = key % sizeOfTable;
            for(iter it = hashTable[index].begin();it != hashTable[index].end();it++)
                if(it->first == key)
                    return it;
            return hashTable[index].end();
        }
    public:
        HashChain(int size = 0):sizeOfTable(size)//,currentNoOfElements(0)
        {
            for(int i = 0;i < size;i++)
                hashTable.push_back(list<pair<int,int> >());
        }
        int Search(int key)
        {
            int index = key % sizeOfTable;
            for(iter it = hashTable[index].begin();it != hashTable[index].end();it++)
                if(it->first == key)
                    return it->second;
            return INT_MIN;
        }
        void Set(int key,int val)
        {
            int index = key % sizeOfTable;
            iter it = searchForKey(key);
            if(it != hashTable[index].end())
                it->second = val;
            else
                hashTable[index].push_back(make_pair(key,val));
        }
        int Delete(int key)
        {
                int index = key % sizeOfTable;
                iter it = searchForKey(key);
                if(it != hashTable[index].end())
                {
                    int value = it->second;
                    hashTable[index].erase(it);
                    return value;
                }
                else
                    return INT_MIN;
        }
        void printHashTable()
        {
            for(int i = 0;i < sizeOfTable;i++)
            {
                cout<<i;
                if(hashTable[i].size() == 0)
                {
                    cout<<endl;
                    continue;
                }
                cout<<"---->";
                iter it = hashTable[i].begin();
                for(;it != hashTable[i].end();)
                {
                    cout<<"("<<it->first<<","<<it->second<<")";
                    it++;
                    if(it != hashTable[i].end())
                        cout<<"--";
                }
                cout<<endl;
            }
        }
};

