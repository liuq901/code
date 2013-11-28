#include <cstdio>
#include <vector>
#include <string>
using namespace std;
vector <int> a;
vector <string> s;
bool dfs(const vector <int> &a,const vector <string >&s)
{
    if (a.size()==1)
    {
        if (a[0]==10)
        {
            printf("%s\n",s[0].c_str());
            return(true);
        }
        return(false);
    }
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
        {
            vector <int> b=a;
            vector <string> t=s;
            b.erase(b.begin()+j);
            t.erase(t.begin()+j);
            b[i]=a[i]+a[j];
            t[i]="("+s[i]+" + "+s[j]+")";
            if (dfs(b,t))
                return(true);
            b[i]=a[i]-a[j];
            t[i]="("+s[i]+" - "+s[j]+")";
            if (dfs(b,t))
                return(true);
            b[i]=a[j]-a[i];
            t[i]="("+s[j]+" - "+s[i]+")";
            if (dfs(b,t))
                return(true);
            b[i]=a[i]*a[j];
            t[i]="("+s[i]+" * "+s[j]+")";
            if (dfs(b,t))
                return(true);
        }
    return(false);
}
int main()
{
    while (1)
    {
        a.resize(4);
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
        if (a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)
            break;
        s.resize(4);
        for (int i=0;i<4;i++)
            s[i]=string("")+char(a[i]+'0');
        if (!dfs(a,s))
            printf("0\n");
    }
    return(0);
}

