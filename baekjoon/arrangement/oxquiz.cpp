#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int turn;
    int sum = 0;
    int cnt = 0;
    char arr[80];
    
    cin >> turn;

    for(int i=0;i<turn;i++)
    {
        cin >> arr;

        for(int j=0;j<strlen(arr);j++)
        {
            if(arr[j] == 'O')
            {
                cnt+=1;
                sum = sum + cnt; 
            }
            else
            {
                cnt = 0;
            }         
        }
        cout << sum << endl;

        cnt = 0;
        sum = 0;        
    }

    return 0;
}