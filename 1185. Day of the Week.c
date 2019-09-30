int leap(int year);
char * dayOfTheWeek(int day, int month, int year){
    int time = 0;
    int monthTime[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *returnDay[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 1971; i < year; i++) {
        if (leap(i)) {
            time += 366;
        }else {
            time += 365;
        }
    }
    for (int i = 0; i < month - 1; i++) {
        time += monthTime[i];
    }
    if (month > 2 && leap(year))
        time++;
    time += day;
    time = time % 7;
    printf("%d ", time);
    return returnDay[(time + 4) % 7];
}

int leap(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;
    }else {
        return 0;
    }
}

/**

Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

*/
