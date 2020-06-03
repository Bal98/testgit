#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    t =1;
    while(t--)
    {
        int l,r,x,y;
        cin>>x>>y>>l>>r;
        // cout<<l<<" "<<r<<" ";
        int z=l;
        int mx=0;
        for(int i=l;i<=r;i++)
        {
            int  p = (x&i)*(y&i);
            cout<<"p="<<p<<endl;
            if(p>mx)
            {
                mx=p;
                z=i;
            }
        }
        cout<<z<<endl;

    }
    return 0;
}
