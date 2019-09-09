#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    string str;
    getline(cin,str);
    int cnt = 0;

    for(int i=0;i<str.length();i++)
    {
        if(str.at(i) == ' ')
        {
            cnt += 1;
        }
    }
    if(str.at(0) == ' ')
    {
        cnt -= 1;
    }
    if(str.at(str.length()-1) == ' ')
    {
        cnt -= 1;
    }

    cout << cnt + 1 << endl;

    return 0;
}