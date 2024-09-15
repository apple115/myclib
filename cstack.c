#include "cstack.h"
#include "list.h"

int stack_create(struct list_head *head) {
    if( head == NULL) {
        return -1;
    }
    list_head_init(head);
    return 0;
}

int stack_push(struct list_head *head, struct list_head *node) {
    if(head == NULL)  return -1;
    if(node == NULL)  return -1;
    list_add_tail(node, head);
    return 0;
}

int stack_pop(struct list_head *head, void(*pointer_free)(struct list_head *)) {
    if(head == NULL)  return -1;
    if (stack_empty(head))  return -1;
    struct list_head *entry = head->prev;
    list_del(head->prev);
    list_head_init(entry);
    pointer_free(entry);
    return 0;
}

int stack_get_size(struct list_head *head) {
    struct list_head *pos;
    int size = 0;
    if (head==NULL)   return -1;
    list_for_each(pos, head) {
        size++;
    }
    return size;
}

int stack_empty(struct list_head *head) {
    return list_empty(head);
}

int stack_get_top(struct list_head *head, struct list_head **entry) {
    *entry = head->prev;
    return 0;
}

int stack_all_free(struct list_head *head, void (*pointer_free)(struct list_head *)) {
    if(head == NULL)  return -1;
    struct list_head *pos;
    list_for_each(pos, head) {
        pointer_free(pos);
    }
    return 0;
}
