/**
 * Author: Luca Mehrpohl
 * Datum:  15.3.22
 * Aufgabe: Berechnung des Tages-index für ein gegebenes Datum
 **/

#include <stdio.h>
#include <stdlib.h>


int is_leapyear(int year);
int day_of_the_year(int day, int month, int year);
void input_date(int *day, int *month, int *year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int check_year(int year);

int main()
{
    int day, month, year;
    input_date(&day, &month, &year);
    if (exists_date(day, month, year)){
        printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
    }else{
        printf("Das Datum ist nicht gültig");
    }
    return 0;
}

/**
 * zum einlesen des Datums
 * ändert inputvariablen ab
 */
void input_date(int *day, int *month, int *year){
    printf("Geben Sie das Jahr an: ");
    scanf("%i", *&year);
    printf("Geben Sie den Monat an: ");
    scanf("%i", *&month);
    printf("Geben Sie den Tag an: ");
    scanf("%i", *&day);
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
int exists_date(int day, int month, int year){
    if (check_year(year)){
        if(month <= 12 && month >= 1){
            if (day <= get_days_for_month(month - 1, year)){
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
int day_of_the_year(int day, int month, int year)
{
    // definieren der Daten und der Summe der Tage
    int dayOfYear = 0;

    int i;
    for (i=0; i<month; i++){
        // falls es nicht der richtige monat ist, alle Tage des Monats addieren
        if (month - i > 1){
            dayOfYear += get_days_for_month(i, year);
        // im letzen Monat nur die Tage des Monats aufaddieren
        }else if(month - i == 1 && day <= get_days_for_month(i, year)){
            dayOfYear += day;
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
