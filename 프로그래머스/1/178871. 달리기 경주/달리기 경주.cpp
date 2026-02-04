#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    vector<string> answer;
    map<string, int> map1;
    map<int,string> map2;
    int idx=0;
    for(string str : players)
    {
        map1[str]=idx;
        map2[idx]=str;
        idx++;
    }
    
    for(string str : callings){ 
        int i = map1[str];
        string name = map2[i-1];
        map1[name]=i;
        map1[str] = i-1;
        map2[i]=name;
        map2[i-1]=str;
    }
    
    for(int j=0;j<idx;j++){
        answer.push_back(map2[j]);
    }
    
    return answer;
}