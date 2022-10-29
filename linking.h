 
typedef struct data{
	char name[20];
	int time;
}data;

typedef struct LNode{
	data data;
	struct LNode *next; 
}LNode,*LinkList;

bool InitList(LinkList L){//初始化空链表（带头节点）
	L=(LNode*)malloc(sizeof(LNode));//分配头节点
	if (L==NULL){
		return false;
	}
	L->data.name[0]='\0';
	L->data.time=0;
	L->next = NULL;//头节点后暂无节点 
	return true; 
}

//插入系统初始的三组data 
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
bool ListINsert(LinkList L,int i,data* d){//i位插入e 
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
	
	LNode *s=(LNode *)malloc(sizeof(LNode));//分配动态存储空间 
	for(k=0;k<20;k++){
		(*s).data.name[k]=(*d).name[k]; 
	}
	(*s).data.time=(*d).time;//将新数据复制到*s中
	
	s->next=p->next;
	p->next=s;//将结点s连到p，即链表末端 
	return true;//插入成功
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
	}//使p指向第i组数据的前一组 
	
	if(p==NULL){
		return false;
	}
	
	if(p->next==NULL){
		p==NULL;
	}//p的下一组为什么会是NULL????? 
	
	LNode *q=p->next;//q指向要删除的数据 
	p->next=q->next;//使删除数据的前一组数据跳过，直接指向再下一组 
	free(q);//释放内存空间 
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
	printf("修改后的姓名：");
	fflush(stdin);
	while((name1[k]=getchar())!='\n'){
		k++;
	}
	while(name1[0]=='\n'){
		printf("你的名字就是一个换行符吗，那可太可惜了\n");
		printf("请再次输入你的姓名（in English）：");
		k=0;
		fflush(stdin);
		while((name1[k]=getchar())!='\n'){
				k++;
		}
	}
	while(k>19){
		printf("你的名字太长啦，请短一点\n");
		printf("请再次输入你的姓名（in English）：");
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
	printf("修改后时间：");
	scanf("%d",&time1);
	while(time1 <= -1||time1 %1!=0){
		fflush(stdin);
		printf("请重新输入：");
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
