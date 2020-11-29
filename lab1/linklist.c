#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Size = 0;
typedef struct LinkItem {
  char *id;
  char *name;
  char *age;
  struct LinkItem *next;
} LNode, *Link;

void printLink(Link L)
{
  if (L == NULL) return;
  Link p = L->next;
  while (p != NULL) 
  {
    printf("%s %s %s\n", p->id, p->name, p->age);
    p = p->next;
  }
}

void printNode(Link L, int pos)
{
  Link p = L->next;
  int temp = pos;
  if (pos < 1 || pos > Size)
  {
    printf("illegal pos\n");
    return ;
  }
  while (--pos) p = p->next;
  printf("pos = %d\t id = %s\t name = %s\t age = %s\t\n",
  temp, p->id, p->name, p->age);
}

void deletNode(Link L, int pos)
{
  Link pre = L;
  if (pos < 1 || pos > Size)
  {
    printf("illegal pos\n");
    return ;
  }
  while (--pos) pre = pre->next;
  Link cur = pre->next;  
  pre->next = cur->next;
  printf("Delete %s\n", cur->name);
  free(cur);
  Size--;
  printLink(L);
}

void insertNode(Link L, int pos, char *id, char *name, char *age)
{
  Link pre = L;
  if (pos < 1 || pos > Size)
  {
    printf("illegal pos\n");
    return ;
  }
  while (--pos) pre = pre->next;
  Link node = (Link) malloc(sizeof(LNode));
  

  node->id = strdup(id); 
  node->name = strdup(name);
  node->age = strdup(age);
  node->next = pre->next;
  pre->next = node;
  printf("insert %s\n", name);
  printLink(L);
}


FILE * openFile(char *path, char *encoding)
{
  // 输入文件指针
  // mac 下相对路径目前不行, 还有乱码问题 ccs (iconv -f GBK23123 -t UTF-8 a > data.txt) 
  FILE *fin = fopen("/Users/yangwu/VSCodeProjects/sysf/lab1/data.txt", "r,ccs=UTF-8");

  if (fin == NULL) 
  {
    fprintf(stderr, "no such file \n");
    exit(EXIT_FAILURE);
  }
  return fin;
}

int main()
{
  // 保存一行数据
  char line[100];
  // mac 下相对路径目前不行, 还有乱码问题 ccs (iconv -f GBK23123 -t UTF-8 a > data.txt) 
  FILE *fin = openFile("/Users/yangwu/VSCodeProjects/sysf/lab1/data.txt", "r,ccs=UTF-8");

  Link  head = (Link)malloc(sizeof(LNode));
  Link r = head;

  // 逐行读取文件，读一行处理一行
  while (fgets(line, 100, fin) != NULL)
  {
   // 分割每行中的字符串, strtok(), 分隔符为 ","
    // 保存每次分割后的字符串
    char *id, *name, *age;
    id = strtok(line, ",");
    name = strtok(NULL, ",");
    age = strtok(NULL, ",");
    
    Link node = (Link)malloc(sizeof(LNode));
    if (node != NULL)
    {
      node->id = strdup(id);
      node->name = strdup(name);
      node->age = strdup(age);
    }
    r->next = node;
    r = node;
    Size++;
  }
  
  r->next = NULL;
  fclose(fin);
  char *input;
  getc(input);
  printf("%s\n", input);
  // printf("%s\n", command);
  // flag = command[0];
  // pos = command[1] - '0';
  char command[10], flag;
  int pos;

  // command = "P3"
  // flag = 'P'; pos = 3;

  // command = "D3"
  // flag = 'D'; pos = 3;

  // command = "I3,SA10225038,张四,24"
  flag = 'I'; pos = 3;
  char *id = "SA10225038";
  char *name = "张四";
  char *age = "24\n";

  

  switch(flag)
  {
    case 'P':
      printNode(head, pos);
      break;
    case 'D':
      deletNode(head, pos);
      break;
    case 'I':
      insertNode(head, pos, id, name, age);
      break;
  }

  return 0;
}
