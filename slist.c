#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include "slist.h"

Slist slist_new(){

    Slist s1 = {NULL,NULL,0};
    return s1;

}

int slist_length(const Slist *list){
    assert(list != NULL);
    return list->length;
}

static Node* _get_new_node_(int32_t val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;

    return newnode;
}

Slist* slist_addnode_head(Slist *list,int32_t val){
    assert(list != NULL );
    Node *newnode = _get_new_node_(val);

    newnode->next = list->head;
    list->head = newnode;

    if(list->tail == NULL){
    list->tail = newnode;
    }
    ++list->length;

    assert( (list->length == 1 && list->head == list->tail) || (list->length > 1 && list->head != list->tail));

    return list;
}

Slist* slist_addnode_tail(Slist *list,int32_t val){
    assert(list != NULL );
    Node *newnode = _get_new_node_(val);

    if(list->tail != NULL){
        list->tail->next = newnode;
        list->tail = newnode;
    }else{
        list->head = list->tail = newnode;
    }
    ++list->length;

    assert( (list->length == 1 && list->head == list->tail) || (list->length > 1 && list->head != list->tail));

    return list;
}

Slist* slist_delnode_head(Slist *list){
    assert( list != NULL);
    Node *temp;
    if (list->head != NULL ){
        temp = list->head;
        list->head = list->head->next;
        if (list->head == NULL ){ // if only one node exists
            list->tail = NULL;
        }
        --list->length;
        free(temp);
    }
    return list;
}

Slist* slist_delnode_tail(Slist *list){
    assert( list != NULL );
    Node *last, *cur;

    if ( list->tail != NULL ){
        last = list->tail;
        if( list->head == list->tail){
            list->head=list->tail=NULL;
        }else{
            cur = list->head;
            while(cur->next != last){
                cur = cur->next;
            }
            list->tail=cur;
            cur->next = NULL;
        }
       --list->length;
       free(last);
    }
    return list;
}

int slist_lookup(const Slist *list, int32_t key){
    assert(list != NULL);
    Node *cur = list->head;

    for(cur = list->head; cur != NULL; cur = cur->next){
        if(cur->data == key){
            break;
        }
    }
    return (cur != NULL );
}

int slist_minimum(const Slist *list){
    assert( list != NULL );
    Node *temp = list->head;
    int min = temp->data;

    while ( temp != NULL ){
        if (temp->data < min){
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

int slist_maximum(const Slist *list){
    assert( list != NULL );
    Node *temp = list->head;
    int max = temp->data;

    while ( temp != NULL ){
        if (temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
}
Slist* slist_addnode_after(Slist *list,int32_t val,int32_t prev_num){
    assert(list != NULL );
    Node *newnode = _get_new_node_(val);
    Node *cur = list->head;

    while ( cur->data != prev_num){
        cur = cur->next;
    }
    newnode->next = cur->next;
    cur->next = newnode;
    ++list->length;

    assert( (list->length == 1 && list->head == list->tail) || (list->length > 1 && list->head != list->tail));

    return list;
}

Slist* delete_item(Slist *list,int val){
    assert( list != NULL );
    Node *cur = list->head;
    Node *prev;

    //if head node itself key
    if ( cur != NULL && cur->data == val ){
        list->head = cur->next;
        free(cur);
        --list->length;
    }else{
        while (cur != NULL && cur->data != val){
            prev = cur;
            cur = cur->next;
        }
        assert (cur != NULL); // if key found cur will not be nill
        prev->next = cur->next;
        free(cur);
        --list->length;
    }
    return list;
}

Slist* reverse_list(Slist *list){
    assert( list != NULL );
    Node *prev = NULL;
    Node *cur = list->head;
    Node *next;


    while ( cur != NULL ){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    list->tail = list->head;
    list->head = prev;
    return list;
}

int compare_list(Slist *list1,Slist *list2){
    assert( list1 != NULL && list2 != NULL );
    Node *temp1 = list1->head;
    Node *temp2 = list2->head;

    while ( temp1 != NULL && temp2 != NULL ){

        if( temp1->data != temp2->data ){
            return 0;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return (temp1 == NULL && temp2 == NULL );
}

Slist* get_unionlist(Slist *list1,Slist *list2){
    assert( list1 != NULL && list2 != NULL );
    Node *temp1 = list1->head;
    Node *temp2 = list2->head;
    Slist s1 = slist_new();
    Slist *unionlist = &s1;

    //insert all elem of list1 to unoin list
    while( temp1 != NULL ){
        slist_addnode_head(unionlist,temp1->data);
        temp1 = temp1->next;
    }

    //insert elem of list2 which are not in list 1
    while( temp2 != NULL ){
        if ( slist_lookup(unionlist,temp2->data) != 1){
            slist_addnode_head(unionlist,temp2->data);
        }
        temp2 = temp2->next;
    }
    return unionlist;
}

Slist* get_intersectionlist(Slist *list1,Slist *list2){
    assert( list1 != NULL && list2 != NULL );
    Node *temp1 = list1->head;
    Slist s1 = slist_new();
    Slist *intersectionlist = &s1;

    while( temp1 != NULL ){
        if( slist_lookup(list2,temp1->data) == 1){
            slist_addnode_head(intersectionlist,temp1->data);
        }
        temp1 = temp1->next;
    }
    return intersectionlist;
}

Slist* slist_addnode_unique(Slist *list,int32_t val){
    assert(list != NULL );
    if(slist_lookup(list,val) != 1){
        Node *newnode = _get_new_node_(val);

        newnode->next = list->head;
        list->head = newnode;

        if(list->tail == NULL){
        list->tail = newnode;
        }
        ++list->length;

        assert( (list->length == 1 && list->head == list->tail) || (list->length > 1 && list->head != list->tail));
    }
    return list;
}



