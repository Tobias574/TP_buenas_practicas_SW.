#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void agregarunlibro(int c);
void verlibros(int c);
void buscarlibros(int c);
void archivarlibros(int c);




struct libro{
	char titulo[100];
	char Autor[50];
	int anyo; //año
}libros[50];

int main(int argc, char *argv[]) {
	int f=0,e=0,c=0;
	
	printf("Bienvenido a su colección de libros ¿Que desea hacer?\n");
	do{
	printf("1)Agregar un libro a la colección\n2)Ver colección total\n3)Buscar un libro por parametro\n4)Archivar la colección\n5)Salir");
	scanf("%d",&e);
	switch(e){
	default:
		printf("Seleccione una opción válida");
		break;
	case 1:
		agregarunlibro(c);
		c=c+1;
		break;
	case 2:
		verlibros(c);
		break;
	case 3: 
		buscarlibros(c);
		printf("Si la función no ha devuelto los datos y posición del libro, entonces este no existe aquí\n");
		break;
	case 4:
		archivarlibros(c);
		break;
	case 5:
		f=100;  //función de salida 
		break;
	}
	}while(f != 100);
	return 0;
}

void agregarunlibro(int c){
	printf("Ingrese el título del libro(use - en vez de espacios)\n");
	scanf("%s",libros[c].titulo);
	printf("Ingrese el autor del libro(use - en vez de espacios)\n");
	scanf("%s",libros[c].Autor);
	printf("Ingrese el ano del libro\n");
	scanf("%d",&libros[c].ano);
	printf("Libro cargado exitosamente\n");
}

void verlibros(int c){
	int i;
	
	for(i=0;i<c;i++){
		printf("libro: %d\n",i);
		printf("%s",libros[i].titulo);
		printf("\n");
		printf("%s",libros[i].Autor);
		printf("\n");
		printf("%d",libros[i].ano);
		printf("\n");
		
	}
}
void buscarlibros(int c){
	int e=0,i,bus2=0;
	char bus[100];
	
	printf("Desea buscar por\n 1)Titulo\n2)Autor\n3)ano\n?");
	scanf("%d",&e);
	switch(e){
	default:
		printf("la proxima vez seleccione una opcion valida");
		break;
	case 1:
		printf("Ingrese el titulo que desea buscar\t");
		scanf("%s",bus);
		for(i=0;i<=c;i++){
			if(strcmp(bus,libros[i].titulo) == 0){
				printf("Libro numero %d\n",i);
				printf("%s\n",libros[i].titulo);
				printf("%s\n",libros[i].Autor);
				printf("%d\n",libros[i].ano);
			}
				
			
		}
		break;
	case 2:
		printf("Ingrese el autor que desea buscar\t");
		scanf("%s",bus);
		for(i=0;i<=c;i++){
			if(strcmp(bus,libros[i].Autor) == 0){
				printf("Libro numero %d\n",i);
				printf("titulo: %s\n",libros[i].titulo);
				printf("Autor: %s\n",libros[i].Autor);
				printf("ano: %d\n",libros[i].ano);
			}
			
		}
		break;
	case 3:
		printf("Ingrese el ano que desea buscar\t");
		scanf("%d",&bus2);
		for(i=0;i<=c;i++){
			if(bus2==libros[i].ano){
				printf("Libro numero %d\n",i);
				printf("titulo: %s\n",libros[i].titulo);
				printf("autor: %s\n",libros[i].Autor);
				printf("ano: %d\n",libros[i].ano);
			}
			
		}
		break;
	}
}

void archivarlibros(int c){
	int i;
	
	FILE *colec= fopen("colec.txt","w");
	
	for(i=0;i<c;i++){
		fprintf(colec,"libro n°%d",i);
		fprintf(colec,"\n");
		fputs(libros[i].titulo,colec);
		fprintf(colec,"\n");
		fputs(libros[i].Autor,colec);
		fprintf(colec,"\n");
		fprintf(colec,"%d",libros[i].ano);
		fprintf(colec,"\n");
	}
	printf("Se guardó su archivo correctamente");
	fclose(colec);
	
}
