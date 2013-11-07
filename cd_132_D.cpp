#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
char buf[1000010];
int a[1000010],b[1000010],l[1000010],r[1000010];
vector <pair <int,int> > ans;
int main()
{
    scanf("%s",buf);
    int len=strlen(buf),n=1;
    a[1]=1,b[1]=1,l[1]=r[1]=len-1;
    for (int i=1;i<len;i++)
        if (buf[i]==buf[i-1])
        {
            b[n]++;
            r[n]=len-i-1;
        }
        else
        {
            n++;
            a[n]=1-a[n-1];
            b[n]=1;
            l[n]=r[n]=len-i-1;
        }
    if (a[n]==0)
        b[n]=2;
    else
    {
        n++;
        a[n]=0;
        b[n]=2;
    }
    for (int i=1;i<=n;i++)
    {
        for (;i<=n;i++)
        {
            if (a[i]==0)
                continue;
            if (b[i]>1)
                break;
            ans.push_back(make_pair(l[i],1));
        }
        if (i>n)
            break;
        ans.push_back(make_pair(l[i]+1,1));
        i++;
        for (;i<=n;i++)
            if (a[i]==0)
            {
                if (b[i]>1)
                {
                    ans.push_back(make_pair(r[i-1],0));
                    break;
                }
                ans.push_back(make_pair(l[i],0));
            }
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%c2^%d\n",ans[i].second==1?'+':'-',ans[i].first);
    return(0);
}

