int strConteins(char* a, char* str)
{
	int n = -1;
	int m = 0;
	while (str[m] != '\0')
	{
		if (str[m] == a[0])
		{
			bool was_found = true;
			int i = 0;
			while (a[i] != '\0')
			{
				if (a[i] != str[m + i])
				{
					was_found = false;
					break;
				}
				i++;
			}
			if (was_found)
			{
				n = i;
				break;
			}
		}
		m++;
	}
	return n;
}