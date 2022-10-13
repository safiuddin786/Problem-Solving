#include <iostream>
#include <vector>
#include <sys/time.h>
#include <chrono>
using namespace std;

vector<int> insertion_sort(vector<int> A)
{
    // First element(Zero index) is always sorted
    for (int i = 1; i < A.size(); i++)
    {
        int key_element = A[i];
        int j = i;
        while (j > 0 && key_element < A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = key_element;
    }
    return A;
}

int main()
{
    vector<int> A{1, 15, 4, 29, 14, 15, 30, 28};
    vector<int> result = insertion_sort(A);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}