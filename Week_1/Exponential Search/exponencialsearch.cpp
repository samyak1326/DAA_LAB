#include <iostream>
using namespace std;

int c=0;

bool binary_search(int *arr, int st, int en, int k){
    if(st>en)
    {
        return false;
    }
    ++c;

    int mid = (st+en)/2;

    if(arr[mid]==k)
    {
        return true;
    }

    if(arr[mid]<k)
    {
        return binary_search(arr, mid+1, en, k);
    }
    else return binary_search(arr, st, mid-1, k);
}

bool exponential_search(int arr[], int n, int k, int exp=2)
{
    if(arr[0]==k){
        ++c;
        return true;
    }
    int i=1;
    while (i<n && arr[i]<=k)
    {
        ++c;
        i*=exp;
    }
    return binary_search(arr, (i/2), min(i, n-1), k);
}

int main()
{
    int t, n, i, k;
    cin >> t; // input number of testcases

    while(t>0)
    {
        cin >> n; // input number of values in array
        int* arr = new int[n];
        for(i=0; i<n; ++i){
            cin >> arr[i]; // input array values
        }

        cin >> k; // input element to search
        c=0;
        bool res = exponential_search(arr, n, k);
        if(res)
        {
            cout << "Present " << c << '\n';
        }

        else
        {
            cout << "Not Present " << c << '\n';
        }
        --t;
    }
    
    return 0;
}