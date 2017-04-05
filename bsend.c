#include <stdio.h>
#include <mpi.h>
#define TAM 100
#define BUFTAM 1000
/*Con 2  procesos*/

main(int argc, char* argv[]){
	int p, my_rank;
	int tag=42;
	MPI_Status status;
	int x[TAM];
	int buff[BUFTAM]; 
	int tambuff=BUFTAM;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&p);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	MPI_Buffer_attach(buff, tambuff);

	if(my_rank ==0){
		printf(“Proceso 0: mando al proceso 1\n”);
		MPI_Bsend(&x,TAM,MPI_INT,1,tag,MPI_COMM_WORLD);
		printf(“Proceso 0: vuelta de la operación de envio\n”);
	}
	else{
		printf(“Proceso 1: recibiendo del proceso 0\n”);
		MPI_Recv(&c,TAM,MPI_INT,0,tag,MPI_COMM_WORLD,&status);
		printf(“Proceso 1: recibidos %d elementos\n”,TAM);
	}
	
	MPI_Buffer_detach(&buff,&tambuff);
	MPI_Finalize();
}	