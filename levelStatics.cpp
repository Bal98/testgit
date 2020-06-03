#include<bits/stdc++.h>
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
        int x,y;
        cin>>x>>y;
        int f;
        if(y>x)
        f=0;
        else
        f=1;
        int lost = x-y;
        for(int i=1;i<n;i++)
        {
              int p,q;
              cin>>p>>q;
              int lost1 = p-q;
              if(x>p||p<q || y>q || lost1<lost)
              {
                  f=0;
              }
              x=p;
              y=q;
              lost = lost1;
        }
        if(f==0)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    return 0;
}
