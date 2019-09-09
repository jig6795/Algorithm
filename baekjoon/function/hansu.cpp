#include <iostream>

using namespace std;

bool hansu(int n)
{
    int max = n/100 - (n/10)%10;
    int min = (n%100)/10 - n%10;

    if(n<100)
    {
        return true;
    }
    else
    {
        if(max == min)
        {
            return true;
        }
        else
        {
            return false;
        }       
    }
}

int main()
{
    int cnt = 0;
    int num;
    cin >> num;

    for(int i =1; i<=num;i++)
    {
        if(hansu(i))
        {
            cnt+=1;
        }       
    }

    cout << cnt << endl;

    return 0;
}