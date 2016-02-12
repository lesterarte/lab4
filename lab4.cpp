#include<cstdlib>
#include<iostream>
using std::endl; 
using std::cout; 
using std::cin; 
void crearcubo();
void ataque_expansive(int*** );

int main(int argc, char*argv[]){
	int sub_jug1=15,sub_jug2=15;
	int*** cub_j1=crearcubo();
	int*** cub_j2=crearcubo();
	int size=15;
	srand(time(NULL)); 









 	return 0;		
}


void crearcubo(){
	int size=12;
	int*** cubo=new int** [size];
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

void ataquewive(int*** cubo , int z,int size, int const){

	int cont=0; 
	
	if(const==1){	
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

	if(const==2){	
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

	if(const==3){	
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
	cint cont=0; 
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




