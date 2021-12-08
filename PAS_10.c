/**
 *      Proyek 2 Algoritma dan Pemograman
 *      1. Louis M. D. Wijaya / 1906379296
 *      2. Wilson A           / 1906379541
 **/  
// Template robot:
// printf("\n <|0_0|>./ ") ;

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <time.h>
# include "error_checking.h"
#define NUMDATABASE 3
# define MAXSTR 30
const int MAXDATA = 40;
const int MAXCOL = 10 ;
const int MAXAIRLINE = 10 ;



typedef struct flightdata{
	char from[MAXSTR] ;
	char to[MAXSTR] ;
	char date[MAXSTR] ;
	char depTime[MAXSTR] ;
	char arrivalTime[MAXSTR] ;
	char duration[MAXSTR] ;
	char flightNum[MAXSTR] ; 
	char airline[MAXSTR] ;
	int availSeat ; 
	int price ;
} structFlightData ;

typedef struct airline{
	char name[MAXSTR] ;
} structAirline;

struct node {
	int *index ;
	int size ;
	struct node *prev ;
	struct node *next ;
} typedef node ;


struct profile {
	char name[MAXSTR] ;
	char gender[2] ; 		// M/F 
	char phoneNumber[MAXSTR] ;
	char password[MAXSTR] ;
	int userID ;
	int voucher ;
} typedef profile ;

struct ticket {
	char name[MAXSTR] ;
	char gender[2] ; 		// M/F 
	structFlightData flight ;
} typedef ticket ;

typedef struct voucher{
	int minimum;
	int discount;
	int count;
}voucher;

typedef struct nodeT{
	ticket userTicket;
	struct nodeT *next;
} nodeTicket ; 

node *start ;

// on database
void fillIndex(int *index, int numData) ;

/* on main function */
void admin_function(structFlightData  *flightDatabase,structAirline *listAirlines,int *numDatabase) ;
void user_function(structFlightData  *flightDatabase,structAirline *listAirlines,int *numDatabase) ;
void print_menu() ;
void print_frame(char *str);

/* on user_function */
int  user_menu(structFlightData  *flightDatabase, structAirline *listAirlines, int *numDatabase) ;
node *init_node() ;
void insert_node( node **Node, int *input_index, int input_size );
nodeTicket *init_node_ticket() ;
void insert_node_ticket(nodeTicket **node, ticket input) ;
void book_a_flight(structFlightData  *flightDatabase, structAirline *listAirlines, int *numDatabase);
int  search_sort_menu(structFlightData *flightDatabase,structAirline *listAirlines, node **head_ptr);
profile get_user_profile()  ;
int get_ticket_normal(structFlightData *FlightDatabase, int select, nodeTicket **head) ;
int get_ticket_account(structFlightData *FlightDatabase, int select, profile account,nodeTicket **head) ;
void printTicket(nodeTicket **head, int index) ;
int getTotalPrice(nodeTicket **head) ;

/* on algorithm (both menu) */
void copyIndex(int *target,int *arrow, int sizeArrow);
void fillIndex(int *index, int numData) ;
void string_array_lwr(char **target, int row) ;
int  str_search(structFlightData *flightDatabase, int numData, int col ,int *index, int *indexTarget, char *strSearch);
void get_string_database(structFlightData *flightData, int *index, char ** newstring, int numData ,int col);
void get_integer_database(structFlightData *flightData, int *index, int *newInt, int numData ,int col) ;
node *undo_control(node **temp) ;
node *redo_control(node **temp) ;
int numSearch(int sizeArrow, int *indexArrow, int *indexTarget, int *temp, int min, int max) ;
int filterDepTime(structFlightData *flightData, int *indexArrow, int sizeArrow, int *indexTarget, int userOption);
int filterPrice(structFlightData *flightData, int *indexArrow, int sizeArrow, int *indexTarget, int minVal, int maxVal) ;
void sortingFlightData(structFlightData *flightData, int *indexArrow, int sizeArrow, int mode, int dataType, int col) ;
int get_user_from_database ();

// int timeFilterFunction(structFlightData *flightdata, node ** node_ptr) ;
char* get_airline(char *message, structAirline *listAirlines ) ;
void header_search_sort_menu(structFlightData *flightDatabase, node **temp) ;

//error checking
int  errorCheckingTime(char check[]) ;

//converter
void formatDate(char **dataDate, int *dateInt, int size) ;                              									// convert date (string) to integer for sorting purpose
void formatTime(char **dataTime, int *temp, int size) ;                                 									// convert boarding time, duration, and arrival time in string form to integer form for sorting purpose

//function for quick sort algorithm
int partition	(int *temp, int *index, int bawah, int atas, int mode);         											// make partition for quick sort
void quickSort	(int *temp, int *index, int bawah, int atas, int mode);         											// quick sort algorithm
void swapNumber	(int *dataNilai, int*dataIndex, int a , int b,int mode);													// swap number
// void sortingIndex(int *index, int size) ;	

//delay
void delay(int milliseconds) ;

//database function
int  readFlightDatabase(structFlightData  *flightData) ;
void writeFlightDatabase(structFlightData  *flightData, int *numData) ;
int  readListOfAirlineDatabase(structAirline *listAirlines) ;
void writeListOfAirlineDatabase(structAirline *listAirlines, int *numData) ;
int readUserDatabase(profile *userData) ;
void writeUserDatabase(profile *userData, int *numData) ;
int readVoucher() ;
void writeVoucher() ;
void inputOptionFlight(structFlightData  *flightData, int *numData,structAirline *listAirlines) ;
int  inputFlightDatabase(structFlightData  *flightData, int *numData, char *airline) ;
void inputOptionAirline(structAirline *listAirlines, int *numData) ;
void inputDatabase(structFlightData  *flightData,structAirline *listAirlines, int *numDatabase) ;
void editFlightDatabase(structFlightData  *flightData, int *numData, structAirline *listAirlines) ;
int  inputEdit(char *message, char *input) ;
void inputVoucher() ;
void deleteDatabase(structFlightData  *flightData,structAirline *listAirlines, int *numDatabase) ;
void deleteFlightDatabase(structFlightData  *flightData, int *numData) ;
void deleteAirlineDatabase(structFlightData  *flightData, structAirline *listAirlines ,int *numData) ;
void deleteFlightData(structFlightData  *flightData, int *numData, int startIndex) ;
void displayAirlineDatabase(char *message,structAirline *listAirlines);
void displayFlightDatabase(structFlightData  *flightData, int numData, int *index) ;
void displayUserDatabase() ;
void displayDatabase(structFlightData  *flightData, structAirline *listAirlines ,int *numData) ;

int help = 0, numAirlines, numUser, numVoucher ;

profile *listUser;
voucher *voucherDiscount ;

int main(){
    int menu, *numDatabase;
    structFlightData  *flightDatabase;
    structAirline *listAirlines;

    numDatabase= (int *)malloc(NUMDATABASE*sizeof(int)) ;

    flightDatabase = (structFlightData  *)malloc(MAXDATA*sizeof(structFlightData )) ;
    listAirlines = (structAirline *)malloc(MAXAIRLINE*sizeof(structAirline)) ;
    listUser = (profile*)malloc(MAXDATA*sizeof(profile)) ;
    voucherDiscount = (voucher*)malloc(sizeof(voucher)) ;

	printf("test\n") ;
	numVoucher = readVoucher(voucherDiscount) ;
    numDatabase[0] = readFlightDatabase(flightDatabase) ; // index 0 for access number of data on flight database
    printf("test") ;
    numDatabase[1] = readListOfAirlineDatabase(listAirlines) ; //index 1 for access number of data on  airlines database
	numDatabase[2] = readUserDatabase(listUser) ;
	numUser = numDatabase[2] ;

    do {
        system("cls") ;
        // printf("Num voucher : %d\n",numVoucher);
        print_menu() ;
        scanf("%d", &menu) ;
        if( menu == 0 ){
			system("cls") ;
            printf("\n <|0_0|>./ Bye-Bye !\n") ;
        }
        else if ( menu == 1 ){
            admin_function(flightDatabase,listAirlines,numDatabase) ;  // admin menu procedure
        }
        else if ( menu == 2 ){
            user_function(flightDatabase,listAirlines,numDatabase) ;   // User menu procedure
            numDatabase[2] = numUser;
        }
        else if ( menu == 3){
            help = !help ;      // enable on screen assistant
        }
        else {
            printf("Wrong input, please try again\n") ;
        }
    } while (menu!=0) ;
    writeVoucher(voucherDiscount) ;
    writeFlightDatabase(flightDatabase,numDatabase) ;
	writeListOfAirlineDatabase(listAirlines, numDatabase) ;
	writeUserDatabase(listUser, numDatabase) ;
	free(voucherDiscount) ;
	free(flightDatabase) ;
	free(listAirlines) ;
	free(listUser) ;
    return 0;
}

void print_frame(char *str){
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t%s", str);
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void print_menu() {
    system("color 0E") ;
    if (help)
        printf("\n <|0_0|>./ Hello!\n Welcome to our program\n Pick Admin Menu if you want to manage the flight database\n Pick User Menu to book a flight!\n") ;
    printf("\n====================================================== TicketWhat? 2.0 (Ticket Pesawhat) ======================================================\n\n");
    print_frame("Main Menu");
    printf("1. Admin Menu\n2. User Menu\n3. Toggle Help\n\n0. Exit\n\nOption : ") ;  
}

void header_search_sort_menu(structFlightData *flightDatabase, node **temp){
    system("cls") ;
    if (help)
        printf("\n <|0_0|>./ Let's pick your flight\n Here we have some sorting and searching function that you can try to find the best ticket\n when you already have the one in mind, pick menu 1 to pick the ticket\n") ; 
    print_frame("TicketWhat? 2.0") ;
    displayFlightDatabase(flightDatabase, (*temp)->size, (*temp)->index) ;
}

int search_sort_menu(structFlightData *flightDatabase,structAirline *listAirlines, node **temp){
    // system("cls") ;
    int *indexTarget = (int*)malloc(MAXDATA * sizeof(int)) ;
    int sizeTarget, option, userOption, minVal, maxVal, select, yorno, index; 
    char *input ;
    input = (char*)malloc(MAXSTR*sizeof(char)) ;
    header_search_sort_menu(flightDatabase, &(*temp)) ;
	printf("User Menu:\n1. Pick Ticket\n2. Filter by Departure Time\n3. Filter by Price\n");
    printf("4. Filter by Airlines\n5. Sort by Lowest Price\n6. Sort by Earliest Departure\n7. Sort by Shortest Duration\n\n8. Undo\n9. Redo\n\n0. Back\n\nOption: ") ;
    scanf("%d", &option) ;
    if ( option == 0){          // Exit to user_menu
        return 0 ;   
    }
    else if (option == 1){      // Pick Ticket
    	nodeTicket *head = NULL ;
		profile user ;
		header_search_sort_menu(flightDatabase, &(*temp)) ;
		/* user profile */
		do{
			printf("Select your ticket by index : ") ;
			scanf("%d", &select) ;
		} while(!(select >= 1 && select <= (*temp)->size)) ;

		do {
			printf("Have you ever book a flight here? (1:yes, 0:no): ");
			scanf("%d", &yorno) ;
		} while (!(yorno == 1|| yorno==0)) ;
		if (yorno==1){
			/* get user from database */
			index = get_user_from_database();
			if(index == -1){
				do{
					printf("1. Register \n0. Back\n\nOption : ");
					scanf("%d",&userOption) ;
				} while(!(userOption == 1 || userOption == 0)) ;
				if(userOption == 1){
					user = get_user_profile() ;
					listUser[numUser] = user ;
					numUser++;
				} else if (userOption == 0){
					return 0;
				}
				
			} else if (index >= 0){
				user = listUser[index] ;
			}
			
		}
		else if ( yorno== 0){
			user = get_user_profile() ;
			listUser[numUser] = user ;
			index  = numUser;
//			printf("%s\n",listUser[numUser].name) ;
			numUser++;
		}		
		do{
			printf("Do you want to use your data as first passenger? (1:yes, 0:no) : "); 
			scanf("%d", &yorno) ;
		}while(!(yorno==1|| yorno==0));
		if (yorno==1){
			while(get_ticket_account(flightDatabase,(*temp)->index[select-1],user,&head));
		} else if (yorno==0){
			while(get_ticket_normal(flightDatabase,(*temp)->index[select-1],&head));
		}
		printf("%s\n",head->userTicket.name);
//		printf("%s\n",head->userTicket.flight.airline) ;
//		printf("test cek\n\n") ;
		printTicket(&head, index) ;
		/* apply voucher */
		return 0;	
    }
    else if (option == 2){      // Filter by depature time
        /* Filter with number */
        header_search_sort_menu(flightDatabase, &(*temp)) ;
        printf("Time range option:\n1. Early Morning (00:00 - 06:00)\n2. Morning (06:00 - 12:00)\n3. Afternoon (12:00 - 18:00)\n4. Evening (18:00 - 24:00)\n");
        printf("What is your prefered departure time \t: ") ;
        scanf("%d",&userOption) ;
        
        sizeTarget = filterDepTime(flightDatabase, (*temp)->index, (*temp)->size, indexTarget, userOption);
        printf("updated to %d index\n", sizeTarget) ;
        insert_node(&(*temp), indexTarget, sizeTarget) ;
    }
    else if (option == 3){      // Filter by price
        /* Filter with number */
        header_search_sort_menu(flightDatabase, &(*temp)) ;
        printf("Enter Minimum Price : ") ;
        scanf("%d",&minVal) ;
        printf("Enter Maximum Price : ") ;
        scanf("%d",&maxVal) ;
        sizeTarget = filterPrice(flightDatabase, (*temp)->index, (*temp)->size, indexTarget, minVal, maxVal);
        printf("updated to %d index\n", sizeTarget) ;
        insert_node(&(*temp), indexTarget, sizeTarget) ;
    }
    else if (option == 4){		// Filter by airlines
        header_search_sort_menu(flightDatabase, &(*temp)) ;
        char *airline = get_airline("List of airlines:\n", listAirlines) ;
        printf("%s", airline) ;
        /* Filter with string airlines */
        sizeTarget = str_search(flightDatabase, (*temp)->size ,4 , (*temp)->index, indexTarget, airline) ;
        printf("updated to %d index\n", sizeTarget) ;
        insert_node(&(*temp), indexTarget, sizeTarget) ;
    }
    else if (option == 5){ 		// sort by lowest price
        sortingFlightData(flightDatabase, (*temp)->index, (*temp)->size, 1, 1, 0) ;
    }
    else if (option == 6){		// sort by earliest departure
        sortingFlightData(flightDatabase, (*temp)->index, (*temp)->size, 1, 0, 5) ;
    }
    else if (option == 7){		// 
        sortingFlightData(flightDatabase, (*temp)->index, (*temp)->size, 1, 0, 6) ;
    }
    else if (option == 8){ 		// undo
        *temp = undo_control(&(*temp)) ;
    }
    else if (option == 9){ 		// redo
        *temp = redo_control(&(*temp)) ;
    }
    else {
        printf("please input the correct range of value\n") ;
    }
    // scanf("%d", &option ) ;
    return 1;
}

node *undo_control(node **temp){
    node *ret = *temp ;
    if ( ret->next == NULL){
        return ret ;
    } else {
    	return ret->next ;
	}
    
}

node *redo_control(node **temp){
    node *ret = *temp ;
    if ( ret->prev == NULL){
        return ret ;
    } else {
    	return ret->prev ;
	}

}

void admin_function(structFlightData  *flightDatabase, structAirline *listAirlines, int *numDatabase) {
    system("cls") ;
    system("color 0F") ; // change color
    if (help)
        printf("\n <|0_0|>./ Please input your password\n it's not definitely not admin123\n") ;

    print_frame("Admin Function") ;

    int i,j,trial = 3,flagAdmin = 0, flagMenu = 0,option,menu, *index;
	char *password = "admin123", *passwordInput;
   	i = 0 ;
   	flagAdmin = 0 ;
   	
   	index = (int *)malloc(MAXDATA*sizeof(int)) ;
   	passwordInput= (char *)malloc( 15 *sizeof(char)) ;
   	
   	while ((i<trial) && !flagAdmin) {
        printf("Input Password: ") ; //pass = admin123
        fflush(stdin) ;                                             // clear stdin for using stdin
        scanf("%[^\n]s", passwordInput) ;                           // get password input
        if (!strcmp(passwordInput,password)){
            // insert admin function
            system("cls");
			if (help)
				printf("\n <|0_0|>./ Welcome to Admin's Menu\n Here we can maintain flight database, airline database and user database\n Try checking Display Database before making changes\n") ;
            do {
                print_frame("Admin's Menu") ;
                printf("1. Display Database\n2. Input Data\n3. Edit Data\n4. Delete Data\n0. Back to Main Menu \n\nOption : ") ;
                scanf("%d", &menu) ;
                if (menu==1){                                       // display data
                    displayDatabase(flightDatabase, listAirlines ,numDatabase) ;
                }else if (menu==2){                                 // input some data to database
                    // input data function
                    system("cls") ;
                    inputDatabase(flightDatabase,listAirlines,numDatabase) ;
                }else if (menu == 3) {
					editFlightDatabase(flightDatabase, numDatabase, listAirlines) ;
				}else if (menu == 4) {
					deleteDatabase(flightDatabase, listAirlines, numDatabase) ;
				}else if (menu == 0) {                                 // return to menu
                    flagAdmin = 1 ;                                 // break out from admin menu flag
                    system("cls") ;
                    break ;
                }else {
//                            printf("Wrong Input :( \n") ;
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
}

void user_function (structFlightData  *flightDatabase, structAirline *listAirlines, int *numDatabase){
    system("cls") ;
    system("color 0B") ; // change color
    if (help)
        printf("\n <|0_0|>./ Welcome to user function\n in here you can book plane ticket with all kind of search and sort function\n Let's try it out\n") ;
    print_frame("User Function") ;

    while (user_menu(flightDatabase,listAirlines,numDatabase)) ;
}

int user_menu(structFlightData  *flightDatabase, structAirline *listAirlines, int *numDatabase){
    int user_option, Flag_exit = 0, Flag_user = 0 ;
    printf("Menu: \n1. Book a Flight\n0. Back to Main Menu\n\nOption: ") ;
    scanf("%d", &user_option) ;
    if ( user_option == 0 ){
        system("cls") ;
        return 0 ;
    }
    else if ( user_option == 1 ){
        book_a_flight(flightDatabase,listAirlines,numDatabase) ;
        system("cls") ;
        return 0 ;
    }
    else {
        printf("Wrong input, please try again\n") ;
        return 1 ;
    }
}

void book_a_flight(structFlightData  *flightDatabase, structAirline *listAirlines, int *numDatabase){
    system("cls") ;
    if (help)
        printf("\n <|0_0|>./ Please answer the question accordingly\n and also mind your spelling, but dont worry for sensitive case\n I'll note it for you!\n") ;
 
    // initialize filtering variable
    int *indexTarget, sizeTarget, flagSearch=0,flagExit = 0,option;
    indexTarget= (int*)malloc(MAXDATA * sizeof(int)) ;
    char *fromPlace, *toPlace, *flightDate ;
    fromPlace= (char *)malloc( MAXSTR *sizeof(char)) ;
    toPlace= (char *)malloc( MAXSTR *sizeof(char)) ; 
    flightDate = (char *)malloc( 10 *sizeof(char) ) ;

	while(!flagExit){
	    print_frame("Book A Flight");
	    printf("Where are you from?\t\t: ") ;
	    fflush(stdin) ;
	    scanf("%[^\n]s" , fromPlace) ;
	    printf("Where do you want to go \t: ") ;
	    fflush(stdin) ;
	    scanf("%[^\n]s" , toPlace) ;
	
	    while(get_date("Date (DD/MM/YYYY Format)\t: ",flightDate));
	
	    node *head_ptr = init_node();
	
	    head_ptr->size = numDatabase[0];
	    fillIndex(head_ptr->index,head_ptr->size) ;
	    printf("fill %d index succeed\n", head_ptr->size) ;
	    
	    // search by fromPlace
	    sizeTarget = str_search(flightDatabase, head_ptr->size ,0 , head_ptr->index, indexTarget, fromPlace) ;
	    printf("updated to %d index\n", sizeTarget) ;
	    insert_node(&head_ptr, indexTarget, sizeTarget) ;
	
	    // search by toPlace
	    sizeTarget = str_search(flightDatabase, head_ptr->size ,1 , head_ptr->index, indexTarget, toPlace) ;
	    printf("updated to %d index\n", sizeTarget) ;
	    insert_node(&head_ptr, indexTarget, sizeTarget) ;
	
	    // search by date 
	    sizeTarget = str_search(flightDatabase, head_ptr->size ,2 , head_ptr->index, indexTarget, flightDate) ;
	    printf("updated to %d index\n", sizeTarget) ;
	    insert_node(&head_ptr, indexTarget, sizeTarget) ;   
	
	    node *temp = init_node() ; 
	    temp->index = head_ptr->index ;
	    temp->size = head_ptr->size ;
	    if((head_ptr)->size == 0){
	    	header_search_sort_menu(flightDatabase, &(temp)) ;
	    	printf("Flight Not Found.\n\n") ;
		} else {
			while (search_sort_menu(flightDatabase, listAirlines, &temp)) ;	
		}
	    while(1){
	    	printf("\n1. Book Another Flight\n0. Back to Main Menu\n\nOption : ");
			scanf("%d",&option);
			if(option == 1){
				flagExit = 0;
				system("cls") ;
				break ;	
			} else if (option == 0){
				flagExit = 1;
				system("cls") ;
				break ;
			} else {
				printf("Wrong input.\n") ;
			}
		}
	}
}

profile get_user_profile() {
	int option ;
	profile user ;
	system("cls") ;
	if (help)
		printf("\n <|0_0|>./ Hello, please input your data here\n user National ID or NIK would be use for the verification process\n") ;
	/* Get user data */
	print_frame("User Profile") ;
	printf("Name\t\t\t: ") ;
	fflush(stdin) ;
	scanf("%[^\n]s", user.name) ;
	printf("Gender (M/F)\t\t: ") ;
	fflush(stdin) ;
	scanf("%[^\n]s", user.gender) ;
	fflush(stdin) ;
	printf("Phone Number \t\t: ") ;
	scanf("%[^\n]s", user.phoneNumber) ;
	printf("User National ID\t: ") ;
	scanf("%d", &user.userID) ;
	printf("\nInput your password\t: ") ;
	fflush(stdin) ;
	scanf("%[^\n]s", user.password) ;
	user.voucher = 0 ;
	do{
		printf("\nContinue (0:change data, 1: continue)? : ") ;
		scanf("%d", &option) ;
	} while( !(option==1 || option==0) ) ; 
	
	if (option==1)
		return user ;
	else if(option==0)
		user = get_user_profile() ;
	
}

int get_user_from_database (){
	int indexPass, index, attemp = 3,i ;
	char password[MAXSTR],nomorHP[MAXSTR] ;
	profile out ;
	system("cls") ;
	print_frame("---User Login---") ;
	// get user phone number
	do{

		printf("Attempt left : %d\n",attemp) ;
		printf("Phone Number\t\t: ") ;
		fflush(stdin) ;
		scanf("%[^\n]s", nomorHP);
		printf("Password\t\t: ");
		fflush(stdin) ;
		scanf("%[^\n]s", password);
		for(i = 0; i < numUser; i++){
			if(!(strcmp(nomorHP,listUser[i].phoneNumber))){
				if(!(strcmp(password,listUser[i].password))){
					printf("Your Data is Registered! \n\n ") ;
					index = i;
					break ;
				}
				else {
					system("cls") ;
					print_frame("---User Login---") ;
					printf("Wrong Password.\n") ;
					index = -1;
				}
			} else {				
				system("cls") ;
				print_frame("---User Login---") ;
				printf("User Not Found.\n") ;
				index = -1;
			}
		}	
		if(index != -1){
			break;
		}
		attemp--;
	} while(attemp > 0) ;
 
	return index ;
}

int get_ticket_normal(structFlightData *FlightDatabase, int select,nodeTicket **head){
	int option; 
	ticket out ;
	printf("Passenger name\t\t: ") ;
	fflush(stdin) ;
	scanf("%[^\n]s", out.name) ;
	printf("Passenger sex (M/F) \t: ") ;
	fflush(stdin) ;
	scanf("%[^\n]s", out.gender) ;
	strcpy(out.flight.airline,FlightDatabase[select].airline);
	strcpy(out.flight.depTime,FlightDatabase[select].depTime);
	strcpy(out.flight.arrivalTime,FlightDatabase[select].arrivalTime);
	strcpy(out.flight.flightNum,FlightDatabase[select].flightNum);
	strcpy(out.flight.date,FlightDatabase[select].date);
	strcpy(out.flight.from,FlightDatabase[select].from);
	strcpy(out.flight.to,FlightDatabase[select].to);
	out.flight.price = FlightDatabase[select].price ;
	FlightDatabase[select].availSeat--;
	insert_node_ticket(&(*head),out) ;
	
	do{
		printf("\nAdd another ticket (1:yes, 0 :no)? ") ;
		scanf("%d", &option) ;
	} while ( !(option==1||option==0)) ;
	if (option==1){
		// push ticket
		return get_ticket_normal(FlightDatabase, select,&(*head) );
	} else if (option == 0){
		
		// push ticket
		return 0 ;
	}	
}

int get_ticket_account(structFlightData *FlightDatabase, int select, profile account,nodeTicket **head){
	ticket out;
	int option ;
	strcpy(out.name, account.name) ;
	strcpy(out.gender,account.gender);
	strcpy(out.flight.airline,FlightDatabase[select].airline);
	strcpy(out.flight.depTime,FlightDatabase[select].depTime);
	strcpy(out.flight.arrivalTime,FlightDatabase[select].arrivalTime);
	strcpy(out.flight.flightNum,FlightDatabase[select].flightNum);
	strcpy(out.flight.date,FlightDatabase[select].date);
	strcpy(out.flight.from,FlightDatabase[select].from);
	strcpy(out.flight.to,FlightDatabase[select].to);
	out.flight.price = FlightDatabase[select].price;
	FlightDatabase[select].availSeat--;
	insert_node_ticket(&(*head),out) ;
	do{
		printf("\nAdd another ticket (1:yes, 0:no)? ") ;
		scanf("%d", &option) ;
	} while ( !(option==1||option==0)) ;
	if (option==1){
		// push ticket
		return get_ticket_normal(FlightDatabase, select,&(*head)) ;
	} else if (option==0){
		// push ticket
		return 0 ;
	}
}

void printTicket(nodeTicket **head, int index) { //ticket printed from linked list

	if(numVoucher > 0){
		if(voucherDiscount[0].minimum != -1){
			if(getTotalPrice(&(*head)) > voucherDiscount[0].minimum){
				listUser[index].voucher += 1; 
			}	
		} else {
			listUser[index].voucher += 0;
		}
	} 

	int discount;
	nodeTicket *temp;
	temp = *head;
	
	system("cls") ; 
    printf("Processing your ticket ") ;
    delay(250); //delay
    printf("..") ;
    delay(250) ;
    printf("..") ;
    delay(250) ;
    printf(".\n\n") ;
	printf("\n\n");
	
	while(temp->next != NULL) {
		printf("\t|=======================================================================================|\n") ;
	    printf("\t|\t\t\t\t%20s  \t\t\t\t\t|\n", (temp)->userTicket.flight.airline) ;
	    printf("\t|\t\t\t\t\t\t\t\t\t\t\t|\n") ;
	    printf("\t|	Name\t\t: %15s\tFlight Number\t:\t%10s\t|\n",(temp)->userTicket.name ,(temp)->userTicket.flight.flightNum ) ;
	    printf("\t|	Sex\t\t: %2s\t\t\tDate\t\t:\t%10s\t|\n",strupr((temp)->userTicket.gender),(temp)->userTicket.flight.date) ;
	    printf("\t|	From\t\t: \t%*s\tTo\t\t:\t%10s\t|\n",10,(temp)->userTicket.flight.from,(temp)->userTicket.flight.to) ;
	    printf("\t|	Departure Time\t: %5s\t\t\tArrival Time\t:\t%10s\t|\n",(temp)->userTicket.flight.depTime,(temp)->userTicket.flight.arrivalTime) ;
	    printf("\t|\t\t\t\t\t\t\t\t\t\t\t|\n") ;
	    printf("\t|	*Tunjukan e-ticket untuk mendapatkan Boarding pass\t\t\t\t|\n") ;
	    printf("\t|=======================================================================================|\n") ;
	    printf("\n\n") ;
	    temp = temp->next; //traverse the data in linked list
	}
	printf("\t|=======================================================================================|\n") ;
    printf("\t|\t\t\t\t%20s  \t\t\t\t\t|\n", (temp)->userTicket.flight.airline) ;
    printf("\t|\t\t\t\t\t\t\t\t\t\t\t|\n") ;
    printf("\t|	Name\t\t: %15s\tFlight Number\t:\t%10s\t|\n",(temp)->userTicket.name ,(temp)->userTicket.flight.flightNum ) ;
    printf("\t|	Sex\t\t: %2s\t\t\tDate\t\t:\t%10s\t|\n",strupr((temp)->userTicket.gender),(temp)->userTicket.flight.date) ;
    printf("\t|	From\t\t: \t%*s\tTo\t\t:\t%10s\t|\n",10,(temp)->userTicket.flight.from,(temp)->userTicket.flight.to) ;
    printf("\t|	Departure Time\t: %5s\t\t\tArrival Time\t:\t%10s\t|\n",(temp)->userTicket.flight.depTime,(temp)->userTicket.flight.arrivalTime) ;
    printf("\t|\t\t\t\t\t\t\t\t\t\t\t|\n") ;
    printf("\t|	*Tunjukan e-ticket untuk mendapatkan Boarding pass\t\t\t\t|\n") ;
    printf("\t|=======================================================================================|\n") ;
    printf("\n\n") ;
    printf("Total Price\t\t\t: Rp. %d\n", getTotalPrice(&(*head)));
    if(numVoucher == 0){
    	discount = 0;
	} else {
		if(listUser[index].voucher == voucherDiscount[0].count) {
	    	discount = voucherDiscount[0].discount;
	    	listUser[index].voucher = 0;
		} else {
			discount = 0;
		}
	}


    printf("Discount\t\t\t: Rp. %d\n",discount) ;
    printf("Total Price with Discount\t: Rp. %d\n\n", getTotalPrice(&(*head)) - discount) ;
	
}

int getTotalPrice(nodeTicket **head) {
	int totalPrice = 0;
	nodeTicket *temp;
	temp = *head ;
	while(temp->next != NULL){
		totalPrice += (temp)->userTicket.flight.price;
		temp= temp->next ;
	}
	totalPrice += (temp)->userTicket.flight.price;
	return totalPrice;
}

void insert_node( node **Node, int *input_index, int input_size ){
    // menggunakan skema push
    node *t = init_node();

    // input to node t
    t->size = input_size ;
    copyIndex(t->index, input_index, t->size) ;

    t->prev = NULL ;

    // menghubungkan dengan node lama
    t->next = (*Node) ;

    // mengubah prev dari head ke new node
    if ( *Node != NULL ){
        (*Node)->prev = t ;
    } 
    // memeindahkan head ke point untuk new node
    (*Node) = t ;
}

node *init_node(){
    node *node_ptr = NULL ;
    node_ptr = (node*)malloc(sizeof(node)) ;
    node_ptr->index = (int*)malloc(MAXDATA*sizeof(int));
    node_ptr->next  = NULL ;
    node_ptr->prev = NULL ;
    return node_ptr ;
}

nodeTicket *init_node_ticket() {
	nodeTicket *node_ptr = NULL;
	node_ptr = (nodeTicket*)malloc(sizeof(nodeTicket)) ;
	node_ptr->next = NULL;	
}

void insert_node_ticket(nodeTicket **node, ticket input) {
	nodeTicket *t = init_node_ticket() ;
	nodeTicket *temp;
	
	t->userTicket = input;
	t->next = NULL;
	
	if(*node == NULL){
		*node = t;
		return;
	}
	temp = (*node) ;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = t;
}

void fillIndex(int *index, int numData) {
	int i;
	for(i = 0 ; i < numData; i++) {
		index[i] = i;
	}
}

void copyIndex(int *target,int *arrow, int sizeArrow){
	int i;
	for(i = 0; i < sizeArrow; i++){
		target[i] = arrow[i];
	}
}

void get_string_database(structFlightData *flightData, int *index, char ** newstring, int numData ,int col){
    int i = 0,j =0 ;

    if (col==0){ //get array of departure location data from flight database
        for (i = 0;i< MAXDATA; i++){

            strcpy(newstring[i],flightData[index[i]].from);
            if(i == numData-1)
                break ;	
        }
    }
    else if (col==1){ //get array of arrival location data from flight database
        for (i = 0;i< MAXDATA; i++){
            strcpy(newstring[i],flightData[index[i]].to);
            if(i==numData-1)
                break ;	
        }
    }
    else if (col==2){ //get array of flight date data from flight database
        for (i = 0;i< MAXDATA; i++){
            strcpy(newstring[i],flightData[index[i]].date);
            if(i==numData-1)
                break ;	
        }
    }
    else if (col == 3){//get array of flight number data from flight database
        for (i = 0;i< MAXDATA; i++){
            strcpy(newstring[i],flightData[index[i]].flightNum) ;
            if(i==numData-1)
                break ;	
        }       
    }
    else if (col == 4){ //get array of airline's data from flight database
        for (i = 0;i< MAXDATA; i++){
            strcpy(newstring[i],flightData[index[i]].airline) ;
            if(i==numData-1)
                break ;	
        }       
    }
    else if (col == 5){ //get array of dep time data from flight database
        for (i = 0;i< MAXDATA; i++){
            strcpy(newstring[i],flightData[index[i]].depTime) ;
            if(i==numData-1)
                break ;	
        }       
    }
    else if (col == 6){ //get array of duration data from flight database
        for (i = 0;i< MAXDATA; i++){
            strcpy(newstring[i],flightData[index[i]].duration) ;
            if(i==numData-1)
                break ;	
        }       
    }
    
    else {
        printf("Function not yet available for this search\n") ;
    }
}

void get_integer_database(structFlightData *flightData, int *index, int *newInt, int numData ,int col) {
	int i;
	
	if(col == 1){ //price
		for(i = 0 ; i < numData; i ++){ 
			newInt[i] = flightData[index[i]].price ;
		}
	} else if (col == 2){ //seat
		
	}
}

void string_array_lwr(char **target, int row){ 
    char *temp ;
    int i ;
    temp = (char *)malloc(MAXSTR * sizeof(char)) ;
    
    for (i = 0; i< row; i++){
    	strcpy(temp,target[i]) ;
        strcpy(target[i],strlwr(temp)) ;
    }
}

int str_search(structFlightData *flightDatabase, int numData, int col ,int *index, int *indexTarget, char *strSearch){
    char **strtemp, *pch ;
    int sizeSearch = 0, i, j = 0 ;
    strtemp = (char**)malloc(MAXDATA*sizeof(char*)) ;
    
    for (i = 0;i<MAXDATA;i++){
    	strtemp[i] = (char *)malloc(MAXSTR * sizeof(char)) ;
	}
	
	if(numData != 0){
	    // get string by column 
	    get_string_database(flightDatabase, index ,strtemp, numData, col) ;
	    // set to lowercase letter for every string
	    strcpy(strSearch,strlwr(strSearch)) ;
	    string_array_lwr(strtemp,numData) ;
		for (i = 0 ; i < numData ; i++){
			printf("%s dan %s\n", *(strtemp+i), strSearch) ;
			pch = strstr(*(strtemp+i),strSearch) ;
			if (pch != NULL){
				printf(" MATCH! ") ;
				indexTarget[j] = index[i];	
				sizeSearch++;
				j++ ;	
			}
		}
		return sizeSearch ;
	} else{
		return 0;
	}
    free(strtemp) ;
    free(pch) ;
}

int readFlightDatabase(structFlightData  *flightData) {
	int numData, i;
	
	FILE *fp = fopen("flightdatabase.txt","r") ;
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("flightdatabase.txt","w") ;
        fclose(fp);
        printf("File 'flightdatabase.txt' does not exist, I JUST CREATED IT, exiting...\n\n\n") ;
        return 0;
    }

    numData = fread(flightData, sizeof(structFlightData ),MAXDATA, fp);

    fclose(fp);
    return numData ;
}

void writeFlightDatabase(structFlightData  *flightData, int *numData) {
	int i;
	FILE *fp = fopen("flightdatabase.txt","w") ;
    if(fp == NULL)
    {
        printf("Error") ;
        exit(1) ;
    }
    fwrite(flightData, sizeof(structFlightData ),numData[0], fp) ;
    
    fclose(fp);
}

int readListOfAirlineDatabase(structAirline *listAirlines) {
	int numData, i;
	
	FILE *fp = fopen("listairlines.txt","r") ;
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("listairlines.txt","w") ;
        fclose(fp);
        printf("File 'listairlines.txt' does not exist, I JUST CREATED IT, exiting...\n\n\n") ;
        return 0;
    }

    numData = fread(listAirlines, sizeof(structAirline ),MAXAIRLINE ,fp);
    fclose(fp);
    numAirlines = numData ;
    return numData ;
}

void writeListOfAirlineDatabase(structAirline *listAirlines, int *numData) {
	int i;
	FILE *fp = fopen("listairlines.txt","w") ;
    if(fp == NULL)
    {
        printf("Error") ;
        exit(1) ;
    }
    fwrite(listAirlines, sizeof(structAirline),numData[1], fp) ;  
    fclose(fp);
}

int readUserDatabase(profile *listUser) {
	int numData;
	FILE *fp = fopen("User.txt","r") ;

    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("User.txt","w") ;
        fclose(fp);
        printf("File 'userdatabase.txt' does not exist, I JUST CREATED IT, exiting...\n\n\n") ;
        return 0;
    }
    numData = fread(listUser, sizeof(struct profile),MAXDATA ,fp);
    fclose(fp);
    numUser = numData;
    return numData;
}

void writeUserDatabase(profile *listUser, int *numData) {
	FILE *fp = fopen("User.txt","w") ;
    if(fp == NULL)
    {
        printf("Error") ;
        exit(1) ;
    }
    fwrite(listUser, sizeof(struct profile),numData[2], fp) ;  
    fclose(fp);
}

int readVoucher(voucher *voucherDiscount) {
	int numData;
	FILE *fp = fopen("VoucherDisc.txt","r") ;

    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("VoucherDisc.txt","w") ;
        fclose(fp);
        printf("File 'Voucher.txt' does not exist, I JUST CREATED IT, exiting...\n\n\n") ;
        return 0;
    }
    numData = fread(voucherDiscount, sizeof(voucher),1,fp);
    fclose(fp);
    return numData;
}

void writeVoucher(voucher *voucherDiscount) {
	FILE *fp = fopen("VoucherDisc.txt","w") ;
    if(fp == NULL)
    {
        printf("Error") ;
        exit(1) ;
    }
    fwrite(voucherDiscount, sizeof(voucher),numVoucher,fp) ;  
    fclose(fp);	
}

void displayFlightDatabase(structFlightData *flightData, int numData, int *index){
    int i = 0, j=1;
    char header[10][15] = {"From","To","Flight Date","De.Time","Ar.Time","Dur","Fl Num", "Airline", "Available Seat","Price"} ;
    printf("\n\n");
    printf("\t                                                     -Airport Database-                                                        \n\n") ;
    printf("\tNumber of Flight Data : %d\n\n",numData) ;
    printf("\t==============================================================================================================================") ;
    printf("\n\t No |%s",header[0]);
    printf("\r\t\t\t|%s",header[1]) ;
    printf("\r\t\t\t\t\t|%s",header[2]) ;
    printf("\r\t\t\t\t\t\t\t|%s",header[3]) ;
    printf("\r\t\t\t\t\t\t\t\t|%s",header[4]) ;
    printf("\r\t\t\t\t\t\t\t\t\t|%s",header[5]) ;
    printf("\r\t\t\t\t\t\t\t\t\t\t|%s",header[6]) ;
    printf("\r\t\t\t\t\t\t\t\t\t\t\t|%s",header[7]) ;
    printf("\r\t\t\t\t\t\t\t\t\t\t\t\t\t|%s",header[8]) ;
    printf("\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|%12s |",header[9]) ;
    printf("\n") ;
	printf("\t==============================================================================================================================\n");
    for(i = 0; i < numData ; i++){
        printf("\t%3d ", j) ; 
        printf("|%s",flightData[index[i]].from) ;
        printf("\r\t\t\t|%s",flightData[index[i]].to) ;
        printf("\r\t\t\t\t\t|%s",flightData[index[i]].date) ;
        printf("\r\t\t\t\t\t\t\t|%s",flightData[index[i]].depTime) ;
        printf("\r\t\t\t\t\t\t\t\t|%s",flightData[index[i]].arrivalTime) ;
        printf("\r\t\t\t\t\t\t\t\t\t|%s",flightData[index[i]].duration) ;
        printf("\r\t\t\t\t\t\t\t\t\t\t|%s",flightData[index[i]].flightNum) ;
        printf("\r\t\t\t\t\t\t\t\t\t\t\t|%s",flightData[index[i]].airline) ;
        printf("\r\t\t\t\t\t\t\t\t\t\t\t\t\t|%d",flightData[index[i]].availSeat) ;
        printf("\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|Rp.%10d|",flightData[index[i]].price) ;
        printf("\n") ;
        j++ ;
    }
    printf("\n") ;
}

void inputOptionFlight(structFlightData *flightData, int *numData,structAirline *listAirlines){
    // display airlines list
    int i, inputAirline, flagInput = 0, option ; 
    printf("Choose the corresponding airline's database : \n") ;
    for (i=0;i<numData[1];i++){
        printf("%d. %s\n", i+1, listAirlines[i].name) ;
    }
    printf("Option: ") ;
    scanf("%d", &inputAirline) ;
    //input
    while(!flagInput){
        flagInput = inputFlightDatabase(flightData,numData,listAirlines[inputAirline - 1].name) ;
        numData[0]++ ;
        printf("1. Continue Input Another Data, 0. Back\nOption : ") ;
        fflush(stdin) ;
        scanf("%d", &flagInput) ;
        flagInput = !flagInput ;
    }
}

int inputFlightDatabase(structFlightData *flightData, int *numData, char *airline) {
	
    int datePass = 0, boardingPass = 0, arrivalPass = 0, durationPass = 0 ;
	printf("test\n") ;
    strcpy((flightData[numData[0]]).airline,airline) ;
    printf("From\t\t\t\t\t: ");    
    fflush(stdin) ;
    scanf("%[^\n]s",(*(flightData + numData[0])).from) ;
    printf("To\t\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%[^\n]s",(*(flightData + numData[0])).to) ;
    while(get_date("Date (DD/MM/YYYY Format)\t\t: ",(*(flightData + numData[0])).date)) ;
    while(get_time("Departure Time (24 hr format HH:MM)\t: ",(*(flightData + numData[0])).depTime)) ;
    while(get_time("Arrival Time (24 hr format HH:MM) \t: ",(*(flightData + numData[0])).arrivalTime)) ;
    while(get_time("Duration (HH:MM Format)\t\t\t: ",(*(flightData + numData[0])).duration)) ;
    printf("Flight Number\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%[^\n]s",(*(flightData + numData[0])).flightNum) ;
    printf("Available Seat\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%d",&(*(flightData + numData[0])).availSeat) ;
    printf("Price/seat\t\t\t\t: ");
    fflush(stdin) ;
    scanf("%d",&(*(flightData + numData[0])).price) ;
    return 0;
}

void inputOptionAirline(structAirline *listAirlines, int *numData) {
	int i,option ,flagInput;
	
	printf("\nList of Airline : \n\n") ;
	for(i = 0; i < numData[1]; i ++){
		printf("%d. %s\n",i+1,listAirlines[i].name) ;
	}	
	printf("\n\n") ;
	flagInput = 0;
	while(!flagInput) {
		printf("New Airline : ") ;
		fflush(stdin) ;
		scanf("%[^\n]s", listAirlines[numData[1]].name) ;
		numData[1]++;
		while(1){
			printf("Enter another airline ? (0: No, 1: yes) : ") ;
			scanf("%d",&option) ;
			if(option == 0){
				flagInput = 1 ;
				printf("\n\n") ;
				break ;			
			} else if (option == 1){
				flagInput = 0;
				break ;
			} else {
				printf("Wrong input.\n") ;
				continue ;
			}
		}	
	}
    numAirlines = numData[1] ;	
}

void inputDatabase(structFlightData  *flightData,structAirline *listAirlines, int *numDatabase) {
	int flagInputData, option;
	flagInputData = 0;
    while(!flagInputData){
		system("cls") ;
		if (help)
			printf("\n <|0_0|>./ Here we can input new values for airlines and flight data\n you also can give voucher (if you want) to the buyer\n") ;
		print_frame("Input Database");
		printf("1. Input New Airline\n2. Input Flight Data\n3. Input Voucher Data\n0. Back\n\nOption : ") ;
		scanf("%d",&option) ;
		if(option == 1){
			system("cls") ;
			inputOptionAirline(listAirlines,numDatabase) ;
		} else if (option == 2){
			system("cls") ;
			inputOptionFlight(flightData,numDatabase,listAirlines) ;
		} else if (option == 3){
			system("cls") ;
			inputVoucher() ;
		}else if (option == 0) {
			flagInputData = 1 ;
			break;
		} else {
			printf("Wrong input.\n") ;
			continue ;
		}
	}
    system("cls") ;
}

void inputVoucher() {
	if(help)
		printf("\n <|0_0|>./ \n Minimum Total Price : the minimum total price to get a voucher for every transaction\n Cashback : the amount of cashback for every transaction\n Count : minimum transaction for getting the voucher\n") ;
	print_frame("Voucher Management") ;
	printf("Previous Cashback : \n\n");
	if(numVoucher == 0){
		printf("1. Minimum Total Price = -\n") ;
		printf("2. Cashback            = -\n") ;
		printf("3. Count               = -\n\n") ; //minimum transaction
	} else if (numVoucher > 0){
		printf("1. Minimum Total Price = %d\n",voucherDiscount[0].minimum) ;
		printf("2. Cashback            = %d\n",voucherDiscount[0].discount) ;
		printf("3. Count               = %d\n",voucherDiscount[0].count) ; //minimum transaction
	}
	printf("New Min Total Price (-1 if dont want give discount)\t : ");
	scanf("%d",&voucherDiscount[0].minimum);
	if(voucherDiscount[0].minimum == -1){
		voucherDiscount[0].discount = 0;
		voucherDiscount[0].count = 0;
	} else {
		printf("New Min Transaction\t\t\t\t\t : ");
		scanf("%d",&voucherDiscount[0].count) ;
		printf("New Discount Nominal\t\t\t\t\t : ");
		scanf("%d",&voucherDiscount[0].discount);
	}
	numVoucher = 1;
}

void editFlightDatabase(structFlightData  *flightData, int *numData, structAirline *listAirlines) {
	char *inputEditFN,*inputEditDate;
	int i,*index,sizeFN,sizeDate, *indexFN, *indexDate, editFlag = 0,inputDataFlag = 0, exitFlag = 0, inputExit, inputParam, anotherParameterFlag = 0,flagDate = 0,flagAirline = 0,userInput,flagTime = 0;
		
    while(!inputDataFlag)
    {
	    index = (int*)malloc(numData[0]*sizeof(int)) ;
		indexFN = (int *)malloc(MAXDATA*sizeof(int)) ;
		indexDate = (int *)malloc(MAXDATA*sizeof(int)) ;
		inputEditDate = (char *)malloc( 15 * sizeof(char)) ;
	    inputEditFN = (char *)malloc( 15 * sizeof(char)) ;
    	system("cls") ;
		printf("\nData Edited by Using Flight Number and Flight Date\n\n") ;
    	printf("Please Enter The Corresponding Flight Date and Flight Number\n\n") ;
    	fillIndex(index,numData[0]) ;
        displayFlightDatabase(flightData,numData[0],index) ;
    	printf("Enter Flight Number\t: ") ; //find data that to be edited by flight number and flight date
	    fflush(stdin) ;
	    scanf("%[^\n]s",inputEditFN) ;
	    printf("Enter Flight Date\t: ") ;
	    fflush(stdin) ;
	    scanf("%[^\n]s",inputEditDate) ;
		sizeFN = str_search(flightData, numData[0], 3 ,index, indexFN, inputEditFN) ;
		sizeDate = str_search(flightData, sizeFN, 2 ,indexFN, indexDate, inputEditDate) ;
        
        system("cls") ;
	    printf("Flight Number: %s\t\tFlight Date: %s\n\n",strupr(inputEditFN), inputEditDate) ;
        displayFlightDatabase(flightData,sizeDate,indexDate) ;
        
        if(sizeDate != 0){ //if data found
        	editFlag = 0;
        	exitFlag = 1;
		} else{ //if data not found 
			printf("\nData Not Found!\n");
//			exitFlag = 0;
			editFlag = 1;
		}
    	
    	while (!editFlag){
    		printf("\nEdit Data Paramater' : \n1. From\n2. To\n3. Flight Date\n4. Departure Time\n5. Arrival Time\n6. Duration\n7. Flight Number\n8. Airline\n9. Available Seat\n10. Price\n\n0. Back\nOption : ") ;
    		scanf("%d",&inputParam);
			if(inputParam == 1){
    			anotherParameterFlag = inputEdit("Enter New Departure Location\t: ", flightData[indexDate[0]].from) ;		
    			displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 2){
    			anotherParameterFlag = inputEdit("Enter New Arrival Location\t: ", flightData[indexDate[0]].to) ;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 3){
				while(get_date("Enter New Flight Date : ",flightData[indexDate[0]].date)) ;
    			anotherParameterFlag = 0;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 4){
				while(get_time("Enter New Departure Time : ",flightData[indexDate[0]].depTime) );
    			anotherParameterFlag = 0;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 5){
				while(get_time("Enter New Arrival Time: ",flightData[indexDate[0]].arrivalTime)) ;
    			anotherParameterFlag = 0;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 6){
				while(get_time("Enter New Duration : ",flightData[indexDate[0]].duration)) ;
    			anotherParameterFlag = 0;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 7){
				anotherParameterFlag = inputEdit("Enter New Flight Number: ", flightData[indexDate[0]].flightNum) ;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 8){
				printf("\n");
				for(i = 0; i < numData[1];i++){
        			printf("%d. %s\n", i+1, listAirlines[i]) ;
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
//				printf("%s",listAirlines[userInput-1]) ;
				strcpy((flightData[indexDate[0]]).airline,listAirlines[userInput-1].name);
    			anotherParameterFlag = 0;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 9){
				printf("Enter New Available Seat : ");
				fflush(stdin) ;
    			scanf("%d",&flightData[indexDate[0]].availSeat) ;
    			anotherParameterFlag = 0;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
			} else if (inputParam == 10){
				printf("Enter New Price : ") ;
				fflush(stdin) ;
    			scanf("%d",&flightData[indexDate[0]].price) ;
    			anotherParameterFlag = 0;
				displayFlightDatabase(flightData,sizeDate,indexDate) ;
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
				} else {
					anotherParameterFlag = 0;
					printf("Wrong Input.\n") ;
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
				free(index );
				free(indexFN);
				free(indexDate);
				free(inputEditDate);
			    free(inputEditFN) ;		
			} else if (inputExit == 0){
				exitFlag = 1;
				inputDataFlag = 1;
				system("cls");
			} else{
				printf("Wrong input\n") ;
			}
		}	
	}
	free(index );
	free(indexFN);
	free(indexDate);
	free(inputEditDate);
    free(inputEditFN) ;		
}

int inputEdit(char *message, char *input) { 
	printf("%s",message);
	fflush(stdin) ;
	scanf("%[^\n]s",input) ;
	return 0;
}

void deleteDatabase(structFlightData  *flightData,structAirline *listAirlines, int *numDatabase) {
	int flagDeleteData, option;
	flagDeleteData = 0;
    while(!flagDeleteData){
    	while(1){
    		system("cls") ;
			if (help)
				printf("\n <|0_0|>./ Here we can maintain available airlines on our database and flight data \n if you delete an airline the corresponding flight data on that airline will be deleted to\n") ;
			print_frame("Delete Database") ;
    		printf("1. Delete Airline\n2. Delete Flight Data\n0. Back\n\nOption : ") ;
    		scanf("%d",&option) ;
    		if(option == 1){
    			system("cls") ;
				deleteAirlineDatabase(flightData, listAirlines, numDatabase) ;
			} else if (option == 2){
				system("cls") ;
				deleteFlightDatabase(flightData, numDatabase) ;
			} else if (option == 0) {
				flagDeleteData = 1;
				break;
			} else {
				printf("Wrong input.\n") ;
				continue ;
			}
		}
	}
    system("cls") ;
}

void deleteFlightDatabase(structFlightData  *flightData, int *numData) {
	char *inputEditFN,*inputEditDate;
	int *index,sizeFN = 0,sizeDate = 0, *indexFN, *indexDate, editFlag = 0,inputDataFlag = 0, exitFlag = 0, inputExit, inputParam,i,j,flagDate = 0;
	
	index = (int*)malloc(numData[0]*sizeof(int)) ;
	indexFN = (int *)malloc(MAXDATA*sizeof(int)) ;
	indexDate = (int *)malloc(MAXDATA*sizeof(int)) ;
	inputEditDate = (char *)malloc( 15 * sizeof(char)) ;
    inputEditFN = (char *)malloc( 15 * sizeof(char)) ;

    while(!inputDataFlag)
    {
    	system("cls") ;
		print_frame("Delete Flight Database") ;
		printf("\nData Deleted by Using Flight Number and Flight Date\n\n") ;
    	printf("Please Enter The Corresponding Flight Date and Flight Number\n\n") ; //find data that to be deleted by flight number and flight date
    	fillIndex(index,numData[0]) ;
    	displayFlightDatabase(flightData,numData[0],index) ;
    	if(numData[0] != 0){
	    	printf("Enter Flight Number\t: ") ;
		    fflush(stdin) ;
		    scanf("%[^\n]s",inputEditFN) ;
		    fflush(stdin) ;
	//	    scanf("%[^\n]s",inputEditDate) ;
			while(get_date("Enter Flight Date\t: ",inputEditDate)) ;
	        sizeFN += str_search(flightData, numData[0], 3 ,index, indexFN, inputEditFN) ;
			sizeDate += str_search(flightData, sizeFN, 2 ,indexFN, indexDate, inputEditDate) ;
	        
	        system("cls") ;
		    printf("Flight Number: %s\t\tFlight Date: %s\n\n",strupr(inputEditFN), inputEditDate) ;
	        displayFlightDatabase(flightData,sizeDate,indexDate) ;
	        
	        if(sizeDate != 0){
	        	editFlag = 0;
	        	exitFlag = 1;
			} else{ //if input flight date and flight number data not found
				printf("\nData Not Found!\n");
				editFlag = 1;
			}
		} else {
			editFlag = 1;
		}

    	
    	while (!editFlag){
    		printf("\nAre you sure to delete data with flight number : %s , flight date : %s ?\n1. Yes\n0. No\nOption : ", inputEditFN, inputEditDate) ;
    		scanf("%d",&inputParam);
			if(inputParam == 1){
				deleteFlightData(flightData, numData, indexDate[0] ) ;
				editFlag = 1;
				exitFlag = 0;
    			displayFlightDatabase(flightData,numData[0],index) ;
    			printf("\n\tData with flight number : %s , flight date : %s has successfully deleted.\n\n", inputEditFN, inputEditDate) ; 
			} else if (inputParam == 0){
				editFlag = 1;
				exitFlag = 0;
			}else{
				printf("Wrong Input.\n");
			}
			
		}
		while(!exitFlag){
			if(numData[0] >  0){
				printf("\n1. Delete Another Data\n0. Back \nOption : ");
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
			} else {
				printf("All flight data have been deleted....\n") ;
				exitFlag = 1;
				inputDataFlag = 1;
				delay(1500) ;
			}
			

		}	
	}
	free(index );
	free(indexFN);
	free(indexDate);
	free(inputEditDate);
    free(inputEditFN) ;		
}

void deleteAirlineDatabase(structFlightData  *flightData, structAirline *listAirlines, int *numData) {
	
	int i,inputDataFlag = 0,option,sizeAirline, *indexAirline,*index,fixSize,editFlag = 0,exitFlag = 0, inputParam, inputExit ;
	char optionAirline[MAXSTR] ;
	
	index = (int*)malloc(numData[0]*sizeof(int)) ;
	indexAirline = (int *)malloc(MAXDATA*sizeof(int)) ;
	fillIndex(index,numData[0]) ;
	
	while(!inputDataFlag){
		numAirlines = numData[1] ;
		system("cls") ;
		print_frame("Delete Airline") ;
		sizeAirline = 0;
		displayFlightDatabase(flightData,numData[0],index) ;
        displayAirlineDatabase("List of Airline : \n\n", listAirlines) ;
        if(numData[1] != 0){
	        while(1){
		 		printf("\nAirline To Be Deleted (by index of list above): ") ;
				scanf("%d",&option) ;
				if((option < 1) || (option > numData[1])){
					printf("Wrong Input.\n") ;
					continue;
				} else {
					break;
				}
			}
			editFlag = 0;
		} else {
			editFlag = 1;
		}

		
		strcpy(optionAirline,listAirlines[option -1].name ) ;
//		printf("test\n") ;
		while (!editFlag){
    		printf("\nAre you sure to delete all %s 's flight data ?\n1. Yes\n0. No\nOption : ", listAirlines[option -1].name) ;
    		scanf("%d",&inputParam);
			if(inputParam == 1){
				sizeAirline = str_search(flightData, numData[0], 4 ,index, indexAirline, listAirlines[option -1].name) ;
				fixSize = sizeAirline ;
				printf("test\n") ;
				if(fixSize != 0){
				for(i = 0; i < fixSize;i++) {
						str_search(flightData, numData[0], 4 ,index, indexAirline, listAirlines[option -1].name) ;
						deleteFlightData(flightData, numData, indexAirline[0]) ;
					}
				} 
				for(i = option - 1; i < numData[1] - 1;i++) {	
					strcpy(listAirlines[i].name,listAirlines[i+1].name);
				}				
				numData[1]--;
				system("cls") ;
    			displayFlightDatabase(flightData,numData[0],index) ;
    			printf("\n\tAll %s 's flight data has successfully deleted.\n\n", optionAirline) ; 
    			numAirlines = numData[1];
    			editFlag = 1;
				exitFlag = 0;
			} else if (inputParam == 0){
				editFlag = 1;
				exitFlag = 0;
			}else{
				printf("Wrong Input.\n");
			}
		}
		while(!exitFlag){
			
			if(numData[1] > 0){
				printf("\n1. Delete Another Airline\n0. Back \nOption : ");
				scanf("%d",&inputExit);
				if(inputExit == 1)
				{
					exitFlag = 1;
					inputDataFlag = 0;	
				} else if (inputExit == 0){
					exitFlag = 1;
					inputDataFlag = 1;
					system("cls");
				} else{
					printf("Wrong input\n") ;
				}
			} else {
				printf("All airlines data have been deleted....\n") ;
				exitFlag = 1;
				inputDataFlag = 1;
				delay(1500) ;
			}
		}
	}
	free(index ) ;
	free(indexAirline) ;	
}

void deleteFlightData(structFlightData  *flightData, int *numData, int startIndex) {
	int i;
	
	for(i = startIndex ; i < numData[0] - 1;i++){
		strcpy(flightData[i].airline,flightData[i+1].airline); //data at specific column on index i filled with data from index i + 1 for i >= index of data that to be deleted && i < number of all data - 1
		strcpy(flightData[i].arrivalTime,flightData[i+1].arrivalTime);
		flightData[i].availSeat = flightData[i+1].availSeat;
		strcpy(flightData[i].date,flightData[i+1].date);
		strcpy(flightData[i].depTime,flightData[i+1].depTime);
		strcpy(flightData[i].duration,flightData[i+1].duration) ;
		strcpy(flightData[i].flightNum,flightData[i+1].flightNum) ;
		strcpy(flightData[i].from,flightData[i+1].from) ;
		flightData[i].price = flightData[i+1].price;
		strcpy(flightData[i].to,flightData[i+1].to) ;
		
	}
	numData[0]--; //decrease number of data 
}

void displayAirlineDatabase(char *message,structAirline *listAirlines){
    int i ;
    printf("%s", message) ;
	for(i = 0; i < numAirlines ;i++) {
		printf("%d. %s\n",i+1,listAirlines[i].name) ;
	}
}

void displayDatabase(structFlightData  *flightData, structAirline *listAirlines ,int *numData) {
	int flagDisplayData, option, *index;
	
	index = (int*)malloc(numData[0]*sizeof(int)) ;
	flagDisplayData = 0;
    while(!flagDisplayData){
		printf("1. Display All Flight Data\n2. Display All Airline Data\n3. Display All User Data\n\n0. Back\n\nOption : ") ;
		scanf("%d",&option) ;
		if(option == 1){
			system("cls") ;
	        fillIndex(index, numData[0]) ;
            displayFlightDatabase(flightData,numData[0],index) ;
		} else if (option == 2){
			system("cls") ;
			displayAirlineDatabase("List of Airline : \n\n",listAirlines) ;
			printf("\n\n\n") ;
		} else if (option == 3){
			displayUserDatabase() ;
			printf("\n\n\n") ;
		}else if (option == 0) {
			flagDisplayData = 1;
			break;
		} else {
			printf("Wrong input.\n") ;
			continue ;
		}
	}
    system("cls") ;
}

void displayUserDatabase() {
	system("cls") ;
	
	int i = 0, j=1;
    char header[5][15] = {"Name","Gender","Phone Number","Password","Voucher"} ;
    printf("\n\n");
//    printf("\t                  -Airport Database-                         \n\n") ;
    printf("\tNumber of User Data : %d\n\n",numUser) ;
    printf("\t============================================================================================") ;
    printf("\n\t No |%s",header[0]);
    printf("\r\t\t\t\t\t|%s",header[1]) ;
    printf("\r\t\t\t\t\t\t|%s",header[2]) ;
    printf("\r\t\t\t\t\t\t\t\t|%s",header[3]) ;
    printf("\r\t\t\t\t\t\t\t\t\t\t\t|%10s|",header[4]) ;
    printf("\n") ;
	printf("\t============================================================================================\n");
    for(i = 0; i < numUser ; i++){
        printf("\t%3d ", j) ; 
        printf("|%20s",listUser[i].name) ;
	    printf("\r\t\t\t\t\t|%2s",listUser[i].gender) ;
	    printf("\r\t\t\t\t\t\t|%15s",listUser[i].phoneNumber) ;
	    printf("\r\t\t\t\t\t\t\t\t|%20s",listUser[i].password) ;
	    printf("\r\t\t\t\t\t\t\t\t\t\t\t|%10d|",listUser[i].voucher) ;
        printf("\n") ;
        j++ ;
    }
    printf("\n") ;
}

char* get_airline(char *message, structAirline *listAirlines ){
    int option ;
    char *output ;
    output = (char*)malloc(MAXSTR*sizeof(char)) ;
    displayAirlineDatabase(message,listAirlines);
    printf("\nOption: ");
    fflush(stdin) ;
    // scanf("%[^\n]s", output) ;
    scanf("%d", &option) ;

    return listAirlines[option-1].name ;
}

void formatDate(char **dataDate, int *dateInt, int size) {
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
                        									
void formatTime(char **dataTime, int *temp, int size) {
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
									
void quickSort	(int *temp, int *index, int bawah, int atas, int mode) {
	int pivot;
	if(bawah < atas)
	{
		pivot = partition(temp,index,bawah,atas,mode); //get index of pivot after partition
		quickSort(temp,index,bawah,pivot-1,mode); //partition 1
		quickSort(temp,index,pivot+1,atas,mode); // partition 2
	}	
}   
											
void swapNumber	(int *dataNilai, int *dataIndex, int a , int b,int mode) {
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

int numSearch(int sizeArrow, int *indexArrow, int *indexTarget, int *temp, int min, int max) {
	int i,j = 0;
	
	for(i = 0; i < sizeArrow; i++){
		if((temp[i] >= min) && (temp[i] <= max)){ //find data in a column inside the database that includes in the range minimum value and  maximum value and return number of data
			indexTarget[j] = indexArrow[i]; //fill indexTarget array with an index that its value includes in the range minimum value and maximum value
			j++;
		}
	}
	return j;
	
}

int filterDepTime(structFlightData *flightData, int *indexArrow, int sizeArrow, int *indexTarget, int userOption) {
	
	int i, minVal, maxVal, *temp, sizeData;
	char **tempStr ;
	
	tempStr = (char **)malloc(MAXDATA*sizeof(char*));					//temporary variabel for storing some string value in 2D array
    for(i = 0; i < MAXDATA; i++)
    {
        tempStr[i] = (char*)malloc(MAXSTR*sizeof(char));
    }
    temp = (int *)malloc(sizeArrow*sizeof(int)) ;

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
//	printf("Here %d %d", minVal, maxVal) ;
	get_string_database(flightData, indexArrow , tempStr, sizeArrow, 5) ;							
    formatTime(tempStr,temp, sizeArrow) ; //tempStr (str) -> to integer
    quickSort(temp, indexArrow, 0 , sizeArrow - 1, 1) ;
    sizeData = numSearch(sizeArrow, indexArrow, indexTarget, temp, minVal, maxVal) ;	 
	return sizeData;                           
}

int filterPrice(structFlightData *flightData, int *indexArrow, int sizeArrow, int *indexTarget, int minVal, int maxVal) {	
	int sizeData, *temp ;
    temp = (int *)malloc(MAXDATA*sizeof(int)) ;
	
	get_integer_database(flightData, indexArrow, temp, sizeArrow ,1)	;
    quickSort(temp, indexArrow, 0 , sizeArrow - 1, 1) ;
    sizeData = numSearch(sizeArrow, indexArrow, indexTarget, temp,minVal, maxVal) ;
    return sizeData ;
}

void sortingFlightData(structFlightData *flightData, int *indexArrow, int sizeArrow, int mode, int dataType, int col) {
	//col = 5 -> depTime, col = 6 ->duration (dataType = String (0))
	//col = 0 -> price (dataType = Int (1))
	int *temp, i ;
	char **tempStr ;
	
	tempStr = (char **)malloc(sizeArrow*sizeof(char*));					//temporary variabel for storing some string value in 2D array
    for(i = 0; i < sizeArrow; i++)
    {
        tempStr[i] = (char*)malloc(MAXSTR*sizeof(char));
    }
    temp = (int *)malloc(sizeArrow*sizeof(int)) ;
    
	if(dataType == 0){
		if(col == 5){
			get_string_database(flightData, indexArrow , tempStr, sizeArrow, 5) ;								
		    formatTime(tempStr,temp, sizeArrow) ; //tempStr (str) -> to integer
		    quickSort(temp, indexArrow, 0 , sizeArrow - 1, mode) ;
		} else if (col == 6){
			get_string_database(flightData, indexArrow , tempStr, sizeArrow, 6) ;								
		    formatTime(tempStr,temp, sizeArrow) ; //tempStr (str) -> to integer
		    quickSort(temp, indexArrow, 0 , sizeArrow - 1, mode) ;
		}
	} else if (dataType == 1){
		if(col == 0) {
			get_integer_database(flightData, indexArrow, temp, sizeArrow ,1) ;
    		quickSort(temp, indexArrow, 0 , sizeArrow - 1, mode) ; //1 -> ascending 0-> 0->descending
		}
	}
}

void delay(int milliseconds){
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
