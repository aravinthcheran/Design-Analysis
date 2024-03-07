#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct minheapnode{
    char data;
    int freq;
    struct minheapnode *left, *right;
};

struct minheap
{
    int capacity;
    struct minheapnode **stack;
    int stackpointer;
};

struct minheapnode *newnode(char data, int freq)
{
    struct minheapnode *temp = (struct minheapnode*)malloc(sizeof(struct minheapnode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct minheap *createMinHeap(int capacity)
{
    struct minheap *p = (struct minheap*)malloc(sizeof(struct minheap));
    p->capacity = capacity;
    p->stack = (struct minheapnode**)malloc(p->capacity * sizeof(struct minheapnode*));
    p->stackpointer = -1;
    return p;
}

void swapnode(struct minheapnode **a, struct minheapnode **b)
{
    struct minheapnode *t = *a;
    *a = *b;
    *b = t;
}

void printCodes(struct minheapnode* root, char arr[], int top)
{
    if (root->left)
    {
        arr[top] = '0';
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = '1';
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right))
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%c", arr[i]);
        printf("\n");
    }
}

void sort(struct minheap *p)
{
    int i = 0;
    while (i < p->stackpointer)
    {
        int j = 0;
        int flag = 0;
        while (j < (p->stackpointer - 1))
        {
            if (p->stack[j]->freq < p->stack[j + 1]->freq)
            {
                swapnode(&p->stack[j], &p->stack[(j + 1)]);
                j++;
                flag = 1;
            }
            if (flag == 0)
                break;
        }
        i++;
    }
}

void huffman(struct minheap *p)
{
    while (p->stackpointer != 1)
    {
        sort(p);
        struct minheapnode *left = p->stack[0];
        p->stackpointer--;
        struct minheapnode *right = p->stack[1];
        p->stackpointer--;
        struct minheapnode *top = newnode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        p->stackpointer++;
        p->stack[p->stackpointer] = top;
    }

    printf("The huffman tree is created\n");
    printf("The codes are:\n");
    printCodes(p->stack[0], "", 0);
}

int main()
{
    printf("Enter the no of characters:");
    int n;
    scanf("%d", &n);
    struct minheap *p = createMinHeap(n);
    printf("Enter the characters and their frequencies in the format: character frequency\n");
    for (int i = 0; i < n; i++)
    {
        char c;
        int f;
        scanf(" %c %d", &c, &f); 
        p->stackpointer++;
        p->stack[p->stackpointer] = newnode(c, f);
    }
    huffman(p);
    return 0;
}