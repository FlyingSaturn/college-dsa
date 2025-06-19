#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

node* push(node* root, int data);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
void free_tree(node* root);

int main()
{
    node* tree1 = NULL;
    int op, d;
    while (true)
    {
        printf("\nEnter your choice:\n 1. Push\n 2. Inorder\n 3. Preorder\n 4. Postorder\n 5. Exit\nOption: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &d);
                tree1 = push(tree1, d);
                break;
            case 2:
                if (tree1 == NULL)
                {
                    printf("Push a node before trying to traverse.\n");
                    break;
                }
                printf("The in-order traversal:\n");
                inorder(tree1);
                break;
            case 3:
                if (tree1 == NULL)
                {
                    printf("Push a node before trying to traverse.\n");
                    break;
                }
                printf("The pre-order traversal:\n");
                preorder(tree1);
                break;
            case 4:
                if (tree1 == NULL)
                {
                    printf("Push a node before trying to traverse.\n");
                    break;
                }
                printf("The post-order traversal:\n");
                postorder(tree1);
                break;
            case 5:
                break;
            default:
                printf("Invalid case. Please try again.\n");
        }
        if (op == 5)
        {
            free_tree(tree1);
            return 0;
        }
    }
}

node* push(node* root, int data)
{
    node* nd = (node*) malloc(sizeof(node));
    if (nd == NULL)
    {
        printf("Can't alloc. Exitting...\n");
        exit(1);
    }
    nd->data = data;
    nd->left = NULL;
    nd->right = NULL;

    if (root == NULL)
    {
        root = nd;
        return root;
    }

    node* ptr = root;
    node* visited;
    int direct = -1;
    // Similar to ptr and preptr in linked lists
    while (ptr != NULL)
    {
        visited = ptr;
        if (data < ptr->data)
        {
            ptr = ptr->left;
            direct = 0;
        }
        else if (data > ptr->data)
        {
            ptr = ptr->right;
            direct = 1;
        }
    }
    if (direct == 0)
        visited->left = nd;
    if (direct == 1)
        visited->right = nd;
    return root;
}


void inorder(node* root)
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d\n", root->data);

    inorder(root->right);
}

void preorder(node* root)
{
    if (root == NULL) return;
    preorder(root->left);
    printf("%d\n", root->data);
    preorder(root->right);
}

void postorder(node* root)
{
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->data);
}

void free_tree(node* root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
