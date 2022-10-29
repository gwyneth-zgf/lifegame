void myprinter(char a[]){
	int i;
	for(i=0;a[i]!='\0';i++){
		printf("%c",a[i]);
		Sleep(60);
		
	}
	printf("\n");
	Sleep(15);
	printf("\n");
	Sleep(15);
	printf("\n");
	Sleep(15);
	printf("\n");
	Sleep(15);
	printf("\n");
	Sleep(150);
	printf("\n");
	Sleep(15);
}
void information(int a){
	switch(a){
		case 1:printf("生命游戏是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。\n"
						"它最初于1970年10月在《科学美国人》杂志中马丁·葛登能的“数学游戏”专栏出现。\n");break;
		case 2:printf("生命游戏非常简单，它的一切进程仅需用包含黑块和白块的无限大方格棋盘实现\n");break;
		case 3:printf("在特定规则的约束下，每个块下一回合的“生”或“死”由周围8个方块的状态决定\n"
						"通过回合数的不断变化，方块呈现不同的千奇百怪图像\n"
						"通过观察，我们很容易发现一些有趣的周期性变化\n"
						"关于生命游戏的探索仍然在进行，不同的规则，不同的初始条件.......");break;
		case 4:printf("以白块为“生”，黑块为“死”，我来介绍它的规则\n");break;
		case 5:printf("Rule 1:生命害怕孤独\n如果一个生命（白色方块）周围的生命少于两个，它就在回合结束时死亡（变为黑色）\n");
				printf("________                         ________ 	 \n");
				printf("|    █|                         |    █|	 \n");
				printf("|  █  |          -----------》  |      |	\n");
				printf("|      |                         |      |	\n");
				printf("￣￣￣￣                         ￣￣￣￣    \n");
				printf("\n\n\t注：仅针对正中间的格子\n");
				break;
		case 6:printf("Rule 2:生命讨厌拥挤\n如果一个生命周围的生命超过3个，他就在回合结束时死亡\n");
				printf("________                         ________ 	 \n");
				printf("|███|                         |███|	 \n");
				printf("|███|          -----------》  |█  █|	\n");
				printf("|███|                         |███|	\n");
				printf("￣￣￣￣                         ￣￣￣￣    \n");
				printf("\n\n\t注：仅针对正中间的格子\n");
				break;
		case 7:printf("Rule 3：如果一个死格子周围有3个生命，那么它在回合结束时获得生命\n");
				printf("________                         ________ 	 \n");
				printf("|█  █|                         |█  █|	 \n");
				printf("|    █|          -----------》  |  ██|	\n");
				printf("|    █|                         |    █|	\n");
				printf("￣￣￣￣                         ￣￣￣￣    \n");
				printf("\n\n\t注：仅针对正中间的格子\n");break;
		case 8:printf("Rule 4：如果一个生命周围有2个或3个生命，那么它就在回合结束时保持原样\n");
				printf("________                         ________ 	 \n");
				printf("|█  █|                         |█  █|	 \n");
				printf("|  █  |          -----------》  |  █  |	\n");
				printf("|    █|                         |    █|	\n");
				printf("￣￣￣￣                         ￣￣￣￣    \n");
				printf("\n\n\t注：仅针对正中间的格子\n");break;break;
		case 9:printf("这就是生命游戏最基础的四个规则，它能玩出什么花样呢？\n"
		"让我们开始吧！");break;
	}
	
}
void start(void)
{	
	int i,j,k;
	char cmd[40] = {0};
	printf("\n\n\t\t\t __*__*__*__*__*__*__*__*__*__");
	printf("\n\n\t\t\t||  Welcome to LIFE GAME!!!  ||");
	printf("\n\n\t\t\t||    欢迎来到生命游戏1.0    ||");
	printf("\n\n\t\t\t||    回车以查看游戏介绍     ||");
	printf("\n\n\t\t\t||PRESS ENTER FOR INFORMATION||");
	printf("\n\n\t\t\t __*__*__*__*__*__*__*__*__*__");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tPRODUCED BY Team8\n");
	while(getchar()=='\n')
		break;
	for(i = 0; i < 10; i++)
		{
				
		        system("cls");
		        sprintf(cmd, "color 0%d", i);
		        system(cmd);
		        printf("\t\t\tPRESS ENTER TO CONTINUE\n\n\n\n"); 
		        information (i);
		        if(getchar()=='\n'){
		        	continue;
				}
				
		        Sleep(100);		              
		}
	system("color 0a");
	system("cls");
	printf("\nNOW LOADING...\n") ;
	printf("PLEASE WAIT FOR A MOMENT...\n");
	for(j=1;j<30;j++){
		printf("》"); 
		Sleep(100-j*3);
		k=(j+10)%10;
		sprintf(cmd, "color 0%d", k);
		system(cmd);
	} 
	system("color 0f");
	system("cls");
	printf("\n一切就绪！开始吧！\n");
}

void end(void){
	int a=0;
	printf("Thanks for playing!!"); 
	printf("\n");
	Sleep(200);
	printf("\n");
	Sleep(200);
	printf("\n");
	Sleep(200);
	char producer00[100]="\t\t开发者介绍\n\t   Developer introduction";
	myprinter(producer00);
	printf("\n\n\n");
	
	char producer0[100]="\t\tTeam8 组长:\n\t\t   江文";
	myprinter(producer0); 

	char producer1[100]="\t\t首席架构师：\n\t    Chief Architector\n\t\t   江文";
	myprinter(producer1); 

	char producer2[100]="\t\t首席创意官:\n\t Chief Creative Officer\n\t\t  何松阳";
	myprinter(producer2); 

	char producer3[100]="\t\t程序编写：\n\t\tProducer\n\t  卞羽舟 何松阳 江文\n\t  商凯  曾桂芳 周泽平";
	myprinter(producer3); 

	char producer4[100]="\t\tDebug：\n\t\t 江文";
	myprinter(producer4); 

	char producer5[100]="\t\tPPT制作：\n\t    PPT Producer\n\t     商凯 周泽平";
	myprinter(producer5); 
	
	char producer6[100]="\t\t资料查找：\n\t Information Searcher\n\t      江文 何松阳 " ; 
	myprinter(producer6); 
	
	char producer7[100]="\t\t文档编写：\n\t      File Writer\n\t    曾桂芳 何松阳 " ; 
	myprinter(producer7);
	
	char producer8[100]="\t\t使用软件：\n\t\tProgram\n\t        Dev C++ " ; 
	myprinter(producer8);  
	
	char producer9[100]="\t\t灵感来源：\n\t        Aganippe\nhttps://www.bilibili.com/video/BV1zx41187v3" ; 
	myprinter(producer9);  
	
	char producer10[100]="\t\t拓展阅读：\n\t    More Information \nhttps://www.bilibili.com/read/cv5696735?from=search" ; 
	myprinter(producer10);
	
	
	while(a<25){
		printf("\n");
		Sleep(100); 
		a++;
	}
	printf("█████  █    █     █     █      █   █   █  █     █  ████ █    █\n");
	printf("    █      █    █   █  █   ██    █   █  █     █  █   █    █ █    █\n");
	printf("    █      ████  ████  █  █  █   ██         █     █    █ █    █\n");
	printf("    █      █    █  █    █  █    █     █  █       █     █    █ █    █\n");
	printf("    █      █    █  █    █  █      █   █    █     █     ████ ████\n");
	
	Sleep(5000);

}
