#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
    int A,B,C,D;
    int arr[9];
    int cnt[] = {0,0,0,0,0,0,0,0,0,0};

    cin >> A >> B >> C;

    D = A*B*C;

    for(int i = 0; i<9;i++)
    {
        arr[i] = (D % (int)pow((double)10,(double)(9-i)))/(int)pow((double)10,(double)(8-i));
    }

    if(arr[0] == 0)
    {
        if(arr[1] == 0)
        {
            cnt[0]-=1;
        }
        
        cnt[0]-=1;
    }

    for(int i = 0; i<9; i++)
    {
        switch(arr[i])
        {
            case 0:
                cnt[0]+=1;
                break;
            case 1:
                cnt[1]+=1;
                break;
            case 2:
                cnt[2]+=1;
                break;
            case 3:
                cnt[3]+=1;
                break;
            case 4:
                cnt[4]+=1;
                break;
            case 5:
                cnt[5]+=1;
                break;
            case 6:
                cnt[6]+=1;
                break;
            case 7:
                cnt[7]+=1;
                break;
            case 8:
                cnt[8]+=1;
                break;
            case 9:
                cnt[9]+=1;
                break;
            default:
                break;
        }
    }

    for(int i=0;i<10;i++)
    {
        cout << cnt[i] << endl;
    }

    return 0;
}