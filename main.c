#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include "trees.h"
#include "lists.h"

#define MAX_CYCLE 10

int main()
{
    /* Функции и структуры в заголовочных файлах
     * Что было в голосовых, то есть тут (вроде) */
    node_t *root = NULL; // Дерево
    node_l *head = NULL; // Односвязный список
    node_tw *twin_head = NULL; // Двухсвязный список
    int value;
    srand(time(NULL));
    for (int i = 0; i < MAX_CYCLE; i++)
    {
        value = rand() % 100;
        root = add_to_tree(root, value);
        head = add_to_list(head, value);
        twin_head = add_to_two_sided_list(twin_head, value);
    }
    printf("Here is a linked list: ");
    print_list(head);
    printf("Here is a two-sided list:\n");
    print_two_sided_list(twin_head);
    printf("Here are 3 tree walks:\n");
    printf("Preorder:\n");
    preorder(root);
    printf("Inorder:\n");
    inorder(root);
    printf("Postorder:\n");
    postorder(root);
    delete_list(head);
    delete_two_sided_list(twin_head);
    delete_tree(root);
    return 0;
}
