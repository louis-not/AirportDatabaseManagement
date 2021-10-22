/**
 *      Proyek 1 Algoritma dan Pemograman
 *      1. Louis M. D. Wijaya / 1906379296
 *      2. Wilson A           / 1906379541
 * 
 *      Airport Database Management :
 *		(string database)
 *		|From		|To			|Date		|Boarding Time | Arrival Time |Flight Number |Airline		|Available Seat |Harga
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
# include <ctype.h>
# define MAXROW 20 
# define MAXSTR 15 

//database      
void displayDatabase(char ***database, int *numData) ;                          // display all data in database
int readDatabase(char ***database, int *numData) ;                              // read database from txt
void writeDatabase(char *** database, int *numData) ;                           // write change to database
int readNumData(int *numData);                                                  // 
void writeNumData(int *numData);                                                //

//function for quick sort algorithm
int partition	(float *temp, int *index, int bawah, int atas, int mode); //make partition for quick sort
void quickSort	(float *temp, int *index, int bawah, int atas, int mode); //quick sort algorithm
void swapNumber	(float *dataNilai, int*dataIndex, int a , int b,int mode);

//error checking
int errorCheckingDate(char *check) ;                                            // error checking input tanggal
int errorCheckingTime(char *check) ;                                            // error checking input time

//converter
void formatDate(char ***database, int *temp, int size) ;                     // convert date (string) to integer for sorting purpose
void formatTime(char ***database, int *temp, int size, int mode) ;           // convert boarding time and arrival time (string) to integer for sorting purpose

void inputOption(char *** database, int *numData) ;                             //    
int inputDatabase(char *** database, int *numData, char *airline) ;             // input data of airlines
void deleteOption(char ***database, int *numData);                              //
int deleteDatabase(char *** datbase, int *numData, char *airline);              // delete data of airlines


void sortingIndex(int *index, int size) ;										//






int main (){
    int menu, flagMenu = 0, i ,j , trial = 3, flagAdmin = 0 , *numData, *index, *temp;
    char *password = "admin123", *passwordInput, ***database;
    
    //temporary variable initialization
    temp = (int *)malloc(MAXROW*sizeof(int));
    
    //index initialization
    index = (int *)malloc(MAXROW*sizeof(int));
    
    // numData initialization 
    numData= (int *)malloc(sizeof(int)) ;

    // password initialization
    passwordInput= (char *)malloc( 15 *sizeof(char)) ;

    // database initialization 
    database = (char *** ) malloc( MAXROW * sizeof(char ** ) ) ;            // allocate MAXROW of rows    
    
    for (i=0; i< 8;i++){
        database[i] = (char **) malloc( 9 * sizeof(char *)) ;               // allocate 8 columns
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

            system("cls") ;
            char *fromPlace, *toPlace;
            fromPlace= (char *)malloc( 15 *sizeof(char)) ;
            toPlace= (char *)malloc( 15 *sizeof(char)) ;
            int userOption, exitFlag = 0, userFlag = 0 ;
            while (!userFlag){
                printf("1. Book a Flight\n0. Exit\n\nOption: ");
                scanf("%d", &userOption) ;
                if (userOption == 0){
                    userFlag = 1 ;
                    flagMenu = 1 ;
                } else if (userOption == 1 ){

            system("cls") ;
            char *fromPlace, *toPlace;
            fromPlace= (char *)malloc( 15 *sizeof(char)) ;
            toPlace= (char *)malloc( 15 *sizeof(char)) ;
            int userOption, exitFlag = 0, userFlag = 0 ;
            while (!userFlag){
                printf("1. Book a Flight\n0. Exit\n\nOption: ");
                scanf("%d", &userOption) ;
                if (userOption == 0){
                    userFlag = 1 ;
                    flagMenu = 1 ;
                } else if (userOption == 1 ){
                    printf("          - Flight Search Helper - \n\n") ;

                    printf("Where are you from \t\t: ") ;
                    fflush(stdin) ;
                    scanf("%[^\n]s" , fromPlace) ;
                    printf("Where do you want to go \t: ") ;
                    fflush(stdin) ;
                    scanf("%[^\n]s" , toPlace) ;
                    // search by from and to
                    
                    while (!exitFlag){
                    	system("cls") ;
                        printf("From: %s\t\tTo: %s\n\n", fromPlace, toPlace) ;
                        // display available flight here

                        printf("Search by:\n1. Date\n2. Airlines\n3. Boarding Time\n4. Price\n0. Exit\n\nOption: ") ;
                        fflush(stdin) ;
                        scanf("%d",&userOption) ;
                        if (userOption == 0){
                            exitFlag = 1 ;
                        } else if (userOption == 1) {
                            // search by Date
                        } else if (userOption == 2) {
                            // search by Airlines
                        } else if (userOption == 3) {
                            // search by Boarding time
                        } else if (userOption == 4) {
                            // search by Price
                        } else {
                            printf("Wrong input\n") ;
                            continue ;
                        }
                    }
                } else {
                    printf("Wrong input\n") ;
                    continue ;
                }
            }
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

//void displayDatabase(char ***database, int *numData){
//    int i = 0, j=0;
//    char header[8][15] = {"From","To","Date","Boarding Time","Arrival Time","Flight Number", "Airline", "Available Seat"} ;
//    printf("\t                                                     -Airport Database-                                                        \n\n") ;
//    printf("\t=================================================================================================================================\n") ;
//    printf("\t|%15s|%15s|%15s|%15s|%15s|%15s|%15s|%15s|\n", header[0],header[1],header[2],header[3],header[4],header[5],header[6],header[7]) ;
//    printf("\t=================================================================================================================================\n") ;
//	printf("\t|                                                                                                                               |\n") ;
//    for(i = 0; i < numData[0] ; i++){
//        printf("\t|%15s\r|%15s\r|%15s\r|%15s\r|%15s\r|%15s\r|%15s\r|%15s\r|\n",*(*(database+i)+0),*(*(database+i)+1),*(*(database+i)+2),*(*(database+i)+3),*(*(database+i)+4),*(*(database+i)+5),*(*(database+i)+6),*(*(database+i)+7)) ;
//    }
//    printf("\n") ;
//}

void displayDatabase(char ***database, int *numData){
    int i = 0, j=0;
    char header[9][15] = {"From","To","Date","Boarding Time","Arrival Time","Flight Number", "Airline", "Available Seat","Price"} ;
    printf("\t                                                     -Airport Database-                                                        \n\n") ;
    printf("\t=================================================================================================================================\n") ;
	printf("\t|%s\r\t\t\t|%s\r\t\t\t\t\t\t|%s\r\t\t\t\t\t|%s\r\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\n", header[0],header[1],header[2],header[3],header[4],header[5],header[6],header[7],header[8]) ;    
	printf("\t|                                                                                                                               |\n") ;
	printf("\t==========================================================================================================================\n");
    for(i = 0; i < numData[0] ; i++){
        printf("\t|%s\r\t\t\t|%s\r\t\t\t\t\t|%s\r\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|%s\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\n",*(*(database+i)+0),*(*(database+i)+1),*(*(database+i)+2),*(*(database+i)+3),*(*(database+i)+4),*(*(database+i)+5),*(*(database+i)+6),*(*(database+i)+7),*(*(database+i)+8)) ;
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
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }
    
	for(i = 0; i < numData[0];i++)
    {
    	for(j = 0; j < 9;j++)
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
    	for(j = 0; j < 9;j++)
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

}

int inputDatabase(char *** database, int *numData, char *airline) {
    //From, To	,Date,Boarding Time,Arrival Time,Flight Number,Available Seat,
    int datePass = 0, boardingPass = 0, arrivalPass = 0 ;
    strcpy(*(*(database+numData[0])+6),airline) ;
    printf("From            : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+0)) ;
    printf("To              : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+1)) ;
    while(!datePass){
	    printf("Date (format DD/MM/YYYY)       : ");
        fflush(stdin) ;
        scanf("%[^\n]s",*(*(database+numData[0])+2)) ;
        datePass = errorCheckingDate(*(*(database+numData[0])+2))  ;  
    }
    while(!boardingPass){
	    printf("Boarding Time (format XX:XX)  : ");
	    fflush(stdin) ;
	    scanf("%[^\n]s",*(*(database+numData[0])+3)) ;    	
	    boardingPass = errorCheckingTime(*(*(database+numData[0])+3)) ;
	}
	while(!arrivalPass){
	    printf("Arrival Time (format XX:XX)   : ");
	    fflush(stdin) ;
	    scanf("%[^\n]s",*(*(database+numData[0])+4)) ;	
		arrivalPass = errorCheckingTime(*(*(database+numData[0])+4)) ;
	}
    printf("Flight Number   : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+5)) ;
    printf("Available Seat  : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+7)) ;
    printf("Price/seat      : ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+8)) ;
}

int errorCheckingDate(char check[]){
//	printf("%s", *check) ;
    int i=0, digitFlag=0;
    for(i =0; i<10 ; i++){
		if ( (i==2)||(i==5) )
            continue ;
        else {
            // check if a char is a digit or not
            if(!isdigit(check[i]))
                return 0;
        }
    }
    return !digitFlag ;
}

int errorCheckingTime(char check[]){
	int i=0, digitFlag = 0 ;
	for(i=0;i<5;i++){
		if (i==2)
			continue ;
		else {
			if(!isdigit(check[i]))
				return 0;
		}
	}
	return !digitFlag ;
}

void sortingIndex(int *index, int size){
   int i;
	for(i = 0; i < size; i++)
	{
		index[i] = i;
	}
}

void formatDate(char ***database, int *dateInt, int size){
    //ex: 15-08-2021 >>> 8*30 + 15 = 255
	int i, j,result,flag,index;
	char temp[5];
	for(i =  0; i < size;i++){
		index = 0;
		flag = 0;
		result = 0;
		for(j = 0; j < 11;j++)
		{
			if((flag == 1 ) && (index == 0))
			{
				result += atoi(temp);
				memset(temp,0,5);
			}
			else if((flag == 2) && (index == 0))
			{
				result += atoi(temp)*30;
				memset(temp,0,5);
			}
			else if((flag == 3) && (index == 0))
			{
				result += (atoi(temp) - 2021)*365;
				memset(temp,0,5);
			}
			if((database[i][2][j] > 57) ||  (database[i][2][j] < 48))
			{
				printf("\n%s\n",temp);
				index = 0;
				flag++;
				continue;
			}
			else
			{
				temp[index] = database[i][2][j];
				index++;
			}
		}
		dateInt[i] = result;		
	}
}

void formatTime(char ***database, int *timeInt, int size, int mode){
    //21:55 >>> (hour)*60 + minute
	int i, j,result,flag,index;
	char temp[5];
	for(i =  0; i < size; i++){
		index = 0;
		flag = 0;
		result = 0;
		for(j = 0; j < 7;j++)
		{
			if((flag == 1 ) && (index == 0))
			{
				result += atoi(temp)*60;
				memset(temp,0,5);
			}
			else if((flag == 2) && (index == 0))
			{
				result += atoi(temp);
				memset(temp,0,5);
			}
            if(mode == 1)                                                   //mode 1 for convert boarding time to int
            {
                if((database[i][3][j] > 57) ||  (database[i][3][j]< 48))
                {
                    // printf("\n%s\n",temp);
                    index = 0;
                    flag++;
                    continue;
                }
                else
                {
                    temp[index] = database[i][3][j] ;
                    index++;
                }
            } else if (mode == 2){                                           //mode 2 for convert arrival time to int
                if((database[i][4][j] > 57) ||  (database[i][4][j] < 48))
                {
                    // printf("\n%s\n",temp);
                    index = 0;
                    flag++;
                    continue;
                }
                else
                {
                    temp[index] = database[i][4][j] ;
                    index++;
                }
            }

		}
		timeInt[i] = result;		
	}
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
