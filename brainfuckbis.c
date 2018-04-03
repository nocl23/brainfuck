#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

  FILE *file = fopen(argv[1], "rb");
  long length_file;
  char *buffer = 0;
  char caractere;
  int loop;
  char loop_char;



//Copy the file into a buffer
  if (file != NULL){

    fseek( file , 0 , SEEK_END);
    length_file = ftell(file);
    fseek(file,0,SEEK_SET);

    buffer = (char*)malloc ((length_file+1)*sizeof(char));

    if(buffer){
      fread(buffer,sizeof(char), length_file, file);
    }

    fclose(file);

    buffer[length_file] = '\0';

    char *ptr = buffer;

    for(int i = 0; i< length_file; i++){
      caractere = buffer[i];
      if(caractere == '>'){
        ++ptr;
      }
      else if(caractere == '<'){
          ptr--;
      }
      else if(caractere == '+'){
          ++(*ptr);
      }
      else if(caractere == '-'){
          --(*ptr);
      }
      else if(caractere == '.'){
          putchar(*ptr);
      }
      else if(caractere == ','){
        (*ptr) = getchar();
      }
      else if(caractere == '['){
      /*TODO*/
      }
      else if(caractere == ']'){
      /*TODO*/
      }

      //printf("buffer[%d] == %c\n", i, buffer[i]);
    }

    //printf("buffer = %s\n", buffer);

  }

  else{
    printf("Impossible d'ouvrir le fichier test.txt");
  }
return 0;
}
