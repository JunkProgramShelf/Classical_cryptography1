/*
*   Affine cipher Encryption program
*   
*   Programing by JunkProgramShelf
*   2024.6.12
*/


#include<stdio.h>
#define N 1000
#define m 66

int main(){
    FILE *input_f;
    FILE *output_f;
    char alphabet[m]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!?,.0123456789";
    int a=13;
    int b=7;
    int i=0;
    int j=0;
    int Enc_data=0;



    char input_filename[]="Code_data.txt";
    char output_filename[]="Affine_Encrypted_data.txt";
    char input_data[N]={};

    if(!(input_f=fopen(input_filename,"r"))){
        printf("file open error\n");
        return -1;
    }
    if(!(output_f=fopen(output_filename,"w"))){
        printf("file open error\n");
        return -1;
    }
    
    //If file input yourself
    /*
    if(!(input_f=fopen(argv[1],"r"))){
        printf("file open error\n");
        return -1;
    }
    if(!(output_f=fopen(argv[2],"w"))){
        printf("file open error\n");
        return -1;
    }
    */

    //Encryption(a=13.b=7,)
    //printf("debug1");
    while(fgets(input_data,sizeof(input_data),input_f) != NULL){
        for(i=0;i<sizeof(input_data);i++){
            //printf("debug2");
            //printf("%c",input_data[i]);
            if(input_data[i]=='\n' || input_data[i]=='\0'){fprintf(output_f,"\n");break;}
            //input_data[i]+=key;
            for(j=0;j<m;j++){
                if(input_data[i]==alphabet[j]){
                    //printf("debug3");
                    Enc_data=(a*j+b) % m;
                    //debug
                    //printf("%c:\nEncrypted:%d,%c\n",input_data[i],Enc_data,alphabet[Enc_data]);
                    fprintf(output_f,"%c",alphabet[Enc_data]);
                    //printf("<=====================>\n");
                    break;
                }
            }
        }        
    }

    fclose(input_f);
    fclose(output_f);
    return 0;
}