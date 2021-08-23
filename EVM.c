// Om Mengshetti
// PRN - 20070122091
// Batch - CS(B2)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
struct candidate{
    char name[50]; 
    char symbol[1];
    int votes;
};

//print the maximum
    int max(int a,int b)
    {
        return a>b? a:b;
    }

int main(){


    struct candidate c[10]; //Using "struct" allows us to combine data of different types together
    int n, n2, i, finish, voters=0;
    char vote[1], filename[10];
    time_t t;   // not a primitive datatype
    time(&t);

    printf("\nWelcome to the Council elections of 2021!\n");
    printf("\nThe starting time of election (date and time): %s", ctime(&t)); //To mark the time at which the election started

    printf("\n====================Add candidates====================\n");

    do{
        printf("\nEnter the number of candidates (Maximum 10): "); 
        scanf("%d", &n);
    }while(n<2 || n>10); //minimum 2 candidates require for voting 

    n2 = n;

    //To store the name of the candidate.
    for(i=0; i<n; i++){
        printf("\n**** Enter Data of Candidate %d *****\n",i+1);
        
        printf("\nName of the candidate : ");
        scanf("%s", c[i].name); 
        
        printf("\nSymbol of the candidate : ");
        scanf("%s", c[i].symbol); 
        c[i].votes =0;
    }

    do{
        printf("\n====================Press the symbol to cast vote====================\n");

        for(i=0; i<n; i++){
            printf("%s ( %s )\n", c[i].name, c[i].symbol);
        }
        vote[0]= getch(); //Using getch() pauses the Output Console until a key is pressed. Next print statement is printed only after a key(symbol) is pressed.

        for(i=0; i<n2; i++){

            if(c[i].symbol[0] == vote[0])
            {
                c[i].votes = c[i].votes+1; 
                printf("Thank You! Your vote has been casted to\n");
                printf("%s ( %s)", c[i].name, c[i].symbol);
            }
        }

        voters++; //Incrementing voter count after every vote is casted.

        printf("\nFinish Voting? (Enter 1 for yes or 2 for no) : ");
        scanf("%d", &finish);

        if(finish==1 || voters==100){
            finish==1;
        }

        else{ 
            finish==2;
        }
    }while(finish==2); //Using do-while loop to process the voting stratagem.


    printf("\n====================Result of Voting====================\n",1);

    for (int i=0; i<n; i++){

        //File name for storing Candidate details.
        sprintf(filename, "c%d.txt", i+1); //Using sprintf to print string.
        FILE * fPtr;
    

        // If above operation is falled print error and extt
        if(fPtr == NULL){
            // File not created hence exit 
            printf("Unable to create file.\n"); 
            exit(EXIT_FAILURE);
        }

        // Writing data in the file

        fPtr= fopen(filename, "w");
        printf("Candidate : %s", c[i].name);
        fprintf(fPtr, "%s\n", c[i].name);

        printf("\t Symbol: %s", c[i].symbol); 
        fprintf(fPtr, "%s\n", c[i].symbol);

        printf("\t Votes: %d\n", c[i].votes);
        fprintf(fPtr, "%d\n", c[i].votes);

        // Closing the file
        fclose(fPtr);   
    }
    
    //finding the max votes
    int maxi=-1;
    char candidate[10];
    for(int j=0;j<n;j++){
        if(maxi<c[j].votes)
            {
                maxi=c[j].votes;
                strcpy(candidate,c[j].name);
            }
    }
   
    printf("\nCongratulations, %s has won with %d votes!!\n",candidate,maxi);
    
    printf("\n====================End of Elections====================\n\n");

    

    FILE *fp;
    fp = fopen("Results.txt","w");
    //Processing of the file
    fprintf(fp,"%s","====================Result of voting====================\n");
    fprintf(fp,"%s has won with %d votes!\n",candidate,maxi);
    fprintf(fp,"You hereby solemnly pledge to devote yourself to the service and well-being of the people.\n");
    fclose(fp);
    
    // char str[20];
    // printf("Dear %s write your oath\n",candidate);
    // while ( strlen ( gets( str ) ) > 0 )
    // {
    //     // writing in the file
    //     fputs(str, fp) ;   
    //     fputs("\n", fp) ;
    // }
    // int k=0;
    // printf("%s", "If you want to exit press 1");
    // while(str[k]!="\0")
    // {
    //     // scanf("%s",str);
    //     // if(str[k]==1){
    //     //     break;
    //     // }
    //     // k++;
    //     // fprintf(fp,"%s",str);
    // } 
    // fprintf(fp, "%s",str);
  

    // fp = fopen("Oath.txt","w");
    // fprintf(fp,"%s",str);
    //End of processing 
    // fclose(fp);

    return 0;
}