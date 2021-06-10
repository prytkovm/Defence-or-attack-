#ifndef DEFENCE_LISTS_H
#define DEFENCE_LISTS_H

typedef struct linear_list
{
    int val;
    struct linear_list *next;
}node_l;

typedef struct two_sided_list
{
    int val;
    struct two_sided_list *next, *prev;
}node_tw;

node_l *add_to_list(node_l *current, int data)
{
    if (current == NULL)
    {
        current = (node_l*)malloc(sizeof(node_l));
        if (current == NULL)
            return NULL;
        current->val = data;
        current->next = NULL;
    }
    else
    {
        current->next = add_to_list(current->next, data);
        if (current->next == NULL)
            return NULL;
    }
    return current;
}

void delete_list(node_l *current)
{
    if (current != NULL)
    {
        delete_list(current->next);
        free(current);
    }
}

void delete_two_sided_list(node_tw *current)
{
    if (current != NULL)
    {
        delete_two_sided_list(current->next);
        free(current);
    }
}

void print_list(node_l *head)
{
    node_l *current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

node_tw *add_to_two_sided_list(node_tw *head, int data)
{
    node_tw *current = head;
    if (current != NULL)
    {
        while (current->next != NULL)
            current = current->next;
        current->next = (node_tw*)malloc(sizeof(node_tw));
        if (current->next == NULL)
            return NULL;
        current->next->next = NULL;
        current->next->prev = current;
        current->next->val = data;
    }
    else
    {
        head = (node_tw*)malloc(sizeof(node_tw));
        if (head == NULL)
            return NULL;
        head->prev = head->next = NULL;
        head->val = data;
    }
    return head;
}

void print_two_sided_list(node_tw *head)
{
    node_tw *current = head, *temp;
    printf("Forward: ");
    while (current != NULL)
    {
        temp = current;
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\nBackward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->prev;
    }
    printf("\n");
}

#endif
