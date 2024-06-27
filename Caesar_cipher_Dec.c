/*
*   Caesar cipher Decryption program
*   
*   Programing by JunkProgramShelf
*   2024.6.12
*/

#include<stdio.h>

#define array_size 1000
#define key 3

int main(int argc,char** argv){
    FILE *cipher_f;
    FILE *decrypted_f;
    char input_filename[]="Caesar_Encrypted_data.txt";
    char output_filename[]="Caesar_Decrypted_data.txt";
    int i=0;
    char text_data[array_size]={};

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
    //decrypted
    while(fgets(text_data,sizeof(text_data),cipher_f) != NULL){
        for(i=0;i<sizeof(text_data);i++){
            if(text_data[i]=='\n' ||text_data[i]=='\0'{break;}
            text_data[i]-=key;
            
        }
        //output
        fprintf(decrypted_f,"%s",text_data);
       
        
    } 


}