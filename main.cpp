#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include <stdbool.h>
#include <malloc.h>
#define NUMEL 25
//至少4个txt——用户、管理员、订单、航班
struct USER
{
    char ID[20];
    char name[21];
    char sex[7];
    char phone[20];
    char password[20];
    char mail[41];
}
;

struct ADMIN
{
    char ID[20];
    char comp[10];
    char name[10];
    char mail[20];
    char password[20];
    int line;
}
;

struct FLIGHT//用于临时储存航班信息
{
    char num[20];
    char comp[20];
    char departure[10];
    char destination[10];
    char offtime[10];
    char flytime[10];
    char num1[10];//头等舱
    char level1[20];//头等舱
    char num2[10];//经济舱
    char level2[20];//经济舱
    char total1[10];//头等舱
    char total2[10];//经济舱
    int remain1;//头等舱
    int remain2;//经济舱
    char price1[10];//头等舱
    char price2[10];//经济舱
    char type[20];
    char punctuality[10];
    char pilot1[20];
    char pilot2[20];

}
;
struct ORDER
{
    char ID[20];
    char person[20];
    char num[10];
    char comp[10];
    char departure[10];
    char destination[10];
    int date;
    char purchasedate[10];
    char offtime[10];
    char flytime[10];
    char level[10];
    char seat[10];
    char type[20];
    int bought;
    int price;
    int buydate;
    char pricec[20];


};
;

char loginID[20];
char adminID[20];
char searchdate[10];
void register1();
void information1();
void checkflight();
void checkorder1();
int pay();
void buy();

void register2(struct ADMIN *registered);//管理员注册
int login2(struct ADMIN *logged);//管理员登录
void checkorder2(struct ADMIN *logged);//管理员查看订单
void manageflight(struct ADMIN *logged);//管理员管理航班
void information2(struct ADMIN *logged);//管理员个人信息管理

void buy();
int Senter1();
int Senter2();
int Senter3();
int login1();//成功返回1，不成功返回0
int main()
{
    typedef struct USER User;
    User tmp,* curUPtr;

    char enter1[5],enter2[5],enter3[5],enter4[5],enter5[5],enter[5];
    int tmp1,tmp2,tmp3,tmp4,m,i,e;
    char userorder[25];
    printf("Please select your entry:\n(Enter 0 for administrators, 1 for users. Enter 2 to exit.)\n");
    gets(enter);
    while(enter[0]<'0'||enter[0]>'2'||enter[1]!='\0')
    {
        printf("\nYour selection is not identified. Please try again.\n");
        printf("Please select your entry:\n(Enter 0 for administrators, 1 for users. Enter 2 to exit.)\n");
        fflush(stdin);
        gets(enter);
    }
    e=atoi(enter);
    while (e!=2)
    {

        switch(e)
        {
            case 1://用户
            {
                printf("What would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");

                scanf("%4s",enter2);
                fflush(stdin);
                while(enter2[0]<'1'||enter2[0]>'3'||enter2[1]!='\0')
                {
                    printf("Error.Please input again.\n");
                    scanf("%4s",enter2);
                    fflush(stdin);
                }
                //添加纯数字验证
                tmp2=atoi(enter2);
                while (tmp2!=3)
                {
                    switch(tmp2)
                    {
                        case 1://注册
                        {

                            register1();
                            printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");

                            scanf("%4s",enter3);
                            fflush(stdin);
                            while(enter3[0]<'1'||enter3[0]>'3'||enter3[1]!='\0')
                            {
                                printf("Error.Please input again.\n");
                                scanf("%4s",enter3);
                                fflush(stdin);
                            }
                            tmp2=atoi(enter3);
                            break;
                            //添加纯数字验证
                        }
                        case 2://登录
                        {


                            if((login1())==0)//即用户错误，选择退出，返回上一级循环
                            {
                                printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");

                                scanf("%4s",enter3);
                                fflush(stdin);
                                while(enter3[0]<'1'||enter3[0]>'3'||enter3[1]!='\0')
                                {
                                    printf("Error.Please input again.\n");
                                    scanf("%4s",enter3);
                                    fflush(stdin);
                                }
                                tmp2=atoi(enter3);
                                //添加纯数字验证
                                break;
                            }
                            else//用户登录成功
                            {
                                printf("\nWhat would you like to do?\n"
                                               "Enter 1 to check available flights\n"
                                               "      2 to manage your personal information\n"
                                               "      3 to check your orders\n"
                                               "      4 to cancel order which have not been purchased\n"
                                               "      5 to return)\n");

                                scanf("%4s",enter4);
                                fflush(stdin);
                                while(enter4[0]<'1'||enter4[0]>'3'||enter4[1]!='\0')
                                {
                                    printf("Error.Please input again.\n");
                                    scanf("%4s",enter4);
                                    fflush(stdin);
                                }
                                tmp3=atoi(enter4);
                                //添加纯数字验证；
                                while(tmp3!=5)
                                {
                                    switch(tmp3)
                                    {
                                        case 1://航班查询
                                        {

                                            checkflight();
                                            //ps:可用的函数声明语句
                                            //int index();//switch接收返回值，case12接index12
                                            //void index1();//index12内部需要排序机制
                                            //void index2();//无论是index1还是2，在这之后的过滤机制都应该是一样的 ——过滤需要临时过滤对象（容器），是否要将index后的结果储存在一个“可复写”txt中？ 【每次添加过滤条件需修改txt，一旦返回，直接返回index前】
                                            //void index3();//热门航班推荐……
                                            //void filtrate(int);
                                            //void buy();//过滤后直接调用函数——包含保存订单—>模拟付款/取消订单(直接检索并删除之前保存的内容)/返回（至choice()）——在订单后添加(paid/unpaid)作关键字
                                            //制作航班信息时，控制单条信息字节数一定，不足的字符位用空格顶上 ——用于信息编号
                                            //void pay();//模拟付款
                                            //void information1();//用于——个人信息管理
                                            //void query();//查询订单——包含paid和unpaid，注意格式
                                            printf("\nWhat would you like to do?\n"
                                                           "Enter 1 to check available flights\n"
                                                           "      2 to manage your personal information\n"
                                                           "      3 to check your orders\n"
                                                           "      4 to cancel order which have not been purchased\n"
                                                           "      5 to return\n");

                                            scanf("%4s",enter4);
                                            fflush(stdin);
                                            while(enter4[0]<'1'||enter4[0]>'3'||enter4[1]!='\0')
                                            {
                                                printf("Error.Please input again.\n");
                                                scanf("%4s",enter4);
                                                fflush(stdin);
                                            }
                                            tmp3=atoi(enter4);
                                            //添加纯数字验证
                                            break;
                                        }
                                        case 2://个人信息管理
                                        {

                                            information1();//列举出信息，用户选择性修改。包括返回选项
                                            printf("\nWhat would you like to do?\n"
                                                           "Enter 1 to check available flights\n"
                                                           "      2 to manage your personal information\n"
                                                           "      3 to check your orders\n"
                                                           "      4 to cancel order which have not been purchased\n"
                                                           "      5 to return)\n");

                                            scanf("%4s",enter4);
                                            fflush(stdin);
                                            while(enter4[0]<'1'||enter4[0]>'3'||enter4[1]!='\0')
                                            {
                                                printf("Error.Please input again.\n");
                                                scanf("%4s",enter4);
                                                fflush(stdin);
                                            }
                                            tmp3=atoi(enter4);
                                            //添加纯数字验证
                                            break;
                                        }
                                        case 3://查询用户订单
                                        {

                                            checkorder1();
                                            printf("\nWhat would you like to do?\n"
                                                           "Enter 1 to check available flights\n"
                                                           "      2 to manage your personal information\n"
                                                           "      3 to check your orders\n"
                                                           "      4 to cancel order which have not been purchased\n"
                                                           "      5 to return)\n");

                                            scanf("%4s",enter4);
                                            fflush(stdin);
                                            while(enter4[0]<'1'||enter4[0]>'3'||enter4[1]!='\0')
                                            {
                                                printf("Error.Please input again.\n");
                                                scanf("%4s",enter4);
                                                fflush(stdin);
                                            }
                                            tmp3=atoi(enter4);
                                            //添加纯数字验证
                                            break;
                                        }
                                        case 4://取消未付款订单
                                        {
                                            strcpy(userorder,loginID);
                                            strcat(userorder,".txt");
                                            remove(userorder);
                                            break;
                                        }
                                        default://用户输入错误（除1234以外的数）
                                        {
                                            printf("\nYour selection is not identified. Please try again.\n");
                                            printf("\nWhat would you like to do?\n"
                                                           "Enter 1 to check available flights\n"
                                                           "      2 to manage your personal information\n"
                                                           "      3 to check your orders\n"
                                                           "      4 to cancel order which have not been purchased\n"
                                                           "      5 to return\n");

                                            scanf("%4s",enter4);
                                            fflush(stdin);
                                            while(enter4[0]<'1'||enter4[0]>'3'||enter4[1]!='\0')
                                            {
                                                printf("Error.Please input again.\n");
                                                scanf("%4s",enter4);
                                                fflush(stdin);
                                            }
                                            tmp3=atoi(enter4);
                                            //添加纯数字雅正
                                            break;
                                        }
                                    }
                                }
                                printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                                gets(enter2);
                                m=atoi(enter2);
                                //添加纯数字验证
                                break;
                            }

                        }
                        default://用户输入错误（除123以外的数）
                        {
                            printf("\nYour selection is not identified. Please try again.\n");
                            printf("What would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                            gets(enter2);
                            m=atoi(enter2);
                            //添加纯数字验证
                            break;
                        }
                    }
                }
                printf("\nPlease select your entry:\n(Enter 0 for administrators, 1 for users. Enter 2 to exit.)\n");//选择3
                gets(enter1);
                i=atoi(enter1);
                //添加纯数字验证
                break;
            }

            case 0://管理员
            {
                printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                gets(enter);
                while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                {
                    printf("Your selection is not identified. Please try again.\n");
                    printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                    fflush(stdin);
                    gets(enter);
                }
                e=atoi(enter);
                while(e!=3)
                {
                    switch(e)
                    {
                        case 1://注册(与用户注册流程相同，保存在不同txt）
                        {
                            struct ADMIN registered;
                            void register2(struct ADMIN *);
                            register2(&registered);//register2函数要将信息都保存在txt中
                            printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                            gets(enter);
                            while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                            {
                                printf("Your selection is not identified. Please try again.\n");
                                printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                                fflush(stdin);
                                gets(enter);
                            }
                            e=atoi(enter);
                            break;
                        }
                        case 2://登录（与用户登录流程相同）
                        {
                            int b;
                            struct ADMIN logged;
                            int login2(struct ADMIN *); //login2中需要对logged结构进行赋值——包括ID，公司，从而进行验证
                            b=login2(&logged);
                            if(b==0)
                            {
                                printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                                gets(enter);
                                while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                {
                                    printf("\nYour selection is not identified. Please try again.\n");
                                    printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                                    fflush(stdin);
                                    gets(enter);
                                }
                                e=atoi(enter);
                                break;
                            }
                            else
                            {
                                printf("\nWhat would you like to do?\n(Enter 1 to manage present orders, 2 to manage flights, 3 to manage your personal information, 4 to return)\n");
                                gets(enter);
                                while(enter[0]<'1'||enter[0]>'4'||enter[1]!='\0'||enter[0]=='\0')
                                {
                                    printf("\nYour selection is not identified. Please try again.\n");
                                    printf("What would you like to do?\n(Enter 1 to manage present orders, 2 to manage flights, 3 to manage your personal information, 4 to return)\n");
                                    fflush(stdin);
                                    gets(enter);
                                }
                                e=atoi(enter);
                                while(e!=4)
                                {
                                    switch(e)
                                    {
                                        case 1:
                                        {
                                            void checkorder2(struct ADMIN *);//订单管理
                                            checkorder2(&logged);
                                            printf("\nWhat would you like to do?\n(Enter 1 to manage present orders, 2 to manage flights, 3 to manage your personal information, 4 to return)\n");
                                            gets(enter);
                                            while(enter[0]<'1'||enter[0]>'4'||enter[1]!='\0'||enter[0]=='\0')
                                            {
                                                printf("\nYour selection is not identified. Please try again.\n");
                                                printf("What would you like to do?\n(Enter 1 to manage present orders, 2 to manage flights, 3 to manage your personal information, 4 to return)\n");
                                                fflush(stdin);
                                                gets(enter);
                                            }
                                            e=atoi(enter);
                                            break;
                                        }
                                        case 2:
                                        {
                                            void manageflight(struct ADMIN *);//航班管理
                                            manageflight(&logged);
                                            printf("\nWhat would you like to do?\n(Enter 1 to manage present orders, 2 to manage flights, 3 to manage your personal information, 4 to return)\n");
                                            gets(enter);
                                            while(enter[0]<'1'||enter[0]>'4'||enter[1]!='\0'||enter[0]=='\0')
                                            {
                                                printf("\nYour selection is not identified. Please try again.\n");
                                                printf("What would you like to do?\n(Enter 1 to manage present orders, 2 to manage flights, 3 to manage your personal information, 4 to return)\n");
                                                fflush(stdin);
                                                gets(enter);
                                            }
                                            e=atoi(enter);
                                            break;
                                        }
                                        case 3:
                                        {
                                            void information2(struct ADMIN *);//个人信息管理
                                            information2(&logged);
                                            printf("\nWhat would you like to do?\n(Enter 1 to manage present orders, 2 to manage flights, 3 to manage your personal information, 4 to return)\n");
                                            gets(enter);
                                            while(enter[0]<'1'||enter[0]>'4'||enter[1]!='\0'||enter[0]=='\0')
                                            {
                                                printf("\nYour selection is not identified. Please try again.\n");
                                                printf("What would you like to do?\n(Enter 1 to manage present orders, 2 to manage flights, 3 to manage your personal information, 4 to return)\n");
                                                fflush(stdin);
                                                gets(enter);
                                            }
                                            e=atoi(enter);
                                            break;
                                        }
                                    }
                                }
                                printf("\nWhat would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                                gets(enter);
                                while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                {
                                    printf("\nYour selection is not identified. Please try again.\n");
                                    printf("What would you like to do?\n(Enter 1 to register, 2 to log in, 3 to return)\n");
                                    fflush(stdin);
                                    gets(enter);
                                }
                                e=atoi(enter);
                                break;
                            }
                            break;
                        }
                    }
                }
                printf("\nPlease select your entry:\n(Enter 0 for administrators, 1 for users. Enter 2 to exit.)\n");
                gets(enter);
                while(enter[0]<'0'||enter[0]>'2'||enter[1]!='\0')
                {
                    printf("\nYour selection is not identified. Please try again.\n");
                    printf("Please select your entry:\n(Enter 0 for administrators, 1 for users. Enter 2 to exit.)\n");
                    fflush(stdin);
                    gets(enter);
                }
                e=atoi(enter);
                break;
            }
        }
    }
    printf("\nThank you for using this program :)\n");
    getchar();
    return 0;
}

void sortofftime(struct FLIGHT**stPtr, int l, int r)
{
    int i, j;
    struct FLIGHT*x;
    if (l < r)
    {
        i = l;
        j = r;
        x=stPtr[l];

        while (i < j)
        {
            while(i < j && (strcmp(stPtr[j]->offtime,x->offtime)==1))
                j--; /* 从右向左找第一个小于x的数 */
            if(i < j)
                stPtr[i++] = stPtr[j];


            while(i < j && ((strcmp(x->offtime,(stPtr[i]->offtime)))==1))
                i++; /* 从左向右找第一个大于x的数 */
            if(i < j)
                stPtr[j--] = stPtr[i];

        }
        stPtr[i]=x;
        sortofftime(stPtr, l, i-1); /* 递归调用 */
        sortofftime(stPtr, i+1, r);
    }
}
;
void sortprice2(struct FLIGHT**stPtr, int l, int r)
{
    int i, j;
    struct FLIGHT*x;
    if (l < r)
    {
        i = l;
        j = r;
        x=stPtr[l];

        while (i < j)
        {
            while(i < j && (strcmp(stPtr[j]->price2,x->price2)==1))
                j--; /* 从右向左找第一个小于x的数 */
            if(i < j)
                stPtr[i++] = stPtr[j];


            while(i < j && ((strcmp(x->price2,(stPtr[i]->price2)))==1))
                i++; /* 从左向右找第一个大于x的数 */
            if(i < j)
                stPtr[j--] = stPtr[i];

        }
        stPtr[i]=x;
        sortprice2(stPtr, l, i-1); /* 递归调用 */
        sortprice2(stPtr, i+1, r);
    }
}

void register1()//用户注册
{
    char password1[20],password2[20],tmp[10];
    int i,at,dot;
    _Bool valid = false;
    FILE *checkPtr,*pfPtr;
    struct USER tempUser,newUser;

    while (1) {
        printf("Please input your ID(6~10,only consist of alphabets and digits)\n");
        scanf("%19s", newUser.ID);
        fflush(stdin);
        valid = true;

        if (strlen(newUser.ID)<6||strlen(newUser.ID)>10)

            valid = false;


        else {
            for (i = 0; i < strlen(newUser.ID); i++) {
                if (isalnum(newUser.ID[i])==0)
                {
                    valid = false;
                    break;
                }
            }
        }
        if ((checkPtr = fopen("user.txt", "rb+")) == NULL)
        {
            printf("ID check failed.Try again.\n");
            valid=false;
            exit(1);
        }
        else
        {

            while (!feof(checkPtr))
            {
                fread(&tempUser,sizeof(struct USER),1,checkPtr);
                if (strcmp(tempUser.ID,newUser.ID)==0)
                {
                    valid = false;
                    printf("This ID have already been used!\n");
                    break;
                }

            }
            fclose(checkPtr);
        }

        if (valid)
            break;
        else
            printf("Error.Please input again.\n");

    }
    do {
        printf("Please input your password(between 8~15 characters)\n");
        scanf("%19s", password1);
        fflush(stdin);
        while (strlen(password1) < 8 || strlen(password1) > 15) {
            fflush(stdin);
            printf("Error.Input your password again.(between 8~15 characters)\n");
            scanf("%19s", password1);
            fflush(stdin);
        }
        printf("Input your password again to confirm.\n");
        scanf("%19s", password2);
        fflush(stdin);
        if (strcmp(password1,password2)!=0)
            printf("Passwords are not the same.Try again.\n");
    }while(strcmp(password1,password2)!=0);
    strcpy(newUser.password,password1);

    printf("Please input your name.(no more than 20 characters,space is included)\n");
    scanf("%20s",newUser.name);
    fflush(stdin);

    printf("Please input your phone number.(11 digits)\n");
    valid=false;
    while(!valid)
    {
        scanf("%19s",newUser.phone);
        fflush(stdin);
        if (strlen(newUser.phone)==11)
        {
            valid=true;
            for(i=0;i<11;i++)
            {
                if(newUser.phone[i]<'0'|| newUser.phone[i]>'9')
                {
                    valid=false;
                    break;
                }
            }
        }
        if(!valid)
            printf("Error.Please your phone number again.\n");
    }

    printf("Please input your email address.(e.g:user@gmail.com)\n");
    valid=false;
    while(!valid)
    {
        scanf("%40s",newUser.mail);
        fflush(stdin);
        at=0;
        dot=0;
        for(i=0;i<strlen(newUser.mail);i++)
        {
            if ('@'==newUser.mail[i])
                at++;
            if('.'==newUser.mail[i])
                dot++;
        }
        if(1==at&&dot)
            valid=true;
        else
            printf("Unavailable email address.Input again.\n");
    }

    printf("Please input your sex.(1 for male,2 for female)\n");
    valid=false;
    while (!valid)
    {
        scanf("%5s",tmp);
        fflush(stdin);
        if(1==strlen(tmp)&&'1'==tmp[0])
        {
            valid=true;
            strcpy(newUser.sex,"male");
        }
        else if (1==strlen(tmp)&&'2'==tmp[0])
        {
            valid=true;
            strcpy(newUser.sex,"female");
        }
        else
            printf("Error.Please input your sex again.(1 for male,2 for female)\n");
    }

    if ((pfPtr=fopen("user.txt","ab+"))==NULL)
    {
        printf("User flie could not be opened.\n");
        exit(1);
    }
    else
    {
        fwrite(&newUser,sizeof(struct USER),1,pfPtr);
        printf("Sign up successfully! \n");

    }
    fclose(pfPtr);
}




int login1()//用户登录
{
    char passwordlogin[20];
    bool exist=false;
    struct USER tmplogin;
    int i;
    FILE *validPtr;

    exist = true;
    printf("Please input your ID\n");
    scanf("%19s",loginID);
    fflush(stdin);
    if (strlen(loginID)<6||strlen(loginID)>10)

        exist = false;


    else if ((validPtr = fopen("user.txt", "rb+")) == NULL)
    {
        printf("ID check failed.Try again.)\n");
        exist=false;
        exit(1);
    }
    else
    {
        exist=false;
        while (!feof(validPtr))
        {
            fread(&tmplogin,sizeof(struct USER),1,validPtr);
            if (strcmp(tmplogin.ID,loginID)==0)
            {
                exist=true;
                break;
            }

        }
        fclose(validPtr);

    }
    if(!exist)
    {
        printf("ID do not exist! Try again!\n");
        return 0;
    }
    else
    {
        printf("Please input your password.\n");
        scanf("%19s",passwordlogin);
        if (strcmp(passwordlogin,tmplogin.password)==0)
        {
            printf("Log in successfully!\n");
            return 1;
        }
        else
        {
            printf("Fail to log in.Wrong ID or password.\n");
            return 0;
        }

    }
}


int Senter1()
{
    char choice[3];

    printf("Enter 1 to search flight by flight numbers and departure time\n"
                   "      2 to search search by departure city, destination city and departure time\n"
                   "      3 to return\n");
    scanf("%2s",choice);
    fflush(stdin);
    while(choice[0]<'0'||choice[0]>'2'||choice[1]!='\0')
    {
        printf("Error.Please input again.\n");
        scanf("%4s",choice);
        fflush(stdin);
    }
    return (atoi(choice));

}
;

void getdate()  // 检验购票时间是否合理
{
    char mon[10], day[5],a,b;
    int m, d;
    _Bool valid = false;
    time_t rawtime;                 //获取当前系统时间
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    m= 1+timeinfo->tm_mon;
    d= timeinfo->tm_mday;

    printf("Please enter the month you want(from 9 to 12): ");
    valid=false;
    while(!valid)
    {
        scanf("%4s",mon);
        fflush(stdin);
        a=atoi(mon);
        if ((a==9||a==11)&&(a>=m))
        {
            valid=true;
            printf("Please enter the date you want(from 1 to 30): ");
            scanf("%4s",day);
            fflush(stdin);
            b=atoi(day);
            if(b>=1&&b<=30&&b>d)
                strcat(mon,day);
            else printf("Error.Please enter again.\n");
        }

        else if ((a==10||a==12)&&a>=m)
        {
            valid=true;
            printf("Please enter the date you want(from 1 to 31): ");
            scanf("%s",day);
            fflush(stdin);
            b=atoi(day);
            if(b>=1&&b<=31&&b>d)
                strcat(mon,day);
            else printf("Error.Please enter again.\n");
        }

        else printf("Error.Please enter again.\n");
        strcpy(searchdate,mon);


    }

}


int checkflightnumber(char*s,struct FLIGHT*Ptr)
{
    FILE*checkPtr;
    struct FLIGHT*M;
    int i,l,exist=0;
    M=(struct FLIGHT*)malloc(sizeof(struct FLIGHT));
    if(M==NULL)
    {
        printf("Memory Error.\n");
        exit(1);
    }

    else if ((checkPtr = fopen("aviation information.txt", "r+")) == NULL)
    {
        printf("Flight check failed.Try again.\n");
        exit(1);
    }
    else
    {

        while((i=fgetc(checkPtr))!=EOF)//计算总行数，用于for循环+fscanf，以及后面fprintf的指针位置确定
        {
            if(i=='\n')
                l++;
        }

        rewind(checkPtr);
        for(i=0;i<l;i++)
        {
            fscanf(checkPtr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",M->num,M->comp,M->departure,M->destination,M->offtime,M->flytime,M->level1,M->total1,M->num1,M->price1,M->level2,M->num2,M->total2,M->price2,M->type,M->punctuality,M->pilot1,M->pilot2);
            if (strcmp(M->num,s)==0)
            {
                *Ptr = *M;
                exist = 1;

                break;
            }

        }
        free(M);
        M=NULL;
        fclose(checkPtr);

    }

    return exist;
}
;
int Senter2()
{
    char choice[3];

    printf("Enter 1 to screen company;\n"
                   "      2 to screen cabin class\n"
                   "      3 to screen plane type\n"
                   "      4 to screen departure\n"
                   "      5 to sort by departure time\n"
                   "      6 to sort by the price(from the lowest to the highest)\n"
                   "      7 to add tickets to an order\n"
                   "      8 to purchase your current now\n"
                   "      9 to return\n");
    scanf("%2s",choice);
    fflush(stdin);
    while(choice[0]<'1'||choice[0]>'8'||choice[1]!='\0')
    {
        printf("Error.Please input again.\n");
        scanf("%4s",choice);
        fflush(stdin);
    }
    return (atoi(choice));
}
;
void checkflight()//用户查询航班
{
    int enter,screen,i,l,no,buf=100;
    char userorder[25];
    while((enter=Senter1())!=8)
    {

        switch(enter)
        {
            case 1:
            {
                struct FLIGHT*bynumPtr;

                char flightnumber[20],subenter[5];//user input mark
                getdate();//输入到全局变量；
                printf("Please input flight numbers:");
                scanf("%9s",flightnumber);
                fflush(stdin);
                bynumPtr=(struct FLIGHT*)malloc(sizeof(struct FLIGHT));
                if(bynumPtr==NULL)
                {
                    printf("Memory Error.\n");
                    exit(1);
                }
                if (!checkflightnumber(flightnumber,bynumPtr))
                {
                    printf("Flight do not exist!\n");
                    free(bynumPtr);
                    bynumPtr=NULL;
                    break;
                }
                else
                {
                    printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime   Level1------Total   Seats   Price   Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");
                    printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-7s %s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",bynumPtr->num,bynumPtr->comp,bynumPtr->departure,bynumPtr->destination,bynumPtr->offtime,bynumPtr->flytime,bynumPtr->level1,bynumPtr->total1,bynumPtr->num1,bynumPtr->price1,bynumPtr->level2,bynumPtr->total2,bynumPtr->num2,bynumPtr->price2,bynumPtr->type,bynumPtr->punctuality,bynumPtr->pilot1,bynumPtr->pilot2);
                    printf("Enter 1 to add to order,enter any character to return;\n");
                    scanf("%2s",subenter);
                    fflush(stdin);
                    if(subenter[0]=='1'&&subenter[1]=='\0')
                        buy();


                    free(bynumPtr);
                    bynumPtr=NULL;
                    break;
                }




            }
            case 2:
            {
                struct FLIGHT *tmpfPtr[buf];
                struct FLIGHT *scan;
                char leave[10],reach[10],company[20],level[5],planetype[20],time1[10],time2[10],add[5];
                FILE*readflight;
                for(i=0;i<buf;i++)
                {
                    tmpfPtr[i]=(struct FLIGHT*)malloc(sizeof(struct FLIGHT));
                    if(tmpfPtr[i]==NULL)
                    {
                        printf("Memory Error.\n");
                        exit(1);

                    }
                }
                printf("Please enter the city where the plane take off.\n");
                scanf("%9s",leave);
                fflush(stdin);
                printf("please enter your destination\n");
                scanf("%9s",reach);
                fflush(stdin);

                if ((readflight = fopen("aviation information.txt", "r+")) == NULL)
                {
                    printf("Flight check failed.Try again.\n");
                    exit(1);
                }
                else
                {
                    l=0;

                    while((i=fgetc(readflight))!=EOF)//计算总行数，用于for循环+fscanf，以及后面fprintf的指针位置确定
                    {
                        if(i=='\n')
                            l++;
                    }
                    rewind(readflight);
                    no=0;
                    for(i=0;i<l;i++)
                    {
                        fscanf(readflight,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",scan->num,scan->comp,scan->departure,scan->destination,scan->offtime,scan->flytime,scan->level1,scan->total1,scan->num1,scan->price1,scan->level2,scan->num2,scan->total2,scan->price2,scan->type,scan->punctuality,scan->pilot1,scan->pilot2);
                        if((strcmp(scan->departure,leave)==0)&&(strcmp(scan->destination,reach)==0))
                            *tmpfPtr[no++]=*scan;

                    }

                    printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime   Level1------Total   Seats   Price   Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");
                    for(i=0;i<no;i++)
                    {

                        printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-7s %s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",tmpfPtr[i]->num,tmpfPtr[i]->comp,tmpfPtr[i]->departure,tmpfPtr[i]->destination,tmpfPtr[i]->offtime,tmpfPtr[i]->flytime,tmpfPtr[i]->level1,tmpfPtr[i]->total1,tmpfPtr[i]->num1,tmpfPtr[i]->price1,tmpfPtr[i]->level2,tmpfPtr[i]->total2,tmpfPtr[i]->num2,tmpfPtr[i]->price2,tmpfPtr[i]->type,tmpfPtr[i]->punctuality,tmpfPtr[i]->pilot1,tmpfPtr[i]->pilot2);
                    }
                    printf("\nThe results are listed above.\n");
                    while((screen=Senter2())!=9)
                        switch (screen)
                        {
                            case 2:
                            {
                                printf("Please enter the class.\n   1 for first class\n   2 for tourist class\n");

                                scanf("%3s",level);
                                fflush(stdin);
                                if(0==strcmp(level,"1")) {
                                    printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime    Level1------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");

                                    for (i = 0; i < no; i++) {


                                        printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",
                                               tmpfPtr[i]->num, tmpfPtr[i]->comp, tmpfPtr[i]->departure,
                                               tmpfPtr[i]->destination, tmpfPtr[i]->offtime, tmpfPtr[i]->flytime,
                                               tmpfPtr[i]->level1, tmpfPtr[i]->total1, tmpfPtr[i]->num1,
                                               tmpfPtr[i]->price1, tmpfPtr[i]->type, tmpfPtr[i]->punctuality,
                                               tmpfPtr[i]->pilot1, tmpfPtr[i]->pilot2);
                                    }
                                    printf("\nThe results are listed above.\n");
                                    printf("Enter 1 to add to order,enter any character to return;\n");
                                    scanf("%2s", add);
                                    fflush(stdin);
                                    if (add[0] == '1' && add[1] == '\0')
                                        buy();

                                    break;
                                }
                                else if(0==strcmp(level,"2")) {
                                    printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime    Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");

                                    for (i = 0; i < no; i++) {


                                        printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",
                                               tmpfPtr[i]->num, tmpfPtr[i]->comp, tmpfPtr[i]->departure,
                                               tmpfPtr[i]->destination, tmpfPtr[i]->offtime, tmpfPtr[i]->flytime,
                                               tmpfPtr[i]->level2, tmpfPtr[i]->total2, tmpfPtr[i]->num2,
                                               tmpfPtr[i]->price2, tmpfPtr[i]->type, tmpfPtr[i]->punctuality,
                                               tmpfPtr[i]->pilot1, tmpfPtr[i]->pilot2);
                                    }
                                    printf("\nThe results are listed above.\n");
                                    printf("Enter 1 to add to order,enter any character to return;\n");
                                    scanf("%2s", add);
                                    fflush(stdin);
                                    if (add[0] == '1' && add[1] == '\0')
                                        buy();

                                    break;
                                }
                                else
                                    break;


                            }
                            case 1:
                            {
                                printf("Please enter the company name.(ex:CA)");
                                scanf("%15s",company);
                                fflush(stdin);
                                printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime   Level1------Total   Seats   Price   Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");
                                for(i=0;i<no;i++)
                                {
                                    if(strcmp(tmpfPtr[i]->comp,company)==0)

                                        printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-7s %s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",tmpfPtr[i]->num,tmpfPtr[i]->comp,tmpfPtr[i]->departure,tmpfPtr[i]->destination,tmpfPtr[i]->offtime,tmpfPtr[i]->flytime,tmpfPtr[i]->level1,tmpfPtr[i]->total1,tmpfPtr[i]->num1,tmpfPtr[i]->price1,tmpfPtr[i]->level2,tmpfPtr[i]->total2,tmpfPtr[i]->num2,tmpfPtr[i]->price2,tmpfPtr[i]->type,tmpfPtr[i]->punctuality,tmpfPtr[i]->pilot1,tmpfPtr[i]->pilot2);
                                }
                                printf("\nThe results are listed above.\n");
                                printf("Enter 1 to add to order,enter any character to return;\n");
                                scanf("%2s",add);
                                fflush(stdin);
                                if(add[0]=='1'&&add[1]=='\0')
                                    buy();

                                break;


                            }
                            case 3:
                            {
                                printf("Please enter the plane type.(ex:Boeing737)");
                                scanf("%15s",planetype);
                                fflush(stdin);
                                printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime   Level1------Total   Seats   Price   Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");
                                for(i=0;i<no;i++)
                                {
                                    if(strcmp(tmpfPtr[i]->type,planetype)==0)

                                        printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-7s %s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",tmpfPtr[i]->num,tmpfPtr[i]->comp,tmpfPtr[i]->departure,tmpfPtr[i]->destination,tmpfPtr[i]->offtime,tmpfPtr[i]->flytime,tmpfPtr[i]->level1,tmpfPtr[i]->total1,tmpfPtr[i]->num1,tmpfPtr[i]->price1,tmpfPtr[i]->level2,tmpfPtr[i]->total2,tmpfPtr[i]->num2,tmpfPtr[i]->price2,tmpfPtr[i]->type,tmpfPtr[i]->punctuality,tmpfPtr[i]->pilot1,tmpfPtr[i]->pilot2);
                                }
                                printf("\nThe results are listed above.\n");
                                printf("Enter 1 to add to order,enter any character to return;\n");
                                scanf("%2s",add);
                                fflush(stdin);
                                if(add[0]=='1'&&add[1]=='\0')
                                    buy();

                                break;

                            }
                            case 4:
                            {
                                printf("Please enter the departure time period\n (format:  HH:MM,ex: 21:05, 03:25)From: ");
                                scanf("%8s",time1);
                                fflush(stdin);
                                while(time1[0]<'0'||time1[0]>'2'||time1[1]<'0'||time1[1]>'9'||time1[2]!=':'||time1[3]<'0'||time1[3]>'5'||time1[4]<'0'||time1[4]>'9'||(time1[0]=='2'&&time1[1]>'3')||time1[5]!='\0') {
                                    printf("\nThe time is invalid. Please try again.\n");
                                    printf("Please enter the departure time period\n (format:  HH:MM,ex: 21:05, 03:25)From: ");
                                    scanf("%8s", time1);
                                    fflush(stdin);
                                }
                                printf("To: ");
                                scanf("%8s",time2);
                                fflush(stdin);
                                while(time2[0]<'0'||time2[0]>'2'||time2[1]<'0'||time2[1]>'9'||time2[2]!=':'||time2[3]<'0'||time2[3]>'5'||time2[4]<'0'||time2[4]>'9'||(time2[0]=='2'&&time2[1]>'3')||time2[5]!='\0'||(!strcmp(time2,time1))) {
                                    printf("\nThe time is invalid. Please try again.\n");
                                    printf("To: \n");
                                    scanf("%8s", time2);
                                    fflush(stdin);
                                }
                                printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime   Level1------Total   Seats   Price   Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");
                                for(i=0;i<no;i++)
                                {
                                    if(strcmp(tmpfPtr[i]->offtime,time1)&&strcmp(time2,tmpfPtr[i]->offtime))

                                        printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-7s %s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",tmpfPtr[i]->num,tmpfPtr[i]->comp,tmpfPtr[i]->departure,tmpfPtr[i]->destination,tmpfPtr[i]->offtime,tmpfPtr[i]->flytime,tmpfPtr[i]->level1,tmpfPtr[i]->total1,tmpfPtr[i]->num1,tmpfPtr[i]->price1,tmpfPtr[i]->level2,tmpfPtr[i]->total2,tmpfPtr[i]->num2,tmpfPtr[i]->price2,tmpfPtr[i]->type,tmpfPtr[i]->punctuality,tmpfPtr[i]->pilot1,tmpfPtr[i]->pilot2);
                                }
                                printf("\nThe results are listed above.\n");
                                printf("Enter 1 to add to order,enter any character to return;\n");
                                scanf("%2s",add);
                                fflush(stdin);
                                if(add[0]=='1'&&add[1]=='\0')
                                    buy();

                                break;

                            }
                            case 5:
                            {
                                sortofftime(tmpfPtr,0,no-1);
                                printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime   Level1------Total   Seats   Price   Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");
                                for(i=0;i<no;i++)
                                {
                                    printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-7s %s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",tmpfPtr[i]->num,tmpfPtr[i]->comp,tmpfPtr[i]->departure,tmpfPtr[i]->destination,tmpfPtr[i]->offtime,tmpfPtr[i]->flytime,tmpfPtr[i]->level1,tmpfPtr[i]->total1,tmpfPtr[i]->num1,tmpfPtr[i]->price1,tmpfPtr[i]->level2,tmpfPtr[i]->total2,tmpfPtr[i]->num2,tmpfPtr[i]->price2,tmpfPtr[i]->type,tmpfPtr[i]->punctuality,tmpfPtr[i]->pilot1,tmpfPtr[i]->pilot2);
                                }
                                printf("\nThe results are listed above.\n");
                                printf("Enter 1 to add to order,enter any character to return;\n");
                                scanf("%2s",add);
                                fflush(stdin);
                                if(add[0]=='1'&&add[1]=='\0')
                                    buy();

                                break;
                            }
                            case 6:
                            {
                                sortprice2(tmpfPtr,0,no-1);
                                printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime   Level1------Total   Seats   Price   Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");
                                for(i=0;i<no;i++)
                                {
                                    printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-7s %s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",tmpfPtr[i]->num,tmpfPtr[i]->comp,tmpfPtr[i]->departure,tmpfPtr[i]->destination,tmpfPtr[i]->offtime,tmpfPtr[i]->flytime,tmpfPtr[i]->level1,tmpfPtr[i]->total1,tmpfPtr[i]->num1,tmpfPtr[i]->price1,tmpfPtr[i]->level2,tmpfPtr[i]->total2,tmpfPtr[i]->num2,tmpfPtr[i]->price2,tmpfPtr[i]->type,tmpfPtr[i]->punctuality,tmpfPtr[i]->pilot1,tmpfPtr[i]->pilot2);
                                }
                                printf("\nThe results are listed above.\n");
                                printf("Enter 1 to add to order,enter any character to return;\n");
                                scanf("%2s",add);
                                fflush(stdin);
                                if(add[0]=='1'&&add[1]=='\0')
                                    buy();

                                break;

                            }
                            case 7:
                            {
                                buy();
                                break;
                            }
                            case 8:
                            {
                                strcpy(userorder,loginID);
                                strcat(userorder,".txt");
                                remove(userorder);
                                break;
                            }

                        }

                }









                for(i=0;i<buf;i++)
                {
                    free(tmpfPtr[i]);
                    tmpfPtr[i]=NULL;
                }

                fclose(readflight);
            }
        }






    }

}


int pay( )  //模拟支付
{

    char cardNO[31];
    char phone[20];
    char userorder[25];
    int i=0,cnt=0;
    int totalprice=0;
    char tmp7;
    _Bool valid = false;
    struct ORDER unpay;
    FILE*display;
    strcpy(userorder,loginID);
    strcat(userorder,".txt");

    if ((display = fopen(userorder, "rb+")) == NULL)
    {
        printf("Failed to open the file.Try again.\n");

        exit(1);
    }
    else
    {

        printf("Your current order is followed:\n");
        printf("NAME               "" NO.   "" COMPANY"" ORIGIN"" DESTINATION "" DATE   "" BD TIME"
                       " SEAT"" CLASS              "" TYPE         "" PRICE  \n");
        while (!feof(display))
        {
            fread(&unpay,sizeof(struct ORDER),1,display);
            printf("%19s %6s %7s %6s %11s %7s %7s %4s %20s %13s %7d\n",unpay.person,unpay.num,unpay.comp,unpay.departure,unpay.destination,unpay.date,unpay.offtime,unpay.seat,unpay.level,unpay.type,unpay.price);
            totalprice+=unpay.price;

        }
        fclose(display);
    }

    printf("Would you like to pay for all the tickets in the order?\n Enter 'Y' to pay,enten any others to quit.");
    scanf("%c", tmp7);
    fflush(stdin);
    if(tmp7=='Y')
    {
        printf("You should pay %s",totalprice);
        printf("Please input your credit card number.(19 digits)\n");
        valid=false;
        while(!valid)
        {
            scanf("%s",cardNO);
            fflush(stdin);
            if (strlen(cardNO)==19)
            {
                valid=true;
                for(i=0;i<19;i++)         //验证输入卡号是否全部为数字
                {
                    if(!isdigit(cardNO[i]))
                    {
                        valid=false;
                        break;
                    }
                }
            }
            if(!valid)           //号码不是19位，或含有非数字字符均重新输入
                printf("Error.Please your phone number again.\n");
        }
        printf("Please input your phone number.(11 digits)\n"); //输入电话
        valid=false;
        while(!valid)
        {
            scanf("%19s",phone);
            fflush(stdin);
            if (strlen(phone)==11)
            {
                valid=true;
                for(i=0;i<11;i++)         //验证输入号码是否全部为数字
                {
                    if(!isdigit(phone[i]))
                    {
                        valid=false;
                        break;
                    }
                }
            }
            if(!valid)           //号码不是11位，或含有非数字字符均重新输入
                printf("Error.Please your phone number again.\n");
        }



        printf("Successfully paid.\n");
        printf("We will send messege to your phone to inform you the payout status.\n ");
        return 1;
    }

    else return 0;
}


void buy()//包含保存订单—>模拟付款/取消订单(直接检索并删除之前保存的内容)
{

    struct FLIGHT flight[30];
    struct ORDER ticket[30];
    struct ORDER order[10];
    int pay();
    int flightnumber1=0;
    FILE *checkticket;
    FILE *checkflight;
    FILE *checkuser;
    FILE *out;
    struct ORDER paid[10];
    FILE *in;
    char userorder[25];
    strcpy(userorder,loginID);
    strcat(userorder,".txt");
    checkuser=fopen(userorder,"ab+");
    checkflight=fopen("aviation information.txt","r");
    checkticket=fopen("order information.txt","rb+");
    if(checkticket==NULL)
    {
        printf("Error! Please check that the file 'order information.txt' exists.\n");
        exit(1);
    }
    if(checkflight==NULL)
    {
        printf("Error! Please check that the file 'aviation information.txt' exists.\n");
        exit(1);
    }
    if(checkuser==NULL)
    {
        printf("Error! \n");
        exit(1);
    }
    int cc=0;
    int ij;
    /*
    while((ij=fgetc(checkticket))!=EOF)//计算总行数，用于for循环+fscanf，以及后面fprintf的指针位置确定
	{
		if(ij=='\n')
		cc++;
	}
	int hh=cc;
	rewind(checkticket);
     */
    int tt=0;
    while((ij=fgetc(checkflight))!=EOF)//计算总行数，用于for循环+fscanf，以及后面fprintf的指针位置确定
    {
        if(ij=='\n')
            tt++;
    }
    tt=tt-3;
    rewind(checkflight);
    int i=0,inorder=0;
    /*
    for(i=0;i<cc;i++)
    {
        fscanf(checkticket,"%s %s %s %s %s %s %d %d %s %s %s %s %s %s %d",ticket[i].ID,ticket[i].passenger,ticket[i].num,ticket[i].comp,ticket[i].departure,ticket[i].destination,ticket[i].date,ticket[i].buydate,ticket[i].offtime,ticket[i].flytime,ticket[i].level,ticket[i].seatnum,ticket[i].type,ticket[i].price,ticket[i].payment);
    }
     */
    while (!feof(checkticket))
    {
        fread(&ticket[i], sizeof(struct ORDER),1,checkticket);
        i++;
    }
    int hh=i;
    cc=i;
    while (!feof(checkuser))
    {
        fread(&order[inorder], sizeof(struct ORDER),1,checkuser);
        inorder++;
    }
    for(i=0;i<tt;i++)
    {
        fscanf(checkflight,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",flight[i].num,flight[i].comp,flight[i].departure,flight[i].destination,flight[i].offtime,flight[i].flytime,flight[i].level1,flight[i].total1,flight[i].num1,flight[i].price1,flight[i].level2,flight[i].num2,flight[i].total2,flight[i].price2,flight[i].type,flight[i].punctuality,flight[i].pilot1,flight[i].pilot2);
    }

    fclose(checkflight);
    time_t rawtime;                 //获取当前系统时间
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int m= 1+timeinfo->tm_mon;
    int d= timeinfo->tm_mday;

    while(flightnumber1<=0||flightnumber1>5)
    {
        printf("Please enter the number of flights you'd like to arrive by(below 6):");
        scanf("%d",&flightnumber1);
        if(flightnumber1<=0||flightnumber1>5)
            printf("Your number does not meet the requirement.");
    }
    char ccompany[5];
    int ab=0;
    char flightnumber2[10];
    int aa=0;

    int ii;
    for(;aa<flightnumber1;aa++)
    {
        int tickett=inorder;
        int jj=0;
        printf("\nPlease type in one flight number you want: ");
        while(jj!=1)
        {
            scanf("%s",flightnumber2);
            for(ii=0;ii<tt;)
            {
                if(strcmp(flightnumber2,flight[ii].num)==0)
                {
                    jj++;
                    break;
                }
                else
                    ii++;

            }
            if(jj!=1)
                printf("\nYour number is wrong.Please type in one flight number you want again: ");
        }
        char mmonth[20];
        char dday[20];
        int ac=0;


        printf("Please enter the date you set off.\n ");
        while(ac!=1)
        {
            printf("month(eg:10):");
            scanf("%s",&mmonth);

            if(isdigit(mmonth[0])==0||(isdigit(mmonth[1])==0&&mmonth[1]!='\0'))
            {
                printf("Your date does not meet the requirement.Please enter again.");
                ac=0;
                continue;
            }
            int mmonth1;
            mmonth1=atoi(mmonth);
            if(mmonth1<9||mmonth1>12)
            {
                printf("Your date does not meet the requirement.Please enter again.");
                ac=0;
                continue;
            }
            else
                ac=1;
        }
        int ad=0;
        int mmonth1;
        mmonth1=atoi(mmonth);
        while(ad!=1)
        {
            printf("day(eg:1):");
            scanf("%s",&dday);
            if(isdigit(dday[0])==0||(isdigit(dday[1])==0&&dday[1]!='\0'))
            {

                printf("Your date does not meet the requirement.Please enter again.");
                ad=0;
                continue;
            }
            int dday1;
            dday1=atoi(dday);
            if(mmonth1==9)
            {
                if(dday1<d||dday1>30)
                {
                    printf("Your date does not meet the requirement.Please enter again.");
                    ad=0;
                    continue;
                }
                else
                    ad=1;
            }

            else if(mmonth1==11)
            {
                if(dday1<1||dday1>30)
                {
                    printf("Your date does not meet the requirement.Please enter again.");
                    ad=0;
                    continue;
                }
                else
                    ad=1;
            }
            else
            {
                if(dday1<1||dday1>31)
                {
                    printf("Your date does not meet the requirement.Please enter again.");
                    break;
                }
                else
                    ad=1;
            }
        }
        int dday1;
        dday1=atoi(dday);
        int passengernum;
        int am=0;
        while(am!=1)
        {
            printf("Please enter the number of passengers:");
            scanf("%d",&passengernum);
            int mn;
            int hm=0;
            for(mn=0;mn<cc;mn++)//一天之内不能购买超过5张票
            {
                if(strcmp(loginID,ticket[mn].ID)==0)
                {
                    if(ticket[mn].buydate==m*100+d)
                        hm++;
                }
            }
            tickett+=hm;
            tickett=tickett+passengernum;
            if(tickett>5)
            {
                printf("Sorry,your number of tickets has above the limit.");
            }
            else
                am=1;
        }

        int kk;
        char prefer[15];
        int level1num=0;
        int level2num=0;
        char levell[]="first-class";
        char levelll[]="tourist-class";
        int mm=0;
        for(;mm<cc;mm++)
        {
            if(strcmp(flightnumber2,ticket[mm].num)==0)
            {
                if(ticket[mm].level[0]=='f')
                    level1num++;
                else
                    level2num++;
            }
        }
        int total11=atoi(flight[ii].total1);
        int total22=atoi(flight[ii].total2);
        flight[ii].remain1=total11-level1num;
        flight[ii].remain2=total22-level2num;
        char seatnumber1[5];
        char seatnumber2[5];
        int qq;
        int gg=0;
        int pp=0;
        int ae=0;
        for(kk=0;kk<passengernum;kk++,cc++)
        {
            printf("Please enter one passenger's name:");
            scanf("%s",&ticket[cc].person);
            printf("Which level do you prefer?(first-class,tourist-class)");

            scanf("%s",&prefer);
            while(strcmp(prefer,levell)!=0&&strcmp(prefer,levelll)!=0)
            {
                printf("Your answer does not meet the requirement.\n");
                printf("Which level do you prefer?(first-class,tourist-class)");
                scanf("%s",&prefer);
            }
            while(ae!=1)
            {
                if(strcmp(prefer,levell)==0)
                {
                    if( flight[ii].remain1>=1)
                    {
                        flight[ii].remain1--;
                        strcpy(ticket[cc].level,prefer);
                        while(pp!=1)
                        {
                            printf("Please enter the seat number(eg:1A,1C,1J,1L):");
                            scanf("%s",&seatnumber1);

                            if(total11==8)
                            {
                                if(seatnumber1[0]!='1'&&seatnumber1[0]!='2')
                                {
                                    printf("Your answer does not meet the requirement.\n");
                                    continue;
                                }
                            }
                            if(total22==12)
                            {
                                if(seatnumber1[0]!='1'&&seatnumber1[0]!='2'&&seatnumber1[0]!='3')
                                {
                                    printf("Your answer does not meet the requirement.\n");

                                    continue;
                                }
                            }
                            if(seatnumber1[1]!='A'&&seatnumber1[1]!='C'&&seatnumber1[1]!='J'&&seatnumber1[1]!='L')
                            {
                                printf("Your answer does not meet the requirement.\n");

                                continue;
                            }
                            if(seatnumber1[2]!='\0')
                            {
                                printf("Your answer does not meet the requirement.\n");

                                continue;
                            }
                            int pq=0;
                            for(qq=0;qq<cc;qq++)
                            {
                                if(strcmp(flightnumber2,ticket[qq].num)==0)
                                {
                                    if(strcmp(seatnumber1,ticket[qq].seat)==0)
                                    {

                                        printf("Sorry,this position has been ordered.");
                                        pq=1;
                                        break;
                                    }

                                }

                            }
                            if(pq==0)
                                pp=1;
                            else
                                pp=0;
                        }

                    }
                    strcpy(ticket[cc].seat,seatnumber1);
                    ae=1;
                    strcpy(ticket[cc].pricec,flight[ii].price1);
                }
                else
                {

                    printf("Sorry,we don't have enough tickets");
                    strcpy(prefer,levelll);
                }

                if(strcmp(prefer,levelll)==0)
                {
                    if( flight[ii].remain2>=1)
                    {
                        flight[ii].remain2--;
                        strcpy(ticket[cc].level,prefer);
                        while(gg!=1)
                        {
                            printf("Please enter the seat number(eg:11A,11B,11C,11J,11K,11L):");
                            scanf("%s",&seatnumber1);
                            if(total22==150)
                            {
                                char ch=seatnumber1[0];
                                if(ch!='1'&&ch!='2'&&ch!='3')
                                {
                                    printf("Your answer does not meet the requirement.\n");
                                    continue;
                                }

                                char ch1=seatnumber1[1];
                                if(isdigit(seatnumber1[1])!=0)
                                {
                                    printf("Your answer does not meet the requirement.\n");
                                    continue;
                                }
                                int chh,chh1;
                                chh=int(ch-'0');//将seatnumber的第一位和第二位转化为数字
                                chh1=int(ch1-'0');
                                if((chh*10+chh1)>35||(chh*10+chh1)<11)
                                {
                                    printf("Your answer does not meet the requirement.\n");
                                    continue;
                                }
                            }
                            if(total22==180)
                            {
                                char ch=seatnumber1[0];
                                if(ch!='1'&&ch!='2'&&ch!='3'&&ch!='4')
                                {
                                    printf("Your answer does not meet the requirement.\n");
                                    continue;
                                }
                                char ch1=seatnumber1[1];
                                if(isdigit(seatnumber1[1])!=0)
                                {
                                    printf("Your answer does not meet the requirement.\n");
                                    continue;
                                }
                                int chh,chh1;
                                chh=int(ch-'0');//将seatnumber1的第一位和第二位转化为数字
                                chh1=int(ch1-'0');
                                if((chh*10+chh1)>40||(chh*10+chh1)<11)
                                {
                                    printf("Your answer does not meet the requirement.\n");
                                    continue;
                                }
                            }
                            if(seatnumber1[2]!='A'&&seatnumber1[2]!='B'&&seatnumber1[2]!='C'&&seatnumber1[2]!='J'&&seatnumber1[2]!='K'&&seatnumber1[2]!='L')
                            {
                                printf("Your answer does not meet the requirement.\n");
                                continue;
                            }
                            if(seatnumber1[3]!='\0')
                            {
                                printf("Your answer does not meet the requirement.\n");
                                continue;
                            }
                            int gq=0;
                            for(qq=0;qq<cc;qq++)
                            {
                                if(strcmp(flightnumber2,ticket[qq].num)==0)
                                {
                                    if(strcmp(seatnumber1,ticket[qq].seat)==0)
                                    {

                                        printf("Sorry,this position has been ordered.");
                                        gq=1;
                                        break;
                                    }

                                }
                            }
                            if(gq==0)
                                gg=1;
                            else
                                gg=0;
                        }
                        strcpy(ticket[cc].seat,seatnumber1);
                        ae=1;
                        strcpy(ticket[cc].pricec,flight[ii].price2);
                    }
                    else
                        printf("Sorry,we don't have enough tickets");
                    strcpy(prefer,levell);
                }
            }

            strcpy(ticket[cc].num,flightnumber2);
            strcpy(ticket[cc].ID,loginID);
            strcpy(ticket[cc].comp,ccompany);
            ticket[cc].date=mmonth1*100+dday1;
            ticket[cc].buydate=m*100+d;
            strcpy(ticket[cc].departure,flight[ii].departure);
            strcpy(ticket[cc].destination,flight[ii].destination);
            strcpy(ticket[cc].offtime,flight[ii].offtime);
            strcpy(ticket[cc].flytime,flight[ii].flytime);
            strcpy(ticket[cc].type,flight[ii].type);
            char price1[20];
            price1[0]=ticket[cc].pricec[1];price1[1]=ticket[cc].pricec[2];price1[2]=ticket[cc].pricec[3];price1[3]=ticket[cc].pricec[4];;
            int price20=atoi(price1);
            ticket[cc].price=price20;
        }

    }

    int rr;

    for(rr=hh;rr<cc;rr++)
    {
        fwrite(&ticket[rr], sizeof(struct ORDER),1,checkuser);
    }
    fclose(checkticket);
    fclose(checkuser);
    if(pay())
    {

        struct ORDER unpay;
        FILE*display;
        strcpy(userorder,loginID);
        strcat(userorder,".txt");
        if ((in = fopen("order information.txt", "ab+")) == NULL)
        {
            printf("Failed to open the file.Try again.\n");

            exit(1);
        }
        if ((out = fopen(userorder, "rb+")) == NULL)
        {
            printf("Failed to open the file.Try again.\n");

            exit(1);
        }
        int j=0;
        while (!feof(out))
        {
            fread(&paid[j], sizeof(struct ORDER),1,out);
            fwrite(&paid[j], sizeof(struct ORDER),1,in);
            j++;
        }
        remove(userorder);

    }
}

void information1()   //用于——个人信息管理
{
    int L,i,tmp6,at,dot;
    char enter6[5];
    char password2[20];
    struct USER tmp0;//原用户信息
    _Bool valid = false;
    FILE *infoPtr;
    infoPtr = fopen("user.txt", "rb+");
    if (infoPtr  == NULL)
    {
        printf("Fail to open the file.\n");
        exit(1);
    }
    else {
        while (!feof(infoPtr)) {
            fread(&tmp0, sizeof(struct USER), 1, infoPtr); //从infoPtr指向的文件中读取大小为sizeof(struct USER)的结构tmp0
            if (strcmp(tmp0.ID, loginID) == 0)
                break;

        }

        if (-1 == fseek(infoPtr, -1L * sizeof(struct USER), SEEK_CUR)) {
            printf("Seek error\n");
            exit(1);
        }
        printf("phone: %s;  email:%s\n",tmp0.phone,tmp0.mail);


        printf("Which personal information would you like to amend?\n");
        printf("Enter 1 to change password, 2 to change phone, 3 to change you mail,4 to return\n");
        scanf("%3s",enter6);
        fflush(stdin);
        while(enter6[0]<'1'||enter6[0]>'4'||enter6[1]!='\0')
        {
            printf("Error.Please input again.\n");
            scanf("%3s",enter6);
            fflush(stdin);
        }

        tmp6=atoi(enter6);

        while(tmp6!=4)
        {


            switch(tmp6)
            {
                case 1:
                {
                    do {
                        printf("Please input your  new password(between 8~15 characters)\n");  //输入密码
                        scanf("%18s", tmp0.password);
                        fflush(stdin);
                        while (strlen(tmp0.password) < 8 || strlen(tmp0.password) > 15) //验证密码是否为8-15位
                        {
                            fflush(stdin);
                            printf("Error.Input your password again.(between 8~15 characters)\n");
                            scanf("%18s", tmp0.password);
                            fflush(stdin);
                        }
                        printf("Input your password again to confirm.\n"); //确认密码
                        scanf("%18s", password2);
                        fflush(stdin);
                        if (strcmp(tmp0.password,password2)!=0)   //比较两字符串是否相同
                            printf("Passwords are not the same.Try again.\n");
                    }while(strcmp(tmp0.password,password2)!=0);
                    printf("Which personal information would you like to amend?\n");
                    printf("Enter 1 to change password, 2 to change phone, 3 to change you mail,4 to return\n");
                    scanf("%3s",enter6);
                    fflush(stdin);
                    while(enter6[0]<'1'||enter6[0]>'4'||enter6[1]!='\0')
                    {
                        printf("Error.Please input again.\n");
                        scanf("%3s",enter6);
                        fflush(stdin);
                    }

                    tmp6=atoi(enter6);


                    break;
                }

                case 2:
                {
                    printf("Please input your new phone number.(11 digits)\n"); //输入电话
                    valid=false;
                    while(!valid)
                    {
                        scanf("%15s",tmp0.phone);
                        fflush(stdin);
                        if (strlen(tmp0.phone)==11)
                        {
                            valid=true;
                            for(i=0;i<11;i++)         //验证输入号码是否全部为数字
                            {
                                if(!isdigit(tmp0.phone[i]))
                                {
                                    valid=false;
                                    break;
                                }
                            }
                        }
                        if(!valid)           //号码不是11位，或含有非数字字符均重新输入
                            printf("Error.Please enter your phone number again.\n");
                    }
                    printf("Which personal information would you like to amend?\n");
                    printf("Enter 1 to change password, 2 to change phone, 3 to change you mail,4 to return\n");
                    scanf("%3s",enter6);
                    fflush(stdin);
                    while(enter6[0]<'1'||enter6[0]>'4'||enter6[1]!='\0')
                    {
                        printf("Error.Please input again.\n");
                        scanf("%3s",enter6);
                        fflush(stdin);
                    }

                    tmp6=atoi(enter6);

                    break;
                }

                case 3:
                {

                    printf("Please input your  new email address.(e.g:user@gmail.com)\n"); //输入邮箱
                    valid=false;
                    while(!valid)
                    {
                        scanf("%39s",tmp0.mail);
                        fflush(stdin);
                        at=0;
                        dot=0;
                        for(i=0;i<strlen(tmp0.mail);i++)
                        {
                            if ('@'==tmp0.mail[i])   //验证输入中存在'.',并且有且只有一个'@'
                                at++;
                            if('.'==tmp0.mail[i])
                                dot++;
                        }
                        if((1==at)&&dot)
                            valid=true;
                        else
                            printf("Unavailable email address.Input again.\n");
                    }
                    printf("Which personal information would you like to amend?\n");
                    printf("Enter 1 to change password, 2 to change phone, 3 to change you mail,4 to return\n");
                    scanf("%3s",enter6);
                    fflush(stdin);
                    while(enter6[0]<'1'||enter6[0]>'4'||enter6[1]!='\0')
                    {
                        printf("Error.Please input again.\n");
                        scanf("%3s",enter6);
                        fflush(stdin);
                    }

                    tmp6=atoi(enter6);

                    break;
                }

            }

        }

        fwrite(&tmp0, sizeof(struct USER),1,infoPtr);

        fclose(infoPtr);
    }
}


void checkorder1()//用户查询订单
{
    struct ORDER tmp;
    int L,ch,i;
    FILE *checkPtr;
    checkPtr = fopen("order information.txt", "rb+");
    if (checkPtr  == NULL)
    {
        printf("Fail to open the file.\n");
        exit(1);
    }
    printf("History of purchased ticket as follow/n");
    printf("NAME               "" NO.   "" COMPANY"" ORIGIN"" DESTINATION "" DATE   "" BD TIME"
                   " SEAT"" CLASS              "" TYPE         "" PRICE  \n");
    while (!feof(checkPtr))
    {
        fread(&tmp,sizeof(struct ORDER),1,checkPtr); //从checkPtr指向的文件中读取大小为sizeof(struct TICKET)的结构tmp
        if (strcmp(tmp.ID,loginID)==0) {


            printf("%19s %6s %7s %6s %11s %7s %7s %4s %20s %13s %7d\n",tmp.person,tmp.num,tmp.comp,tmp.departure,tmp.destination,tmp.date,tmp.offtime,tmp.seat,tmp.level,tmp.type,tmp.price);

        }
        printf("All result is above./n");

        fclose(checkPtr);

    }
}


void register2(struct ADMIN *registered)//管理员注册
{
    FILE *admin;
    admin=fopen("administrator information.txt","r+");
    if(admin==NULL)
    {
        printf("Error! Please check that the file 'administrator.txt' exist.\n");
        exit(1);
    }
    int i,e;
    char enter[20];
    //------------ID-----------//
    struct ADMIN temp;
    char string[81];
    char space;
    printf("\nEnter your ID: (letters and numbers only, 6 to 10 characters)(Enter -1 to quit)\n");
    fflush(stdin);
    gets(enter);
    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
        return;
    while(fgets(string,81,admin)!=NULL)
    {
        fscanf(admin,"%s %s %s %s %s",temp.ID,temp.name,temp.comp,temp.password,temp.mail);
        if(strcmp(temp.ID,enter)==0)
        {
            printf("\nSorry. This ID has already been used. Please try another one.\n");
            printf("Enter your ID: (letters and numbers only, 6 to 10 characters)(Enter -1 to quit)\n");
            rewind(admin);
            fflush(stdin);
            gets(enter);
            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                return;
        }
    }
    for(i=0;i<strlen(enter);i++)
    {
        while(strlen(enter)<6||strlen(enter)>10||(isdigit(enter[i])==0&&isalpha(enter[i])==0))
        {
            printf("\nYour ID is illegal. Please try again.\n");
            printf("Enter your ID: (letters and numbers only, 6 to 10 characters)(Enter -1 to quit)\n");
            fflush(stdin);
            gets(enter);
            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                return;
        }
    }
    strcpy(registered->ID,enter);
    //---------company-----------//
    printf("\nSelect your company: (Enter -1 to quit)\n");
    printf("1.MU  2.CA  3.CZ  4.HU\n");
    gets(enter);
    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
        return;
    while(enter[0]<'1'||enter[0]>'4'||enter[1]!='\0'||enter[0]=='\0')
    {
        printf("\nYour selection is not identified. Please try again.\n");
        printf("Select your company: (Enter -1 to quit)\n");
        printf("1.MU  2.CA  3.CZ  4.HU\n");
        fflush(stdin);
        gets(enter);
        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
            return;
    }
    e=atoi(enter);
    switch(e)
    {
        case 1:
        {
            strcpy(registered->comp,"MU");
            break;
        }
        case 2:
        {
            strcpy(registered->comp,"CA");
            break;
        }
        case 3:
        {
            strcpy(registered->comp,"CZ");
            break;
        }
        case 4:
        {
            strcpy(registered->comp,"HU");
            break;
        }
    }
    //---------e-mail----------//
    printf("\nEnter your e-mail: (Enter -1 to quit)\n");
    fflush(stdin);
    gets(enter);
    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
        return;
    e=0;
    while(e!=2)
    {
        for(i=0;i<strlen(enter);i++)
        {
            if(enter[i]=='@'&&e==0)
                e++;
            if(enter[i]=='.'&&e==1)
                e++;
        }
        if(e!=2)
        {
            printf("\nYour e-mail is illegal. Please try again.\n");
            printf("Enter your e-mail: (Enter -1 to quit)\n");
            fflush(stdin);
            gets(enter);
            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                return;
            e=0;
        }
        else
        {
            strcpy(registered->mail,enter);
            break;
        }
    }
    //---------name---------//
    printf("\nEnter your name:(with no space in the middle) (Enter -1 to quit)\n");
    fflush(stdin);
    gets(enter);
    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
        return;
    e=1;
    while(e)
    {
        for(i=0;i<strlen(enter);i++)
        {
            if(enter[i]==' ')
                e=0;
        }
        if(e==0)
        {
            printf("\nPlease delete the space and try again.\n");
            printf("Enter your name: (with no space in the middle) (Enter -1 to quit)\n");
            fflush(stdin);
            gets(enter);
            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                return;
            e=1;
        }
        else
            e=0;
    }
    strcpy(registered->name,enter);
    //----------password-----------//
    char enter0[20];
    printf("\nEnter your password: (less than 9 digits)(Enter -1 to quit)\n");
    fflush(stdin);
    gets(enter);
    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
        return;
    printf("\nPlease enter your password again:(Enter -1 to quit)\n");
    fflush(stdin);
    gets(enter0);
    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
        return;
    while(strcmp(enter,enter0)!=0||strlen(enter)>9||strlen(enter0)>9)
    {
        printf("\nPlease ensure that your password is valid and try again.\n");
        printf("Enter your password: (less than 9 digits) (Enter -1 to quit)\n");
        fflush(stdin);
        gets(enter);
        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
            return;
        printf("\nPlease enter your password again:(Enter -1 to quit)\n");
        fflush(stdin);
        gets(enter0);
        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
            return;
    }
    strcpy(registered->password,enter);
    //-----------fprintf-----------//
    fseek(admin,0,SEEK_END);
    fprintf(admin,"\n%-10s %-10s %-3s %-4s %-10s\n",registered->ID,registered->name,registered->comp,registered->password,registered->mail);
    fclose(admin);
}

int login2(struct ADMIN *logged)//管理员登录
{
    FILE *log;
    log=fopen("administrator information.txt","r+");
    if(log==NULL)
    {
        printf("Error! Please check that the file 'administrator information.txt' exists.\n");
        exit(1);
    }
    char enter[20];
    char buf[NUMEL];
    struct ADMIN temp[NUMEL];
    temp[0].line=0;
    int e,i,j,k;
    //----------读行数----------//
    while((k=fgetc(log))!=EOF)
    {
        if(k=='\n')
            temp[0].line++;
    }
    rewind(log);
    //---------读取用户ID--------//
    printf("\nEnter your ID: (Enter -1 to quit)\n");
    fflush(stdin);
    gets(enter);
    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
        return 0;
    e=1;//初始条件
    while(e)
    {
        for(i=0;i<temp[0].line;i++)
        {
            fscanf(log,"%s %s %s %s %s",temp[i].ID,temp[i].name,temp[i].comp,temp[i].password,temp[i].mail);
            if(strcmp(enter,temp[i].ID)==0)//找到符合项，改变条件
            {
                e=0;
                j=i;
            }
        }
        if(e==1)//找不到 ID
        {
            printf("\nYour ID cannot be found. Please try again.\n");
            printf("Enter your ID: (Enter -1 to quit)\n");
            fflush(stdin);
            gets(enter);
            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                return 0;
        }
        else//找到了 ID //--------取得用户真实密码-------//
        {
            //--------获取用户输入---------//
            printf("\nEnter your password: (Enter -1 to quit)\n");
            fflush(stdin);
            gets(enter);
            if(enter[0]=='-'||enter[1]=='1'||enter[2]=='\0')
                return 0;
            while(strcmp(enter,temp[j].password)!=0)//密码与ID不符
            {
                printf("\nYour password is not correct. Please try again.\n");
                printf("Enter your password: (Enter -1 to quit)\n");
                fflush(stdin);
                gets(enter);
                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                    return 0;
            }
            strcpy(logged->ID,temp[j].ID);
            strcpy(logged->comp,temp[j].comp);
            return 1;
        }
    }
}

void checkorder2(struct ADMIN *logged)//管理员查看订单
{
    FILE *checkorder;
    checkorder=fopen("order information.txt","rb+");
    if(checkorder==NULL)
    {
        printf("Error! Please check that the file 'order information.txt' exists.\n");
        exit(1);
    }
    char string[81];
    char enter[20];

    int e=0,i,cnt=0,j,k,n=0,m;//e用于存储输入，ijk用于循环，m
    struct ORDER order[NUMEL];//储存所有订单内容
    struct ORDER order1[NUMEL];//管理员所在公司的订单
    struct ORDER order2[NUMEL];//排序后的订单
    while (!feof(checkorder))
    {
        fread(&order[cnt],sizeof(struct ADMIN),1,checkorder);
        if (strcmp(order[cnt].comp,logged->comp)==0)
        {
            cnt++;
        }

    }
    fclose(checkorder);
    printf("\nWhat would you like to do? (Enter -1 to exit)\n");//管理员选择1.查看所有订单  2.统计订单信息
    printf("1.Check All Users' Orders of Your Company 2.Count Information of Users' Orders\n");
    gets(enter);
    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
        return;
    while(enter[0]<'1'||enter[0]>'2'||enter[1]!='\0')
    {
        printf("\nYour selection is not identified. Please try again.\n");
        printf("What would you like to do? (Enter -1 to exit)\n");
        printf("1.Check All Users' Orders  2.Count Information of Users' Orders\n");
        fflush(stdin);
        gets(enter);
        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
            return;
    }
    e=atoi(enter);
    switch(e)
    {
        case 1:
        {
            printf("\nAll orders of flights of your company:\n");
            for(i=0;i<cnt;i++)
            {
                printf("%-10s %-15s %-7s %-3s %-3s %-3s %-9s %-6s %-6s %-14s %-4s %-10s %d\n",order[i].ID,order[i].person,order[i].num,order[i].comp,order[i].departure,order[i].destination,order[i].date,order[i].offtime,order[i].flytime,order[i].level,order[i].seat,order[i].type,order[i].bought);
            }
            break;
        }
        case 2:
        {
            /*1.本公司还未起飞的航班——按照已购票人数排序*/
            printf("\n1.The flights of your company that haven't taken off:\n");
            //----------筛选出管理员所属公司的订单---------// ---order1
            /*for(i=0;i<cnt;i++)
            {
                if(strcmp(order[i].comp,logged->comp)==0)
                {
                    strcpy(order1[n].ID,order[i].ID);
                    strcpy(order1[n].person,order[i].person);
                    strcpy(order1[n].num,order[i].num);
                    strcpy(order1[n].comp,order[i].comp);
                    strcpy(order1[n].departure,order[i].departure);
                    strcpy(order1[n].destination,order[i].destination);
                    strcpy(order1[n].date,order[i].date);
                    strcpy(order1[n].offtime,order[i].offtime);
                    strcpy(order1[n].flytime,order[i].flytime);
                    strcpy(order1[n].level,order[i].level);
                    strcpy(order1[n].seat,order[i].seat);
                    strcpy(order1[n].type,order[i].type);
                    order1[n].bought=order[i].bought;
                    n++;
                }
            }*/
            //----------对order1（含n个元素）根据已购票人数进行排序---------// ——要先求出已购票人数
            struct BOUGHTNUM
            {
                char flightnum[10];
                int boughtnum;
            }temp[NUMEL];
            n=cnt;
            strcpy(temp[0].flightnum,order[0].num);
            k=1;
            e=1;
            for(i=1;i<n;i++)
            {
                for(j=0;j<i-1;j++)
                {
                    if(strcmp(order[i].num,temp[j].flightnum)==0)
                    {
                        k=0;
                        break;
                    }
                }
                if(k==1)
                {
                    strcpy(temp[e].flightnum,order[i].num);
                    e++;
                }
                else
                    k=1;
            }
            /*得到了不重复的航班结构 temp，含e项*/
            /*还需要对比order1（含n项）才能得到已购票人数*/
            k=0;
            for(i=0;i<e;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(strcmp(temp[i].flightnum,order[j].num)==0&&order[j].bought==1)
                        k++;
                }
                temp[i].boughtnum=k;
                k=0;
            }
            /*对temp结构，每个不重复的航班都有了已购票人数boughtnum可以比较*/
            //排序//
            for(i=0;i<n;i++)
            {
                for(j=1;j<n;j++)
                {
                    if(temp[i].boughtnum<temp[j].boughtnum)
                    {
                        k=temp[j].boughtnum;
                        temp[j].boughtnum=temp[i].boughtnum;
                        temp[i].boughtnum=k;
                        strcpy(string,temp[j].flightnum);
                        strcpy(temp[j].flightnum,temp[i].flightnum);
                        strcpy(temp[i].flightnum,string);
                    }
                }
            }
            //----------输出排序后的结果-----------//
            for(i=0;i<e;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(strcmp(temp[i].flightnum,order[n].num)==0)
                    {
                        printf("%-10s %-15s %-10s %-5s %-5s %-5s %-10d %-7s %-7s %-15s %-5s %-12s\n",order[n].ID,order[n].person,order[n].num,order[n].comp,order[n].departure,order[n].destination,order[n].date,order[n].offtime,order[n].flytime,order[n].level,order[n].seat,order[n].type);
                        break;
                    }
                }
            }

            /*至于上座率和总票价收入排序，和已购票人数同理，在此因为时间原因……不再写下去*/
        }
    }
}

void manageflight(struct ADMIN *logged)//管理员管理航班
{
    FILE *infile;
    infile=fopen("aviation information.txt","r+");
    if(infile==NULL)
    {
        printf("Error! Please check that the file 'aviation information.txt' currently exists.\n");
        exit(1);
    }
    struct FLIGHT flight;
    struct FLIGHT flight0[NUMEL];//储存所有航班信息
    char enter[20];
    int e,i,j,m,n;//e用于switch，ij用于循环，m用于航班号重复判定，n用于写入算法代替goto
    e=0;
    while((i=fgetc(infile))!=EOF)//计算总行数，用于for循环+fscanf，以及后面fprintf的指针位置确定
    {
        if(i=='\n')
            e++;
    }
    j=e;
    rewind(infile);
    for(i=0;i<j;i++)
    {
        fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",flight0[i].num,flight0[i].comp,flight0[i].departure,flight0[i].destination,flight0[i].offtime,flight0[i].flytime,flight0[i].level1,flight0[i].total1,flight0[i].num1,flight0[i].price1,flight0[i].level2,flight0[i].num2,flight0[i].total2,flight0[i].price2,flight0[i].type,flight0[i].punctuality,flight0[i].pilot1,flight0[i].pilot2);
    }
    printf("\nWhat would you like to do?\n(Enter 1 to check flights, 2 to add a new flight, 3 to return.)\n");
    gets(enter);
    while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
    {
        printf("\nYour selection is not identified. Please try again.\n");
        printf("What would you like to do?\n(Enter 1 to check flights, 2 to add a new flight, 3 to return.)\n");
        fflush(stdin);
        gets(enter);
    }
    e=atoi(enter);
    while(e!=3)
    {
        switch(e)
        {
            case 1://查询航班
            {
                i=1;
                //-----------根据航班信息，根据公司名输出特定航班------------//
                printf("\nAvailable flights at present:\n");
                printf("FlightNum   Company   Departure   Destination   OffTime   FlyingTime   Level1------Total   Seats   Price   Level2------Total   Seats   Price   TypeOfPlane   Punctuality   Pilot1   Pilot2\n");
                for(i=0;i<j;i++)
                {
                    if(strcmp(flight0[i].comp,logged->comp)==0)
                        printf(" %-13s %-10s %-11s %-10s %-10s %-8s %-15s %-5s %-7s %s %-15s %-5s %-9s %-8s %-14s %-12s %-6s %-5s\n",flight0[i].num,flight0[i].comp,flight0[i].departure,flight0[i].destination,flight0[i].offtime,flight0[i].flytime,flight0[i].level1,flight0[i].total1,flight0[i].num1,flight0[i].price1,flight0[i].level2,flight0[i].total2,flight0[i].num2,flight0[i].price2,flight0[i].type,flight0[i].punctuality,flight0[i].pilot1,flight0[i].pilot2);
                }
                printf("\nThe results are listed above.\n");
                printf("What would you like to do?\n(Enter 1 to check flights, 2 to add a new flight, 3 to return.)\n");
                gets(enter);
                while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                {
                    printf("\nYour selection is not identified. Please try again.\n");
                    printf("What would you like to do?\n(Enter 1 to check flights, 2 to add a new flight, 3 to return.)\n");
                    fflush(stdin);
                    gets(enter);
                }
                e=atoi(enter);
                break;
            }
            case 2://添加航班
            {
                //----------先把前两位公司写上-----------//
                strcpy(flight.num,logged->comp);
                strcpy(flight.level1,"first-class");
                strcpy(flight.level2,"tourist-class");
                strcpy(flight.comp,logged->comp);
                //-----------航班号----------//
                printf("\nEnter the flight number(eg: 1234): (Enter -1 to exit)\n");//航班号——要求：2个大写字母+4个数字
                fflush(stdin);
                gets(enter);
                m=0;//用于航班号重复性判定
                n=0;//用于取代goto
                while(enter[0]!='-'||enter[1]!='1'||enter[2]!='\0')
                {
                    while(enter[0]<'1'||enter[0]>'9'||enter[1]<'0'||enter[1]>'9'||enter[2]<'0'||enter[2]>'9'||enter[3]<'0'||enter[3]>'9'||enter[4]!='\0')
                    {
                        printf("\nThe flight number is invalid. Please try again.\n");
                        printf("Enter the flight number(eg: 1234): (Enter -1 to exit)\n");
                        fflush(stdin);
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                        {
                            n=1;
                            break;
                        }
                    }
                    if(n==1)
                        break;
                    else
                        strcat(flight.num,enter);
                    //----------始发地---------//
                    printf("\nSelect the departure: (Enter -1 to exit)\n");
                    printf("1.GZ  2.BJ  3.DL  4.SH\n");
                    gets(enter);
                    while(enter[0]!='-'||enter[1]!='1'||enter[2]!='\0')
                    {
                        while(enter[0]<'1'||enter[0]>'4'||enter[1]!='\0'||enter[0]=='\0')
                        {
                            printf("\nYour selection is not identified. Please try again.\n");
                            printf("Select the departure: (Enter -1 to exit)\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        e=atoi(enter);
                        switch(e)
                        {
                            case 1:
                            {
                                strcpy(flight.departure,"GZ");
                                break;
                            }
                            case 2:
                            {
                                strcpy(flight.departure,"BJ");
                                break;
                            }
                            case 3:
                            {
                                strcpy(flight.departure,"DL");
                                break;
                            }
                            case 4:
                            {
                                strcpy(flight.departure,"SH");
                                break;
                            }
                        }
                        //----------目的地----------//
                        printf("\nSelect the destination: (Enter -1 to exit)\n");
                        switch(e)
                        {
                            case 1:
                            {
                                printf("1.BJ  2.DL  3.SH\n");
                                fflush(stdin);
                                gets(enter);
                                while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                {
                                    printf("\nYour selection is not identified. Please try again.\n");
                                    printf("Select the departure: (Enter -1 to exit)\n");
                                    fflush(stdin);
                                    gets(enter);
                                    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                    {
                                        n=1;
                                        break;
                                    }
                                }
                                if(n==1)
                                    break;
                                e=atoi(enter);
                                switch(e)
                                {
                                    case 1:
                                    {
                                        strcpy(flight.destination,"BJ");
                                        break;
                                    }
                                    case 2:
                                    {
                                        strcpy(flight.destination,"DL");
                                        break;
                                    }
                                    case 3:
                                    {
                                        strcpy(flight.destination,"SH");
                                        break;
                                    }
                                }
                                break;
                            }
                            case 2:
                            {
                                printf("1.GZ  2.DL  3.SH\n");
                                fflush(stdin);
                                gets(enter);
                                while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                {
                                    printf("\nYour selection is not identified. Please try again.\n");
                                    printf("Select the departure: (Enter -1 to exit)\n");
                                    fflush(stdin);
                                    gets(enter);
                                    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                    {
                                        n=1;
                                        break;
                                    }
                                }
                                if(n==1)
                                    break;
                                e=atoi(enter);
                                switch(e)
                                {
                                    case 1:
                                    {
                                        strcpy(flight.destination,"GZ");
                                        break;
                                    }
                                    case 2:
                                    {
                                        strcpy(flight.destination,"DL");
                                        break;
                                    }
                                    case 3:
                                    {
                                        strcpy(flight.destination,"SH");
                                        break;
                                    }
                                }
                                break;
                            }
                            case 3:
                            {
                                printf("1.GZ  2.BJ  3.SH\n");
                                fflush(stdin);
                                gets(enter);
                                while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                {
                                    printf("\nYour selection is not identified. Please try again.\n");
                                    printf("Select the departure: (Enter -1 to exit)\n");
                                    fflush(stdin);
                                    gets(enter);
                                    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                    {
                                        n=1;
                                        break;
                                    }
                                }
                                if(n==1)
                                    break;
                                e=atoi(enter);
                                switch(e)
                                {
                                    case 1:
                                    {
                                        strcpy(flight.destination,"GZ");
                                        break;
                                    }
                                    case 2:
                                    {
                                        strcpy(flight.destination,"BJ");
                                        break;
                                    }
                                    case 3:
                                    {
                                        strcpy(flight.destination,"SH");
                                        break;
                                    }
                                }
                                break;
                            }
                            case 4:
                            {
                                printf("1.GZ  2.BJ  3.DL\n");
                                fflush(stdin);
                                gets(enter);
                                while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                {
                                    printf("\nYour selection is not identified. Please try again.\n");
                                    printf("Select the departure: (Enter -1 to exit)\n");
                                    fflush(stdin);
                                    gets(enter);
                                    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                    {
                                        n=1;
                                        break;
                                    }
                                }
                                if(n==1)
                                    break;
                                e=atoi(enter);
                                switch(e)
                                {
                                    case 1:
                                    {
                                        strcpy(flight.destination,"GZ");
                                        break;
                                    }
                                    case 2:
                                    {
                                        strcpy(flight.destination,"BJ");
                                        break;
                                    }
                                    case 3:
                                    {
                                        strcpy(flight.destination,"DL");
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        //------------起飞时间----------//
                        printf("\nEnter the departure time: (eg: 08:20)(Enter -1 to exit)\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        while(enter[0]<'0'||enter[0]>'2'||enter[1]<'0'||enter[1]>'9'||enter[2]!=':'||enter[3]<'0'||enter[3]>'5'||enter[4]<'0'||enter[4]>'9'||(enter[0]=='2'&&enter[1]>'3')||enter[5]!='\0')
                        {
                            printf("\nThe departure time is invalid. Please try again.\n");
                            printf("Enter the departure time: (eg: 08:20)\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        strcpy(flight.offtime,enter);
                        //------------预计飞行时间-----------//
                        printf("\nEnter the anticipated flying time: (eg: 04:00)(Enter -1 to exit)\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        while(enter[0]<'0'||enter[0]>'2'||enter[1]<'0'||enter[1]>'9'||enter[2]!=':'||enter[3]<'0'||enter[3]>'5'||enter[4]<'0'||enter[4]>'9'||(enter[0]=='2'&&enter[1]>'3')||enter[5]!='\0')
                        {
                            printf("\nThe flying time is invalid. Please try again.\n");
                            printf("Enter the anticipated flying time: (eg: 04:00)(Enter -1 to exit)\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        else
                            strcpy(flight.flytime,enter);
                        //--------头等舱价位--------//
                        printf("\nEnter the unit price of the first-class cabin(￥): (Enter -1 to exit)\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        e=1;
                        while(e)
                        {
                            for(i=0;i<strlen(enter);i++)
                            {
                                if(enter[0]<'1'||enter[0]>'9')
                                    e=0;
                                else if(enter[i]<'0'||enter[i]>'9')
                                    e=0;
                            }
                            if(e==0)
                            {
                                printf("\nThe unit price is invalid. Please try again.\n");
                                printf("Enter the unit price of the first-class cabin(￥): (Enter -1 to exit)\n");
                                fflush(stdin);
                                gets(enter);
                                e=1;
                                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                {
                                    n=1;
                                    break;
                                }
                            }
                            else
                                e=0;
                        }
                        if(n==1)
                            break;
                        else
                            strcpy(flight.price1,enter);
                        //----------头等舱座位号和总位数----------//
                        printf("\nSelect the seats number of first-class cabin: (Enter -1 to exit)\n");
                        printf("1.1A-2L  2.1A-3L\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        while(enter[0]<'1'||enter[0]>'2'||enter[1]!='\0')
                        {
                            printf("\nYour selection is not identified. Please try again.\n");
                            printf("Select the seats number of first-class cabin: (Enter -1 to exit)\n");
                            printf("1.1A-2L  2.1A-3L\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        e=atoi(enter);
                        switch(e)
                        {
                            case 1:
                            {
                                strcpy(flight.num1,"1A-2L");
                                strcpy(flight.total1,"8");
                                break;
                            }
                            case 2:
                            {
                                strcpy(flight.num1,"1A-3L");
                                strcpy(flight.total1,"12");
                                break;
                            }
                        }
                        //----------经济舱票价---------//
                        printf("\nEnter the unit price of tourist-class cabin(￥): (Enter -1 to exit)\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        e=1;
                        while(e)
                        {
                            for(i=0;i<strlen(enter);i++)
                            {
                                if(enter[0]<'1'||enter[0]>'9')
                                    e=0;
                                else if(enter[i]<'0'||enter[i]>'9')
                                    e=0;
                            }
                            if(e==0)
                            {
                                printf("\nThe unit price is invalid. Please try again.\n");
                                printf("Enter the unit price of the first-class cabin(￥): (Enter -1 to exit)\n");
                                fflush(stdin);
                                gets(enter);
                                e=1;
                                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                {
                                    n=1;
                                    break;
                                }
                            }
                            else
                                e=0;
                        }
                        if(n==1)
                            break;
                        else
                            strcpy(flight.price2,enter);
                        //----------经济舱座位号和总位数----------//
                        printf("\nSelect the seats number of first-class cabin: (Enter -1 to exit)\n");
                        printf("1.11A-35L  2.11A-40L\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        while(enter[0]<'1'||enter[0]>'2'||enter[1]!='\0')
                        {
                            printf("\nYour selection is not identified. Please try again.\n");
                            printf("Select the seats number of tourist-class cabin: (Enter -1 to exit)\n");
                            printf("1.11A-35L  2.11A-40L\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        e=atoi(enter);
                        switch(e)
                        {
                            case 1:
                            {
                                strcpy(flight.num2,"11A-35L");
                                strcpy(flight.total2,"150");
                                break;
                            }
                            case 2:
                            {
                                strcpy(flight.num2,"11A-40L");
                                strcpy(flight.total2,"180");
                            }
                        }
                        //----------机型----------//
                        printf("\nSelect the type of plane: (Enter -1 to exit)\n");
                        printf("1.Boeing737  2.Boeing747\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        while(enter[0]<'1'||enter[0]>'2'||enter[1]!='\0')
                        {
                            printf("\nYour selection is not identified.\n");
                            printf("Select the type of plane: (Enter -1 to exit)\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        e=atoi(enter);
                        switch(e)
                        {
                            case 1:
                            {
                                strcat(flight.type,"Boeing737");
                                break;
                            }
                            default:
                            {
                                strcat(flight.type,"Boeing747");
                                break;
                            }
                        }
                        //----------准点率---------//
                        printf("\nEnter the punctuality rate: (percentage--eg: '80.0%') (Enter -1 to exit)\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        while(enter[0]<'1'||enter[0]>'9'||enter[1]<'0'||enter[1]>'9'||enter[2]!='.'||enter[3]<'0'||enter[3]>'9'||enter[4]!='%')
                        {
                            printf("\nThe punctuality rate is invalid. Please try again.\n");
                            printf("Enter the punctuality rate: (percentage--eg: '80.0%') (Enter -1 to exit)\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        else
                            strcpy(flight.punctuality,enter);
                        //----------飞行员1---------//
                        printf("\nEnter the pilot No.1: (eg: A1/C9) (Enter -1 to exit)\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        while(enter[0]<'A'||enter[0]>'Z'||enter[1]<'1'||enter[1]>'9'||enter[2]!='\0')
                        {
                            printf("\nThe pilot number is not valid. Please try again.\n");
                            printf("Enter the pilot No.1: (eg: A2/C4)\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        else
                            strcpy(flight.pilot1,enter);
                        //----------飞行员2---------//
                        printf("\nEnter the pilot No.2: (eg: A1/C9) (Repetition not allowed) (Enter -1 to exit)\n");
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            break;
                        while(strcmp(enter,flight.pilot1)==0||enter[0]<'A'||enter[0]>'Z'||enter[1]<'1'||enter[1]>'9'||enter[2]!='\0')
                        {
                            printf("\nThe pilot number is not valid. Please try again.\n");
                            printf("Enter the pilot No.1: (eg: A2/C4) (Enter -1 to exit)\n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        else
                            strcpy(flight.pilot2,enter);
                        //-----------可修改和取消----------//
                        printf("\nWhat would you like to do?\n");
                        printf("1.Make changes  2.Quit 3.Release\n");
                        fflush(stdin);
                        gets(enter);
                        while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                        {
                            printf("\nYour selection is not identified. Please try again.\n");
                            printf("What would you like to do?\n");
                            printf("1.Make changes  2.Quit \n");
                            fflush(stdin);
                            gets(enter);
                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            {
                                n=1;
                                break;
                            }
                        }
                        if(n==1)
                            break;
                        e=atoi(enter);
                        while(e!=2)
                        {
                            printf("\nWhat would you like to change? (Enter -1 to quit)\n");
                            printf("1.Flight Number  2.Departure&Destination  3.Offtime  4.Flytime\n5.SeatNum of First-class Cabin  6.SeatNum of Tourist-class Cabin  7.Price1  8.Price2\n9.Type  10.Punctuality  11.Pilot1  12.Pilot2\n");
                            gets(enter);
                            while(enter[0]!='-'||enter[1]!='1'||enter[2]!='\0')
                            {
                                e=atoi(enter);
                                while(e<1||e>12)
                                {
                                    printf("\nYour selection is not identified. Please try again.\n");
                                    printf("\nWhat would you like to change? (Enter -1 to quit)\n");
                                    printf("1.Flight Number 2.Departure&Destination 3.Offtime 4.Flytime 5.SeatNum of First-class Cabin 6.SeatNum of Tourist-class Cabin\n7.Price1 8.Price2 9.Type 10.Punctuality 11.Pilot1 12.Pilot2\n");
                                    fflush(stdin);
                                    gets(enter);
                                    if(enter[0]=='-'&&enter[1]!='1'&&enter[2]=='\0')
                                        break;
                                }
                                switch(e)
                                {
                                    case 1:
                                    {
                                        printf("\nEnter the flight number(eg: 1234): (Enter -1 to exit)\n");
                                        fflush(stdin);
                                        gets(enter);
                                        while(enter[0]<'1'||enter[0]>'9'||enter[1]<'0'||enter[1]>'9'||enter[2]<'0'||enter[2]>'9'||enter[3]<'0'||enter[3]>'9'||enter[4]!='\0')
                                        {
                                            printf("\nThe flight number is invalid. Please try again.\n");
                                            printf("Enter the flight number(eg: 1234): (Enter -1 to exit)\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        else
                                        {
                                            memset(flight.num,0,strlen(flight.num));
                                            strcpy(flight.num,logged->comp);
                                            strcat(flight.num,enter);
                                        }
                                        break;
                                    }
                                    case 2:
                                    {
                                        printf("\nSelect the departure: (Enter -1 to exit)\n");
                                        printf("1.GZ  2.BJ  3.DL  4.SH\n");
                                        gets(enter);
                                        while(enter[0]!='-'||enter[1]!='1'||enter[2]!='\0')
                                        {
                                            while(enter[0]<'1'||enter[0]>'4'||enter[1]!='\0'||enter[0]=='\0')
                                            {
                                                printf("\nYour selection is not identified. Please try again.\n");
                                                printf("Select the departure: (Enter -1 to exit)\n");
                                                fflush(stdin);
                                                gets(enter);
                                                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                                {
                                                    n=1;
                                                    break;
                                                }
                                            }
                                            if(n==1)
                                                break;
                                            e=atoi(enter);
                                            switch(e)
                                            {
                                                case 1:
                                                {
                                                    strcpy(flight.departure,"GZ");
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    strcpy(flight.departure,"BJ");
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    strcpy(flight.departure,"DL");
                                                    break;
                                                }
                                                default:
                                                {
                                                    strcpy(flight.departure,"SH");
                                                    break;
                                                }
                                            }
                                            //----------目的地----------//
                                            printf("\nSelect the destination: (Enter -1 to exit)\n");
                                            switch(e)
                                            {
                                                case 1:
                                                {
                                                    printf("1.BJ  2.DL  3.SH\n");
                                                    fflush(stdin);
                                                    gets(enter);
                                                    while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                                    {
                                                        printf("\nYour selection is not identified. Please try again.\n");
                                                        printf("Select the departure: (Enter -1 to exit)\n");
                                                        fflush(stdin);
                                                        gets(enter);
                                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                                        {
                                                            n=1;
                                                            break;
                                                        }
                                                    }
                                                    if(n==1)
                                                        break;
                                                    e=atoi(enter);
                                                    switch(e)
                                                    {
                                                        case 1:
                                                        {
                                                            strcpy(flight.destination,"BJ");
                                                            break;
                                                        }
                                                        case 2:
                                                        {
                                                            strcpy(flight.destination,"DL");
                                                            break;
                                                        }
                                                        case 3:
                                                        {
                                                            strcpy(flight.destination,"SH");
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    printf("1.GZ  2.DL  3.SH\n");
                                                    fflush(stdin);
                                                    gets(enter);
                                                    while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                                    {
                                                        printf("\nYour selection is not identified. Please try again.\n");
                                                        printf("Select the departure: (Enter -1 to exit)\n");
                                                        fflush(stdin);
                                                        gets(enter);
                                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                                        {
                                                            n=1;
                                                            break;
                                                        }
                                                    }
                                                    if(n==1)
                                                        break;
                                                    e=atoi(enter);
                                                    switch(e)
                                                    {
                                                        case 1:
                                                        {
                                                            strcpy(flight.destination,"GZ");
                                                            break;
                                                        }
                                                        case 2:
                                                        {
                                                            strcpy(flight.destination,"DL");
                                                            break;
                                                        }
                                                        case 3:
                                                        {
                                                            strcpy(flight.destination,"SH");
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    printf("1.GZ  2.BJ  3.SH\n");
                                                    fflush(stdin);
                                                    gets(enter);
                                                    while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                                    {
                                                        printf("\nYour selection is not identified. Please try again.\n");
                                                        printf("Select the departure: (Enter -1 to exit)\n");
                                                        fflush(stdin);
                                                        gets(enter);
                                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                                        {
                                                            n=1;
                                                            break;
                                                        }
                                                    }
                                                    if(n==1)
                                                        break;
                                                    e=atoi(enter);
                                                    switch(e)
                                                    {
                                                        case 1:
                                                        {
                                                            strcpy(flight.destination,"GZ");
                                                            break;
                                                        }
                                                        case 2:
                                                        {
                                                            strcpy(flight.destination,"BJ");
                                                            break;
                                                        }
                                                        case 3:
                                                        {
                                                            strcpy(flight.destination,"SH");
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                                default:
                                                {
                                                    printf("1.GZ  2.BJ  3.DL\n");
                                                    fflush(stdin);
                                                    gets(enter);
                                                    while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
                                                    {
                                                        printf("\nYour selection is not identified. Please try again.\n");
                                                        printf("Select the departure: (Enter -1 to exit)\n");
                                                        fflush(stdin);
                                                        gets(enter);
                                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                                        {
                                                            n=1;
                                                            break;
                                                        }
                                                    }
                                                    if(n==1)
                                                        break;
                                                    e=atoi(enter);
                                                    switch(e)
                                                    {
                                                        case 1:
                                                        {
                                                            strcpy(flight.destination,"GZ");
                                                            break;
                                                        }
                                                        case 2:
                                                        {
                                                            strcpy(flight.destination,"BJ");
                                                            break;
                                                        }
                                                        case 3:
                                                        {
                                                            strcpy(flight.destination,"DL");
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                }
                                            }
                                        }
                                        break;
                                    }
                                        //-----------Offtime-----------//
                                    case 3:
                                    {
                                        printf("\nEnter the departure time: (eg: 08:20)(Enter -1 to exit)\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        while(enter[0]<'0'||enter[0]>'2'||enter[1]<'0'||enter[1]>'9'||enter[2]!=':'||enter[3]<'0'||enter[3]>'5'||enter[4]<'0'||enter[4]>'9'||(enter[0]=='2'&&enter[1]>'3')||enter[5]!='\0')
                                        {
                                            printf("\nThe departure time is invalid. Please try again.\n");
                                            printf("Enter the departure time: (eg: 08:20)\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        else
                                            strcpy(flight.offtime,enter);
                                        break;
                                    }
                                        //-----------Flytime-----------//
                                    case 4:
                                    {
                                        printf("\nEnter the anticipated flying time: (eg: 04:00)(Enter -1 to exit)\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        while(enter[0]<'0'||enter[0]>'2'||enter[1]<'0'||enter[1]>'9'||enter[2]!=':'||enter[3]<'0'||enter[3]>'5'||enter[4]<'0'||enter[4]>'9'||(enter[0]=='2'&&enter[1]>'3')||enter[5]!='\0')
                                        {
                                            printf("\nThe flying time is invalid. Please try again.\n");
                                            printf("Enter the anticipated flying time: (eg: 04:00)(Enter -1 to exit)\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        else
                                            strcpy(flight.flytime,enter);
                                        break;
                                    }
                                        //-----------SeatNum of FIrst-Class-----------//
                                    case 5:
                                    {
                                        printf("\nSelect the seats number of first-class cabin: (Enter -1 to exit)\n");
                                        printf("1.1A-2L  2.1A-3L\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        while(enter[0]<'1'||enter[0]>'2'||enter[1]!='\0')
                                        {
                                            printf("\nYour selection is not identified. Please try again.\n");
                                            printf("Select the seats number of first-class cabin: (Enter -1 to exit)\n");
                                            printf("1.1A-2L  2.1A-3L\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        e=atoi(enter);
                                        switch(e)
                                        {
                                            case 1:
                                            {
                                                strcpy(flight.num1,"1A-2L");
                                                strcpy(flight.total1,"8");
                                                break;
                                            }
                                            default:
                                            {
                                                strcpy(flight.num1,"1A-3L");
                                                strcpy(flight.total1,"12");
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                        //-----------SeatNum of Tour Class------------//
                                    case 6:
                                    {
                                        printf("\nSelect the seats number of first-class cabin: (Enter -1 to exit)\n");
                                        printf("1.11A-35L  2.11A-40L\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        while(enter[0]<'1'||enter[0]>'2'||enter[1]!='\0')
                                        {
                                            printf("\nYour selection is not identified. Please try again.\n");
                                            printf("Select the seats number of tourist-class cabin: (Enter -1 to exit)\n");
                                            printf("1.11A-35L  2.11A-40L\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        e=atoi(enter);
                                        switch(e)
                                        {
                                            case 1:
                                            {
                                                strcpy(flight.num2,"11A-35L");
                                                strcpy(flight.total2,"150");
                                                break;
                                            }
                                            case 2:
                                            {
                                                strcpy(flight.num2,"11A-40L");
                                                strcpy(flight.total2,"180");
                                            }
                                        }
                                        break;
                                    }
                                        //-----------Price1----------//
                                    case 7:
                                    {
                                        printf("\nEnter the unit price of the first-class cabin(￥): (Enter -1 to exit)\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        e=1;
                                        while(e)
                                        {
                                            for(i=0;i<strlen(enter);i++)
                                            {
                                                if(enter[0]<'1'||enter[0]>'9')
                                                    e=0;
                                                else if(enter[i]<'0'||enter[i]>'9')
                                                    e=0;
                                            }
                                            if(e==0)
                                            {
                                                printf("\nThe unit price is invalid. Please try again.\n");
                                                printf("Enter the unit price of the first-class cabin(￥): (Enter -1 to exit)\n");
                                                fflush(stdin);
                                                gets(enter);
                                                e=1;
                                                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                                {
                                                    n=1;
                                                    break;
                                                }
                                            }
                                            else
                                                e=0;
                                        }
                                        if(n==1)
                                            break;
                                        else
                                            strcpy(flight.price1,enter);
                                        break;
                                    }
                                        //-----------Price2----------//
                                    case 8:
                                    {
                                        printf("\nEnter the unit price of tourist-class cabin(￥): (Enter -1 to exit)\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        e=1;
                                        while(e)
                                        {
                                            for(i=0;i<strlen(enter);i++)
                                            {
                                                if(enter[0]<'1'||enter[0]>'9')
                                                    e=0;
                                                else if(enter[i]<'0'||enter[i]>'9')
                                                    e=0;
                                            }
                                            if(e==0)
                                            {
                                                printf("\nThe unit price is invalid. Please try again.\n");
                                                printf("Enter the unit price of the first-class cabin(￥): (Enter -1 to exit)\n");
                                                fflush(stdin);
                                                gets(enter);
                                                e=1;
                                                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                                {
                                                    n=1;
                                                    break;
                                                }
                                            }
                                            else
                                                e=0;
                                        }
                                        if(n==1)
                                            break;
                                        else
                                            strcpy(flight.price2,enter);
                                        break;
                                    }
                                        //-----------Type---------//
                                    case 9:
                                    {
                                        printf("\nSelect the type of plane: (Enter -1 to exit)\n");
                                        printf("1.Boeing737  2.Boeing747\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        while(enter[0]<'1'||enter[0]>'2'||enter[1]!='\0')
                                        {
                                            printf("\nYour selection is not identified.\n");
                                            printf("Select the type of plane: (Enter -1 to exit)\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        e=atoi(enter);
                                        switch(e)
                                        {
                                            case 1:
                                            {
                                                strcat(flight.type,"Boeing737");
                                                break;
                                            }
                                            case 2:
                                            {
                                                strcat(flight.type,"Boeing747");
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                        //----------Punctuality---------//
                                    case 10:
                                    {
                                        printf("\nEnter the punctuality rate: (percentage--eg: '80.0%') (Enter -1 to exit)\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        while(enter[0]<'1'||enter[0]>'9'||enter[1]<'0'||enter[1]>'9'||enter[2]!='.'||enter[3]<'0'||enter[3]>'9'||enter[4]!='%')
                                        {
                                            printf("\nThe punctuality rate is invalid. Please try again.\n");
                                            printf("Enter the punctuality rate: (percentage--eg: '80.0%') (Enter -1 to exit)\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        else
                                            strcpy(flight.punctuality,enter);
                                        break;
                                    }
                                        //----------Pilot1----------//
                                    case 11:
                                    {
                                        printf("\nEnter the pilot No.1: (eg: A1/C9) (Enter -1 to exit)\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        while(enter[0]<'A'||enter[0]>'Z'||enter[1]<'1'||enter[1]>'9'||enter[2]!='\0'||strcmp(enter,flight.pilot1)==0||strcmp(enter,flight.pilot2)==0)
                                        {
                                            printf("\nThe pilot number is not valid. Please try again.\n");
                                            printf("Enter the pilot No.1: (eg: A2/C4)\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        else
                                            strcpy(flight.pilot1,enter);
                                        break;
                                    }
                                        //----------Pilot2---------//
                                    default:
                                    {
                                        printf("\nEnter the pilot No.2: (eg: A1/C9) (Repetition not allowed) (Enter -1 to exit)\n");
                                        gets(enter);
                                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            break;
                                        while(strcmp(enter,flight.pilot1)==0||enter[0]<'A'||enter[0]>'Z'||enter[1]<'1'||enter[1]>'9'||enter[2]!='\0')
                                        {
                                            printf("\nThe pilot number is not valid. Please try again.\n");
                                            printf("Enter the pilot No.1: (eg: A2/C4) (Enter -1 to exit)\n");
                                            fflush(stdin);
                                            gets(enter);
                                            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                                            {
                                                n=1;
                                                break;
                                            }
                                        }
                                        if(n==1)
                                            break;
                                        else
                                            strcpy(flight.pilot2,enter);
                                    }
                                }
                                printf("\nWhat would you like to change? (Enter -1 to quit)\n");
                                printf("1.Flight Number 2.Departure&Destination 3.Offtime 4.Flytime 5.SeatNum of First-class Cabin 6.SeatNum of Tourist-class Cabin\n7.Price1 8.Price2 9.Type 10.Punctuality 11.Pilot1 12.Pilot2\n");
                                fflush(stdin);
                                gets(enter);
                            }
                            if(n==1)
                                break;
                            //-----------保存到航班表---------//
                            if(e==3)
                                break;
                            fseek(infile,0,SEEK_END);
                            fprintf(infile,"\n%-6s %-2s %-2s %-2s %-5s %-5s %-11s %-2s %-5s %-4s %-13s %-7s %-3s %-4s %-9s %-5s %-2s %-2s",flight.num,flight.comp,flight.departure,flight.destination,flight.offtime,flight.flytime,flight.level1,flight.total1,flight.num1,flight.price1,flight.level2,flight.num2,flight.total2,flight.price2,flight.type,flight.punctuality,flight.pilot1,flight.pilot2);
                            fclose(infile);
                            break;
                        }
                        break;
                    }
                }
                break;
            }
        }
        printf("\nWhat would you like to do?\n(Enter 1 to check flights, 2 to add a new flight, 3 to return.)\n");//用户输入-1，返回上一页
        fflush(stdin);
        gets(enter);
        while(enter[0]<'1'||enter[0]>'3'||enter[1]!='\0')
        {
            printf("\nYour selection is not identified. Please try again.\n");
            printf("What would you like to do?\n(Enter 1 to check flights, 2 to add a new flight, 3 to return.)\n");
            fflush(stdin);
            gets(enter);
        }
        e=atoi(enter);
    }
    fclose(infile);
}

void information2(struct ADMIN *logged)//管理员个人信息管理
{
    FILE *information2;
    information2=fopen("administrator information.txt","r+");
    if(information2==NULL)
    {
        printf("Error! Please check that the file 'administrator.txt' exists.\n");
        exit(1);
    }
    char string[NUMEL];
    char enter[20];
    int e=0,i,j,m,n,k;//e用于switch和读行数，ij用于循环，mn用于判断输出情形，k用于取代goto
    struct ADMIN temp0;//存储读得的管理员信息
    while((i=fgetc(information2))!=EOF)
    {
        if(i=='\n')
            e++;
    }
    rewind(information2);
    for(i=0;i<e;i++)
    {
        fscanf(information2,"%s %s %s %s %s",temp0.ID,temp0.name,temp0.comp,temp0.password,temp0.mail);
        if(strcmp(temp0.ID,logged->ID)==0)
        {
            j=i;
            break;
        }
    }
    rewind(information2);//移动指针到开头
    for(i=0;i<j-1;i++)
    {
        fgets(string,81,information2);//移动指针到第j-1行末尾
    }
    m=n=0;
    printf("\nWhat would you like to change?(Enter -1 to exit)\n");
    printf("1.Password  2.Mailbox\n");
    fflush(stdin);
    gets(enter);
    while(enter[0]!='-'||enter[1]!='1'||enter[2]!='\0')
    {
        while(enter[0]<'1'||enter[0]>'2'||enter[0]=='\0'||enter[1]!='\0')
        {
            printf("\nYour selection is not identified. Please try again.\n");
            printf("What would you like to change?(Enter -1 to exit)\n");
            printf("1.Password  2.Mailbox\n");
            fflush(stdin);
            gets(enter);
            if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                return;
        }
        e=atoi(enter);
        switch(e)
        {
            case 1:
            {
                char enter0[20];
                printf("\nEnter a new password:(less than 9 digits) (Enter -1 to quit)\n");
                fflush(stdin);
                gets(enter);
                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                    break;
                printf("\nPlease enter your password again:(Enter -1 to quit)\n");
                fflush(stdin);
                gets(enter0);
                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                    break;
                while(strcmp(enter,enter0)!=0||strlen(enter)>9||strlen(enter0)>9)
                {
                    printf("\nPlease ensure that your password is valid and try again.\n");
                    printf("Enter a new password: (less than 9 digits) (Enter -1 to quit)\n");
                    fflush(stdin);
                    gets(enter);
                    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')//用于下面选择性break
                    {
                        k=1;
                        break;
                    }
                    printf("\nPlease enter your password again:(Enter -1 to quit)\n");
                    fflush(stdin);
                    gets(enter0);
                    if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')//用于下面选择性break
                    {
                        k=1;
                        break;
                    }
                    while(strcmp(enter,enter0)!=0||strlen(enter)>9||strlen(enter0)>9)
                    {
                        printf("\nPlease ensure that your password is valid and try again.\n");
                        printf("Enter your password: (less than 9 digits) (Enter -1 to quit)\n");
                        fflush(stdin);
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')//用于下面选择性break
                        {
                            k=1;
                            break;
                        }
                        printf("\nPlease enter your password again:\n");
                        fflush(stdin);
                        gets(enter0);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')//用于下面选择性break
                        {
                            k=1;
                            break;
                        }
                    }
                }
                if(k==1)
                    break;
                else
                {
                    memset(temp0.password,0,strlen(temp0.password));
                    strcpy(temp0.password,enter);
                    m=1;
                    break;
                }
            }
            case 2:
            {
                printf("\nEnter a new e-mail: (Enter -1 to quit)\n");
                fflush(stdin);
                gets(enter);
                if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                    break;
                e=0;
                while(e!=2)
                {
                    for(i=0;i<strlen(enter);i++)
                    {
                        if(enter[i]=='@'&&e==0)
                            e++;
                        if(enter[i]=='.'&&e==1)
                            e++;
                    }
                    if(e!=2)
                    {
                        printf("\nYour e-mail is illegal. Please try again.\n");
                        printf("Enter your e-mail: (Enter -1 to quit)\n");
                        fflush(stdin);
                        gets(enter);
                        if(enter[0]=='-'&&enter[1]=='1'&&enter[2]=='\0')
                            return;
                        e=0;
                    }
                    else
                    {
                        memset(temp0.mail,'\0',strlen(temp0.mail));
                        strcpy(temp0.mail,enter);
                        break;
                    }
                }
                n=1;
                break;
            }
        }
        printf("\nWhat would you like to change?(Enter -1 to exit)\n");
        printf("1.Password  2.Mailbox\n");
        fflush(stdin);
        gets(enter);
    }
    if(m==0&&n==0)
        ;
    else
        fprintf(information2,"\n%-10s %-10s %-3s %-4s %-10s",temp0.ID,temp0.name,temp0.comp,temp0.password,temp0.mail);
    fclose(information2);
};
