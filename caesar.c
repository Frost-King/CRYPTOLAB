#include <stdio.h>
#include <ctype.h>
#include <string.h>
void main(){
char mes[50],en[50],de[50];
int elen,mlen,key;
char ch;
printf("Enter the message: ");
fgets(mes,sizeof(mes),stdin);
mes[strcspn(mes,"\n")]='\0';
printf("Enter the key: ");
scanf("%d",&key);
mlen=strlen(mes);
for(int i=0;i<mlen;i++){
    ch=mes[i];
    if(isalnum(ch)){
        if(isupper(ch)){
            ch=((((ch-'A')+key)%26)+'A');
        }
        if(islower(ch)){
            ch=((((ch-'a')+key)%26)+'a');
        }
        if(isdigit(ch)){
            ch=((((ch-'0')+key)%10)+'0');
        }
        en[i]=ch;
    }
    else{
        en[i]=ch;
    }
}
en[mlen]='\0';
elen=strlen(en);
for(int i=0;i<elen;i++){
    ch=en[i];
    if(isalnum(ch)){
        if(isupper(ch)){
            ch=((((ch-'A')-key+26)%26)+'A');
        }
        if(islower(ch)){
            ch=((((ch-'a')-key+26)%26)+'a');
        }
        if(isdigit(ch)){
            ch=((((ch-'0')-key+26)%10)+'0');
        }
        de[i]=ch;
    }
    else{
        de[i]=ch;
    }
}
de[elen]='\0';
printf("Original Message:%s\n",mes);
printf("Encrypted Message:%s\n",en);
printf("Decrypted Message:%s\n",de);
}
