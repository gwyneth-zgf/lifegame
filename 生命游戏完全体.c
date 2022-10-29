#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include <windows.h>
#include "linking.h"
#include "youhua+.h"
#define LENGTH 40
#define WIDTH 40

void my_Printmap(int map[WIDTH][LENGTH],int width,int length,int skin);
void my_Mapcalculate(int map[WIDTH][LENGTH],int width,int length);
int my_Roundsum(int map[WIDTH][LENGTH],int widaddress,int lenaddress);
void my_Mapcalculate_living(int map[WIDTH][LENGTH],int width,int length);
void my_Huaxiangji(int map[WIDTH][LENGTH]); 
void my_Ship(int map[WIDTH][LENGTH]);
void my_Gospersglidergun(int map[WIDTH][LENGTH]); 

int main(void){
	start();
	int width,length;
	int a=-5;
	int b=-5;
	int skin=-1;
	int mod=-1;
	int count;
	int total=1;
	int judge;
	int map[WIDTH][LENGTH];
	int k=0;
	int circle=0;
	int datacount;
	int linkchange=-1;
	int i=-1;
	int repeatlinkchange;
	int firstgame=0;
	data yourdata;
	LinkList L;
	int turn=0; 
	int turn1=-1;
	outgame:
	for(width=0;width<WIDTH;width++){
		for(length=0;length<LENGTH;length++){
			map[width][length]=0;
		}
	}//����������ȫ������
	
	printf("��ѡ��������ʽ(0=�׸��ӣ�1=���ǣ�2=�����Σ�3=Բ��)��");
	scanf("%d",&skin);
	while(skin!=0&&skin!=1&&skin!=2&&skin!=3){
				fflush(stdin);
				printf("�������ֵ�������������룺");
				scanf("%d",&skin);
	}  
	printf("��ѡ��ģʽ(0=���У�1=��������,2=����������)��");
	scanf("%d",&mod);
	while(mod!=0&&mod!=1&&mod!=2){
				fflush(stdin);
				printf("�������ֵ�������������룺");
				scanf("%d",&mod);
	}
	
/*********************************************************
*  mod=0Ϊ����ģʽ                                       *
*  �������£�                                            *
*  ����������                                          *
*  ���һ��������Χ����������2�����غϽ���ʱ����         *
*  ���һ��������Χ����������3�����غϽ���ʱ����         *
*  ���һ����������Χ�������������غϽ���ʱ�������      *
*  ���һ��������Χ��2��3���������غϽ���ʱ����ԭ��      *
**********************************************************/

	if(mod==0){
		while(a!=-1&&b!=-1){
			printf("������������������ĸ��ӣ�������ͼΪ40*40��(���뷽ʽ�������� ������)(�����룺-1 -1��ʼ����)\n"); 
			printf("���ṩ����������ģ�ͣ�����-2 -2��Ϊ�����ģ�ͣ�-3 -3Ϊ���ͷɴ�ģ�ͣ�-4 -4Ϊ��˹�������ǹģ�ͣ���"); 
			scanf("%d %d",&a,&b);
			while(a<=-5||b<=-5||a>=WIDTH||b>=LENGTH||a%1!=0||b%1!=0){
				fflush(stdin);
				printf("�������ֵ�������������룺");
				scanf("%d %d",&a,&b);
			} 
			if(a==-4&&b==-4){
				my_Gospersglidergun(map);
				goto out1;
			}
			if(a==-2&&b==-2){
				my_Huaxiangji(map);
				goto out1;
			}
			if(a==-3&&b==-3){
				my_Ship(map);
				goto out1;
			}
			if(a!=-1&&b!=-1){
				map[a][b]=1;
			}
		}//Ϊ��a,b����������
		out1 :
		system("cls");
		while(total!=0){
			total=0;
			for(width=0;width<WIDTH;width++){
				for(length=0;length<LENGTH;length++){
					total+=map[width][length];
				}
			}//���㵱ǰ������������total
			printf("��ǰ��������������%d��",total);
			my_Printmap(map,WIDTH,LENGTH,skin);//��ӡ���� 
			my_Mapcalculate(map,WIDTH,LENGTH);//������һ�غ�������� 
			Sleep(100);
			turn++;
			if(turn==50){
				Sleep(1000);
				printf("��������Ҫ����һ�ֿ�ζ����0=���ˣ��һ��뿴���仯��1=�����ˣ���Ҫ�ɱ�ģ���");
				scanf("%d",&turn1);
				while(turn1!=1&&turn1!=0){
					fflush(stdin);
					printf("�������ֵ�������������룺");
					scanf("%d",&turn1);
				}
				turn=0;
				if(turn1==1){
					system("cls");
					goto outgame;
				}
			}
			system("cls");
			 
		}
		
	}
	
/****************************************************************
*  mod=1Ϊ��������ģʽ                                          *
*  �������£�                                                   *
*  �û�����������                                             *
*  ����û�������ĸ�����Χ�������������غϽ���ʱ�ø��ӻ������   *
*  �����������ĸ�����Χ�������������غϽ���ʱ�ø��ӱ�ס����     *
*****************************************************************/

	if(mod==1){
		int numbertotal=0;
		int timetotal=0;
		printf("�ڼ��������£�����û�������ĸ�����Χ�������������ܵ����������������ĸ�����Χ�������������ܱ�����������ÿ�غ��ݱ���û����ܹ������һ������,��ʼ�������������\n");
		for(count=0;count<5;count++){
			printf("������������������ĸ��ӣ�������ͼΪ40*40��(���뷽ʽ�������� ������)��"); 
			scanf("%d %d",&a,&b);
			while(a<=-1||b<=-1||a>=WIDTH||b>=LENGTH||a%1!=0||b%1!=0){
				fflush(stdin);
				printf("�������ֵ�������������룺");
				scanf("%d %d",&a,&b);	
			}
			map[a][b]=1;
		}//��������������������Ϊ5
		
		my_Printmap(map,WIDTH,LENGTH,skin);
		for(width=0;width<WIDTH;width++){
			for(length=0;length<LENGTH;length++){
				numbertotal+=map[width][length];
			}
		}//������������ 
		
		while(numbertotal!=0){
			my_Mapcalculate_living(map,WIDTH,LENGTH);//������һ�غ�������� 
			my_Printmap(map,WIDTH,LENGTH,skin);//��ӡ���� 
			for(width=0;width<WIDTH;width++){
				for(length=0;length<LENGTH;length++){
					if(map[width][length]==1){
						printf("��ǰ��������ڵ�%d��%d��\n",width,length);
					}
				}
			}
			numbertotal=0;
			for(width=0;width<WIDTH;width++){
				for(length=0;length<LENGTH;length++){
					numbertotal+=map[width][length];
				}
			}	
			timetotal++;
			if(numbertotal==0){
				goto outone;
			} 
			printf("�������%d�����ʱ��%d�غ�\n",numbertotal,timetotal);
			printf("��������ӵ��������꣺"); 
			scanf("%d %d",&a,&b);
			while(a<=-1||b<=-1||a>=WIDTH||b>=LENGTH||a%1!=0||b%1!=0){
				fflush(stdin);
				printf("�������ֵ�������������룺");
				scanf("%d %d",&a,&b);	
			}
			map[a][b]=1;
			my_Printmap(map,WIDTH,LENGTH,skin);
			Sleep(1000);  
		}
		
		outone ://����ȫ���������غϽ��� 
		printf("\n��һ�������%d���غ�\n",timetotal);
		printf("�Ƿ�Ҫ��������ݼ�¼����0=����¼��1=��¼����");
		scanf("%d",&judge);
		if(firstgame==0){
			InitList(L);//��ʼ�������� 
		}
		if(firstgame==0){
			L=(LNode*)malloc(sizeof(LNode));//���䶯̬�洢�ռ� 
		}	
		 
		if(judge==1){
			if(firstgame==0){
				my_Strangelink(L);
			}	 
			if(firstgame!=0){
				for(k=0;k<20;k++){
					yourdata.name[k]='\0';
				}
				k=0;
			}
			yourdata.time=timetotal;
			
			printf("���������������in English����");
			getchar();
			while((yourdata.name[k]=getchar())!='\n'){
				k++;
			}
			while(yourdata.name[0]=='\n'){
				printf("������־���һ�����з����ǿ�̫��ϧ��\n");
				printf("���ٴ��������������in English����");
				k=0;
				fflush(stdin);
				while((yourdata.name[k]=getchar())!='\n'){
					k++;
				}
			}
			while(k>19){
				printf("�������̫���������һ��\n");
				printf("���ٴ��������������in English����");
				k=0;
				fflush(stdin);
				while((yourdata.name[k]=getchar())!='\n'){
					k++;
				}
			}
			yourdata.name[k]='\0';
			yourdata.time=timetotal;
			ListINsert(L,circle+3,&yourdata);//���������������ݣ���circle+3 
		} //�����û��������� 
		
		for(datacount=1;datacount<=circle+4;datacount++){
			printf("data%d:\n",datacount);
			my_ListResearch(L,datacount);
		}
		
		outlink:
		printf("���Ƿ�Ҫ�����е�������һЩа������飿\n");
		printf("(0=���ˣ�����һ����ֱ����)\n") ;
		printf("(1=��������ǵ�����ɾ��)\n");
		printf("(2=��������ݸ���)\n");
		printf("(3=�����Լ���һ������)\n");
		printf("(4=����ѳɼ�������)��"); 
		scanf("%d",&linkchange);
		while(linkchange!=0&&linkchange!=1&&linkchange!=2&&linkchange!=3&&linkchange!=4){
				fflush(stdin);
				printf("�������ֵ�������������룺");
				scanf("%d",&linkchange);	
		}
		switch(linkchange){
			case 1:
				printf("�ðɺðɣ���Ȼ�е���֣�������ɾ��˭�����ݣ�(����������ݵ����)��");
				scanf("%d",&i);
				while(i<=0||i>circle+4||i%1!=0){
					fflush(stdin);//������뻺������ȷ����Ӱ���������ݶ�ȡ 
					printf("��������ȷ��ֵ��");
					scanf("%d",&i); 
				}
				
				if(i!=1){
					ListDelete(L,i-1);
				}
				
				if(i==1){
					L=L->next;
				}//��Ҫɾ����һ�����ݣ�ֱ����������һ�� 
				
				circle--;//��������-1 
				for(datacount=1;datacount<=circle+4;datacount++){
					printf("data%d:\n",datacount);
					my_ListResearch(L,datacount);
				}
				printf("�ƣ���������û������"); 
				break;
			case 2:
				printf("��ô��������˭�������أ�(����������ݵ����)��"); 
				scanf("%d",&i);
				while(i<=0||i>circle+4||i%1!=0){
					fflush(stdin);
					printf("��������ȷ��ֵ��");
					scanf("%d",&i); 
				}
				my_ListChange(L,i);
				for(datacount=1;datacount<=circle+4;datacount++){
					printf("data%d:\n",datacount);
					my_ListResearch(L,datacount);
				}
				printf("�ƣ���������(�����������һ��)�����ˣ���"); 
				break;
			case 3:
				printf("��ô�������Լ���ٸ��غ��أ���");
				scanf("%d", &i);
				while(i<=0||i%1!=0){
					fflush(stdin);
					printf("��������ȷ��ֵ��");
					scanf("%d",&i); 
				} 
				k=0;
				data yourdata1;
				printf("���������������in English����");
				getchar();
				while((yourdata1.name[k]=getchar())!='\n'){
					k++;
				}
				while(yourdata1.name[0]=='\n'){
					printf("������־���һ�����з����ǿ�̫��ϧ��\n");
					printf("���ٴ��������������in English����");
					k=0;
					fflush(stdin);
				while((yourdata1.name[k]=getchar())!='\n'){
					k++;
				}
				}
				while(k>19){
					printf("�������̫���������һ��\n");
					printf("���ٴ��������������in English����");
					k=0;
					fflush(stdin);
					while((yourdata1.name[k]=getchar())!='\n'){
						k++;
					}
				} 
				yourdata1.name[k]='\0'; 
				circle++;
				yourdata1.time=i;
				ListINsert(L,circle+3,&yourdata1);
				for(datacount=1;datacount<=circle+4;datacount++){
					printf("data%d:\n",datacount);
					my_ListResearch(L,datacount);
				}
				printf("wow,���ֵĿ����\n");
				break;
			case 4:
				my_Bubbling(L,circle+2);
				for(datacount=1;datacount<=circle+4;datacount++){
					printf("data%d:\n",datacount);
					my_ListResearch(L,datacount);
				}
				break; 
		}
		printf("��ô�����������ٸ�������?(0=�����㣬��˵��������ֱ���ˣ�1=���㣬�����Ҹĸ�)��");
		scanf("%d",&repeatlinkchange);
		while(repeatlinkchange!=0&&repeatlinkchange!=1){
			fflush(stdin);
			printf("�������ֵ�������������룺");
			scanf("%d",&repeatlinkchange);	
		}
		if(repeatlinkchange==1){
			goto outlink;
		}
		circle++;
		if(firstgame==0){
			firstgame++;
		} 
	}
	if(mod==2){
		end();
	}
	system("cls");
	goto outgame;
	return 0;	
} 

/************************************************
*  my_Roundsum�������������������ӵ�λ�����    *
*  ��������Χ������������                       *
*************************************************/

int my_Roundsum(int map[WIDTH][LENGTH],int widaddress,int lenaddress){
	int sum;
	if (widaddress>0&&widaddress<WIDTH-1&&lenaddress>0&&lenaddress<LENGTH-1){
		sum=map[widaddress-1][lenaddress-1]+map[widaddress-1][lenaddress]+map[widaddress-1][lenaddress+1]
			+map[widaddress][lenaddress-1]+map[widaddress][lenaddress+1]+map[widaddress+1][lenaddress-1]
			+map[widaddress+1][lenaddress]+map[widaddress+1][lenaddress+1];
	}else if(widaddress==0&&lenaddress==0){
		sum=map[widaddress][lenaddress+1]+map[widaddress+1][lenaddress]+map[widaddress+1][lenaddress+1];
	}else if(widaddress==0&&lenaddress==LENGTH-1){
		sum=map[widaddress][lenaddress-1]+map[widaddress+1][lenaddress]+map[widaddress+1][lenaddress-1];
	}else if(widaddress==0&&lenaddress!=LENGTH-1&&lenaddress!=0){
		sum=map[widaddress][lenaddress-1]+map[widaddress][lenaddress+1]+map[widaddress+1][lenaddress-1]
			+map[widaddress+1][lenaddress]+map[widaddress+1][lenaddress+1];
	}else if(widaddress==WIDTH-1&&lenaddress==0){
		sum=map[widaddress-1][lenaddress]+map[widaddress-1][lenaddress+1]+map[widaddress][lenaddress+1];
	}else if(widaddress==WIDTH-1&&lenaddress==LENGTH-1){
		sum=map[widaddress-1][lenaddress-1]+map[widaddress-1][lenaddress]+map[widaddress][lenaddress-1];
	}else if(widaddress==WIDTH-1&&lenaddress!=LENGTH-1&&lenaddress!=0){
		sum=map[widaddress-1][lenaddress-1]+map[widaddress-1][lenaddress]+map[widaddress-1][lenaddress+1]
			+map[widaddress][lenaddress-1]+map[widaddress][lenaddress+1];
	}else if(widaddress!=0&&widaddress!=WIDTH-1&&lenaddress==0){
		sum=map[widaddress-1][lenaddress]+map[widaddress-1][lenaddress+1]+map[widaddress][lenaddress+1]
			+map[widaddress+1][lenaddress]+map[widaddress+1][lenaddress+1];
	}else if(widaddress!=0&&widaddress!=WIDTH-1&&lenaddress==LENGTH-1){
		sum=map[widaddress-1][lenaddress-1]+map[widaddress-1][lenaddress]+map[widaddress][lenaddress-1]
			+map[widaddress+1][lenaddress-1]+map[widaddress+1][lenaddress];
	}
	return sum;
}

/**************************************
*  my_Printmap������ӡһ�غ��ڵ�����  * 
***************************************/

void my_Printmap(int map[WIDTH][LENGTH],int width,int length,int skin){
	int wid,len;
	for(wid=0;wid<width;wid++){
		for(len=0;len<length;len++){
			if(map[wid][len]==1){
				if(skin==0){
					printf("��");
				}else if(skin==1){
					printf("��");
				}else if(skin==2){
					printf("��");
				}else if(skin==3){
					printf("��");
				}
			}else{
				printf("  ");
			}
			if(len==length-1){
				printf("\n");
			}
		}
	}
}

/***********************************
*  my_Mapcalculate��������map����  *
*  ʹ������Ϊ��һ�غϵ��������    * 
*  ������ģʽ��                    *
************************************/

void my_Mapcalculate(int map[WIDTH][LENGTH],int width,int length){
	int wid,len;
	int cpymap[WIDTH][LENGTH];
	for(wid=0;wid<width;wid++){
		for(len=0;len<length;len++){
			if(map[wid][len]==1&&my_Roundsum(map,wid,len)==2){
				cpymap[wid][len]=1;
			}else if(map[wid][len]==1&&my_Roundsum(map,wid,len)==3){
				cpymap[wid][len]=1;
			}else if(map[wid][len]==0&&my_Roundsum(map,wid,len)==3){
				cpymap[wid][len]=1;
			}else{
				cpymap[wid][len]=0;
			}
		}
	}
	for(wid=0;wid<width;wid++){
		for(len=0;len<length;len++){
			map[wid][len]=cpymap[wid][len];
		}
	}
}

/*******************************************
*  my_Mapcalculate_living��������map����   *
*  ʹ������Ϊ��һ�غϵ��������            * 
********************************************/

void my_Mapcalculate_living(int map[WIDTH][LENGTH],int width,int length){
	int wid,len;
	int cpymap[WIDTH][LENGTH];
	for(wid=0;wid<width;wid++){
		for(len=0;len<length;len++){
			if(map[wid][len]==1&&my_Roundsum(map,wid,len)==3){
				cpymap[wid][len]=1;
			}else if(map[wid][len]==0&&my_Roundsum(map,wid,len)==3){
				cpymap[wid][len]=1;
			}else{
				cpymap[wid][len]=0;
			}
		}
	}
	for(wid=0;wid<width;wid++){
		for(len=0;len<length;len++){
			map[wid][len]=cpymap[wid][len];
		}
	}
}

void my_Huaxiangji(int map[WIDTH][LENGTH]){
	int width,length;
	for(width=0;width<WIDTH;width++){
		for(length=0;length<LENGTH;length++){
			map[width][length]=0;
		}
	}
	map[WIDTH/2][LENGTH/2]=1;
	map[WIDTH/2+1][LENGTH/2+1]=1;
	map[WIDTH/2+1][LENGTH/2+2]=1;
	map[WIDTH/2+2][LENGTH/2]=1;
	map[WIDTH/2+2][LENGTH/2+1]=1;
}

void my_Ship(int map[WIDTH][LENGTH]){
	int width,length;
	for(width=0;width<WIDTH;width++){
		for(length=0;length<LENGTH;length++){
			map[width][length]=0;
		}
	}
	map[WIDTH/4+1][LENGTH/4]=1;
	map[WIDTH/4][LENGTH/4+1]=1;
	map[WIDTH/4][LENGTH/4+2]=1;
	map[WIDTH/4][LENGTH/4+3]=1;
	map[WIDTH/4][LENGTH/4+4]=1;
	map[WIDTH/4+1][LENGTH/4+4]=1;
	map[WIDTH/4+2][LENGTH/4+4]=1;
	map[WIDTH/4+3][LENGTH/4+3]=1;
	map[WIDTH/4+3][LENGTH/4]=1;
}

void my_Gospersglidergun(int map[WIDTH][LENGTH]){
	int width,length;
	for(width=0;width<WIDTH;width++){
		for(length=0;length<LENGTH;length++){
			map[width][length]=0;
		}
	}
	map[6][LENGTH-1]=1;
	map[7][LENGTH-1]=1;
	map[6][LENGTH-2]=1;
	map[7][LENGTH-2]=1;
	map[6][LENGTH-10]=1;
	map[6][LENGTH-11]=1;
	map[5][LENGTH-11]=1; 
	map[7][LENGTH-11]=1;
	map[4][LENGTH-12]=1; 
	map[5][LENGTH-12]=1;
	map[6][LENGTH-12]=1;
	map[7][LENGTH-12]=1;
	map[8][LENGTH-12]=1;
	map[3][LENGTH-13]=1;
	map[4][LENGTH-13]=1;
	map[8][LENGTH-13]=1;
	map[9][LENGTH-13]=1;
	map[5][LENGTH-17]=1;
	map[6][LENGTH-17]=1;
	map[7][LENGTH-17]=1;
	map[5][LENGTH-18]=1;
	map[6][LENGTH-18]=1;
	map[7][LENGTH-18]=1;
	map[4][LENGTH-20]=1;
	map[3][LENGTH-21]=1;
	map[5][LENGTH-21]=1;
	map[2][LENGTH-22]=1;
	map[6][LENGTH-22]=1;
	map[3][LENGTH-23]=1;
	map[4][LENGTH-23]=1;
	map[5][LENGTH-23]=1;
	map[1][LENGTH-24]=1; 
	map[2][LENGTH-24]=1; 
	map[6][LENGTH-24]=1; 
	map[7][LENGTH-24]=1; 
	map[4][LENGTH-35]=1;
	map[5][LENGTH-35]=1;
	map[4][LENGTH-36]=1;
	map[5][LENGTH-36]=1;
}


