// 通用双向链表头文件

#ifndef LLGEN_H  // 确保只包含一次头文件
#define LLGEN_H 1

// 定义双链表数据节点 LLNode
typedef struct Node 
{
  struct Node * prev;
  struct Node * next;
  void        * pdata; // 通用数据
}LLNode, * Link;

// 定义双链表数据结构 List
typedef struct List 
{
  Link LHead;
  Link LTail;
  unsigned int LCount; 
  // 定义四个通用函数指针，操作链表数
  void * ( * LCreateData)    (void *); // void * 保证数据的通用性
  int    ( * LDeleteData)    (void *);
  int    ( * LDuplicateNode) (Link, Link);
  int    ( * LNodeDataCmp)   (void *, void *);
}LList, * PList;

// 通用函数原型
int AddNodeAscend(PList, void *);
int AddNodeAtHead(PList, void *);
PList CreateLList(
  void * (*) (void *),         // 创建
  int    (*) (void *),         // 删除
  int    (*) (Link, Link),     // 重复
  int    (*) (void *, void *)  // 比较
);
Link CreateNode     (PList, void *);
int  DeleteNode     (PList, Link);
Link FindNode       (PList, void *);
Link FindNodeAscend (PList, void *);
Link GoToNext       (PList, Link);
PList GoToPrev      (PList, Link);

#endif