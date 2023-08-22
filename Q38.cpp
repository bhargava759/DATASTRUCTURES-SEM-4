#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10

struct DirectAddressTable {
    int table[TABLE_SIZE];
};

int divisionHash(int key) {
    return key % TABLE_SIZE;
}

int multiplicationHash(int key) {
    float A = (sqrt(5) - 1) / 2;
    return (int)(TABLE_SIZE * (key * A - (int)(key * A)));
}

struct OpenAddressingTable {
    int table[TABLE_SIZE];
};

void initOpenAddressingTable(struct OpenAddressingTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++)
        table->table[i] = -1;
}

int linearProbingHash(int key, int attempt) {
    return (divisionHash(key) + attempt) % TABLE_SIZE;
}

void insertLinearProbing(struct OpenAddressingTable *table, int key) {
    int index = divisionHash(key);
    int attempt = 0;

    while (table->table[index] != -1) {
        attempt++;
        index = linearProbingHash(key, attempt);
    }

    table->table[index] = key;
}

int searchLinearProbing(struct OpenAddressingTable *table, int key) {
    int index = divisionHash(key);
    int attempt = 0;

    while (table->table[index] != -1) {
        if (table->table[index] == key)
            return index;
        attempt++;
        index = linearProbingHash(key, attempt);
    }

    return -1;
}

int main() {
    // Direct Addressing
    struct DirectAddressTable directTable;
    for (int i = 0; i < TABLE_SIZE; i++)
        directTable.table[i] = -1;

    int numDirectElements;
    printf("Enter the number of elements for Direct Addressing: ");
    scanf("%d", &numDirectElements);

    printf("Enter %d elements for Direct Addressing:\n", numDirectElements);
    for (int i = 0; i < numDirectElements; i++) {
        int key, value;
        scanf("%d %d", &key, &value);
        directTable.table[key] = value;
    }

    int divisionKey;
    printf("Enter the key for Division Hashing: ");
    scanf("%d", &divisionKey);

    int divisionIndex = divisionHash(divisionKey);
    printf("Division Hashing: Key %d maps to index %d\n", divisionKey, divisionIndex);

    int multiplicationKey;
    printf("Enter the key for Multiplication Hashing: ");
    scanf("%d", &multiplicationKey);

    int multiplicationIndex = multiplicationHash(multiplicationKey);
    printf("Multiplication Hashing: Key %d maps to index %d\n", multiplicationKey, multiplicationIndex);

    struct OpenAddressingTable openAddressingTable;
    initOpenAddressingTable(&openAddressingTable);

    int numOpenAddressingElements;
    printf("Enter the number of elements for Open Addressing: ");
    scanf("%d", &numOpenAddressingElements);

    printf("Enter %d elements for Open Addressing:\n", numOpenAddressingElements);
    for (int i = 0; i < numOpenAddressingElements; i++) {
        int key;
        scanf("%d", &key);
        insertLinearProbing(&openAddressingTable, key);
    }

    int searchKey;
    printf("Enter the key to search in Open Addressing: ");
    scanf("%d", &searchKey);

    int searchResult = searchLinearProbing(&openAddressingTable, searchKey);
    if (searchResult != -1)
        printf("Key %d found at index %d in Open Addressing\n", searchKey, searchResult);
    else
        printf("Key %d not found in Open Addressing\n", searchKey);

    return 0;
}

