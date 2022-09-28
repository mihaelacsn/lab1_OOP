/*
Linked List (min. 5 points):
   - Append (0.5 point) aka add an elem at the end of the list
    -Prepend (0.5 point) aka add an elem at the beggining of the list
    -Reverse (0.5 point)
    -Add a value to the specific index (0.5 point)
    -Remove a value the from index (0.5 point)
    -Sort the linked list, with re-arranging the cells, not just copying values (0.5 point)
    -Search for a value (0.5 point)
    -Join two linked lists (0.5 point)
    -Backwards traversal, use double-linked-list (1 point)
*/
#include "mylibrary.h"

TypeList allocList()
{
    TypeList aux = malloc(sizeof(TypeList));
    return aux;
}

void print(TypeList l)
{
    for (; l != NULL; l = l->next)
      printf("%d ", l->value); 
        printf("\n");
}

void destroy(TypeList* dl)
{
    TypeList aux;
    while(*dl)
  {
    aux = *dl;
    *dl = aux->next;
    free(aux);
  }

}

//Prepend 
TypeList Prepend(TypeList *head, int new_value)
{
    TypeList l = malloc(sizeof(struct node));
    l->value = new_value;
    l->next=*head;
    *head = l;
}

//Append

TypeList Append(TypeNode *head, int new_value)
{
    TypeNode *l = head;
     while(l->next!=NULL)
    {
        l = l->next;
    }
   l->next = allocList();
   l->next->value = new_value;
   l->next->next  =NULL;
}

//Reverse list
void Reverse(TypeList *rev)
{
    TypeList prev = NULL;
    TypeList l = *rev;
    TypeList next = NULL;
    while (l != NULL) {
        next = l->next;
        l->next = prev;
        prev = l;
        l = next;
    }
    *rev = prev;
}

//Add a value to the specific index
TypeList AddElem(TypeList head, int value, int pos)
{
    TypeList apos  = head;
    TypeList bpos = malloc(sizeof(struct node));

    bpos->value = value;
    bpos->next = NULL;
    pos--;

    while(pos != 1)
    {
        apos = apos->next;
        pos--;
    }
    bpos->next= apos->next;
    apos->next=bpos;
}
//Remove a value the from index 
void RemElem(TypeList *head, int pos)
{
    TypeList l = *head;
    TypeList prev = *head;

    if(pos == 1)
    {
        *head = l->next;
        free(l);
        l = NULL;
    }
    else 
    {   while (pos != 1)
        {
            prev = l;
            l = l->next;
            pos--;
        }
        prev->next = l->next;
        free(l);
        l = NULL;
    }
}

//Sorting Bubble sort
void SortList(TypeList head)
{
    TypeList l = head, i = NULL;
    int aux;

    while (l !=NULL)
    {
        i=l->next;
    

        while (i != NULL)
        {
            if (l->value > i->value)
            {
            aux = l->value;
            l->value=i->value;
            i->value=aux;
            }

            i = i->next;
        }

        l=l->next;
    }
}

//Search for the value
void SearchValue(TypeList head, int search_value)
{
    TypeNode *l = head;
    int aux = 0;
    

    while(l != NULL)
    {      
            if(l->value == search_value){
                
                aux++;
            }
                l=l->next;
            
            
            
    }
    if (aux == 0)
    {
        printf("value not found");
    }
    else 
    {
        printf("value found");
    }
    
  
}

TypeList JoinList(TypeList head1, TypeList head2)
{
    TypeList l1, l2, l3;
    
    l1 = allocList();
    l2 = allocList();
    l3 = allocList();

    l1 = head1;
    l2 = head2;
    l3 = head1;

    
    
    if (l1 != NULL && l2 != NULL)
    {   
        while(l1->next!=NULL)
        l1 = l1->next;
    }
    l1->next = l2;
   
return l3;
}

void Backward(TypeList l)
{   
   
    for (; l != NULL; l = l->prev)
      printf("%d ", l->value); 
      
        printf("\n");
}

void SaveInFile(TypeList head)
{
    TypeList aux = head;

    FILE* file;
    file = fopen("saved_data", "w");

    

    while (aux != NULL)
    {
        if(aux->next==NULL){
            fprintf(file, "%d", aux->value);
        }else{
            fprintf(file, "%d ", aux->value);
        }
        
        aux = aux->next;
    }
    fclose(file);
}

TypeList ReadFile(){
    FILE *file;
    TypeList temp = allocList();
    TypeList head, tail; 
    int r = 0;
    int i;
    tail = NULL;
    head = NULL;
    file = fopen("saved_data", "r");

    while(!feof(file))
    {
        
        
        TypeList aux;
        r++;
        aux = allocList();
        fscanf(file,"%d",&aux->value);
        
        temp->next = aux;
        //temp->next->prev = temp; 
        temp=temp->next; 
        
        if(r==1)
        {
            head = allocList();
            head = aux;
        } 
    }
    fclose(file);
    return head;
    
}


