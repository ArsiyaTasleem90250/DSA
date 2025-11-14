#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;
int queue[MAX], front = -1, rear = -1;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST* root = NULL;

void push(int x) {
    if (top == MAX-1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void enqueue(int x) {
    if (rear == MAX-1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void insertList(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = head;
    head = n;
}

void displayList() {
    struct Node* t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

struct BST* insertBST(struct BST* r, int x) {
    if (!r) {
        r = malloc(sizeof(struct BST));
        r->data = x;
        r->left = r->right = NULL;
        return r;
    }
    if (x < r->data) r->left = insertBST(r->left, x);
    else r->right = insertBST(r->right, x);
    return r;
}

void inorder(struct BST* r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1 Push\n2 Pop\n3 Enqueue\n4 Dequeue\n5 Insert Linked List\n6 Display Linked List\n7 Insert BST\n8 Display BST (Inorder)\n9 Exit\n");
        scanf("%d", &ch);

        if (ch == 9) break;

        switch (ch) {
            case 1: scanf("%d", &x); push(x); break;
            case 2: printf("%d\n", pop()); break;
            case 3: scanf("%d", &x); enqueue(x); break;
            case 4: printf("%d\n", dequeue()); break;
            case 5: scanf("%d", &x); insertList(x); break;
            case 6: displayList(); break;
            case 7: scanf("%d", &x); root = insertBST(root, x); break;
            case 8: inorder(root); printf("\n"); break;
            default: break;
        }
    }
    return 0;
}
