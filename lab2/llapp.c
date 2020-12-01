#include<stdlib.h>
#include<string.h>

#include "llgen.h"
#include "llapp.h"

void * CreateData1(void * data)
{

  pND1 new_data;
  if ((new_data = (pND1)malloc(sizeof(ND1))) == NULL)
    return NULL;

  new_data->word = strdup((char*)data);
  if (new_data->word == NULL)
  {
    free(new_data);
    return NULL;
  }

  return new_data;
}

int DeleteData1(void * data)
{
  free ( ((pND1) data)->word );
  return 0;
}

int DuplicatedNode1(Link new_node, Link list_node)
{
  return 0;
}

int NodeDataCmp1 ( void *first, void *second )
{
    return ( strcmp ( ((pND1) first)->word,
                      ((pND1) second)->word ));
}



