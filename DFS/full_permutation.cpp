#include<iostream>
#include<string>
#include<vector>
using namespace std;

int c = 1;
vector<string> ans;
string r;
bool used[101] = {false};
void dfs(string s, int k, int m){
    if(k == m+1) {ans.push_back(r); return;}
    for(int i=0; i<=m; ++i){
        if(used[i] == false){
            r.push_back(s[i]);
            used[i] = true;
            dfs(s, k+1, m);
            r.pop_back(); 
            used[i] = false;
        }
    }
}

int main(){
    string s;
    cin >> s;
    dfs(s, 0, s.size()-1);
    for(int i=0; i<ans.size(); ++i) cout << i+1 << ":" <<  ans[i] << endl;
    return 0;
}