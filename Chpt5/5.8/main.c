#include<stdio.h>

static int daytab[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/*将某年某月某日转换为该年的第几天*/
int day_of_year(int year, int month, int day)
{
	int i = 0;
	int isleapyear;
	isleapyear = is_leap_year(year);
	for(i = 0;i < month - 1;i++)
	  day += daytab[isleapyear][i];
	return day;
}

/*将某年的第n天转换为月份和日*/
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int isleapyear = 0;
	int month = 1;
	int days = 0;

	isleapyear = is_leap_year(year);
	for(month = 1;month <= 12;month++)
	{
		if(days + daytab[isleapyear][month - 1] >= yearday)
		  break;
		days += daytab[isleapyear][month - 1];
	}

	*pmonth = month;
	*pday = yearday - days;
}

/*根据月份返回英文*/
char *month_name(int n)
{
	/*static char *name[] = */
	static char name[][15] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	printf("sizeof name is %d\n", sizeof(name));

	return (n < 1 || n > 12) ? name[0] : name[n];
}

int main()
{
	int year,month,day,yearday;

	yearday = day_of_year(2012, 12, 20);
	printf("2012年12月20日是2012年的第 %d 天\n", yearday);

	month_day(2012, yearday, &month, &day);
	printf("2012年的第 %d 天是 %d 月 %d 日\n", yearday, month, day);

	printf("English Name of 12th month is %s\n", month_name(12));

	return 0;
}
