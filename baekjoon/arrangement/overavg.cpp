#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int turn;
    cin >> turn;
    int num=1000;
    int arr[num];  
    double sum=0; 
    double avg=0; 
    double ratio = 0;
    double cnt=0;

    for(int i=0;i<turn;i++)
    {
        cin >> num;

        for(int j=0;j<num;j++)
        {
            cin >> arr[j];
        }

        for(int k=0;k<num;k++)
        {
            sum = sum + arr[k];
        }
        avg = sum/(double)num;
        
        for(int n=0;n<num;n++)
        {
            if(avg<arr[n])
            {
                cnt+=1;
            }
        }
        ratio = (cnt/num)*100;
        cout << fixed;
        cout.precision(3);
        cout << ratio << "%" << endl;

        cnt = 0;
        ratio = 0;
        sum = 0;
        avg = 0;
    }

    return 0;
}