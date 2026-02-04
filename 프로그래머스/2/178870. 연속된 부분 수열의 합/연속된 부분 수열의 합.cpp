#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int l=0;
    int r=-1;
    int size=sequence.size();
    int sum=0;
    int index=0;
    
    while(r < size) {
       
        if(sum < k){
            r++;
            sum+=sequence[r];
        }
        
        else {
            if(sum==k){
                if(index==0||index>(r-l+1)){
                index=r-l+1;
                answer[0]=l;
                answer[1]=r;  
                }
            }
            
            sum-=sequence[l];
            l++; 
        } 
    }
    return answer;
}