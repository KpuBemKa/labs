#include "sort.h"

int main() {

	std::vector<int> arr1 = { 1, 2, 0, 6, 2, 0, 0, 2, 0, 6, 8, 8, 8, 2, 2, 1, 0 };
	std::vector<int> arr2 = { 81, 56, 78, 70, 28, 95, 27, 23, 26, 91 };
	std::vector<int> arr3 = { 49, 63, 64, 54, 98, 14, 67, 55, 60, 58 };
	std::vector<int> arr4 = { 20, 33, 45, 82, 66, 15, 57, 47, 69, 24 };

	/*sort::sortAscending(arr1, true);
	std::cout << "\n";*/
	std::cout << "quickSort:\n";
	sort::quickSort(arr1, false);

	/*sort::sortAscending(arr3, true);
	std::cout << "\n";
	sort::sortAscending(arr4, false);
	std::cout << "\n";*/

}
