/*
*   //Substitution cipher Dencryption program
*   
*   Programing by JunkProgramShelf
*   2024.6.12
*/
#include<stdio.h>
#include<stdlib.h>
#define N 10000

int main(int argc,char** argv){

    FILE *cipher_f;
    FILE *decrypted_f;
    int i=0;
    int j=0;
    int k=0;
    int code1=0;
    int code2=0;
    char cipher_data[N]={};
    char decrypted_data[N]={};
    char input_filename[]="Encrypted_Substitution_cipher_data.txt";
    char output_filename[]="Decrypted_Substitution_cipher_data.txt";

    //code table1
    char code_table1[6][5]={
        {'A','B','C','D','E'},
        {'F','G','H','I','J'},
        {'K','L','M','N','O'},
        {'P','Q','R','S','T'},
        {'U','V','W','X','Y'},
        {'Z','!','?',',','.'},
    };
    //code table2
    char code_table2[6][5]={
        {'a','b','c','d','e'},
        {'f','g','h','i','j'},
        {'k','l','m','n','o'},
        {'p','q','r','s','t'},
        {'u','v','w','x','y'},
        {'z','@',':','$','&'},
    };

    if(!(cipher_f=fopen(input_filename,"r"))){
        printf("input file open error\n");
        return -1;
    }
    if(!(decrypted_f=fopen(output_filename,"w"))){
        printf("output file open error\n");
        return -1;
    }

    /*
    if(!(cipher_f=fopen(argv[1],"r"))){
        printf("file open error\n");
        return -1;
    }
    if(!(decrypted_f_f=fopen(argv[2],"w"))){
        printf("file open error\n");
        return -1;
    }
    */

    while(fgets(cipher_data,sizeof(cipher_data),cipher_f) != NULL){
        for(i=0;i<sizeof(cipher_data);i+=3){
            //printf("%c",cipher_data[i]);
            if(cipher_data[i]=='\n' || cipher_data[i]=='\0'){fprintf(decrypted_f,"\n");break;}
            if(cipher_data[i]=='0'){
                code1=cipher_data[i+1]-'0';
                code2=cipher_data[i+2]-'0';
               //printf("(%d,%d)%c\n",code1,code2,code_table1[code1][code2]);
                fprintf(decrypted_f,"%c",code_table1[code1][code2]);
            }else if(cipher_data[i]=='1'){
                code1=cipher_data[i+1]-'0';
                code2=cipher_data[i+2]-'0';
               // printf("(%d,%d)%c\n",code1,code2,code_table2[code1][code2]);
                fprintf(decrypted_f,"%c",code_table2[code1][code2]);

            }
        }

    }

    fclose(cipher_f);
    fclose(decrypted_f);
    return 0;
}