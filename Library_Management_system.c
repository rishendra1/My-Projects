//ASSIGNMENT – 3 Name : Rishendra Ruppa ID – AP24110011858 
#include <stdio.h> 
#include <string.h> 
// Let us define a struct representing book 
struct Book{ 
    char title[100]; 
    //Title of book 
    char author[100]; 
    //Autnor of book 
    char isbn[20]; 
    //ISBN value 
    char genre[50]; 
    //Genre of book 
    float price; 
    //Pice of book 
    int publication_Year; 
    //Publication year of the book 
    int availability;  
    // 1 for available, 0 for borrowed 
}; 
//Function to take input of details of books 
//This function takes the details of books as the input 
void input(struct Book b[], int n) { 
    for (int i = 0; i < n; i++) { 
        printf("\nEnter details for book %d: \n", i + 1); 
        printf("Title: "); 
        getchar(); 
        fgets(b[i].title,100,stdin); 
        strtok(b[i].title,"\n"); 
//strtok() is a function that splits string into multiple pieces   
        printf("Author: "); 
        fgets(b[i].author,100,stdin); 
        strtok(b[i].author,"\n"); 
        printf("ISBN: "); 
        fgets(b[i].isbn,20,stdin); 
        strtok(b[i].isbn,"\n"); 
        printf("Genre: "); 
        fgets(b[i].genre,50,stdin); 
        strtok(b[i].genre,"\n"); 
        printf("Price: "); 
        scanf("%f", &b[i].price); 
        printf("Publication Year: "); 
        scanf("%d", &b[i].publication_Year); 
        printf("Availability(1 for available,0 for borrowed):"); 
        scanf("%d", &b[i].availability); 
    } 
} 
//Function to display the details of books 
//This is the function that prints the details of books 
void display(struct Book b[], int n) { 
    printf("\nBook Details:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("\nBook %d:\n", i + 1); 
        printf("Title: %s\n", b[i].title); 
        printf("Author: %s\n", b[i].author); 
        printf("ISBN: %s\n", b[i].isbn); 
        printf("Genre: %s\n", b[i].genre); 
        printf("Price: RS %.2f\n", b[i].price); 
        printf("Publication Year: %d\n", b[i].publication_Year); 
        printf("Availability: %s\n", b[i].availability ? "Available" : "Borrowed"); 
    } 
} 
// Function to calculate the Average price 
//This function helps in calculating the avg price of the book 
float Average_Price(struct Book b[], int n) { 
    float totalPrice = 0; 
    for (int i = 0; i < n; i++) { 
        totalPrice += b[i].price; 
    } 
    return totalPrice / n; 
} 
//Function to print Old and new books 
//This function prints the old and new books according to their publishing year 
void Old_And_New_Books(struct Book b[], int n) { 
    int old = b[0].publication_Year; 
    int new = b[0].publication_Year; 
    char oldest[100], newest[100]; 
    strcpy(oldest, b[0].title); 
    strcpy(newest, b[0].title); 
 
    for (int i = 1; i < n; i++) { 
        if (b[i].publication_Year < old) { 
            old = b[i].publication_Year; 
            strcpy(oldest, b[i].title); 
        } 
        if (b[i].publication_Year > new) { 
            new = b[i].publication_Year; 
            strcpy(newest, b[i].title); 
        } 
    } 
    printf("\nOldest Book: %s (%d)\n", oldest, old); 
    printf("Newest Book: %s (%d)\n", newest, new); 
} 
//Function to count available books 
void count_Available_Books(struct Book b[], int n) { 
    int count = 0; 
    for (int i = 0; i < n; i++) { 
        if (b[i].availability) { 
            count++; 
        } 
    } 
    printf("\nNumber of Available Books: %d\n", count); 
} 
// Function to print expensive books 
//It prints the book which is more expensive 
void Expensive_Book(struct Book b[], int n) { 
    float max_price = b[0].price; 
    char expensive[100]; 
    strcpy(expensive, b[0].title); 
 
    for (int i = 1; i < n; i++) { 
        if (b[i].price > max_price) { 
            max_price = b[i].price; 
            strcpy(expensive, b[i].title); 
        } 
    } 
    printf("\nMost expensive Book: %s (Rs. %.2f)\n", expensive, max_price); 
} 
//Function to print the books whose price is above the avg price 
void Books_Above_Avg_Price(struct Book b[], int n, float averagePrice) { 
    printf("\nBooks with Price Above Average:\n"); 
    for (int i = 0; i < n; i++) { 
        if (b[i].price > averagePrice) { 
            printf("%s(Rs %.2f)\n", b[i].title, b[i].price); 
        } 
    } 
} 
int main() { 
int n; 
printf("Enter the number of books: "); 
scanf("%d", &n); 
struct Book b[n]; 
input(b, n); 
display(b, n); 
f
loat averagePrice = Average_Price(b, n); 
printf("\nAverage Price of Books: RS %.2f\n", averagePrice); 
Old_And_New_Books(b, n); 
count_Available_Books(b, n); 
Expensive_Book(b, n); 
Books_Above_Avg_Price(b, n, averagePrice); 
return 0; 
} 
