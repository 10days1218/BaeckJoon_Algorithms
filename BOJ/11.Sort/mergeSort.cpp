//https://www.acmicpc.net/problem/2751
#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int res[1000000];
/// merge sort range : [low ~ high]
void mergeSort(int A[], int low, int high)
{
    // 1. base condition
    if (low >= high)
        return;

    // 2. divide
    int mid = (low + high) / 2;

    // 3. conquer
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);

    // 4. combine
    int i = low, j = mid + 1, k = low;
    for (; k <= high; ++k)
    {
        if (j > high)
            res[k] = A[i++];
        else if (i > mid)
            res[k] = A[j++];
        else if (A[i] < A[j])
            res[k] = A[i++];
        else
            res[k] = A[j++];
    }

    // 5. copy
    for (i = low; i <= high; ++i)
        arr[i] = res[i];
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    return 0;
}