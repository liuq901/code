#include <iostream>
#include <string>
#include <bitset>
using namespace std;
const int mod=10007,lq=26147,LQ=12531;
bool *f;
int a[10],c[30];
string s;
int calc(const string &s)
{
    int ret=0;
    for (int i=0;i<s.size();i++)
        ret=(ret*lq+c[s[i]-'a'])%mod;
    return(ret);
}
int main()
{
    ios::sync_with_stdio(false);
    a[0]=1;
    for (int i=1;i<10;i++)
        a[i]=a[i-1]*lq%mod;
    c[0]=1;
    for (int i=1;i<26;i++)
        c[i]=c[i-1]*LQ%mod;
    int n,in,input,out,output,one,puton;
    in=calc("in");
    input=calc("input");
    out=calc("out");
    output=calc("output");
    one=calc("one");
    puton=calc("puton");
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        f=new(bool[s.size()+10]);
        for (int i=0;i<=s.size();i++)
            f[i]=false;
        f[0]=true;
        int p[10]={0};
        for (int i=1;i<=s.size();i++)
        {
            for (int j=0;j<=7;j++)
            {
                p[j]=(p[j]*lq+c[s[i-1]-'a'])%mod;
                if (i>j)
                {
                    p[j]=(p[j]-c[s[i-j-1]-'a']*a[j])%mod;
                    if (p[j]<0)
                        p[j]+=mod;
                }
            }
            if (p[2]==in && f[i-2])
                f[i]=true;
            if ((p[3]==out || p[3]==one) && f[i-3])
                f[i]=true;
            if ((p[5]==input || p[5]==puton) && f[i-5])
                f[i]=true;
            if (p[6]==output && f[i-6])
                f[i]=true;
        }
        cout<<(f[s.size()]?"YES":"NO")<<endl;
        delete[](f);
    }
    return(0);
}

