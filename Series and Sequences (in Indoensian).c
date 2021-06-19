#include<stdio.h>
#include<math.h>

void aritgeo(void);

int main()
{
	aritgeo();
	return 0;
}

void aritgeo(void)
{
	int option, deret;
	float n, r, a, b, un;
	char x = '1';
	
	do		/*do while untuk looping jika ingin mengulang operasi*/
	{
		system("cls");
		printf("------------------------------------------------------------------------------\n");	
		printf("			OPERASI YANG BISA DILAKUKAN BESERTA\n");
		printf("		Baris aritmatika (Un) = 1	Baris Geometri (Un) = 3\n");
		printf("		Deret aritmatika (Sn) = 2	Deret Geometri (Sn) = 4\n");
		printf("						Deret Geometri (Sn tak hingga) = 5\n");
		printf("------------------------------------------------------------------------------\n\n");
		printf("Input kode operasi yang ingin dijalankan : ");
		scanf("%d", &option);
		
		switch(option)																		/*switch case untuk menentukan operasi apa yang ditentukan*/
		{
			case 1: printf("\nRumus dasar baris aritmatika (Un)\n");
					printf("Un = U1 + (n - 1) * b atau Un = a + (n - 1) * b\n\n");
					printf("Masukan suku ke berapa yang dicari (n) : ");
					scanf("%f", &n);
					printf("Masukan bilangan pertama dalam baris (a) : ");
					scanf("%f", &a);
					printf("Masukan beda antar dua bilangan (b) : ");
					scanf("%f", &b);
					
					printf("\nU%f = %f + (%f - 1) * %f = %f", n, a, n, b, a+((n-1)*b));
					break;
			case 2: printf("Jika beda (b) tidak diketahui ketik 1\n");
					printf("Jika beda (b) diketahui ketik 2\n");
					printf("Jawaban anda : ");
					scanf("%d", &deret);
					if(deret == 1)															/*if untuk menentukan apakah beda dari deret aritmatika diketahui atau tidak*/
					{
						printf("\nRumus dasar deret aritmatika (Sn)\n");
						printf("Sn = n/2 * (a + Un)\n\n");
						printf("Masukan jumlah suku ke berapa (n) : ");
						scanf("%f", &n);
						printf("Masukan bilangan pertama dalam deret (a) : ");
						scanf("%f", &a);
						printf("Masukan bilangan suku ke-%f : ", n);
						scanf("%f", &un);
					
						printf("\nS%f = %f/2 * (%f + %f) = %f", n, n, a, un, (n/2)*(a+un));
					}
					else if(deret == 2)														/*else untuk menentukan apakah beda dari deret aritmatika diketahui atau tidak*/
					{
						printf("\nRumus dasar deret aritmatika (Sn)\n");
						printf("Sn = n/2 * (2a + (n-1) * b)\n\n");
						printf("Masukan jumlah suku ke berapa (n) : ");
						scanf("%f", &n);
						printf("Masukan bilangan pertama dalam deret (a) : ");
						scanf("%f", &a);
						printf("Masukan beda antar dua bilangan (b) : ");
						scanf("%f", &b);
					
						printf("\nS%f = %f/2 * (2*%f + (%f-1) * %f) = %f", n, n, a, n, b, (n/2)*(2*a+(n-1)*b));
					}
					else																	/*else jika pilihan yang dimasukan untuk menentukan beda (b)nya salah*/
					{
						printf("\nKODE YANG ANDA MASUKAN SALAH");
					}
					break;
			case 3: printf("\nRumus dasar baris geometri (Un)\n");
					printf("Un = a * r^(n-1)\n");
					printf("\nMasukan suku ke berapa yang dicari (n) : ");
					scanf("%f", &n);
					printf("Masukan bilangan pertama dalam deret (a) : ");
					scanf("%f", &a);
					printf("Masukan rasio antar dua bilangan (r) : ");
					scanf("%f", &r);
					
					printf("\nU%f = %f * %f^(%f - 1) = %f", n, a, r, n, pow(r,(n-1)));
					break;
			case 4: printf("Jika rasio dari deret lebih besar dari 1 (r>1) ketik angka = 1\n");
					printf("Jika rasio dari deret lebih kecil dari 1 (r<1) ketik angka = 2\n");
					printf("Jawaban anda : ");
					scanf("%d", &deret);
					if(deret == 1)															/*if untuk rasio deret geometri lebih besar dari 1*/
					{
						printf("\nRumus dasar deret geometri (Sn)\n");
						printf("Sn = (a * (r^n - 1)) / (r - 1)\n\n");
						printf("Masukan jumlah suku ke berapa (n) : ");
						scanf("%f", &n);
						printf("Masukan bilangan pertama dalam deret (a) : ");
						scanf("%f", &a);
						printf("Masukan rasio r : ");
						scanf("%f", &r);
						if(r > 1 || r < -1)													/*if untuk memastikan rasionya benar*/
						{
							printf("\nS%f = (%f * (%f^%f - 1)) / (%f - 1) = %f", n, a, r, n, r, (a * (pow(r,n) - 1)) / (r - 1));
						}
						else
						{
							printf("\nKODE YANG ANDA MASUKAN SALAH");
							break;
						}
					}
					else if(deret == 2)														/*else untuk rasio deret geometri lebih kecil dari 1*/
					{
						printf("\nRumus dasar deret geometri (Sn)\n");
						printf("Sn = (a * (1 - r^n)) / (1 - r)\n\n");
						printf("Masukan jumlah suku ke berapa (n) : ");
						scanf("%f", &n);
						printf("Masukan bilangan pertama dalam deret (a) : ");
						scanf("%f", &a);
						printf("Masukan rasio r : ");
						scanf("%f", &r);
						if(r > -1 && r < 1 && r != 0)										/*if untuk memastikan rasionya benar*/
						{
							printf("\nS%f = (%f * (1 - %f^%f)) / (1 - %f) = %f", n, a, r, n, r, (a * (1 - pow(r,n))) / (1 - r));
						}
						else
						{
							printf("\nKODE YANG ANDA MASUKAN SALAH");
							break;
						}					
					}
					else
					{
						printf("\nKODE YANG ANDA MASUKAN SALAH");
					}
					break;
			case 5: printf("\nRumus dasar deret geometri tak hingga");
					printf("S = a / (1 - r) syarat (-1 < r < 1)");
					printf("\nMasukan bilangan pertama dalam deret (a) : ");
					scanf("%f", &a);
					printf("Masukan rasio r (-1 < r < 1): ");
					scanf("%f", &r);
					if(r > -1 && r < 1 && r != 0)											/*if untuk memastikan rasionya benar*/
					{
						printf("\nS = %f / (1 - %f) = %f", a, r, a / (1 - r));
						break;
					}
					else
					{
						printf("\nKODE YANG ANDA MASUKAN SALAH");
						break;
					}
			default:printf("\nKODE YANG ANDA MASUKAN SALAH");
					break;
		}
		
		printf("\n\nIngin mengulangi lagi? iya = ketik angka bebas, tidak = 0 : ");
		scanf(" %c", &x);
		printf("\n\n");
	} while(x != '0');
}
