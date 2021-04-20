#include <stdio.h>

int ascii_char[30000] = { 0 };

void arr(int* pa);
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
	int cnt = 0, ptr = 0, i = 0, j = 0;
	int pos_1[1000] = { 0 };
	int pos_2[1000] = { 0 };
	int str[30000] = { 0 };

	while (*pc != '\0')
	{
		switch (*pc)
		{
		case '+': str[ptr] = str[ptr] + 1; break;
		case '-': str[ptr] = str[ptr] - 1; break;
		case '>': ptr++; break;
		case '<': ptr--; break;
		case '[': pos_1[j] = cnt; pos_2[j] = ptr; j++; break;
		case ']': if (str[ptr] != 0) { pc = pc - (cnt - pos_1[j - 1]); cnt = pos_1[j - 1];  ptr = pos_2[j - 1]; }
				else if (str[ptr] == 0) { arr(pos_2); arr(pos_1); j = j - 1; } break;
		case '.': ascii_char[i] = str[ptr]; i++; break;
		}
		cnt++;
		pc++;
	}
}
void arr(int* pa)
{
	while (*pa != 0)
	{
		pa++;
		if (*pa == 0)
		{
			pa--;
			*pa = 0;
			break;
		}
	}
}