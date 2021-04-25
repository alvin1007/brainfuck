#include <stdio.h>

int ascii_char[30000] = { 0 };

void transform(char* pc);

int main()
{
	int i = 0;
	char code[30000];
	printf("입력 : ");
	scanf("%s", code);
	transform(code);
	while (ascii_char[i] != 0)
	{
		printf("%c", ascii_char[i]);
		i++;
	}
	return 0;
}
void transform(char* pc)
{
	int cnt1, cnt2, ptr = 0, i = 0, j = 0;
	int str[30000] = { 0 };

	while (*pc != '\0')
	{
		switch (*pc)
		{
		case '+': str[ptr] = str[ptr] + 1; break;
		case '-': str[ptr] = str[ptr] - 1; break;
		case '>': ptr++; break;
		case '<': ptr--; break;
		case '[': if (str[ptr] == 0) 
		{
			cnt1 = 1;
			while (1)
			{
				if (cnt1 == 0) break;
				pc++;
				if (*pc == '[')
				{
					cnt1++;
				}
				else if (*pc == ']')
				{
					cnt1--;
				}
				else continue;
			}
		} break;
		case ']': if (str[ptr] != 0)
		{
			cnt2 = 1;
			while (1)
			{
				if (cnt2 == 0) break;
				pc--;
				if (*pc == '[')
				{
					cnt2--;
				}
				else if (*pc == ']')
				{
					cnt2++;
				}
				else continue;
			}
		} break;
		case '.': ascii_char[i] = str[ptr]; i++; break;
		}
		pc++;
	}
}