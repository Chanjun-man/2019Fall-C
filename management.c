#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();

struct date{
    int month;
	int day;
	int year;
};

struct {
    char name[60];
    int acc_no;
	int age;
    char address[60];
    char phone[20];
    struct date dob;

}add,upd,check,rem;

void close(void)
{
    printf("\n\n\n\n�ڽ��� �� ���� �ۼ�");
}

void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
        k=i;
}

void new_acc()
{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t record�� ��� �߰� ");
    printf("\n���� ��ȣ �Է�:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.phone)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
				printf("������ �����ϴ� ���� ��ȣ �Դϴ�! �ٸ� ��ȣ�� �Է����ּ���");
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
    printf("\n�̸�:");
    scanf("%s",add.name);
    printf("\n����(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\n����:");
    scanf("%d",&add.age);
    printf("\n�ּ�:");
    scanf("%s",add.address);
    printf("\n��ȭ��ȣ: ");
    scanf("%s",add.phone);

    
	fprintf(ptr,"%d %s %d/%d/%d %d %s %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone);
    fclose(ptr);
    printf("\n������ ���������� �����Ǿ����ϴ�.");
    
	while(1){
		printf("\n\n���� �޴��� ������ 1, �����Ϸ��� 0�� �����ּ���:");
    	scanf("%d",&main_exit);
    	system("cls");
    	if((main_exit == 1) || (main_exit == 0))
    		break;
    	printf("\n0�� 1�� �ϳ��� �Է����ּ���!\a");
	}
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
}

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\t�̸�\t\t\t�ּ�\t\t\t��ȭ��ȣ\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.phone)!=EOF)
	{
       printf("\n%6d\t %10s\t\t\t%10s\t\t%s",add.acc_no,add.name,add.address,add.phone);
       test++;
	}
    fclose(view);
    
    if (test==0)
    {
		system("cls");
        printf("\n��ϵ� ������ �����ϴ�!\n");
	}

	while(1)
	{
		printf("\n\n���� �޴��� ������ 1, �����Ϸ��� 0�� �����ּ���:");
    	scanf("%d",&main_exit);
    	system("cls");
    	if((main_exit == 1) || (main_exit == 0))
    		break;
    	printf("\n0�� 1�� �ϳ��� �Է����ּ���!\a");
	}
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
}

void edit(void)
{
	return;
}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("���� ���� ���� ��ȣ�� �Է��ϼ���:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.phone)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone);

        else
        {
			test++;
            printf("\n���������� �����Ǿ����ϴ�!\n");
        }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
	{
        printf("\n�Է��Ͻ� ���� ��ȣ�� ���� �߰ߵ��� �ʾҽ��ϴ�!!\a\a\a");
        erase_invalid:
        printf("\n�ٽ� �õ��Ϸ��� 0, ���� �޴��� ������ 1, �����Ϸ��� �ٸ� Ű�� �����ּ���:");
        scanf("%d",&main_exit);
        if(main_exit==0)
            erase();
        else if (main_exit==1)
            menu();
        else
            close();
    }
    else
    {
		printf("\n���� �޴��� ������ 1, �����Ϸ��� �ٸ� Ű�� �����ּ���:");
	    scanf("%d",&main_exit);
	    system("cls");
	    if (main_exit==1)
	        menu();
	    else
	        close();
    }

}

void menu(void)
{
    int choice;
    system("cls");
    printf("\n\n\t\t\t ���� �ý���\n");
    printf("\n\n\t\t1. ���� �����ϱ�\n");
	printf("\t\t2. ���� ���� �����ϱ�\n");
	printf("\t\t3. ��ü ���� ��������\n");

	//���� �����غ��� 
	printf("\t\t4. ���� ���� ������Ʈ�ϱ�\n");

	//�߰��� �ڽŸ��� ��� 2�� �̻� ��� �����ϱ� 
	printf("\t\t5. ���� ������ ���\n");
	printf("\t\t6. ���� ������ ���\n");
	printf("\t\t7.����\n\n\n\n\n");
	printf("\t\t ����:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:
			new_acc();
	        break;
        case 2:
			erase();
        	break;
        case 3:
			view_list();
        	break;
	    case 4:
			edit();
	        break;
        case 5:
        	//�߰��� �Լ� 
        	break;
        case 6:
        	//�߰��� �Լ� 
        	break;
        case 7:
			close();
        	break;

    }



}
int main()
{
    char pass[10],password[10]="codewithc";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
    {
		printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    }
    else
    {
	    printf("\n\nWrong password!!\a\a\a");
        login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
        {
            system("cls");
            main();
        }

        else if (main_exit==0)
        {
            system("cls");
            close();
		}
        else
        {
			printf("\nInvalid!");
	        fordelay(1000000000);
	        system("cls");
	        goto login_try;
		}

    }
    return 0;
}

