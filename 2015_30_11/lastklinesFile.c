#include<stdio.h>
void lastkline(char *str,int k);
int main()
{
    lastkline("test.txt",5);
}
/* Make two file pointer. Fix one at first line and make other move k lines.
after that move both  till the second pointer reaches EOF. First pointer will now point to last kth line
*/

void lastkline(char *name,int k)
{
    FILE *fp1, *fp2; 
    char ch;
    fp1 = fopen(name,"r");
    fp2 = fopen(name,"r");
    while(k > 0)
    {
        ch = getc(fp1);
        if(ch == EOF)   //There are less than k lines
            return;
        if(ch == '\n')
            k--;
    }

    while((ch=getc(fp1)) != EOF)
    {
        if(ch == '\n')
        {
            while((ch=getc(fp2)) != '\n');

        }
    }
    while((ch=getc(fp2))!=EOF)
    {
        printf("%c",ch);
    }

    fclose(fp1);
    fclose(fp2);
}

