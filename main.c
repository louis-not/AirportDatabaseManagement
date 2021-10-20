/**
 *      Proyek 1 Algoritma dan Pemograman
 *      1. Louis M. D. Wijaya / 1906379296
 *      2. Wilson A           / 190637
 * 
 *      Airport Database Management :
 *		(string database)
 *		|From		|To			|Date		|Boarding Time | Arrival Time |Flight Number |Airline		|Available Seat |
 *		 
 *		Virtual Ticket	:
 *		|===================================================================================|
 *		|									%Airline										|
 *		|																					|
 *		|	Name			:							Flight Number	:					|
 *		|	Sex				:							Date			:					|
 *		|	From  			:							To				:					|
 *		|	Boarding Time	:							Arrival Time	:			 		|
 *		| 																					|
 *		|	*Tunjukan e-ticket untuk mendapatkan Boarding pass								|
 * 		|===================================================================================|
 *	
 *		Query (++):
 * 		Nama,Sex,FlightNumber,Date,From,To,BoardingTime,ArrivalTime
 **/  

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAXROW 10 
# define MAXSTR 15 
        
void displayDatabase(char ***database, int *numData) ;                          // display all data in database
int readDatabase(char ***database, int *numData) ;                              // read database from txt
void writeDatabase(char *** database, int *numData) ;                           // write change to database
void inputOption(char *** database, int *numData) ; 
int inputDatabase(char *** database, int *numData, char *airline) ;              //input data of airlines
void deleteOption(char ***database, int *numData);                          
int deleteDatabase(char *** datbase, int *numData, char *airline);              //delete data of airlines
int readNumData(int *numData);
void writeNumData(int *numData);

int main (){
    int menu, flagMenu = 0, i ,j , trial = 3, flagAdmin = 0 , *numData;
    char *password = "admin123", *passwordInput, ***database;
    
    // numData initialization
    numData= (int *)malloc(sizeof(int)) ;

    // password initialization
    passwordInput= (char *)malloc( 15 *sizeof(char)) ;

    // database initialization 
    database = (char *** ) malloc( MAXROW * sizeof(char ** ) ) ;            // allocate MAXROW of rows    
    
    for (i=0; i< 8;i++){
        database[i] = (char **) malloc( 8 * sizeof(char *)) ;               // allocate 8 columns
    }
    for (i=0; i< 8;i++){
        for(j=0; j< MAXSTR ; j++){
            database[i][j] = (char *) malloc( MAXSTR * sizeof(char )) ;     // allocate MAXSTR of char for every row x cols
        }
    }

	numData[0] = 0;
    //read data from database.txt
	readNumData(numData);
    readDatabase(database,numData);
       
    do {
        printf("======================= Airport Database Management ======================\n\n");
        printf("1. Admin Menu\n2. User Menu\n\n0. Exit\n\nOption :") ;
        scanf("%d", &menu) ;
        if(menu==1){ 
           // Admin menu (option 1)
           system("cls") ;
           i = 0 ;
           while ((i<trial) && !flagAdmin){
                printf("Input Password: ") ;
                fflush(stdin) ;                                             // clear stdin for using stdin
                scanf("%[^\n]s", passwordInput) ;                           // get password input
                if (!strcmp(passwordInput,password)){
                    // insert admin function
                    do {
                        printf("1. Display Database\n2. Input Data\n0. Back to Menu\n\nOption :") ;
                        scanf("%d", &menu) ;
                        if (menu==1){                                       // display data
                            displayDatabase(database,numData) ;
                        }else if (menu==2){                                 // input to database
                            // input data function
                            inputOption(database,numData) ;
                        }else if (menu==0){                                 // return to menu
                            flagAdmin = 1 ;                                 // break out from admin menu flag
                            break ;
                        // }else if (menu==3){                              // query view
                            
                        // }
                        }else {
                            printf("Wrong Input :( \n") ;
                        }
                    } while (!flagAdmin) ;
                    i-- ;
                } else { // wrong password condition
                    printf("Wrong Password (trial left: %d)\n\n", trial-i-1) ;
                }
                i++ ;
           }
           if (trial == i) 
                flagMenu = 1;
        } else if (menu==2){
            // User menu (option 2)
            
             
            
        } else if (menu==0){
            flagMenu=1 ;
        } else {
            printf("Wrong Input :( \n") ;
            system("cls") ;
        }

    } while (!flagMenu) ;
    printf("Good Bye! :D\n") ;
    writeDatabase(database,numData);
    writeNumData(numData) ;
    free(numData) ;
    free(database) ;
    free(passwordInput) ;
    return 0 ;
}

void displayDatabase(char ***database, int *numData){
    int i = 0, j=0;
    printf("======================= Airport Database ======================\n\n") ;
    printf("|From	|To		|Date	|Boarding Time | Arrival Time |Flight Number |Airline	|Available Seat |\n") ;
    for(i = 0; i < numData[0] ; i++){
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",*(*(database+i)+0),*(*(database+i)+1),*(*(database+i)+2),*(*(database+i)+3),*(*(database+i)+4),*(*(database+i)+5),*(*(database+i)+6),*(*(database+i)+7)) ;
    }
    printf("\n") ;
}

int readDatabase(char ***database, int *numData){
    FILE *fp = fopen("database.txt","r");
    int i,j;
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("database.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting xixixi ngAkak AbieZZZ...\n\n\n");
        return 0;
    }
    
	for(i = 0; i < numData[0];i++)
    {
    	for(j = 0; j < 8;j++)
    	{
    		fread(database[i][j], sizeof(char),MAXSTR, fp);
		}
	} 
    fclose(fp); 
    return 0;
}

void writeDatabase(char ***database, int *numData){
    FILE *fp = fopen("database.txt","w");
    int i,j;
    if(fp == NULL) 
    {
        printf("Error");
        exit(1);
    }
    for(i = 0; i < numData[0];i++)
    {
    	for(j = 0; j < 8;j++)
    	{
    		fwrite(database[i][j],sizeof(char),MAXSTR,fp);
		}
	}
    fclose(fp);
}

int readNumData(int *numData){
	FILE *fp = fopen("numData.txt","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("numData.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    fread(numData, sizeof(int),1, fp);
    fclose(fp);
    return 0;
}
void writeNumData(int *numData){
	FILE *fp = fopen("numData.txt","w+");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(numData, sizeof(int),1, fp);
    fclose(fp);	
//    printf("\nDi bagian write : %d\n",numData[0]);
}

void inputOption(char ***database, int *numData){
    // display airlines list
    int i, airline, flagInput = 0, option ; 
    char airlines[5][20] ={"Bangau Indonesia","Bitak air","Countrylink","Air Africa","SariJaya Air"} ;
    printf("Choose the corresponding airline's database : \n") ;
    for (i=0;i<5;i++){
        printf("%d. %s\n", i+1, airlines[i]) ;
    }
    printf("Option: ") ;
    scanf("%d", &airline) ;
    //input
    while(!flagInput){
        flagInput = inputDatabase(database,numData,airlines[airline]) ;
        numData[0]++ ;
        printf("1. Continue, 0. Back\nOption : ") ;
        fflush(stdin) ;
        scanf("%d", &flagInput) ;
        flagInput = !flagInput ;
    }
//    writeDatabase(database, numData[0]) ;
}

int inputDatabase(char *** database, int *numData, char *airline) {
    //From, To	,Date,Boarding Time,Arrival Time,Flight Number,Available Seat,
    strcpy(*(*(database+numData[0])+6),airline) ;
    printf("From            : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+0)) ;
    printf("To              : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+1)) ;
    printf("Date            : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+2)) ;
    printf("Boarding Time   : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+3)) ;
    printf("Arrival Time    : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+4)) ;
    printf("Flight Number   : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+5)) ;
    printf("Available Seat  : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+7)) ;
}

// void deleteOption(char ***database, int *numData){
//     int i,airline,flagInput = 0;

//     char airlines[5][20] ={"Bangau Indonesia","Bitak air","Countrylink","Air Africa","SariJaya Air"} ;
//     printf("Choose the corresponding airline's database : \n") ;
//     for (i=0;i<numAirlines;i++){
//         printf("%d. %s\n", i+1, airlines[i]) ;
//     }
//     printf("Option: ") ;
//     scanf("%d", &airline);
    
//     while(!flagInput)){
//         flagInput = deleteDatabase(database,numData,airlines[airline]) ;
       
//     }


// }

// int deleteDatabase(char *** datbase, int *numData, char *airline){




// }
