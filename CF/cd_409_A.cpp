#include <cstdio>
#include <cstring>
char a[30],b[30];
int sign(char x,char y)
{
    if (x==y)
        return(0);
    if (x=='8' && y=='[' || x=='[' && y=='(' || x=='(' && y=='8')
        return(1);
    return(-1);
}
int main()
{
    scanf("%s%s",a,b);
    int n=strlen(a),x=0,y=0;
    for (int i=0;i<n;i+=2)
    {
        int p=sign(a[i],b[i]);
        if (p==1)
            x++;
        if (p==-1)
            y++;
    }
    if (x==y)
        printf("TIE\n");
    else
        printf("TEAM %d WINS\n",1+(x<y));
    return(0);
}

