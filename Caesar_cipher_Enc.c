/*
*   Caesar cipher Encryption program
*   
*   Programing by JunkProgramShelf
*   2024.6.12
*/

#include<stdio.h>
#define N 1000
#define key 3

int main(int argc,char** argv){
    FILE *input_f;
    FILE *output_f;
    char input_filename[]="test_data.txt";
    char output_filename[]="Caesar_Encrypted_data.txt";
    int i=0;
    char data;
    
    char text_data[N]={};
    
    
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
    if(!(output_f=fopen(argv[1],"w"))){
        printf("file open error\n");
        return -1;
    }
    */

    //File roading and Encryption
    while(fgets(text_data,sizeof(text_data),input_f) != NULL){
        for(i=0;i<sizeof(text_data);i++){
            if(text_data[i]=='\n' || text_data[i]=='\0'){break;}
            text_data[i]+=key;
            
        }
        //output
        fprintf(output_f,"%s",text_data);

    } 
    //file closing
    fclose(input_f);
    fclose(output_f);
    return 0;
}