#include<iostream>
using namespace std;

char m[5][5];

void makeMatrix(string k){
    string s="",a="ABCDEFGHIKLMNOPQRSTUVWXYZ";

    for(char c:k)
        if(s.find(c)==-1)
            s+=c;

    for(char c:a)
        if(s.find(c)==-1)
            s+=c;

    int x=0;

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            m[i][j]=s[x++];
}

void find(char c,int &r,int &col)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(m[i][j]==c)
            {
                r=i;
                col=j;
            }
        }
    }
}

string enc(string t)
{
    string c="";

    for(int i=0;i<t.size();i+=2){
        int r1,c1,r2,c2;

        find(t[i],r1,c1);
        find(t[i+1],r2,c2);

        if(r1==r2){
            c+=m[r1][(c1+1)%5];
            c+=m[r2][(c2+1)%5];
        }

        else if(c1==c2){
            c+=m[(r1+1)%5][c1];
            c+=m[(r2+1)%5][c2];
        }

        else{
            c+=m[r1][c2];
            c+=m[r2][c1];
        }
    }

    return c;
}

string dec(string t){
    string c="";

    for(int i=0;i<t.size();i+=2){
        int r1,c1,r2,c2;

        find(t[i],r1,c1);
        find(t[i+1],r2,c2);

        if(r1==r2)
        {
            c+=m[r1][(c1+4)%5];
            c+=m[r2][(c2+4)%5];
        }

        else if(c1==c2)
        {
            c+=m[(r1+4)%5][c1];
            c+=m[(r2+4)%5][c2];
        }

        else
        {
            c+=m[r1][c2];
            c+=m[r2][c1];
        }
    }

    return c;
}

int main(){
    string k,t;

    cout<<"Key: ";
    cin>>k;

    cout<<"Text: ";
    cin>>t;

    makeMatrix(k);

    string e=enc(t);

    cout<<"Encrypted = "<<e<<endl;
    cout<<"Decrypted = "<<dec(e);

    return 0;
}