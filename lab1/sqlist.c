#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SqlItem {
  char id[11]; // 数组最后必须有 '\0'
  char name[20];
  char age[20];
} Node;
// 定义顺序表
int len;
Node SqList[100];

void printSqListAddr()
{
  for (int i = 0; i < len; i++)
    printf("i = %d\t addr = %p\n", i, &SqList[i]);
}

void printSqList()
{
  for (int j = 0; j < len; j++) 
  {
    printf("%s %s %s\n", SqList[j].id,SqList[j].name, SqList[j].age);
  }
}

void printAtIndex(int index)
{
  printf("P3 id = %s\t name = %s\t age = %s\t\n",
  SqList[index].id, SqList[index].name, SqList[index].age);
}

void deletAtIndex(int index)
{
  printf("delete %s\n", SqList[index].name);
  for (int i = index; i < len - 1; i++)
    SqList[i] = SqList[i + 1];
  len--;
  printSqList();
}

void insertAtIndex(int index, char *id, char *name, char *age)
{
  for (int i = len; i > index; i--)
    SqList[i] = SqList[i - 1];
  strcpy(SqList[index].id, id);
  strcpy(SqList[index].name, name);
  strcpy(SqList[index].age, age);
  len++;
  printf("inset %s\n", SqList[index].name);
  printSqList();
}

int main()
{
  // 保存一行数据
  char line[100];
  // 输入文件指针
  FILE *fin = NULL;
  // mac 下相对路径目前不行, 还有乱码问题 ccs (iconv -f GBK23123 -t UTF-8 a > data.txt) 
  fin = fopen("/Users/yangwu/VSCodeProjects/sysf/lab1/data.txt", "r,ccs=UTF-8");

  if (fin == NULL) 
  {
    fprintf(stderr, "no such file \n");
    exit(EXIT_FAILURE);
  }

  int i = 0;
  
  // 逐行读取文件，读一行处理一行
  while (fgets(line, 100, fin) != NULL)
  {
    // 分割每行中的字符串, strtok(), 分隔符为 ","
    // 保存每次分割后的字符串
    char *id, *name, *age;
    id = strtok(line, ",");
    name = strtok(NULL, ",");
    age = strtok(NULL, ",");

    strcpy(SqList[i].id, id);
    strcpy(SqList[i].name, name);
    strcpy(SqList[i].age, age);
    ++i;
    len++;
  }

  fclose(fin);

  char command[10], flag;
  int pos;

  // command = "P3"
  flag = 'P'; pos = 3;

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
      printAtIndex(pos-1);
      break;
    case 'D':
      deletAtIndex(pos-1);
      break;
    case 'I':
      insertAtIndex(pos-1, id, name, age);
      break;
  }
  // printf("sizeof Node = %dB\n", sizeof(SqList[0]));
  printSqListAddr();

  return 0;
}