#include <iostream>

using namespace std;

int main(void)
{
    int arr[10];
    int remain[10];
    int cnt = 0;
    int total = 0;

    for(int i=0;i<10;i++)
    {
        cin >> arr[i];

        remain[i] = arr[i] % 42;
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            if(remain[i] == remain[j])
            {
                cnt += 1;
            }
        }

        if(cnt == 1)
        {
            total += 1;
        }
        
        cnt = 0;

    }

    cout << total << endl;

    return 0;
}