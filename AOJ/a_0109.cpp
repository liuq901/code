#include <cstdio>
char s[100000];
int calc(int l,int r)
{
    int now=0;
    for (int i=r;i>=l;i--)
    {
        now+=(s[i]=='(')-(s[i]==')');
        if (now==0 && (s[i]=='+' || s[i]=='-'))
            return(s[i]=='+'?calc(l,i-1)+calc(i+1,r):calc(l,i-1)-calc(i+1,r));
    }
    for (int i=r;i>=l;i--)
    {
        now+=(s[i]=='(')-(s[i]==')');
        if (now==0 && (s[i]=='*' || s[i]=='/'))
            return(s[i]=='*'?calc(l,i-1)*calc(i+1,r):calc(l,i-1)/calc(i+1,r));
    }    
    if (s[l]=='(' && s[r]==')')
        return(calc(l+1,r-1));
    int ret=0;
    for (int i=l;i<=r;i++)
        ret=ret*10+s[i]-'0';
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        for (int i=0;;i++)
            if (s[i]=='=')
            {
                printf("%d\n",calc(0,i-1));
                break;
            }
    }
    return(0);
}

