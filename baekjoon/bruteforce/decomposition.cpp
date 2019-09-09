#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int com = 0;
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        if(i<10)
        {
            sum = i + i;
            if(sum == n)
            {
                com = i;
                break;
            }
        }
        else if(i>=10 && i<100)
        {
            sum = i + i/10 + i%10;
            if(sum == n)
            {
                com = i;
                break;
            }
        }
        else if(i>=100 && i<1000)
        {
            sum = i + i/100 + (i%100)/10 + i%10;
            if(sum == n)
            {
                com = i;
                break;
            }
        }
        else if(i>=1000 && i<10000)
        {
            sum = i + i/1000 + (i%1000)/100 + (i/10)%10 + i%10;
            if(sum == n)
            {
                com = i;              
                break;
            }
        }
        else if(i>=10000 && i<100000)
        {
            sum = i + i/10000 + (i%10000)/1000 + (i/100)%10 + (i/10)%10 + i%10;
            if(sum == n)
            {
                com = i;
                break;
            }
        }
        else if(i>=100000 && i<1000000)
        {
            sum = i + i/100000 + (i%100000)/10000 + (i/1000)%10 + (i/100)%10 + (i/10)%10 + i%10;
            if(sum == n)
            {
                com = i;
                break;
            }
        }


    }
    
    cout << com << endl;

    return 0;
}