#include <cstdio>
#include <cstring>
typedef long long ll;
int n,tin,tout,len[4],in[10][10],out[10][10];
char op,s[4][20],ans[4][20],buf[100000];
void init()
{
    int a[10];
    a[0]=1<<0|1<<1|1<<2|1<<4|1<<5|1<<6;
    a[1]=1<<2|1<<5;
    a[2]=1<<0|1<<2|1<<3|1<<4|1<<6;
    a[3]=1<<0|1<<2|1<<3|1<<5|1<<6;
    a[4]=1<<1|1<<2|1<<3|1<<5;
    a[5]=1<<0|1<<1|1<<3|1<<5|1<<6;
    a[6]=1<<0|1<<1|1<<3|1<<4|1<<5|1<<6;
    a[7]=1<<0|1<<2|1<<5;
    a[8]=1<<0|1<<1|1<<2|1<<3|1<<4|1<<5|1<<6;
    a[9]=1<<0|1<<1|1<<2|1<<3|1<<5;
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            for (int k=0;k<=6;k++)
            {
                int u=a[i]>>k&1,v=a[j]>>k&1;
                if (u==0 && v==1)
                    in[i][j]++;
                if (u==1 && v==0)
                    out[i][j]++;
            }
}
ll get(char *s)
{
    int n=strlen(s);
    ll ret=0;
    for (int i=0;i<n;i++)
        ret=ret*10+s[i]-'0';
    return(ret);
}
bool check()
{
    ll x=get(ans[1]),y=get(ans[2]),z=get(ans[3]);
    if (op=='+')
        return(x+y==z);
    if (op=='-')
        return(x-y==z);
    if (op=='*')
        return(x*y==z);
    if (op=='/')
        return(y!=0 && x/y==z && x%y==0);
}
bool dfs(int id,int dep)
{
    if (tin>n || tout>n)
        return(false);
    if (id==4)
        return(tin==tout && tin==n && check());
    if (dep==len[id])
        return(dfs(id+1,0));
    int x=s[id][dep]-'0';
    for (int i=0;i<10;i++)
    {
        ans[id][dep]=i+'0';
        tin+=in[x][i];
        tout+=out[x][i];
        if (dfs(id,dep+1))
            return(true);
        tin-=in[x][i];
        tout-=out[x][i];
    }
    return(false);
}
int main()
{
    init();
    while (1)
    {
        gets(buf);
        if (strcmp(buf,"EOF")==0)
            break;
        sscanf(buf,"%s %c %s %*c %s %*c%d%*c",s[1],&op,s[2],s[3],&n);
        for (int i=1;i<=3;i++)
        {
            len[i]=strlen(s[i]);
            ans[i][len[i]]='\0';
        }
        static int id=0;
        printf("%d. ",++id);
        tin=tout=0;
        if (dfs(1,0))
            printf("%s%c%s=%s\n",ans[1],op,ans[2],ans[3]);
        else
            printf("UNSOLVABLE\n");
    }
    return(0);
}

