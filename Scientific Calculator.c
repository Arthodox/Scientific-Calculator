#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float num[25];
	char op[25];	
}Calc;

struct dimensi{
    int row;
    int col;
};

//Prototypes 
void add(Calc *opt,int i);
void sub(Calc *opt,int i);
float mul(float num1,float num2);
float divis(float num1,float num2);
float power(float num1,float num2);
float root(float num1,float num2);
float fact(float num);
void log_ln(void);
void logarithm(double *base, double *value, double *result);
void ln(double *value, double *result);
void ln(double *value, double *result);
void permucombi(void);
void trigono(void);
void aritgeo(void);
void matrix(void);
struct dimensi DimensiMatrix(int i);
void InputDimensi(struct dimensi *dimensi, char name[]);
void Matrix(int array[10][10], int rows, int colums);
void InputMatrix(int matrix[10][10], char name[],int rows,int cols);
void PrintMatrix(int array[10][10], int rows, int colums);
void Addition(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul); //penjumlahan sekaligus pengurangan
void Scalar(int array[10][10], int scalar, int rows, int colums);
void Multiplication(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA, int columsB);

int main(){
	int i=0,j=0,b,check=0;//Sets Counters and checkers for the Loops
	Calc init, math;//initializing the Structs
	system("cls");//Clears command window
	printf("-+=Scientific Calculator=+-\nMade by,\n1. Rui Vressel Sugarcia (1906384131)\n2. Stefanus Prayoga Dewanto (1906306230)\n3. Sultan Ahmad Nuha (1906306306)\n\nOperating mode options, \n1. Basic (B/b)\n2. Complex (C/c)\nSelect Operating mode: ");
	scanf(" %c",&init.op[0]);
	
	while(init.op[0] != 'C' && init.op[0] != 'c' &&init.op[0] != 'B' && init.op[0] != 'b'){//Checking for valid ops
		printf("INVALID OPERATING MODE\nSelect an Operating mode: ");
		scanf(" %c",&init.op[0]);
	}
	
	if(init.op[0] == 'B'||init.op[0] == 'b'){//Transfers to Basic Operations Mode
		do{
			b=0;
			system("cls"); //Clears command window
			printf("-=BASIC MODE=-\nAvailable Operators:\n1. Addition (+)\n2. Subtraction(-)\n3. Multiplication(x)\n4. Division(/)\n5. Power(^)\n6. Roots(R)\n7. Factorial(!)\n\nInput Example: 2x3+25/2+3!\n(note: do not use parentheses(). Always enter your factorials\nat the END of the operation)\n\nEnter \"0B\" to return to main menu.\n\nEnter Calculations ");
			
			do{
				do{
					scanf("%f%c",&math.num[b],&math.op[b]);
					b++;
				}while(math.op[b-1]!='\n' && math.op[b-1]!='!' && math.op[b-1]!='B');
				
				if(math.op[b-1]=='B'){//
					main();
				}
				
				for(i=0;i<b-1;i++){ // Checking every operator for validity
					if(math.op[i]!='+'&& math.op[i]!='-'&& math.op[i]!='x'&& math.op[i]!='/'&& math.op[i]!='^'&& math.op[i]!='R'&& math.op[i]!='!'){
						printf("INVALID OPERATORS\nEnter Calculations: ");
						check=0;
						b=0;//resets counter for new input
					}
					else{
						check=1;// if all operator are valid enables loop escape
					}
				}
			}while(check==0);//Pseudo Bool value to check if the operators are valid or not
			
			if(math.op[b-1]=='!'){ //Recalibrates Form To accomodate acceptable operation form
				math.num[b]=0;
				b++;
			}
			
			b--;//Recalibrates for proper indexing
			//Priority 1 (Factorials, Roots and Power)
			for(i=0;i<b;i++){
				if(math.op[i]=='^'){
					math.num[i]= power(math.num[i],math.num[i+1]);
					for(j=i+1;j<b;j++){
						math.num[j]=math.num[j+1];
						math.op[j-1]=math.op[j];
					}
					b--;
					i--;
				}
				else if(math.op[i]=='R'){
					math.num[i]= root(math.num[i],math.num[i+1]);
					for(j=i+1;j<b;j++){
						math.num[j]=math.num[j+1];
						math.op[j-1]=math.op[j];
					}
					b--;
					i--;
				}
				else if (math.op[i]=='!'){
					math.num[i] = fact(math.num[i]);
					if(i == b-1){
						math.op[i]='+';
					}
					else{
						printf("Enter Operation after Factorial: ");
						scanf(" %c",&math.op[i]);
						i--;
					}
				}
			}
			
			//Priority 2 (Multiplication and Division)
			for(i=0;i<b;i++){
				if(math.op[i]=='x'){
					math.num[i]= mul(math.num[i],math.num[i+1]);
					for(j=i+1;j<b;j++){
						math.num[j]=math.num[j+1];
						math.op[j-1]=math.op[j];
					}
					b--;
					i--;
				}
				else if(math.op[i]=='/'){
					math.num[i]= divis(math.num[i],math.num[i+1]);
					for(j=i+1;j<b;j++){
						math.num[j]=math.num[j+1];
						math.op[j-1]=math.op[j];
					}
					b--;
					i--;
				}
			}
			
			//Priority 3 (Addition and Subtraction)
			for(i=0;i<b;i++){
				switch (math.op[i]){
					case '+':
						add(&math,i);
						break;
					case '-':
						sub(&math,i);
						break;
				}
				math.num[i]=math.num[i+1];
			}
	
			printf("Your result is %f",math.num[i]);
			
			printf("\n\nContinue the Operation, enter any to continue, Zero (0) to end: ");
			scanf(" %c",&init.op[1]);
		}while(init.op[1]!='0');
	}
	
	else if(init.op[0] == 'C'||init.op[0] == 'c'){
		system("cls"); //Clears command window
		printf("-=Complex MODE=-\nOperations: \n1. Logaritma dan Ln\n2. Permutasi & Kombinasi\n3. Trigonometri\n4. Deret Aritmatika dan Geometri\n5. Operasi Matrix\nEnter '0'(zero) to go back to main menu.\n\nPilih Nomor Operasi yang diinginkan: ");
		
		do{
			scanf(" %c",&init.op[1]);
			if(!(init.op[1]>='1'&&init.op[1]<='5')){
				printf("INVALID MODE!!\nPilih Nomor Operasi yang diinginkan: ");
			}
		}while(!(init.op[1]>='0'&&init.op[1]<='5'));
		
		switch(init.op[1]){
			case '0':
				main();
				break;
			case '1':
				log_ln();
				break;
			case '2':
				permucombi();
				break;
			case '3':
				trigono();
				break;
			case '4':
				aritgeo();
				break;
			case '5':
				matrix();
				break;
		}			
	}
	
	return 0;	
}

void add(Calc *opt,int i){
	opt->num[i+1]+=opt->num[i];
}

void sub(Calc *opt,int i){
	opt->num[i+1]=opt->num[i] - opt->num[i+1];
}

float mul(float num1,float num2){
	return num1*num2;
}

float divis(float num1,float num2){
	return num1/num2;
}

float power(float num1,float num2){
	return pow(num1,num2);
}

float root(float num1,float num2){
	return pow(num2,(1/num1));
}

float fact(float num){
	if(num<=1){
		return 1;
	}
	else{
		return (num*fact(num-1));
	}
}

void log_ln(){
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

void permucombi(void){
	int option, n, r;
	char x='1';
	
	do{//Loop berlaku sebagai opsi melakukan operasi ulang dan juga sebagai error management
		system("cls");
		printf("-------------------------------------------------------------------------------\n");
		printf("			KODE OPERASI YANG BISA DILAKUKAN\n");
		printf("		     	  Permutasi = 1	 Kombinasi = 2\n");
		printf("-------------------------------------------------------------------------------\n\n");
		printf("Input kode operasi yang ingin dijalankan : ");
		scanf("%d",&option);//Memilih antara Permutasi atau Kombinasi
		
		switch(option)
		{
			case 1: printf("\nRumus dasar permutasi\n"); //Operasi Permutasi
					printf("nPr = n!/(n-r)!  <-- Syarat: n>=r>=0\n\n");
					do{
						printf("Silahkan input n : ");
						scanf("%d", &n);
						printf("Silahkan input r : ");
						scanf("%d", &r);
						if(!(n>=r && r>=0)){
							printf("Masukan input Valid!!\n");
						}
					}while(!(n>=r && r>=0));				
					printf("\n%dP%d = %d! / (%d - %d)! = %f", n, r, n, n, r, (fact(n)/fact(n-r)));
					break;
			case 2: printf("\nRumus dasar kombinasi\n"); //Operasi Kombinasi 
					printf("nCr = n!/[r!(n-r)!] <-- Syarat: n>=r>=0\n\n");
					do{
						printf("Silahkan input n : ");
						scanf("%d", &n);
						printf("Silahkan input r : ");
						scanf("%d", &r);
						if(!(n>=r && r>=0)){
							printf("Masukan input Valid!!\n");
						}
					}while(!(n>=r && r>=0));	
					printf("\n%dC%d = %d! / [%d!(%d - %d)!] = %f", n, r, n, r, n, r, (fact(n)/(fact(r) * fact(n-r))));
					break;
			default:printf("KODE YANG ANDA MASUKAN SALAH"); // Error Manager 
					break;
		}
		
		printf("\n\nIngin mengulangi lagi? iya = Enter apa saja, tidak = 0 : ");
		scanf(" %c", &x);
		printf("\n\n");
	}while (x != '0');
}

void trigono(void){
	int option;
	char x='1';
	float degree, radian, derajat;
	double hasil;
	const float PI = 3.14159;
	
	do{//Loop berlaku sebagai opsi melakukan operasi ulang dan juga sebagai error management
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
		scanf("%d", &option);// Menginput Jenis operasi yang diinginkan 
		
		if(option <= 12 && option > 0){ //Input jika Operasi yang diinput telah sesuai
			printf("Masukan nilai :");
			scanf("%f", &degree); 
			
			radian = degree * (PI / 180.0);
		
			switch (option){ // Mencetak Hasil operasi yang dilakukan 
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
		else
		{
			printf("\nKODE YANG ANDA MASUKAN SALAH");//Error Manager 
		}
		
		printf("\n\nIngin mengulangi lagi? iya = ketik angka bebas, tidak = 0 : ");
		scanf(" %c", &x);
		printf("\n\n");
	}while (x != '0');
}

void aritgeo(void){
	int option, deret;
	float n, r, a, b, un;
	char x ='1';
	
	do{	/*do while untuk looping jika ingin mengulang operasi*/
		system("cls");
		printf("------------------------------------------------------------------------------\n");	
		printf("			OPERASI YANG BISA DILAKUKAN BESERTA\n");
		printf("		Baris aritmatika (Un) = 1	Baris Geometri (Un) = 3\n");
		printf("		Deret aritmatika (Sn) = 2	Deret Geometri (Sn) = 4\n");
		printf("			Deret Geometri (Sn tak hingga) = 5\n");
		printf("------------------------------------------------------------------------------\n\n");
		printf("Input kode operasi yang ingin dijalankan : ");
		scanf("%d", &option);
		
		switch(option)/*switch case untuk menentukan operasi apa yang ditentukan*/
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
					if(deret == 1)	/*if untuk menentukan apakah beda dari deret aritmatika diketahui atau tidak*/
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
					else if(deret == 2)	/*else untuk menentukan apakah beda dari deret aritmatika diketahui atau tidak*/
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
					else	/*else jika pilihan yang dimasukan untuk menentukan beda (b)nya salah*/
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
					if(deret == 1)	/*if untuk rasio deret geometri lebih besar dari 1*/
					{
						printf("\nRumus dasar deret geometri (Sn)\n");
						printf("Sn = (a * (r^n - 1)) / (r - 1)\n\n");
						printf("Masukan jumlah suku ke berapa (n) : ");
						scanf("%f", &n);
						printf("Masukan bilangan pertama dalam deret (a) : ");
						scanf("%f", &a);
						printf("Masukan rasio r : ");
						scanf("%f", &r);
						if(r > 1 || r < -1)	/*if untuk memastikan rasionya benar*/
						{
							printf("\nS%f = (%f * (%f^%f - 1)) / (%f - 1) = %f", n, a, r, n, r, (a * (pow(r,n) - 1)) / (r - 1));
						}
						else
						{
							printf("\nKODE YANG ANDA MASUKAN SALAH");
							break;
						}
					}
					else if(deret == 2)	/*else untuk rasio deret geometri lebih kecil dari 1*/
					{
						printf("\nRumus dasar deret geometri (Sn)\n");
						printf("Sn = (a * (1 - r^n)) / (1 - r)\n\n");
						printf("Masukan jumlah suku ke berapa (n) : ");
						scanf("%f", &n);
						printf("Masukan bilangan pertama dalam deret (a) : ");
						scanf("%f", &a);
						printf("Masukan rasio r : ");
						scanf("%f", &r);
						if(r > -1 && r < 1 && r != 0)	/*if untuk memastikan rasionya benar*/
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
					if(r > -1 && r < 1 && r != 0)	/*if untuk memastikan rasionya benar*/
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

void matrix(void){
	
	int matrixA[10][10];
    int matrixB[10][10];
    int opsi;
    int scalar = 0;
    int add = 1;
    int sub = -1;
    char again = 'Y';
    
    while (again == 'Y') //untuk melakukan perhitungan kembali
	{
    system("cls");
	printf("--------------------------------------------\n");
	printf("                   MATRIX\n");
	printf("                1. Addition\n");
	printf("               2. Subtraction\n");
	printf("            3. Multiple by Scalar\n");	
	printf("              4. Multiplication\n");
	printf("--------------------------------------------\n\n");
	printf("Pilih Opsi : "); scanf("%d", &opsi);

        struct dimensi d;
        struct dimensi da,db;

        switch (opsi){

        case 1:
        	
            d = DimensiMatrix(opsi);
            InputMatrix(matrixA,"A",d.row,d.col);
            InputMatrix(matrixB,"B",d.row,d.col);

            printf("\nmatrix A + matrix B = \n");
            Addition(matrixA, matrixB, d.row,d.col, add);

            break;

        case 2:

            d = DimensiMatrix(opsi);
            InputMatrix(matrixA,"A",d.row,d.col);
            InputMatrix(matrixB,"B",d.row,d.col);

            printf("\nmatrix A - matrix B = \n");
            Addition(matrixA, matrixB, d.row,d.col, sub);

            break;

        case 3:

            printf("\nNilai scalar : ");
            scanf("%d", &scalar);
            printf("\nBesar scalar = %d ", scalar);

            d = DimensiMatrix(opsi);
            InputMatrix(matrixA,"A",d.row,d.col);
            
            printf("\nMatrix A * %d = \n", scalar);
            Scalar(matrixA, scalar, d.row, d.col);

            break;

        case 4:
        	
            InputDimensi(&da, "A");
            InputDimensi(&db, "B");

            while (da.col != db.row)
            {
                printf("\n\nError! kolom matrix pertama beda dengan baris matrix kedua.\n\n");
                InputDimensi(&da, "A");
                InputDimensi(&db, "B");
            }
            InputMatrix(matrixA,"A",da.row,da.col);
            InputMatrix(matrixB,"B",db.row,db.col);

            Multiplication(matrixA, matrixB, da.row, da.col, db.col);

            break;
        	
        default:
            printf("\nError! Masukkan angka lagi 1-4.");
            break;
        }

        printf("\n\nIngin menghitung lagi? Y/N\n");
        scanf(" %c", &again);
        again = toupper(again);
    }
    printf("\nEnd Process!\nHave a nice day!");
}

struct dimensi DimensiMatrix(int i){
    struct dimensi da,db;
    if (i == 3){               //pada case 3 hanya memerlukan 1 matrix
    	InputDimensi(&da, "A");
    	return da;
	}
	else{
		InputDimensi(&da, "A");
    	InputDimensi(&db, "B");
	}	
    while ((da.row != db.row) || (da.col != db.col)){
        printf("\nMatrix harus dengan dimensi yang sama\n");
        InputDimensi(&da, "A");
        InputDimensi(&db, "B");
    }
    return da;
}

void InputDimensi(struct dimensi* d, char name[]){
    printf("\nMasukkan dimensi kolom & baris matrix %s: ",name);
    scanf("%d%d",&( d->row ), &( d->col ));
}

void InputMatrix(int matrix[10][10], char name[],int rows,int cols){
    printf("\nMasukkan angka matrix %s ukuran %d x %d : \n",name, rows, cols);
    Matrix(matrix, rows, cols);
    printf("\n  Matrix %s : \n",name);
    PrintMatrix(matrix, rows, cols);
}

void Matrix(int array[10][10], int rows, int colums){
    int i, j;
    for (i = 0; i < rows; i++){                             
        printf("%d input untuk row %d: ", colums, i + 1);
        for (j = 0; j < colums; j++){
            scanf("%d", &array[i][j]);
        }
    }
    return;
}

void PrintMatrix(int array[10][10], int rows, int colums){
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < colums; j++){
            printf("  %d", array[i][j]);
        }
        printf("\n");
    }
}

void Addition(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul){ //penjumlahan sekaligus pengurangan
    int i, j;
    int x[10][10];
    int y[10][10];
    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            y[i][j] = mul * arraytwo[i][j]; //mul untuk membuat matriks kedua berniali positif atau negatif
        }                                   //positif untuk aaddition & negatif untuk substraction
    }

    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            x[i][j] = arrayone[i][j] + y[i][j]; //Hasil dari penjumlahan matrix pertama dan kedua(dipengaruhi oleh mul)
            printf("  %d", x[i][j]);
        }
        printf("\n");
    }
}

void Scalar(int array[10][10], int scalar, int rows, int colums){
    int i, j;
    int y[10][10];
    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            y[i][j] = scalar * array[i][j];
            printf("%d  ", y[i][j]);
        }
        printf("\n");
    }

}

void Multiplication(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA,int columsB){
    int i, j, k;
    int x[10][10];

    for (i = 0; i < rowsA; ++i)           //membuat matrix acuan menjadi 0 terlebih dahulu
        for (j = 0; j < columsB; ++j)
        {
            x[i][j] = 0;
        }

    for (i = 0; i < rowsA; ++i)           //3 for disini untuk melakukan perkalian matrix baris*kolom
        for (j = 0; j < columsB; ++j)
            for (k = 0; k < columsA; ++k)
            {
                x[i][j] += arrayone[i][k] * arraytwo[k][j]; //hasil dari perkalian dimasukkan ke matrix acuan
            }
    printf("\nHasil perkalian matrix = \n");
    for (i = 0; i < rowsA; ++i)
        for (j = 0; j < columsB; ++j) //print hasil perkalian matrix
        {
            printf("  %d", x[i][j]);
            if (j == columsB - 1)
                printf("\n");
        }
    }
    
