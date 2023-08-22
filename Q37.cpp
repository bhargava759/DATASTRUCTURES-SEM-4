#include <stdio.h>

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int num_elements;
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    int arr_heap[num_elements], arr_merge[num_elements], arr_insertion[num_elements], arr_quick[num_elements];

    printf("Enter %d elements:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &arr_heap[i]);
        arr_merge[i] = arr_heap[i];
        arr_insertion[i] = arr_heap[i];
        arr_quick[i] = arr_heap[i];
    }

    heapSort(arr_heap, num_elements);
    mergeSort(arr_merge, 0, num_elements - 1);
    insertionSort(arr_insertion, num_elements);
    quickSort(arr_quick, 0, num_elements - 1);

    printf("Heap Sorted array: ");
    for (int i = 0; i < num_elements; i++)
        printf("%d ", arr_heap[i]);
    printf("\n");

    printf("Merge Sorted array: ");
    for (int i = 0; i < num_elements; i++)
        printf("%d ", arr_merge[i]);
    printf("\n");

    printf("Insertion Sorted array: ");
    for (int i = 0; i < num_elements; i++)
        printf("%d ", arr_insertion[i]);
    printf("\n");

    printf("Quick Sorted array: ");
    for (int i = 0; i < num_elements; i++)
        printf("%d ", arr_quick[i]);
    printf("\n");

    return 0;
}

