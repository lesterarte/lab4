#include<cstdlib>
#include<iostream>

using std::endl; 
using std::cout; 
using std::cin; 
void llenar(int***,int, int);
void iniciarcubo(int***,int);
void crearcubo(int***);
void ataque_expansive(int***);
void ataquenormal(int*** , int , int , int );
void ataquewive(int***, int ,int, int);
void coordenadas(int*** ,int );
int  subrestantes(int*** ,int);
void eliminar(int***,int);

int main(int argc, char*argv[]){

	int sub_jug1=15;
	int sub_jug2=15;
	int*** cub_j1;
	int*** cub_j2;
	crearcubo(cub_j1);
	crearcubo(cub_j2);
	int size=15;
	srand(time(NULL)); 
	bool turn=true;
	while(sub_jug1!=0 || sub_jug2!=0){
		
	  	if(turn==true){
			int atq=0,cantWave=3,cant_espa=3;
			coordenadas(cub_j1,size);
			cout<<"*********Le quedan por destruir "<<sub_jug1<<"De su contrincante *******"<<endl;
			cout<<"Elija su ataque \n"
			    <<"1--Normal \n"
			    <<"2--Wave \n"
			    <<"3--Expansive \n"<<endl;
			cin>>atq;

			if(atq==1){
				int x,y,z;
				cout<<"Ingrese las coordenadas \n"<<endl
				    <<"X ";
		 		cin>>x;
				cout<<"Y ";
				cin>>y;
				cout<<"Z ";
				cin>>z; 
				if((x >= 0 && x <=11) && (y >= 0 && y <= 11) && (z >= 0 && z <= 11)){
					 ataquenormal(cub_j2,   x,   y,   z);
					 turn==false;
				}else{
					cout<<"Pierde turno por movimientos invalidos"<<endl;
					turn==false;	
				}
			}else if(atq==2){
				int opWave=0;
				int z;
				
				cout<<"Ingrese el tipo de Wave \n"<<endl;
				cout<<"1-XY \n2-XZ\n3-YZ ";
 				cin>>opWave;
				cout<<"Ingrese el numero de plano deseado"<<endl;
				cin>>z;
				if(cantWave<3){
					ataquewive(cub_j2,z,size,opWave);
					cantWave--;
					turn==false;	
				}else{
					cout<<"Pierde turno porque no tiene mas waves"<<endl;
					turn==false;
				}

 			}else if(atq==3){
				if(cant_espa<3){
					ataque_expansive(cub_j2);
					cant_espa--;
					turn==false;
				}else{
					cout<<"Pierde turno porque no tiene mas espansives"<<endl;
					turn==false;
				}
			
			}


	




		}else if(turn==false){
			int atq2=0,cantWave2=3,cant_espa2=3;
			coordenadas(cub_j2,size);
			cout<<"*********Le quedan por destruir "<<sub_jug1<<"De su contrincante *******"<<endl;
			cout<<"Elija su ataque \n"
			    <<"1--Normal \n"
			    <<"2--Wave \n"
			    <<"3--Expansive \n"<<endl;
			cin>>atq2;

			if(atq2==1){
				int x,y,z;
				cout<<"Ingrese las coordenadas \n"<<endl
				    <<"X ";
		 		cin>>x;
				cout<<"Y ";
				cin>>y;
				cout<<"Z ";
				cin>>z; 
				if((x >= 0 && x <=11) && (y >= 0 && y <= 11) && (z >= 0 && z <= 11)){
					 ataquenormal(cub_j1,   x,  y,  z);
					 turn==true;
				}else{
					 cout<<"Pierde turno por movimientos invalidos"<<endl;
					 turn==true;	
				}
			}else if(atq2==2){
				int opWave=0;
				int z;
				
				cout<<"Ingrese el tipo de Wave \n"<<endl;
				cout<<"1-XY \n2-XZ\n3-YZ ";
 				cin>>opWave;
				cout<<"Ingrese el numero de plano deseado"<<endl;
				cin>>z;
				if(cantWave2<3){
					ataquewive(cub_j1,z,size,opWave);
					cantWave2--;
					turn==true;	
				}else{
					cout<<"Pierde turno porque no tiene mas waves"<<endl;
					turn==true;
				}

 			}else if(atq2==3){
				if(cant_espa2<3){
					ataque_expansive(cub_j1);
					cant_espa2--;
					turn==true;
				}else{
					cout<<"Pierde turno porque no tiene mas espansives"<<endl;
					turn==true;
				}
			
			}
		}

		

	
	}	

	eliminar(cub_j1,size);
	eliminar(cub_j2,size);
	return 0;

	
			
}


void crearcubo(int*** cubo){
	int size=12;
	cubo=new int** [size];
	for(int i=0;i<=size; i++){
		cubo[i]=new int* [size];	
	}
	
	for(int i=0;i<=size;i++){
		for(int j=0;j<=size;j++){
			cubo[i][j]=new int[size];	
		}
	}

}

void iniciarcubo(int*** cubo,int size){

	for(int i=0; i<size; i++){
		for(int j=0; i<size; j++){
			for(int k=0; i<size; k++){
				cubo[i][j][k]= 0;

			}
		}	
	}
	
}



void llenar(int*** cubo,int size, int submarinos){

	 while(submarinos !=0){

		int i=rand()%size; 
		int j=rand()%size; 
		int k= rand()%size;  
		 
		if(cubo[i][j][k]== 0){

			cubo[i][j][k]= 1; 		
			submarinos--; 
		}
			     
	}		 
}


void ataquenormal(int*** cubo, int x, int y, int z){
	
	if(cubo[x][y][z]== 0){
		cout<<"HAHA no destruiste nada"<<endl; 
	}
	else{
		cout<<"felicidades destruiste un Submarino Oponente"<<endl;
		cubo[x][y][z]=0; 
		 

	}
			
}

void ataquewive(int*** cubo , int z,int size, int conste){

	int cont=0; 
	
	if(conste==1){	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(cubo[i][j][z] !=0){
				 cubo[i][j][z]=0;
				 cont++;	
			}	

			
		}
	}

	if(cont==0){
		cout<<"No destruiste nada mijo"<<endl; 
	}
	else{
		cout<<"Destruiste "<<cont<<"del oponente FELICIDADES!!!!"<<endl; 
	}

	}//fin if

	if(conste==2){	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(cubo[i][z][j] !=0){
				 cubo[i][z][j]=0;
				 cont++;	
			}	

			
		}
	}

	if(cont==0){
		cout<<"No destruiste nada mijo"<<endl; 
	}
	else{
		cout<<"Destruiste "<<cont<<"del oponente FELICIDADES!!!!"<<endl; 
	}

	}//fin if

	if(conste==3){	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(cubo[z][i][j] !=0){
				 cubo[z][i][j]=0;
				 cont++;	
			}	

			
		}
	}

	if(cont==0){
		cout<<"No destruiste nada mijo"<<endl; 
	}
	else{
		cout<<"Destruiste "<<cont<<"del oponente FELICIDADES!!!!"<<endl; 
	}

	}//fin if
	
		
}//fin void 


void coordenadas(int*** cubo,int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				
				if(cubo[i][j][k]==1){
					cout<<"("<<i<<","<<j<<","<<k<<")"<<endl; 
				}	
			}	
		}	
	} 
	
}

int  subrestantes(int*** cubo,int size){
	int cont=0; 
	for(int i=0; i<size;i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				
				if(cubo[i][j][k]==1){
					cont++; 	
				}		
			}	
		}	
	}

	return cont; 
}

void ataque_expansive(int*** cubo){
	int x,y,z;
	cout<<"Ingrese las coordenadas \n"<<endl
	    <<"X ";
	cin>>x;
	cout<<"Y ";
	cin>>y;
	cout<<"Z ";
	cin>>z; 
	if((x > 0 && x < 11) && (y > 0 && y < 11) && (z > 0 && z < 11)){	
		for(int i=x-1;i<x+2; ++i){
			for(int j=y-1;j<y+2; ++j){
				for(int k=z-1;k<z+2; ++k){
					if(cubo[i][j][k]==1){
						cout<<"submarino destruido "<<cubo[i][j][k]<<cubo<<endl;			
					}else if(cubo[i][j][k]==0){
							cout<<"Nada que destruir"<<endl;				
					 
						}	
				}		
			}
		}
	
	
	}

}

void eliminar(int*** cubo,int size){

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			delete[] cubo[i][j];		
		}	
	}

	for(int k=0; k<size; k++){
		delete[] cubo[k]; 
		
	}

	delete[] cubo; 

	
}

