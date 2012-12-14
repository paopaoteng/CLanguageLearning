#include<stdio.h>

/*�����ַ���*/
char *rt_strcpy(char *des, const char *source)
{
    char *p = des;
    while(*des++ = *source)
        ;
    return p;
}

/*�Ƚ��ַ���*/
int rt_strcmp(const char *s, const char *t)
{
    for(;*s == *t;s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}

/*���ַ���ut׷�ӵ��ַ���s�ĺ���*/
char *rt_strcat(char *s, const char *t)
{
    char *p = s;
    while(*s)
        ++s;
    while(*s++ = *t++)
        ;
    return p;
}

/*�ж��ַ���t�Ƿ�������ַ���s��ĩβ*/
int rt_strend(const char *s, const char *t)
{
    const char *p = t;

    while(*s)
        s++;
    while(*t++)
        s--;
    
    /*return (rt_strcmp(s, p) == 0) ? 1 : 0;*/
    for(;*s == *p;s++, p++)
        if(*s == '\0')
            return 1;
    return 0;
}

/*��ิ��n���ַ�,��source�ĳ��Ȳ���n���ַ�����ʹ�á�\0��������n��*/
char *rt_strncpy(char *des, const char *source, int n)
{
    char *p = des;

    while(n-- && (*des++ = *source++))
        ;

    while(n-- > 0)
        *des++ = '\0';
    return p;
}

/*���׷��n���ַ�*/
char *rt_strncat(char *des, const char *source, int n)
{
    char *p = des;
    while(*des)
        ++des;
    while(n-- && (*des++ = *source++))
        ;
    *des = '\0';
    return p;
}

/*�Ƚ����ַ���ǰnλ�Ĵ�С*/
int rt_strncmp(const char *s, const char *t, int n)
{
    for(;*s == *t && n--;s++, t++)
        if(*s == '\0' || n == 0)
            return 0;
    return *s - *t;
}

int main()
{
    char s[20] = "123abc";
    char t[20] = "123456";
    printf("%d\n", rt_strncmp(s, t, 4));

    return 0;
}


