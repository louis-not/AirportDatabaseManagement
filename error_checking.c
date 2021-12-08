# include <stdio.h>
# include <stdlib.h>

int get_date(char *message,char *date){
    printf("%s", message) ;
    fflush(stdin); 
    scanf("%[^\n]s", date);
    int i=0 ;
    for(i =0; i<10 ; i++){
		if ( (i==2)||(i==5) )
            continue ;
        else {
            if(!isdigit(date[i]))
                return 1;
        } 
    }
    return 0 ;
}

int get_time(char *message, char *check){
    printf("%s", message) ;
    fflush(stdin);
    scanf("%[^\n]s", check);
	int i=0; 
	char temp[1];
	for(i=0;i<5;i++){
		temp[0] = check[i];
		if (i==2)
			continue ;
		else {
			if(!isdigit(check[i])) // check if a char is a digit or not
				return 1;
		}
		if(i == 0){
			if((atoi(temp)< 0) || (atoi(temp)> 2)){
				return 1;
			} else if(atoi(temp) == 2){               //check if index 0 of time is 2, then index 1 must be smaller than 4
				temp[0] = check[1];
				if((atoi(temp) < 0) || (atoi(temp)> 3)){
					return 1;
				}
			}
		} 
		if(i == 3){									//index 3 of time must be smaller than 6
			if((atoi(temp) < 0) || (atoi(temp) > 5)){
				return 1;
			}
		}
	}
	return 0 ;   
}

void get_string(char **string){
    fflush(stdin);
    scanf("%[^\n]s", string); 
}