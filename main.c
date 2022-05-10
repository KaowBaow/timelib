/**
 * Author: Luca Mehrpohl
 * Datum:  15.3.22
 * Aufgabe: Berechnung des Tages-index für ein gegebenes Datum
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"


int main()
{
    int day, month, year;
    struct Date date = input_date();
    if (exists_date(date)){
        printf("Tag des Jahres: %i\n", day_of_the_year(date));
    }else{
        printf("Das Datum ist nicht gültig");
    }
    return 0;
}

