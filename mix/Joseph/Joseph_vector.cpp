#include<iostream>
#include<vector>


using namespace std;

// source from:poj 1012
// description:
// from among n people, numbered 1, 2, . . ., n, standing in circle 
// every mth is going to be executed and only the life of the last remaining person 
// will be saved.Suppose that there are k good guys and k bad guys. In the circle the 
// first k are good guys and the last k bad guys. You have to determine such minimal m 
// that all the bad guys will be executed before the first good guy.

void restore(vector<int> &a, int n){
    for(int i=1; i<=n; ++i)   a.push_back(i);
}

int main(){
    vector<int> table;
    int k;
    while(cin >> k){
        if(k == 0) break;
        if(k==1){
            cout << 2 << endl;
            break;
        }
        int m, n, i;
        for(m=1; ; ++m){
            table.clear();
            restore(table, 2*k);
            int tmp = m%table.size()-1;
            for(i=0; i<k; ++i){
                if(table[tmp] <=k) break;
                table.erase(table.begin()+tmp);
                if(table.size())   tmp = (tmp+m-1) % table.size();
            }
            if(i==k) break;
        }
        cout << m << endl;
    }    
    return 0;
}