//1427번 - 소트인사이드
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(char a,char b)
{
    return a > b;
}

int main(void)
{
    string n;
    cin >> n;
    vector<char> number;

    for(int i=0;i<n.length();i++)
    {
        number.push_back(n[i]);
    }
    sort(number.begin(),number.end(),cmp);

    for(int i=0;i<number.size();i++)
    {
        cout << number[i];
    }
}