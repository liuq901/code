#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char s[1000010];
int sum[1000010],pos[1000010],b[1000010];
void work(int pos,int len)
{
    int sum=0,top=0;
    for (int i=1;i<=pos;i++)
        if (s[i]=='a' || s[i]=='i')
        {
            sum++;
            b[++top]=i;
        }
        else
            top--;
    for (int i=sum+1;i<=len/2;i++)
        s[++pos]='a';
    for (int i=sum+1;i<=len/2;i++)
        s[++pos]='e';
    while (top)
    {
        s[++pos]=s[b[top]]=='a'?'e':'o';
        top--;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s+1);
        int len=strlen(s+1);
        int top=0;
        string ans;
        for (int i=1;i<=len;i++)
        {
            sum[i]=sum[i-1];
            pos[i]=b[top];
            if (s[i]=='a' || s[i]=='i')
            {
                b[++top]=i;
                sum[i]++;
            }
            else
            {
                if (top==0 || s[i]=='e' && s[b[top]]!='a' || s[i]=='o' && s[b[top]]!='i')
                {
                    ans="INVALID";
                    break;
                }
                top--;
            }
        }
        if (top!=0)
            ans="INVALID";
        if (ans=="")
        {
            for (int i=len;i;i--)
            {
                if (s[i]=='a')
                {
                    if (s[pos[i]]=='a')
                    {
                        s[i]='e';
                        work(i,len);
                        ans=s+1;
                        break;
                    }
                    s[i]='i';
                    work(i,len);
                    ans=s+1;
                    break;
                }
                if (s[i]=='e' && sum[i-1]<len/2)
                {
                    s[i]='i';
                    work(i,len);
                    ans=s+1;
                    break;
                }
                if (s[i]=='i' && s[pos[i]]=='i')
                {
                    s[i]='o';
                    work(i,len);
                    ans=s+1;
                    break;
                }
            }
            if (ans=="")
                ans="ULTIMATE";
        }
        printf("%s\n",ans.c_str());
    }
    return(0);
}

