#include <cstdio>
#include <cstring>
#include <cctype>
char s[100];
inline bool isop(char ch)
{
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/');
}
bool check(int l,int r)
{
    if (l==r)
        return(isdigit(s[l]));
    int k=-1;
    for (int i=r;i;i--)
        if (isop(s[i]))
        {
            k=i;
            break;
        }
    if (k==-1 || !isdigit(s[r]))
        return(false);
    for (int i=k+1;i<r;i++)
        if (s[i]!='.')
            return(false);
    int last=k-1;
    while (last>=l && s[last]=='.')
        last--;
    return(l<=last && check(l,last));
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    while (T--)
    {
        gets(s);
        printf("%s\n",check(0,strlen(s)-1)?"Yes":"No");
    }
    return(0);
}

