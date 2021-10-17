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
int n = 0, t = 1;    //nΪ�ܲ�������t����ѭ��
struct material {
    char num[100];    //¼��˳�����к� 
    char name[100];   //���� 
    float basic_attributes[7];   //���ϻ������� 
}material[N];
int main()
{
    int number;
    while (t)
    {
        menu();
        printf("������˵���ţ�");
        scanf("%d", &number);
        switch (number)
        {
        case 1:help(); break;    //ʹ�ð���
        case 2:increase(); break;    //���Ӳ���Ϣ
        case 3:search(); break;    //��ѯ������Ϣ
        case 4:dlt(); break;    //ɾ��������Ϣ
        case 5:display(); break;    //��ʾ��ǰ��Ϣ
        case 6:modify(); break;    //�޸Ĳ�����Ϣ
		case 7:save(); break;    //���浱ǰ��Ϣ
        case 8:flush(); break;    //ˢ��ѧ����Ϣ
        case 9:exit(0); break;    //�˳���
 
        default:printf("��������");
        }
    }
}
void help()    //ʹ�ð���
{
    printf("\n����һ��������Ϣ����ϵͳ��Ϊ�����������˽����������Ķ�����ע�����\n");
    printf("\nע������:                    \n ");
    printf("\n       1���������ʾ���в�����\n");
    printf("\n       2������ʹ������ѡ������ѧ����Ϣ��\n");
    printf("\n       8��������Ϣ���������кš����ơ�����ģ�����ܶȡ�Ӳ�ȡ�������ϵ��������ϵ���������ݡ����裡\n");
    printf("\n       9��ʹ�������κ���������������ϵ���绰��12345678\n");
    printf("\n       10������л����ʹ�ã�\n");
    system("pause");    //��ϵͳ��ͣ
}

void menu()    //��ʾ�˵�
{
    printf("\n");
    printf("*****************************************************\n");
    printf("*               ������Ϣ����ϵͳ                  *\n");
    printf("*****************************************************\n");
    printf("********************ϵͳ���ܲ˵�*********************\n");
    printf("-----------------------     -------------------------\n");
    printf("*****************************************************\n");
    printf("**    1��ʹ�ð���       *     2�����Ӳ�����Ϣ      **\n");
    printf("*****************************************************\n");
    printf("**    3����ѯ������Ϣ   *     4��ɾ��������Ϣ      **\n");
    printf("*****************************************************\n");
    printf("**    5����ʾ��ǰ��Ϣ   *     6���޸Ĳ�����Ϣ      **\n");
    printf("*****************************************************\n");
    printf("**    7�����浱ǰ��Ϣ   *     8��ˢ�²�����Ϣ      **\n");
    printf("**    9���˳�ϵͳ       *                          **\n");
    printf("*************************                            \n");
    printf("-----------------------     -------------------------\n");

}
void save()    //����ѧ����Ϣ
{
    FILE* fp;
    char filename[100];
    int i;
    printf("������Ҫ������ļ�����\n");
    scanf("%s", filename);
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        if (fwrite(&material[i], sizeof(struct material), 1, fp) != 1)
            printf("����ʧ�ܣ�\n");
    }
    printf("����ɹ���\n");
    fclose(fp);
    system("pause");
}
void flush()    //ˢ��ѧ����Ϣ
{
    FILE* fp;
    char filename[100];
    int i, k = 0;
    printf("��������Ҫˢ�µ��ļ�����\n");
    getchar();
    gets(filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
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
    if (k == 0) printf("ˢ��ʧ�ܣ�\n");
    else printf("ˢ�³ɹ���\n");
    fclose(fp); 
    system("pause");
}


void search()    //��ѯѧ����Ϣ
{
    int number, flag, i;
    char s1[100];
    printf("*****************************\n");
    printf("**-------1.�����кŲ�ѯ------**\n");
    printf("**-------2.�����Ʋ�ѯ------**\n");
    printf("**-------3.�˳����˵�------**\n");
    printf("*****************************\n");
    while (1)
    {
        flag = 0;
        printf("������Ҫִ�еĲ�����ţ�\n");
        scanf("%d", &number);
        switch (number)
        {
        case 1:
            printf("��������Ҫ������Ϣ�����кţ�\n");
            scanf("%s",s1);
            for (i = 0; i < n; i++)
            {
                if (strcmp(material[i].num, s1) == 0)
                {
                    flag = 1;
                    printf("���к�\t����\t����ģ��\t�ܶ�\tӲ��\t������ϵ��\t����ϵ��\t������\t����\n");
                   printf("%s\t%s\t%.2f\t\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\t%.2f\n",material[i].num, material[i].name, material[i].basic_attributes[0], material[i].basic_attributes[1],material[i].basic_attributes[2],material[i].basic_attributes[3],material[i].basic_attributes[4],material[i].basic_attributes[5],material[i].basic_attributes[6]);
                }
            }break;
        case 2:
            printf("��������Ҫ���Ҳ��ϵ����ƣ�\n");
            scanf("%s", s1);
            for (i = 0; i < n; i++)
            {
                if (strcmp(material[i].name, s1) == 0)
                {
                    flag = 1;
                    printf("���к�\t����\t����ģ��\t�ܶ�\tӲ��\t������ϵ��\t����ϵ��\t������\t����\n");
                   printf("%s\t%s\t%.2f\t\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\t%.2f\n",material[i].num, material[i].name, material[i].basic_attributes[0], material[i].basic_attributes[1],material[i].basic_attributes[2],material[i].basic_attributes[3],material[i].basic_attributes[4],material[i].basic_attributes[5],material[i].basic_attributes[6]);
            }break;
        case 3:return;
        default:printf("����1--3֮�����룡\n");
        }
        if (flag == 0)
            printf("�Ҳ����ò��ϣ����������룡\n");
    }
}
} 
void increase()    //���ӻ�ѧ������Ϣ
{
    int m, flag, i = n, j;
    printf("���������ӵĲ�����Ϣ����\n");
    scanf("%d", &m);
    if (m > 0)
    {
        do
        {
            flag = 1;
            while (flag != 0)
            {
                flag = 0;
                printf("�������%d�����ϵ����кţ�\n", i + 1);
                getchar();
                gets(material[i].num);
                for (j = 0; j < i; j++)
                {
                    if (strcmp(material[i].num, material[j].num) == 0)
                    {
                        printf("�����к��Ѵ��ڣ����������룡\n");
                        flag = 1;
                        break;
                    }
                }
            }
            printf("�������%d���������ƣ�\n", i + 1);
            gets(material[i].name);
            printf("�������%d�����ϵ���ģ����\n", i + 1);
            scanf("%f", &material[i].basic_attributes[0]);
            printf("�������%d�������ܶȣ�\n", i + 1);
            scanf("%f", &material[i].basic_attributes[1]);
            printf("�������%d������Ӳ�ȣ�\n", i + 1);
            scanf("%f", &material[i].basic_attributes[2]);
            printf("�������%d������������ϵ����\n", i + 1);
            scanf("%f", &material[i].basic_attributes[3]);
            printf("�������%d�����ϵ���ϵ����\n", i + 1);
            scanf("%f", &material[i].basic_attributes[4]);  
            printf("�������%d�����ϱ����ݣ�\n", i + 1);
            scanf("%f", &material[i].basic_attributes[5]);
            printf("�������%d���������裺\n", i + 1);
            scanf("%f", &material[i].basic_attributes[6]);									          
            i++;
        } while (i < m + n);
        n += m;
        printf("�����ɣ�");
        system("pause");
    }
}
void dlt()   //ɾ����Ϣ
{
    int flag, i, j;
    char s1[100];
    printf("������Ҫɾ�����ϵ����кţ�\n");
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
                material[j] = material[j + 1];      //��ĩβ�ζ�˳��洢�ṹ��������ɾ�� 
            }
        }
        if (flag == 1) break;
    }
    if (flag == 0) printf("δ�ҵ��ò��ϣ�\n");
    if (flag == 1)
    {
        printf("ɾ���ɹ���\n");
        n--;
    }
    system("pause");
}
void display()    //��ʾ��ǰ��Ϣ
{
    int i;
    if (n == 0)
        printf("���ã��������޲�����Ϣ��������Ӳ�����Ϣ��\n");
    else
    {
        printf("���ڹ���%d������\n", n);  
          printf("���к�\t����\t����ģ��\t�ܶ�\tӲ��\t������ϵ��\t����ϵ��\t������\t����\n");
        for (i = 0; i < n; i++)
        {
               printf("%s\t%s\t%.2f\t\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\t%.2f\n",material[i].num, material[i].name, material[i].basic_attributes[0], material[i].basic_attributes[1],material[i].basic_attributes[2],material[i].basic_attributes[3],material[i].basic_attributes[4],material[i].basic_attributes[5],material[i].basic_attributes[6]);
    }
    system("pause");
}
} 
void modify()    //�޸Ĳ�����Ϣ
{
    int flag, num,age, i;
    char number[100], new_name[10];
    float new_basic_attributes[7];
    char s1[100];
    printf("��������Ҫ�޸ĵĲ������ƣ�\n");
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
                printf("*----1.�޸����к�-------------------2.�޸�����-------*\n");
                printf("*----3.�޸ĵ���ģ��-----------------4.�޸��ܶ�--*\n");
                printf("*----5.�޸�Ӳ��---------------------6.�޸�������ϵ��---*\n");
                printf("*----7.�޸ĵ���ϵ��-----------------8.�޸ı�����---*\n");
                printf("*----9.�޸�����----------------------------------------*\n");
                printf("*----10.�˳����˵�------------------*\n");
                printf("***************************************************\n\n");
                printf("������˵���ţ�\n");
                scanf("%d", &num);
                switch (num)
                {
                case 1:
                    printf("�����������кţ�\n");
                    getchar();
                    gets(number);
                    strcpy(material[i].num, number);
                    break;
                case 2:
                    printf("�����������ƣ�\n");
                    getchar();
                    gets(new_name);
                    strcpy(material[i].name, new_name); 
                case 3:
                    printf("������ò��ϵĵ���ģ����\n");
                    scanf("%f", &new_basic_attributes[0]);//���� 
                    material[i].basic_attributes[0] = new_basic_attributes[0]; //���� 
                    break; 
                 case 4:
                    printf("������ò��ϵ��ܶȣ�\n");
                    scanf("%f", &new_basic_attributes[1]);//���� 
                    material[i].basic_attributes[1] = new_basic_attributes[1]; //���� 
                    break;                   
                case 5:
                    printf("������ò��ϵ�Ӳ�ȣ�\n");
                    scanf("%f", &new_basic_attributes[2]);//���� 
                    material[i].basic_attributes[2] = new_basic_attributes[2]; //���� 
                    break;
                case 6:
                    printf("������ò��ϵ�������ϵ����\n");
                    scanf("%f", &new_basic_attributes[3]);//���� 
                    material[i].basic_attributes[3] = new_basic_attributes[3]; //���� 
                    break;
				case 7:
                    printf("������ò��ϵĵ���ϵ����\n");
                    scanf("%f", &new_basic_attributes[4]);//���� 
                    material[i].basic_attributes[4] = new_basic_attributes[4]; //���� 
                    break;	
                case 8:
                    printf("������ò��ϵı����ݣ�\n");
                    scanf("%f", &new_basic_attributes[5]);//���� 
                    material[i].basic_attributes[5] = new_basic_attributes[5]; //���� 
                    break;
                case 9:
                    printf("������ò��ϵ����裺\n");
                    scanf("%f", &new_basic_attributes[6]);//���� 
                    material[i].basic_attributes[6] = new_basic_attributes[6]; //���� 
                    break;
			
				case 10:return;
                default:printf("������1--9֮������֣�\n");
                }
                if (num > 0 && num < 11)
                    printf("�޸ĳɹ���\n");
                break;
            }
        }
        if (flag == 0)
        {
            printf("δ�ҵ��ò��ϣ�����������������ƣ�\n");
            gets(s1);
        }
    }
    system("pause");
}

