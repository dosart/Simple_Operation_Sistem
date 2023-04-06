#include "lib/string.h"

void* memcpy(void* dest, const void* src, size_t n)
{
    char* tmp_dest = (char*)dest;
    const char* tmp_src = (const char*)src;

    for(size_t i = 0; i < n; ++i)
    {
        tmp_dest[i] = tmp_src[i];
    }
    return dest;
}

void* memset(void* buf, char z, size_t bytes)
{
    char* tmp_buf = buf;
    while(bytes)
    {
        *tmp_buf++ = z;
        --bytes;
    }
    return buf;
}

int strcmp(const char* str1, const char* str2)
{
    while(1)
    {
        if(*str1 != *str2)
            return (*str1 - *str2);
        if(*str1 == '\0')
            return 0;
        ++str1;
        ++str2;
    }
}

char* strcat(char* dest, const char* src)
{
    register char* origin = dest;

    while(*dest != '\0')
        ++dest;
    while(*src != '\0')
        *dest++ = *src++;
    *dest = '\0';

    return origin;
}

size_t strlen(const char* str)
{
    size_t i = 0;
    while(*str != '\0')
    {
        ++str;
        ++i;
    }
    return i;
}

char* strcpy(char* dest, const char* src)
{
    char* original = dest;
    while((*dest++ = *src++))
        ;
    return original;
}

char* strcpyn(char* dest, const char* src, size_t n)
{
    char* original = dest;
    size_t i = 0;
    while(*src != '\0' && i < n)
    {
        *dest++ = *src++;
        ++i;
    }
    return original;
}

size_t strspn(const char* str, char* accept)
{
    size_t count = 0;
    while(*str && strch(accept, *str++))
        count++;

    return count;
}

size_t strcspn(const char* str, char* accept)
{
    size_t count = 0;
    while(*str)
    {
        if(strch(accept, *str++))
            return count;
        ++count;
    }
    return count;
}

char* strch(char* str, char c)
{
    size_t i = 0;
    while(str[i] && str[i] != c)
        ++i;
    return c == str[i] ? (char*)str + i : NULL;
}

char* strext(char* buf, const char* str, char sym)
{
    while(*str != '\0')
    {
        *buf++ = *str++;
        *buf++ = sym;
    }

    return buf;
}

char* itoa(uint32_t value, char* str, uint32_t base)
{
    char* original = str;
    char digit;

    do
    {
        digit = value % base;
        value = value / base;
        if(digit < 10)
        {
            *str++ = digit | 0x30; /* number */
        }
        else if(digit < 16)
        {
            *str++ = ((digit - 10) | 0x40) + 1; /* alpha */
        }
        else
        {
            *str++ = '?';
        }
    } while(value > 0);

    if(base == 16)
    {
        /* hexedecimal integer */
        *str++ = 'x';
        *str++ = '0';
    }
    else if(base == 8)
    {
        /* octal integer */
        *str++ = 'o';
        *str++ = '0';
    }
    else if(base == 2)
    {
        /* binary integer */
        *str++ = 'b';
        *str++ = '0';
    }
    *str++ = '\0';

    strinv(original);

    return str;
}

char* strinv(char* str)
{
    uint32_t n = strlen(str);
    char buf[n + 2];
    char* cur = buf;

    for(uint32_t i = n - 1; i >= 0; --i)
    {
        *cur++ = str[i];
    }
    *cur++ = '\0';

    strcpy(str, buf);

    return str;
}

uint32_t vsprintf(char* s1, const char* s2, va_list list)
{
    return vsnprintf(s1, 4 * 1024, s2, list);
}

uint32_t vsnprintf(char* s1, uint32_t n, const char* s2, va_list list)
{
    uint32_t j = 0;
    size_t count = 0;
    char number[32];
    char* cur = s1;
    char* str;

    while(s2[j] != '\0' && j < n)
    {
        if(s2[j] != '%')
        {
            /* text */
            *cur++ = s2[j++];
        }
        else if(s2[j] == '%')
        {
            /* control character */
            switch(s2[++j])
            {
            case 'c':
                /* character */
                *cur++ = va_arg(list, char);
                break;
            case 'u':
                /* unsigned decimal */
                itoa(va_arg(list, uint32_t), number, 10);
                strcpy(cur, number);
                cur += strlen(number);
                break;
            case 'X':
                /* unsigned hexedecimal */
                itoa(va_arg(list, uint32_t), number, 16);
                strcpy(cur, number);
                cur += strlen(number);
                break;
            case 's':
                /* string */
                str = va_arg(list, char*);
                strcpy(cur, str);
                cur += strlen(str);
                break;
            }
            j += 1;
        }
    }

    count = ((size_t)cur - (size_t)s1);
    *cur++ = '\0';

    va_end(list);

    return count;
}
