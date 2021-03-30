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
	int cnt = 0, cnt_2 = 0, cnt_3 = 0, pos_1, pos_2, i = 0;
	int str[30000] = { 0 };
	int *pr = str;

	while (*pc != '\0')
	{
		switch (*pc)
		{
		case '+': str[cnt_2] = str[cnt_2] + 1; break;
		case '-': str[cnt_2] = str[cnt_2] - 1; break;
		case '>': cnt_2++; break;
		case '<': cnt_2--; break;
		case '[': pos_1 = cnt; pos_2 = cnt_2; break;
		case ']': if (str[cnt_2] != 0) { pc = pc - (cnt - pos_1); cnt_2 = pos_2; cnt = pos_1; }
				else if (str[cnt_2] == 0) { break; } break;
		case '.': ascii_char[i] = str[cnt_2]; i++; break;
		}
		cnt++;
		pc++;
	}
}
