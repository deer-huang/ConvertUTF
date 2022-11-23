#include <stdio.h>
#include <string.h>

#include "./ConvertUTF.h"

void show_str(unsigned char const* str)
{
	printf("%s: ", str);
	while((*str) != '\0')
	{
		printf("0x%2x,", *str);	
		str++;
	}
	printf("\n");
}

int main(){
	
	UTF8 str_utf8[] = "苏铁";
	UTF16 str_utf16[6];
	UTF32 str_utf32[6];
	
	uint8_t str_size = sizeof(str_utf8);
	
	printf("str_utf8 sizr :%d\n", str_size);
	
	UTF8* p_utf8 = str_utf8;
	UTF16* p_utf16 = str_utf16;
	
	printf("%s\r\n", str_utf8);
	show_str(str_utf8);
	
	ConvertUTF8toUTF16(&p_utf8, &str_utf8[str_size-1], &p_utf16, &str_utf16[(str_size-1)/2], 0);
	show_str(str_utf16);
	
    return 0;                                          
}