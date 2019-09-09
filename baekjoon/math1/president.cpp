#include <iostream>
using namespace std;

void sum(int p, int q)
{
    int arr1[q];
    int arr2[q];
    for(int i=0;i<q;i++)
    {
        arr1[i] = i+1;
        arr2[i] = i+1;
    }

    for(int i = 0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            for(int k=0;k<=j;k++)
            {
                arr2[j+1] += arr1[k];
            }
        }
        
        for(int j=0;j<q;j++)
        {
            arr1[j] = arr2[j];
        }
    }

    cout << arr2[q-1] << endl;
}

int main(void)
{
    int t;
    cin >> t;
    int k,n;

    for(int i=0;i<t;i++)
    {
        cin >> k >> n;

        sum(k,n);
    }

    return 0;
}