//in the name of god

#include <stdio.h>

//defining the spacing of the individual cells and gap in between columns
#define col_gap_val 2
#define row_gap_val 2
#define tabsize 3

//defining the vertical separator of length 3 and blank of length 3

#define line printf("%*s",tabsize ,"---")
#define blank printf("%*s",tabsize ,"")

//newline 'cause I can't keep typing it

#define endl puts("")

void col_gap(){
    for (int j = 0; j < col_gap_val; j++){
        blank;
    }
}

void row_gap(){
    for (int j = 0; j < row_gap_val; j++){
        endl;
    }
}


int main(){

    //take the year as an input
    unsigned long long year;

    puts("Please enter an year:");
    scanf("%llu", &year);

    //Array for names of days
    char *day[7] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};

    //Array for names of months
    char *month_name[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    //Hold number of days in a month
    unsigned short days_in_month[12];

    //Often feel like just hardcoding it would have been easier
    for (int i = 1; i < 13; i++){        
        switch(i){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: days_in_month[i-1] = 31; break;
            case 2: days_in_month[i-1] = (year%4 == 0 && year%100 != 0)||(year%400 == 0)?29:28; break;
            case 4:
            case 6:
            case 9:
            case 11: days_in_month[i-1] = 30; break;
        }
        
    }

    //Remainder of each month to be used as an offset from Monday
    unsigned short month_offset[12];

    //Offset of Jan depends on the year taken
    month_offset[0] = ((((year-1)%400)/100)*5 + ((year-1)%100)*365 + ((year-1)%100)/4)%7;

    //Offset of other months depend on the previous months
    for (unsigned short i = 1; i < 12; i++){
        month_offset[i] = (month_offset[i-1] + days_in_month[i-1])%7;
    }

    row_gap();
    for (int i = 0; i < 10; i++){
        blank;
    } col_gap();
    printf("%0*llu", tabsize, year);
    row_gap(); 

    //Four iterations for four rows
    for (unsigned short row_iterator = 0; row_iterator < 4; row_iterator++){

        //Month Headers
        printf("%*s%*s%*s", 4*tabsize, month_name[3*row_iterator], (7 + col_gap_val)*tabsize, month_name[3*row_iterator + 1], (7 + col_gap_val)*tabsize, month_name[3*row_iterator + 2]);

        row_gap();

        //Day Headers
        for (unsigned short month_iterator = 0; month_iterator < 3; month_iterator++){
            for (unsigned short day_iterator = 0; day_iterator < 7; day_iterator++){
                printf("%*s", tabsize, day[day_iterator]);
            }
            col_gap();
        }
    
        endl;

        //Divider under day header
        for (unsigned short month_iterator = 0; month_iterator < 3; month_iterator++){
            for (unsigned short day_iterator = 0; day_iterator < 7; day_iterator++){
                line;
            }
            col_gap();
        }
    
        endl;

        //to store the last printed number of each month in each line
        unsigned short flag[3] = {0};

        //First row(week) of each month in the calendar
        for (unsigned short month_iterator = 0; month_iterator < 3; month_iterator++){
            //to leave blanks corresponding to the previous month / according to the Jan of that year
            for (unsigned short day_iterator = 0; day_iterator < month_offset[3*row_iterator + month_iterator]; day_iterator++){
                blank;
            }
            //print the days till Sunday
            for (unsigned short day_iterator =  0; day_iterator + month_offset[3*row_iterator + month_iterator] < 7; day_iterator++){
                printf("%*d", tabsize, day_iterator + 1);
                flag[month_iterator] = day_iterator + 1;
            }
            col_gap();
        }
    
        endl;

        //Print the next three weeks
        for (unsigned short week_iterator = 0; week_iterator < 3; week_iterator++){
            for (unsigned short month_iterator = 0; month_iterator < 3; month_iterator++){
                for (unsigned short day_iterator = 0; day_iterator < 7; day_iterator++){
                    printf("%*d", tabsize, day_iterator + flag[month_iterator] + 1);
                }
                flag[month_iterator] += 7;
                col_gap();
            }
            endl;
        }

        //Stores if a sixth line is required for any month or not
        unsigned short sixlines[3] = {0};

        //Print the last/second-last row of each month
        for (int month_iterator = 0; month_iterator < 3; month_iterator++){
            int day_iterator =  0;
            for (; day_iterator + flag[month_iterator] < days_in_month[3*row_iterator + month_iterator]; day_iterator++){
                printf("%*d", tabsize, day_iterator + flag[month_iterator] + 1);
                //check if sixth line is reqd for any month
                if (day_iterator == 6) {
                    sixlines[month_iterator] = 1;
                    flag[month_iterator] += 7;
                    break;
                }
            }

            //printing necessary blanks if sixth line isnt required
            if (sixlines[month_iterator] == 0){
                for (int k = 0; k <= 6 - day_iterator; k++){
                    blank;
                }
            }
            col_gap();
        }
        endl;

        for (int month_iterator = 0; month_iterator < 3; month_iterator++){
            if (sixlines[month_iterator] != 0){
                for (int day_iterator = 0; day_iterator + flag[month_iterator] < days_in_month[3*row_iterator + month_iterator]; day_iterator++){
                    printf("%*d", tabsize, day_iterator + flag[month_iterator] + 1);
                }
                for (int day_iterator = 0; (day_iterator + days_in_month[3*row_iterator + month_iterator])%7 != 0; day_iterator++){
                    blank;
                }
            } else {
                for (int day_iterator = 0; day_iterator < 7; day_iterator++){
                    blank;
                }
            }
            col_gap();
        }
        
        row_gap();
    
    }    
}
