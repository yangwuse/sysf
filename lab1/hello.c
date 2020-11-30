#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node 
{
  char* name;
}LNode;

int main(){

  LNode* node;
  char* s = "hello";
  node->name = s;
  s = "world";
  printf("%s\n", node->name);
  return 0;
}