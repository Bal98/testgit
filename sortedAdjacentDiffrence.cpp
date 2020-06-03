#include<bits/stdc++.h>
#define ll long long
#define pb push_back;
#define all(x) x.begin(),x.end()
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<ll>v(n);
    for(auto &x:v)
    cin>>x;

    sort(all(v));
    int i;
    if(n%2==0)
    i=n/2-1;
    else
    i=n/2;
    int j=i+1;
    int k=0;
    while(i>=0 && j<n)
    {
      if(k%2==0)
      cout<<v[i]<<" ",i--;
      else
      cout<<v[j]<<" ",j++;
      k++;
    }
    if(i>=0)
    cout<<v[i];
    if(j<n)
    cout<<v[j];
    cout<<endl;

  }
  return 0;
}
