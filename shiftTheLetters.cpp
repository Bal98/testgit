#include<bits/stdc++.h>
#define ll long long
#define pb push_back;
#define all(x) x.begin(),x.end()
const ll inf = 1e18;
using namespace std;
ll dp[2050][26][35];
int k;
string s;
int n;
ll cost(int a,int b)
{
  return (b-a+26)%26;
}

ll solve(int i,int cnt,int last)
{
  if(cnt>k)
  return inf;

  if(i==n)
  return 0;

  if(dp[i][last][cnt]!=-1)
  return dp[i][last][cnt];

  ll res= inf;

  for(int j=0;j<26;j++)
  {
    if(j==last)
    res= min(res , solve(i+1,cnt,j)+cost(s[i]-'a',j));
    else
    res = min(res,solve(i+1,cnt+1,j)+cost(s[i]-'a',j));
  }

  retturn dp[i][last][cnt]=res;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  cin>>s;
  cin>>k;
  n = s.size();

  int ans = inf;
  memset(dp,-1,sizeof dp);

  for(int i=0;i<26;i++)
  {
    ans = min(ans,solve(1,i,0)+cost(s[0]-'a',i));
  }

  cout<<ans<<endl;
  return 0;

}
