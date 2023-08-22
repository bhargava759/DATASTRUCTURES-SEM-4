#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct Node {
    char data;
    struct Node* next;
};

void insert(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool isPalindrome(struct Node* head, char* str) {
    struct Node* current = head;
    int index = 0;

    while (current != NULL) {
        if (current->data != str[index]) {
            return false;
        }
        current = current->next;
        index++;
    }
    
    return true;
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        insert(&head, input[i]);
    }

    if (isPalindrome(head, input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    freeList(head);

    return 0;
}

