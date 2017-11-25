#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
	int viv;// ontrolador de viva o muerta
}Fo;

typedef struct nodo{
	struct nodo *sgte;
	Fo *vive;
}Nodo;
typedef struct{
	Nodo *ini;
	int tam;
}Pila;
typedef struct {
	int x[2000][2000];//coordenada matriz 
}Mat;
void guardado(int x, int y, int viom, Pila *a,Nodo *ma );
int restar(Mat *b, Pila *a);
void mostrar (Mat *a, int x, int y);
void crear(Mat *a,int x, int y){

	int i=0,j=0;
	for (i=0;i< x ;i++){
		for (j=0;j <y;j++){
			a->x[i][j]=0;
		}
	}
}
void mostrar(Mat *a, int x, int y){
	int i=0, j=0;
	for (i=0; i<x ;i++){
		for (j=0;j < y;j++){
			printf("%i",a->x[i][j]);
		}
		printf("\n");
	}
}
//inix y iniy es el x y la y de la matriz inicial se ocuoa para los numeros que estan en las esquina x 
// en vida se verfifican los vecino con dos for(); y hacer las condicionalesl.
int vida(Mat *b, int inix , int iniy, Pila *pil, Nodo *ma){
	int cont=0;
	int x=0,y=0,g;
	for (x=0; x<inix; x++){
		for (y=0;y<iniy;y++){
			
			if (x==inix && y==0){
				if (b->x[0][0]==1){
					cont++;
					
				}
				if(b->x[0][iniy]==1){
					cont++;
				}
				if (b->x[1][iniy]==1){
					cont++;
				}
				if (b->x[inix][iniy]==1){
					cont++;
				}
				if (b->x[x-1][y]==1){
					cont++;
				}
				if (b->x[x][y+1]==1){
					cont++;
				}
				if (b->x[x-1][y]==1){
					cont++;
				}
				if (b->x[x-1][iniy-1]==1){
					cont++;
				}
			}
			if (x==inix && y==iniy){
					if (b->x[0][0]==1){
					cont++;
				}
				if(b->x[inix][0]==1){
					cont++;
				}
				if (b->x[inix][1]==1){
					cont++;
				}
				if (b->x[0][iniy]==1){
					cont++;
				}
				if (b->x[1][iniy]==1){
					cont++;
				}
				if (b->x[x][y-1]==1){
					cont++;
				}
				if (b->x[x-1][y]==1){
					cont++;
				}
				if (b->x[x-1][iniy-1]==1){
					cont++;
				}
			}
			if (x==0 && y==0){
				if (b->x[x][iniy]==1){
					cont++;
				}
				if(b->x[inix][y]==1){
					cont++;
				}
				if (b->x[inix][iniy]==1){
					cont++;
				}
				if (b->x[inix][y+1]==1){
					cont++;
				}
				if (b->x[x+1][y+1]==1){
					cont++;
				}
				if (b->x[x][y+1]==1){
					cont++;
				}
				if (b->x[x+1][y]==1){
					cont++;
				}
				if (b->x[x+1][iniy]==1){
					cont++;
				}
			
			}
			else {
				if (x==0){
					if(b->x[inix][y]==1){
						cont++;
					}
					if (b->x[inix][y+1]==1){
						cont ++;
					}
					if (b->x[inix][y-1]==1){
						cont ++;
					}
					if (b->x[x][y-1]==1){
						cont++;
					}
					if (b->x[x][y+1]==1){
						cont ++;
					}
					if (b->x[x+1][y]==1){
						cont ++;
					}
					if (b->x[x+1][y+1]==1){
						cont++;
					}
					if (b->x[x+1][y-1]==1){
						cont++;
					}
			}
				if (y==0){
					if(b->x[x][iniy]==1){
						cont++;
					}
					if (b->x[x+1][iniy]==1){
						cont ++;
					}
					if (b->x[x-1][iniy]==1){
						cont ++;
					}
					if (b->x[x-1][y]==1){
						cont++;
					}
					if (b->x[x+1][y]==1){
						cont ++;
					}
					if (b->x[x][y+1]==1){
						cont ++;
					}
					if (b->x[x+1][y+1]==1){
						cont++;
					}
					if (b->x[x-1][y+1]==1){
						cont++;
					}
				}
		        if (y==iniy){
					if(b->x[x][0]==1){
						cont++;
					}
					if (b->x[x+1][0]==1){
						cont ++;
					}
					if (b->x[x-1][0]==1){
						cont ++;
					}
					
					if (b->x[x-1][y]==1){
						cont++;
					}
					if (b->x[x+1][y]==1){
						cont ++;
					}
					if (b->x[x][y-1]==1){
						cont ++;
					}
					if (b->x[x+1][y-1]==1){
						cont++;
					}
					if (b->x[x-1][y-1]==1){
						cont++;
					}
				}
				if (x==inix){
					if(b->x[0][y]==1){
						cont++;
					}
					if (b->x[0][y+1]==1){
						cont ++;
					}
					if (b->x[0][y-1]==1){
						cont ++;
					}
					if (b->x[x][y-1]==1){
						cont++;
					}
					if (b->x[x][y+1]==1){
						cont ++;
					}
					if (b->x[x-1][y]==1){
						cont ++;
					}
					if (b->x[x-1][y+1]==1){
						cont++;
					}
					if (b->x[x-1][y-1]==1){
						cont++;
						}
					
					}
				
				if (x!=0 && y != 0){
				
					if (b->x[x][y+1]==1){
						cont ++;
					}
					if (b->x[x][y-1]==1){
						cont ++;
					}
					if (b->x[x-1][y-1]==1){
						cont++;
					}
					if (b->x[x-1][y+1]==1){
						cont ++;
					}
					if (b->x[x-1][y]==1){
						cont ++;
					}
					if (b->x[x+1][y+1]==1){
						cont++;
					}
					if (b->x[x+1][y-1]==1){
						cont++;
					}
					if(b->x[x+1][y]==1){
						cont++;
					}
				}	
				if (cont == 3&&b->x[x][y]==0){
					
					guardado(x,y,1,pil,ma);
				
				}if (cont > 3 && b->x[x][y]==1) {
				
					guardado(x,y,0,pil,ma);
					}
				if (cont <3 &&b->x[x][y]==1){
					guardado(x,y,0,pil,ma);
				}
			}			
			cont=0;
		}
	}
	g = restar(b,pil);
	mostrar(b,inix+1,iniy+1);
	return g;
}
int restar(Mat *b, Pila *a){
	int i=0;
	Nodo *aux;
	Fo *el;
	if (i < a->tam){	
		aux=a->ini;
		el=aux->vive;
		b->x[el->x][el->y]=el->viv;
		a->ini=aux->sgte;
		a->tam--;
		restar(b,a);
	}else{
		printf("no hay mas cambios\n");
		return 1;
	}
	
}

void guardado(int x, int y, int viom, Pila *a,Nodo *ma ){
	ma->vive->viv= viom;
	ma->vive->x=x;
	ma->vive->y=y;
	a->ini = ma;
	ma->sgte= a->ini;
	a->ini=ma;
	a->tam++;
}

