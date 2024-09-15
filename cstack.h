#ifndef MY_CLIB_STACK_H
#define MY_CLIB_STACK_H
#include "list.h"

#define cstack list_head
#define STACK_HEAD(name) LIST_HEAD(name)

#define stack_entry(ptr,type,member) \
        list_entry(ptr, type, member)

int stack_create(struct list_head *head);
int stack_push(struct list_head *head, struct list_head *node);
int stack_pop(struct list_head *head,void(*pointer_free)(struct list_head *));
int stack_get_size(struct list_head *head);
int stack_empty(struct list_head *head);
int stack_get_top(struct list_head *head,struct list_head **entry);
int stack_all_free(struct list_head *head,void(*pointer_free)(struct list_head *));

#endif /* MY_CLIB_STACK_H */
