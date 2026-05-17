#include <iostream>
using namespace std;

int findLargest(int arr[], int n, int index = 1)
{
    if (index == n)
        return arr[0];

    int largest = findLargest(arr, n, index + 1);

    if (arr[index] > largest)
        return arr[index];

    return largest;
}

bool subsetSum(int arr[], int n, int target, int index)
{
    if (target == 0)
        return true;

    if (index == n || target < 0)
        return false;

    return subsetSum(arr, n, target - arr[index], index + 1) ||
           subsetSum(arr, n, target, index + 1);
}

int magicNumber(int arr[], int n)
{
    if (n == 0)
        return -1;

    int largest = findLargest(arr, n);

    int* temp = new int[n - 1];

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != largest || j == n - 1)
        {
            temp[j] = arr[i];
            j++;
        }
    }

    if (subsetSum(temp, n - 1, largest, 0))
    {
        delete[] temp;
        return largest;
    }

    int* newArr = new int[n - 1];

    for (int i = 0; i < n - 1; i++)
        newArr[i] = temp[i];

    delete[] temp;

    int result = magicNumber(newArr, n - 1);

    delete[] newArr;

    return result;
}

int main()
{
    int arr[] = {2, 3, 5, 8, 13};
    int n = 5;

    cout << magicNumber(arr, n);

    return 0;
}