#include <iostream>
#include <vector>
#include <fstream>


void showVector(std::vector<int> arr) {

    std::ofstream file("out.txt", std::ofstream::app);

    for (int i : arr) {
        file << i << " ";
    }
    file << "\n";

    file.close();

}

void ascendingShellSort(std::vector<int> arr) {

    int n = arr.size();

    int gap = n / 2;
    do {

        int i = gap;
        do {

            int temp = arr[i];

            int j = i;
            do {
                if (arr[j - gap] > temp) {
                    showVector(arr);
                    std::swap(arr[j - gap], arr[j]);
                    std::cout << "\n";
                }


                j -= gap;
            } while (j >= gap && arr[j - gap] > temp);

            i++;
        } while (i < n);

        gap /= 2;
    } while (gap > 0);


    std::cout << "Vectorul sortat ascendent:\n\t";
    showVector(arr);

}

void descendingShellSort(std::vector<int> arr) {

    int n = arr.size();

    int gap = n / 2;
    do {

        int i = gap;
        do {

            int temp = arr[i];

            int j = i;
            do {
                if (arr[j - gap] < temp)
                    std::swap(arr[j - gap], arr[j]);

                j -= gap;
            } while (j >= gap && arr[j - gap] < temp);

            i++;
        } while (i < n);

        gap /= 2;
    } while (gap > 0);


    std::cout << "Vectorul sortat descendent:\n\t";
    showVector(arr);

}

int main() {

    std::vector<int> arr1{ 1, 2, 0, 6, 2, 0, 0, 2, 0, 6, 8, 8, 8, 2, 2, 1, 0 };
    std::cout << "Vectorul sortat ascendent:\n";
    ascendingShellSort(arr1);

    return 0;
}
