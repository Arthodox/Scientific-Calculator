#include<stdio.h>
#include<math.h>

void trigono(void);

int main(){
	trigono();
	return 0;
}

void trigono(void)
{
	int option;
	char x = '1';
	float degree, radian, derajat;
	double hasil;
	const float PI = 3.14159;
	
	do{
		system("cls");
		printf("------------------------------------------------------------------------------\n");	
		printf("		DAFTAR OPERASI YANG BISA DILAKUKAN BESERTA KODENYA\n");
		printf("			Sin   = 1	arcSin 	 = 7\n");
		printf("			Cos   = 2	arcCos   = 8\n");
		printf("			Tan   = 3	arcTan   = 9\n");
		printf("			Cosec = 4	arcCosec = 10\n");
		printf("			Sec   = 5	arcSec   = 11\n");
		printf("			Cotan = 6	arccotan = 12\n");
		printf("------------------------------------------------------------------------------\n\n");
		printf("Input kode operasi yang ingin dijalankan : ");
		scanf("%d", &option);
		
		if(option <= 12 && option > 0){
			printf("Masukan nilai :");
			scanf("%f", &degree);
			
			radian = degree * (PI / 180.0);
			
			switch (option)
			{
					case 1: printf("sin(%f) = %f", degree, sin(radian));
							break;
					case 2: printf("cos(%f) = %f", degree, cos(radian));
							break;
					case 3: printf("tan(%f) = %f", degree, tan(radian));
							break;
					case 4: printf("cosec(%f) = %f", degree, 1/sin(radian));
							break;	
					case 5: printf("sec(%f) = %f", degree, 1/cos(radian));
							break;
					case 6: printf("cotan(%f) = %f", degree, 1/tan(radian));
							break;
					case 7: hasil = asin(degree)* (180.0/PI);
							printf("arcsin(%f) = %lf",degree, hasil);
							break;
					case 8: hasil = acos(degree)* (180.0/PI);
							printf("arccos(%f) = %lf", degree, hasil);
							break;
					case 9: hasil = atan(degree)* (180.0/PI);
							printf("arctan(%f) = %lf", degree, hasil);
							break;
					case 10:hasil = 1/(asin(degree) * (180.0/PI));
							printf("arccosec(%f) = %lf",degree, hasil);
							break;
					case 11:hasil = 1/(acos(degree) * (180.0/PI));
							printf("arcsec(%f) = %lf", degree, hasil);
							break;
					case 12:hasil = 1/(atan(degree)* (180.0/PI));
							printf("arccotan(%f) = %lf", degree, hasil);
							break;
			}
		}
		else{
			printf("\nKODE YANG ANDA MASUKAN SALAH");
		}
		
		printf("\n\nIngin mengulangi lagi? iya = ketik angka bebas, tidak = 0 : ");
		scanf(" %c", &x);
		printf("\n\n");
	}while (x != '0');
}
