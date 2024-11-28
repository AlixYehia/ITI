#include <iostream>
using namespace std;

class LinearSearch {
private:
    int* array;
    int size;

public:

    LinearSearch(int* inputArray, int inputSize)
    {
        size = inputSize;
        array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = inputArray[i];
        }
    }


    ~LinearSearch()
    {
        delete[] array;
    }

    /// Function to perform linear search and return indices of occurrences
    int* search(int target, int& count)
    {
        count = 0;


        for (int i = 0; i < size; i++)
        {
            if (array[i] == target)
            {
                count++;
            }
        }

        if (count == 0)
        {
            return NULL;
        }

        // Allocate array to store indices
        int* indices = new int[count];
        int index = 0;

        // Second pass: Collect indices
        for (int i = 0; i < size; i++)
        {
            if (array[i] == target)
            {
                indices[index] = i;
                index++;
            }
        }

        return indices;
    }

    // Setter for the array
    void setArray(int* inputArray, int inputSize)
    {
        delete[] array;
        size = inputSize;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = inputArray[i];
        }
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

int main()
{
    int inputArray[7] = {1, 2, 3, 4, 2, 5, 12};
    int size = 7;
    int target = 2;

    LinearSearch searcher(inputArray, size);
    int count;
    int* result = searcher.search(target, count);

    if (result != NULL)
    {
        cout << "Target element " << target <<" found "<<count<< " time(s) at indices: ";
        for (int i = 0; i < count; i++)
        {
            cout << result[i] << (i < count - 1 ? ", " : "");  ///If i < count - 1, meaning there are more indices to print, therefore add a comma and space ", " after the current index.
                                                               ///If i == count - 1, meaning it's the last index, it adds an empty string ""
        }
        cout << endl;

        /// Free dynamically allocated memory for indices since result now points to it
        delete[] result;
    }
    else
    {
        cout << "Target element " << target << " not found in the array." << endl;
    }

    return 0;
}
