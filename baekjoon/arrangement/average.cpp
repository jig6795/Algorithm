#include <iostream>

using namespace std;

int main(void)
{
    int max;
    double sum = 0;
    double average=0;
    int n;
    cin >> n;
    
    double avg[n];

    for(int i=0;i<n;i++)
    {
        cin >> avg[i];
    }

    max = avg[0];

    for(int i=0;i<n;i++)
    {
        if(max < avg[i])
        {
            max = avg[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        avg[i] = (avg[i]/max) * 100;

        sum = sum + avg[i];
    }

    average = sum / n;

    cout << average << endl;

    return 0;
}