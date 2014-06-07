#include <cstdio>
#include <cstring>
char s[110];
bool a[1100];
int state;
bool calc(int l,int r)
{
    if (l==r)
        return(state>>s[l]-'a'&1);
    int cnt=0;
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(')
            cnt++;
        if (s[i]==')')
            cnt--;
        if (!cnt && s[i]=='|')
            return(calc(l,i-1) || calc(i+1,r));
    }
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(')
            cnt++;
        if (s[i]==')')
            cnt--;
        if (!cnt && s[i]=='&')
            return(calc(l,i-1) && calc(i+1,r));
    }
    return(s[l]=='!'?!calc(l+1,r):calc(l+1,r-1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        for (int i=0;i<1024;i++)
        {
            state=i;
            a[i]=calc(1,len);
        }
        scanf("%s",s+1);
        len=strlen(s+1);
        bool flag=true;
        for (int i=0;i<1024;i++)
        {
            state=i;
            if (a[i]!=calc(1,len))
            {
                flag=false;
                break;
            }
        }
        static int id=0;
        printf("Case %d: %sEquivalent\n",++id,flag?"":"Not ");
    }
    return(0);
}

