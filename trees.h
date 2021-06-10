#ifndef DEFENCE_TREES_H
#define DEFENCE_TREES_H

typedef struct tree_node
{
    int val;
    struct tree_node *left, *right;
}node_t;

void preorder(node_t *current)
{
    if (current != NULL)
    {
        printf("%d\n", current->val);
        preorder(current->left);
        preorder(current->right);
    }
}

void inorder(node_t *current)
{
    if (current != NULL)
    {
        inorder(current->left);
        printf("%d\n", current->val);
        inorder(current->right);
    }

}

void postorder(node_t *current)
{
    if (current != NULL)
    {
        postorder(current->left);
        postorder(current->right);
        printf("%d\n", current->val);
    }
}

node_t *add_to_tree(node_t *current, int data)
{
    if (current == NULL)
    {
        current = (node_t*)malloc(sizeof(node_t));
        if (current == NULL)
            return NULL;
        current->left = current->right = NULL;
        current->val = data;
    }
    else if (data <= current->val)
    {
        current->left = add_to_tree(current->left, data);
        if (current->left == NULL)
            return NULL;
    }
    else
    {
        current->right = add_to_tree(current->right, data);
        if (current->right == NULL)
            return NULL;
    }
    return current;
}

void delete_tree(node_t *current)
{
    if (current != NULL)
    {
        delete_tree(current->left);
        delete_tree(current->right);
        free(current);
    }
}

#endif
