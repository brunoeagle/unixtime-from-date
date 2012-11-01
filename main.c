#include "stdio.h"

unsigned int passedDaysPerMonth[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

unsigned char leap_year (unsigned int y) {
	if (((!(y % 4)) && (y % 100) ) || (!(y % 400))) return 1;
	else return 0;
}

int main(){
	unsigned long unixTime;
	unsigned int year, month, day, hour, minute, second;
	printf("Year: ");
	scanf("%u", &year);
	year -= 1900;
	printf("Month: ");
	scanf("%u", &month);
	printf("Day: ");
	scanf("%u", &day);
	printf("Hour: ");
	scanf("%u", &hour);
	printf("Minute: ");
	scanf("%u", &minute);
	printf("Second: ");
	scanf("%u", &second);
	unixTime  = second;
	unixTime += minute * 60;
	unixTime += hour * 3600;
	unixTime += passedDaysPerMonth[month] * 86400;
	unixTime += (day - 1) * 86400;
	unixTime += (year - 70) * 31536000;
	unixTime += ((year - 69) / 4) * 86400;
	unixTime -= ((year - 1) / 100) * 86400;
	unixTime += ((year + 299) / 400) * 86400;
	if (leap_year(year) && month >= 3) unixTime += 86400;
	printf("Unix timestamp: %u", unixTime);
}

