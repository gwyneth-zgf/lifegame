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
	}//首先令生命全部死亡
	
	printf("请选择生命样式(0=白格子，1=星星，2=三角形，3=圆形)：");
	scanf("%d",&skin);
	while(skin!=0&&skin!=1&&skin!=2&&skin!=3){
				fflush(stdin);
				printf("你输入的值有误请重新输入：");
				scanf("%d",&skin);
	}  
	printf("请选择模式(0=休闲，1=极限生存,2=制作人名单)：");
	scanf("%d",&mod);
	while(mod!=0&&mod!=1&&mod!=2){
				fflush(stdin);
				printf("你输入的值有误请重新输入：");
				scanf("%d",&mod);
	}
	
/*********************************************************
*  mod=0为休闲模式                                       *
*  规则如下：                                            *
*  输入生命后，                                          *
*  如果一个生命周围的生命少于2个，回合结束时死亡         *
*  如果一个生命周围的生命超过3个，回合结束时死亡         *
*  如果一个死格子周围有三个生命，回合结束时获得生命      *
*  如果一个生命周围有2或3个生命，回合结束时保持原样      *
**********************************************************/

	if(mod==0){
		while(a!=-1&&b!=-1){
			printf("请输入最初赋予生命的格子（本格子图为40*40）(输入方式：纵坐标 横坐标)(若输入：-1 -1则开始演算)\n"); 
			printf("（提供三个基本的模型，输入-2 -2则为滑翔机模型，-3 -3为轻型飞船模型，-4 -4为高斯帕滑翔机枪模型）："); 
			scanf("%d %d",&a,&b);
			while(a<=-5||b<=-5||a>=WIDTH||b>=LENGTH||a%1!=0||b%1!=0){
				fflush(stdin);
				printf("你输入的值有误请重新输入：");
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
		}//为（a,b）赋予生命
		out1 :
		system("cls");
		while(total!=0){
			total=0;
			for(width=0;width<WIDTH;width++){
				for(length=0;length<LENGTH;length++){
					total+=map[width][length];
				}
			}//计算当前存活的生命个数total
			printf("当前存活的生命个数：%d个",total);
			my_Printmap(map,WIDTH,LENGTH,skin);//打印生命 
			my_Mapcalculate(map,WIDTH,LENGTH);//计算下一回合生命情况 
			Sleep(100);
			turn++;
			if(turn==50){
				Sleep(1000);
				printf("看腻了吗，要不换一种口味？（0=不了，我还想看他变化，1=我腻了，我要干别的）：");
				scanf("%d",&turn1);
				while(turn1!=1&&turn1!=0){
					fflush(stdin);
					printf("你输入的值有误请重新输入：");
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
*  mod=1为极限生存模式                                          *
*  规则如下：                                                   *
*  用户输入生命后，                                             *
*  仅当没有生命的格子周围有三个生命，回合结束时该格子获得生命   *
*  仅当有生命的格子周围有三个生命，回合结束时该格子保住生命     *
*****************************************************************/

	if(mod==1){
		int numbertotal=0;
		int timetotal=0;
		printf("在极限生存下，仅有没有生命的格子周围有三个生命才能诞生生命，有生命的格子周围有三个生命才能保存生命，在每回合演变后，用户将能够再添加一条生命,初始将有五个生命。\n");
		for(count=0;count<5;count++){
			printf("请输入最初赋予生命的格子（本格子图为40*40）(输入方式：纵坐标 横坐标)："); 
			scanf("%d %d",&a,&b);
			while(a<=-1||b<=-1||a>=WIDTH||b>=LENGTH||a%1!=0||b%1!=0){
				fflush(stdin);
				printf("你输入的值有误请重新输入：");
				scanf("%d %d",&a,&b);	
			}
			map[a][b]=1;
		}//输入生命，生命上限数为5
		
		my_Printmap(map,WIDTH,LENGTH,skin);
		for(width=0;width<WIDTH;width++){
			for(length=0;length<LENGTH;length++){
				numbertotal+=map[width][length];
			}
		}//计算生命总数 
		
		while(numbertotal!=0){
			my_Mapcalculate_living(map,WIDTH,LENGTH);//计算下一回合生命情况 
			my_Printmap(map,WIDTH,LENGTH,skin);//打印生命 
			for(width=0;width<WIDTH;width++){
				for(length=0;length<LENGTH;length++){
					if(map[width][length]==1){
						printf("当前存活生命在第%d行%d列\n",width,length);
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
			printf("存活数量%d个存活时间%d回合\n",numbertotal,timetotal);
			printf("请输入添加的生命坐标："); 
			scanf("%d %d",&a,&b);
			while(a<=-1||b<=-1||a>=WIDTH||b>=LENGTH||a%1!=0||b%1!=0){
				fflush(stdin);
				printf("你输入的值有误请重新输入：");
				scanf("%d %d",&a,&b);	
			}
			map[a][b]=1;
			my_Printmap(map,WIDTH,LENGTH,skin);
			Sleep(1000);  
		}
		
		outone ://生命全部死亡，回合结束 
		printf("\n你一共存活了%d个回合\n",timetotal);
		printf("是否要将你的数据记录？（0=不记录，1=记录）：");
		scanf("%d",&judge);
		if(firstgame==0){
			InitList(L);//初始化空链表 
		}
		if(firstgame==0){
			L=(LNode*)malloc(sizeof(LNode));//分配动态存储空间 
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
			
			printf("请输入你的姓名（in English）：");
			getchar();
			while((yourdata.name[k]=getchar())!='\n'){
				k++;
			}
			while(yourdata.name[0]=='\n'){
				printf("你的名字就是一个换行符吗，那可太可惜了\n");
				printf("请再次输入你的姓名（in English）：");
				k=0;
				fflush(stdin);
				while((yourdata.name[k]=getchar())!='\n'){
					k++;
				}
			}
			while(k>19){
				printf("你的名字太长啦，请短一点\n");
				printf("请再次输入你的姓名（in English）：");
				k=0;
				fflush(stdin);
				while((yourdata.name[k]=getchar())!='\n'){
					k++;
				}
			}
			yourdata.name[k]='\0';
			yourdata.time=timetotal;
			ListINsert(L,circle+3,&yourdata);//由于已有三个数据，故circle+3 
		} //插入用户个人数据 
		
		for(datacount=1;datacount<=circle+4;datacount++){
			printf("data%d:\n",datacount);
			my_ListResearch(L,datacount);
		}
		
		outlink:
		printf("你是否要对已有的数据做一些邪恶的事情？\n");
		printf("(0=不了，我是一个正直的人)\n") ;
		printf("(1=我想把他们的数据删了)\n");
		printf("(2=我想把数据改了)\n");
		printf("(3=我想自己编一点数据)\n");
		printf("(4=我想把成绩排排序)："); 
		scanf("%d",&linkchange);
		while(linkchange!=0&&linkchange!=1&&linkchange!=2&&linkchange!=3&&linkchange!=4){
				fflush(stdin);
				printf("你输入的值有误请重新输入：");
				scanf("%d",&linkchange);	
		}
		switch(linkchange){
			case 1:
				printf("好吧好吧，虽然有点过分，但你想删掉谁的数据？(请输入该数据的序号)：");
				scanf("%d",&i);
				while(i<=0||i>circle+4||i%1!=0){
					fflush(stdin);//清空输入缓冲区，确保不影响后面的数据读取 
					printf("请输入正确的值：");
					scanf("%d",&i); 
				}
				
				if(i!=1){
					ListDelete(L,i-1);
				}
				
				if(i==1){
					L=L->next;
				}//若要删除第一个数据，直接整体向下一组 
				
				circle--;//数据总数-1 
				for(datacount=1;datacount<=circle+4;datacount++){
					printf("data%d:\n",datacount);
					my_ListResearch(L,datacount);
				}
				printf("瞧，他的数据没啦！！"); 
				break;
			case 2:
				printf("那么，你打算帮谁做个弊呢？(请输入该数据的序号)："); 
				scanf("%d",&i);
				while(i<=0||i>circle+4||i%1!=0){
					fflush(stdin);
					printf("请输入正确的值：");
					scanf("%d",&i); 
				}
				my_ListChange(L,i);
				for(datacount=1;datacount<=circle+4;datacount++){
					printf("data%d:\n",datacount);
					my_ListResearch(L,datacount);
				}
				printf("瞧，他的数据(大概是连名字一起)被改了！！"); 
				break;
			case 3:
				printf("那么，你想自己活几百个回合呢？：");
				scanf("%d", &i);
				while(i<=0||i%1!=0){
					fflush(stdin);
					printf("请输入正确的值：");
					scanf("%d",&i); 
				} 
				k=0;
				data yourdata1;
				printf("请输入你的姓名（in English）：");
				getchar();
				while((yourdata1.name[k]=getchar())!='\n'){
					k++;
				}
				while(yourdata1.name[0]=='\n'){
					printf("你的名字就是一个换行符吗，那可太可惜了\n");
					printf("请再次输入你的姓名（in English）：");
					k=0;
					fflush(stdin);
				while((yourdata1.name[k]=getchar())!='\n'){
					k++;
				}
				}
				while(k>19){
					printf("你的名字太长啦，请短一点\n");
					printf("请再次输入你的姓名（in English）：");
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
				printf("wow,你坚持的可真久\n");
				break;
			case 4:
				my_Bubbling(L,circle+2);
				for(datacount=1;datacount<=circle+4;datacount++){
					printf("data%d:\n",datacount);
					my_ListResearch(L,datacount);
				}
				break; 
		}
		printf("怎么样？还打算再改数据吗?(0=不打算，我说了我是正直的人，1=打算，再让我改改)：");
		scanf("%d",&repeatlinkchange);
		while(repeatlinkchange!=0&&repeatlinkchange!=1){
			fflush(stdin);
			printf("你输入的值有误请重新输入：");
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
*  my_Roundsum函数分类讨论生命格子的位置情况    *
*  并计算周围的生命格子数                       *
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
*  my_Printmap函数打印一回合内的生命  * 
***************************************/

void my_Printmap(int map[WIDTH][LENGTH],int width,int length,int skin){
	int wid,len;
	for(wid=0;wid<width;wid++){
		for(len=0;len<length;len++){
			if(map[wid][len]==1){
				if(skin==0){
					printf("█");
				}else if(skin==1){
					printf("★");
				}else if(skin==2){
					printf("▲");
				}else if(skin==3){
					printf("●");
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
*  my_Mapcalculate函数重置map数组  *
*  使其数据为下一回合的生命情况    * 
*  【休闲模式】                    *
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
*  my_Mapcalculate_living函数重置map数组   *
*  使其数据为下一回合的生命情况            * 
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


