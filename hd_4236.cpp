/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    void run() throws Exception
    {
        int T=nextInt();
        while (T-->0)
        {
            int id=nextInt(),n=nextInt();
            String s=next();
            writer.print(id+" ");
            for (int i=0;i<s.length();i++)
                for (int j=0;j<n;j++)
                    writer.print(s.charAt(i));
            writer.println();
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

