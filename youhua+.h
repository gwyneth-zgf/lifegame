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
		case 1:printf("������Ϸ��Ӣ����ѧ��Լ�����ζ١�������1970�귢����ϸ���Զ�����\n"
						"�������1970��10���ڡ���ѧ�����ˡ���־����������ܵġ���ѧ��Ϸ��ר�����֡�\n");break;
		case 2:printf("������Ϸ�ǳ��򵥣�����һ�н��̽����ð����ڿ�Ͱ׿�����޴󷽸�����ʵ��\n");break;
		case 3:printf("���ض������Լ���£�ÿ������һ�غϵġ���������������Χ8�������״̬����\n"
						"ͨ���غ����Ĳ��ϱ仯��������ֲ�ͬ��ǧ��ٹ�ͼ��\n"
						"ͨ���۲죬���Ǻ����׷���һЩ��Ȥ�������Ա仯\n"
						"����������Ϸ��̽����Ȼ�ڽ��У���ͬ�Ĺ��򣬲�ͬ�ĳ�ʼ����.......");break;
		case 4:printf("�԰׿�Ϊ���������ڿ�Ϊ�������������������Ĺ���\n");break;
		case 5:printf("Rule 1:�������¹¶�\n���һ����������ɫ���飩��Χ���������������������ڻغϽ���ʱ��������Ϊ��ɫ��\n");
				printf("________                         ________ 	 \n");
				printf("|    ��|                         |    ��|	 \n");
				printf("|  ��  |          -----------��  |      |	\n");
				printf("|      |                         |      |	\n");
				printf("��������                         ��������    \n");
				printf("\n\n\tע����������м�ĸ���\n");
				break;
		case 6:printf("Rule 2:��������ӵ��\n���һ��������Χ����������3���������ڻغϽ���ʱ����\n");
				printf("________                         ________ 	 \n");
				printf("|������|                         |������|	 \n");
				printf("|������|          -----------��  |��  ��|	\n");
				printf("|������|                         |������|	\n");
				printf("��������                         ��������    \n");
				printf("\n\n\tע����������м�ĸ���\n");
				break;
		case 7:printf("Rule 3�����һ����������Χ��3����������ô���ڻغϽ���ʱ�������\n");
				printf("________                         ________ 	 \n");
				printf("|��  ��|                         |��  ��|	 \n");
				printf("|    ��|          -----------��  |  ����|	\n");
				printf("|    ��|                         |    ��|	\n");
				printf("��������                         ��������    \n");
				printf("\n\n\tע����������м�ĸ���\n");break;
		case 8:printf("Rule 4�����һ��������Χ��2����3����������ô�����ڻغϽ���ʱ����ԭ��\n");
				printf("________                         ________ 	 \n");
				printf("|��  ��|                         |��  ��|	 \n");
				printf("|  ��  |          -----------��  |  ��  |	\n");
				printf("|    ��|                         |    ��|	\n");
				printf("��������                         ��������    \n");
				printf("\n\n\tע����������м�ĸ���\n");break;break;
		case 9:printf("�����������Ϸ��������ĸ������������ʲô�����أ�\n"
		"�����ǿ�ʼ�ɣ�");break;
	}
	
}
void start(void)
{	
	int i,j,k;
	char cmd[40] = {0};
	printf("\n\n\t\t\t __*__*__*__*__*__*__*__*__*__");
	printf("\n\n\t\t\t||  Welcome to LIFE GAME!!!  ||");
	printf("\n\n\t\t\t||    ��ӭ����������Ϸ1.0    ||");
	printf("\n\n\t\t\t||    �س��Բ鿴��Ϸ����     ||");
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
		printf("��"); 
		Sleep(100-j*3);
		k=(j+10)%10;
		sprintf(cmd, "color 0%d", k);
		system(cmd);
	} 
	system("color 0f");
	system("cls");
	printf("\nһ�о�������ʼ�ɣ�\n");
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
	char producer00[100]="\t\t�����߽���\n\t   Developer introduction";
	myprinter(producer00);
	printf("\n\n\n");
	
	char producer0[100]="\t\tTeam8 �鳤:\n\t\t   ����";
	myprinter(producer0); 

	char producer1[100]="\t\t��ϯ�ܹ�ʦ��\n\t    Chief Architector\n\t\t   ����";
	myprinter(producer1); 

	char producer2[100]="\t\t��ϯ�����:\n\t Chief Creative Officer\n\t\t  ������";
	myprinter(producer2); 

	char producer3[100]="\t\t�����д��\n\t\tProducer\n\t  ������ ������ ����\n\t  �̿�  ���� ����ƽ";
	myprinter(producer3); 

	char producer4[100]="\t\tDebug��\n\t\t ����";
	myprinter(producer4); 

	char producer5[100]="\t\tPPT������\n\t    PPT Producer\n\t     �̿� ����ƽ";
	myprinter(producer5); 
	
	char producer6[100]="\t\t���ϲ��ң�\n\t Information Searcher\n\t      ���� ������ " ; 
	myprinter(producer6); 
	
	char producer7[100]="\t\t�ĵ���д��\n\t      File Writer\n\t    ���� ������ " ; 
	myprinter(producer7);
	
	char producer8[100]="\t\tʹ�������\n\t\tProgram\n\t        Dev C++ " ; 
	myprinter(producer8);  
	
	char producer9[100]="\t\t�����Դ��\n\t        Aganippe\nhttps://www.bilibili.com/video/BV1zx41187v3" ; 
	myprinter(producer9);  
	
	char producer10[100]="\t\t��չ�Ķ���\n\t    More Information \nhttps://www.bilibili.com/read/cv5696735?from=search" ; 
	myprinter(producer10);
	
	
	while(a<25){
		printf("\n");
		Sleep(100); 
		a++;
	}
	printf("����������  ��    ��     ��     ��      ��   ��   ��  ��     ��  �������� ��    ��\n");
	printf("    ��      ��    ��   ��  ��   ����    ��   ��  ��     ��  ��   ��    �� ��    ��\n");
	printf("    ��      ��������  ��������  ��  ��  ��   ����         ��     ��    �� ��    ��\n");
	printf("    ��      ��    ��  ��    ��  ��    ��     ��  ��       ��     ��    �� ��    ��\n");
	printf("    ��      ��    ��  ��    ��  ��      ��   ��    ��     ��     �������� ��������\n");
	
	Sleep(5000);

}
