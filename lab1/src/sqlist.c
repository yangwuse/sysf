#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SqlItem {
  char* m_id; 
  char* m_name;
  char* m_age;
} Node;

// 定义顺序表
int LEN;
Node SqList[100];

void printSqListAddr()
{
  for (int i = 0; i < LEN; i++)
    printf("i = %d\t addr = %p\n", i, &SqList[i]);
}

void printSqList()
{
  for (int j = 0; j < LEN; j++) 
  {
    printf("%d %s %s %s\n", j+1, SqList[j].m_id,SqList[j].m_name, SqList[j].m_age);
  }
}

void printAtIndex(int index)
{
  printf("id = %s\t name = %s\t age = %s\t\n",
  SqList[index].m_id, SqList[index].m_name, SqList[index].m_age);
}

void deletAtIndex(int index)
{
  printf("删除 %s\n", SqList[index].m_name);
  for (int i = index; i < LEN - 1; i++)
    SqList[i] = SqList[i + 1];
  LEN--;
  printSqList();
}

void insertAtIndex(int index, char *id, char *name, char *age)
{
  for (int i = LEN; i > index; i--)
    SqList[i] = SqList[i - 1];
  // 这里直接赋值没问题
  SqList[index].m_id = id;
  SqList[index].m_name = name;
  SqList[index].m_age = age;
  LEN++;
  printf("插入 %s\n", SqList[index].m_name);
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
    // 使用 strdup 不需要手动 malloc 了
    SqList[i].m_id = strdup(id);
    SqList[i].m_name = strdup(name);
    SqList[i].m_age = strdup(age);
    ++i;
    LEN++;
  }

  fclose(fin);
  char input[20];
  gets(input);
  char *tmpStr, flag, *id, *name, *age;
  int pos; 
  while (strcmp(input, "") != 0)
  {
    // P3, D3
    tmpStr = strtok(input, ",");
    flag = tmpStr[0];
    pos = tmpStr[1] - '0';
    // I3,SA10225038,张四,24
    id = strtok(NULL, ",");
    name = strtok(NULL, ",");
    age = strtok(NULL, ","); 
    switch(flag)
    {
      case 'P':
        printAtIndex(pos);
        break;
      case 'D':
        deletAtIndex(pos);
        break;
      case 'I':
        insertAtIndex(pos,id, name, age);
        break;
    }
    printf("输入命令以继续，否则结束\n");
    gets(input);
  }
  printSqListAddr();

  return 0;
}