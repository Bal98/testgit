#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  string s;
  cin>>s;
  int l=s.lenght();
  int k=1;
  ll sum=0;
  for(int i=l-1;i>=0;i--)
  {
     if(s[i]=='1')
     {
         sum=(sum+k)%mod;
     }
     k=(2*k)%mod;
 }
  cout<<sum<<endl;
}
