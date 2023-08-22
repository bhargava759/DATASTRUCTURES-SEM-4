#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int findLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    int len1 = findLength(list1);
    int len2 = findLength(list2);

    while (len1 > len2) {
        list1 = list1->next;
        len1--;
    }
    while (len2 > len1) {
        list2 = list2->next;
        len2--;
    }

    while (list1 != list2) {
        list1 = list1->next;
        list2 = list2->next;
    }

    return list1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n1, n2;

    printf("Enter the number of nodes in the first list: ");
    scanf("%d", &n1);

    printf("Enter the elements of the first list:\n");
    for (int i = 0; i < n1; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = list1;
        list1 = newNode;
    }

    printf("Enter the number of nodes in the second list: ");
    scanf("%d", &n2);

    printf("Enter the elements of the second list:\n");
    for (int i = 0; i < n2; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = list2;
        list2 = newNode;
    }

    struct Node* intersection = findIntersection(list1, list2);

    if (intersection) {
        printf("Intersection point data: %d\n", intersection->data);
    } else {
        printf("No intersection found.\n");
    }

    while (list1 != NULL) {
        struct Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        struct Node* temp = list2;
        list2 = list2->next;
        free(temp);
    }

    return 0;
}

