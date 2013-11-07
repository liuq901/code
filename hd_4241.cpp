/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    String fix(char ch)
    {
        if (ch=='\\' || ch=='#')
            return("\\"+ch);
        return(""+ch);
    }
    String fill(String s,int n)
    {
        while (s.length()<n)
            s="0"+s;
        return(s);
    }
    void run() throws Exception
    {
        String p="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
        int test=nextInt();
        while (test-->0)
        {
            int id=nextInt();
            String s=next(),a="";
            for (int i=0;i<s.length();i++)
            {
                String temp=Integer.toBinaryString(Integer.parseInt(s.substring(i,i+1),16));
                a+=fill(temp,4);
            }
            String ans="";
            int now=0,num=0;
            while (now+4<=a.length())
            {
                String op=a.substring(now,now+4);
                now+=4;
                if (op.equals("0001"))
                {
                    int n=Integer.parseInt(a.substring(now,now+10),2);
                    now+=10;
                    num+=n;
                    for (int i=1;i<=n/3;i++)
                    {
                        ans+=String.format("%03d",Integer.parseInt(a.substring(now,now+10),2));
                        now+=10;
                    }
                    if (n%3==2)
                    {
                        ans+=String.format("%02d",Integer.parseInt(a.substring(now,now+7),2));
                        now+=7;
                    }
                    if (n%3==1)
                    {
                        ans+=Integer.parseInt(a.substring(now,now+4),2);
                        now+=4;
                    }
                }
                else if (op.equals("0010"))
                {
                    int n=Integer.parseInt(a.substring(now,now+9),2);
                    now+=9;
                    num+=n;
                    for (int i=1;i<=n/2;i++)
                    {
                        int x=Integer.parseInt(a.substring(now,now+11),2);
                        now+=11;
                        char first=p.charAt(x/45),second=p.charAt(x%45);
                        ans+=fix(first)+fix(second);
                    }
                    if (n%2==1)
                    {
                        ans+=fix(p.charAt(Integer.parseInt(a.substring(now,now+6),2)));
                        now+=6;
                    }
                }
                else if (op.equals("0100"))
                {
                    int n=Integer.parseInt(a.substring(now,now+8),2);
                    now+=8;
                    num+=n;
                    for (int i=1;i<=n;i++)
                    {
                        int x=Integer.parseInt(a.substring(now,now+8),2);
                        if (x<0x20 || x>0x76)
                            ans+="\\"+fill(Integer.toHexString(x).toUpperCase(),2);
                        else
                            ans+=(char)x;
                        now+=8;
                    }
                }
                else if (op.equals("1000"))
                {
                    int n=Integer.parseInt(a.substring(now,now+8),2);
                    now+=8;
                    num+=n;
                    for (int i=1;i<=n;i++)
                    {
                        ans+="#"+fill(Integer.toHexString(Integer.parseInt(a.substring(now,now+13),2)).toUpperCase(),4);
                        now+=13;
                    }
                }
                else if (op.equals("0000"))
                    break;
            }
            writer.println(id+" "+num+" "+ans);
        }
        reader.close();
        writer.close();
    }
    public static void main(String args[]) throws Exception
    {
        (new Main()).run();
    }
    BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer=new PrintWriter(System.out);
    StringTokenizer tokenizer=null;
    String next() throws Exception
    {
        for (;tokenizer==null || !tokenizer.hasMoreTokens();)
            tokenizer=new StringTokenizer(reader.readLine());
        return(tokenizer.nextToken());
    }
    int nextInt() throws Exception
    {
        return(Integer.parseInt(next()));
    }
}
*/
int main(){}

