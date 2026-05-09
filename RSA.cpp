
#include <iostream>
using namespace std;

int gcd(int a,int b){
    while(b){
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int mod(int b,int p,int m){
    int r=1;
    while(p--){
        r=(r*b)%m;
    }
    return r;
}

int main() {
    int p,q,n,phi,e,d=1,msg,c,dec;

    cout<<"Enter two prime numbers p and q: ";
    cin>>p>>q;

    n=p*q;
    phi=(p-1)*(q-1);

    cout<<"n = "<<n<<endl;
    cout<<"phi = "<<phi<<endl;

    cout<<"Enter e such that gcd(e, phi) = 1: ";
    cin>>e;

    if(gcd(e,phi)!=1){
        cout<<"Invalid e"<<endl;
        return 0;
    }

    while((e*d)%phi!=1)
        d++;

    cout<<"Public Key  = ("<<e<<", "<<n<<")"<<endl;
    cout<<"Private Key = ("<<d<<", "<<n<<")"<<endl;

    cout<<"Enter message less than "<<n<<": ";
    cin>>msg;

    c=mod(msg,e,n);
    cout<<"Encrypted message = "<<c<<endl;

    dec=mod(c,d,n);
    cout<<"Decrypted message = "<<dec<<endl;

    return 0;
}
