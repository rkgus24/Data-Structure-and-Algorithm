#include <stdio.h>
#define ROWS 3
#define COLS 3
void inputMatrix(int a[][COLS]);
void transMatrix(int a[][COLS],int b[][COLS]);
void printMatrix(int a[][COLS]);
int main(){
    int array1[ROWS][COLS];
    int array2[ROWS][COLS];
		inputMatrix(array1);	
    transMatrix(array1,array2);
    printMatrix(array1);
		printf("\n   전치행렬 출력\n");
	  printf("  --------------\n");
    printMatrix(array2);
    return 0;
}
void inputMatrix(int a[][COLS]){
    int i,j;
  //3행 3열 배열 입력
}
void transMatrix(int a[][COLS],int b[][COLS]){
  //a배열의 행과열을 바꾸어 b배열에 저장
}
void printMatrix(int a[][COLS]){
    int i,j;
    //3행 3열 배열 출력

}
