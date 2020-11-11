#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"

void test_empty_list(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert (slist_length(list) == 0 );
}

void test_add_at_head(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert (slist_length(list) == 0 );
    list = slist_addnode_head(list,10);
    assert(slist_length(list)==1);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);
    assert(slist_length(list)==3);
    assert(slist_lookup(list,20)==1);


}

void test_delete_at_head(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list,10);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);
    list = slist_delnode_head(list);
    assert(slist_length(list) == 2);
    assert(slist_lookup(list,30)==0);
    assert(slist_lookup(list,20)==1);
    list = slist_addnode_head(list,40);
    list = slist_addnode_head(list,50);
    list = slist_delnode_head(list);
    assert(slist_length(list) == 3);
}

void test_delete_at_tail(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);
    list = slist_delnode_tail(list);
    assert(slist_length(list) == 2);
    assert(slist_lookup(list,30)==0);
    assert(slist_lookup(list,20)==1);
    list = slist_addnode_tail(list,40);
    list = slist_addnode_tail(list,50);
    list = slist_delnode_tail(list);
    assert(slist_length(list) == 4);
}

void test_min_slist(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);
    assert(slist_minimum(list) == 10);
}

void test_max_slist(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);
    assert(slist_maximum(list) == 30);
}

int main()
{
    //printf("Hello world!\n");
    //test_empty_list();
    //test_add_at_head();
    //test_delete_at_head();
    //test_delete_at_tail();
    //test_min_slist();
    test_max_slist();
    return 0;
}
