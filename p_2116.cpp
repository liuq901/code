#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char s[10000],t[10000];
bool f[1000];
vector <int> a,b,c;
void work(vector <int> &a)
{
    while (1)
    {
        bool flag=true;
        if (a.empty())
            break;
        for (int i=0;i<a.size();i++)
            if (!a[i])
                a[i]=1;
        sort(a.begin(),a.end());
        for (int i=0;i<a.size()-1;i++)
        {
            if (a[i]==a[i+1])
            {
                if (a[i]==1)
                {
                    a[i+1]++;
                    a.erase(a.begin()+i);
                }
                else
                {
                    a[i]-=2;
                    a[i+1]++;
                }
                flag=false;
            }
            if (a[i]+1==a[i+1])
            {
                a[i+1]++;
                a.erase(a.begin()+i);
                flag=false;
            }
        }
        if (flag)
            break;
    }
}
int main()
{
    while (scanf("%s%s",s,t)==2)
    {
        int n=strlen(s);
        a.clear();
        b.clear();
        c.clear();
        for (int i=0;i<n;i++)
            if (s[i]=='1')
            {
                a.push_back(n-i);
                b.push_back(n-i);
            }
        n=strlen(t);
        for (int i=0;i<n;i++)
            if (t[i]=='1')
            {
                a.push_back(n-i);
                c.push_back(n-i);
            }
        work(a);
        work(b);
        work(c);
        int la=a.empty()?1:a.back(),lb=b.empty()?1:b.back(),lc=c.empty()?1:c.back();
        memset(f,0,sizeof(f));
        for (int i=0;i<b.size();i++)
            f[b[i]]=true;
        for (int i=1;i<=la-lb+2;i++)
            printf(" ");
        for (int i=lb;i;i--)
            printf("%d",f[i]?1:0);
        printf("\n");
        memset(f,0,sizeof(f));
        for (int i=0;i<c.size();i++)
            f[c[i]]=true;
        printf("+");
        for (int i=1;i<=la-lc+1;i++)
            printf(" ");
        for (int i=lc;i;i--)
            printf("%d",f[i]?1:0);
        printf("\n");
        printf("  ");
        for (int i=1;i<=la;i++)
            printf("-");
        printf("\n");
        memset(f,0,sizeof(f));
        for (int i=0;i<a.size();i++)
            f[a[i]]=true;
        printf("  ");
        for (int i=la;i;i--)
            printf("%d",f[i]?1:0);
        printf("\n\n");
    }
    return(0);
}

