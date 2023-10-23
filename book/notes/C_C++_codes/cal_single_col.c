//in the name of god

#include <stdio.h>

//defining the spacing of the individual cells

#define tabsize 4

//defining the vertical separator of length 4 and blank of length 4

#define line printf("%*s",tabsize ,"----")
#define blank printf("%*s",tabsize ,"")

//newline 'cause I can't keep typing it

#define endl printf("\n")

int main(){

    //the year to be taken as input
    
    int year;
    
    //prompt to enter the year
    
    printf("\nPlease enter the required year: ");
    
    //take the current year as input
    
    scanf("%d", &year);
    
    //setting offset for January of the year; every 400 years the calendar repeats; every 100 years an offset of 5 days is added; the rest is calculated manually
    
    int start = ((((year-1)%400)/100)*5 + ((year-1)%100)*365 + ((year-1)%100)/4)%7;

    //The below comment was a test to check the offset for each year. Fuck the julian calendar.

    // //printf("%d",start%7);
    
    //blank space for neatness
    
    endl; endl;

    //initialize an array to hold days of the month
    
    int month[12];

    //Array to hold the days
    
    char* day[7] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    char* month_name[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

    //Initialising the no. of days in a month; if it is a year divisible by 400 or it is divisible by 4 but not by 100, then feb has 29 days
    
    for (int i = 1; i < 13; i++){
    
        switch(i){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: month[i-1] = 31; break;
            case 2: month[i-1] = (year%4 == 0 && year%100 != 0)||(year%400 == 0)?29:28; break;
            case 4:
            case 6:
            case 9:
            case 11: month[i-1] = 30; break;
        }
        
    }
    //print the month name

    printf("%*s", 16, month_name[0]);

    endl; endl;
    
    //print the first line of days

    for (int l = 0; l < 7; l++){
       printf("%*s", tabsize, day[l]);
    }

    endl;

    //print a vertical continuous vertical line below it. Note that the continuity is created 
    //by the terminal and font glyphs. Not all terminals support this.
    
    for (int i = 0; i < 7; i++){
            line;
    }
    
    endl;

    //At the very beginning this was an array, later I realised that this wasn't required 
    //and that the offset can be calculated within the loop printing the numbers
    
    // //int rem = start;

    //Print offset for jan
    
    for (int k = 0; k < start%7; k++){
        blank;        
    }

    // start the loop for all the months
    
    for (int i = 0; i < 12; i++){

        //start loop for days in each month
        
        for (int j = 1; j <= month[i]; j++){
            printf("%*d", tabsize, j);

            
            
            if((j+start)%7 == 0){
                
                endl;
            }
        }

        //set the offset for the next month right now
        
        start =  (start + month[i])%7;

        //neatness
        
        endl; endl;

        //only do all this if the month is not dec; otherwise there would be stray spaces and an extra header of days at the very last.
        
        if (i < 11){
            printf("%*s", 16, month_name[i+1]);

            endl; endl;
            
            for (int k = 0; k < 7; k++){
                printf("%*s", tabsize, day[k]);
            }

            endl;

        for (int l = 0; l < 7; l++){
            line;
        }
        
            endl;
            
        }

        for (int m = 0; m < start; m++){
            blank;
        }            

    }
    
    endl;

}

