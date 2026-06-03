#include <iostream>

using namespace std;

void recInsertionSort(int arr[], int i, int n)
{
    if (i == n)
        return;

    int j = i;
    while (j > 0 && arr[j-1] > arr[j])
    {
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
        j--;
    }
    recInsertionSort(arr, i + 1, n);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    recInsertionSort(arr, 0, n);
    printArray(arr, n);
    return 0;
}