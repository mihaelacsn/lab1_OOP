#include "mylibrary.h"

int main()
{
    TypeList prev, head, list, head2, list2, prev2, tail;

    int n,nn,i, val;
    printf("\n write the number of elements in list ");
    scanf("%d", &n);
            
    head = NULL;
     
     list = allocList();
     scanf("%d",&list->value);
    for(i = 1; i < n; i++)
    {   TypeList aux;
        aux=allocList();
        if(head == NULL){
            head = list;
        }
    
        scanf("%d",&aux->value);

        list->next = aux;
        list->next->prev = list; 
        list=list->next;     
        
        if (i==n-1)
        {
            tail = allocList();
            tail = aux;
           

        }
    }
    
    //second list
    printf("\n write the number of elements in list ");
    scanf("%d", &nn);
    
    head2 = NULL;
    list2 = allocList();
    scanf("%d",&list2->value);

    for(i = 1; i < nn; i++)
    {   TypeList aux;
        aux=allocList();
        if(head2 == NULL){
            head2 = list2;
        }

        scanf("%d",&aux->value);

        list2->next = aux; 
        list2=list2->next;     
    }
    
    //The menu with the function implemented:
    printf("Choose an available command from the list below:\n");
    printf("Press 'p' for printing the first list\n");
    printf("Press 'l' for printing the second list\n");
    printf("Press 'a' for Append function\n");
    printf("Press 'g' for Preppend function\n");
    printf("Press 'r' for Reverse function\n");
    printf("Press 'w' for AddElement function\n");
    printf("Press 'd' for RemElem function\n");
    printf("Press 't' for SortList function\n");
    printf("Press 's' for SearchValue\n");
    printf("Press 'j' for JoinList function\n");
    printf("Press 'b' for Backward function\n");
    printf("Press 'f' to save the results in a file\n");
    printf("Press 'y' to read the results from the file\n");
    printf("Press 'q' to quit the menu option program\n");

    char menu;
    while(menu = getchar())
    {
        switch(menu)
        {
            case 'p':
                printf("The elements of the first list\n");
                print(head);
                break;
            case 'l':
                printf("The elements of the second list\n");
                print(head2);
                break;
            case 'a':
                int value_end;
                printf("Add a value at the end of the list\n");
                printf("\nthe value to be added at the end ");
                scanf("%d", &value_end);
                Append(head, value_end);
                print(head);
                break;
            case 'g':
                int value_front;
                printf("Add a value at the beggining of the list\n");
                printf("\nThe value to be add at the beggining ");
                scanf("%d", &value_front);
                Prepend(&head, value_front);
                print(head);
                break;
            case 'r':
                printf("\nReversed list ");
                Reverse(&head);
                print(head);
                break;
            case 'w':
                printf("Add a value to a specific index in the list\n");
                int new, pos;
                printf("\n Value to be added ");
                scanf("%d", &new);
                printf("\nThe position to add the new value ");
                scanf("%d", &pos);
                AddElem(head, new, pos);
                print(head);
                break;
            case 'd':
                int pos_del;
                printf("Delete a value at a specific index in the list\n");
                printf("\nPosition the elem is gonna be deleted ");
                scanf("%d", &pos_del);
                RemElem(&head, pos_del);
                print(head);
                break;
            case 't':
                SortList(head);
                printf("\nThe sorted list ");
                print(head);
                break;
            case 's':
                printf("Search for a specific value in the list\n");
                 int search_val;
                printf("Value to be searched ");
                scanf("%d", &search_val);
                SearchValue(head, search_val);
                break;
            case 'j':
                printf("Join the two linked lists\n");
                TypeList list_final;
                list_final = allocList();
                printf("\n The lists joined:");
                head = JoinList(head, head2);
                print(head); 
                break;
            case 'b':
                printf("Transversal backward using double-linked list\n");
                printf("\n Backward function");
                Backward(tail);
                break;
            case 'f':
                printf("Save the results in a file:\n");
                SaveInFile(head);
                break;
            case 'q':
                printf("Program quited\n");
                exit(0);
            case 'y':
                
                list = ReadFile();
                print(list);
                break;
            
        }
    }
    return 0;
}