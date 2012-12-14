#include<stdio.h>

/*复制字符串*/
char *rt_strcpy(char *des, const char *source)
{
    char *p = des;
    while(*des++ = *source)
        ;
    return p;
}

/*比较字符串*/
int rt_strcmp(const char *s, const char *t)
{
    for(;*s == *t;s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;
}

/*将字符查ut追加到字符串s的后面*/
char *rt_strcat(char *s, const char *t)
{
    char *p = s;
    while(*s)
        ++s;
    while(*s++ = *t++)
        ;
    return p;
}

/*判断字符串t是否出现在字符串s的末尾*/
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

/*最多复制n个字符,若source的长度不足n个字符，则使用‘\0’补充至n个*/
char *rt_strncpy(char *des, const char *source, int n)
{
    char *p = des;

    while(n-- && (*des++ = *source++))
        ;

    while(n-- > 0)
        *des++ = '\0';
    return p;
}

/*最多追加n个字符*/
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

/*比较两字符串前n位的大小*/
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


