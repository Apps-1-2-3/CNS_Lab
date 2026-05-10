#include<iostream>
#include <cctype>
using namespace std;

char m[5][5];

void makeMatrix(string k){
    string s="",a="ABCDEFGHIKLMNOPQRSTUVWXYZ";

    for(char &c:k){
        c=toupper(c);
        if(c=='J') c='I';

        if(s.find(c)==-1)
            s+=c;
    }

    for(char c:a)
        if(s.find(c)==-1)
            s+=c;

    int x=0;

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            m[i][j]=s[x++];
}

void findPos(char c,int &r,int &col){

    if(c=='J') c='I';

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(m[i][j]==c){
                r=i;
                col=j;
            }
}

string process(string t,int dir){

    string c="";

    for(int i=0;i<t.size();i+=2){

        int r1,c1,r2,c2;

        findPos(t[i],r1,c1);
        findPos(t[i+1],r2,c2);

        if(r1==r2){
            c+=m[r1][(c1+dir+5)%5];
            c+=m[r2][(c2+dir+5)%5];
        }

        else if(c1==c2){
            c+=m[(r1+dir+5)%5][c1];
            c+=m[(r2+dir+5)%5][c2];
        }

        else{
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

    for(char &c:t){
        c=toupper(c);
        if(c=='J') c='I';
    }

    if(t.size()%2)
        t+='X';

    makeMatrix(k);

    string e=process(t,1);

    cout<<"Encrypted = "<<e<<endl;
    cout<<"Decrypted = "<<process(e,-1);

    return 0;
}
