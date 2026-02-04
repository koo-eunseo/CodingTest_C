#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int size=section.size();
    int answer=0;
    int last=0;
   
    for(int i=0;i<size;i++){
        if(section[i]>last){
            answer++;
            last=section[i]+m-1;
        }
    }
    return answer;
}