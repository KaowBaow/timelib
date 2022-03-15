/**
 * Author: Luca Mehrpohl
 * Datum:  15.3.22
 **/

#include <stdio.h>
#include <stdlib.h>

int leapYearCheck(int year){
    return (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0));
}

int day_of_the_year(int day, int month, int year)
{
    // definieren der Daten und der Summe der Tage
    int dayOfYear = 0;

    // definieren des Standart lookup tables
    int lookup[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // prüfung ob es ein Schaltjahr ist
    if (leapYearCheck(year)){
        lookup[1] = 29;
    }

    int i;
    for (i=0; i<month; i++){
        // falls es nicht der richtige monat ist, alle Tage des Monats addieren
        if (month - i > 1){
            dayOfYear += lookup[i];
        // im letzen Monat nur die Tage des Monats aufaddieren
        }else if(month - i == 1 && day <= lookup[i]){
            dayOfYear += day;
        }else{
            printf("Ungültiges Datum\n");
        }
    }

    return dayOfYear;
}

int main()
{
    int day, month, year;

    // einlesen des Datums
    printf("Geben Sie das Jahr an: ");
    scanf("%i", &year);
    printf("Geben Sie den Monat an: ");
    scanf("%i", &month);
    printf("Geben Sie den Tag an: ");
    scanf("%i", &day);

    printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
    return 0;
}
