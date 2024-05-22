#include <stdio.h>
#define MAXLINE 1000
#define YES 1 
#define NO 0
#define N 10
#define P 3
#define K 4
int lr1(void)
{
    printf("Формулировка задания: из пункта А в пункт Б, выехала машина со\nскорость V1 км/ч. Навстречу ей выехал мотоциклист со скоростью V2 км/ч.\nНа каком расстоянии находятся пункты А и Б, если машина и мотоциклист\nвстретились через t часов?");
    printf("\n");
    float V1; 
    //скорость машины
    float V2; 
    //скорость мотоциклиста
    float t;
    // время встречи
    float S;
    //расстояние между А и Б
    printf("V1 = ");
    scanf("%f", &V1);
    printf("V2 = ");
    scanf("%f", &V2);
    printf("t = ");
    scanf("%f", &t);
    S = V1*t + V2*t;
    printf ("S = %f", S);
    return 0;
}
int lr12(void)
{
    printf("Формулировка задания:измените переменную, которая используется для расчётов, на\nцелочисленную переменную");
    printf("\n");
    int V1; 
    //скорость машины
    float V2; 
    //скорость мотоциклиста
    int t;
    // время встречи
    float S;
    //расстояние между А и Б
    printf("V1 = ");
    scanf("%d", &V1);
    printf("V2 = ");
    scanf("%f", &V2);
    printf("t = ");
    scanf("%d", &t);
    S = V1*t + V2*t;
    printf ("S = %f", S);
    return 0;
}

int lr2(void)
{
    printf("Формулировка задания: вычислить сумму первых N элементов ряда");
    printf("\n");
    float s,a;
    int n,i,k,x1;
    printf("n=");
    scanf("%d", &n);
    s=0;
    k=1;
    i=0;
    x1=1;
    while(i<n)
    {

        a=(i+1)/((float)(x1));
        s=s+a*k;
        k=-k;
        i=i+1;
        x1*=2;
    }
    printf("s=%f",s);
    return 0;
}
int lr22(void)
{
    printf("Формулировка задания: вместо while реализуйте цикл for");
    printf("\n");
    float s,a;
    int n,i,k,x1;
    printf("s=%f",s);
    printf("\n");
    printf("n=");
    scanf("%d", &n);
    s=0;
    k=1;
    i=0;
    x1=1;
    for(;i<n;i++)
    {
        a=(i+1)/((float)(x1));
        s=s+a*k;
        k=-k;
        x1*=2;
    }
    printf("s=%f",s);
    return 0;
}
int isLetter(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1; // символ является буквой
    } else {
        return 0; // символ не является буквой
    }
}

int lr3(void)
{
    printf("Формулировка задания: В потоке символов сосчитать число слов, у\nкоторых первые две буквы совпадают.");
    printf("\n");
    int cnt, c, prev_c, flag;
    cnt=0;
    flag=NO;
    printf ("Для окончания работы программы введите ctrl+D \n");
    while((c = getchar ()) != '0')
    {
        if ((c == ' ') || (c == '.') || (c == '\n') || (c == ','))
        {
            flag=NO;
            prev_c ==' ';
        }
        else
        {
            if (flag==NO)
            {
                flag=YES;
                prev_c=c;
            }
            else
            {
                if (prev_c==c)
                {
                    cnt++;
                    prev_c=' ';
                }
                else
                    prev_c=' ';
            }
        }
    }
    printf("\n number of words = %d\n", cnt );
}
int lr33(void)
{
    printf("Формулировка задания: В потоке символов сосчитать число слов,\nу которых первые три буквы совпадают.");
    printf("\n");
    int b,s=0,j=2;
    printf("колво символов = ");
    scanf("%i", &b);

    while ((getchar()) != '\n') {} // Очистка стандартного ввода

    char a[b];
    printf("введите строку = ");
    fgets(a, b+1, stdin);
    while( a[j] != '\0')
    {
        if(j==2){
            if(a[j-2]==a[j-1]&&a[j-1]==a[j]&&isLetter(a[j]) ){
                s++;
            }
        }else{
            if(a[j-3]==' '&&a[j-2]==a[j-1]&&a[j-1]==a[j]&&isLetter(a[j])){
                s++;
            }
        }
        j++;
        
    }
    printf("колво слов с первыми 3 одинаковыми буквами = %i\n", s );
}
void process_line( char buffer[] );
int lr4( void )
{
    printf("Формулировка задания: В символьной строке удалить все слова,\nначинающиеся с гласной буквы.");
    printf("\n");
    getchar();
    char line[MAXLINE];
    fgets( line,MAXLINE,stdin); ; 
    process_line( line );
    puts( line );
    return 0;
} 
void process_line( char buffer[] )
{ 
    char c; // текущий символ
    int prev_c= ' '; // предыдущий символ
    int flag= NO; // признак слова
    int found= NO; // индикатор того, что искомый признак в слове обнаружен
    int i= 0; // позиция текущего символа исходной cтроки
    int pos= 0; // позиция текущего символа результирующей строки
    int start= 0; // позиция начала слова
    int j; 
// цикл чтения символов из строки
do
    {
        c = buffer[i]; // взять текущий символ из  буфера
        if( c == ' ' || c == '.' || c == ',' ||  c == '\n' || c == '\0')
        {
            prev_c = c;
            if( flag == YES ) 
            { 
                if( found == NO ) 
                { 
                    // слово не подлежит удалению
                    // оно копируется в результирующую 
                    // строку
                    for( j = start; j < i; j++ )
                    buffer[pos++] = buffer[j]; 
                }
            }
            flag = NO; 
            buffer[pos++] = c; 
        }
        else
        { 
            // найдена буква
            if( flag == NO )
            {
                start = i;
                if((c=='a'|| c=='e'|| c=='y'|| c=='u'|| c=='i'|| c=='o')&& (prev_c==' '||prev_c=='.'|| prev_c == ',')) 
                    found = YES; 
                else
                    found = NO;
            }
            flag = YES; 
        } 
        prev_c = c;
        i++;
    }
    while( c != '\0' );
}
void process_line1( char buffer[] );
int lr44(void)
{
    printf("Формулировка задания: хочу, чтобы удалялись только те слова,\nкоторые содержат в себе меньше 3 букв.");
    printf("\n");
    char line[MAXLINE];
    fgets( line,MAXLINE,stdin); ; 
    process_line1( line );
    puts( line );
    return 0;
} 
void process_line1( char buffer[] )
{ 
    char c; // текущий символ
    int prev_c= ' '; // предыдущий символ
    int flag= NO; // признак слова
    int found= NO; // индикатор того, что искомый признак в слове обнаружен
    int i= 0; // позиция текущего символа исходной cтроки
    int pos= 0; // позиция текущего символа результирующей строки
    int start= 0; // позиция начала слова
    int j; 
// цикл чтения символов из строки
do
    {
        c = buffer[i]; // взять текущий символ из  буфера
        if( c == ' ' || c == '.' || c == ',' ||  c == '\n' || c == '\0')
        {
            prev_c = c;
            if( flag == YES ) 
            { 
                if( found == NO ) 
                { 
                    // слово не подлежит удалению
                    // оно копируется в результирующую 
                    // строку
                    for( j = start; j < i; j++ )
                    buffer[pos++] = buffer[j]; 
                }
            }
            flag = NO; 
            buffer[pos++] = c; 
        }
        else
        { 
            // найдена буква
            if( flag == NO )
            {
                start = i;
                if((c=='a'|| c=='e'|| c=='y'|| c=='u'|| c=='i'|| c=='o')&& (prev_c==' '||prev_c=='.'|| prev_c == ',')) 
                    found = YES; 
                else
                    found = NO;
            }
            flag = YES; 
        } 
        prev_c = c;
        i++;
    }
    while( c != '\0' );
}



int lr5(void)
{
    printf("Формулировка задания: В массиве из 10 целых чисел найти и поменять\nместами минимальный и максимальный элементы.");
    printf("\n");
    int arr[N]; 
    int i;
    int min_indx=0;
    int max_indx=0;

    for(i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    for( i = 1; i < N; i++ )
    {
        if (arr[i]<arr[min_indx]){
            min_indx=i;
        }
        if (arr[i]>arr[max_indx]){
            max_indx=i;
        }
    }
    int a=arr[min_indx];
    arr[min_indx]=arr[max_indx];
    arr[max_indx]=a;
    
    for( i = 0; i < N; i++ ){
        printf("%d ", arr[i]);
    }
    return 0;
}

int lr55(void)
{
    printf("Формулировка задания: если сохраняется регрессия ничего не меняется, иначе в массиве\nиз 10 целых чисел найти и поменять местами минимальный и максимальный элементы.");
    printf("\n");
    int n=10;
    int arr[n];
    int i;
    int min_indx=0;
    int max_indx=0;
    printf("Введите элементы ряда:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int isRegression = 1; // Предполагаем, что ряд является регрессией
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            isRegression = 0; // Если найден элемент больше предыдущего, то это не регрессия
            break;
        }
    }

    if (isRegression) {
        printf("Ряд является регрессией.\n");
    } else 
    {
        for( i = 1; i < N; i++ )
    {
        if (arr[i]<arr[min_indx]){
            min_indx=i;
        }
        if (arr[i]>arr[max_indx]){
            max_indx=i;
        }
    }
    int a=arr[min_indx];
    arr[min_indx]=arr[max_indx];
    arr[max_indx]=a;
        
    }
    for( i = 0; i < N; i++ ){
        printf("%d ", arr[i]);
    }
    return 0;
}

void printArray (int arr[P][K]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void selectionSort(int n, int p, int arr[n][p]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            int minIndexI = i;
            int minIndexJ = j;
            for (int k = i; k < n; k++) {
                for (int l = (k == i) ? j : 0; l < p; l++) {
                    if (arr[k][l] < arr[minIndexI][minIndexJ]) {
                        minIndexI = k;
                        minIndexJ = l;
                    }
                }
            }
            int temp = arr[i][j];
            arr[i][j] = arr[minIndexI][minIndexJ];
            arr[minIndexI][minIndexJ] = temp;
        }
    }
}
int lr6(void){
    printf("Формулировка задания: В двумерном целочисленном массиве размера N на K\nобнулить все строки, находящиеся ниже минимального элемента.");
    printf("\n");
    int arr[P][K];
    printf("Введите элементы массива %dx%d:\n", P, K);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int minIndexj = -1;
    int minIndex = -1;
    int aver=1000;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < K; j++) {
            if (aver > arr[i][j]) {
            aver=arr[i][j];
            minIndex = i;
            minIndexj=j;
            }
        }
    }
    // обнулить все строки, находящиеся ниже минимального элемента.
    for (int j = minIndexj+1; j < K; j++) {
            arr[minIndex][j]=0;
        }
    for (int i =minIndex+1; i < P; i++) {
        for (int j = 0; j < K; j++) {
            arr[i][j]=0;
        }
    }
    printf("Полученный массив:\n");
    printArray(arr);
    return 0;
    
    
}
int lr66(void) {
    printf("Формулировка задания: В двумерном целочисленном массиве размера N на K\nвнедрить сортировку выборкой");
    printf("\n");
    int arr[P][K];
    printf("Введите элементы массива %dx%d:\n", P, K);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int minIndexj = -1;
    int minIndex = -1;
    int aver=1000;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < K; j++) {
            if (aver > arr[i][j]) {
            aver=arr[i][j];
            minIndex = i;
            minIndexj=j;
            }
        }
    }
    // обнулить все строки, находящиеся ниже минимального элемента.
    for (int j = minIndexj+1; j < K; j++) {
            arr[minIndex][j]=0;
        }
    for (int i =minIndex+1; i < P; i++) {
        for (int j = 0; j < K; j++) {
            arr[i][j]=0;
        }
    }
    selectionSort(P, K, arr);    
    printf("Полученный массив:\n");
    printArray(arr);
    return 0;
}


int lr7(void) {
    printf("Формулировка задания: В длинном целом числе N поменять местами нулевой разряд с первым разрядом, второй разряд с третьим разрядом и т.д.");
    printf("\n");
    printf ("Для окончания работы программы введите ctrl+D \n");
    unsigned int L;
    printf("Исходное число: ");
    scanf("%u\n",&L);
    unsigned int mask = 0xAAAAAAAA; // Mask to select нечётных bits
    unsigned int even_bits = (L & mask) >> 1;
    
    mask = 0x55555555; // Mask to select чётных bits
    unsigned int odd_bits = (L & mask) << 1;
    
    unsigned int result = even_bits | odd_bits;
    
    printf("Числло после замены разрядов: %u\n", result);
    
    return 0;
}