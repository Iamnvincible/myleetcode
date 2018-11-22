#ifndef SOLUTION_146
#define SOLUTION_146
/* Design and implement a data structure for Least Recently Used (LRU) cache.
 It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key
if the key exists in the cache,
otherwise return -1.

put(key, value) - Set or insert the value if the key is not already present.
When the cache reached its capacity,
it should invalidate the least recently
used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

设计一个最近最少使用LRU的数据结构
借助标准库已经实现的双向链表和map数据结构，实现常数时间内的get和put操作
哈希表查找效率高
双向链表的插入和删除效率高

*/
#include <list>
#include <unordered_map>
class LRUCache {
 public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    //没找到
    if (cacheMap.find(key) == cacheMap.end()) return -1;
    //找到了
    //把节点移动到链表头部
    //把cacheList中cacheMap[key]所指向位置的元素移动到
    // cacheList.begin()之前
    cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
    //更新原来key指向元素的位置
    cacheMap[key] = cacheList.begin();
    return cacheMap[key]->value;
  }

  void put(int key, int value) {
    //如果链表中没有这个key
    if (cacheMap.find(key) == cacheMap.end()) {
      //是否以及达到容量
      if (cacheList.size() == capacity) {
        //删除链表尾部元素
        cacheMap.erase(cacheList.back().key);
        cacheList.pop_back();
      }
      //插入新key
      cacheList.push_front(CacheNode(key, value));
      cacheMap[key] = cacheList.begin();
    }
    //有这个key,更新value
    else {
      cacheMap[key]->value = value;
      cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
      cacheMap[key] = cacheList.begin();
    }
  }

 private:
  struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
  };
  //一个双向链表记录节点结构体
  std::list<CacheNode> cacheList;
  //一个map记录key对应结构体在链表中的位置
  std::unordered_map<int, std::list<CacheNode>::iterator> cacheMap;
  //容量
  int capacity;
};
#endif