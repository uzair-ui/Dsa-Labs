//#include <iostream>
//using namespace std;
//
//int findMax(int arr[], int size)
//{
//    if (size == 1)
//        return arr[0];
//
//    int maxValue = findMax(arr, size - 1);
//
//    if (arr[size - 1] > maxValue)
//        return arr[size - 1];
//
//    return maxValue;
//}
//
//int main()
//{
//    int arr[] = { 12, 5, 18, 7, 3 };
//    int size = 5;
//
//    cout << "Maximum element: " << findMax(arr, size);
//
//    return 0;
//}