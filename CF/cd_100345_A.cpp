#include <cstdio>
#include <cctype>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
FILE *in,*out;
struct reference
{
    bool isbook;
    vector <vector <string> > author;
    string title,publisher;
    int volume,number,year,page1,page2;
    reference()
    {
        volume=number=year=page1=page2=0;
    }
    void update(const string &name,const string &value)
    {
        if (name=="author")
            parse(value);
        else if (name=="title")
            title=value;
        else if (name=="journal" || name=="publisher")
            publisher=value;
        else if (name=="year")
            sscanf(value.c_str(),"%d",&year);
        else if (name=="volume")
            sscanf(value.c_str(),"%d",&volume);
        else if (name=="number")
            sscanf(value.c_str(),"%d",&number);
        else
            sscanf(value.c_str(),"%d--%d",&page1,&page2);
    }
    void parse(const string &value)
    {
        string name;
        stringstream sin(value);
        vector <string> now,tmp;
        while (sin>>name)
            now.push_back(name);
        now.push_back("and");
        for (int i=0;i<now.size();i++)
        {
            if (now[i]=="and")
            {
                tmp.insert(tmp.begin(),tmp.back());
                tmp.pop_back();
                author.push_back(tmp);
                tmp.clear();
                continue;
            }
            tmp.push_back(now[i]);
        }
        sort(author.begin(),author.end());
    }
    void print(int id)
    {
        fprintf(out,"[%d] ",id);
        for (int i=0;i<author.size();i++)
        {
            if (i)
                fprintf(out,", ");
            fprintf(out,"%s",author[i][0].c_str());
            for (int j=1;j<author[i].size();j++)
                fprintf(out," %c.",author[i][j][0]);
        }
        fprintf(out," %s",title.c_str());
        if (!isbook)
        {
            fprintf(out," // %s",publisher.c_str());
            if (volume!=0)
                fprintf(out,", %d",volume);
            if (number!=0)
                fprintf(out," (%d)",number);
            fprintf(out," -- %d",year);
            if (page1!=0)
            {
                fprintf(out," -- ");
                if (page2!=0)
                    fprintf(out,"pp. %d--%d",page1,page2);
                else
                    fprintf(out,"p. %d",page1);
            }
        }
        else
        {
            if (volume!=0)
                fprintf(out,", Vol. %d",volume);
            fprintf(out," -- %s, %d",publisher.c_str(),year);
        }
        fprintf(out,"\n");
    }
};
inline bool operator <(const reference &a,const reference &b)
{
    return(a.author<b.author || a.author==b.author && (a.title<b.title || a.title==b.title && a.volume<b.volume));
}
string s;
pair <string,string> calc(int l,int r)
{
    int pos;
    for (int i=l;i<=r;i++)
        if (s[i]=='=')
        {
            pos=i;
            break;
        }
    pair <string,string> ret;
    for (int i=l;i<pos;i++)
        if (!isspace(s[i]))
            ret.first+=s[i];
    int start,len;
    for (int i=pos+1;i<=r;i++)
        if (s[i]=='"')
        {
            start=i+1;
            break;
        }
    for (int i=r;i>pos;i--)
        if (s[i]=='"')
        {
            len=i-start;
            break;
        }
    ret.second=s.substr(start,len);
    return(ret);
}
reference parse(int l,int r,const string &title)
{
    reference ret;
    ret.isbook=title=="@book";
    int pos=l;
    bool flag=true;
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='"')
            flag=!flag;
        if (flag && s[i]==',')
        {
            pair <string,string> tmp=calc(pos,i-1);
            ret.update(tmp.first,tmp.second);
            pos=i+1;
        }
    }
    return(ret);
}
char buf[1000000];
int main()
{
    in=fopen("bibtex.in","r");
    out=fopen("bibtex.out","w");
    while (fgets(buf,1000000,in))
        s+=buf;
    bool flag=true;
    string title;
    int tmp;
    vector <reference> a;
    for (int i=0;i<s.size();i++)
    {
        if (isspace(s[i]))
            continue;
        if (s[i]=='{')
        {
            flag=false;
            tmp=i;
        }
        else if (s[i]=='}')
        {
            s[i]=',';
            a.push_back(parse(tmp+1,i,title));
            flag=true;
            title="";
        }
        else if (flag)
            title+=s[i];
    }
    sort(a.begin(),a.end());
    for (int i=0;i<a.size();i++)
        a[i].print(i+1);
    return(0);
}

