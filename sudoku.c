#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n)
{
   for (int a = 0; a < 9; a++)
   {
      int num[10] = {0};
      for (int b = 0; b < 9; b++)
      {
         if (n->sudo[a][b] != 0 && num[n->sudo[a][b]] == 1) return 0;
            
         else num[n->sudo[a][b]] = 1;
      }
   }
   for (int b = 0; b < 9; b++)
   {
      int num[10] = {0};
      for (int a = 0; a < 9; a++)
      {
         if (n->sudo[a][b] != 0 && num[n->sudo[a][b]] == 1) return 0;

         else num[n->sudo[a][b]] = 1;
      }
   }
   return 1;
}


List* get_adj_nodes(Node* n)
{
   List* list=createList();
   for(int x = 0 ; x < 9 ; x++)
   {
      for(int y = 0 ; y < 9 ; y++)
      {
         if(n->sudo[x][y] == 0)
         {
            for(int i = 1 ; i <= 9 ; i++)
            {
               Node* adyacente = copy(n);
               adyacente->sudo[x][y] = i;
               if(is_valid(adyacente))
               {
                  pushBack(list, adyacente);
               }
            }
         }
      }  
   }
   return list;
}


int is_final(Node* n)
{
   for(int x = 0 ; x < 9 ; x++)
   {
      for(int y = 0 ; y < 9 ; y++)
      {
         if(n->sudo[x][y] == 0) return 0;
      }
   }
   return 1;
}

Node* DFS(Node* initial, int* cont)
{
   /*
   Stack* stack = createStack();
   push(stack, initial);
   while(get_size(stack) != 0)
   {
      Node* n = top(stack);
      pop(stack);
   }
   */
   return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/