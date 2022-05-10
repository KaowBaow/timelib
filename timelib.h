struct Date{
    int day;
    int month;
    int year;
};

struct Date input_date();
int exists_date(struct Date);
int day_of_the_year(struct Date);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int check_year(int year);
void get_day_of_week(struct Date date, char *day);
