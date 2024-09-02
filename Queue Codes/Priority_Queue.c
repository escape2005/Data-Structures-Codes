#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

void enqueue(int a, int p);
void dequeue();
void display();
int isEmpty();

int main() {
    int choice, val, pri;

    while (1) {
        printf("\n1. ENQUEUE\n");
        printf("\n2. DEQUEUE\n");
        printf("\n3. DISPLAY\n");
        printf("\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &val);
            printf("Enter the priority of the value: ");
            scanf("%d", &pri);
            enqueue(val, pri);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Enter again.\n");
        }
    }
    return 0;
}

void enqueue(int a, int p) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = front;
    struct node *prev = NULL;

    newnode->data = a;
    newnode->priority = p;
    newnode->next = NULL;

    if (front == NULL || front->priority > p) {
        newnode->next = front;
        front = newnode;
    } else {
        while (temp != NULL && temp->priority <= p) {
            prev = temp;
            temp = temp->next;
        }
        newnode->next = temp;
        prev->next = newnode;
    }

    printf("Element %d with priority %d was added successfully.\n", a, p);
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow: Queue is empty.\n");
    } else {
        struct node *temp = front;
        printf("Element %d with priority %d was deleted.\n", temp->data, temp->priority);
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct node *temp = front;
        printf("Queue elements are:\n");
        while (temp != NULL) {
            printf("Value: %d | Priority: %d\n", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}

int isEmpty() {
    return front == NULL;
}
