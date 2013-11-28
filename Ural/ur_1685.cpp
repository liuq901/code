#include <cstdio>
#include <cstring>
char s[20010],ans[20010];
int m;
void work(int l,int r)
{
    if (l>r)
        return;
    int mid=l+r>>1;
    work(l+1,mid);
    ans[m++]=s[l];
    work(mid+1,r);
}
int main()
{
    gets(s);
    int n=strlen(s);
    work(0,n-1);
    ans[m]='\0';
    printf("%s\n",ans);
    return(0);
}

