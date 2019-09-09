#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{   
    string str1, str2;
    cin >> str1 >> str2;

    string str3, str4;
    string temp1, temp2;
    string temp3, temp4;

    temp1 = str1.at(0);
    temp2 = str1.at(2);
    str3 = temp2 + str1.at(1) + temp1;

    temp3 = str2.at(0);
    temp4 = str2.at(2);
    str4 = temp4 + str2.at(1) + temp3;
    
    if((int)str1.at(2) > (int)str2.at(2))
    {
        cout << str3 << endl;
    }
    else if((int)str1.at(2) < (int)str2.at(2))
    {
        cout << str4 << endl;
    }
    else if((int)str1.at(2) == (int)str2.at(2))
    {
        if((int)str1.at(1) > (int)str2.at(1))
        {
            cout << str3 << endl;
        }
        else if((int)str1.at(1) < (int)str2.at(1))
        {
            cout << str4 << endl;
        }
        else if((int)str1.at(1) == (int)str2.at(1))
        {
            if((int)str1.at(0) > (int)str2.at(0))
            {
                cout << str3 << endl;
            }
            else if((int)str1.at(0) < (int)str2.at(0))
            {
               cout << str4 << endl;
            }
        }
    }

    return 0;
}