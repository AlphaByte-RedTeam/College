#include <iostream>
#include <vector>
#include <functional>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

bool ascending(int a, int b) {
	return a > b;
}

bool descending(int a, int b) {
	return a < b;
}

void fillArray(std::vector<int> &arr) {
	int size;
	std::cout << "How much size of array : ";
	std::cin >> size;

	arr.resize(size);

	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << "#" << i << " Input : ";
		std::cin >> arr[i];
	}
}

void sort(std::vector<int> &arr, std::function<bool(int a, int b )> order = ascending) {
	for (int i = 0; i < arr.size(); i++)
	{
		bool isSorted = true;
		for (int j = 0; j < (arr.size() - 1) - i; j++)
		{
			if (order(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
				isSorted = false;
			}
		}
		if (isSorted) {
			break;
		}
	}
}

void print(const std::vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n\n";
}

int main() {
	std::vector<int> arr;
	fillArray(arr);

	system("cls");
	//before sort
	std::cout << "Before sort : \n";
	print(arr);

	sort(arr);

	//after sort
	std::cout << "after sort ascending : \n";
	print(arr);

	sort(arr, descending);

	std::cout << "after sort descending : \n";
	print(arr);

	return 0;
}