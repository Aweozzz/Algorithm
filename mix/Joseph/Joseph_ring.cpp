#include<iostream>
#include<vector>

using namespace std;

//description:
//已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号为k的人开始报数，
//数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，
//直到圆桌周围的人全部出列。最后一个人为胜利者

void restore(vector<int> &a, int n){
    for(int i=1; i<=n; ++i)   a.push_back(i);
}

int main(){
    int m ,n;
    vector<int> table;
    while(cin >> n >> m){
        table.clear();
        restore(table, n);
        int tmp = m-1;
        for(int i=0; i<n; ++i){
            cout << table[tmp] << ' ';
            table.erase(table.begin()+tmp);
            if(table.size())    //avoid devided by zero
                tmp = (tmp + m -1)%table.size();
        }
        cout << endl;
    }
    return 0;
}