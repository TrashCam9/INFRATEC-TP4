//MARIA CAMILA GOMEZ HERNANDEZ - 202011050 - mc.gomezh1@uniandes.edu.co
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void empaquetador(int* vector_int, char* vector_char);
int main(){
    /*
    Con este programa podrá ingresar una palabra y obtener su traducción a hexa.
    */
    char cadena[100];
    int i; //i tendrá la longitud de la cadena ingresada
    int *ptr_int; //apuntador al vector de ints
    char *ptr_char; //apuntador al vector de chars
    scanf("%s", &cadena); //en cadena guardaré lo que me pasen en el output
    for(i=0; cadena[i]!='\0';i++);
    //Me aseguro de que i sea divisible entre 4, si no lo es entonces le sumo 1 a la división para tener otro puesto de más en el array de ints
    if (i%4!=0){
        i = (i/4)+1;
    }else{
        i = i/4;
    }
    ptr_int = (int*) calloc(i, sizeof(int));//creo el apuntador al vector de ints
    ptr_char = &cadena[0]; // creo el apuntador al array de char
    empaquetador(ptr_int, ptr_char);
    //imprimo la cadena convertida en hexa
    for(int j=0; j<(i); j++){
        if(i!=1 && j!=0){
            printf("%c", ',');
        }
        printf("0x%x", ptr_int[j]);
    }
    //libero la memoria 
    free(ptr_int);
    return 0;
}

void empaquetador(int* vector_int, char* vector_char){
    /*
    Esta función recibirá 2 apuntadores por parametro y se encargará de empaquetar los char que hay en el vector_char dentro de vector_int
    */
    bool terminado = false;
    while(!terminado){
        int box = 0;
        char letra1 = '\0';
        char letra2 = '\0';
        char letra3 = '\0';
        char letra4 = '\0';
        while (!terminado && box !=4){
            char letra = *(vector_char);
            if (letra == '\0'){
                terminado = true;
            }else{
                if (box == 0){
                    letra1 = letra; 
                }else if(box == 1){
                    letra2 = letra; 
                }else if(box == 2){
                    letra3 = letra; 
                }else if(box == 3){
                    letra4 = letra; 
                }
                vector_char++;
                box++;
                }
            }
        *vector_int = (letra1<<24)|(letra2<<16)|(letra3<<8)|(letra4);
        vector_int++;
        }
    }