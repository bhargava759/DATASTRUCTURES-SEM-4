#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;

void append(int num) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    struct node* right = head;
    while (right->next != NULL)
        right = right->next;

    right->next = temp;
}

void add(int num) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = head;
    head = temp;
}

void addafter(int num, int loc) {
    if (loc <= 0) {
        printf("Invalid location.\n");
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < loc; i++) {
        if (temp == NULL) {
            printf("Location is out of bounds.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Location is out of bounds.\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = temp->next;
    temp->next = newNode;
}

int getCount() {
    struct node* n = head;
    int count = 0;
    while (n != NULL) {
        n = n->next;
        count++;
    }
    return count;
}

void deleteNode(int num) {
    struct node* temp = head;
    struct node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == num) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("%d deleted successfully\n", num);
            return;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    printf("%d not found in the list\n", num);
}

void display() {
    struct node* current = head;
    if (current == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("Elements in the list are: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, num, loc;

    while (1) {
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1. Append\n");
        printf("2. Display\n");
        printf("3. Size\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to append: ");
                scanf("%d", &num);
                append(num);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Size of the list is %d\n", getCount());
                break;
            case 4:
                if (head == NULL) {
                    printf("List is Empty\n");
                } else {
                    printf("Enter the number to delete: ");
                    scanf("%d", &num);
                    deleteNode(num);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}

