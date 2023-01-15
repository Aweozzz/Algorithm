#include<iostream>
#include<string>
using namespace std;

int c = 1;
void permutation(string s, int k, int m){
    if(k == m) cout << c++ << ':' << s << endl;
    else{
        for(int i=k; i<=m; ++i){
            swap(s[k], s[i]);
            permutation(s, k+1, m);
            swap(s[i], s[k]);
        }
    }
}

int main(){
    string s;
    cin >> s;
    permutation(s, 0, s.size()-1);
    return 0;
}