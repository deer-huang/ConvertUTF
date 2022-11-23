#include <stdio.h>
#include <string.h>

#include "ConvertUTF.h"

void show_str(unsigned char const* str)
{
	while((*str) != '\0')
	{
		printf("%x,", *str);
		str++;
	}
	printf("\n");
}

int main(){
	
	UTF8 str_utf8[] = "苏铁";
	UTF16 str_utf16[10];
	
	printf("%s\r\n", str_utf8);
	show_str(str_utf8);
	
	//ConvertUTF8toUTF16(NULL, NULL, NULL, NULL);
	//ConvertUTF8toUTF16(&(&str_utf8), &(str_utf8+5), &(&str_utf16), &(str_utf16+3));
    return 0;
}