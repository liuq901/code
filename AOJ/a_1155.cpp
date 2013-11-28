#include <cstdio>
#include <cstring>
#include <cctype>
const int NOT[3]={2,1,0};
const int AND[3][3]={{0,0,0},{0,1,1},{0,1,2}};
const int OR[3][3]={{0,1,2},{1,1,2},{2,2,2}};
char s[1000000];
int P,Q,R;
int calc(int l,int r)
{
    if (l==r)
    {
        if (isdigit(s[l]))
            return(s[l]-'0');
        return(s[l]=='P'?P:s[l]=='Q'?Q:R);
    }
    if (s[l]=='-')
        return(NOT[calc(l+1,r)]);
    l++,r--;
    int sum=0,k;
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(')
            sum++;
        if (s[i]==')')
            sum--;
        if (sum==0 && (s[i]=='*' || s[i]=='+'))
        {
            k=i;
            break;
        }
    }
    if (s[k]=='*')
        return(AND[calc(l,k-1)][calc(k+1,r)]);
    else
        return(OR[calc(l,k-1)][calc(k+1,r)]);
}
int main()
{
    while (1)
    {
        scanf("%s",s);
        if (s[0]=='.')
            break;
        int n=strlen(s),ans=0;
        for (P=0;P<=2;P++)
            for (Q=0;Q<=2;Q++)
                for (R=0;R<=2;R++)
                    ans+=calc(0,n-1)==2;
        printf("%d\n",ans);
    }
    return(0);
}

