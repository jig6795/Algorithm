#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    int cnt = 0;
    int temp;

    for(int i=0;i<str.length();i++)
    {
        temp = str.at(i);
        
        if(temp <= 67)
        {
            cnt += 3;
        }
        else if(temp <= 70)
        {
            cnt += 4;
        }
        else if(temp <= 73)
        {
            cnt += 5;
        }
        else if(temp <= 76)
        {
            cnt += 6;
        }
        else if(temp <= 79)
        {
            cnt += 7;
        }
        else if(temp <= 83)
        {
            cnt += 8;
        }
        else if(temp <= 86)
        {
            cnt += 9;
        }
        else if(temp <= 90)
        {
            cnt += 10;
        }
    }

    cout << cnt << endl;
    
    return 0;
}
