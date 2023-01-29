#include<iostream>
#include<string>

using namespace std;

const int N = 1001;

//poj 1001
//descriptionProblems involving the computation of exact values of very large magnitude and precision are common. For example, 
// the computation of the national debt is a taxing experience for many computer systems.This problem requires that you write 
// a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.

int main(){
    string s;
    int n;
    while(cin >> s >> n){
        if(n == 0) cout << 1 << endl;
        else{
            int inum[N]={0}, ans[3*N]={0}, tmp[N] = {0};

            int size = s.size(), i, j, di;
            for(i=0; i<size; ++i){
                if(s[i] == '.') break;  //record the point position 
            }
            
            for(j=size-1; s[j] == '0'; j--);
            di = j-i;   //effective figure

            for(i=0; i<=j; ++i){
                if(s[j-i] != '.')
                    inum[i] = s[j-i] - '0';
            }
            
            for(i=di; i<j; ++i) inum[i] = inum[i+1];
            inum[i] = 0;
            size = j; //remove the decimal point

            //calculate the exponentiation   bug!!
            int size2;
            for(i=0; i<size; ++i) tmp[i] = inum[i];
            for(int k=2; k<=n; ++k){
                for(i=N; i>-1; --i) ans[i] = 0;
                for(i=N-1; tmp[i]==0; --i);
                size2 = i+1; 
                for(i=0; i<size; ++i){
                    for(j=0; j<size2; ++j){
                        ans[i+j] += (inum[i]*tmp[j]);
                    }
                }
                for(i=size+size2; i>-1; --i) tmp[i] = ans[i];

                //process the carry digit
                for(i=0; i<N; ++i){
                    if(tmp[i] >= 10){
                        tmp[i+1] += (tmp[i] / 10);
                        tmp[i] %= 10;
                    }
                }
            }
            

            di *= n;    //how many digits after decimal point
            for(i=N-1; tmp[i]==0; --i);
            
            if(di > i) {
                i=di;
                cout << '.';
                for(i=di-1; i>-1; --i) cout << tmp[i];
            }
            else{
                for(; i>-1; --i){
                    cout << tmp[i];
                    if(i == di && di) cout << '.';
                }
            }
            cout << endl;
        }
    }
    return 0;
}