#include "../includes/libft.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

unsigned int	ft_uni_to_utf8(wchar_t codepoint);

void	compare(wchar_t unicode)
{
	unsigned int	utf8;

	ft_putstr("Unicode = ");
	ft_puthex(unicode, "min");
	utf8 = ft_uni_to_utf8(unicode);
	ft_putstr("\nUTF-8 = ");
	write(1, &utf8, 4);
	printf("\nWith printf : %lc\n", unicode);
	ft_print_memory(&utf8, 4);
	ft_putchar('\n');
}

int	main(void)
{
	setlocale(LC_ALL, "");

	compare(0xE9);
	compare(0x7F7);
	compare(0x20AC);
	compare(0x20012);
	return (0);
}
