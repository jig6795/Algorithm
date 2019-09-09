#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    if(n == 1)
    {
        cout << 1 << '/' << 1 << endl;
    }
    int i=0;
    int temp1 = 1;
    int temp2 = 3;
    int a=0;//분자
    int b=0;//분모

    while(1)
    {
        i++;
        if(n >= (temp1 + 1) && n <= temp2)
        {
            if(i%2 != 0) // i홀수
            {
                a=1;
                b=i+1;
                for(int j=(temp1+1);j<n;j++)
                {
                    a = a + 1;
                    b = b - 1;
                }
                cout << a << '/' << b << endl;
            }
            else
            {
                a=i+1;
                b=1;
                for(int k=(temp1+1);k<n;k++)
                {
                    a = a - 1;
                    b = b + 1;
                }
                cout << a << '/' << b << endl;
            }
            break;            
        }
        else
        {
            temp1 = temp2;
            temp2 = temp2 + (2+i);
        }
    }
    return 0;
}