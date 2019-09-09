#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int i=0;

    int range1 = (2*i);
    int range2 = (2*i) + 2*(i+1);
    

    if((n+1)%3 == 0)
    {
        n = (n+1)/3;
    }
    else if((n-1)%3 == 0)
    {
        n = (n-1)/3;
    }
    else if(n%3 == 0)
    {
        n = n/3;
    }

    while(1)
    {
        if(n == 0)
        {
            break;
        }
        else
        {
            i++;

            if(n>=(range1+1) && n<=range2)
            {

                break;
            }
            else
            {
                range1 = range2;
                range2 = range2 + 2*(i+1);
            }
        }
    }

    cout << i+1 << endl;

    return 0;
}