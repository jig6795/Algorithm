//실패
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    int ten = 1; //10의 자리를 나타내기 위한 변수
    vector<int> number; //각 자리의 수를 저장하기 위한 배열
    vector<int> zeroOne; //조합을 위한 배열
    vector<int> temp_num;
    vector<int> same;
    int temp = 0; //조합된 수를 임시를 받기 위한 변수
    int cnt = 0;
    int count = 0;
    int num = atoi(numbers.c_str());

    //각 자리수를 나눠 저장 후 정렬
    for(int i=1;i<=numbers.length();i++)
    {
        number.push_back(num%10);
        num /= 10;
    }
    sort(number.begin(),number.end());

    //일의 자리수 숫자들 소수 확인
    //-----------------------------------------------------------------------
    temp_num.push_back(number[0]);
    for(int i=1;i<number.size();i++)
    {
        for(int j=0;j<temp_num.size();j++)
        {
            if(number[i] != temp_num[j])
            {
                count += 1;
            }
        }
        
        if(count == temp_num.size())
        {
            temp_num.push_back(number[i]);
        }

        count = 0;
    }
    
    for(int i=0;i<temp_num.size();i++)
    {
        if(!((temp_num[i] > 3) && (temp_num[i]%2 == 0 || temp_num[i]%3 == 0)))
        {
            if(temp_num[i] > 1)
            {
                cout << temp_num[i] << endl;
                answer += 1;
            }
        }   
    }
    //----------------------------------------------------------------------------

    //2자리 이상의 수를 조합
    for(int i=number.size();i>=2;i--)
    {
        //원하는 갯수만큼 조합을 위해 1,0을 이용
        //--------------------------------------
        for(int j=0;j<i;j++)
        {
            zeroOne.push_back(1);
        }

        for(int k=0;k<number.size()-i;k++)
        {
            zeroOne.push_back(0);
        }

        sort(zeroOne.begin(),zeroOne.end());
        //---------------------------------------
    
        do
        {
            for(int a=0;a<zeroOne.size();a++)
            {
                if(zeroOne[a] == 1)
                {
                    temp += (number[a]*ten);
                    ten *= 10;
                }
            }

            for(int c=0;c<same.size();c++)
            {
                if(temp == same[c])
                {
                    temp = 0;
                    break;
                }
            }
            same.push_back(temp);

            for(int b=2;b<temp;b++)
            {
                if((temp%b) == 0)
                {
                    cnt = 0;
                    break;
                }
                cnt += 1;
            }

            if(cnt > 0 && temp > 0)
            {
                cout << temp << endl;
                answer += 1;
            }            
            ten = 1;
            temp = 0;
        } while (next_permutation(number.begin(),number.end()));

        zeroOne.clear();
    }
    return answer;
}

int main(void)
{
    string number;
    cin >> number;

    int answer = solution(number);
    
    cout << answer << endl;
}