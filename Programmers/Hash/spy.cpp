#include <iostream>
#include <string>
#include <vector>
#include  <map>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 0;
    map<string, int> clothe; //각 종류에 몇 가지가 들어있는지 짝을 지어준다.
    int total = 1; //곱해주기 위한 변수
    
    for(int i=0;i<clothes.size();i++)
    {
        for(auto it = clothe.begin();it != clothe.end();it++)
        {
            if(clothes[i][1] == it->first) //종류가 같은 경우 +1
            {
                it->second += 1;
                break;
            }
        }
        clothe.insert(pair<string, int> (clothes[i][1],1)); //종류를 처음 등록하는 경우
    }
    
    //각 종류의 개수에 입지 않은 경우를 더해서 곱을 해준 뒤
    //하나도 입지 않은 경우를 제외시켜 지켜줍니다.
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