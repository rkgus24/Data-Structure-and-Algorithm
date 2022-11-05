#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data[4];
	struct Node *next;
}Node;

//공백 연결 리스트를 생성
Node *createList(){
	Node* head = (Node*)malloc(sizeof(Node));
	head = NULL;
	return head;
}

Node* deleteAll(Node* head){
	Node *p = head;
	Node* removed;
	if (p == NULL) return NULL;
	while(p != NULL){
		removed = p; //free할 주소를 removed 저장	
		p = p->next; //////// 중요 시험 나옴 다음 주소로 이동;
		free(removed); //removed 주소 할당해제
		removed = removed->next = NULL;//할당해제 후 NULL참조로 저장
	}
	return head;	
}
// 연결 리스트를 순서대로 출력하는 연산
void printList(Node *head){
	Node *p = head;
	printf("L =(");
	while(p!=NULL){
	printf("%s", p->data); //p의 값을 출력 처음에는 head 의 값
  p = p->next; //p 를 다음 값으로 이동
	if(p!=NULL) printf("->"); //다음데이터가 있으면 ->출력
	}
	printf(") \n");

}

// 첫번째 노드로 삽입하는 연산
Node*  insertFirst(Node *head, char* x){
  Node* newNode = (Node*)malloc(sizeof(Node)); //동적할당
	strcpy(newNode->data, x); // 새 노드의 데이터 필드에 x 저장
  newNode->next = head; //newNode와 head 를 연결하기
	head = newNode; //newNode를 새로운 head로 저장하기
	return head;
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddle(Node* head, Node* pre, char* x){
	Node* newNode = (Node*)malloc(sizeof(Node)); //동적할당
	strcpy(newNode->data, x); //데이터 저장
	
	if(head == NULL || pre == NULL){ //오류
		newNode->next = NULL;
		head = newNode;
	}
	else {
	newNode->next = pre->next; // 뉴노드를 pre 뒤에 값으로 연결하고
	pre->next = newNode; //프리뒤를 newnode로 설정
	}
}
void insertLast( Node *head, char *x){
	Node* newNode = (Node*)malloc(sizeof(Node)); //새노드 동적할당;
	Node* p;
	strcpy(newNode->data, x);
	newNode->next = NULL; //newNode 는 마지막이니까 null값
	if(head==NULL) { //head가 null이면
		head = newNode; //newNode가 head주소로 저장 
	}
	p = head;
	while(p->next != NULL) {
		p = p->next; /* temp는 NULL 이 나올때까지 계속해서 이동*/
	}
	p->next = newNode;
}	

Node *searchNode(Node *head, char *x){
	Node *temp =head;
	while (temp != NULL){
		if(strcmp(temp->data, x) == 0) return temp;
		else temp=temp->next; /*다음 주소로 이동*/
	}
	return temp;	
}

int main(){
	Node* head;
	Node * p;

	printf("(1) 공백리스트 생성하기! \n");
	head = createList();
	printList( head );
	
	printf("(2) 리스트 처음에 [수]노드 삽입하기! \n");
	head =insertFirst( head, "수");
	printList( head );
	
	printf("(3) 리스트 마지막에 [금]노드 삽입하기! \n");
	insertLast( head, "금");
	printList( head );
	
	printf("(4) 리스트 첫 번째에 [월]노드 삽입하기! \n");
	head =insertFirst( head, "월");
	printList( head);
	
	printf("(5) 리스트에서 [수] 노드를 찾아 그 뒤에 [목] 삽입하기! \n");
	p = searchNode(head, "수");
	if( p == NULL ) printf("찾는 데이터가 없습니다.\n");
	else insertMiddle( head, p, "목");
	printList( head );
	
	printf("(6) 리스트를 삭제하여 공백 리스트로 만들기! \n");
	deleteAll(head);
	printList( head );
	return 0;
}
