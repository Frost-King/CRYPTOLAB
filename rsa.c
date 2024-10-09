#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int powMod(int base,int exp,int mod){
int result=1;
base=base%mod;
while(exp>0){
    if(exp%2==1){
        result=(result*base)%mod;
    }
    exp=exp>>1;
    base=(base*base)%mod;
}
return result;
}
int main(){
int p,q,m,n,phi,e=7,d=1,C,M,D;
printf("Enter p and q: ");
scanf("%d%d",&p,&q);
printf("Enter the message M: ");
scanf("%d",&M);
n=p*q;
phi=(p-1)*(q-1);
while((e*d)%phi!=1){
d++;
if(d>phi){
printf("Couldn't find a valid d. Please check your inputs.\n");
return 1;
}
}
C=powMod(M,e,n);
D=powMod(C,d,n);
printf("Given message: %d\n",M);
printf("Encrypted: %d\n",C);
printf("Decrypted: %d\n",D);
return 0;
}
