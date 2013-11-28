#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
struct piece
{
    char kind;
    int row,col;
    piece(char k,int x,int y):kind(k),row(x),col(y){}
};
vector <piece> black,white;
char s[100000];
int c[260];
inline bool operator <(const piece &a,const piece &b)
{
    if (a.kind!=b.kind)
        return(c[a.kind]<c[b.kind]);
    return(a.row<b.row || a.row==b.row && a.col<b.col);
}
int main()
{
    c['k']=0,c['q']=1,c['r']=2,c['b']=3,c['n']=4,c['p']=5;
    gets(s);
    for (int i=8;i;i--)
    {
        gets(s);
        int t=2;
        for (int j=1;j<=8;j++)
        {
            if (isupper(s[t]))
                white.push_back(piece(tolower(s[t]),i,j));
            if (islower(s[t]))
                black.push_back(piece(s[t],-i,j));
            t+=4;
        }
        gets(s);
    }
    sort(white.begin(),white.end());
    sort(black.begin(),black.end());
    printf("White: ");
    for (int i=0;i<white.size();i++)
    {
        if (white[i].kind!='p')
            printf("%c",toupper(white[i].kind));
        printf("%c%d%c",white[i].col+'a'-1,white[i].row,i==white.size()-1?'\n':',');
    }
    printf("Black: ");
    for (int i=0;i<black.size();i++)
    {
        if (black[i].kind!='p')
            printf("%c",toupper(black[i].kind));
        printf("%c%d%c",black[i].col+'a'-1,-black[i].row,i==black.size()-1?'\n':',');
    }
    return(0);
}

