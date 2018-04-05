#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BF_MAX 30000

int main(int argc, char *argv[]){

  FILE *file = fopen(argv[1], "rb");
  long length_file;
  char *instructions = 0;
  char caractere;
  size_t i;
  unsigned char *memory;
  unsigned char *ptr;
  int is_char;

  //Copy the file into a instructions
  if (file != NULL){

    // Set the size of the file
    if(fseek( file , 0 , SEEK_END) != 0){
      perror("fseek");
    }

    length_file = ftell(file);
    fseek(file,0,SEEK_SET);

    //Tab with copy of the file
    if((instructions = (char*)malloc ((length_file+1)*sizeof(char))) == NULL){
      perror("malloc");
      return EXIT_FAILURE;
    };

    // Tab for the pointer
    if((memory = malloc(BF_MAX*sizeof(unsigned char))) == NULL){
      perror("malloc");
      return EXIT_FAILURE;
    }

    //Set 0 to tab
    memset(memory,0,BF_MAX);

    if(instructions){
      fread(instructions,sizeof(char), length_file, file);
    }

    fclose(file);

    instructions[length_file] = '\0';

    // Pointer on memory tab
    ptr = memory;

    for(i = 0; i < (length_file) ; ++i){
      is_char = 0;
      caractere = instructions[i];

      if(caractere == '>'){
        is_char++;
        ++ptr;

      }
      else if(caractere == '<'){
        is_char++;
          ptr--;

      }
      else if(caractere == '+'){
        is_char++;
          ++(*ptr);

      }
      else if(caractere == '-'){
        is_char++;
          --(*ptr);

      }
      else if(caractere == '.'){
        is_char++;
          putchar(*ptr);
      }
      else if(caractere == ','){
        is_char++;
        (*ptr) = getchar();
      }
      else if(caractere == '['){
        is_char++;
        if(!*ptr)
          while(instructions[i++] != ']');

      }
      else if(caractere == ']'){
        is_char++;
        if(*ptr)

          while(instructions[i--] != '[');

      }
      else if(is_char == 0){
        i++;
      }

    }

  }

  else{
    printf("Impossible d'ouvrir le fichier test.txt");
  }
free(memory);
free(instructions);
return 0;
}
