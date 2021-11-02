/**
 *      Proyek 1 Algoritma dan Pemograman
 *      1. Louis M. D. Wijaya / 1906379296
 *      2. Wilson A           / 1906379541
 * 
 *      Airport Database Management :
 *		(string database)
 *		|From		|To			|Date		|Boarding Time | Arrival Time | Duration | Flight Number |Airline		|Available Seat |Harga
 *	0	
 *  1
 *  2
 *  3   
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
# define MAXROW 40
# define MAXCOL 10 
# define MAXSTR 30 

//database      
void displayDatabase(char ***database, int size, int *index) ;                  											// display all data on database base on index in array *index
int readDatabase(char ***database, int *numData) ;                              											// read database from txt
void writeDatabase(char *** database, int *numData) ;                           											// write change to database
int readNumData(int *numData);                                                  											// read number of data inside database form numData.txt
void writeNumData(int *numData);                                                											// write change of number of data to numData.txt
void inputOption(char *** database, int *numData) ;                            												// user interface for input new data to database
int inputDatabase(char *** database, int *numData, char *airline) ;             											// input database information one-by-one (get called by inputOption)
void deleteDatabase(char *** datbase, int *numData, int *index);              												// delete some flight data inside database
void editDatabase(char ***database, int *numData, int *index, char airlines[][20]);																// edit some parameter of a datum inside the database


//error checking
int errorCheckingDate(char *check) ;                                                    									// error checking input tanggal
int errorCheckingTime(char *check) ;                                                                                        // error checking input time

//function for quick sort algorithm
int partition	(int *temp, int *index, int bawah, int atas, int mode);         											// make partition for quick sort
void quickSort	(int *temp, int *index, int bawah, int atas, int mode);         											// quick sort algorithm
void swapNumber	(int *dataNilai, int*dataIndex, int a , int b,int mode);													// swap number
void sortingIndex(int *index, int size) ;																					// fill array of index with sorted index

// Searching Algorithm 
void string_array_lwr(char **target, int row) ;                                     										// set an array of string to lowercase
void get_string_database(char *** db, char ** newstring, int numData ,int index) ;  										// get a whole column from a database
void printstrarray(char** arr, int row) ;                                           										// print a string array of 'row' row, for debuging use only
int str_search(char*** db, int numData, int col ,int *index, int *indexSearching, char *strSearch) ; 						// search strSearch string on db database, number of match and index.
int numSearch(char ***database, int sizeArrow, int *indexArrow, int *indexTarget, int *temp, int min, int max, int col) ; 	// 
int indexSwap (int *change, int *withthis, int *safefirst, int thisize , int changesize );                                  // memindahkan index change ke safefirst sebelum memindahkan withthis ke change.
int indexCopy (int *target,int *arrow, int sizeArrow);                                                                      // copy index arrow ke target

//converter
void formatDate(char **dataDate, int *dateInt, int size) ;                              									// convert date (string) to integer for sorting purpose
void formatTime(char **dataTime, int *temp, int size) ;                                 									// convert boarding time, duration, and arrival time in string form to integer form for sorting purpose
void formatPrice(char **dataPrice, int *temp, int size);																	// convert price (string) to integer for sorting purpose
void getColumnDatabase(char ***database, int *index, int size, char **tempTime, int col) ;    								// function for get array of some data in string form from specific column in database         

// User 
void printBoardingPass(char ***database, int index , char *name, char *gender) ;											// display e-ticket


int main (){
    int menu, flagMenu = 0, i ,j , trial = 3, flagAdmin = 0 , *numData, *index, *temp, flagAirlines = 0, flagTime = 0, flagPrice = 0, errorDateFlag = 0, userOption, exitFlag = 0, userFlag = 0, userDataFlag = 0 , errorInputFlag = 0;
    int pickTicket, *indexTarget, *indexArrow, *indexBack ,sizeArrow,sizeTarget, flagBack ,minVal, maxVal, userSeat, temporary, totalPrice, flagFilterPrice = 0, flagFilterTime = 0, flagFilterAirline = 0;
    char *password = "admin123", *passwordInput, ***database, *searching, *fromPlace, *toPlace, *dateInput, **tempStr, **userName, **userGender;
    char airlines[5][20] ={"Bangau Indo","Bitak air","Countrylink","Air Africa","SariJaya Air"} ; //list of airlines that used in this program
	fromPlace= (char *)malloc( 15 *sizeof(char)) ;
	toPlace= (char *)malloc( 15 *sizeof(char)) ;
    dateInput = (char *)malloc( 10 * sizeof(char)) ;

    //temporary variable initialization
    temp = (int *)malloc(MAXROW*sizeof(int)); 							//temporary variabel for storing some integer value in 1D array
    tempStr = (char **)malloc(MAXROW*sizeof(char*));					//temporary variabel for storing some string value in 2D array
    for(i = 0; i < MAXROW; i++)
    {
        tempStr[i] = (char*)malloc(MAXSTR*sizeof(char));
    }
    
    //index initialization
    index = (int *)malloc(MAXROW*sizeof(int));
    indexTarget = (int *)malloc(MAXROW*sizeof(int)) ;
    indexArrow = (int *)malloc(MAXROW*sizeof(int)) ;
    indexBack = (int *)malloc(MAXROW*sizeof(int)) ;
    
    // numData initialization 
    numData= (int *)malloc(sizeof(int)) ;							//

    // password initialization
    passwordInput= (char *)malloc( 15 *sizeof(char)) ;

    // database initialization 
    database = (char *** ) malloc( MAXROW * sizeof(char ** ) ) ;                // allocate MAXROW of rows    
    for (i=0; i< MAXROW ;i++){
        database[i] = (char **) malloc( MAXCOL * sizeof(char *)) ;              // allocate 8 columns
    }
    for (i=0; i< MAXROW;i++){
        for(j=0; j< MAXCOL ; j++){
            database[i][j] = (char *) malloc( MAXSTR * sizeof(char )) ;         // allocate MAXSTR of char for every row x cols
        }
    }
    // searching variable initialization
	searching = (char*)malloc(MAXSTR*sizeof(char)) ;

    // user information initialization
    userName = (char**)malloc(20 *sizeof(char*)) ;
    userGender = (char**)malloc(20 *sizeof(char*)) ;
    for (i=0; i< MAXROW ;i++){
        userName[i] = (char *) malloc( 35 * sizeof(char)) ;
        userGender[i] = (char *) malloc( 3 * sizeof(char)) ;               
    }
    

	numData[0] = 0; 					//
    //read data from database.txt
	readNumData(numData);				//read number of data from database and variable numData[0] will be updated
    readDatabase(database,numData);
     
    do {
        system("color 0f") ;
        printf("======================= Airport Database Management ======================\n\n");
        printf("========================\n");
        printf("Main Menu\n");
        printf("========================\n\n");
        printf("1. Admin Menu\n2. User Menu\n\n0. Exit\n\nOption :") ;
        scanf("%d", &menu) ;
        if(menu==1){ 
            system("color 03") ;
           // Admin menu (option 1)
           system("cls") ;
           i = 0 ;
           flagAdmin = 0 ;
           while ((i<trial) && !flagAdmin){
                printf("Input Password: ") ;
                fflush(stdin) ;                                             // clear stdin for using stdin
                scanf("%[^\n]s", passwordInput) ;                           // get password input
                if (!strcmp(passwordInput,password)){
                    // insert admin function
                    system("cls");
                    do {
                    	printf("========================\n");
                    	printf("Admin's Menu\n");
                    	printf("========================\n\n");
                        printf("1. Display Database\n2. Input Data\n3. Edit Data\n4. Delete Data\n0. Back to Main Menu \n\nOption : ") ;
                        scanf("%d", &menu) ;
                        if (menu==1){                                       // display data
                        	sortingIndex(index, numData[0]);
                            displayDatabase(database,numData[0],index) ;
                        }else if (menu==2){                                 // input some data to database
                            // input data function
                            inputOption(database,numData) ;
                            system("cls");
                        }else if (menu == 3){
							editDatabase(database,numData,index,airlines);
						}else if (menu == 4){
							deleteDatabase(database, numData, index);
						}else if (menu==0){                                 // return to menu
                            flagAdmin = 1 ;                                 // break out from admin menu flag
                            system("cls");
                            break ;
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
            system("color f0") ;
            system("cls") ;
            printf("========================\n");
        	printf("User's Menu\n");
        	printf("========================\n\n");
            char *fromPlace, *toPlace;
            fromPlace= (char *)malloc( 15 *sizeof(char)) ;
            toPlace= (char *)malloc( 15 *sizeof(char)) ;
            int userOption, exitFlag = 0, userFlag = 0 ;
            while (!userFlag){	
                printf("Menu: \n1. Book a Flight\n0. Back to Main Menu\n\nOption: ") ;
                scanf("%d", &userOption) ;
                if (userOption == 0){
                    userFlag = 1 ;
                    system("cls");
                    // flagMenu = 1 ;
                } else if (userOption == 1 ){
                    errorDateFlag = 0 ;
                    flagBack = 0 ;
                    printf("          - Flight Search Helper -    \n\n") ;

                    printf("Where are you from \t\t: ") ;
                    fflush(stdin) ;
                    scanf("%[^\n]s" , fromPlace) ;
                    printf("Where do you want to go \t: ") ;
                    fflush(stdin) ;
                    scanf("%[^\n]s" , toPlace) ;
                    errorDateFlag = 0 ;
                    while(!errorDateFlag){
                        printf("Date\t\t\t\t: ") ;
                        fflush(stdin) ;
                        scanf("%s", dateInput) ;
                        errorDateFlag = errorCheckingDate(dateInput) ;
                    }
                    // search by from and to and date
                    sortingIndex(index,numData[0]);
					sizeArrow = numData[0] ;
					sizeTarget = 0 ;
					
					// Filter by origin place
					printf("sizeArrow: %d\n", sizeArrow) ;
					indexSwap(indexArrow, index, indexBack, sizeArrow, sizeTarget) ;
					sizeTarget = sizeArrow ;
					sizeArrow = str_search(database,sizeArrow,0,indexArrow,indexTarget, fromPlace) ;
					
					
					// Filter by destination place
                    printf("sizeArrow: %d\n", sizeArrow) ;
                    indexSwap(indexArrow, indexTarget,indexBack, sizeArrow,sizeTarget) ;
                    sizeTarget = sizeArrow ;
					sizeArrow = str_search(database,sizeArrow,1,indexArrow,indexTarget, toPlace) ;
					
					
					// filter by flight date
                    printf("sizeArrow: %d\n", sizeArrow) ;
                    indexSwap(indexArrow, indexTarget,indexBack, sizeArrow,sizeTarget) ;
                    sizeTarget = sizeArrow;
					sizeArrow = str_search(database,sizeArrow,2,indexArrow,indexTarget, dateInput) ;
					
					
                    printf("sizeArrow: %d\n", sizeArrow) ;
					indexSwap(indexArrow, indexTarget,indexBack, sizeArrow,sizeTarget) ;
//					indexSwap (indexArrowBefore, indexArrow, sizeArrow, 1) ;
					
					exitFlag = 0 ;		
					if (sizeArrow != 0){
						while (!exitFlag){
							system("cls") ;
	                        printf("From: %s\t\tTo: %s\n\n", fromPlace, toPlace) ;
	                        printf("Date: %s\n", dateInput) ;
	                        // display available flight here
	//                        displayDatabase(database,sizeDate,indexDate) ;
	                        displayDatabase(database,sizeArrow,indexArrow) ;
	                        printf("User Menu:\n1. Pick Ticket\n2. Filter by Departure Time\n3. Filter by Price\n4. Filter by Airlines\n5. Step Back\n6. Sort by Lowest Price\n7. Sort by Earliest Departure\n8. Sort by Shortest Duration\n0. Back\n\nOption: ") ;
	                        fflush(stdin) ;
	                        scanf("%d",&userOption) ;
	                        if (userOption == 0){
	                            exitFlag = 1 ;
	                            userFlag = 0 ;
	                            system("cls");
	                        } else if (userOption == 1){
	                            exitFlag = 1 ;
	                            printf("Pick your ticket by index :") ;
	                            fflush(stdin) ;
	                            scanf("%d", &pickTicket) ;
	                            i = 0 ;
	                            printf("Print number of ticket : ");
	                            fflush(stdin) ;
	                            scanf("%d", &userSeat) ;
	
	                            // check number of seat available
	                            // *(*(database+indexArrow[pickTicket-1])+8)
	                            if (userSeat <= atoi(*(*(database+indexArrow[pickTicket-1])+8))){
	                                temporary = atoi(*(*(database+indexArrow[pickTicket-1])+8)) - userSeat ;
	                                temporary = sprintf(*(*(database+indexArrow[pickTicket-1])+8),"%d",temporary) ;
	                            } else {
	                                printf("Sorry, available seat isn't sufficient\n");
	                                exitFlag = 1;
	                            }
	
	                            while(!userDataFlag){
	                                system("cls") ;
	                                printf("\nName        : ") ;
	                                fflush(stdin) ;
	                                scanf("%[^\n]s", userName[i]) ;
	                                printf("Gender(L/P) : ") ;
	                                fflush(stdin) ;
	                                scanf("%[^\n]s", userGender[i]) ;
	                                system("cls") ;
	                                printf("\nYour Data-%d: \n", i) ;
	                                printf("Name        : %s\n", userName[i]) ;
	                                printf("Gender(L/P) : %s\n", userGender[i]) ;
	                                printf("\nCorrect? (1:yes/0:no): ") ;
	                                fflush(stdin) ;
	                                scanf("%d", &userOption) ;
	                                if (userOption==1)
	                                    i++ ;
	                                if ( i == userSeat )
	                                    userDataFlag = 1 ;
	                            }
	                            system("cls") ; 
	                            printf("Processing your ticket . . . \n\n") ;
	                            // display ticket 
	                            for (i = 0; i< userSeat; i++){
	                                printBoardingPass(database, indexArrow[pickTicket-1],userName[i],userGender[i]) ;
	                            }
	                            totalPrice = userSeat*atoi(*(*(database+indexArrow[pickTicket-1])+9)) ;
	                            printf("\nTotal Price: Rp. %d\n", totalPrice);
	                        } else if (userOption == 4) {  
	                            printf("What is your prefered airlines : \n") ;
	                            for (i=0;i<5;i++){
	                                printf("%d. %s\n", i+1, airlines[i]) ;
	                            }
	                            printf("\noption: ") ;
	                            fflush(stdin) ;
	                            scanf("%d", &userOption) ;
	                            strcpy(searching,airlines[userOption-1]) ;
	                            sizeTarget = sizeArrow ;
	                            sizeArrow = str_search(database,sizeArrow,7,indexArrow,indexTarget, searching) ;
	                            indexSwap(indexArrow, indexTarget, indexBack, sizeArrow, sizeTarget) ;
	                            flagAirlines = 1;
	                        } else if (userOption == 2) {
	                            // search by departure Time
		                        printf("1. Early Morning (00:00 - 06:00)\n2. Morning (06:00 - 12:00)\n3. Afternoon (12:00 - 18:00)\n4. Evening (18:00 - 24:00)\nOption : ");
		                        printf("What is your prefered departure time \t: ") ;
		                        scanf("%d",&userOption) ;
		                        if(userOption == 1){
		                            minVal = 0;
		                            maxVal = 360;
								} else if (userOption == 2){
									minVal = 360;
									maxVal = 720;
								} else if (userOption == 3){
									minVal = 720;
									maxVal = 1080;
								} else if (userOption == 4){
									minVal = 1080;
									maxVal = 1440;
								}
								sizeTarget = sizeArrow ; 
	                            getColumnDatabase(database, indexArrow, sizeArrow, tempStr, 3) ;								
	                            formatTime(tempStr, temp , sizeArrow) ;
	                            quickSort(temp, indexArrow, 0 , sizeArrow - 1, 1) ;
	                            sizeArrow = numSearch(database, sizeArrow, indexArrow, indexTarget, temp,minVal, maxVal, 3) ;
	                            indexSwap(indexArrow, indexTarget, indexBack, sizeArrow, sizeTarget) ;	                            
								flagTime = 1 ;
	
	                        } else if (userOption == 3) {
	                            // search by Price
	                            printf("Enter Minimum Price : ") ;
	                            scanf("%d",&minVal) ;
	                            printf("Enter Maximum Price : ") ;
	                            scanf("%d",&maxVal) ;
	                            sizeTarget = sizeArrow ;
	                            getColumnDatabase(database, indexArrow, sizeArrow, tempStr, 9) ;
	                            formatPrice(tempStr, temp, sizeArrow);
	                            quickSort(temp, indexArrow, 0 , sizeArrow - 1, 1) ;
	                            sizeArrow = numSearch(database, sizeArrow, indexArrow, indexTarget, temp,minVal, maxVal, 9) ;
	                            indexSwap(indexArrow, indexTarget, indexBack, sizeArrow,sizeTarget) ;
	                            flagPrice = 1 ;
	                            
	                        } else if (userOption == 5 ){
	                        	if (flagBack == 0 ){
	                        		// step back condition 
		                        	indexSwap(indexArrow , indexBack, indexTarget , sizeTarget, sizeArrow) ;
									sizeArrow = sizeTarget ;
									flagBack = 1 ;
								} else {
									// reset condition
									sortingIndex(index,numData[0]);
									sizeArrow = numData[0] ;
									sizeTarget = 0 ;
									indexSwap(indexArrow, index, indexBack, sizeArrow, sizeTarget) ;									
								}
							} else if (userOption == 6){
								// sort by lowest price
								getColumnDatabase(database, indexArrow, sizeArrow, tempStr, 9);
			                    formatPrice(tempStr, temp,sizeArrow);
			                    indexCopy (indexTarget,indexArrow, sizeArrow);
			                    quickSort	(temp, indexTarget, 0 , sizeArrow - 1, 1) ;
			                    sizeTarget = sizeArrow ;
			                    indexSwap(indexArrow, indexTarget, indexBack, sizeArrow,sizeTarget) ;
									     
							} else if (userOption == 7){
								//sort by earliest departure
								getColumnDatabase(database, indexArrow, sizeArrow, tempStr, 3);
			                    formatTime(tempStr, temp, sizeArrow);
			                    indexCopy (indexTarget,indexArrow, sizeArrow);
			                    quickSort	(temp, indexTarget, 0 , sizeArrow - 1, 1) ;
			                    sizeTarget = sizeArrow ;
			                    indexSwap(indexArrow, indexTarget, indexBack, sizeArrow,sizeTarget) ;
								     
							} else if (userOption == 8){
								//sort by short duration
								
								getColumnDatabase(database, indexArrow, sizeArrow, tempStr, 5);
			                    formatTime(tempStr, temp, sizeArrow);
			                    indexCopy (indexTarget,indexArrow, sizeArrow);
			                    quickSort	(temp, indexTarget, 0 , sizeArrow - 1, 1) ;
			                    sizeTarget = sizeArrow ;
			                    indexSwap(indexArrow, indexTarget, indexBack, sizeArrow,sizeTarget) ;
									     
							}else {
	                            printf("Wrong input\n") ;
	                            continue ;
	                        }
							if (userOption != 5)
								flagBack = 0 ;		
						}	
					} else if (sizeArrow == 0){
						system("cls") ;
	                    printf("From: %s\t\tTo: %s\n\n", fromPlace, toPlace) ;
	                    printf("Date: %s\n", dateInput) ;
	                    displayDatabase(database,sizeArrow,indexArrow) ;
						printf("\n\tFlight from %s to %s on %s is not available yet.\n\n",fromPlace,toPlace,dateInput) ;
						errorInputFlag = 0;
						while(!errorInputFlag){
							printf("1. Book Another Flight\n0. Back to Main Menu\nOption : ") ;
							scanf("%d",&userOption);
							if(userOption == 1){
								exitFlag = 1;
								errorInputFlag = 1;
								userFlag = 0;
								system("cls");
							} else if (userOption == 0){
								exitFlag = 1;
								userFlag = 1;
								flagMenu = 0;
								errorInputFlag = 1;
								system("cls");
							} else{
								printf("Wrong Input") ;
								errorInputFlag = 0;
							}	
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
    free(index);
    free(passwordInput) ;
    return 0 ;
}

void displayDatabase(char ***database, int size, int *index){
    int i = 0, j=1;
    char header[10][15] = {"From","To","Flight Date","De.Time","Ar.Time","Dur","Fl Num", "Airline", "Available Seat","Price"} ;
    printf("\n\n");
    printf("\t                                                     -Airport Database-                                                        \n\n") ;
    printf("\tNumber of Data : %d\n\n",size);
    printf("\t==============================================================================================================================") ;
    printf("\n\t No |%s",header[0]);
    printf("\r\t\t\t|%s",header[1]);
    printf("\r\t\t\t\t\t|%s",header[2]);
    printf("\r\t\t\t\t\t\t\t|%s",header[3]);
    printf("\r\t\t\t\t\t\t\t\t|%s",header[4]);
    printf("\r\t\t\t\t\t\t\t\t\t|%s",header[5]);
    printf("\r\t\t\t\t\t\t\t\t\t\t|%s",header[6]);
    printf("\r\t\t\t\t\t\t\t\t\t\t\t|%s",header[7]);
    printf("\r\t\t\t\t\t\t\t\t\t\t\t\t\t|%s",header[8]);
    printf("\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|%12s |",header[9]);
    printf("\n");
	printf("\t==============================================================================================================================\n");
    for(i = 0; i < size ; i++){
        printf("\t%3d ", j) ; 
        printf("|%s",*(*(database+index[i])+0));
        printf("\r\t\t\t|%s",*(*(database+index[i])+1));
        printf("\r\t\t\t\t\t|%s",*(*(database+index[i])+2));
        printf("\r\t\t\t\t\t\t\t|%s",*(*(database+index[i])+3));
        printf("\r\t\t\t\t\t\t\t\t|%s",*(*(database+index[i])+4));
        printf("\r\t\t\t\t\t\t\t\t\t|%s",*(*(database+index[i])+5));
        printf("\r\t\t\t\t\t\t\t\t\t\t|%s",*(*(database+index[i])+6));
        printf("\r\t\t\t\t\t\t\t\t\t\t\t|%s",*(*(database+index[i])+7));
        printf("\r\t\t\t\t\t\t\t\t\t\t\t\t\t|%s",*(*(database+index[i])+8));
        printf("\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|Rp.%10s|",*(*(database+index[i])+9));
        printf("\n");
        j++ ;
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
    	for(j = 0; j < MAXCOL ;j++)
    	{
    		fread(database[i][j], sizeof(char),MAXSTR, fp); //read data from database.txt for each row and colum and store it to array
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
    	for(j = 0; j < MAXCOL ;j++)
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
    char airlines[5][20] ={"Bangau Indo","Bitak air","Countrylink","Air Africa","SariJaya Air"} ;
    printf("Choose the corresponding airline's database : \n") ;
    for (i=0;i<5;i++){
        printf("%d. %s\n", i+1, airlines[i]) ;
    }
    printf("Option: ") ;
    scanf("%d", &airline) ;
    //input
    while(!flagInput){
        flagInput = inputDatabase(database,numData,airlines[airline - 1]) ;
        numData[0]++ ;
        printf("1. Continue Input Another Data, 0. Back\nOption : ") ;
        fflush(stdin) ;
        scanf("%d", &flagInput) ;
        flagInput = !flagInput ;
    }

}

int inputDatabase(char *** database, int *numData, char *airline) {
    int datePass = 0, boardingPass = 0, arrivalPass = 0, durationPass = 0 ;
    strcpy(*(*(database+numData[0])+7),airline) ;
    printf("From\t\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+0)) ;
    printf("To\t\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+1)) ;
    while(!datePass){
	    printf("Date ( format DD/MM/YYYY)\t\t: ");
        fflush(stdin) ;
        scanf("%[^\n]s",*(*(database+numData[0])+2)) ;
        datePass = errorCheckingDate(*(*(database+numData[0])+2))  ;  
    }
    while(!boardingPass){
	    printf("Departure Time (24 hr format XX:XX)\t: ");
	    fflush(stdin) ;
	    scanf("%[^\n]s",*(*(database+numData[0])+3)) ;    	
	    boardingPass = errorCheckingTime(*(*(database+numData[0])+3)) ;
	}
	while(!arrivalPass){
	    printf("Arrival Time (24 hr format XX:XX) \t: ");
	    fflush(stdin) ;
	    scanf("%[^\n]s",*(*(database+numData[0])+4)) ;	
		arrivalPass = errorCheckingTime(*(*(database+numData[0])+4)) ;
	}
	while(!durationPass){
		printf("Duration\t\t\t\t: ");
		fflush(stdin) ;
		scanf("%[^\n]s",*(*(database+numData[0])+5)) ;
		durationPass = errorCheckingTime(*(*(database+numData[0])+5)) ;
 	}
    printf("Flight Number\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+6)) ;
    printf("Available Seat\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+8)) ;
    printf("Price/seat\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%[^\n]s",*(*(database+numData[0])+9)) ;
    return 0;
}

int errorCheckingDate(char check[]){
//	printf("%s", *check) ;
    int i=0, digitFlag=0;
    for(i =0; i<MAXCOL ; i++){
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
	int i=0, digitFlag = 0; 
	char temp[1];
	for(i=0;i<5;i++){
		temp[0] = check[i];
		if (i==2)
			continue ;
		else {
			if(!isdigit(check[i])) // check if a char is a digit or not
				return 0;
		}
		if(i == 0){
			if((atoi(temp)< 0) || (atoi(temp)> 2)){
				return 0;
			} else if(atoi(temp) == 2){               //check if index 0 of time is 2, then index 1 must be smaller than 4
				temp[0] = check[1];
				if((atoi(temp) < 0) || (atoi(temp)> 3)){
					return 0;
				}
			}
		} 
		if(i == 3){									//index 3 of time must be smaller than 6
			if((atoi(temp) < 0) || (atoi(temp) > 5)){
				return 0;
			}
		}
	}
	return !digitFlag ;
}

void sortingIndex(int *index, int size){
   int i;
	for(i = 0; i < size; i++)
	{
		index[i] = i; //fill value index i with 0 - size
	}
}

void formatDate(char **dataDate, int *dateInt, int size){
    //ex: 15-08-2021 >>> 8*30 + 15 = 255
	int i, j,result,flag,index;
	char temp[5]; //temporary array for store day, month, year of  a data of time in integer form
	for(i =  0; i < size;i++){
		index = 0;
		flag = 0;
		result = 0;
		for(j = 0; j < 11;j++)
		{
			if((flag == 1 ) && (index == 0)) //get day
			{
				temp[2] = 0;
				temp[3] = 0;
				result += atoi(temp); 
				memset(temp,0,5); //reset each value in the temp array by filling it with 0
			}
			else if((flag == 2) && (index == 0)) //get month
			{
				result += atoi(temp)*30;
				memset(temp,0,5); //reset each value in the temp array by filling it with 0
			}
			else if((flag == 3) && (index == 0)) //get year
			{
				result += (atoi(temp) - 2021)*365;
				memset(temp,0,5);
			}
			if((dataDate[i][j] > 57) ||  (dataDate[i][j]  < 48)) //if value of string not 0 - 9
			{
				// printf("\n%s\n",temp); ////debugging
				index = 0;
				flag++;
				continue;
			}
			else
			{
				temp[index] = dataDate[i][j];
				index++;
			}
		}
		dateInt[i] = result; //store data of time that already converted in integer form in dateInt[i]
		// printf("%d\n",dateInt[i]);		
	}
}

void formatTime(char **dataTime, int *temp, int size){
    //21:55 >>> (hour)*60 + minute
	int i, j,result,flag,index;
	char tempTime[5];
	for(i =  0; i < size; i++){
		index = 0;
		flag = 0;
		result = 0;
		for(j = 0; j < 7;j++)
		{
			if((flag == 1 ) && (index == 0)) //get hour
			{
				result += atoi(tempTime)*60;
				memset(tempTime,0,5); //reset each value in the temp array by filling it with 0
			}
			else if((flag == 2) && (index == 0)) //get second
			{
				result += atoi(tempTime);
				memset(tempTime,0,5);
			}
            if((dataTime[i][j] > 57) ||  (dataTime[i][j]< 48)) //if value of string not 0 - 9
            {
                // printf("\n%s\n",temp);
                index = 0;
                flag++;
                continue;
            }
            else{
                tempTime[index] = dataTime[i][j] ;
                index++;
            }
        } 
        temp[i]= result; //store data of time that already converted in integer form in temp[i]
	}
}

void printBoardingPass(char ***database, int index , char *name, char *gender){
	printf("\n\n");
    system("color F9") ;
    // printf("index = %d\n", index) ;
    printf("\t|=======================================================================================|\n") ;
    printf("\t|\t\t\t\t%20s  \t\t\t\t\t|\n", *(*(database+index)+7)) ;
    printf("\t|\t\t\t\t\t\t\t\t\t\t\t|\n") ;
    printf("\t|	Name\t\t: %15s\tFlight Number\t:\t%10s\t|\n",name ,*(*(database+index)+6) ) ;
    printf("\t|	Sex\t\t: %2s\t\t\tDate\t\t:\t%10s\t|\n",gender,*(*(database+index)+2)) ;
    printf("\t|	From\t\t: \t%*s\tTo\t\t:\t%10s\t|\n",10,*(*(database+index)+0),*(*(database+index)+1)) ;
    printf("\t|	Departure Time\t: %5s\t\t\tArrival Time\t:\t%10s\t|\n",*(*(database+index)+3),*(*(database+index)+4)) ;
    printf("\t|\t\t\t\t\t\t\t\t\t\t\t|\n") ;
    printf("\t|	*Tunjukan e-ticket untuk mendapatkan Boarding pass\t\t\t\t|\n") ;
    printf("\t|=======================================================================================|\n") ;
    printf("\n\n");
}

int partition	(int *temp, int *index, int bawah, int atas, int mode){
	int i, j;
	j = bawah;
	if(mode == 0) //descending
	{
		for(i = bawah; i < atas; i++)
		{
			if(temp[i] > temp[atas]) //if value bigger than pivot
			{
				swapNumber(temp,index,i,j,0); //nilai
				swapNumber(temp,index,i,j,1); //index
				j++;
			}
		}
		swapNumber(temp,index,j,atas,0); //swap location of pivot from atas to j for value
		swapNumber(temp,index,j,atas,1); //swap location of pivot from atas to j for index
		return j;
	}
	else if(mode == 1) //ascending
	{
		for(i = bawah; i < atas; i++)
		{
			if(temp[i] < temp[atas])//if value smaller than pivot
			{
				swapNumber(temp,index,i,j,0);
				swapNumber(temp,index,i,j,1);
				j++;
			}
		}
		swapNumber(temp,index,j,atas,0); //swap location of pivot from atas to j
		swapNumber(temp,index,j,atas,1); //swap location of pivot from atas to j for index
		return j;
	}	
}   
   
void quickSort	(int *temp, int *index, int bawah, int atas, int mode){
	int pivot;
	if(bawah < atas)
	{
		pivot = partition(temp,index,bawah,atas,mode); //get index of pivot after partition
		quickSort(temp,index,bawah,pivot-1,mode); //partition 1
		quickSort(temp,index,pivot+1,atas,mode); // partition 2
	}	
	
}   
  
void swapNumber	(int*dataNilai, int*dataIndex, int a , int b,int mode){
	int temp; 
	float temp2;
	if(mode == 0) //data nilai
	{
		temp2 = dataNilai[b];
		dataNilai[b] = dataNilai[a];
		dataNilai[a] = temp2;
	}
	else if(mode == 1) //data index
	{
		temp = dataIndex[b];
		dataIndex[b] = dataIndex[a];
		dataIndex[a] = temp;
	}	
}

void string_array_lwr(char **target, int row){ 
    char **temp ;
    int i ;
    temp = (char **)malloc(row * sizeof(char*)) ;
    for (i = 0;i< row;i++){
        temp[i] = (char *)malloc(MAXSTR * sizeof(char)) ;
    }
    for (i = 0; i< row; i++){
        strcpy(temp[i],strlwr(target[i])) ;
    }
    for(i = 0; i<row; i++){
        strcpy(target[i], temp[i]) ;
    }
}

void printstrarray(char** arr, int row){  // debugging function
    int i ;
    for (i = 0; i<row; i++){
        printf("%s\n", arr[i]) ;
    }
}

void get_string_database(char *** db, char ** newstring, int numData ,int col){
    int i = 0,j =0 ;
    for (i = 0;i< MAXROW; i++){
//    	printf("%s\n", *(*(db+i)+index)) ;
		strcpy(newstring[i],*(*(db+i)+col));
		if(i==numData)
			break ;	
    }
}

int str_search(char*** db, int numData, int col ,int *index, int *indexSearching, char *strSearch){
    char **strtemp, *pch ;
    int sizeSearch = 0, i, j=0 ;
    strtemp = (char**)malloc(MAXROW*sizeof(char*)) ;
    for (i = 0;i<MAXROW;i++){
    	strtemp[i] = (char *)malloc(MAXSTR * sizeof(char)) ;
	}
//    printstrarray(strtemp,numData) ;
    get_string_database(db, strtemp, MAXROW, col) ;
    strcpy(strSearch,strlwr(strSearch)) ;
    string_array_lwr(strtemp,MAXROW) ;
    
	for (i = 0 ; i < numData ; i++){
//		printf("%s dan %s ", *(strtemp+index[i]), strSearch) ;
		pch = strstr(*(strtemp+index[i]),strSearch) ;
		if (pch != NULL){
//			printf(" MATCH! ") ;
			indexSearching[j] = index[i];	
			sizeSearch++;
			j++ ;	
		}
//		printf("i = %d --> %d,  j = %d --> %d\n", i, index[i], j, index[j]) ;
	}
    free(strtemp) ;
    free(pch) ;
	return sizeSearch ;
}

int indexSwap (int *change, int *withthis, int *safefirst, int thisize , int changesize ){
	int i ;
	for (i = 0; i<MAXROW ; i++){
		safefirst[i] = 0 ;	// bersihkan dlu
	}
	for (i =0; i< changesize; i++){
		safefirst[i] = change[i] ;
	}
	for (i =0; i< thisize; i++){
		change[i] = withthis[i] ;
		withthis[i] = 0;
	}	
}

void editDatabase(char ***database, int *numData, int *index, char airlines[][20]){

	char *inputEditFN,*inputEditDate;
	int i,sizeFN,sizeDate, *indexFN, *indexDate, editFlag = 0,inputDataFlag = 0, exitFlag = 0, inputExit, inputParam, anotherParameterFlag = 0,flagDate = 0,flagAirline = 0,userInput,flagTime = 0;
	
	indexFN = (int *)malloc(MAXROW*sizeof(int)) ;
	indexDate = (int *)malloc(MAXROW*sizeof(int)) ;
	inputEditDate = (char *)malloc( 15 * sizeof(char)) ;
    inputEditFN = (char *)malloc( 15 * sizeof(char)) ;

    while(!inputDataFlag)
    {
    	system("cls") ;
		printf("\nData Edited by Using Flight Number and Flight Date\n\n") ;
    	printf("Please Enter The Corresponding Flight Date and Flight Number\n\n") ;
    	sortingIndex(index, numData[0]) ;
        displayDatabase(database,numData[0],index) ;
    	printf("Enter Flight Number\t: ") ; //find data that to be edited by flight number and flight date
	    fflush(stdin) ;
	    scanf("%[^\n]s",inputEditFN) ;
	    printf("Enter Flight Date\t: ") ;
	    fflush(stdin) ;
	    scanf("%[^\n]s",inputEditDate) ;
	    
		sortingIndex(index,numData[0]) ;
        sizeFN = str_search(database,numData[0],6,index,indexFN, inputEditFN) ;
        sizeDate = str_search(database,sizeFN,2,indexFN,indexDate, inputEditDate) ;
        
        system("cls") ;
	    printf("Flight Number: %s\t\tFlight Date: %s\n\n",strupr(inputEditFN), inputEditDate) ;
        displayDatabase(database,sizeDate,indexDate) ;
        
        if(sizeDate != 0){ //if data found
        	editFlag = 0;
        	exitFlag = 1;
		} else{ //if data not found 
			printf("\nData Not Found!\n");
//			exitFlag = 0;
			editFlag = 1;
		}
    	
    	while (!editFlag){
    		printf("\nEdit Data's Paramater' : \n1. From\n2. To\n3. Flight Date\n4. Departure Time\n5. Arrival Time\n6. Duration\n7. Flight Number\n8. Airline\n9. Available Seat\n10. Price\n0. Back\nOption : ") ;
    		scanf("%d",&inputParam);
			if(inputParam == 1){
				printf("Enter New Departure Location\t: ");
				fflush(stdin) ;
    			scanf("%[^\n]s",*(*(database+indexDate[0])+0)) ;
    			anotherParameterFlag = 0;
    			displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 2){
				printf("Enter New Arrival Location\t: ");
				fflush(stdin) ;
    			scanf("%[^\n]s",*(*(database+indexDate[0])+1)) ;
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 3){
				printf("Enter New Flight Date : ");
				fflush(stdin) ;
    			scanf("%[^\n]s",*(*(database+indexDate[0])+2)) ;
    			flagDate = 0;
    			while(!flagDate){ //error checking
		    		printf("Enter Flight Date\t: ") ;
		    		fflush(stdin) ;
		    		scanf("%[^\n]s",inputEditDate) ;
		    		flagDate = errorCheckingDate(inputEditDate); 
				}
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 4){
				flagTime = 0;
    			while(!flagTime){ //error checking
    				printf("Enter New Departure Time : ");
		    		fflush(stdin) ;
    				scanf("%[^\n]s",*(*(database+indexDate[0])+3)) ;
		    		flagTime = errorCheckingTime(*(*(database+indexDate[0])+3)) ;
				}
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 5){
				flagTime = 0;
    			while(!flagTime){
    				printf("Enter New Arrival Time: ");
					fflush(stdin) ;
    				scanf("%[^\n]s",*(*(database+indexDate[0])+4)) ;
		    		flagTime = errorCheckingTime(*(*(database+indexDate[0])+4)) ;
				}
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 6){
				flagTime = 0;
    			while(!flagTime){
    				printf("Enter New Duration : ");
					fflush(stdin) ;
    				scanf("%[^\n]s",*(*(database+indexDate[0])+5)) ;
		    		flagTime = errorCheckingTime(*(*(database+indexDate[0])+5)) ;
				}
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 7){
				printf("Enter New Flight Number: ");
				fflush(stdin) ;
    			scanf("%[^\n]s",*(*(database+indexDate[0])+6)) ;
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 8){
				printf("\n");
				for(i = 0; i < 5;i++){
        			printf("%d. %s\n", i+1, airlines[i]) ;
				}
				while(!flagAirline){
					printf("Enter New Airline (1 - 5): ");
					scanf("%d",&userInput);
					if((userInput < 1) || (userInput > 5)){
						printf("\nWrong Input\n");
						continue;
					}
					break;
				}
				strcpy(*(*(database+indexDate[0])+7),airlines[userInput-1]);
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 9){
				printf("Enter New Available Seat : ");
				fflush(stdin) ;
    			scanf("%[^\n]s",*(*(database+indexDate[0])+8)) ;
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 10){
				printf("Enter New Price : ") ;
				fflush(stdin) ;
    			scanf("%[^\n]s",*(*(database+indexDate[0])+9)) ;
    			anotherParameterFlag = 0;
				displayDatabase(database,sizeDate,indexDate) ;
			} else if (inputParam == 0){
				anotherParameterFlag = 1;
				editFlag = 1;
				exitFlag = 0;
			}else{
				printf("Wrong Input \n");
				anotherParameterFlag = 1;
			}
			
			while(!anotherParameterFlag){
				printf("1. Edit Another Parameter\n0. Back\nOption : ");
				scanf("%d",&inputParam);
				if(inputParam == 1){
					anotherParameterFlag = 1;	
				} else if (inputParam == 0){
					anotherParameterFlag= 1;
					editFlag = 1;
					exitFlag  = 0;		
				}
			}
		}
		while(!exitFlag){
//			system("cls");
			printf("\n1. Edit Another Data\n0. Back to Admin's Menu\nOption : ");
			scanf("%d",&inputExit);
			if(inputExit == 1)
			{
				exitFlag = 1;	
			} else if (inputExit == 0){
				exitFlag = 1;
				inputDataFlag = 1;
				system("cls");
			} else{
				printf("Wrong input\n") ;
			}
		}	
	}
}

void getColumnDatabase(char ***database, int *index, int size, char **tempTime, int col) {
	int i;
	
	for(i = 0; i < size; i++){
		strcpy(tempTime[i],database[index[i]][col]); //copy data from specific column in database to array 2D tempTime
	}		
}

void formatPrice(char **dataPrice, int *temp, int size){
    int i;
    
    for(i = 0; i < size; i++)
    {
    	temp[i] = atoi(dataPrice[i]); //convert from string to integer using atoi
	}
}

int numSearch(char ***database, int sizeArrow, int *indexArrow, int *indexTarget, int *temp, int min, int max, int col) {
	int i,j = 0;
	
	for(i = 0; i < sizeArrow; i++){
		if((temp[i] >= min) && (temp[i] <= max)){ //find data in a column inside the database that includes in the range minimum value and  maximum value and return number of data
			indexTarget[j] = indexArrow[i]; //fill indexTarget array with an index that its value includes in the range minimum value and maximum value
			j++;
		}
		
	}
	return j;
	
}

void deleteDatabase(char *** database, int *numData, int *index){
	
	char *inputEditFN,*inputEditDate;
	int sizeFN,sizeDate, *indexFN, *indexDate, editFlag = 0,inputDataFlag = 0, exitFlag = 0, inputExit, inputParam,i,j,flagDate = 0;
	
	indexFN = (int *)malloc(MAXROW*sizeof(int)) ;
	indexDate = (int *)malloc(MAXROW*sizeof(int)) ;
	inputEditDate = (char *)malloc( 15 * sizeof(char)) ;
    inputEditFN = (char *)malloc( 15 * sizeof(char)) ;

    while(!inputDataFlag)
    {
    	system("cls") ;
		printf("\nData Deleted by Using Flight Number and Flight Date\n\n") ;
    	printf("Please Enter The Corresponding Flight Date and Flight Number\n\n") ; //find data that to be deleted by flight number and flight date
    	sortingIndex(index, numData[0]) ;
        displayDatabase(database,numData[0],index) ;
    	printf("Enter Flight Number\t: ") ;
	    fflush(stdin) ;
	    scanf("%[^\n]s",inputEditFN) ;
	    while(!flagDate){ //error checking
	    	printf("Enter Flight Date\t: ") ;
	    	fflush(stdin) ;
	    	scanf("%[^\n]s",inputEditDate) ;
	    	flagDate = errorCheckingDate(inputEditDate); 
		}

		sortingIndex(index,numData[0]) ;
        sizeFN = str_search(database,numData[0],6,index,indexFN, inputEditFN) ;
        sizeDate = str_search(database,sizeFN,2,indexFN,indexDate, inputEditDate) ;
        
        system("cls") ;
	    printf("Flight Number: %s\t\tFlight Date: %s\n\n",strupr(inputEditFN), inputEditDate) ;
        displayDatabase(database,sizeDate,indexDate) ;
        
        if(sizeDate != 0){
        	editFlag = 0;
        	exitFlag = 1;
		} else{ //if input flight date and flight number data not found
			printf("\nData Not Found!\n");
			editFlag = 1;
		}
    	
    	while (!editFlag){
    		printf("\nAre you sure to delete data with flight number : %s , flight date : %s ?\n1. Yes\n0. No\nOption : ", inputEditFN, inputEditDate) ;
    		scanf("%d",&inputParam);
			if(inputParam == 1){
				for(i = indexDate[0] ; i < numData[0] - 1;i++){
					for(j = 0; j < 10;j++){
						strcpy(database[i][j],database[i+1][j]); //data at specific column on index i filled with data from index i + 1 for i >= index of data that to be deleted && i < number of all data - 1
					}
				}
				numData[0]--; //decrease number of data 
				editFlag = 1;
				exitFlag = 0;
    			displayDatabase(database,numData[0],index) ;
    			printf("\n\tData with flight number : %s , flight date : %s has successfully deleted.\n\n", inputEditFN, inputEditDate) ; 
			} else if (inputParam == 0){
				editFlag = 1;
				exitFlag = 0;
			}else{
				printf("Wrong Input \n");
			}
			
		}
		while(!exitFlag){
			
			printf("\n1. Delete Another Data\n0. Back to Admin's Menu\nOption : ");
			scanf("%d",&inputExit);
			if(inputExit == 1)
			{
				exitFlag = 1;	
			} else if (inputExit == 0){
				exitFlag = 1;
				inputDataFlag = 1;
				system("cls");
			} else{
				printf("Wrong input\n") ;
			}
		}	
	}
	
}

int indexCopy (int *target,int *arrow, int sizeArrow){
	int i;
	for(i = 0; i < sizeArrow; i++){
		target[i] = arrow[i];
	}
}


