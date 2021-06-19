#include<stdio.h>

long factorial(long number);
void permucombi(void);

int main()
{
	permucombi();
	return 0;
}
void permucombi(void)
{
	int option, n, r;
	char x = '1';
	
	do{
		system("cls");
		printf("-------------------------------------------------------------------------------\n");
		printf("			KODE OPERASI YANG BISA DILAKUKAN\n");
		printf("		     	  Permutasi = 1	 Kombinasi = 2\n");
		printf("-------------------------------------------------------------------------------\n\n");
		printf("Input kode operasi yang ingin dijalankan : ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: printf("\nRumus dasar permutasi\n");
					printf("nPr = n!/(n-r)!\n\n");
					printf("Silahkan input n : ");
					scanf("%d", &n);
					printf("Silahkan input r : ");
					scanf("%d", &r);
					
					printf("\n%dP%d = %d! / (%d - %d)! = %ld", n, r, n, n, r, factorial(n) / factorial(n-r));
					break;
			case 2: printf("\nRumus dasar kombinasi\n");
					printf("nCr = n!/[r!(n-r)!]\n");
					printf("\nSilahkan input n : ");
					scanf("%d", &n);
					printf("Silahkan input r : ");
					scanf("%d", &r);
					
					printf("\n%dC%d = %d! / [%d!(%d - %d)!] = %ld", n, r, n, r, n, r, factorial(n) / (factorial(r) * factorial(n-r)));
					break;
			default:printf("KODE YANG ANDA MASUKAN SALAH");
					break;
		}
		
		printf("\n\nIngin mengulangi lagi? iya = ketik angka bebas, tidak = 0 : ");
		scanf(" %c", &x);
		printf("\n\n");
	}while (x != '0');
}

long factorial(long number)
{
	if(number <= 1){
		return 1;
	}
	else{
		return (number * factorial(number-1)); 	
	}
}
