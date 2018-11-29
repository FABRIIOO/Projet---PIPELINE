#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include<time.h>
#include <conio.h>


int flag;
func_record (float y, float u_ins, float mult_in, float eco) {

  struct dados {
  	 float y2,un_intr,mult_instr,econ;
   };	
  dados a;
  
  FILE *arquivos;
  arquivos = fopen("resultado.txt","a+");
   
   if (arquivos == NULL) {
  	 printf("Problemas com o arquivo.");
   } else {
   	
  	 	a.y2 = y;
  	 	a.un_intr = u_ins;
  	 	a.mult_instr = mult_in;
  	 	a.econ = eco;
  	 	fwrite(&a,sizeof(dados),1,arquivos);
   
   }
    fclose(arquivos);
 }

//function read
func_read (float y, float u_ins, float mult_in, float eco) {
  
  struct dados {
  	float y2,un_intr,mult_instr,econ;
  };	
  
  dados a;
  FILE *arquivos;
  arquivos = fopen("resultado.txt","r");
   
   if (arquivos == NULL) {
  	 printf("Problemas com o arquivo.");
   } else 
     {
     	int c=1;
   		while (!feof(arquivos)) 
		{
   		  fread(&a,sizeof(dados),1,arquivos);
   		  printf("\n*****\n");
		  printf("\n Valor de resto: %0.f",a.y2);
		  printf("\n Valor linear %0.f",a.un_intr);
		  printf("\n Valor com PipeLine: %0.f",a.mult_instr);
		  printf("\n Valor de economia com PipLine: %0.f",a.econ);	
		  c++;
		} 
	 }
  fclose(arquivos);
}

//function scalar
func_scalar () {
	
	int m_time,soma,vetor[5];
	int n_nucleos,instrucao,linear,econo;
	 
	if (flag == 3) {
	
		 m_time = 0,soma = 0,instrucao = 0,linear = 0,econo = 0;
			 for(int i=0;i<5;i++){
			 	vetor[i] = 0;	
			 } 
			
			 printf("Digite a quantidade de instrução: ");
			 scanf("%d",&instrucao);	
				
			int qt_estagio = 3;
			int i = 0;
			do
		  	{
			 do 
			   {
			   	
				  printf("Insira o estagio %d: ",i+1);
				  scanf("%d",&vetor[i]); 
				
				}while (vetor[i] <= 0);
			  i++;
			}while (i < 3);
			 soma = 0;
			 for (int i = 1;i<3;i++) {
				if (soma <= vetor[i]) {
					soma = vetor[i]; 
			   	  }
			}
		
	   		linear = ((vetor[0]+vetor[1]+vetor[2]+vetor[3])*instrucao); // linear
			int vlr = vetor[0]+vetor[1]+vetor[2]+vetor[3]+(soma*(instrucao-1));   
			econo = linear-vlr; //economia entre de tempo com o pipe-line 		
			func_record(soma,linear,vlr,econo);
			func_read(soma,linear,vlr,econo);
			
			getch();

   } else if (flag == 4) { //4 intership
		
			 m_time = 0,soma = 0,instrucao = 0,linear = 0,econo = 0;
			 for(int i=0;i<5;i++){
			 	vetor[i] = 0;	
			 } 
			
			 printf("Digite a quantidade de instrução: ");
			 scanf("%d",&instrucao);	
				
			int qt_estagio = 4;
			int i = 0;
			do
		  	{
			 do 
			   {
			   	
				  printf("Insira o estagio %d: ",i+1);
				  scanf("%d",&vetor[i]); 
				
				}while (vetor[i] <= 0);
			  i++;
			}while (i < 4);
			 soma = 0;
			 for (int i = 1;i<4;i++) {
				if (soma <= vetor[i]) {
					soma = vetor[i]; 
			   	  }
			}
		
	   		linear = ((vetor[0]+vetor[1]+vetor[2]+vetor[3]+vetor[4])*instrucao); // linear
			int vlr = vetor[0]+vetor[1]+vetor[2]+vetor[3]+vetor[4]+(soma*(instrucao-1));   
			econo = linear-vlr; //economia entre de tempo com o pipe-line 		
			func_record(soma,linear,vlr,econo);
			func_read(soma,linear,vlr,econo);
			
			getch();
	
   } else if (flag == 5) {
   				
			 m_time = 0,soma = 0,instrucao = 0,linear = 0,econo = 0;
			 for(int i=0;i<5;i++){
			 	vetor[i] = 0;	
			 } 
			
			 printf("Digite a quantidade de instrução: ");
			 scanf("%d",&instrucao);	
				
			int qt_estagio = 5;
			int i = 0;
			do
		  	{
			 do 
			   {
			   	
				  printf("Insira o estagio %d: ",i+1);
				  scanf("%d",&vetor[i]); 
				
				}while (vetor[i] <= 0);
			  i++;
			}while (i < 5);
			 soma = 0;
			 for (int i = 1;i<5;i++) {
				if (soma <= vetor[i]) {
					soma = vetor[i]; 
			   	  }
			}
		
	   		linear = ((vetor[0]+vetor[1]+vetor[2]+vetor[3]+vetor[4]+vetor[5])*instrucao); // linear 
			econo = linear-soma; //economia entre de tempo com o pipe-line 		
			func_record(m_time,linear,soma,econo);
			func_read(m_time,linear,soma,econo);
			
			getch();
	
    }
 }

//function superscalar
func_sup_scalar () {
	
	int m_time,soma,vetor[5];
	int n_nucleos,instrucao,linear,econo;
			
	if (flag == 3) {
		
		 m_time = 0,soma = 0,n_nucleos = 0,instrucao = 0,linear = 0,econo = 0;
		 for(int i=0;i<5;i++){
		 	vetor[i] = 0;	
		 } 
			 
		
		 printf("Digite a quantidade de nucleo: "); 
		 scanf("%d",&n_nucleos);
		 printf("Digite a quantidade de instrução: ");
		 scanf("%d",&instrucao);	
		
		int qt_estagio = 3;
		int i = 0;
		do
	  	{
		 do 
		   {
		   	
			  printf("Insira o estagio %d: ",i+1);
			  scanf("%d",&vetor[i]); 
			
			}while (vetor[i] <= 0);
		  i++;
		}while (i < 3);
		 
		 m_time  = vetor[1];
		 
		 for (i = 0; i < qt_estagio; i++)
		  {
			if(vetor[i] > m_time){
				m_time = vetor[i];
			}
		  }
		
		for (i = 0; i < qt_estagio; i++){
			soma += vetor[i]; //soma vlr dos estagios
		}
		
		for (i=n_nucleos; i < instrucao; i += n_nucleos){
			soma += m_time;
		}
	
   		float linear = ((vetor[1]+vetor[2]+vetor[3])*instrucao); // linear 
		float econo = linear-soma; //economia entre de tempo com o pipe-line 		
		func_record(m_time,linear,soma,econo);
		func_read(m_time,linear,soma,econo);
		
		getch();

	
   } else if (flag == 4) { //4 intership

		 m_time = 0,soma = 0,n_nucleos = 0,instrucao = 0,linear = 0,econo = 0;
		 for(int i=0;i<5;i++){
		 	vetor[i] = 0;	
		 } 
	
		 printf("Digite a quantidade de nucleo: "); 
		 scanf("%d",&n_nucleos);
		 printf("Digite a quantidade de instrução: ");
		 scanf("%d",&instrucao);	
			
		int qt_estagio = 4;
		int i = 0;
		do
	  	{
		 do 
		   {
		   	
			  printf("Insira o estagio %d: ",i+1);
			  scanf("%d",&vetor[i]); 
			
			}while (vetor[i] <= 0);
		  i++;
		}while (i < 4);
		 
		 m_time  = vetor[1];
		 
		 for (i = 0; i < qt_estagio; i++)
		  {
			if(vetor[i] > m_time){
				m_time = vetor[i];
			}
		  }
		
		for (i = 0; i < qt_estagio; i++){
			soma += vetor[i]; //soma vlr dos estagios
		}
		
		for (i=n_nucleos; i < instrucao; i += n_nucleos){
			soma += m_time;
		}
	
   		float linear = ((vetor[1]+vetor[2]+vetor[3]+vetor[4])*instrucao); // linear 
		float econo = linear-soma; //economia entre de tempo com o pipe-line 		
		func_record(m_time,linear,soma,econo);
		func_read(m_time,linear,soma,econo);
		
		getch();
  
   } else if (flag == 5) {
		
		 m_time = 0,soma = 0,n_nucleos = 0,instrucao = 0,linear = 0,econo = 0;
		 for(int i=0;i<5;i++){
		 	vetor[i] = 0;	
		 } 
		
		 printf("Digite a quantidade de nucleo: "); 
		 scanf("%d",&n_nucleos);
		 printf("Digite a quantidade de instrução: ");
		 scanf("%d",&instrucao);	
			
		int qt_estagio = 5;
		int i = 0;
		do
	  	{
		 do 
		   {
		   	
			  printf("Insira o estagio %d: ",i+1);
			  scanf("%d",&vetor[i]); 
			
			}while (vetor[i] <= 0);
		  i++;
		}while (i < 5);
		 
		 m_time  = vetor[1];
		 
		 for (i = 0; i < qt_estagio; i++)
		  {
			if(vetor[i] > m_time){
				m_time = vetor[i];
			}
		  }
		
		for (i = 0; i < qt_estagio; i++){
			soma += vetor[i]; //soma vlr dos estagios
		}
		
		for (i=n_nucleos; i < instrucao; i += n_nucleos){
			soma += m_time;
		}
	
   		linear = ((vetor[0]+vetor[1]+vetor[2]+vetor[3]+vetor[4])*instrucao); // linear 
		econo = linear-soma; //economia entre de tempo com o pipe-line 		
		func_record(m_time,linear,soma,econo);
		func_read(m_time,linear,soma,econo);
		
		getch();
	
    }
}

main () {
  setlocale(LC_ALL, "Portuguese");
	int i,internship;
	int tip_pipe,loop;
	
	//type pipeline 
	do {
		
 		 internship = 0;
		 printf("\nMenu de opções: \n");
	 	 printf("1 - Escalar\n");
		 printf("2 - Superscalar\n");
		 printf("3 - Para sair digite sair\n");
		 printf("Escolha sua opção: ");
		  fflush(stdin); 
		  scanf("%d",&tip_pipe);
		
		 if (tip_pipe == 1 || tip_pipe == 2) {
	   	  do { 
		   printf("\nDigite o quantidade de estágios, sendo 3, 4 ou 5\n");
		   fflush(stdin);
		    scanf("%d",&internship);
		     loop=1;
		     if (internship > 5 || internship <= 2) {
			 	internship = -1;
			  }
			} while (internship <= 0);
	     }
		 else if(tip_pipe == 3){
	    	return 0;
		 }else {
			loop = -1;
		 }
		 
	  }while(loop <= 0);

	switch (internship) {
		case 3:
			flag = 3;
		break;
		case 4:
		    flag = 4;
		break;
		case 5:
		    flag = 5;
		break;
		default:
		    printf("Digite uma quantidade de estágios valida.\n");
			return 0;
		break;				
	}
	
	switch (tip_pipe){		
		case 1:
		  func_scalar();
		break;	
		case 2:
		  func_sup_scalar();
		break;
		case 3:
			return 0;
		break; 	
		default:
		    printf("\nDigite um caractere correspondente.");
		break;		
	}	
}
