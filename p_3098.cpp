#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
char buf[1000000];
string s[110];
void update(string &ans,const string &s)
{
    if (s=="")
        return;
    if (ans=="" || s<ans)
        ans=s;
}
string get(int n,int l,int r)
{
    for (int i=1;i<=n;i++)
    {
        bool flag=true;
        int cnt1,cnt2;
        cnt1=cnt2=0;
        for (int j=l;j<=r;j++)
        {
            if (isalpha(buf[j]))
            {
                cnt1++;
                if (count(s[i].begin(),s[i].end(),buf[j]))
                    cnt2++;
                continue;
            }
            if (buf[j]=='+')
                if (!count(s[i].begin(),s[i].end(),buf[++j]))
                {
                    flag=false;
                    break;
                }
            if (buf[j]=='-')
                if (count(s[i].begin(),s[i].end(),buf[++j]))
                {
                    flag=false;
                    break;
                }
        }
        if (cnt1 && !cnt2)
            flag=false;
        if (flag)
            return(s[i]);
    }
    return("");
}
int main()
{
    while (1)
    {
        int n=0;
        while (1)
        {
            scanf("%s",buf);
            if (buf[0]=='#')
                goto last;
            if (buf[0]=='*')
                break;
            s[++n]=buf;
        }
        sort(s+1,s+n+1);
        while (1)
        {
            scanf("%s",buf);
            if (buf[0]=='*')
                break;
            int len=strlen(buf),l=0;
            buf[len]='|';
            string ans;
            for (int i=0;i<=len;i++)
                if (buf[i]=='|')
                {
                    update(ans,get(n,l,i-1));
                    l=i+1;
                    continue;
                }
            if (ans=="")
                printf("NONE\n");
            else
                printf("%s\n",ans.c_str());
        }
        printf("$\n");
    }
last:
    return(0);
}

