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
    struct Date date = input_date();
    if (exists_date(date)){
        printf("Tag des Jahres: %i\n", day_of_the_year(date));
    }else{
        printf("Das Datum ist nicht gültig");
    }
    char dow;
    //get_day_of_week(date, &dow);
    printf("Der aktuelle Tag ist %c", dow);
    return 0;
}

