#include<stdio.h>

void preorder( char t[], int i, int size ){
   if(i > size || t[i] == NULL) return;
   printf("%c ",t[i]);
   preorder( t, i*2, size);//왼쪽서브트리 순회
   preorder(t, i*2+1, size);//오른쪽 서브트리 순회
   
   
}
void inorder( char t[], int i, int size ){
   if(i > size || t[i] == NULL) return;
   inorder( t, i*2, size);//왼쪽서브트리 순회
   printf("%c ",t[i]);
   inorder(t, i*2+1, size);//오른쪽 서브트리 순회
}
void postorder( char *t, int i, int size ){
   if(i > size || t[i] == NULL) return;
   postorder( t, i*2, size);//왼쪽서브트리 순회
   postorder(t, i*2+1, size);//오른쪽 서브트리 순회
   printf("%c ", t[i]);
}
int main(){
   char tree[]= {0,'A', 'B', 'C','D', 'E', 'F', 'G', 0, 0, 'H', 'I',0, 'J', 'K', 'L'};
   int size=16;
   printf("\n<<전위 탐색>>\n");
   preorder( tree, 1, size );
   printf("\n<<중위 탐색>>\n");
   inorder( tree, 1, size );
   printf("\n<<후위 탐색>>\n");
  postorder( tree, 1, size );
   }