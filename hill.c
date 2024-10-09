#include <stdio.h>
#include <string.h>
void main(){
int i,j;
int key[2][2]={{2,3},{3,6}};
char mes[30];
printf("Enter the message: ");
scanf("%s",mes);
int len=strlen(mes);
char en[len],num[len],d[len];
for(int i=0;i<len;i++){
    num[i]=mes[i]-'a';
}
for(i=0;i<len;i+=2){
    en[i]=((num[i]*key[0][0])%26+(num[i+1]*key[0][1])%26)%26;
    en[i+1]=((num[i]*key[1][0])%26+(num[i+1]*key[1][1])%26)%26;
}
char enc[len+1];
for(i=0;i<len;i++){
    enc[i]=en[i]+'a';
}
enc[len]='\0';
printf("The Original message:%s\n",mes);
printf("Encrypted String:%s\n",enc);
int det=(key[0][0]*key[1][1]-key[0][1]*key[1][0])%26;
if(det<0) det+=26;
int det_inv;
for(i=0;i<26;i++){
    if((det*i)%26==1){
        det_inv=i;
        break;
    }
}
int adj[2][2]={{key[1][1],-key[0][1]},{-key[1][0],key[0][0]}};
int inv[2][2];
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        inv[i][j]=(adj[i][j]*det_inv)%26;
        if(inv[i][j]<0) inv[i][j]+=26;
    }
}
for(i=0;i<len;i+=2){
    d[i]=((en[i]*inv[0][0])%26 + (en[i+1]*inv[0][1])%26)%26;
    d[i+1]=((en[i]*inv[1][0])%26 + (en[i+1]*inv[1][1])%26)%26;
}
char dec[len+1];
for(i=0;i<len;i++){
    dec[i]=d[i]+'a';
}
dec[len]='\0';
printf("Decrypted String:%s\n",dec);
}
