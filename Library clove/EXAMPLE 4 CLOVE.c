#include <clove.h>

Init()
	Begin
	    // Teste das funções de manipulação de datas
	    Date date1 = createDate(1, January, 2023);
	    Date date2 = createDate(5, February, 2023);
	
	    printf("Date 1: %d/%d/%d\n", date1.day, date1.month, date1.year);
	    printf("Date 2: %d/%d/%d\n", date2.day, date2.month, date2.year);
	
	    int result = compareDates(date1, date2);
	    
	    if (result < 0)
	        printf("Date 1 is before Date 2.\n");
	    else if (result > 0)
	        printf("Date 2 is before Date 1.\n");
	    else
	        printf("Date 1 and Date 2 are the same.\n");
	
	    Date date3 = addDays(date1, 45);
	    printf("45 days after Date 1: %d/%d/%d\n", date3.day, date3.month, date3.year);
	
	    Date date4 = subtractDays(date2, 15);
	    printf("15 days before Date 2: %d/%d/%d\n", date4.day, date4.month, date4.year);
	
	    Week weekday = getWeekday(date1);
	    printf("Weekday of Date 1: ");
	    printWeekday(weekday);
	
	    Week weekday2 = getWeekday(date2);
	    printf("Weekday of Date 2: ");
	    printWeekday(weekday2);
	
	    int dayOfYear = getDayOfYear(date2);
	    printf("Day of the year for Date 2: %d\n", dayOfYear);
	
	    return 0;
	end