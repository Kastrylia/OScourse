#include <stdio.h>
#include <stdlib.h>
int main()
{
	char temp[200];
	while(1==1)
	{
		fgets(temp,200,stdin);
		char *args[200];
		int i = 0;
		int j = 0;
		int t=0;
		for(i=0;i<200;i++)
		{
			args[i]=NULL;
		}
		i=0;
		args[0]=(char*)malloc(200);	
		while(1==1)
		{
			if(temp[i]!=' ' && temp[i]!='\n' && temp[i]!='\0')
			{
				args[t][j]=temp[i];
				i++,j++;
			}
			else if(temp[i]==' ')
			{
				j = 0;
				i++,t++;
				args[t]=(char*)malloc(200);
			}
			else
			{
				break;
			}
		}
		int pid=fork();
		if(pid==0)
		{
			execvp(args[0],args,NULL);
		}
	}
	return 0;
}
