
#include<bits/stdc++.h>
unordered_map<int,pair<int,list<int>::iterator>>myMap;
list<int>myList;
int n;
LRUCache::LRUCache(int capacity) {
    myMap.clear();
    myList.clear();
    n=capacity;
}

int LRUCache::get(int key) {
    if(myMap.find(key)==myMap.end())
        return -1;
    auto it=myMap[key];
    myList.erase(it.second);
    myList.push_front(key);
    pair<int,list<int>::iterator>temp;
    temp.first=it.first;
    temp.second = myList.begin();
    myMap[key]=temp;
    return it.first;
}

void LRUCache::set(int key, int value) {
    if(myMap.find(key)==myMap.end())
    {
        if((int)myList.size()==n)
        {
            int f=myList.back();
            myList.pop_back();
            myMap.erase(f);
            myList.push_front(key);
            pair<int,list<int>::iterator>temp;
            temp.first=value;
            temp.second = myList.begin();
            myMap.insert(make_pair(key,temp));
        }
        else
        {
             myList.push_front(key);
            pair<int,list<int>::iterator>temp;
            temp.first=value;
            temp.second = myList.begin();
            myMap.insert(make_pair(key,temp));
        }
    }
    else
    {
        auto it=myMap[key];
        myList.erase(it.second);
        myList.push_front(key);
        pair<int,list<int>::iterator>temp;
        temp.first=value;
        temp.second = myList.begin();
        myMap[key]=temp;
    }

}
