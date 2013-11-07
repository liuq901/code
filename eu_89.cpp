#include <cstdio>
#include <cstring>
bool before(char a,char b)
{
    if (a=='I')
        return(b=='V' || b=='X');
    if (a=='X')
        return(b=='L' || b=='C');
    if (a=='C')
        return(b=='D' || b=='M');
    return(false);
}
int get(char ch)
{
    switch (ch)
    {
    case 'I':
        return(1);
    case 'V':
        return(5);
    case 'X':
        return(10);
    case 'L':
        return(50);
    case 'C':
        return(100);
    case 'D':
        return(500);
    case 'M':
        return(1000);
    }
}
int toNum(char *s)
{
    int n=strlen(s),ans=0;
    for (int i=0;i<n;i++)
        if (i+1<n && before(s[i],s[i+1]))
            ans-=get(s[i]);
        else
            ans+=get(s[i]);
    return(ans);
}
int calc(int x)
{
    if (x==4 || x==9)
        return(2);
    if (x<=3)
        return(x);
    return(x-4);
}
int toRoman(int n)
{
    int ans=0;
    if (n/1000==4)
    {
        ans=4;
        n%=1000;
    }
    while (n)
    {
        ans+=calc(n%10);
        n/=10;
    }
    return(ans);
}
int main()
{
    int ans=0,sum=0;
    char s[100];
    while (scanf("%s",s)==1)
    {
        int n=toNum(s);
        ans+=strlen(s)-toRoman(n);
    }
    printf("%d\n",ans);
    return(0);
}

