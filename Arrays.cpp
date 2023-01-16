#include <iostream>
#include <iomanip>
using namespace std;
void printdistinctpairs(int a[], int z)
{
    for (int i = 0; i < z; i++)
    {
        for (int j = i + 1; j < z; j++) // for distinct pairs
        // for (int j = 0 ; j <= z; j++) //for all pairs
        // for (int j = i; j <= z; j++) //for all pairs starting with i
        {
            if (j != z)
                cout << "{" << a[i] << "," << a[j] << "}"
                     << " ";
            else
                cout << "{" << a[i] << "," << a[j] << "}";
        }
        cout << endl;
    }
}

void printsubarrays(int a[], int z)
{
    int maxsum = 0;
    for (int i = 0; i < z; i++)
    {
        for (int j = i; j < z; j++)
        {
            int subsum = 0;
            cout << "{";
            for (int k = i; k <= j; k++)
            {
                subsum += a[k];
                if (k != j)
                    cout << a[k] << ",";
                else
                    cout << a[k] << "}";
            }
            maxsum = max(maxsum, subsum);
            // if (subsum > maxsum)
            //     maxsum = subsum;
            // cout << setw(20 - j) << right << subsum;
            cout << "       Subarray sum is= " << subsum;
            cout << endl;
        }
    }
    cout << endl
         << endl;
    cout << "Largest subarray sum is = " << maxsum << endl
         << endl
         << endl;
}

// Prefix Sum approach O(n^2)
void prefixsum(int a[], int z)
{
    int array[100] = {0};
    array[0] = a[0];
    for (int i = 1; i < z; i++)
    {
        array[i] = array[i - 1] + a[i];
    }
    int largestsum = 0;
    for (int i = 0; i < z; i++)
    {
        int subarraysum = 0;
        for (int j = i; j < z; j++)
        {
            subarraysum = i > 0 ? array[j] - array[i - 1] : array[j];
            cout << "Subarray sum is " << subarraysum << endl;
            largestsum = max(largestsum, subarraysum);
        }
        cout << endl;
    }
    cout << endl
         << endl
         << "Largest subarray sum is " << largestsum << endl;
}

int main()
{
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int z = sizeof(a) / sizeof(int);
    cout << z << endl
         << endl;
    //   printdistinctpairs(a, z);
    // printsubarrays(a, z);
    prefixsum(a, z);
}