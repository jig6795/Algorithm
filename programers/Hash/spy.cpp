#include <iostream>
#include <string>
#include <vector>
#include  <map>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 0;
    map<string, int> clothe;
    int total = 1;
    int cnt = 0;
    
    for(int i=0;i<clothes.size();i++)
    {
        for(auto it = clothe.begin();it != clothe.end();it++)
        {
            if(clothes[i][1] == it->first)
            {
                it->second += 1;
                break;
            }
        }
        clothe.insert(pair<string, int> (clothes[i][1],1));
        cnt += 1;
    }
    
    for(auto it = clothe.begin();it != clothe.end();it++)
    {
        total *= (it->second + 1);
    }

    answer = total - 1;
    return answer;
}

int main(void)
{
    vector<vector<string> > clothe_type;

    vector<string> a;
    vector<string> b;
    vector<string> c;

    a.push_back("yellow_hat");
    a.push_back("headgear");
    b.push_back("blue_sunglasses");
    b.push_back("eyewear");
    c.push_back("green_turban");
    c.push_back("headgear");

    clothe_type.push_back(a);
    clothe_type.push_back(b);
    clothe_type.push_back(c);

    cout << solution(clothe_type) << " is answer" << endl;

    return 0;
}