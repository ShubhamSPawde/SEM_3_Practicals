#include <bits/stdc++.h>
using namespace std;


void InsertionSort(vector<int>& vec) {
    for(int i = 1; i<vec.size(); i++){
        int j = i;
        while(j > 0 && vec[j-1] > vec[j]){
            swap(vec[j], vec[j-1]);
            j--;
        }
    }
}

void SelectionSort(vector<int>& arr) {
    for(int i = 0; i<arr.size(); i++){
        int minIndex = i;
        for(int j = i + 1; j<arr.size(); j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void BubbleSort(vector<int>& arr){
    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j<arr.size()- i -1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vector<int>& arr, int low, int high){
    if(low>high){
        return;
    }
    
    int pivot = partition(arr, low, high);
    QuickSort(arr, low, pivot-1);
    QuickSort(arr, pivot+1, high);
}

int main() {
    srand(time(0));

    const int size = 7;
    vector<int> vec(size);

    for (int i = 0; i < size; ++i) {
        vec[i] = rand() % 100;
    }

    cout << "Vector: ";
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    InsertionSort(vec);
    
    cout<< "Insertion Sort : ";    
    
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    SelectionSort(vec);
    
    cout<< "Selection Sort : ";    
    
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    BubbleSort(vec);

     cout<< "BubbleSort Sort : ";    
    
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    QuickSort(vec, 0, 7);

     cout<< "QuickSort Sort : ";    
    
    for (int i = 0; i < size; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;


    return 0;
}
