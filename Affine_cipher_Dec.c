/*
*   Affine cipher Encryption program
*   
*   Programing by JunkProgramShelf
*   2024.6.12
*/
#include<stdio.h>
//array size
#define N 1000
//alphabet value
#define m 66

int main(){

    int a=13;
    int b=7;
    int i=0;
    int j=0;
    int k=0;
    int temp=0;
    int Dec_data=0;

    FILE *cipher_f;
    FILE *decrypted_f;
    char cipher_data[N]={};
    char decrypted_data[N]={};
    char input_filename[]="Affine_Encrypted_data.txt";
    char output_filename[]="Affine_Decrypted_data.txt";
    const char alphabet[m]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!?,.0123456789";

    if(!(cipher_f=fopen(input_filename,"r"))){
        printf("file open error\n");
        return -1;
    }
    if(!(decrypted_f=fopen(output_filename,"w"))){
        printf("file open error\n");
        return -1;
    }
    //If file input yourself
    /*
    if(!(cipher_f=fopen(argv[1],"r"))){
        printf("file open error\n");
        return -1;
    }
    if(!(decrypted_f=fopen(argv[2],"w"))){
        printf("file open error\n");
        return -1;
    }
    */

    while(fgets(cipher_data,sizeof(cipher_data),cipher_f) != NULL){
        
        for(i=0;i<sizeof(cipher_data);i++){
            printf("%c:::::\n",cipher_data[i]);
            if(cipher_data[i]=='\n' || cipher_data[i]=='\0'){fprintf(decrypted_f,"\n");break;}

            for(j=0;j<m;j++){
                if(cipher_data[i]==alphabet[j]){

                    for(k=1;k<m;k++){
                        //Calculation inverse of a
                        if(((m * k +1) % a)==0){
                            temp= (int)m+((m * k+1) / a);
                            printf("temp::%d\n",temp);
                            break;
                        }
                    }
                    //Decryption
                    Dec_data= (temp * ( j - b )) % m;
                    if(Dec_data<0){Dec_data+=m;}
                    //debug printf
                    //printf("j:::%d\n",j);
                    //printf("Dec_data::%d\n",Dec_data);
                    //printf("Decrypted_data::%c\n",alphabet[Dec_data]);
                    //printf("<=====================>\n");

                    //output
                    fprintf(decrypted_f,"%c",alphabet[Dec_data]);
                    break;
                }
            }
        }        
    }
    //closing process
    fclose(cipher_f);
    fclose(decrypted_f);
    return 0;
}