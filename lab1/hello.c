#include<stdio.h>
#include<string.h>


int main(){

  char input[40];
  gets(input);
  char flag;
  int pos;
  char id[40];
  char name[40];
  char age[40];
  while (strcmp(input, "") != 0) 
  {
    flag = input[0];
    pos = input[1] - '0';
    strncpy(id, input+3, 10);
    id[10] = '\0';
    strncpy(name, input+14, 6);
    name[39] = '\0';
    strncpy(age, input+21, 2);
    age[39] = '\0';
    printf("flag = %c pos = %d id = %s name = %s age = %s\n",
    flag, pos, id, name, age);
    gets(input);
  }
  return 0;
}