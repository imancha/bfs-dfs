#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

void spasi(int n);

int main(int argc, char** argv) 
{
	srand(time(NULL));
	int d, b, r, s, a;
	
	cout << "--------------------------------------------------------------\n"
		 << "Format penulisan input : >tree.exe -d val -b val -r val -s val\n"
		 << "                Contoh : >tree.exe -d 3 -b 5 -r 100 -s 23\n"
		 << "--------------------------------------------------------------\n"
		 << "\nInput : \n\n";
		 
	scanf(">tree.exe -d %i -b %i -r %i -s %i",&d,&b,&r,&s);				// Input Program
	d = 3;		
	int q = d*b;	
	int node[q][q];
			
	for (int i=0; i<d; i++){						// Pembentukan Node/Simpul
		for (int j=1; j<=pow(b,i); j++){						
			node[i][j] = rand()%r + 1;
		}
	}
	
	cout << "\nOutput : \n\n";
	
	for (int i=0; i<d; i++){
		for (int j=1; j<=pow(b,i); j++){			
			printf("Node[%i][%i] = %i\n",i,j,node[i][j]);
		}
	}							
			
	cout << endl
		 << endl
		 << node[0][1]
		 << endl;
		 	 						 	 					
	int l = 1;
	int m = 1;
	int n = 1;
	int i = 1;
	int j = 0;
		
	breadth :								// Output Tree
		if (j != b){			
			depth :				
				if (i != d-1){
					spasi(i-1);
					printf("|_%i\n",node[m][n]);	
					if (n != b){
						printf("|");
					} else {
						printf(" ");
					}
					++m;					
					++i;									
					goto depth;
				} else {
					int k = 0;
					leaf :
						if (k != b){		
							spasi(i-1);					
							printf("|_%i\n",node[m][l]);
							if (n != b){
								printf("|");
							} else {
								printf(" ");
							}
							++l;
							++k;
							goto leaf;
						} else {
							--i;
							--m;
							++n;
							++j;
							printf("\n");
							goto breadth;					
						}
				}		
		}
				
	printf("\nPencarian Angka %i : \n\n",s);		// Searching
	for (int i=0; i<d; i++){
		for (int j=1; j<=pow(b,i); j++){			
			if (s == node[i][j]){
				printf("Breadth = %i, Depth = %i\n",i,j);
			}
		}
	}		

	printf("\n");
	system("pause");
	return 0;
}

void spasi(int n){
	for(int i=0; i<3*n; i++){
		cout << " ";
	}
}
