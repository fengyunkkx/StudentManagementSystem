#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <iomanip>

/* Power by FoxGeeker*/

using namespace std;            //命名空间 std

struct lesson                   //定义课程 struct
{
   float chinesegrade;          //定义语文成绩
   float englishgrade;          //定义英语成绩
   float mathgrade;             //定义数学成绩
};

struct student       //定义学生 struct
{
   char   name [10]; //定义姓名 char
   char   clas [20]; //定义班级 char
   int    num;       //定义分数 int
   float  sum;       //定义总分 float
   float  average;   //定义平均成绩 float
   float  fangcha;   //定义查分 float
   lesson less;      //定义课程
}
m [100];

int        n = 100;
static int e = 0;
void sort();                   //定义排序

void error()                   //定义错误信息
{
   cout << "---输入有误，请重新输入---" << endl;
   cout << "\n";
}


/*---欢迎界面---*/

void welcome()       //输入密码进入系统，欢迎界面
{
   char password [5];
   char num [5];

   strcpy(num, "123");
loopback3: printf(" \n\n\n\n\n\n\n\n");
   system("color F1");
   printf("\t\t\t欢迎使用学生成绩管理系统！\n");
   printf("\t\t\t\t密码:");
   scanf("%s", &password);
   if (strcmp(password, num) == 0)
   {
      system("cls");
      system("color F0");
      printf(" \n\n\n\n\n\n\n\n\n\t\t\t欢迎使用学生成绩管理系统！");
      Sleep(300);
      system("cls");
      system("color F2");
      printf(" \n\n\n\n\n\n\n\n\n\t\t\t欢迎使用学生成绩管理系统！");
      Sleep(300);
      system("cls");
      system("color F3");
      printf(" \n\n\n\n\n\n\n\n\n\t\t\t欢迎使用学生成绩管理系统！");
      Sleep(300);
      system("cls");
      system("color F4");
      printf(" \n\n\n\n\n\n\n\n\n\t\t\t欢迎使用学生成绩管理系统！");
      Sleep(300);
      system("cls");
      system("color F5");
      printf(" \n\n\n\n\n\n\n\n\n\t\t\t欢迎使用学生成绩管理系统！");
      Sleep(300);
      system("cls");
      system("color F0");
      printf(" \n\n\n\n\n\n\n\n\n\t\t\t欢迎使用学生成绩管理系统！");
      Sleep(300);
   }
   else
   {
      printf("\t\t\t\t 密码错误!");           //密码错误重新输出
      Sleep(2000);
      system("cls");
      goto loopback3;
   }
}


/*---1.学生信息浏览---*/

void show()          //1.学生信息浏览
{
   system("cls");                  //清屏
   int i;
   cout << setiosflags(ios::left)  // 左对齐
        << setw(2) << "学号" << "  " // 输出宽度为 2
        << setw(10) << "姓名" << "  "
        << setw(12) << "班级"
        << setw(8) << "语文"
        << setw(8) << "英语"
        << setw(8) << "数学"
        << setw(8) << "总分"
        << setw(10) << "平均分"
        << setw(10) << "方差"
        << endl;                                    //显示第一行类别
   for (i = 0; i < e; i++)
   {
      m [i].sum =
         (
            m [i].less.chinesegrade +
            m [i].less.englishgrade +
            m [i].less.mathgrade
         );                            //总分计算公式

      m [i].average =
         (
            m [i].sum / 3
         );                            //平均分计算公式

      m [i].fangcha =
         (
            (m [i].less.chinesegrade - m [i].average) *
            (m [i].less.chinesegrade - m [i].average) +
            (m [i].less.englishgrade - m [i].average) *
            (m [i].less.englishgrade - m [i].average) +
            (m [i].less.mathgrade - m [i].average) *
            (m [i].less.mathgrade - m [i].average)
         ) / 3;                          //方差计算公式

      cout << setiosflags(ios::left)
           << setw(5) << m [i].num << "  "
           << setw(10) << m [i].name
           << setw(14) << m [i].clas
           << setw(8) << m [i].less.chinesegrade
           << setw(8) << m [i].less.englishgrade
           << setw(8) << m [i].less.mathgrade
           << setw(8) << m [i].sum
           << setw(10) << m [i].average
           << setw(10) << m [i].fangcha << endl;
      if (m [i].num == 0)
      {
         break;                           //输出结果
      }
   }
}


/*---2.学生信息录入---*/

void input()         //2.学生信息录入
{
   system("cls");    //清屏
   int a;
   cout << "-----录入学生信息-----" << endl;
   cout << "请输入信息，输入 0 结束录入" << endl;
   cout << "依次输入:学号 姓名 班级 语文 英语 数学" << endl;
   for (a = e; a < n; a++)
   {
      cin >> m [a].num;
      if (m [a].num == 0)
      {
         break;                                //输入0退出
      }
      cin >> m [a].name >> m [a].clas >> m [a].less.chinesegrade
      >> m [a].less.englishgrade >> m [a].less.mathgrade;
      e++;                   //循环
   }
}


/*---3.学生信息删除---*/

void delate()        //3.学生信息删除
{
   show();
   cout << "---输入要删除的学生学号:---";
   int a;
   cin >> a;
   for (int i = 0; i < e; i++)
   {
      if (a == m [i].num)
      {
         int j;
         for (j = i; j < e - 1; j++)
         {
            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].num     = m [j + 1].num;
            m [j].sum     = m [j + 1].sum;
            m [j].average = m [j + 1].average;
            m [j].fangcha = m [j + 1].fangcha;
         }


         for (i = 0; i < e - 1; i++)
         {
            cout << setw(5) << m [i].num
                 << setw(10) << m [i].name
                 << setw(15) << m [i].clas
                 << setw(10) << m [i].less.chinesegrade
                 << setw(10) << m [i].less.englishgrade
                 << setw(10) << m [i].less.mathgrade
                 << setw(10) << m [i].less.mathgrade
                 << setw(8) << m [i].sum
                 << setw(10) << m [i].average
                 << setw(10) << m [i].fangcha << endl;
         }
         cout << "---学生信息删除成功---" << endl;
         break;
      }
   }
}


/*---4.按学号查找输出信息---*/

void numsearch()                //4.按学号查找 输出信息
{
   show();
   cout << "请输入您要查找的学号:" << endl;
   int a;
   cin >> a;
   int BOOL = 0;
   for (int i = 0; i < n; i++)
   {
      if (a == m [i].num)
      {
         cout << setiosflags(ios::left)
              << setw(2) << "学号" << "   "
              << setw(10) << "姓名"
              << setw(10) << "班级"
              << setw(10) << "语文"
              << setw(10) << "英语"
              << setw(10) << "数学" << endl;
         cout << setiosflags(ios::left)
              << setw(5) << m [i].num << "  "
              << setw(10) << m [i].name
              << setw(10) << m [i].clas
              << setw(10) << m [i].less.chinesegrade
              << setw(10) << m [i].less.englishgrade
              << setw(10) << m [i].less.mathgrade << endl;
         cout << endl;
         BOOL = 1;
      }
   }

   if (BOOL == 0)
   {
      cout << "---没有您要查询的信息!---" << endl;
   }
}


/*---5.按姓名查找---*/

void namesearch()  //5.按姓名查找 输出信息
{
   show();
   cout << "请输入您要查找的姓名:" << endl;
   string a;
   cin >> a;
   int BOOL = 0;
   for (int i = 0; i < n; i++)
   {
      if (a == m [i].name)
      {
         cout << setiosflags(ios::left)
              << setw(2) << "学号" << "   "
              << setw(10) << "姓名"
              << setw(10) << "班级"
              << setw(10) << "语文"
              << setw(10) << "英语"
              << setw(10) << "数学" << endl;
         cout << setiosflags(ios::left)
              << setw(5) << m [i].num << "  "
              << setw(10) << m [i].name
              << setw(10) << m [i].clas << setw(10) << m [i].less.chinesegrade
              << setw(10) << m [i].less.englishgrade
              << setw(10) << m [i].less.mathgrade << endl;
         cout << endl;
         BOOL = 1;
      }
   }
   if (BOOL == 0)
   {
      cout << "---抱歉没有您要查询的信息---" << endl;
   }
}


/*---6.按课程查找---*/

void lesssearch()  //6.按课程查找 输出信息
{
   show();
   cout << "---请输入您要查找的课程:---" << endl;
   cout << "1. 语文" << endl;
   cout << "2. 英语" << endl;
   cout << "3. 数学" << endl;
   string a;
   cin >> a;
   cout << setiosflags(ios::left)
        << setw(2)
        << setw(10) << "姓名"
        << setw(10) << "成绩：" << endl;
   int BOOL = 0;
   for (int i = 0; i < e; i++)
   {
      if (a == "1")
      {
         cout << setiosflags(ios::left)
              << setw(5)
              << setw(10) << m [i].name
              << setw(10) << m [i].less.chinesegrade << endl;
         BOOL = 1;
      }
      else if (a == "2")
      {
         cout << setiosflags(ios::left)
              << setw(5)
              << setw(10) << m [i].name
              << setw(10) << m [i].less.englishgrade << endl;
         BOOL = 1;
      }
      else if (a == "3")
      {
         cout << setiosflags(ios::left)
              << setw(5)
              << setw(10) << m [i].name
              << setw(10) << m [i].less.mathgrade << endl;
         BOOL = 1;
      }
   }
   if (BOOL == 0)
   {
      cout << "---没有您要查询的信息!---" << endl;
   }
}


/*---7.1.按英语成绩排序---*/

void sort1()   //7.1.按英语成绩排序
{
   int   j, i;
   char  t1 [20], t2 [20];
   int   t4, t5, t6;
   float t7;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].less.englishgrade < m [j + 1].less.englishgrade)                      //冒泡排序
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
            t7 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
            m [j + 1].num = t7;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.2.按语文成绩排序---*/

void sort2()   //7.2.按语文成绩排序
{
   int   j, i;
   char  t1 [20], t2 [20];
   int   t4, t5, t6;
   float t7;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].less.chinesegrade <= m [j + 1].less.chinesegrade)                     //冒泡排序
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
            t7 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
            m [j + 1].num = t7;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.3.按数学成绩排序---*/

void sort3()   //7.3.按数学成绩排序
{
   int   j, i;
   char  t1 [20], t2 [20];
   float t4, t5, t6;
   float t7;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].less.mathgrade <= m [j + 1].less.mathgrade)        //冒泡排序
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
            t7 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
            m [j + 1].num = t7;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.4.按学号排序---*/

void sort4()   //7.4.按学号排序
{
   int   j, i;
   char  t1 [20], t2 [20];
   float t4, t5, t6;
   float t7;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if (m [j].num <= m [j + 1].num)                     //冒泡排序
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
            t7 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
            m [j + 1].num = t7;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.5.按总成绩由小到大排序---*/

void sort5()   //7.5.按总成绩由小到大排序 （冒泡排序）
{
   int   j, i;
   char  t1 [20], t2 [20];
   int   t4, t5, t6;
   float t7;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if ((m [j].less.chinesegrade + m [j].less.englishgrade + m [j].less.mathgrade)
             >= (m [j + 1].less.chinesegrade + m [j + 1].less.englishgrade + m [j + 1].less.mathgrade))
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
            t7 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
            m [j + 1].num = t7;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.6.按总成绩由大到小排序---*/

void sort6()   //7.6.按总成绩由大到小排序（冒泡排序）
{
   int   j, i;
   char  t1 [20], t2 [20];
   int   t4, t5, t6;
   float t7;

   for (i = 0; i < e - 1; i++)
   {
      for (j = 0; j < e - i - 1; j++)
      {
         if ((m [j].less.chinesegrade + m [j].less.englishgrade + m [j].less.mathgrade) <= (m [j + 1].less.chinesegrade + m [j + 1].less.englishgrade + m [j + 1].less.mathgrade))
         {
            strcpy(t1, m [j].name);
            strcpy(t2, m [j].clas);
            t4 = m [j].less.chinesegrade;
            t5 = m [j].less.englishgrade;
            t6 = m [j].less.mathgrade;
            t7 = m [j].num;

            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].num = m [j + 1].num;

            strcpy(m [j + 1].name, t1);
            strcpy(m [j + 1].clas, t2);
            m [j + 1].less.chinesegrade = t4;
            m [j + 1].less.englishgrade = t5;
            m [j + 1].less.mathgrade    = t6;
            m [j + 1].num = t7;
         }
      }
   }
   show();
   cout << "sort sucess!" << endl;
   cout << endl;
   sort();
}


/*---7.学生成绩排序工具---*/

void sort()   //7.学生成绩排序工具
{
   cout << " \n\n\n\n\n\n\n\t\t\t  欢迎使用学生成绩排序工具" << endl;
   cout << "                          *************************" << endl;
   cout << "                          * 1. 按英语成绩排序      *" << endl;
   cout << "                          * 2. 按语文成绩排序      *" << endl;
   cout << "                          * 3. 按数学成绩排序      *" << endl;
   cout << "                          * 4. 按学号排序          *" << endl;
   cout << "                          * 5. 按总成绩由小到大排序 *" << endl;
   cout << "                          * 6. 按总成绩由大到小排序 *" << endl;
   cout << "                          * 7. 退出程序            *" << endl;
   cout << "                          *************************" << endl;
   cout << "                          * 输入「0-7」进入对应功能 *" << endl;
   int r;
   cin >> r;
   switch (r)
   {
   case 1:
      sort1();
      break;

   case 2:
      sort2();
      break;

   case 3:
      sort3();
      break;

   case 4:
      sort4();
      break;

   case 5:
      sort5();
      break;

   case 6:
      sort6();
      break;

   case 7:
      cout << "---退出到首页---" << endl;
      return;

      break;

   default:
      error();
   }
}


/*---8.学生信息统计工具---*/

void statistics()    //8.学生信息统计工具，计算最高分、最低分、平均分、方差
{
   system("cls");    //系统清屏

   /*---定义各种信息---*/

   float        sumc = 0, sume = 0, summ = 0;
   static float sum     = 0;
   static float average = 0;
   static float fangcha = 0;
   char         max_class [20],
                max_name [20],
                min_class [20],
                min_name [20];
   int   i, j, c = 0;
   float count1 = 0, count2 = 0, count3 = 0;
   float maxc = m [0].less.chinesegrade,                        //语文最大值
         minc = m [0].less.chinesegrade,                        //语文最小值
         pc,
         maxe = m [0].less.englishgrade,                        //英语最大值
         mine = m [0].less.englishgrade,                        //英语最小值
         pe,
         maxm = m [0].less.mathgrade,                           //数学最大值
         minm = m [0].less.mathgrade,                           //数学最小值
         pm,
         max_score        = maxc + maxe + maxm,                 //总分最大值
         min_score        = minc + mine + minm,                 //总分最小值
         max_chinesegrade = 0,
         max_englishgrade = 0,
         max_mathgrade    = 0,
         max_num,
         min_chinesegrade = 0,
         min_englishgrade = 0,
         min_mathgrade    = 0,
         min_num;

   /*---计算学生分数---*/

   for (i = 1; i < e; i++)         //最大值、最小值、总分最大、总分最小的学生分数
   {
      if (minc > m [i].less.chinesegrade)
      {
         minc = m [i].less.chinesegrade;
      }
      if (maxc < m [i].less.chinesegrade)
      {
         maxc = m [i].less.chinesegrade;
      }
      if (mine > m [i].less.englishgrade)
      {
         mine = m [i].less.englishgrade;
      }
      if (maxe < m [i].less.englishgrade)
      {
         maxe = m [i].less.englishgrade;
      }
      if (minm > m [i].less.mathgrade)
      {
         minm = m [i].less.mathgrade;
      }
      if (maxm < m [i].less.mathgrade)
      {
         maxm = m [i].less.mathgrade;
      }

      /*---计算最大值---*/

      if (max_score < (
             m [i].less.chinesegrade +
             m [i].less.englishgrade +
             m [i].less.mathgrade))
      {
         max_score =
            m [i].less.chinesegrade +
            m [i].less.englishgrade +
            m [i].less.mathgrade;
         max_num = m [i].num;
         strcpy(max_name, m [i].name);
         strcpy(max_class, m [i].clas);
         max_chinesegrade = m [i].less.chinesegrade;
         max_englishgrade = m [i].less.englishgrade;
         max_mathgrade    = m [i].less.mathgrade;
      }

      /*---计算最小值---*/

      if (min_score > (
             m [i].less.chinesegrade +
             m [i].less.englishgrade +
             m [i].less.mathgrade))
      {
         min_score =
            m [i].less.chinesegrade +
            m [i].less.englishgrade +
            m [i].less.mathgrade;
         min_num = m [i].num;
         strcpy(min_name, m [i].name);
         strcpy(min_class, m [i].clas);
         min_chinesegrade = m [i].less.chinesegrade;
         min_englishgrade = m [i].less.englishgrade;
         min_mathgrade    = m [i].less.mathgrade;
      }
   }

   /*---计算及格率---*/

   for (j = 0; j < e; j++)
   {
      sumc = sumc + m [j].less.chinesegrade;
      if (m [j].less.chinesegrade >= 60)
      {
         ++count1;
      }                 //语文成绩
      sume = sume + m [j].less.englishgrade;
      if (m [j].less.englishgrade >= 60)
      {
         ++count2;
      }                 //英语成绩
      summ = summ + m [j].less.mathgrade;
      if (m [j].less.mathgrade >= 60)
      {
         ++count3;
      }                 //数学成绩
   }
   pc = count1;         //语文成绩赋值给 pc
   pe = count2;         //英语成绩赋值给 pe
   pm = count3;         //数学成绩赋值给 pm

   /*---显示提示---*/

   cout << "1. 计算某学生的总分、平均分、方差" << endl;
   cout << "2. 计算全班总成绩信息" << endl;

   /*---读取输入---*/

   int k;
   cin >> k;                //输入一个 k
   if (k == 1)              //显示某个学生的总分及平均分
   {
      cout << "请输入学生学号:" << endl;
      int t;
      cin >> t;
      for (i = 0; i < e; i++)
      {
         if (t == m [i].num)
         {
            sum = m [i].less.chinesegrade +
                  m [i].less.englishgrade +
                  m [i].less.mathgrade;
            average = sum / 3;
            fangcha = ((m [i].less.chinesegrade - average) *
                       (m [i].less.chinesegrade - average) +
                       (m [i].less.englishgrade - average) *
                       (m [i].less.englishgrade - average) +
                       (m [i].less.mathgrade - average) *
                       (m [i].less.mathgrade - average)) / 3;
            cout << "姓名:" << m [i].name
                 << "     总分:" << sum
                 << "     平均分:" << average
                 << "     方差:" << fangcha
                 << endl;
            c++;
         }
      }
      if (c == 0)
      {
         error();
      }
   }
   else         //每个学科的最低最高平均及格率
   {
      cout << "1. 语文成绩 " << endl;
      cout << "2. 英语成绩 " << endl;
      cout << "3. 数学成绩 " << endl;
      cout << "4. 全班成绩 " << endl;
      cout << "5. 返回     " << endl;
      cout << "请输入序号：" << endl;
      int r;
      cin >> r;
      switch (r)
      {
      case 1:
         cout << "语文成绩最高分:  " << maxc << endl;
         cout << "语文成绩最低分:  " << minc << endl;
         cout << "语文全班平均分:  " << sumc / e << endl;
         cout << "语文及格率:  " << pc / e << endl;
         break;

      case 2:
         cout << "英语成绩最高分:  " << maxe << endl;
         cout << "英语成绩最低分:  " << mine << endl;
         cout << "英语全班平均分:  " << sume / e << endl;
         cout << "英语及格率: " << pe / e << endl;
         break;

      case 3:
         cout << "数学成绩最高分:  " << maxm << endl;
         cout << "数学成绩最低分:  " << minm << endl;
         cout << "数学全班平均分:  " << summ / e << endl;
         cout << "数学及格率:  " << pm / e << endl;
         break;

      case 4:
         cout << "全班最高分:  " << max_score << endl;
         cout << "他的信息为:  " << endl;
         cout << setiosflags(ios::left)
              << setw(2) << "学号" << "   "
              << setw(10) << "姓名"
              << setw(10) << "班级"
              << setw(10) << "语文"
              << setw(10) << "英语"
              << setw(10) << "数学" << endl;
         cout << setiosflags(ios::left)
              << setw(5) << max_num << "  "
              << setw(10) << max_name
              << setw(10) << max_class
              << setw(10) << max_chinesegrade
              << setw(10) << max_englishgrade
              << setw(10) << max_mathgrade << endl;
         cout << "全班最低分:  " << min_score << endl;
         cout << "他的信息为:  " << endl;
         cout << setiosflags(ios::left)
              << setw(2) << "学号" << "   "
              << setw(10) << "姓名"
              << setw(10) << "班级"
              << setw(10) << "语文"
              << setw(10) << "英语"
              << setw(10) << "数学" << endl;
         cout << setiosflags(ios::left)
              << setw(5) << min_num << "  "
              << setw(10) << min_name
              << setw(10) << min_class
              << setw(10) << min_chinesegrade
              << setw(10) << min_englishgrade
              << setw(10) << min_mathgrade << endl;
         break;

      case 5:
         cout << "---返回---" << endl;
         return;

         break;

      default:
         error();
         break;
      }
   }
}


/*---9.学生信息写入文件--*/

void save()    //9.学生信息写入文件
{
   int      i;
   ofstream outfile("Student.dat", ios::out);

   if (!outfile)
   {
      cerr << "open Student.dat error!" << endl;
      exit(1);
   }
   outfile << e << endl;
   for (i = 0; i < e; i++)
   {
      outfile << m [i].num << ' ';
      outfile << m [i].name << ' ';
      outfile << m [i].clas << ' ';
      outfile << m [i].less.chinesegrade << ' ';
      outfile << m [i].less.englishgrade << ' ';
      outfile << m [i].less.mathgrade << ' ';
      outfile << m [i].sum << ' ';
      outfile << m [i].average << ' ';
      outfile << endl;
   }
   outfile.close();
   cout << endl;
   cout << "---数据已成功保存---" << endl;
}


/*---加载界面 load---*/

void load()    //加载界面 load
{
   system("cls");
   cout << setiosflags(ios::left)
        << setw(2) << "学号" << "   "
        << setw(10) << "姓名"
        << setw(10) << "班级"
        << setw(10) << "语文"
        << setw(10) << "英语"
        << setw(10) << "数学" << endl;
   ifstream infile("Student.dat", ios::in);
   //    if(!infile)
   //	{
   //			cerr<<"open Student.dat error!"<<endl;
   //			exit(1);
   //	}
   infile >> e;
   for (int i = 0; i < e; i++)
   {
      infile >> m [i].num;
      infile >> m [i].name;
      infile >> m [i].clas;
      infile >> m [i].less.chinesegrade;
      infile >> m [i].less.englishgrade;
      infile >> m [i].less.mathgrade;
      infile >> m [i].sum;
      infile >> m [i].average;
   }
}


/*---主函数 main---*/

int main()    //主界面 main
{
   system("cls");
   system("color F1");
   welcome();                             //调用欢迎界面
   load();                                //调用加载界面
   for ( ; ;)
   {
      //system("cls");                                            //清屏
      cout << " \n\n\n\n\n\n\n\t\t\t   "
           << "*************************" << endl;
      cout << "                          | 欢迎使用学生成绩管理系统 |" << endl;
      cout << "                          |************************|" << endl;
      cout << "                          |　　　　基本功能　　　　　|" << endl;
      cout << "                          |　1.浏览学生成绩信息　　　|" << endl;
      cout << "                          |　2.录入学生成绩信息　　　|" << endl;
      cout << "                          |　3.删除学生成绩信息　　　|" << endl;
      cout << "                          |　4.学号信息查询成绩　　　|" << endl;
      cout << "                          |　5.姓名信息查询成绩　　　|" << endl;
      cout << "                          |　6.课程信息查询成绩　　　|" << endl;
      cout << "                          |　　　　　　　　　　　　　|" << endl;
      cout << "                          |　　　　其他工具　　　　　|" << endl;
      cout << "                          |　7.学生成绩排序工具　　　|" << endl;
      cout << "                          |　8.学生成绩统计工具　　　|" << endl;
      cout << "                          |　9.学生成绩写入文件　　　|" << endl;
      cout << "                          |　　　　　　　　　　　　　|" << endl;
      cout << "                          |　　　　结束操作　　　　　|" << endl;
      cout << "                          |　0.退出学生管理系统　　　|" << endl;
      cout << "                          |************************|" << endl;
      cout << "                           输入「0-9」进入对应功能 " << endl;
      int n;
      cin >> n;
      if ((n >= 0) && (n <= 9))                                 //进入不同的功能
      {
         switch (n)
         {
         case 1:
            show();
            break;                      //浏览学生信息

         case 2:
            input();
            save();
            break;                      //输入学生信息

         case 3:
            delate();
            break;                      //删除学生信息

         case 4:
            numsearch();
            break;                      //学号查询

         case 5:
            namesearch();
            break;                      //姓名查询

         case 6:
            lesssearch();
            break;                      //课程查询

         case 7:
            sort();
            break;                      //排序

         case 8:
            statistics();
            break;                      //统计

         case 9:
            save();
            break;                      //写入文件

         case 0:
            cout << "欢迎您的使用" << endl;
            exit(0);                    //退出

         default:
            break;
         }
         cout << endl;
      }
   }
}
