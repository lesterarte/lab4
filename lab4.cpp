#include<iostream>
using std::endl; 
using std::cout; 
using std::cin; 
void crearcubo();

int main(int argc, char*argv[]){
	int sub=15;
	crearcubo();
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
