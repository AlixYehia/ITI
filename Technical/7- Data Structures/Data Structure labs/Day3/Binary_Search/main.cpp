#include <iostream>
using namespace std;

class BinarySearch
{
private:
    int* array;
    int size;

public:

    BinarySearch(int* inputArray, int inputSize)
    {
        size = inputSize;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = inputArray[i];
        }
    }

    // Destructor to release dynamically allocated memory
    ~BinarySearch()
    {
        delete[] array;
    }

    /// Binary Search function that returns the index of the target element
    int search(int target)
    {
        int left = 0;
        int right = size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;  // Calculate middle index

            // If the target is at the mid return index
            if (array[mid] == target)
            {
                return mid;
            }
            // If target is smaller, ignore the right half
            else if (array[mid] > target)
            {
                right = mid - 1;
            }
            // If target is larger, ignore the left half
            else {
                left = mid + 1;
            }
        }

        return -1;
    }

    // Getter for the array
    int* getArray() const
    {
        return array;
    }

    // Getter for the size of the array
    int getSize() const
    {
        return size;
    }
};

int main() {
    int inputArray[7] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int target = 4;

    BinarySearch searcher(inputArray, size);

    int result = searcher.search(target);

    if (result != -1)
    {
        cout << "Target element " << target << " found at index " << result << endl;
    }
    else
    {
        cout << "Target element " << target << " not found in the array." << endl;
    }

    return 0;
}
