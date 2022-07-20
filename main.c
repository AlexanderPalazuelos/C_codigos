#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int j=0, anterior = 4, x_lado, x_altura, h_lado, h_altura;
char indicaciones[100][10], num_indicaciones=0;


int BuscaCaracter (char string[][100], char caracter, int n, int i)
{
        j=0;
        while ( string[i][j] != '\0' )
        {
             if ( string[i][j] == caracter )
             {
                 //printf("Encontre la X :D, esta en: %d %d", j, i);
                 return j;
             }
             j++;
        }
}
int Busqueda (int altura, int lado, char mapa[][100])
{
    while(x_lado != h_lado || x_altura != h_altura){
//printf("Estas en la fila: %d y en la columna: %d.\nMientras que tu objetivo esta en la fila: %d y en la columna: %d.\n\n", x_altura+1, x_lado+1, h_altura+1, h_lado+1);
 if (altura == 0 && lado == 0){ //------------- si esta abajo a la izquierda la salida -------------
  if((mapa[x_altura+1][x_lado] == '.' || mapa[x_altura+1][x_lado] == 'H') && anterior != 0){ // if hay camino abajo
      anterior = 1;
      strcpy(indicaciones[num_indicaciones],"ABAJO");
      num_indicaciones++;
      x_altura++;
  }else if((mapa[x_altura][x_lado-1] == '.' || mapa[x_altura][x_lado-1] == 'H') && anterior != 2){ // if hay camino a la izquierda
      anterior = 3;
      strcpy(indicaciones[num_indicaciones],"IZQUIERDA");
      num_indicaciones++;
      x_lado--;
  } else if((mapa[x_altura-1][x_lado] == '.' || mapa[x_altura-1][x_lado] == 'H') && anterior != 1){// if hay camino a arriba
      anterior = 0;
      strcpy(indicaciones[num_indicaciones],"ARRIBA");
      num_indicaciones++;
      x_altura--;
  }else if((mapa[x_altura][x_lado+1] == '.' || mapa[x_altura][x_lado+1] == 'H') && anterior != 3){ // if hay camino a la derecha
      anterior = 2;
      strcpy(indicaciones[num_indicaciones],"DERECHA");
      num_indicaciones++;
      x_lado++;
  }
 }
 if (altura == 0 && lado == 1){ //------------- si esta abajo a la derecha la salida -------------
  if((mapa[x_altura+1][x_lado] == '.' || mapa[x_altura+1][x_lado] == 'H') && anterior != 0){ // if hay camino abajo
      anterior = 1;
      strcpy(indicaciones[num_indicaciones],"ABAJO");
      num_indicaciones++;
      x_altura++;
  }else if((mapa[x_altura][x_lado+1] == '.' || mapa[x_altura][x_lado+1] == 'H') && anterior != 3){ // if hay camino a la derecha
      anterior = 2;
      strcpy(indicaciones[num_indicaciones],"DERECHA");
      num_indicaciones++;
      x_lado++;
  }else if((mapa[x_altura-1][x_lado] == '.' || mapa[x_altura-1][x_lado] == 'H') && anterior != 1){// if hay camino a arriba
      anterior = 0;
      strcpy(indicaciones[num_indicaciones],"ARRIBA");
      num_indicaciones++;
      x_altura--;
  }else if((mapa[x_altura][x_lado-1] == '.' || mapa[x_altura][x_lado-1] == 'H') && anterior != 2){ // if hay camino a la izquierda
      anterior = 3;
      strcpy(indicaciones[num_indicaciones],"IZQUIERDA");
      num_indicaciones++;
      x_lado--;
  }
 }
 if(altura == 1 && lado == 0){ //------------- si esta arriba a la izquierda la salida -------------
  if((mapa[x_altura-1][x_lado] == '.' || mapa[x_altura-1][x_lado] == 'H') && anterior != 1){// if hay camino a arriba
      anterior = 0;
      strcpy(indicaciones[num_indicaciones],"ARRIBA");
      num_indicaciones++;
      x_altura--;
  }else if((mapa[x_altura][x_lado-1] == '.' || mapa[x_altura][x_lado-1] == 'H') && anterior != 2){ // if hay camino a la izquierda
      anterior = 3;
      strcpy(indicaciones[num_indicaciones],"IZQUIERDA");
      num_indicaciones++;
      x_lado--;
  }else if((mapa[x_altura+1][x_lado] == '.' || mapa[x_altura+1][x_lado] == 'H') && anterior != 0){ // if hay camino abajo
      anterior = 1;
      strcpy(indicaciones[num_indicaciones],"ABAJO");
      num_indicaciones++;
      x_altura++;
  }else if((mapa[x_altura][x_lado+1] == '.' || mapa[x_altura][x_lado+1] == 'H') && anterior != 3){ // if hay camino a la derecha
      anterior = 2;
      strcpy(indicaciones[num_indicaciones],"DERECHA");
      num_indicaciones++;
      x_lado++;
  }
 }
 if (altura == 1 && lado == 1){ //------------- si esta arriba a la derecha la salida -------------
  if((mapa[x_altura-1][x_lado] == '.' || mapa[x_altura-1][x_lado] == 'H') && anterior != 1){// if hay camino a arriba
      anterior = 0;
      strcpy(indicaciones[num_indicaciones],"ARRIBA");
      num_indicaciones++;
      x_altura--;
  }else if((mapa[x_altura][x_lado+1] == '.' || mapa[x_altura][x_lado+1] == 'H') && anterior != 3){ // if hay camino a la derecha
      anterior = 2;
      strcpy(indicaciones[num_indicaciones],"DERECHA");
      num_indicaciones++;
      x_lado++;
  }else if((mapa[x_altura+1][x_lado] == '.' || mapa[x_altura+1][x_lado] == 'H') && anterior != 0){ // if hay camino abajo
      anterior = 1;
      strcpy(indicaciones[num_indicaciones],"ABAJO");
      num_indicaciones++;
      x_altura++;
  }else if((mapa[x_altura][x_lado-1] == '.' || mapa[x_altura][x_lado-1] == 'H') && anterior != 2){ // if hay camino a la izquierda
      anterior = 3;
      strcpy(indicaciones[num_indicaciones],"IZQUIERDA");
      num_indicaciones++;
      x_lado--;
  }
 }

    Busqueda(altura, lado, mapa);
    }
}


int main()
{
    //Inicializar valores
   int n, posicion[4] = {0, 0, 0, 0}, cond=0, altura = 0, lado = 0;
   char mapa[100][100], letra = 'X';
   //Leer las dimensiones del mapa
   scanf("%d", &n);
   //Generar Mapa
   for(int i=0; i<n; i++)
   {
       scanf("%s", mapa[i]);

       if ( BuscaCaracter(mapa,letra, n, i) != -1 && cond == 0) // buscar X
       {
           x_lado = BuscaCaracter(mapa,letra, n, i);
           x_altura = i;
           if(x_lado != 0){cond = 1;}
       }
   }
    /*



    // printf("La letra X esta en la fila %d, columna %d", posicion[1], posicion[0]);




    */
    cond = 0;
    letra = 'H'; //cambia valor
    for(int i=0; i<n; i++){
        if ( BuscaCaracter(mapa,letra, n, i) != -1 && cond == 0) // buscar H
       {
           h_lado = BuscaCaracter(mapa,letra, n, i);
           h_altura = i;
           if(h_lado != 0){cond = 1;}
       }
    }
    if(h_altura < x_altura){
        altura = 1;
    }else{
        altura = 0;
    }
    if(h_lado < x_lado){
     lado = 0;
    }else{
    lado = 1;
    }
    Busqueda(altura, lado, mapa);

    for(int i = 0; i<num_indicaciones; i++){
        printf("%s\n", indicaciones[i]);
    }

    return 0;
}
