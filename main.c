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
float prefect[3];
float good[3];
float mid[3];
float pass[3];
float fail[3];
//分数等级
void sum()
{

	for (int i = 0; i < 3; i++) {
		all[i] = 0;
		prefect[i] = 0;
		good[i] = 0;
		mid[i] = 0;
		pass[i] = 0;
		fail[i] = 0;
	}
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 30; i++)
		{
			all[j] += student[i][j];
		}
	}
	//各科总和（分别计入数组）
	for (int l = 0; l < 3; l++)
	{
		ave[l] = all[l] / 30;
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
		for (int p = 1; p < 30; p++)
		{
			if (max[k] < student[p][k])
			{
				max[k] = student[p][k];
			}
			if (min[k] > student[p][k])
			{
				min[k] = student[p][k];
			}
		}
	}
	//比较大小并替换

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 30; i++)
		{
			if (student[i][j] >= 90)
			{
				prefect[j] += 1;
			}
			else if (student[i][j] < 90 && student[i][j] >= 80)
			{
				good[j] += 1;
			}
			else if (student[i][j] < 80 && student[i][j] >= 70)
			{
				mid[j] += 1;
			}
			else if (student[i][j] < 70 && student[i][j] >= 60)
			{
				pass[j] += 1;
			}
			else if (student[i][j] < 60 && student[i][j] >= 0)
			{
				fail[j] += 1;
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
//计算
void saveData()
{
	FILE* file = fopen("student.dat", "wb");
	if (file == NULL)
	{
		printf("错误：无法创建文件！\n");
		return;
	}
	// 写入学生学号
	fwrite(student_, sizeof(int), 30, file);

	// 写入学生成绩
	for (int i = 0; i < 30; i++)
	{
		fwrite(student[i], sizeof(float), 3, file);
	}

	fclose(file);
	printf("数据已成功保存！\n");
}
// 数据导入进文件
int loadData()
{
	FILE* file = fopen("student.dat", "rb");
	if (file == NULL)
	{
		printf("错误：文件不存在！\n");
		return 0;
	}
	// 读取学生学号
	fread(student_, sizeof(int), 30, file);
	// 读取学生成绩
	for (int i = 0; i < 30; i++)
	{
		fread(student[i], sizeof(float), 3, file);
	}
	fclose(file);
	// 重新计算统计信息
	sum();
	printf("数据加载成功！\n");
	return 1;
}
// 从文件加载数据
void reput()
{
	int stu_id, subject, found = 0;
	float new_score;

	printf("请输入要修改成绩的学生学号：");
	scanf("%d", &stu_id);

	// 查找学生
	for (int i = 0; i < 30; i++)
	{
		if (student_[i] == stu_id)
		{
			found = 1;
			printf("当前成绩：语文%.2f，数学%.2f，英语%.2f\n", student[i][0], student[i][1], student[i][2]);
			printf("请选择要修改的科目（0.语文，1.数学，2.英语）：");
			scanf("%d", &subject);

			if (subject >= 0 && subject <= 2)
			{
				printf("请输入新成绩：");
				scanf("%f", &new_score);
				student[i][subject] = new_score;
				printf("修改成功！\n");
				sum(); // 重新计算统计信息
			}
			else
			{
				printf("科目选择错误！\n");
			}
			break;
		}
	}

	if (!found)
	{
		printf("未找到该学号的学生！\n");
	}
}
//更改学生信息
void check()
{
	int stu_id,found = 0;

	printf("请输入要查找成绩的学生学号：");
	scanf("%d", &stu_id);
	// 查找学生
	for (int i = 0; i < 30; i++)
	{
		if (student_[i] == stu_id)
		{
			found = 1;
			printf("当前成绩：语文%.2f，数学%.2f，英语%.2f\n", student[i][0], student[i][1], student[i][2]);
		}
	}
	if (!found)
	{
		printf("未找到该学号的学生！\n");
	}
}
//查找学生信息
/*void print()
{
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:printf("\n在语文科目中：\n"); break;
		case 1:printf("\n在数学科目中：\n"); break;
		case 2:printf("\n在英语科目中：\n"); break;
		default:break;
		};
			printf("评级为	优秀	人数为：%.2f%%\n", ( prefect[i]/30) * 100);
			printf("评级为	良好	人数为：%.2f%%\n", (good[i]/30) * 100);
			printf("评级为	中等	人数为：%.2f%%\n", (mid[i]/30) * 100);
			printf("评级为	及格	人数为：%.2f%%\n", (pass[i]/30) * 100);
			printf("评级为	不及格	人数为：%.2f%%\n", (fail[i]/30) * 100);
			printf("该科目平均分：%.2f\n", ave[i]);
			printf("该科目最高分：%.2f\n", max[i]);
			printf("该科目最低分：%.2f\n", min[i]);
			printf("该科目总分：%.2f\n", all[i]);
	}
}
//打印

*/
void print()
{
	printf("科目\t");
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:printf("语文\t"); break;
		case 1:printf("数学\t"); break;
		case 2:printf("英语\t"); break;
		default:break;
		}
	}
	printf("\n");
	printf("优秀\t%.2f%%\t%.2f%%\t%.2f%%\t\n", (prefect[0] / 30) * 100, (prefect[1] / 30) * 100, (prefect[2] / 30) * 100);
	printf("良好\t%.2f%%\t%.2f%%\t%.2f%%\t\n", (good[0] / 30) * 100, (good[1] / 30) * 100, (good[2] / 30) * 100);
	printf("中等\t%.2f%%\t%.2f%%\t%.2f%%\t\n", (mid[0] / 30) * 100, (mid[1] / 30) * 100, (mid[2] / 30) * 100);
	printf("及格\t%.2f%%\t%.2f%%\t%.2f%%\t\n", (pass[0] / 30) * 100, (pass[1] / 30) * 100, (pass[2] / 30) * 100);
	printf("不及格\t%.2f%%\t%.2f%%\t%.2f%%\t\n", (fail[0] / 30) * 100, (fail[1] / 30) * 100, (fail[0] / 30) * 100);
	printf("平均分\t%.2f\t%.2f\t%.2f\t\n", ave[0], ave[1], ave[2]);
	printf("最高分\t%.2f\t%.2f\t%.2f\t\n", max[0], max[1], max[2]);
	printf("最低分\t%.2f\t%.2f\t%.2f\t\n", min[0], min[1], min[2]);
	printf("总分\t%.2f\t%.2f\t%.2f\t\n", all[0], all[1], all[2]);
}

void input()
{
	int project;
	int i;
	printf("*输入第一个学号后，系统录入过程中输入-1即可退出*\n");
	printf("*系统将跟据第一个学生学号自动递进至下一个学生*\n");
	printf("请输入第一个学生的学号：");
	scanf(" %d", &student_[0]);
	for (i = 1; i <= 29;i++)
	{
		student_[i] = student_[i-1] + 1;
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
			default:printf("输入的科目不合法！"); break;
			}
			scanf("%f", &temp);
			if (temp == -1)
			{
				return;
			}
			else
			{
				student[i][project] = temp;
			}
		}
	}
	sum();
}
//录入
static void breakout()
{
	return;
}
//退出
void markmanage_system()
{
	int out = 0;
	while (out!=1)
	{
		printf("请选择你要进行的操作：\n");
		printf("1.录入成绩\n");
		printf("2.修改成绩\n");
		printf("3.载入文件\n");
		printf("4.储存文件\n");
		printf("5.统计数据\n");
		printf("6.成绩查询\n");
		printf("7.退出系统\n");
		scanf(" %d", &choose);
		switch (choose)
		{
		case 1:input(); break;
		case 2:reput(); break;
		case 3:loadData(); break;
		case 4:saveData(); break;
		case 5:print(); break;
		case 6:check(); break;
		case 7:out = 1; breakout(); break;
		default:printf("请选择正确的选项"); break;
		}
	}
}
//成绩系统主体
void login()
{
	int login_= 0;
	printf("***成绩管理系统***\n");
	while (login_!=1)
	{
		printf("请输入系统密码：");
		scanf(" %s", &password);
		if (strcmp(password, defult_password) == 0)
		{
			printf("登陆成功！\n");
			login_ = 1;
		}
		else if (strcmp(password, defult_password) != 0)
		{
			printf("密码错误，请重新输入\n");
		}
	}
}
//登录
void main()
{
	login();
	markmanage_system();
}
//主函数
