#include <iostream>
#include <bitset>
using namespace std;
bitset <20> a;
int cnt,ans[1<<20];
void set(int dep)
{
    int reset(int);
    if (dep==0)
    {
        a.set(0);
        ans[a.to_ulong()]=++cnt;
        return;
    }
    set(dep-1);
    a.set(dep);
    ans[a.to_ulong()]=++cnt;
    reset(dep-1);
}
void reset(int dep)
{
    if (dep==0)
    {
        a.reset(0);
        ans[a.to_ulong()]=++cnt;
        return;
    }
    set(dep-1);
    a.reset(dep);
    ans[a.to_ulong()]=++cnt;
    reset(dep-1);
}
int main()
{
    a.reset();
    set(19);
    int T;
    cin>>T;
    while (T--)
    {
        cin>>a;
        bitset <20> Ans(ans[a.to_ulong()]);
        int k;
        for (int i=19;i>=0;i--)
            if (a.test(i))
            {
                k=i;
                break;
            }
        cout<<Ans.to_string().substr(19-k)<<endl;
    }
    return(0);
}

