#include "timelib.h"
#include <stdio.h>

/**
 * zum einlesen des Datums
 * ändert inputvariablen ab
 */
/**
void input_date(struct Date *date){
    printf("Geben Sie das Jahr an: ");
    scanf("%i", &date->year);
    printf("Geben Sie den Monat an: ");
    scanf("%i", &date->month);
    printf("Geben Sie den Tag an: ");
    scanf("%i", &date->day);
}
*/
struct Date input_date(){
    struct Date date;
    printf("Geben Sie das Jahr an: ");
    scanf("%d", &date.year);
    printf("Geben Sie den Monat an: ");
    scanf("%i", &date.month);
    printf("Geben Sie den Tag an: ");
    scanf("%i", &date.day);
    return date;

}

/**
 * prüft Relevanten Jahreszahl
 */
int check_year(int year){
    return (year >= 1582 && year <= 2400);
}

/**
 * Prüft ob das eingegebene Datum ein Gültiges Datum des Gregorianischem Kalenders ist
 */
int exists_date(struct Date date){
    if (check_year(date.year)){
        if(date.month <= 12 && date.month >= 1){
            if (date.day <= get_days_for_month(date.month - 1, date.year)){
                return 1;
            }
        }
    }
    printf("Tag existiert nicht\n");
    return 0;
}

/**
 * Gibt zurück der wie vielte Tag ein gegebenes Datum ist
 */
int day_of_the_year(struct Date date)
{
    // definieren der Daten und der Summe der Tage
    int dayOfYear = 0;

    int i;
    for (i=0; i<date.month; i++){
        // falls es nicht der richtige monat ist, alle Tage des Monats addieren
        if (date.month - i > 1){
            dayOfYear += get_days_for_month(i, date.year);
        // im letzen Monat nur die Tage des Monats aufaddieren
        }else if(date.month - i == 1 && date.day <= get_days_for_month(i, date.year)){
            dayOfYear += date.day;
        }else{
            printf("Ungültiges Datum\n");
            return 0;
        }
    }

    return dayOfYear;
}
/**
 * gibt zurück wie viele Tage der Monat des Jahres hat
 * Monate beginnen mit 0
 * Nur für valide Daten des Gregorianschem Kalenders
 */
int get_days_for_month(int month, int year){

    if (month >= 12 || month < 0 || !check_year(year)){
        return -1;
    }

    // definieren des Standart lookup tables
    int lookup[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


    if (is_leapyear(year)){
        lookup[1] = 29;
    }
    return lookup[month];

}

/**
 * Gibt zurück ob ein gegebenes Schaltjahr ist
 * Nur für valide Jahreszahlen des Gregorianischem Kalender
 */
int is_leapyear(int year){
    if (check_year(year)){
        return (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0));
    }else{
        return -1;
    }
}
