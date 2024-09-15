#include <stdio.h>
#include <stdlib.h>
#include "cstack.h"

struct person {
    char *name;
    int age;
    struct cstack stack_head;
};

int main() {
    STACK_HEAD(person_head);

    struct person* person;
    person = calloc(1, sizeof(*person));
    person->age=10;
    person->name="Tom";
    stack_push(&person_head,&person->stack_head);

    struct person* person2;
    person2=calloc(1, sizeof(*person2));
    person2->age=20;
    person2->name="andy";
    stack_push(&person_head,&person2->stack_head);

    printf("test get_stack_size %d\n\n",stack_get_size(&person_head));

    struct cstack* stack_pos;
    stack_get_top(&person_head,&stack_pos);
    struct person* pos=stack_entry(stack_pos,struct person, stack_head);
    printf("name:%s  \nage:%d  \n\n",pos->name,pos->age);
    stack_pop(&person_head);

    stack_get_top(&person_head,&stack_pos);
    pos=stack_entry(stack_pos,struct person, stack_head);
    printf("name:%s  \nage:%d  \n\n",pos->name,pos->age);

    printf("test get_stack_size %d\n\n",stack_get_size(&person_head));
    stack_pop(&person_head);

    printf("stack is empty %d\n",stack_empty(&person_head));
    return 0;
}
