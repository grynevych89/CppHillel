#include <stdio.h>

int main()
{
	printf("\n");
	printf("   Name       Age    Salary\n");
	printf("----------------------------\n");
	printf("%s %s %3d %9.2f\n", "1.", "Olexander", 23, 42.25);
	printf("%s %s %8d %11.2f\n", "2.", "Olha", 42, 1423.25);
	printf("%s %s %6d %11.2f\n", "3.", "Mykola", 23, 1422.25);
	printf("%s %s %6d %12.2f\n", "4.", "Nikita", 31, 14112.25);
	printf("%s %s %5d %12.2f\n", "5.", "Vasiliy", 48, 14232.25);
	printf("%s %s %5d %10.2f\n", "6.", "Mariana", 18, 142.25);
	printf("%s %s %4d %11.2f\n", "7.", "Nataliia", 29, 1242.25);

	return 0;
}
