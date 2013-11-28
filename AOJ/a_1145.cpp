#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
char s[110];
int f[110][110];
int getnum(int l,int r)
{
    if (l>r)
        return(0);
    if (f[l][r]!=-1)
        return(f[l][r]);
    int &ret=f[l][r];
    if (isalpha(s[l]))
        return(ret=min(1000010,getnum(l+1,r)+1));
    int num=0,u;
    for (int i=l;i<=r;i++)
    {
        if (!isdigit(s[i]))
        {
            u=i;
            break;
        }
        num=num*10+s[i]-'0';
    }
    if (isalpha(s[u]))
        return(ret=min(1000010,num+getnum(u+1,r)));
    int now=0,v;
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(')
            now++;
        if (s[i]==')')
        {
            now--;
            if (now==0)
            {
                v=i;
                break;
            }
        }
    }
    return(ret=min(1000010,num*getnum(u+1,v-1)+getnum(v+1,r)));
}
char get(int l,int r,int pos)
{
    if (l>r)
        return('0');
    if (isalpha(s[l]))
    {
        if (pos==1)
            return(s[l]);
        return(get(l+1,r,pos-1));
    }
    int num=0,u;
    for (int i=l;i<=r;i++)
    {
        if (!isdigit(s[i]))
        {
            u=i;
            break;
        }
        num=num*10+s[i]-'0';
    }
    if (isalpha(s[u]))
    {
        if (pos<=num)
            return(s[u]);
        return(get(u+1,r,pos-num));
    }
    int now=0,v;
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(')
            now++;
        if (s[i]==')')
        {
            now--;
            if (now==0)
            {
                v=i;
                break;
            }
        }
    }
    int t=getnum(u+1,v-1);
    if (pos<=t*num)
        return(get(u+1,v-1,pos%t==0?t:pos%t));
    else
        return(get(v+1,r,pos-t*num));
}
int main()
{
    while (1)
    {
        int pos;
        scanf("%s%d",s,&pos);
        if (strlen(s)==1 && s[0]=='0' && pos==0)
            break;
        pos++;
        memset(f,-1,sizeof(f));
        printf("%c\n",get(0,strlen(s)-1,pos));
    }
    return(0);
}

