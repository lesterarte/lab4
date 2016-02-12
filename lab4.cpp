#include<cstdlib>
#include<iostream>
using std::endl; 
using std::cout; 
using std::cin; 
void crearcubo();

int main(int argc, char*argv[]){
	int sub=15;
	crearcubo();
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




