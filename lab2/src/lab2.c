#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "llgen.h"
#include "llapp.h"

int main()
{
  char ch;
  // 创建并初始化双链表
  PList L1 = CreateLList(CreateData1, DeleteData1, DuplicatedNode1,  NodeDataCmp1);
  if (L1 == NULL) 
  {
    fprintf(stderr, "双链表创建失败\n");
    exit(EXIT_FAILURE);
  }
  while (1)
  {
    ch = getchar();
    while (ch != '\n')
    {
      if (AddNodeAtHead(L1, &ch) == 0) 
        fprintf(stderr, "add error\n");
      ch = getchar();
    }

    Link head = L1->LHead, tail = L1->LTail;
    int cmp = 0;
    while (head != tail)
    {
      cmp = L1->LNodeDataCmp(head->pdata, tail->pdata);
      if (cmp != 0)
        break;
      head = head->next;
      // 偶数长度退出条件
      if (head == tail)
        break;
      tail = tail->prev;
    }

    if (cmp == 0)
      printf("对称\n");
    else 
      printf("非对称\n");

    Link p = L1->LHead, nex = p->next;
    while(L1->LCount != 1)
    {
      DeleteNode(L1, p);
      p = nex;
      nex = nex->next;
    }
    L1->LHead = NULL;
    L1->LTail = NULL;
    L1->LCount = 0;
  }

  return 0;
}


