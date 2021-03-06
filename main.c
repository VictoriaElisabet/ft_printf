#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char *s = "teststring";
	int i = 4278;
	float c = 12.123456789;
	float d = 12.00321;
	long double l = 123.56784;

	ft_printf("%d\n", i);
	printf("%d\n", i);
	ft_printf("%10d\n", i);
	printf("%10d\n", i);
	ft_printf("%.7d\n", i);
	printf("%.7d\n", i);
	ft_printf("%+.7d\n", i);
	printf("%+.7d\n", i);
	ft_printf("%-10.7d\n", i);
	printf("%-10.7d\n", i);
	ft_printf("%-10d\n", i);
	printf("%-10d\n", i);
	ft_printf("%-+5.5d\n", i);
	printf("%-+5.5d\n", i);
	ft_printf("%.0d\n", i);
	printf("%.0d\n", i);
	ft_printf("%.0d\n", 0);
	printf("%.0d\n", 0);
	ft_printf("%d\n", 2147483647);
	printf("%d\n", 2147483647);
	ft_printf("%ld\n", -2147483648l);
	printf("%ld\n", -2147483648l);
	ft_printf("%ld\n", -2147483648l);
	printf("%ld\n", -2147483648l);


	ft_printf("%s\n" , "next: i");

	ft_printf("%i\n", i);
	printf("%i\n", i);
	ft_printf("%10i\n", i);
	printf("%10i\n", i);
	ft_printf("%.7i\n", i);
	printf("%.7i\n", i);
	ft_printf("%+.7i\n", i);
	printf("%+.7i\n", i);
	ft_printf("%-10.7i\n", i);
	printf("%-10.7i\n", i);
	ft_printf("%-10i\n", i);
	printf("%-10i\n", i);
	ft_printf("%-+5.5i\n", i);
	printf("%-+5.5i\n", i);
	ft_printf("%.0i\n", i);
	printf("%.0i\n", i);
	ft_printf("%.0i\n", 0);
	printf("%.0i\n", 0);

	ft_printf("%s\n" , "next: o");

	ft_printf("%o\n", i);
	printf("%o\n", i);
	ft_printf("%10o\n", i);
	printf("%10o\n", i);
	ft_printf("%.7o\n", i);
	printf("%.7o\n", i);
	ft_printf("%.7o\n", i);
	printf("%.7o\n", i);
	ft_printf("%-10.7o\n", i);
	printf("%-10.7o\n", i);
	ft_printf("%-#10o\n", i);
	printf("%-#10o\n", i);
	ft_printf("%-8.5o\n", i);
	printf("%-8.5o\n", i);
	ft_printf("%.0o\n", i);
	printf("%.0o\n", i);
	ft_printf("%.0o\n", 0);
	printf("%.0o\n", 0);
	ft_printf("%#16o\n", i);
	printf("%#16o\n", i);

	ft_printf("%s\n" , "next: u");

	ft_printf("%u\n", i);
	printf("%u\n", i);
	ft_printf("%10u\n", i);
	printf("%10u\n", i);
	ft_printf("%.7u\n", i);
	printf("%.7u\n", i);
	ft_printf("%.7u\n", i);
	printf("%.7u\n", i);
	ft_printf("%-10.7u\n", i);
	printf("%-10.7u\n", i);
	ft_printf("%-10u\n", i);
	printf("%-10u\n", i);
	ft_printf("%-8.5u\n", i);
	printf("%-8.5u\n", i);
	ft_printf("%.0u\n", i);
	printf("%.0u\n", i);
	ft_printf("%.0u\n", 0);
	printf("%.0u\n", 0);
	ft_printf("%16u\n", i);
	printf("%16u\n", i);

	ft_printf("%s\n" , "next: x");

	ft_printf("%x\n", i);
	printf("%x\n", i);
	ft_printf("%10x\n", i);
	printf("%10x\n", i);
	ft_printf("%.7x\n", i);
	printf("%.7x\n", i);
	ft_printf("%.7x\n", i);
	printf("%.7x\n", i);
	ft_printf("%-10.7x\n", i);
	printf("%-10.7x\n", i);
	ft_printf("%-10x\n", i);
	printf("%-10x\n", i);
	ft_printf("%-8.5x\n", i);
	printf("%-8.5x\n", i);
	ft_printf("%.0x\n", i);
	printf("%.0x\n", i);
	ft_printf("%.0x\n", 0);
	printf("%.0x\n", 0);
	ft_printf("%#16x\n", i);
	printf("%#16x\n", i);

	ft_printf("%s\n" , "next: X");

	ft_printf("%X\n", i);
	printf("%X\n", i);
	ft_printf("%10X\n", i);
	printf("%10X\n", i);
	ft_printf("%.7X\n", i);
	printf("%.7X\n", i);
	ft_printf("%.7X\n", i);
	printf("%.7X\n", i);
	ft_printf("%-10.7X\n", i);
	printf("%-10.7X\n", i);
	ft_printf("%-10X\n", i);
	printf("%-10X\n", i);
	ft_printf("%-8.5X\n", i);
	printf("%-8.5X\n", i);
	ft_printf("%.0X\n", i);
	printf("%.0X\n", i);
	ft_printf("%.0X\n", 0);
	printf("%.0X\n", 0);
	ft_printf("%#16X\n", i);
	printf("%#16X\n", i);

	ft_printf("%s\n" , "next: f");

	ft_printf("%f\n", c);
	printf("%f\n", c);
	ft_printf("%10f\n", c);
	printf("%10f\n", c);
	ft_printf("%+.7f\n", c);
	printf("%+.7f\n", c);
	ft_printf("% .7f\n", c);
	printf("% .7f\n", c);
	ft_printf("%-10.7f\n", c);
	printf("%-10.7f\n", c);
	ft_printf("%-10f\n", c);
	printf("%-10f\n", c);
	ft_printf("%-8.5f\n", c);
	printf("%-8.5f\n", c);
	ft_printf("%.0f\n", c);
	printf("%.0f\n", c);
	ft_printf("%.0f\n", 0.0);
	printf("%.0f\n", 0.0);
	ft_printf("%#16f\n", c);
	printf("%#16f\n", c);
	ft_printf("%#.0f\n", c);
	printf("%#.0f\n", c);
	ft_printf("%#8.8f\n", c);
	printf("%#8.8f\n", c);
	ft_printf("%f\n", d);
	printf("%f\n", d);
	ft_printf("%10f\n", d);
	printf("%10f\n", d);
	ft_printf("%+.7f\n", d);
	printf("%+.7f\n", d);
	ft_printf("% .7f\n", d);
	printf("% .7f\n", d);
	ft_printf("%-10.7f\n", d);
	printf("%-10.7f\n", d);
	ft_printf("%-10f\n", d);
	printf("%-10f\n", d);
	ft_printf("%-8.5f\n", d);
	printf("%-8.5f\n", d);
	ft_printf("%.0f\n", d);
	printf("%.0f\n", d);
	ft_printf("%.0f\n", 0.0);
	printf("%.0f\n", 0.0);
	ft_printf("%#16f\n", d);
	printf("%#16f\n", d);
	ft_printf("%#.0f\n", d);
	printf("%#.0f\n", d);
	ft_printf("%#8.8f\n", d);
	printf("%#8.8f\n", d);
	ft_printf("%#f\n", d);
	printf("%#f\n", d);
	ft_printf("%#f\n", 12.001);
	printf("%#f\n", 12.001);
	ft_printf("%#f\n", 1.0);
	printf("%#f\n", 1.0);
	ft_printf("%f\n", 2147483647.0);
	printf("%f\n", 2147483647.0);
	ft_printf("%f\n", -2147483648.0);
	printf("%f\n", -2147483648.0);
	ft_printf("%8.8Lf\n", l);
	printf("%8.8Lf\n", l);
	ft_printf("%Lf\n", l);
	printf("%Lf\n", l);
	ft_printf("%#2.5Lf\n", l);
	printf("%#2.5Lf\n", l);
	ft_printf("%.0f\n", d);
	printf("%.0f\n", d);


	ft_printf("%s\n" , "next: c");

	ft_printf("%-3c%-4c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c\n", '"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	printf("%-3c%-4c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c\n", '"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	
	ft_printf("%s\n" , "next: s");

	ft_printf("%s\n", s);
	printf("%s\n", s);
	ft_printf("%10s\n", s);
	printf("%10s\n", s); 
	ft_printf("%.7s\n", s);
	printf("%.7s\n", s);
	ft_printf("%.7s\n", s);
	printf("%.7s\n", s);
	ft_printf("%-10.7s\n", s);
	printf("%-10.7s\n", s);
	ft_printf("%-10s\n", s);
	printf("%-10s\n", s);
	ft_printf("%-8.5s\n", s);
	printf("%-8.5s\n", s);
	ft_printf("%.0s\n", s);
	printf("%.0s\n", s);
	ft_printf("%.0s\n", "0");
	printf("%.0s\n", "0");
	ft_printf("%16s\n", s);
	printf("%16s\n", s);

	ft_printf("%s\n" , "next: p");

	ft_printf("%p\n", s);
	printf("%p\n", s);
	ft_printf("%10p\n", s);
	printf("%10p\n", s);
	ft_printf("%7p\n", s);
	printf("%7p\n", s);
	ft_printf("%7p\n", s);
	printf("%7p\n", s);
	ft_printf("%-10p\n", s);
	printf("%-10p\n", s);
	ft_printf("%-10p\n", s);
	printf("%-10p\n", s);
	ft_printf("%-8p\n", s);
	printf("%-8p\n", s);
	ft_printf("%p\n", s);
	printf("%p\n", s);
	ft_printf("%p\n", "0");
	printf("%p\n", "0");
	ft_printf("%16p\n", s);
	printf("%16p\n", s);

	ft_printf("%s\n" , "next: %");

	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%10%\n");
	printf("%10%\n");
	ft_printf("%7%\n");
	printf("%7%\n");
	ft_printf("%7%\n");
	printf("%7%\n");
	ft_printf("%-10%\n");
	printf("%-10%\n");
	ft_printf("%-10%\n");
	printf("%-10%\n");
	ft_printf("%-8.9%\n");
	printf("%-8.9%\n");
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("japp%16%\n");
	printf("japp%16%\n");
	ft_printf("test%%\n");
	printf("test%%\n");

	//char *str = "japp\0";
	//done = ft_printf(3, 10, 4,i 7);
	//system("leaks a.out");
	//ft_printf("%c", 't');
	//ft_printf("%+#10.5x\n", 3723);
	//ft_printf("%7.4d", 5263);
	////ft_printf("%+10.5d\n", 3723);
	//ft_printf("%7.2p\n", &i);
	//printf("%7.2p\n", &i);
	//printf("%+10f\n", t); 
	//ft_printf("%+ 10.10f\n", 1.4567);
	//printf("%+10.10f\n", 1.4567); 
	//printf("\n");
	//printf("%lld\n", ft_power_of(10, 12));
	//printf("111%s333%.2s555", "222", "444");
	//system("leaks a.out");
	//ft_printf("%d", printf("%17p", &42));
	//ft_printf("%7.3s\n", "jovars");
	//ft_printf("hello, %s\n", NULL);
	//printf("hello, %s", NULL);
	//system("leaks a.out");
}
