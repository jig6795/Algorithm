#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int cnt = 0; //같은 다이얼의 수

    for(int i=0;i<phone_book.size();i++)
    {
        string temp = phone_book[i]; //전화번호 목록 중 하나를 받아온다.

        for(int j=0;j<phone_book.size();j++)
        {
            if(i == j) //같은 번호인 경우 skip
            {
                continue;
            }

            for(int k=0;k<temp.length();k++) //temp의 길이만큼 반복을 하면서 같은 다이얼인 경우 cnt 증가
            {
                if(temp[k] == phone_book[j][k])
                {
                    cnt += 1;
                }
            }

            if(cnt == temp.length()) //임의의 번호가 다른 전화번호가 되는 경우 return
            {
                answer = false;
                return  answer;
            }
            cnt = 0;
        }
    }
    return answer;
}

int main(void)
{
    vector<string> phone;
    phone.push_back("12");
    phone.push_back("123");
    phone.push_back("1235");
    phone.push_back("567");
    phone.push_back("88");

    if(!solution(phone))
    {
        cout << "false" << endl;
    }   
    else
    {
        cout << "true" << endl;
    }
    

    return 0;
}