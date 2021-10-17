#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
void menu();
void increase();
void search();
void dlt();
void save();
void flush();
void display();
void modify();
void exit();
int n = 0, t = 1;    //n为总材料数，t控制循环
struct material {
    char num[100];    //录入顺序序列号 
    char name[100];   //名称 
    float basic_attributes[7];   //材料基本属性 
}material[N];
int main()
{
    int number;
    while (t)
    {
        menu();
        printf("请输入菜单编号：");
        scanf("%d", &number);
        switch (number)
        {
        case 1:help(); break;    //使用帮助
        case 2:increase(); break;    //增加材料息
        case 3:search(); break;    //查询材料信息
        case 4:dlt(); break;    //删除材料信息
        case 5:display(); break;    //显示当前信息
        case 6:modify(); break;    //修改材料信息
		case 7:save(); break;    //保存当前信息
        case 8:flush(); break;    //刷新学生信息
        case 9:exit(0); break;    //退出、
 
        default:printf("输入有误！");
        }
    }
}
void help()    //使用帮助
{
    printf("\n这是一个材料信息管理系统，为方便您更快了解它，请先阅读以下注意事项：\n");
    printf("\n注意事项:                    \n ");
    printf("\n       1、请根据提示进行操作！\n");
    printf("\n       2、初次使用请先选择增加学生信息！\n");
    printf("\n       8、材料信息包括：序列号、名称、弹性模量、密度、硬度、热膨胀系数、导热系数、比热容、热阻！\n");
    printf("\n       9、使用遇到任何问题请与我们联系，电话：12345678\n");
    printf("\n       10、最后感谢您的使用！\n");
    system("pause");    //让系统暂停
}

void menu()    //显示菜单
{
    printf("\n");
    printf("*****************************************************\n");
    printf("*               材料信息管理系统                  *\n");
    printf("*****************************************************\n");
    printf("********************系统功能菜单*********************\n");
    printf("-----------------------     -------------------------\n");
    printf("*****************************************************\n");
    printf("**    1、使用帮助       *     2、增加材料信息      **\n");
    printf("*****************************************************\n");
    printf("**    3、查询材料信息   *     4、删除材料信息      **\n");
    printf("*****************************************************\n");
    printf("**    5、显示当前信息   *     6、修改材料信息      **\n");
    printf("*****************************************************\n");
    printf("**    7、保存当前信息   *     8、刷新材料信息      **\n");
    printf("**    9、退出系统       *                          **\n");
    printf("*************************                            \n");
    printf("-----------------------     -------------------------\n");

}
void save()    //保存学生信息
{
    FILE* fp;
    char filename[100];
    int i;
    printf("请输入要保存的文件名：\n");
    scanf("%s", filename);
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        if (fwrite(&material[i], sizeof(struct material), 1, fp) != 1)
            printf("保存失败！\n");
    }
    printf("保存成功！\n");
    fclose(fp);
    system("pause");
}
void flush()    //刷新学生信息
{
    FILE* fp;
    char filename[100];
    int i, k = 0;
    printf("请输入需要刷新的文件名：\n");
    getchar();
    gets(filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    for (i = 0; i < N; i++)
    {
        if (fread(&material[i], sizeof(struct material), 1, fp) == 1)
        {
            k++;
        }
    }
    n = k;
    if (k == 0) printf("刷新失败！\n");
    else printf("刷新成功！\n");
    fclose(fp); 
    system("pause");
}


void search()    //查询学生信息
{
    int number, flag, i;
    char s1[100];
    printf("*****************************\n");
    printf("**-------1.按序列号查询------**\n");
    printf("**-------2.按名称查询------**\n");
    printf("**-------3.退出本菜单------**\n");
    printf("*****************************\n");
    while (1)
    {
        flag = 0;
        printf("请输入要执行的操作序号：\n");
        scanf("%d", &number);
        switch (number)
        {
        case 1:
            printf("请输入需要查找信息的序列号：\n");
            scanf("%s",s1);
            for (i = 0; i < n; i++)
            {
                if (strcmp(material[i].num, s1) == 0)
                {
                    flag = 1;
                    printf("序列号\t名称\t弹性模量\t密度\t硬度\t热膨胀系数\t导热系数\t比热容\t热阻\n");
                   printf("%s\t%s\t%.2f\t\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\t%.2f\n",material[i].num, material[i].name, material[i].basic_attributes[0], material[i].basic_attributes[1],material[i].basic_attributes[2],material[i].basic_attributes[3],material[i].basic_attributes[4],material[i].basic_attributes[5],material[i].basic_attributes[6]);
                }
            }break;
        case 2:
            printf("请输入需要查找材料的名称：\n");
            scanf("%s", s1);
            for (i = 0; i < n; i++)
            {
                if (strcmp(material[i].name, s1) == 0)
                {
                    flag = 1;
                    printf("序列号\t名称\t弹性模量\t密度\t硬度\t热膨胀系数\t导热系数\t比热容\t热阻\n");
                   printf("%s\t%s\t%.2f\t\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\t%.2f\n",material[i].num, material[i].name, material[i].basic_attributes[0], material[i].basic_attributes[1],material[i].basic_attributes[2],material[i].basic_attributes[3],material[i].basic_attributes[4],material[i].basic_attributes[5],material[i].basic_attributes[6]);
            }break;
        case 3:return;
        default:printf("请在1--3之间输入！\n");
        }
        if (flag == 0)
            printf("找不到该材料，请重新输入！\n");
    }
}
} 
void increase()    //增加化学材料信息
{
    int m, flag, i = n, j;
    printf("请输入待添加的材料信息数：\n");
    scanf("%d", &m);
    if (m > 0)
    {
        do
        {
            flag = 1;
            while (flag != 0)
            {
                flag = 0;
                printf("请输入第%d个材料的序列号：\n", i + 1);
                getchar();
                gets(material[i].num);
                for (j = 0; j < i; j++)
                {
                    if (strcmp(material[i].num, material[j].num) == 0)
                    {
                        printf("该序列号已存在，请重新输入！\n");
                        flag = 1;
                        break;
                    }
                }
            }
            printf("请输入第%d个材料名称：\n", i + 1);
            gets(material[i].name);
            printf("请输入第%d个材料弹性模量：\n", i + 1);
            scanf("%f", &material[i].basic_attributes[0]);
            printf("请输入第%d个材料密度：\n", i + 1);
            scanf("%f", &material[i].basic_attributes[1]);
            printf("请输入第%d个材料硬度：\n", i + 1);
            scanf("%f", &material[i].basic_attributes[2]);
            printf("请输入第%d个材料热膨胀系数：\n", i + 1);
            scanf("%f", &material[i].basic_attributes[3]);
            printf("请输入第%d个材料导热系数：\n", i + 1);
            scanf("%f", &material[i].basic_attributes[4]);  
            printf("请输入第%d个材料比热容：\n", i + 1);
            scanf("%f", &material[i].basic_attributes[5]);
            printf("请输入第%d个材料热阻：\n", i + 1);
            scanf("%f", &material[i].basic_attributes[6]);									          
            i++;
        } while (i < m + n);
        n += m;
        printf("添加完成！");
        system("pause");
    }
}
void dlt()   //删除信息
{
    int flag, i, j;
    char s1[100];
    printf("请输入要删除材料的序列号：\n");
    getchar();
    gets(s1);
    flag = 0;
    for (i = 0; i < n; i++)
    {
        if (strcmp(material[i].num, s1) == 0)
        {
            flag = 1;
            for (j = i; j < n - 1; j++)
            {
                material[j] = material[j + 1];      //从末尾段对顺序存储结构进行左移删除 
            }
        }
        if (flag == 1) break;
    }
    if (flag == 0) printf("未找到该材料！\n");
    if (flag == 1)
    {
        printf("删除成功！\n");
        n--;
    }
    system("pause");
}
void display()    //显示当前信息
{
    int i;
    if (n == 0)
        printf("您好，现在暂无材料信息，请先添加材料信息！\n");
    else
    {
        printf("现在共有%d个材料\n", n);  
          printf("序列号\t名称\t弹性模量\t密度\t硬度\t热膨胀系数\t导热系数\t比热容\t热阻\n");
        for (i = 0; i < n; i++)
        {
               printf("%s\t%s\t%.2f\t\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\t%.2f\n",material[i].num, material[i].name, material[i].basic_attributes[0], material[i].basic_attributes[1],material[i].basic_attributes[2],material[i].basic_attributes[3],material[i].basic_attributes[4],material[i].basic_attributes[5],material[i].basic_attributes[6]);
    }
    system("pause");
}
} 
void modify()    //修改材料信息
{
    int flag, num,age, i;
    char number[100], new_name[10];
    float new_basic_attributes[7];
    char s1[100];
    printf("请输入需要修改的材料名称：\n");
    getchar();
    gets(s1);
    while (1)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (strcmp(s1, material[i].name) == 0)
            {
                flag = 1;
                printf("***************************************************\n");
                printf("*----1.修改序列号-------------------2.修改名称-------*\n");
                printf("*----3.修改弹性模量-----------------4.修改密度--*\n");
                printf("*----5.修改硬度---------------------6.修改热膨胀系数---*\n");
                printf("*----7.修改导热系数-----------------8.修改比热容---*\n");
                printf("*----9.修改热阻----------------------------------------*\n");
                printf("*----10.退出本菜单------------------*\n");
                printf("***************************************************\n\n");
                printf("请输入菜单编号：\n");
                scanf("%d", &num);
                switch (num)
                {
                case 1:
                    printf("请输入新序列号：\n");
                    getchar();
                    gets(number);
                    strcpy(material[i].num, number);
                    break;
                case 2:
                    printf("请输入新名称：\n");
                    getchar();
                    gets(new_name);
                    strcpy(material[i].name, new_name); 
                case 3:
                    printf("请输入该材料的弹性模量：\n");
                    scanf("%f", &new_basic_attributes[0]);//键入 
                    material[i].basic_attributes[0] = new_basic_attributes[0]; //赋新 
                    break; 
                 case 4:
                    printf("请输入该材料的密度：\n");
                    scanf("%f", &new_basic_attributes[1]);//键入 
                    material[i].basic_attributes[1] = new_basic_attributes[1]; //赋新 
                    break;                   
                case 5:
                    printf("请输入该材料的硬度：\n");
                    scanf("%f", &new_basic_attributes[2]);//键入 
                    material[i].basic_attributes[2] = new_basic_attributes[2]; //赋新 
                    break;
                case 6:
                    printf("请输入该材料的热膨胀系数：\n");
                    scanf("%f", &new_basic_attributes[3]);//键入 
                    material[i].basic_attributes[3] = new_basic_attributes[3]; //赋新 
                    break;
				case 7:
                    printf("请输入该材料的导热系数：\n");
                    scanf("%f", &new_basic_attributes[4]);//键入 
                    material[i].basic_attributes[4] = new_basic_attributes[4]; //赋新 
                    break;	
                case 8:
                    printf("请输入该材料的比热容：\n");
                    scanf("%f", &new_basic_attributes[5]);//键入 
                    material[i].basic_attributes[5] = new_basic_attributes[5]; //赋新 
                    break;
                case 9:
                    printf("请输入该材料的热阻：\n");
                    scanf("%f", &new_basic_attributes[6]);//键入 
                    material[i].basic_attributes[6] = new_basic_attributes[6]; //赋新 
                    break;
			
				case 10:return;
                default:printf("请输入1--9之间的数字！\n");
                }
                if (num > 0 && num < 11)
                    printf("修改成功！\n");
                break;
            }
        }
        if (flag == 0)
        {
            printf("未找到该材料，请重新输入材料名称：\n");
            gets(s1);
        }
    }
    system("pause");
}

