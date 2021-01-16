#define FILEINOUT
#define _CRT_SECURE_WARNINGS
#define _USE_MATH_DEFINE

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// loops
#define fori(x) for (int i = 0; i < (x); ++i)
#define fordi(x) for (int i = (x - 1); i >= 0; --i)
#define forj(x) for (int j = 0; j < (x); j++)
#define fordj(x) for (int j = (x - 1); j >= 0; --j)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
// upgraded functions
#define min3(a, b, c) min(ll(a), min(ll(b), ll(c)))
#define max3(a, b, c) max(ll(a), max(ll(b), ll(c)))
#define abs0(x) max(L0, ll(x))
// math
#define pow2(x) ((x) * (x))
#define pow3(x) ((x) * (x) * (x))
// others
#define endl printf("\n")

typedef long long ll;
typedef long double ld;

typedef struct dataStruct {
    int low_temp_night;
    int high_temp_night;
    int low_temp_day;
    int high_temp_day;
} dataStruct;

typedef struct dateStruct {
    int day;
    int month;
    int year;
} dateStruct;

typedef enum wordCase {
    nominative,
    genitive,
    dative,
    accusative,
    instrumental,
    prepositional
} wordCase;

const ld ZERO = 1e-15;
const ld EPS = 1e-10;
const int MAXN = 100500;
const int INF9 = 2 * 1e9;
const ll INF18 = 4 * 1e18;
const ll L0 = 0;

// ------------------    CODE    ------------------ //

dataStruct data;

void inputData(FILE *In) {
    fscanf(In, "%d", &data.low_temp_night);
    fscanf(In, "%d", &data.high_temp_night);
    fscanf(In, "%d", &data.low_temp_day);
    fscanf(In, "%d", &data.high_temp_day);
    return;
}

void outputData(FILE *Out) {

}

// Transform dd.mm.yyyy to text
char* transform_date(dateStruct date, wordCase word_case) {
    char res[MAXN] = { 0 };
    char day_str[MAXN] = { 0 };
    char month_str[MAXN] = { 0 };
    char year_str[MAXN] = { 0 };
    int day = date.day;
    int month = date.month;
    int year = date.year;

    // Transform day

    if (20 < day && day < 30) {
        strcat(day_str, "двадцать ");
        day -= 20;
    }
    if (30 < day) {
        strcat(day_str, "тридцать ");
        day -= 30;
    }

    if (day == 10) strcat(day_str, "десят");
    else if (day == 20) strcat(day_str, "двадцат");
    else if (day == 30) strcat(day_str, "тридцат");
    else {
        switch (day) {
            case 1: { strcat(day_str, "перв"); break; }
            case 2: { strcat(day_str, "втор"); break; }
            // TODO:  make individual case for digit 3 break;
            case 4: { strcat(day_str, "четверт"); break; }
            case 5: { strcat(day_str, "пят"); break; }
            case 6: { strcat(day_str, "шест"); break; }
            case 7: { strcat(day_str, "седьм"); break; }
            case 8: { strcat(day_str, "восьм"); break; }
            case 9: { strcat(day_str, "девят"); break; }

            case 11: { strcat(day_str, "одиннадцат"); break; }
            case 12: { strcat(day_str, "двенадцат"); break; }
            case 13: { strcat(day_str, "тринадцат"); break; }
            case 14: { strcat(day_str, "четырнадцат"); break; }
            case 15: { strcat(day_str, "пятнадцат"); break; }
            case 16: { strcat(day_str, "шестнадцат"); break; }
            case 17: { strcat(day_str, "семнадцат"); break; }
            case 18: { strcat(day_str, "восемнадцат"); break; }
            case 19: { strcat(day_str, "девятнадцат"); break; }
        }
    }
    if (day % 10 == 3 && day != 13) {
        switch (word_case) {
            case nominative:    { strcat(day_str, "третье "); break; }
            case genitive:      { strcat(day_str, "третьего "); break; }
            case dative:        { strcat(day_str, "третьему "); break; }
            case accusative:    { strcat(day_str, "третье "); break; }
            case instrumental:  { strcat(day_str, "третьим "); break; }
            case prepositional: { strcat(day_str, "третьем "); break; }
        }
    } else switch (word_case) {
        case nominative:    { strcat(day_str, "ое "); break; }
        case genitive:      { strcat(day_str, "ого "); break; }
        case dative:        { strcat(day_str, "ому "); break; }
        case accusative:    { strcat(day_str, "ое "); break; }
        case instrumental:  { strcat(day_str, "ым "); break; }
        case prepositional: { strcat(day_str, "ом "); break; }
    }

    // Transform month

    switch (month) {
        case 1: { strcat(month_str, "января "); break; }
        case 2: { strcat(month_str, "февраля "); break; }
        case 3: { strcat(month_str, "марта "); break; }
        case 4: { strcat(month_str, "апреля "); break; }
        case 5: { strcat(month_str, "мая "); break; }
        case 6: { strcat(month_str, "июня "); break; }
        case 7: { strcat(month_str, "июля "); break; }
        case 8: { strcat(month_str, "августа "); break; }
        case 9: { strcat(month_str, "сентября "); break; }
        case 10: { strcat(month_str, "октября "); break; }
        case 11: { strcat(month_str, "ноября "); break; }
        case 12: { strcat(month_str, "декабря "); break; }
        default: break;
    }

    // Transform year

    sprintf(year_str, "%d", year);

    strcat(res, day_str);
    strcat(res, month_str);
    strcat(res, year_str);

    return res;
}

int main() {
#ifdef FILEINOUT
    FILE *In, *Out;
    In = fopen("Input.txt", "r");
    Out = fopen("Output.txt", "w");
#endif


        dateStruct date;
        date.day = 21;
        date.month = 1;
        date.year = 2021;
        char str[MAXN] = { 0 };
        strcpy(str, transform_date(date, genitive));
        fprintf(Out, "%s\n", str);


#ifdef FILEINOUT
    fclose(In);
    fclose(Out);
#endif

    return 0;
}