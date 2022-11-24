#include <stdio.h>

#include "./ConvertUTF.h"

#define UTF8_CHAR_SIZE	3
#define UTF16_CHAR_SIZE 2
#define UTF32_CHAR_SIZE 4

void show_str(uint8_t const* str,  uint8_t str_len)
{
	uint8_t len = str_len;

	printf("%s: ", str);
	while( (len--) > 0 )
	{
		printf("0x%02x,", *str);	
		str++;
	}
	printf("\n");
}

int main(){
	
	UTF8 str[] = "苏铁";
	UTF8 *str_utf8 = str;
	UTF16 str_utf16[6];
	UTF32 str_utf32[6];
	
	uint8_t str_size = (sizeof(str_utf8) - 1)/3;
	uint8_t utf8_size = str_size*UTF8_CHAR_SIZE ,
			utf16_size = str_size*UTF16_CHAR_SIZE ,
			utf32_size = str_size*UTF32_CHAR_SIZE ;
	
	
	UTF8* p_utf8 = str_utf8;
	UTF16* p_utf16 = str_utf16;
	UTF32* p_utf32 = str_utf32;
	
	printf("\nstr_utf8 = \n");
	show_str((uint8_t*)str_utf8, utf8_size);
	
	ConvertUTF8toUTF16((const UTF8**)&str_utf8, (const UTF8*)&str_utf8[utf8_size], &p_utf16, &str_utf16[utf16_size-1], strictConversion);
	printf("\nstr_utf16 = \n");
	show_str((uint8_t*)str_utf16, utf16_size);
	
	ConvertUTF8toUTF32((const UTF8**)&str_utf8, (const UTF8*)&str_utf8[utf8_size], &p_utf32, &str_utf32[utf32_size-1], strictConversion);
	printf("\nstr_utf32 = \n");
	show_str((uint8_t*)str_utf32, utf32_size);
	
    return 0;                                          
}