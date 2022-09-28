#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
    struct node* prev;
}*TypeList, TypeNode;

TypeList allocList();
void print(TypeList l);
void destroy(TypeList* dl);
TypeList Append(TypeNode *head, int new_value);
TypeList Prepend(TypeList *head, int new_value);
void Reverse(TypeList *rev);
TypeList AddElem(TypeList head, int value, int pos);
void RemElem(TypeList *head, int pos);
void SortList(TypeList head);
void SearchValue(TypeList head, int search_value);
TypeList JoinList(TypeList head1, TypeList head2);
void Backward(TypeList l);
void SaveInFile(TypeList head);
TypeList ReadFile();