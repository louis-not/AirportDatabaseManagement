/**
 *      Proyek-1 Algoritma dan Pemograman
 *      1. Louis M. D. Wijaya / 1906379296
 *      2. Wilson A           / 190637
 * 
 *      Airport Database Management :
 *		(string database)
 *		|From		|To			|Date		|Time		|Flight Number |Airline		|Available Seat |
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

int main (){
    int menu, flagMenu = 0, i , trial = 3, flagAdmin = 0 ;
    char *password = "admin123", *passwordInput;
    passwordInput= (char *)malloc( 15 *sizeof(char)) ;
    do {
        printf("======================= Airport Database Management ======================\n\n");
        printf("1. Admin Menu\n2. User Menu\n\n0. Exit\n\nOption :") ;
        scanf("%d", &menu) ;
        if(menu==1){
           // Admin menu
           system("cls") ;
           for (i=0;i<trial;i++){
           		if (flagAdmin) break ;
                printf("Input Password: ") ;
                fflush(stdin) ;
                scanf("%[^\n]s", passwordInput) ;
                if (!strcmp(passwordInput,password)){
                    // insert admin function



                    printf("Pass\n") ;
                } else {
                    printf("Wrong Password (trial left: %d)\n\n", trial-i-1) ;
                }
           }
           if (trial == i) 
                flagMenu = 1;
        } else if (menu==2){
            // User menu
            
             
            
        } else if (menu==0){
            flagMenu=1;
        } else {
            printf("Wrong Input :( \n") ;
            system("cls") ;
        }

    } while (!flagMenu) ;
    printf("Good Bye! :D\n") ;
    return 0 ;
}
