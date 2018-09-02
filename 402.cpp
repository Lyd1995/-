int findword()
{
	int len=strlen(str);
	int i=0,count=0;
	while(len)
	{
		if(ischar(str[i]))
		{
			while(ischar(str[i])&&len)
			{
				i++;
				len--;
			}
			count++;
		}
		else
		{
			i++;
			len--;
		}
	}
	return count;
}

int ischar(char c)
{
	if((c>='a' && c<='z') || (c>='A'&& c<='Z'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
