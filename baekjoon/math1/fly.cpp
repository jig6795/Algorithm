#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int test;
    cin >> test;

    for(int i=0;i<test;i++)
    {
        int start, end;
        cin >> start >> end;

        if(start >= end)
        {
            return 0;
        }

        long long dist = end - start;
        long long n = 1;
        long long before = 1;
        long long after = 2;

        while(1)
        {
            if(dist>=before && dist<=after)
            {
                if(dist <= n*n)
                {
                    cout << 2*n - 1 << "\n";
                    break;
                }
                else
                {
                    cout << 2*n << "\n";
                    break;
                }
            }
            n++;
            before = (n*n) - n + 1;
            after = (n*n) + n;
        } 
    }   

    return 0;
}