#include <iostream>

using namespace std;

int main(void)
{
    int scale[] = {1,2,3,4,5,6,7,8};
    int newScale[8];

    for(int i=0;i<8;i++)
    {
        cin >> newScale[i];
    }

    if(newScale[0] == 1)
    {
        for(int i=1;i<8;i++)
        {
            if(scale[i] == newScale[i])
            {
                newScale[i] = 9;
            }
            else
            {
                cout << "mixed" << endl;
                break;
            }           
        }
    }
    else if(newScale[0] == 8)
    {
        for(int i=1;i<8;i++)
        {
            if(scale[7-i] == newScale[i])
            {
                newScale[i] = 0;
            }
            else
            {
                cout << "mixed" << endl;
                break;
            }           
        }
    }
    else
    {
        cout << "mixed" << endl;
    }

    if(newScale[7] == 9)
    {
        cout << "ascending" << endl;
    }
    else if(newScale[7] == 0)
    {
        cout << "descending" << endl;
    }

    return 0;
}