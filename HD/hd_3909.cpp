#include <cstdio>
#include <cstring>
const char a[]=" 123456789ABCDEFG";
struct data
{
    int l,r,u,d,x,y;
};
data p[20000];
int cnt,n,N,P,ans[260],tmp[260],sum[1050];
char M[300],b[20][20];
void build()
{
    int z[10],q[1050];
    bool c[20][20],d[20][20],f[20][20];
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            c[i][j]=d[i][j]=f[i][j]=false;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
        {
            if (b[i][j]=='.')
                continue;
            int k=M[b[i][j]];
            c[i][k]=d[j][k]=f[(i-1)/n*n+(j-1)/n+1][k]=true;
        }
    for (int i=1;i<=P*4;i++)
    {
        p[i].l=i-1;
        p[i].r=i+1;
        sum[i]=0;
        p[i].x=0;
        p[i].y=i;
        q[i]=i;
    }
    p[0].r=1;
    p[0].l=P*4;
    p[P*4].r=0;
    int num=P*4,t=0;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            for (int k=1;k<=N;k++)
            {
                t++;
                if (b[i][j]!='.' && M[b[i][j]]!=k)
                    continue;
                if (b[i][j]=='.' && (c[i][k] || d[j][k] || f[(i-1)/n*n+(j-1)/n+1][k]))
                    continue;
                z[1]=(i-1)*N+k;
                z[2]=(j-1)*N+k+P;
                z[3]=((i-1)/n*n+(j-1)/n)*N+k+P*2;
                z[4]=(i-1)*N+j+P*3;
                for (int l=1;l<=4;l++)
                {
                    sum[z[l]]++;
                    int tmp=num+l;
                    p[tmp].x=t;
                    p[tmp].y=z[l];
                    if (l!=1)
                    {
                        p[tmp].l=num+l-1;
                        p[num+l-1].r=tmp;
                    }
                    p[tmp].u=q[z[l]];
                    p[q[z[l]]].d=tmp;
                    q[z[l]]=tmp;
                }
                p[num+1].l=num+4;
                p[num+4].r=num+1;
                num+=4;
            }
    for (int i=1;i<=P*4;i++)
    {
        p[i].u=q[i];
        p[q[i]].d=i;
    }
}
void del(int t)
{
    p[p[t].r].l=p[t].l;
    p[p[t].l].r=p[t].r;
    for (int i=p[t].d;i!=t;i=p[i].d)
        for (int j=p[i].r;j!=i;j=p[j].r)
        {
            sum[p[j].y]--;
            p[p[j].u].d=p[j].d;
            p[p[j].d].u=p[j].u;
        }
}
void renew(int t)
{
    p[p[t].r].l=t;
    p[p[t].l].r=t;
    for (int i=p[t].u;i!=t;i=p[i].u)
        for (int j=p[i].l;j!=i;j=p[j].l)
        {
            sum[p[j].y]++;
            p[p[j].u].d=j;
            p[p[j].d].u=j;
        }
}
void search(bool first)
{
    if (p[0].r==0)
    {
        cnt++;
        if (cnt==1 && first)
            memcpy(ans,tmp,sizeof(tmp));
        return;
    }
    int mi=1<<30,t;
    for (int i=p[0].r;i;i=p[i].r)
        if (sum[p[i].y]<mi)
        {
            mi=sum[p[i].y];
            t=i;
        }
    del(t);
    for (int i=p[t].d;i!=t;i=p[i].d)
    {
        tmp[++tmp[0]]=p[i].x;
        for (int j=p[i].r;j!=i;j=p[j].r)
            del(p[j].y);
        search(first);
        if (cnt==2)
            return;
        tmp[0]--;
        for (int j=p[i].l;j!=i;j=p[j].l)
            renew(p[j].y);
    }
    renew(t);
}
void print()
{
    int s[260];
    for (int i=1;i<=ans[0];i++)
    {
        int x=(ans[i]-1)/N,y=ans[i]%N;
        if (y==0)
            y=N;
        s[x+1]=y;
    }
    for (int i=1;i<=P;i++)
    {
        printf("%c",a[s[i]]);
        if (i%N==0)
            printf("\n");
    }
}
int main()
{
    for (int i=1;i<=16;i++)
        M[a[i]]=i;
    while (scanf("%d",&n)==1)
    {
        N=n*n;
        P=N*N;
        for (int i=1;i<=N;i++)
            scanf("%s",b[i]+1);
        cnt=tmp[0]=0;
        build();
        search(true);
        if (cnt==0)
            printf("No Solution\n");
        else if (cnt==2)
            printf("Multiple Solutions\n");
        else
        {
            bool flag=true;
            for (int i=1;i<=N;i++)
                for (int j=1;j<=N;j++)
                {
                    if (b[i][j]=='.')
                        continue;
                    char ch=b[i][j];
                    b[i][j]='.';
                    cnt=tmp[0]=0;
                    build();
                    search(false);
                    if (cnt!=2)
                    {
                        flag=false;
                        goto out;
                    }
                    b[i][j]=ch;
                }
out:
            if (!flag)
                printf("Not Minimal\n");
            else
                print();
        }
    }
    return(0);
}

