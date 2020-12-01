// 应用特定头文件
#ifndef LLAPP_H
#define LLAPP_H 1

// 节点只包含一个字符
typedef struct NodeData1
{
  char* word;
}ND1, * pND1;

extern void * CreateData1(void *);
extern int    DeleteData1(void *);
extern int    DuplicatedNode1(Link, Link);
extern int    NodeDataCmp1(void *, void *);

#endif