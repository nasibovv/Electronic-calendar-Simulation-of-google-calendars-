 // #calendar.h
 // defined
 
char filename[40]= "Notes.txt";
int isLeapYear( int year );        /* Returns true if leap year */
int leapYears( int year );         /* The number of leap year */
int todayOf( int y, int m, int d); /* The number of days since the beginning of the year */
int gotit;
char *ptr;
char buff[BUFSIZ];
long days( int y, int m, int d);   
void calendar(int y, int m);       /* display calendar at m y */
FILE *fp, *fp1, *fp2;
int i;

void flush()   //  flush generates a value which helps to break from used function
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
 
typedef struct {
  int day;
  int month;
  int year;
  char note[255];
} Note;
  
 int isLeapYear( int y ){                                         //Next 4 functions performs spesific calculations for calendar
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));  
}
 
int leapYears( int y ){
    return y/4 - y/100 + y/400;
}
 
int todayOf( int y, int m, int d) {
    static int DayOfMonth[] = 
        { -1,0,31,59,90,120,151,181,212,243,273,304,334};
    return DayOfMonth[m] + d + ((m>2 && isLeapYear(y))? 1 : 0);
}
 
long days( int y, int m, int d){
    int lastYear;
    lastYear = y - 1;
    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}
 
void calendar(int y, int m){
    Note* notes, note;
    int len, j, hasNote = 0;
    char choice;
    const char *NameOfMonth[] = { NULL/*dummp*/,
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    char Week[] = "Su   Mo   Tu   We   Th   Fr   Sa";
    int DayOfMonth[] =
        { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    int weekOfTopDay;
    int i,day;
    
    weekOfTopDay = days(y, m, 1) % 7;
 
    len = 0;

    j = 0;
    notes = (Note*) malloc (sizeof(Note) * len);
 
    if(isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);


    for(i=0;i<weekOfTopDay;i++)
        printf("     ");
    for(i=weekOfTopDay,day=1;day <= DayOfMonth[m];i++,day++){
        hasNote = 0;
        for (j = 0; j < len; j++) {
          if (notes[j].day == day) {
            printf("|%3d| ",day);
            hasNote = 1;
            break;
          }
        }
        
        if (hasNote == 0) {
          printf("%2d   ",day);
        }
        if(i % 7 == 6)
            printf("\n");
    }   
    printf("\n");
    printf("\n");
    printf("Enter any key to exit.\n");
    scanf("\n%c", &choice);
    system("CLS");
      return;
    
}
