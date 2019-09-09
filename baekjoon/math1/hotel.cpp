#include <iostream>
using namespace std;

int main(void)
{
    int c;
    cin >> c;
    int h,w,n;

    for(int i=0;i<c;i++)
    {
        cin >> h >> w >> n;

        if(n%h != 0) //꼭대기가 아닐때
        {
            if(n/h>=9)
            {
                cout << n%h << n/h + 1 << endl;
            }
            else
            {
                cout << n%h << 0 << n/h + 1 << endl;
            }
        }
        else
        {
            if(n/h>9)
            {
                cout << h << n/h << endl;
            }
            else
            {
                cout << h << 0 << n/h << endl;
            }
        }
        
    }

    return 0;
}