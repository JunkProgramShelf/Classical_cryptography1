
/*
*   //Substitution cipher Encryption program
*   
*   Programing by JunkProgramShelf
*   2024.6.12
*/
#include<stdio.h>
#define N 10000

int main(int argc,char** argv){

    FILE *input_f;
    FILE *output_f;
    int i=0;
    int j=0;
    int k=0;
    char code_1;
    char code_2;
    char input_filename[]="test_data.txt";
    char output_filename[]="Encrypted_Substitution_cipher_data.txt";
    char input_data[N]={};

    //0
    char code_table1[6][5]={
        {'A','B','C','D','E'},
        {'F','G','H','I','J'},
        {'K','L','M','N','O'},
        {'P','Q','R','S','T'},
        {'U','V','W','X','Y'},
        {'Z','!','?',',','.'},
    };
    //1
    char code_table2[6][5]={
        {'a','b','c','d','e'},
        {'f','g','h','i','j'},
        {'k','l','m','n','o'},
        {'p','q','r','s','t'},
        {'u','v','w','x','y'},
        {'z','@',':','$','&'},
    };


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

    while(fgets(input_data,sizeof(input_data),input_f) != NULL){
        for(i=0;i<sizeof(input_data);i++){
            if(input_data[i]=='\n'  || input_data[i]=='\0'){break;}
            //printf("%c\n",input_data[i]);
            for(j=0;j<6;j++){
                for(k=0;k<5;k++){
                    //output and Encryption
                    if(input_data[i]==code_table1[j][k]){
                        //printf("table1,%c::(%d,%d)\n",code_table1[j][k],j,k);
                        fprintf(output_f,"%d%d%d",0,j,k);
                    }else if(input_data[i]==code_table2[j][k]){
                        //printf("table2,%c::(%d,%d)\n",code_table2[j][k],j,k);
                        fprintf(output_f,"%d%d%d",1,j,k);

                    }
                    
                } 
            }
        }
        fprintf(output_f,"\n");

    }
    

    
    
    fclose(input_f);
    fclose(output_f);
    return 0;
}

