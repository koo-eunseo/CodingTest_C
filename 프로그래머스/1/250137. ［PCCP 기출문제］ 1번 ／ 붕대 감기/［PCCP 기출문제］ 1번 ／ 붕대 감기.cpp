#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int size = attacks.size();
    int time = attacks[size-1][0];
    int t= bandage[0], x=bandage[1], y =bandage[2];
    int flag=1;
    int index=0;
    
    for(int i=1; i<time+1;i++){
        flag=1;
        index++;
        for(int j=0;j<size;j++){
            if(i==attacks[j][0])
            {
                answer-=attacks[j][1];
                if(answer<=0) return -1;
                flag=0;
                index=0;
            }
        }
    
        if(answer<health&&flag==1)
        {
            answer+=x;
            if(index%t==0) answer+=y;
            if(answer>health) answer=health;
        }
    }
    return answer;
}