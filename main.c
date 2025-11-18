#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int choose;
char password[7];
char defult_password[7] = "abc123";
float student[30][3];
int student_[30];
//数据
float temp;
//缓存
float all[3];
float max[3];
float min[3];
float ave[3];
//计算
int prefect[3];
int good[3];
int mid[3];
int pass[3];
int fail[3];
//分数等级

void sum()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 30; i++)
		{
			all[j] += student[i][j];
		}
	}
	//各科总和（分别计入数组）
	for ( int l = 0; l < 3; l++)
	{
		ave[l] == max[l] / 30;
	}
	//各科平均分
	for (int i = 0; i < 3; i++)
	{
		max[i] = student[0][i];
	}
	//初始默认MAX值
	for (int i = 0; i < 3; i++)
	{
		min[i] = student[0][i];
	}
	//初始默认MIN值
	for (int k = 0; k < 3; k++)
	{
		for (int p=1;p<30;p++)
		{
			if (max[k]<student[k][p])
			{
				max[k] = student[k][p];
			}
			if (min[k]>student[k][p])
			{
				min[k] = student[k][p];
			}
		}
	}
	//比较大小并替换

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 30; j++) 
		{
			if (student[i][j]>=90)
			{
				prefect[i] += 1;
			}
			else if(student[i][j] < 90&& student[i][j] >= 80)
			{
				good[i]+=1;
			}
			else if (student[i][j] < 80 && student[i][j] >= 70)
			{
				mid[i] += 1;
			}
			else if(student[i][j] < 70 && student[i][j] >= 60)
			{
				pass[i] += 1;
			}
			else if(student[i][j] < 60)
			{
				fail[i] += 1;
			}
		}
	}
	//计算各等级学生的比例
	/*
	对应等级分布：
	优/良/中/及格/不及格
>90/89-80/79-70/69-60/<59
	*/
}

void input()
{
	int project;
	int i;
	printf("*系统录入过程中输入-1即可退出*\n");
	printf("*系统将跟据第一个学生学号自动递进指下一个学生*\n");
	printf("请输入第一个学生的学号：");
	scanf(" %d", &student_[0]);
	for (i = 0; i < 30;i++)
	{
		student_[i + 1] = student_[i] + 1;
	};
//学生的学号
	for (i = 0; i < 30; i++)
	{
		printf("学生学号：%d\n", student_[i]);
		for (project = 0;  project< 3; project++)
		{
			switch (project)
			{
			case 0:printf("请输入该学生的语文科目成绩："); break;
			case 1:printf("请输入该学生的数学科目成绩："); break;
			case 2:printf("请输入该学生的英语科目成绩："); break;
			default:break;
			}
			scanf("%f", &temp);
			if (temp == -1)
			{
				return 0;
			}
			else
			{
				student[i][project] = temp;
			}
		}
	}
}
//录入
static void reput()
{
	return 0;
}
//修改
static void reload()
{
	return 0;
}
//重新导入
static void breakout()
{
	return 0;
}
//退出
void markmanage_system()
{
	printf("请选择你要进行的操作：\n");
	printf("1.录入成绩\n");
	printf("2.修改成绩\n");
	printf("3.重新导入\n");
	printf("4.退出系统\n");
	scanf(" %d", &choose);
	switch (choose)
	{
	case 1:input(); break;
	case 2:reput(); break;
	case 3:reload(); break;
	case 4:breakout(); break;
	default:printf("请选择正确的选项"); break;
	}

}
//成绩系统主体
void login()
{
	printf("***成绩管理系统***\n");
	printf("请输入系统密码：");
	scanf(" %s", &password);
	if (strcmp(password,defult_password)==0)
	{
		printf("登陆成功！\n");
		markmanage_system();
	}
	else if(strcmp(password, defult_password) != 0)
	{
		printf("密码错误！\n");
	}
}
//登录
void main()
{
	login();
}

