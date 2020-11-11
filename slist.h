#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED


typedef struct _node_ Node;

struct _node_ {
    int32_t data;
    Node    *next;
};

typedef struct _slist_ Slist;

struct _slist_ {
    Node *head;
    Node *tail;
    int length;
};

//initialise sll
Slist slist_new();
int slist_lookup( const Slist *list, int32_t key);
int slist_length(const Slist *list);
Slist* slist_addnode_head(Slist *list,int32_t val);
Slist* slist_addnode_tail(Slist *list,int32_t val);
Slist* slist_delnode_head(Slist *list);
Slist* slist_delnode_tail(Slist *list);
int slist_minimum(const Slist *list);
int slist_maximum(const Slist *list);


#endif // SLIST_H_INCLUDED
