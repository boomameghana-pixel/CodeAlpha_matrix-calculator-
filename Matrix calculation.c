// TASK 2: Medium - Matrix Operations
// Student Name: Bhuma.Meghana | CodeAlpha Internship
#include <stdio.h>
#define MAX 10

// Function declarations - Using 2D arrays
void inputMatrix(int mat[MAX][MAX], int r, int c);
void printMatrix(int mat[MAX][MAX], int r, int c);
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c);
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int r, int c);

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX], trans[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Matrix Operations\n");
    printf("1. Matrix Addition\n2. Matrix Multiplication\n3. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter Matrix A:\n"); inputMatrix(a, r1, c1);
            printf("Enter Matrix B:\n"); inputMatrix(b, r1, c1);
            addMatrix(a, b, result, r1, c1);
            printf("Result of Addition:\n"); printMatrix(result, r1, c1);
            break;

        case 2:
            printf("Enter rows and cols for A: "); scanf("%d %d", &r1, &c1);
            printf("Enter rows and cols for B: "); scanf("%d %d", &r2, &c2);
            if(c1!= r2){ printf("Multiplication not possible!\n"); break; }
            printf("Enter Matrix A:\n"); inputMatrix(a, r1, c1);
            printf("Enter Matrix B:\n"); inputMatrix(b, r2, c2);
            multiplyMatrix(a, b, result, r1, c1, c2);
            printf("Result of Multiplication:\n"); printMatrix(result, r1, c2);
            break;

        case 3:
            printf("Enter rows and columns: "); scanf("%d %d", &r1, &c1);
            printf("Enter Matrix:\n"); inputMatrix(a, r1, c1);
            transposeMatrix(a, trans, r1, c1);
            printf("Transpose Matrix:\n"); printMatrix(trans, c1, r1);
            break;

        default: printf("Invalid Choice!\n");
    }
    return 0;
}

void inputMatrix(int mat[MAX][MAX], int r, int c){
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) scanf("%d",&mat[i][j]);
}
void printMatrix(int mat[MAX][MAX], int r, int c){
    for(int i=0;i<r;i++){ for(int j=0;j<c;j++) printf("%d\t",mat[i][j]); printf("\n"); }
}
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c){
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) res[i][j]=a[i][j]+b[i][j];
}
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2){
    for(int i=0;i<r1;i++) for(int j=0;j<c2;j++){ res[i][j]=0; for(int k=0;k<c1;k++) res[i][j]+=a[i][k]*b[k][j]; }
}
void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int r, int c){
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) trans[j][i]=mat[i][j];
}