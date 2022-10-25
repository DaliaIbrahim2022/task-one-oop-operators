#include<bits/stdc++.h>

#define inf 1e9
#define ll long long
#define vc  vector
#define vll  vc<ll>
//#define s second
#define f first
#define fro front
#define bk back
#define e "\n"
#define speed                     ios_base::sync_with_stdio(0);    cin.tie(0);    cout.tie(0);

using namespace std ;

bool bear(int n)
{
    if(n==42)
        return true;
    if(n<42) return false;
    assert(n >= 42);
    bool res = 0;
    if(n%5==0){
        res |= bear(n-42);
    }
    if(n%2==0){
        res |= bear(n/2);
    }
    if(n%3==0 || n%4 ==0){
        int temp = n%100;
        int temp2=(temp%10)*(temp/10);
        if(temp2 != 0)
          res |= bear(n-temp2);
    }
    return res;
}

int main() {

    //int n; cin>>n;
    //if(bear(n))  cout<< "yes";
    //else cout<<"no";

    cout<<" bear of 250 " <<  bear(250) << e ;
    cout<<" bear of 42 " <<  bear(42) <<e;
    cout<<" bear of 84 " <<  bear(84) <<e;
    cout<<" bear of 53 " <<  bear(53) <<e;
    cout<<" bear of 41 " <<  bear(41) <<e;




}