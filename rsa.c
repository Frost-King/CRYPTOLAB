#include <stdio.h>
int powMod(int base,int exp,int mod){
int result=1;
base=base%mod;
while(exp>0){
if(exp%2==1){
result=(result*base)%mod;
}
exp = exp >> 1;
base = (base * base) % mod;
}
return result;
}
int gcd(int a , int b){
return b==0 ? a : gcd(b,a%b);
}
int findModInverse(int e,int phi){
for(int d=1;d<phi;d++){
if((e*d)%phi==1){
return d;
}
}
return -1;
}
int main(){
int C,D,M,N,p=61,q=53,n,phi,e=17;
n=p*q;
phi=(p-1)*(q-1);
int d=findModInverse(e,phi);
if(d==-1){
printf("Cannot find valid d. Exiting\n");
return -1;
}
printf("Enter the message: ");
scanf("%d",&M);
C=powMod(M,e,n);
D=powMod(C,d,n);
printf("Original message: %d\n",M);
printf("Encrypted message: %d\n",C);
printf("Decrypted message: %d\n",D);
return 0;
}
