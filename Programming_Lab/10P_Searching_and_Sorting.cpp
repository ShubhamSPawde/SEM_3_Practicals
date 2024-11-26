#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = partition(arr, low, high);
    QuickSort(arr, low, pivot - 1);
    QuickSort(arr, pivot + 1, high);
}


// Fibonacci Search Function
int fibonacciSearch(int arr[], int n, int x) {
    // Initialize Fibonacci numbers
    int fib2 = 0;  // (m-2)'th Fibonacci number
    int fib1 = 1;  // (m-1)'th Fibonacci number
    int fibM = fib2 + fib1;  // m'th Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    // Marks the eliminated range from the front
    int offset = -1;

    // While there are elements to inspect
    while (fibM > 1) {
        // Check if fib2 is a valid index
        int i = min(offset + fib2, n - 1);

        // If x is greater than the value at index i, cut the subarray after i
        if (arr[i] < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        // If x is less than the value at index i, cut the subarray before i
        else if (arr[i] > x) {
            fibM = fib2;
            fib1 -= fib2;
            fib2 = fibM - fib1;
        }
        // Element found
        else {
            return i;
        }
    }

    // Compare the last element with x
    if (fib1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    // Element not found
    return -1;
}



int main() {
    srand(time(0));

    const int size = 7;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }

    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    InsertionSort(arr, size);
    cout << "Insertion Sort: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }

    SelectionSort(arr, size);
    cout << "Selection Sort: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }

    BubbleSort(arr, size);
    cout << "Bubble Sort: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }

    QuickSort(arr, 0, size - 1);
    cout << "QuickSort: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
