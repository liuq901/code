#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char a[][20]={"100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111",
    "1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
char s[1000000];
string change(char ch)
{
    if (ch==' ')
        return("101");
    if (ch=='\'')
        return("000000");
    if (ch==',')
        return("000011");
    if (ch=='-')
        return("10010001");
    if (ch=='.')
        return("010001");
    if (ch=='?')
        return("000001");
    return(a[ch-'A']);
}
int main()
{
    while (gets(s))
    {
        string now;
        int len=strlen(s);
        for (int i=0;i<len;i++)
            now+=change(s[i]);
        while (now.size()%5!=0)
            now+="0";
        for (int i=0;i<now.size();i+=5)
        {
            int tmp=0;
            for (int j=0;j<5;j++)
                tmp=tmp<<1|now[i+j]-'0';
            if (tmp<26)
                printf("%c",'A'+tmp);
            else if (tmp==26)
                printf(" ");
            else if (tmp==27)
                printf(".");
            else if (tmp==28)
                printf(",");
            else if (tmp==29)
                printf("-");
            else if (tmp==30)
                printf("'");
            else
                printf("?");
        }
        printf("\n");
    }
    return(0);
}

