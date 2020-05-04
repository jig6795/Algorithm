//실패
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkAttribute[8] = {true}; //속성에 대해서 사용가능한 경우, true
int count_Key = 0; //후보키의 개수

//
// 각 속성에서 tuple을 비교해서 유일성이 만족하면 attribute[]에 false로 바꿈
//
void compareTuple(vector<string> attribute, int num)
{
    for(int i=0;i<attribute.size();i++)
    {
        for(int j=0;j<attribute.size();j++)
        {
            if(attribute[i] == attribute[j] && i != j)
            {
                cout << "Error : Same Tuple is existed" << endl;
                return;
            }
        }
    }
    //cout << num << endl;
    checkAttribute[num] = false;
    count_Key += 1;
    return;
}

int solution(vector<vector<string> > relation) {
    int answer = 0;

    //속성 1개로 유일성을 만족하는 경우
    for(int i=0;i<relation.size();i++)
    {
        compareTuple(relation[i],i);
    }

    //속성 1개로 만족하지 않는 경우
    
    
    answer = count_Key;
    return answer;
}

int main(void)
{
    vector<vector<string> > relation;
    vector<string> tuple1; //학번
    vector<string> tuple2; //이름
    vector<string> tuple3; //전공
    vector<string> tuple4; //학년

    //학번 속성
    tuple1.push_back("100");
    tuple1.push_back("200");
    tuple1.push_back("300");
    tuple1.push_back("400");
    tuple1.push_back("500");
    tuple1.push_back("600");

    //이름 속성
    tuple2.push_back("ryan");
    tuple2.push_back("apeach");
    tuple2.push_back("tube");
    tuple2.push_back("con");
    tuple2.push_back("muzi");
    tuple2.push_back("apeach");

    //전공 속성
    tuple3.push_back("music");
    tuple3.push_back("math");
    tuple3.push_back("computer");
    tuple3.push_back("computer");
    tuple3.push_back("music");
    tuple3.push_back("music");

    //학년 속성
    tuple4.push_back("2");
    tuple4.push_back("2");
    tuple4.push_back("3");
    tuple4.push_back("1");
    tuple4.push_back("3");
    tuple4.push_back("2");

    relation.push_back(tuple1);
    relation.push_back(tuple2);
    relation.push_back(tuple3);
    relation.push_back(tuple4);

    cout << solution(relation);

    return 0;
}