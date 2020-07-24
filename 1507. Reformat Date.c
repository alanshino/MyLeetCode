/* 1507. Reformat Date */
/**
 * Given a date string in the form Day Month Year, where:
     Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
     Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
     Year is in the range [1900, 2100].
 * Convert the date string to the format YYYY-MM-DD, where:
     YYYY denotes the 4 digit year.
     MM denotes the 2 digit month.
     DD denotes the 2 digit day.
 * Example 1:
 * Input: date = "20th Oct 2052"
 * Output: "2052-10-20"
 * Example 2:
 * Input: date = "6th Jun 1933"
 * Output: "1933-06-06"
 * Example 3:
 * Input: date = "26th May 1960"
 * Output: "1960-05-26"
 * Solution:
 * 本來想將年月日先轉換好再放入，但後來發現有點多此一舉。
 * 所以直接採用指標定位的方式做轉換。
 * ptr_index = date + 8 代表直接抓取年分
 * ptr_index = date + 4 代表抓取月份
 * 另外做了一個機制作防範，如果遇到0-9的單數將會產生抓取誤差。
 * 算好回傳大小後直接malloc一個剛好的大小作放置。
 */

char * reformatDate(char * date){
    char *preturn = malloc(sizeof(char) * 11);
    char *ptr_index = date + 8;
    if (*ptr_index == ' ') {  // 有可能產生抓取誤差
        ptr_index++;
    }
    while (*ptr_index) {
        *preturn++ = *ptr_index++;
    }
    *preturn++ = '-';
    ptr_index = date + 4;
    if (*ptr_index == ' ') {  // 有可能產生抓取誤差
        ptr_index++;
    }
    switch (*ptr_index) {     // 月份部分較為複雜，所以向後比較字母來做月份的最終確定
        case 'J':
            ptr_index++;
            if (*ptr_index == 'a') {
                *preturn++ = '0';
                *preturn++ = '1';
            } else {
                ptr_index++;
                if (*ptr_index == 'n') {
                    *preturn++ = '0';
                    *preturn++ = '6';
                } else {
                    *preturn++ = '0';
                    *preturn++ = '7';
                }
            }
            break;
        case 'F':
            *preturn++ = '0';
            *preturn++ = '2';
            break;
        case 'M':
            ptr_index += 2;
            if (*ptr_index == 'r') {
                *preturn++ = '0';
                *preturn++ = '3';
            } else {
                *preturn++ = '0';
                *preturn++ = '5';
            }
            break;
        case 'A':
            ptr_index++;
            if (*ptr_index == 'p') {
                *preturn++ = '0';
                *preturn++ = '4';
            } else {
                *preturn++ = '0';
                *preturn++ = '8';
            }
            break;
        case 'S':
            *preturn++ = '0';
            *preturn++ = '9';
            break;
        case 'O':
            *preturn++ = '1';
            *preturn++ = '0';
            break;
        case 'N':
            *preturn++ = '1';
            *preturn++ = '1';
            break;
        case 'D':
            *preturn++ = '1';
            *preturn++ = '2';
            break;
    }
    *preturn++ = '-';
    ptr_index = date;
    if (*(ptr_index + 1) >= '0' && *(ptr_index + 1) <= '9') {
        *preturn++ = *ptr_index++;
        *preturn++ = *ptr_index++;
    } else {
        *preturn++ = '0';
        *preturn++ = *ptr_index;
    }
    *preturn = 0;
    preturn = preturn - 10;
    return preturn;
}

