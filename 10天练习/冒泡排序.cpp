#include <iostream>

using namespace std;

int main()
{

    int size = 10;
    int arr[size] = {0, 120, 343, 123, 345, 756, 999, -123, 12, 141};
    

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }

    for (auto &i: arr)
    {
        cout << i << endl;
    }
    
}