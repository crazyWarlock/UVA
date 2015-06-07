#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(a % b, b);
}
int main(){
    long long a, b, G, L;
        
    int T;
    cin>>T;
    while(T --){
        cin>>G>>L;
        long long mul = G * L;
        int f = 0;
        for(a = G; a <= L; a += G){
            if(mul % a != 0) continue;
            b = mul / a;
            if(gcd(a, b) == G){
                f = 1;
                break;
            }
        }
        if(f) cout<<a<<" "<<b<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
