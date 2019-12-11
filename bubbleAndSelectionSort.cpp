#include <iostream>
using namespace std;

const int ARR_LEN = 20;

void setArr(int[], int);
void copyArr(int[], int[], int);
int bubbleSort(int[], int);
int selectionSort(int[], int);
void results(int, int);

int main() {
    int firstArr[ARR_LEN];
    int secondArr[ARR_LEN];
    int bubbleCount;
    int selectionCount;

    setArr(firstArr, ARR_LEN);
    copyArr(firstArr, secondArr, ARR_LEN);

    bubbleCount = bubbleSort(firstArr, ARR_LEN);
    selectionCount = selectionSort(secondArr, ARR_LEN);

    results(bubbleCount, selectionCount);

    return 0;
}

void setArr(int arr[], int size) {
    cout << "20 nums, please: ";
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void copyArr(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
}

int bubbleSort(int arr[], int size) {
    int temp, count = 0;
    bool swap;

    do {
        swap = false;

        for (int i = 0; i < (size - 1); i++) {
            if (arr[i + 1] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
                count += 1;
            }
        }
    } while (swap);

    cout << "\n\nAfter the bubble sort algorithm, the array looks like: [";
    for (int j = 0; j < size; j++) {
        if (j == (size - 1)) {
            cout << arr[j] << "]\n\n";
            break;
        }
        cout << arr[j] << ", ";
    }
    return count;
}

int selectionSort(int arr[], int size) {
    int startScan, minInd, minVal, count = 0;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minInd = startScan;
        minVal = arr[startScan];
        for (int i = 0; i < size; i++) {
            if (arr[i] < arr[startScan]) {
                minInd = i;
                minVal = arr[i];
                count++;
            }
        }
        arr[minInd] = arr[startScan];
        arr[startScan] = minVal;
    }
    cout << "\n\nAfter the selection sort algorithm, the array looks like: [";
    for (int j = 0; j < size; j++) {
        if (j == (size - 1)) {
            cout << arr[j] << "]\n\n";
            break;
        }
        cout << arr[j] << ", ";
    }
    return count;
}

void results(int bubbleResult, int selectionResult) {
    cout << "The bubble sort algorithm performed the sort in " << bubbleResult << " sorts.\n";
    cout << "The selection sort algorithm performed the sort in " << selectionResult<< " sorts.\n";
}