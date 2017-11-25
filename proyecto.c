//integrantes jose campos- valentina miranda
//debe tener un archivo de nombre "bacteria.bin"
#include <stdio.h>
#include "archivo.h"
#include "mat.h"
#include <stdlib.h>
#include <stdint.h>
//coordenadas para crear matriz y buscar nuemero de bacterias,
typedef struct {
 	int x;
 	int y;
}Coordenadas;
//numero magico 

int main (){
	int cant; 

	Nodo *ma= (Nodo*)malloc (sizeof(Nodo));
	FILE *f, *es;
	Pila *punt =(Pila*)malloc(sizeof(Pila));
	punt->tam=0;
	punt->ini=NULL;
	Des rec;//puntero icial del archivo
	f = fopen( "bacteria.bin","rb");
	int i=0;
	//trae los valores hasta la cantidad que se le dice en el sizeof ()
	fread(&rec, sizeof(Des), 1, f);
	//trae los datos del archivo para la matriz
	int ho = abrir(&rec);
	if (ho == 1){
		return 0;
	}
	Coordenadas cor; 
	Mat *b =(Mat*)malloc(sizeof(Mat));

	
	//crea una matriz de 0 segun lo que salga en el archivo
	crear(b, rec.x, rec.y);
	int z;
	for (i=0;i<rec.cantidad;i++){
		fread(&cor, sizeof(Coordenadas), 1 , f);
		// cambia el valor de los parametros ingresados
		b->x[cor.x][cor.y]=1;
	}
	fclose(f);
	//muestra matriz dps de recibir realizar el cambio
	mostrar(b,rec.x,rec.y);
	printf("indique la cantidad de veces que quiere hacer el cabio de vida");
	scanf("%i",&cant);
	int g =0;
	for (i=0; i < cant; i++){
		if(g==0){
			g = vida( b, rec.x-1, rec.y-1, punt,ma);	
		
		}
	}	
			printf("no tiene mas cambios\n");
			i=cant;
	i=0;
	int j=0;
	FILE *fo = fopen("salida.bin","wb");
	int nume = 0X7201D2ED;
	fwrite(&nume,sizeof(int), 1,fo);
	fwrite(&rec.x,sizeof(int), 1,fo);
	fwrite(&rec.y,sizeof(int), 1,fo );
	int m=0;
	for (i=0;i<rec.x;i++ ){
		for (j=0; j<rec.y;j++){
			if (b->x[i][j]==1){
				m++;
			}
		}
	}
	i=0;
	j=0;
	fwrite(&m,sizeof(int), 1,fo );
	for (i=0;i<rec.x;i++ ){
		for (j=0; j<rec.y;j++){
			if (b->x[i][j]==1){
				printf("%d %d",i,j);
			    fwrite(&i,sizeof(int), 1,fo);
			    fwrite(&j,sizeof(int), 1,fo );
			}
		}
	}
	fclose(fo);
			printf("Guardado con exito, cierre el archivo\n");
			return 0;
}

