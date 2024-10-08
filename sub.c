#include <stdio.h>
#include <ctype.h>
void main(){
char sub[]="QWERTYUIOPASDFGHJKLZXCVBNM";
char subl[]="qwertyuiopasdfghjklzxcvbnm";
char mes[50],en[50],de[50];
int mlen,i,j,in;
char ch;
printf("Enter the message: ");
fgets(mes,sizeof(mes),stdin);
mes[strcspn(mes,"\n")]='\0';
mlen=strlen(mes);
for(i=0;i<mlen;i++){
    ch=mes[i];
    if(isalpha(ch)){
        if(isupper(ch)){
            in=mes[i]-'A';
            en[i]=sub[in];
        }
        if(islower(ch)){
            in=mes[i]-'a';
            en[i]=subl[in];
        }
    }
    else{
        en[i]=ch;
    }
}
en[mlen]='\0';
for(i=0;i<mlen;i++){
    ch=en[i];
    for(j=0;j<26;j++){
        if(isalpha(ch)){
            if(isupper(ch)){
                if(en[i]==sub[j]){
                    de[i]=j+'A';
                }
            }
            if(islower(ch)){
                if(en[i]==subl[j]){
                    de[i]=j+'a';
                }
            }
        }
        else{
            de[i]=ch;
        }
    }
}
en[mlen]='\0';
printf("The Original Message:%s\n",mes);
printf("The encrypted message:%s\n",en);
printf("The decrypted message:%s\n",de);
}
