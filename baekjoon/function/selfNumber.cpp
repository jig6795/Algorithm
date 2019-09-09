#include <iostream>

using namespace std;

int d(int n)
{
    int sum = n;

    while(n != 0)
    {
        sum += n%10;
        n = n/10;
    }

    return sum;
}

int main()
{
    bool arr[10000] = {false};

    for(int i=0;i<10000;i++)
    {
        int k = d(i+1);
        if(k<=10000)
        {
            arr[k-1] = true; 
        }
    }

    for(int i=0;i<10000;i++)
    {
        if(!arr[i])
        {
            cout << i+1 << endl;
        }
    }

    return 0;
}