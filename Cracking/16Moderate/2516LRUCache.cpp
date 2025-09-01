#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <limits.h>
#include <numeric> // Required for std::accumulate
#include <queue>

// g++ -std=c++17 2516LRUCache.cpp -o hola

// map + queue.

#define MAX_SIZE 5

void GetFromCache(int x, int &size, std::unordered_map<int, int> &cacheMap, std::queue<int> &lastUsedQueue)
{
    if(cacheMap.count(x)) { // Already exists.
        // Erase from the queue.
        std::queue<int> auxQueue;
        while(!lastUsedQueue.empty()) {
            int queueValue = lastUsedQueue.front();
            if(queueValue != x) {
                auxQueue.push(queueValue);
            }
            lastUsedQueue.pop();
        }

        lastUsedQueue = auxQueue;
    } else {
        cacheMap[x] = 42;
        ++size;
        if(size > MAX_SIZE) {
            size = MAX_SIZE;
            cacheMap.erase(lastUsedQueue.front());
            lastUsedQueue.pop();
        }
    }

    lastUsedQueue.push(x);
}

int main()
{
    std::unordered_map<int, int> cacheMap;
    std::queue<int> lastUsedQueue;
    int size = 0;

    GetFromCache(24, size, cacheMap, lastUsedQueue);
    GetFromCache(65, size, cacheMap, lastUsedQueue);
    GetFromCache(84, size, cacheMap, lastUsedQueue);
    GetFromCache(12, size, cacheMap, lastUsedQueue);
    GetFromCache(54, size, cacheMap, lastUsedQueue);
    GetFromCache(99, size, cacheMap, lastUsedQueue); // Reset Last used cache (24)

    //for(auto pair : cacheMap) {
    //    std::cout << pair.first << "  " << pair.second << std::endl;
    //} std::cout << std::endl;

    GetFromCache(54, size, cacheMap, lastUsedQueue);
    GetFromCache(65, size, cacheMap, lastUsedQueue);
    GetFromCache(11, size, cacheMap, lastUsedQueue); // 11 sould substitute 84.

    for(auto pair : cacheMap) {
        std::cout << pair.first << "  " << pair.second << std::endl;
    } std::cout << std::endl;

    return 0;
}