#include<iostream>

using namespace std;

// source from:poj 1012
// description:
// from among n people, numbered 1, 2, . . ., n, standing in circle 
// every mth is going to be executed and only the life of the last remaining person 
// will be saved.Suppose that there are k good guys and k bad guys. In the circle the 
// first k are good guys and the last k bad guys. You have to determine such minimal m 
// that all the bad guys will be executed before the first good guy.

int main(){
    int k;
    int a[15] = {0};
    a[1] = 2;   //this case can be deduced easily

    for(k=2; k<=14; ++k){
        int m, n, i;
        for(m=1; ; ++m){
            n = 2*k;
            int tmp = m%n-1;
            for(i=0; i<k; ++i){
                if(tmp < k) break;
                n--;
                if(n)   tmp = (tmp+m-1) % n;
            }
            if(i==k) break;
        }
        a[k] = m;
    }
    while(scanf("%d", &k) && k){
        printf("%d\n", a[k]);
    }    
    return 0;
}
