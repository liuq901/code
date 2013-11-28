#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const string a[8]={"A+","A-","B+","B-","AB+","AB-","O+","O-"};
char buf[3][100];
string F,M,C;
vector <string> ans;
void checkAB(string F,string M,string C,string s)
{
    if (F!="AB")
        swap(F,M);
    if (M=="O")
    {
        if (C=="A" || C=="B")
            ans.push_back(s);
        return;
    }
    if (C!="O")
        ans.push_back(s);
}
void check(string F,string M,string C,string s)
{
    char c1,c2,c3;
    c1=F[F.size()-1],c2=M[M.size()-1],c3=C[C.size()-1];
    if (c1=='-' && c2=='-' && c3!='-')
        return;
    F.erase(F.size()-1);
    M.erase(M.size()-1);
    C.erase(C.size()-1);
    if (F=="AB" || M=="AB")
    {
        checkAB(F,M,C,s);
        return;
    }
    if (F>M)
        swap(F,M);
    if (F=="A" && M=="B")
    {
        ans.push_back(s);
        return;
    }
    if (F=="A")
    {
        if (C=="A" || C=="O")
            ans.push_back(s);
        return;
    }
    if (F=="B")
    {
        if (C=="B" || C=="O")
            ans.push_back(s);
        return;
    }
    if (C=="O")
        ans.push_back(s);
} 
void print()
{
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    printf(" ");
    if (ans.empty())
    {
        printf("IMPOSSIBLE");
        return;
    }
    if (ans.size()==1)
    {
        printf("%s",ans[0].c_str());
        return;
    }
    printf("{");
    for (int i=0;i<ans.size();i++)
    {
        if (i)
            printf(", ");
        printf("%s",ans[i].c_str());
    }
    printf("}");
}
int main()
{
    while (1)
    {
        scanf("%s%s%s",buf[0],buf[1],buf[2]);
        F=buf[0],M=buf[1],C=buf[2];
        if (F=="E" && M=="N" && C=="D")
            break;
        int k;
        if (F=="?")
            k=0;
        else if (M=="?")
            k=1;
        else
            k=2;
        ans.clear();
        for (int i=0;i<8;i++)
        {
            if (k==0)
                F=a[i];
            else if (k==1)
                M=a[i];
            else
                C=a[i];
            check(F,M,C,a[i]);
        }
        static int id=0;
        printf("Case %d:",++id);
        if (k==0)
            print();
        else
            printf(" %s",F.c_str());
        if (k==1)
            print();
        else
            printf(" %s",M.c_str());
        if (k==2)
            print();
        else
            printf(" %s",C.c_str());
        printf("\n");
    }
    return(0);
}

