#include <stdio.h>
#include <string.h>
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
	
	uint8_t str_size = (sizeof(str) - 1)/3;
	uint8_t utf8_size = str_size*UTF8_CHAR_SIZE ,
			utf16_size = str_size*UTF16_CHAR_SIZE ,
			utf32_size = str_size*UTF32_CHAR_SIZE ;
			
	UTF8 str_utf8[8];
	UTF16 str_utf16[8];
	UTF32 str_utf32[8];
	
	memcpy(str_utf8, str, sizeof(str));
	
	UTF8* p_utf8 = str_utf8;
	UTF16* p_utf16 = str_utf16;
	UTF32* p_utf32 = str_utf32;
	
	
	uint8_t err_code;
	
	

/*************************************************************************Test UTF8 => UTF16 & UTF32*************************************************************************/
	printf("\n\nstr_utf8 = \n");
	show_str((uint8_t*)str_utf8, utf8_size);
	
	err_code = ConvertUTF8toUTF16((const UTF8**)&p_utf8, (const UTF8*)&str_utf8[utf8_size], &p_utf16, &str_utf16[str_size], strictConversion);
	printf("\nstr_utf8 => str_utf16: \n");
	printf("err_code = %d: \n", err_code);
	show_str((uint8_t*)str_utf16, utf16_size);
	
	err_code = ConvertUTF8toUTF32((const UTF8**)&p_utf8, (const UTF8*)&str_utf8[utf8_size], &p_utf32, &str_utf32[str_size], strictConversion);
	printf("\nstr_utf8 => str_utf32: \n");
	printf("err_code = %d: \n", err_code);
	show_str((uint8_t*)str_utf32, utf32_size);
	
	memset(str_utf8, 0x00, 6);
	memset(str_utf32, 0x00, 6);
/************************************************************************Test UTF16 => UTF8 & UTF32************************************************************************/
	
	printf("\n\n\nstr_utf16 = \n");
	show_str((uint8_t*)str_utf16, utf16_size);
	
	err_code = ConvertUTF16toUTF8((const UTF16**)&p_utf16, (const UTF16*)&str_utf16[str_size], &p_utf8, &str_utf8[utf8_size], strictConversion);
	printf("\nstr_utf16 => str_utf8: \n");
	printf("err_code = %d: \n", err_code);
	show_str((uint8_t*)str_utf8, utf8_size);
	
	err_code = ConvertUTF16toUTF32((const UTF16**)&p_utf16, (const UTF16*)&str_utf16[str_size], &p_utf32, &str_utf32[str_size], strictConversion);
	printf("\nstr_utf16 => str_utf32: \n");
	printf("err_code = %d: \n", err_code);
	show_str((uint8_t*)str_utf32, utf32_size);
	
	memset(str_utf8, 0x00, 6);
	memset(str_utf16, 0x00, 6);
/************************************************************************Test UTF32 => UTF8 & UTF16************************************************************************/
	
	printf("\n\n\nstr_utf32 = \n");
	show_str((uint8_t*)str_utf32, utf32_size);
	
	err_code = ConvertUTF32toUTF8((const UTF32**)&p_utf32, (const UTF32*)&str_utf32[str_size], &p_utf8, &str_utf8[utf8_size], strictConversion);
	printf("\nstr_utf32 => str_utf8: \n");
	printf("err_code = %d: \n", err_code);
	show_str((uint8_t*)str_utf8, utf8_size);
	
	err_code = ConvertUTF32toUTF16((const UTF32**)&p_utf32, (const UTF32*)&str_utf32[str_size], &p_utf16, &str_utf16[str_size], strictConversion);
	printf("\nstr_utf32 => str_utf16: \n");
	printf("err_code = %d: \n", err_code);
	show_str((uint8_t*)str_utf16, utf16_size);
	
    return 0;                                          
}