#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int cnt = 0;
    
    if(n<3 || n>5000)
    {
        return 0;
    }

    while(1)
    {
        if(n>0 && n<3)
        {
            cnt = -1;
            break;
        }
        else if(n<=0)
        {
            break;
        }

        if(n%5 == 0)
        {
            //cout << 1 << endl;
            cnt = cnt + n/5;
            n = 0;
        }
        else
        {
            //cout << 2 << endl;
            n = n - 3;
            cnt++;
        }
    }
    
    cout << cnt << endl;

    return 0;
}