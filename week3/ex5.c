#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    struct ListItem * head;
    int size;
};

struct ListItem{
    struct ListItem* next;
    struct ListItem* previous;
    int value;
};

//creates new linked list
struct LinkedList* create_list(){
    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

//Prints size and all elements of the list
void print_list(struct LinkedList* list){
    if(list->size == 0){
        printf("Nothing to display, list is empty");
    }
    else{
        printf("There is %d elements in the list: ", list->size);
        struct ListItem * current = list->head;
        do{
            printf("%d ", current->value);
            current = current->next;
        }while(current!=NULL);
    }
    printf("\n");

}

//inserts new value into list to this index
// if index negative - does nothing
// if index bigger then the list size - inserts into the end of the list
void insert_node(struct LinkedList* list, int newValue, int index){
    struct ListItem* newItem = malloc(sizeof(struct ListItem));
    newItem->value = newValue;
    newItem->next = NULL;
    newItem->previous = NULL;
    if(index <0){
        printf("Attempt to insert into cell with negative index\n");
    }
    else if (list->size == 0  || list->head == NULL){
        list->head = newItem;
    }
    else if (index == 0){
        newItem->next = list->head;
        newItem->next->previous = newItem;
        list->head = newItem;
    }
    else{
        struct ListItem* last = list->head;
        int i = 1;
        //find element to insert after
        while(last->next != NULL && i!=index){
            last = last->next;
            i++;
        }
        newItem->next = last->next;
        if(last->next!=NULL){
            last->next->previous = newItem;
        }
        last->next = newItem;
        newItem->previous = last;
    }
    list->size ++;

}

//deletes value from cell with this index of the list
//if index negative or list is empty- does nothing
//if index bigger then the list size - deletes from the end of the list
int delete_node(struct LinkedList* list, int index){

    if(index <0){
        printf("Attempt to delete from cell with negative index\n");
    }
    else if (list->size == 0  || list->head == NULL){
        printf("Attempt to delete from empty list\n");
        return 0;
    }
    else if(index == 0 || list->size == 1){
        struct ListItem* toDelete = list->head;
        list->head = list->head->next;
        if(list->head!=NULL){
            list->head->previous = NULL;
        }
        free(toDelete);
        list->size --;
    }
    else{
        struct ListItem* last = list->head;
        int i = 1;
        //find element before element to delete
        while(last->next->next != NULL && i!=index){
            last = last->next;
            i++;
        }
        struct ListItem* toDelete = last->next;
        last->next = last->next->next;
        if(last->next != NULL){
            last->next->previous = last;
        }
        free(toDelete);
        list->size --;
    }
}

int main(){
    struct LinkedList* myList = create_list();
    insert_node(myList,0,0);
    insert_node(myList,1,0);
    insert_node(myList,2,0);
    print_list(myList);

    delete_node(myList,0);
    print_list(myList);

    insert_node(myList,10,10);
    print_list(myList);
    delete_node(myList,1);
    print_list(myList);
    delete_node(myList,10);
    print_list(myList);
    delete_node(myList,1);
    print_list(myList);
    delete_node(myList,1);

    insert_node(myList,0,0);
    insert_node(myList,1,0);
    insert_node(myList,2,0);
    print_list(myList);

    delete_node(myList,0);
    print_list(myList);

    insert_node(myList,10,10);
    print_list(myList);
    delete_node(myList,1);
    print_list(myList);
    delete_node(myList,10);
    print_list(myList);
    delete_node(myList,1);
    print_list(myList);
    delete_node(myList,1);
    return 0;
}


