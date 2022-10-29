 
typedef struct data{
	char name[20];
	int time;
}data;

typedef struct LNode{
	data data;
	struct LNode *next; 
}LNode,*LinkList;

bool InitList(LinkList L){//��ʼ����������ͷ�ڵ㣩
	L=(LNode*)malloc(sizeof(LNode));//����ͷ�ڵ�
	if (L==NULL){
		return false;
	}
	L->data.name[0]='\0';
	L->data.time=0;
	L->next = NULL;//ͷ�ڵ�����޽ڵ� 
	return true; 
}

//����ϵͳ��ʼ������data 
void my_Strangelink(LinkList L){
	L->data.name[0]='a';
	L->data.name[1]='\0';
	L->data.time=4;
	data data2,data3;
	data2.name[0]='b';
	data3.name[0]='c';
	data2.time=6;
	data3.time=9;
	ListINsert(L,1,&data2);
	ListINsert(L,2,&data3);
}

////////////////////////////////////////
bool ListINsert(LinkList L,int i,data* d){//iλ����e 
	int k;
	if (i<1){
		return false;
	}
	LNode *p;
	int j=0;
	p=L; 
	while (p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	
	LNode *s=(LNode *)malloc(sizeof(LNode));//���䶯̬�洢�ռ� 
	for(k=0;k<20;k++){
		(*s).data.name[k]=(*d).name[k]; 
	}
	(*s).data.time=(*d).time;//�������ݸ��Ƶ�*s��
	
	s->next=p->next;
	p->next=s;//�����s����p��������ĩ�� 
	return true;//����ɹ�
}

//////////////////////////////////////
bool ListDelete(LinkList L,int i){
	if(i<1){
		return false;
	} 
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}//ʹpָ���i�����ݵ�ǰһ�� 
	
	if(p==NULL){
		return false;
	}
	
	if(p->next==NULL){
		p==NULL;
	}//p����һ��Ϊʲô����NULL????? 
	
	LNode *q=p->next;//qָ��Ҫɾ�������� 
	p->next=q->next;//ʹɾ�����ݵ�ǰһ������������ֱ��ָ������һ�� 
	free(q);//�ͷ��ڴ�ռ� 
	return true;
} 


bool my_ListResearch(LinkList L,int i){
	int k;
	if (i<1){
		return false;
	}
	LNode *p;
	int j=0;
	p=L;
	while (p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	printf("	name:%s\n",(*p).data.name);
	printf("	time:%d\n",(*p).data.time);
	return true;
}


bool my_ListChange(LinkList L,int i){
	char name1[20]="\0";
	int time1 = -1;
	int k=0;
	if (i<1){
		return false;
	}
	LNode *p;
	int j=0;
	p=L;
	while (p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	printf("name:%s\n",(*p).data.name);
	printf("time:%d",(*p).data.time);
	printf("�޸ĺ��������");
	fflush(stdin);
	while((name1[k]=getchar())!='\n'){
		k++;
	}
	while(name1[0]=='\n'){
		printf("������־���һ�����з����ǿ�̫��ϧ��\n");
		printf("���ٴ��������������in English����");
		k=0;
		fflush(stdin);
		while((name1[k]=getchar())!='\n'){
				k++;
		}
	}
	while(k>19){
		printf("�������̫���������һ��\n");
		printf("���ٴ��������������in English����");
		k=0;
		fflush(stdin);
		while((name1[k]=getchar())!='\n'){
			k++;
		}
	}
	name1[k]='\0';
	fflush(stdin);
	for (k=0;k<20;k++){
		(*p).data.name[k]=name1[k];
	}
	printf("�޸ĺ�ʱ�䣺");
	scanf("%d",&time1);
	while(time1 <= -1||time1 %1!=0){
		fflush(stdin);
		printf("���������룺");
		scanf("%d",&time1);
	} 
	(*p).data.time=time1;
	return true;
}


void my_Bubbling(LinkList L,int i){
	int k,j,s;
	int st;
	char str[20];
	LNode *p;
	p=L;
	for(j=0;j<i;j++){
		for (k=0;k<i;k++){
			if(p->data.time<p->next->data.time){
				s=p->data.time;
				p->data.time=p->next->data.time;
				p->next->data.time=s;
				strcpy(str,p->data.name);
				strcpy(p->data.name,p->next->data.name);
				strcpy(p->next->data.name,str);
				p=p->next;
			}
		}
		p=L;
	}
		
}
