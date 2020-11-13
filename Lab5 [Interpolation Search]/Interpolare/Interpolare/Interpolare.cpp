#include <iostream>
#include <algorithm>
#include <vector>

void showVector(std::vector<int> arr) {

    for (int v : arr) {
        std::cout << v << " ";
    }

    std::cout << "\n";

}

std::vector<int> bubbleSort(std::vector<int> arr) {

    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1; j++) {

            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);

        }
    }

    return arr;

}

std::vector<int> insertionSort(std::vector<int> arr) {

    for (int i = 1; i < arr.size(); i++) {
        
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;

    }

    return arr;

}

std::vector<int> selectionSort(std::vector<int> arr) {

    for (int i = 0; i < arr.size(); i++) {

        int minElementIndex = i;

        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minElementIndex])
                minElementIndex = j;
        }

        std::swap(arr[minElementIndex], arr[i]);

    }

    return arr;

}

int interpolationSearch(std::vector<int> arr, int x)
{

    int lo = 0, hi = (arr.size() - 1);

    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x) return lo;
            return -1;
        }

        int pos = lo + ( ( (double)(hi - lo) / (arr[hi] - arr[lo]) ) * (x - arr[lo]) );

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            lo = pos + 1; 
        else
            hi = pos - 1;
    }

    return -1;
}

int main() {

    std::vector<int> bubbleVector = { 36, 66, 44, 49, 12, 19, 46, 70, 77, 88 };
    int x1 = 66;

    std::vector<int> insertionVector = { 14, 24, 94, 80, 37, 95, 48, 38, 50, 40 };
    int x2 = 40;

    std::vector<int> selectionVector = { 14, 24, 94, 80, 37, 95, 48, 38, 50, 40 };
    int x3 = 48;

    // vectorul 1, folosind metoda bulelor
    std::cout << "Vectorul 1:\n";
    showVector(bubbleVector);

    std::cout << "Vectorul sortat:\n";
    bubbleVector = bubbleSort(bubbleVector);
    showVector(bubbleVector);

    std::cout << "Elementul " << x1 << " se afla pe pozitita " << interpolationSearch(bubbleVector, x1) << ".\n";

    // vectorul 2, folosind metoda inserției
    std::cout << "\nVectorul 2:\n";
    showVector(insertionVector);

    std::cout << "Vectorul sortat:\n";
    insertionVector = insertionSort(insertionVector);
    showVector(insertionVector);

    std::cout << "Elementul " << x2 << " se afla pe pozitita " << interpolationSearch(insertionVector, x2) << ".\n";

    // vectorul 3, folosind metoda selecției
    std::cout << "\nVectorul 3:\n";
    showVector(selectionVector);

    std::cout << "Vectorul sortat:\n";
    selectionVector = selectionSort(selectionVector);
    showVector(selectionVector);

    std::cout << "Elementul " << x3 << " se afla pe pozitita " << interpolationSearch(selectionVector, x3) << ".\n";

}