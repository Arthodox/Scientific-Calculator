#include <stdio.h>

struct dimensi{
    int row;
    int col;
};
struct dimensi DimensiMatrix();
void InputDimensi(struct dimensi *dimensi, char name[]);
void Matrix(int array[10][10], int rows, int colums);
void InputMatrix(int matrix[10][10], char name[],int rows,int cols);
void PrintMatrix(int array[10][10], int rows, int colums);
void Addition(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul); //penjumlahan sekaligus pengurangan
void Scalar(int array[10][10], int scalar, int rows, int colums);
void Multiplication(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA, int columsB);

int main(){
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
        	
            d = DimensiMatrix();
            InputMatrix(matrixA,"A",d.row,d.col);
            InputMatrix(matrixB,"B",d.row,d.col);

            printf("\nmatrix A + matrix B = \n");
            Addition(matrixA, matrixB, d.row,d.col, add);

            break;

        case 2:

            d = DimensiMatrix();
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
    return 0;
}
struct dimensi DimensiMatrix(int i){
    struct dimensi da,db;
    if (i == 3){               //pada case 3 hanya memerlukan 1 matrix
    InputDimensi(&da, "A");
    return da;
    
}	else{
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
