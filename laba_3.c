#include <stdio.h>
int main(void)
{
    char str[80];
    int i = 0, j, k = 0, m, flag = 0, xflag = 0;
    
    printf("Input line\n");
    fgets(str, 80, stdin);
    char *s = str;
    
    while(*(s+i))
    {
        if(*(s+i) != ' ' && flag == 0)
        {
            flag = 1;
            k = i;
        }
        if(flag == 1 && (*(s+i) == ' ' || *(s+i) == '.' || *(s+i) == '\n' || *(s+i) == ','))
        {
            for(j = k; j < i - 1; j++)
            {
                for(m = k + 1; m < i; m++)
                {
                    if(*(s+j) == *(s+m) && j != m)
                    {
                        xflag = 1;
                    }
                }
            }
            
            if(xflag == 0)
            {
                for(j = k; j < i; j++)
                    printf("%c",*(s+j));
                printf(" ");
            }
            xflag = 0;
            flag = 0;
        }
        i++;
    }
    return 0;
}
