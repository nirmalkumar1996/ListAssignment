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

void test_addnode_after(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list,10);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);
    assert(slist_length(list) == 3);
    list = slist_addnode_after(list,40,20);
    assert(slist_length(list) == 4);
    assert(slist_lookup(list,40)==1);

}

void test_delete_item(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    list = slist_addnode_head(list,10);
    list = slist_addnode_head(list,20);
    list = slist_addnode_head(list,30);
    assert(slist_length(list) == 3);
    assert(slist_lookup(list,20)==1);
    list = delete_item(list,20);
    assert(slist_length(list) == 2);
    assert(slist_lookup(list,20)== 0);

}

void test_reverse_list(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    Slist *rev_list;
    list = slist_addnode_tail(list,10);
    list = slist_addnode_tail(list,20);
    list = slist_addnode_tail(list,30);
    rev_list = reverse_list(list);
    assert(rev_list->head->data == 30);
}

void test_compare_list(){
    Slist s1 = slist_new();
    Slist *list1 = &s1;
    Slist s2 = slist_new();
    Slist *list2 = &s2;
    list1 = slist_addnode_head(list1,10);
    list1 = slist_addnode_head(list1,20);
    list1 = slist_addnode_head(list1,30);
    assert(slist_length(list1) == 3);
    list2 = slist_addnode_head(list2,10);
    list2 = slist_addnode_head(list2,20);
    list2 = slist_addnode_head(list2,30);
    assert(compare_list(list1,list2) == 1 );
}

void test_union_list(){
    Slist s1 = slist_new();
    Slist *list1 = &s1;
    Slist s2 = slist_new();
    Slist *list2 = &s2;
    Slist *unionlist;
    list1 = slist_addnode_head(list1,10);
    list1 = slist_addnode_head(list1,20);
    list1 = slist_addnode_head(list1,30);
    assert(slist_length(list1) == 3);
    list2 = slist_addnode_head(list2,10);
    list2 = slist_addnode_head(list2,20);
    list2 = slist_addnode_head(list2,40);
    unionlist = get_unionlist(list1,list2);
    assert(slist_length(unionlist) == 4);
}

void test_intersection_list(){
    Slist s1 = slist_new();
    Slist *list1 = &s1;
    Slist s2 = slist_new();
    Slist *list2 = &s2;
    Slist *intersectionlist;
    list1 = slist_addnode_head(list1,10);
    list1 = slist_addnode_head(list1,20);
    list1 = slist_addnode_head(list1,30);
    assert(slist_length(list1) == 3);
    list2 = slist_addnode_head(list2,10);
    list2 = slist_addnode_head(list2,20);
    list2 = slist_addnode_head(list2,40);
    intersectionlist = get_intersectionlist(list1,list2);
    assert(slist_length(intersectionlist) == 2);
    assert(slist_lookup(intersectionlist,10) == 1);
}

void test_addnode_unique(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert (slist_length(list) == 0 );
    list = slist_addnode_unique(list,10);
    assert(slist_length(list)==1);
    list = slist_addnode_unique(list,20);
    list = slist_addnode_unique(list,30);
    assert(slist_length(list)==3);
    assert(slist_lookup(list,20)==1);
    list = slist_addnode_unique(list,30);
    assert(slist_length(list)==3);
}

int main()
{
    //printf("Hello world!\n");
    //test_empty_list();
    //test_add_at_head();
    //test_delete_at_head();
    //test_delete_at_tail();
    //test_min_slist();
    //test_max_slist();
    //test_addnode_after();
    //test_delete_item();
    //test_reverse_list();
    //test_compare_list();
    //test_union_list();
    //test_intersection_list();
    test_addnode_unique();
    return 0;
}
