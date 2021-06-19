#include <stdio.h>
#include <math.h>

int main(){
	int x, opsi;
	char again = 'Y';
	double value, base, result;
	
	while (again == 'Y') //melakukan perhitungan lagi
	{
	system("cls");
	printf("--------------------------------------------\n");
	printf("                 LOGARITHM\n");
	printf("       yLog(x)   x = nilai   y = base\n");
	printf("             1. Logarithm (log)\n");
	printf("          2. Natural Logarithm (ln)\n");
	printf("--------------------------------------------\n\n");
	printf("Pilih opsi : "); scanf("%d", &opsi);
	
		switch (opsi){
		
		case 1 : 
		
		printf("\nMasukkan nilai base : ");
		scanf("%lf", &base);
		printf("Masukkan nilai x : ");
		scanf("%lf", &value);
	
		logarithm(&base, &value, &result);
		printf("Log%.2f(%.2f) = %f", base, value, result);
		
		break;
		
		case 2 :
		
		printf("\nMasukkan nilai x : ");
		scanf("%lf", &value);
	
		ln(&value, &result);
		printf("Ln(%.2f) = %f", value, result);
		
		break;
			
		default :
			printf("\nError! Masukkan angka lagi 1-2.");
            break;
	}
	
    	printf("\n\nIngin menghitung lagi? Y/N\n");
    	scanf(" %c", &again);
    	again = toupper(again);
	}
	
	printf("\nEnd Process!\nHave a nice day!");
    return 0;
}
void logarithm(double *base, double *value, double *result){
	double a, b;
	
	a = log(*value);
	b = log(*base);
	*result = a/b;			
}
void ln(double *value, double *result){
	*result = log(*value);
}
	
