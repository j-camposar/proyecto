#include <stdio.h>
#include <stdint.h>

typedef struct {
	// Número mágico extraído desde el archivo.
	uint8_t magic[4];
	// Ancho y alto de la matriz.
	uint32_t x;
	uint32_t y;
	// Cantidad de bacterias (población)
	uint32_t cantidad;
}Des;

int abrir (Des *rec){
	//File fopen abre archivo ("direccion de archibo", "lo que quiero que haga ")
	int i=0, j=0;
	
	for(i = 0; i < 4; i++){
		// La máscara %X imprime como número hexadecimal
		// 02 define que se rellenará con ceros hasta que imprima 2 digitos
		
	}
	for(i = 0; i < 4; i++){
		// La máscara %X imprime como número hexadecimal
		// 02 define que se rellenará con ceros hasta que imprima 2 digitos
		
	}
		if (0XED==rec->magic[0]){
			if (0XD2==rec->magic[1]){
				if (0X01==rec->magic[2]){
					if (0X72 ==rec->magic[3]){
						printf ("\nel numero magico es correcto\n");
					return 0;
					}else{
					printf("\n el numero magico es erroneo");
			return 1;
		}
				}else{
			printf("\n el numero magico es erroneo");
			return 1;
		}
			}else{
			printf("\n el numero magico es erroneo");
			return 1;
		}
		}else{
			printf("\n el numero magico es erroneo");
			return 1;
		}
		
}

