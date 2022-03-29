/**
 * Author: Luca Mehrpohl
 * Datum:  15.3.22
 **/

#include <stdio.h>
#include <stdlib.h>


int is_leapyear(int year);
int day_of_the_year(int day, int month, int year);
void input_date(int *day, int *month, int *year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);

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

void input_date(int *day, int *month, int *year){
    printf("Geben Sie das Jahr an: ");
    scanf("%i", *&year);
    printf("Geben Sie den Monat an: ");
    scanf("%i", *&month);
    printf("Geben Sie den Tag an: ");
    scanf("%i", *&day);
}

int exists_date(int day, int month, int year){
    int lower_year_bounds = 1582;
    int upper_year_bounds = 2400;
    if (year < upper_year_bounds && year > lower_year_bounds){
        if(month <= 12 && month >= 1){
            if (day <= get_days_for_month(month - 1, year)){
                return 1;
            }
        }
    }
    printf("Tag existiert nicht\n");
    return 0;
}

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

// gibt tage des jewiligen Monats zurück 
// Monate beginnen mit 0
int get_days_for_month(int month, int year){
    // definieren des Standart lookup tables
    int lookup[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // prüfung ob es ein Schaltjahr ist
    if (is_leapyear(year)){
        lookup[1] = 29;
    }
    return lookup[month];

}

int is_leapyear(int year){
    return (year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0));
}
