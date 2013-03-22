#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main_menu (void);// main menu function prototype
void pick_num (int* ,int*);// picking numbers function prototype
void print_num (int*, int*);//printing numbers to screen function prototype
void sort_num (int* ,int*); //sort the selected numbers into ascending order prototype
void check_num(int*, int *);// checking numbers function prototype
void frequency(int*, int *);//Finding the frequency of numbers picked prototypeprototype


main()
{
    
    main_menu();        // calling the main menu function
    
}

void main_menu(void)    //this is the main menu function
{
    
    int choice,bonus= 0, counter,end;
    int *ptr;
    int picked[6];
    
    ptr = picked;       // Assigns the address of the array to the pointer ptr
    
    printf("~~~~~~~~~~Welcome to the lotto game, this is the main menu~~~~~~~~~~\n");

    do      // Main do while statement with the menu inside, will complete this once unless exited early
    {
        printf("Option 1: Choose your lotto numbers\n");
        printf("Option 2: Print your chosen numbers + the bonus on screen\n");
        printf("Option 3: Sort the numbers you have chosen in ascending order\n");
        printf("Option 4: Check if your numbers are the winning numbers\n");
        printf("Option 5: See how many times you have picked each number\n");
        printf("Option 6: Play the game again\n");
        printf("Option 7: End the game\n\n");
        printf("Please enter in a number corresponding to the option\n");
        printf("You must choose your numbers before continuing with another option\n\n");
        
        scanf("%d",&choice);
        
        if (choice == 1)
        {
            printf("You have chosen to enter your lotto numbers\n");
            counter = 1;
            pick_num(ptr , &bonus);     // Calls the function pick_num where the user can enter in their lotto numbers
        }
        if(counter ==1)
        {
            if (choice == 2)
            {
                printf("You have chosen to print your selected numbers\n");
                print_num(ptr, &bonus);     // Calls the function print_num which will display the selected numbers on screen
            }
            
            if (choice == 3)
            {
                printf("You have chosen to sort your numbers in order of smallest to largest\n");
                sort_num (ptr,&bonus);      //Calls the function sort_num which sorts the entered numbers in ascending order and then prints to screen
            }
            
            if (choice == 4)
            {
                printf("You have chosen to check your numbers against the winning numbers\n");
                check_num(picked,&bonus);   //Calls the function check_num where the selected numbers are checked against the winning numbers
            }
              if (choice == 5)
            {
                printf("You have chosen to see the number frequency selection results\n");
                frequency(ptr, &bonus);
            }
            if(choice == 6)
            {
                printf("You have chosen to play the game again\n");
                system("cls");
            }
        }
        else
        {
            printf("You must chose to enter your numbers first before choosing another option\n\n");
            // Basic error checking if a selection from the menu is not pressed
        }
        if(choice == 7)        
        {
            printf("You have chosen to end the game\n\n");
            printf("Press any key to close window\n");
            end = 1;        // This will end the do while loop if executed, also ending the program
            getchar();
            getchar();
        }
    }   
    while (end!=1);
}

void pick_num (int *ptr, int *bonus_ptr)    // This is the picking numbers function, the address of the array and the bonus variable has been passed to it
{  
    int i,j;
    
    printf("You must enter 6 numbers , all between 1 and 45\n\n");
    
    for(i=0;i<6;i++)
    {    
        scanf("%d",&(*(ptr + i)));
    }
    
    for(i=0;i<6;i++)
    {
        if(*(ptr + i) < 1 || *(ptr + i) > 42)
        {
            printf(" Number %d is invalid, Please enter a number between 1 and 42\n\n",i);
            scanf("%d",&(*(ptr +i)));
        }
    }
    
    for(i=0; i<6; i++)
    {
        for(j=(i+1); j<6; j++)
        {
            if(*(ptr + i) ==  *(ptr + j))
            {
                printf(" Number %d is invalid, Please enter a number not entered before\n\n",i);
                scanf("%d",&(*(ptr +i)));
            }
        }
    }
    
    printf("You must now enter your bonus number \n\n");
    printf("Enter a number between 1 and 42 and that hasn't been picked before\n\n");
    
    scanf("%d", &(*(bonus_ptr)));
    
    for(i=0;i<6;i++)
    {
        if(*(bonus_ptr) < 1 || *(bonus_ptr) > 42)
        {
            printf("You entered an invalid number, Please enter a number between 1 and 42\n\n");
            scanf("%d", &bonus_ptr);
        }
    }
    
    for(i=0;i<6;i++)
    { 
        if(*(bonus_ptr) == *(ptr + i))
        {
            printf("You entered an invalid number, Please enter a number between 1 and 42\n\n");
            scanf("%d", &bonus_ptr);
        }
    }
    system ("cls");
}

void check_num (int * ptr, int *bonus_ptr)

{
    int i, j, match = 0, bonus_match = 0;
    int LOTTO [6] = {1,3,5,7,9,11};
    int win_bonus = 42;
    
    system("cls");
    
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(*(ptr +i) == *(LOTTO + j))
            {
                match++;
            }
        }
    }
    
    if ( *(bonus_ptr) == win_bonus)
    {
        bonus_match ++;
    }
    
    if(match == 6 && bonus_match == 1)
    {
        printf("Congratulations!!You've matched all 7 numbers and hit the JACKPOT!!\n\n");
    }
    else if (match == 5 && bonus_match == 1)
    {
        printf("Well done you matched 5 plus the bonus number! just one off!!\n\n");
    }
    else if (match == 5)
    {
        printf("You have matched 5 numbers! Holidays paid for boo yeah\n\n");
    }
    else if(match == 4 && bonus_match == 1)
    {
        printf("You matched 4 and the bonus number! Night out paid for! SESSION!\n\n");
    }
    else if (match == 4)
    {
        printf("You matched 4 numbers well done, petrol tank full to the brim!\n\n");
    }
    else if(match == 3 && bonus_match == 1)
    {
        printf("Congratulations, you have won a scratch card.. Wooo\n\n");
    }
    else
    {
        printf("Unlucky...You won naaahtin\n\n");
    }
}

void print_num(int *ptr, int *bonus_ptr)
{
    system("cls");
    int i;
    for(i=1;i<=6;i++)
    {
        printf("Number %d that you have chosen is %d\n\n",i,*(ptr + (i-1)));
    }
    
    printf("The bonus number you have chosen is %d\n\n", *(bonus_ptr));
    
    // printf to show bonus number goes here
}

void sort_num(int *ptr, int *bonus_ptr)
{
    system("cls");
    
    int i,j, temp;
    for (i = 0 ; i < 6-1 ;i++)
    { 
        for (j = 0 ; j < 6-1;j++) 
        {
            
            if( *(ptr + j) > *(ptr +(j+1)) )
            {
                temp = *(ptr + j);
                
                *(ptr + j) =  *(ptr + (j+1));
                
                *(ptr  +(j+1)) = temp;
            }
        }   
    }
    
    printf("The numbers have now been sorted in ascending order\n\n");
    for(i=1;i<7;i++)
    {
        printf("Number %d is %d\n\n",i, *(ptr + i-1));
    }
    printf("The bonus number you have chosen is %d\n\n", *(bonus_ptr));
}

void frequency(int*ptr, int *bonus_ptr)
{
    int frequency[42] = {0};
    int i,j;
    
    for(i=0;i<6;i++)
    {
        for(j = 0;j<42;j++)
        {
            if(*(ptr + i) == j)
            {
                *(frequency + j) = *(frequency + j) + 1 ;
            }
        }
    }
    
    for(j = 0;j<42;j++)
    {
        if (*(bonus_ptr) == j )
        {
            *(frequency + j) = *(frequency + j) + 1 ;
        }
    }
    
    for(i=0;i<42;i++)
    {   
        if ( *(frequency + i) >0)
        {
            printf("The number %d has been selected %d times\n\n", i, *(frequency + i));
        }
    }
}    
