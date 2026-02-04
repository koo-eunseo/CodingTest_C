#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    set<char> s;
    int size = keymap.size();
    for(string str : keymap){
        for(char ch : str)
            s.insert(ch);
    }
    
    vector<char> v(s.begin(),s.end());
    vector<int> num(v.size());
    
    for(int i=0;i<v.size();i++){
        for(string str : keymap){
            for(int j=0;j<str.length();j++){
                if(v[i]==str[j])
                {
                    if(num[i]==0)
                        num[i]=j+1;
                    if(num[i]>j+1)
                        num[i]=j+1;
                }
            }
        }
    }

    for(string str:targets){
        int flag=1;
        int result=0;
        for(char ch : str){
            flag=1;
             for(int i=0;i<v.size();i++){
                 if(ch==v[i]){
                     result+=num[i];
                     flag=0;
                 }
             }
            if(flag==1)
            {
                result=0;
                break;
            }
        }
        if(result==0)
            result=-1;
        answer.push_back(result);
    }
    return answer;
}