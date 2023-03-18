#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#define MAX 5
#define MAXSIZE 5
#define MAXLENGTH 50

struct Stack {
    int top;
    char items[MAXSIZE][MAXLENGTH];
};

void initialisasi(struct Stack *stack) {
    (*stack).top = -1;
}

int is_empty(struct Stack *stack) {
    return (*stack).top == -1;
}

int is_full(struct Stack *stack) {
    return (*stack).top == MAXSIZE - 1;
}

void push(struct Stack *stack) {
    system("cls");
    char input[MAXLENGTH];
    printf("\n\n========================================================================================================================\n");
    printf("                                                 ++ PUSH STACK ++\n");
    printf("========================================================================================================================\n\n\n");

    if (is_full(stack)) {
        printf("Data is full !\n");
        system("pause");
        return;
    }
    printf("Enter data to be inputted: ");
    scanf(" %[^\n]s", input);
    if (strlen(input) > MAXLENGTH) {
        printf("The input is too long.\n");
        return;
    }
    (*stack).top++;
    strcpy((*stack).items[(*stack).top], input);
    printf("Data '%s' successfully input.\n", input);
    system("pause");
}

void pop(struct Stack *stack) {
    system("cls");
    printf("\n\n========================================================================================================================\n");
    printf("                                                 ++ POP STACK ++\n");
    printf("========================================================================================================================\n\n\n");
    if (is_empty(stack)) {
        printf("Data is still empty !\n");
        system("pause");
        return;
    }
    char *dele = (*stack).items[(*stack).top];
    (*stack).top--;
    printf("The data %s has been deleted.\n", dele);
    system("pause");
}

void print(struct Stack *stack) {
    system("cls");
    printf("\n\n========================================================================================================================\n");
    printf("                                                  ++ PRINT STACK++\n");
    printf("========================================================================================================================\n\n\n");

    if (is_empty(stack)) {
        printf("Data is empty !\n");
        system("pause");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("Data stack to %d = %s\n", i, stack->items[i]);
    }
    system("pause");
}

void hapus(struct Stack *stack) {
    system("cls");
    printf("\n\n========================================================================================================================\n");
    printf("                                               ++ DELETE ALL DATA ++\n");
    printf("========================================================================================================================\n\n\n");

    if (is_empty(stack)) {
        printf("Data is still empty !\n");
        system("pause");
    } else {
        (*stack).top = -1;
        printf("Data has been deleted.\n");
        system("pause");
    }
}

void menu() {
    char choice;
    struct Stack stack;
    initialisasi(&stack);
    do {
        system("cls");
        cover2();
        gotoxy(10,13);printf("Menu Stack");
        gotoxy(32,2);printf(" _____ _______  __  ____ _   _");
        gotoxy(32,3);printf("/ ____)_    __|/  |/  __) | / /");
        gotoxy(32,4);printf("\\___ \\  |  |  / d |  |  | |/ /");
        gotoxy(32,5);printf("  __| | |  | / _  |  |__|  _ \\");
        gotoxy(32,6);printf("(____.  |__|/_/ |_|\\____)_| \\_\\");
        gotoxy(49,8);printf("== Main Menu Stack ==");
        gotoxy(3,15);puts("1. Push Stack");
        gotoxy(3,16);puts("2. Pop Stack");
        gotoxy(3,17);puts("3. Print Stack");
        gotoxy(3,18);puts("4. Delete Stack");
        gotoxy(3,19);puts("5. Return Main Menu");
        gotoxy(3,20);printf("Pilihan: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                push(&stack);
                break;
            case '2':
                pop(&stack);
                break;
            case '3':
                print(&stack);
                break;
            case '4':
                hapus(&stack);
                break;
            case '5':
                main();
                break;
            default:
                menu();
        }
    } while (choice != '5');
}

struct Queue {
    int head;
    int tail;
    int data[MAX];
}queue;

void initialise() {
    queue.head=queue.tail = -1;
}

int is_emptyq() {
    if(queue.tail == -1){
        return 1;
    }else{
        return 0;
    }
}

int is_fullq() {
    if(queue.tail == MAX -1){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(int data) {
    int input;
    if(is_emptyq()==1){
        queue.head=queue.tail = 0;
        queue.data[queue.tail] = data;
        printf("\nData '%d' successfully input\n",queue.data[queue.tail]);
    }else{
        if(is_fullq() == 0){
            queue.tail++;
            queue.data[queue.tail] = data;
            printf("\nData '%d' successfully input\n",queue.data[queue.tail]);
        }
    }
}

int dequeue() {
    system("cls");
    printf("\n\n========================================================================================================================\n");
    printf("                                                 ++ DEQUEUE QUEUE ++\n");
    printf("========================================================================================================================\n\n\n");
    if(is_emptyq ()){
        printf("Data is still empty !\n");
    }else{
        int i;
        int e = queue.data[queue.head];
        printf("The data %d has been deleted.\n",queue.data[queue.head]);
        for(i=queue.head;i<=queue.tail-1;i++){
            queue.data[i] = queue.data[i+1];
        }
        queue.tail--;
    }
    system ("pause");
    return;
}

void print1() {
    system("cls");
    printf("\n\n========================================================================================================================\n");
    printf("                                                  ++ PRINT QUEUE ++\n");
    printf("========================================================================================================================\n\n\n");
    if(is_emptyq() == 0){
        for(int i=queue.head;i<=queue.tail;i++){
                printf("Data to %d = %d \n",i, queue.data[i]);
            }
        }else{
            if (queue.tail == -1) {
                printf("No data in queue !\n");
            }else{
                printf("Data is still empty !\n");
            }
    }
    system("pause");
}

void hapus1() {
    system("cls");
    printf("\n\n========================================================================================================================\n");
    printf("                                               ++ DELETE ALL DATA ++\n");
    printf("========================================================================================================================\n\n\n");
    if(is_emptyq()){
        printf("Data is still empty !\n");
    }else{
    queue.head=queue.tail=-1;
    printf("Data has been deleted !\n");}
    system("pause");
}

void menuqueue(){
    char pil;
    int dt;
    initialise();
    do {
        system("cls");
        cover2();
        gotoxy(10,13);printf("Menu Queue");
        gotoxy(32,2);printf(" _______    __________     _ ________");
        gotoxy(32,3);printf("|  _  | |  | | _____/ |   | |  _____/");
        gotoxy(32,4);printf("| |./ | |  | |  __| | |   | |  ___|");
        gotoxy(32,5);printf("|____ \\ |__| | |___ | |___| | |____");
        gotoxy(32,6);printf("     \\_\\____/|_____| \\_____/|______|");
        gotoxy(49,8);printf("== Main Menu Queue ==");
        gotoxy(3,15);puts("1. Enqueue Int");
        gotoxy(3,16);puts("2. DequeueInt");
        gotoxy(3,17);puts("3. Print Queue");
        gotoxy(3,18);puts("4. Delete Stack");
        gotoxy(3,19);puts("5. Return Main Menu");
        gotoxy(3,20);printf("Pilihan: ");
        scanf(" %c", &pil);
        switch (pil) {
            case '1':
                system("cls");
                printf("\n\n========================================================================================================================\n");
                printf("                                                 ++ ENQUEUE QUEUE ++\n");
                printf("========================================================================================================================\n\n\n");
                if(is_fullq() !=1){
                    printf("Enter data to be inputted = ");
                    scanf("%d", &dt);
                    enqueue(dt);
                }else{
                    printf("Data is full !\n");
                }
                system("pause");
                break;
            case '2':
                dequeue();
                break;
            case '3':
                print1();
                break;
            case '4':
                hapus1();
                break;
            case '5':
                main();
                break;
            default:
                menu();
        }
    } while (pil != '5');
}

void cover2(){
    int i,l;l=119;
    system("COLOR 0B");
    gotoxy(32,2);printf(" _            ________     ____  ___  ___   ___ ______");
    gotoxy(32,3);printf("\\  \\  __    /|  ____/ |   /  __)/   \\|   \\ /   | ____/");
    gotoxy(32,4);printf(" \\  \\/  \\  / |  __| | |  |  /  /  <  | |\\ V /| |  __|  ");
    gotoxy(32,5);printf("  \\   /\\ \\/ /| |___ | |__|_ \\_ \\  V  | | \\_/ | | |____");
    gotoxy(32,6);printf("   \\_/  \\__/ |_____/|_____/____)\\___/|_|     |_|_____/");
    gotoxy(49,8);printf("== to THIS PROGRAM ==");
    for (i=0;i<=118;i++){
        gotoxy(i,0);
        printf("");
    }//baris atas
    for (i=0;i<=118;i++){
        gotoxy(i,10);
        printf("%c",219);
    }//baris tengah
    for (i=0;i<=118;i++){
        gotoxy(i,0);
        printf("%c",219);
    }
    for (i=0;i<=29;i++){
        gotoxy(0,i);
        printf("%c",219);
    }//baris kiri
    for (i=10;i<=29;i++){
        gotoxy(29,i);
        printf("%c",219);
    }//baris kiri
    for (i=0;i<=29;i++){
        gotoxy(l,i);
        printf("%c",219);
    }//baris kanan
    for (i=0;i<=30;i++){
        gotoxy(l,i);
        printf("");
    }
    for (i=0;i<=119;i++){
        gotoxy(i,30);
        printf("%c",219);
    }//baris bawah
    for (i=12;i<=22;i++){
        gotoxy(1,i);
        printf("%c",186);
    }//garis || ke bawah
    for (i=11;i<=22;i++){
        gotoxy(28,i);
        printf("%c",186);
    }//garis || ke bawah
    for (i=1;i<=28;i++){
        gotoxy(i,11);
        printf("%c",186);
    }//baris || || || || || ke kanan
    for (i=1;i<=28;i++){
        gotoxy(i,22);
        printf("%c",186);
    }
    for (i=0;i<=29;i++){
        gotoxy(i,23);
        printf("%c",219);
        gotoxy(5,26);
        printf("CREATED BY :");
        gotoxy(5,27);
        printf("Raraheree_672022028");
    }
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void arrowhere (int realposition,int arrowposition){
    if(realposition == arrowposition){
        printf("==>");
    }else{
        printf("   ");
    }
}


int main(){
    system("cls");
    system("COLOR 0b");
    cover2();
    int position = 1;
    int keyPressed = 0;
    int maxoption = 3;
    gotoxy(7,13);printf("Stack and Queue");
    gotoxy(35,21);printf("Queue adalah struktur data yang digunakan untuk menyimpan elemen dalam urutan");
    gotoxy(35,22);printf("tertentu dan memungkinkan operasi untuk menambahkan elemen ke ujung belakang ");
    gotoxy(35,23);printf("queue, dan menghapus elemen dari ujung depan queue. Queue dapat digunakan dlm");
    gotoxy(35,24);printf("berbagai aplikasi, seperti salah satu contohnya yaitu antrian permintaan. Dlm");
    gotoxy(35,25);printf("struktur data queue, elemen pertama yang dimasukkan ke dalam queue adalh yang");
    gotoxy(35,26);printf("pertama pula yang keluar dari queue. Konsep ini dikenal sebagai First-In-Firs");
    gotoxy(35,27);printf("t-Out (FIFO). ");
    gotoxy(35,13);printf("Stack adalah struktur data yang digunakan untuk menyimpan elemen dalam urutan");
    gotoxy(35,14);printf("tertentu, di mana operasi yang terakhir dilakukan adalah operasi pertama yang");
    gotoxy(35,15);printf("harus diselesaikan. Konsep ini dikenal sebagai Last-In-First-Out (LIFO). Sbgi");
    gotoxy(35,16);printf("contoh, jika kita menambahkan elemen A, B, dan C ke dalam sebuah stack secara");
    gotoxy(35,17);printf("berurutan, maka elemen C akan menjadi elemen pertama yang keluar  dari stack ");
    gotoxy(35,18);printf("ketika kita melakukan operasi pop.Stack digunakan dalam berbagai aplikasi,spt");
    gotoxy(35,19);printf("dalam pengolahan ekspresi matematika atau logika, pemanggilan fungsi dalam  p");
    gotoxy(35,20);printf("emrograman, dan penyimpanan state dalam sistem operasi.");
    while(keyPressed != 13){
        gotoxy(3,16);
        arrowhere(1,position); printf("  1. Stack String");
        gotoxy(3,17);
        arrowhere(2,position); printf("  2. Queue Integer");
        gotoxy(3,18);
        arrowhere(3,position); printf("  3. Exit Program");
        keyPressed = getch();
        if(keyPressed == 80 && position !=3){
            position++;
        }else if(keyPressed == 72 && position !=1){
            position--;
        }else{
            position = position;
        }
    }
    printf(" Select Option ,%d \n",position);
    int x = position;
    int a;
    int b;
    switch (x){
        case 1:
		    menu();
		    main();
            break;
		case 2:
            menuqueue();
		    main();
			break;
		case 3:
			system("cls");
            printf("Thank You! ByeBye");
            exit(0);
			break;
        default:
            main();
    }
}
