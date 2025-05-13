#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} node;

node *push(node *top, int data);
node *pop(node *top);
void list(node *top);

int main(void)
{
    int tmp, count;
    node *top = NULL;

    while (1)
    {
        printf("push->1, pop->2, list->3, end->4\n>>");
        scanf("%d", &tmp);

        switch (tmp)
        {
        case 1:
            printf(">>");
            scanf("%d",&count);
            top = push(top, count);
            break;
        case 2:
            if (top == NULL) break;
            top = pop(top);
            break;
        case 4:
            return 0;
        default:
            break;
        }
        list(top);
    }
}

node *push(node *top, int data)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = top;
    return p;
}

node *pop(node *top)
{
    node *tmp;
    tmp = top->next;
    free(top);
    return tmp;
}

void list(node *top)
{
    printf("top> ");
    node *now = top;
    while (now != NULL)
    {
        printf("%d ", now->data);
        now = now->next;
    }
    printf("<bottom\n\n");
}