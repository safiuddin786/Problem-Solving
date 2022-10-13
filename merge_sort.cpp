#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// merge sort
vector<int> merge_sort(vector<int> A)
{
    if (A.size() > 1)
    {
        int mid = A.size() / 2;

        vector<int> split_left(A.begin(), A.begin() + mid);
        vector<int> split_right(A.begin() + mid, A.end());
        vector<int> left = merge_sort(split_left);
        vector<int> right = merge_sort(split_right);

        vector<int> merged_vector;

        // Merge the left and right vector
        int i = 0, j = 0;
        while (i < left.size() && j < right.size())
        {
            if (left[i] < right[j])
            {
                merged_vector.push_back(left[i]);
                i++;
            }
            else
            {
                merged_vector.push_back(right[j]);
                j++;
            }
        }
        if (i < left.size())
        {
            merged_vector.insert(merged_vector.end(), left.begin() + i, left.end());
        }
        else
        {
            merged_vector.insert(merged_vector.end(), right.begin() + j, right.end());
        }
        return merged_vector;
    }
    return A;
}

int main()
{
    vector<int> A{1, 15, 4, 29, 14, 15, 30, 28};
    vector<int> result = merge_sort(A);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
