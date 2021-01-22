#define FILEINOUT
#define _CRT_SECURE_WARNINGS
#define _USE_MATH_DEFINE

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>


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

typedef enum cloudCase {
    clear,
    shiny,
    temp_shiny,
    temp_clear,
    rainy,
    cloudy,
} cloudCase;

typedef enum precipitation {
    no,
    rain_little,
    rain_medium,
    rain_hard,
    snow,
    hail,
    acid_rain
} precipitationCase;

typedef enum phenomenaCase {
    tornado,
    squall,
    storm,
    breeze,
    ice,
    snow_storm,
    fog,
    smog,
    eruption,
    thunder_storm
} phenomenaCase;

typedef struct windStruct {
    int velocity;
    int dash;
    char direction[2];
} windStruct;

typedef struct temperatureStruct {
    int low_temp_night;
    int high_temp_night;
    int low_temp_day;
    int high_temp_day;
} temperatureStruct;

typedef struct pressureStruct {
    int pressure;
} pressureStruct;

typedef struct weatherStruct {
    temperatureStruct temperature;
    precipitationCase precipitation;
    cloudCase cloudy;
    windStruct wind;
    phenomenaCase phenomena;
} weatherStruct;

const ld ZERO = 1e-15;
const ld EPS = 1e-10;
const int MAXN = 100500;
const int INF9 = 2 * 1e9;
const ll INF18 = 4 * 1e18;
const ll L0 = 0;

// ------------------    CODE    ------------------ //

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

// Returns whether the year is leap
int is_leap_year(dateStruct date) {
    return (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0 ? 1 : 0);
}

// Returns number of the day in the year
int get_day_number(dateStruct date) {
    int len[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (is_leap_year(date)) len[1]++;

    int num = 0;

    fori(date.month - 1) num += len[i];

    num += date.day + 1;

    return num;
}

// Returns horoscope sign for date
char* get_horoscope(dateStruct date) {
    int number = get_day_number(date);

    char signs[12][MAXN] = {
            "Водолей",
            "Рыбы",
            "Овен",
            "Телец",
            "Близнецы",
            "Рак",
            "Лев",
            "Дева",
            "Весы",
            "Скорпион",
            "Стрелец",
            "Козерог"
    };

    number -= 20;

    if (number <= 0) {
        char res[MAXN];
        strcpy(res, "Козерог");
        return res;
    }

    int ind = 0;

    ind = number / 30;

    return signs[ind];
}

char* get_random_phrase(FILE* In) {
    int cnt;
    fscanf(In, "%d", &cnt);

    int n = rand() % cnt;
    char str[MAXN];
    fgets(str, MAXN, In);
    fori(n + 1) fgets(str, MAXN, In);

    str[strlen(str) - 1] = '\0';

    return str;
}

char* get_message_for_city(FILE* In_City, char city[]) {

    char str[MAXN];
    strcpy(str, get_random_phrase(In_City));

    strcat(str, " ");
    //str[strlen(str) - 1] = '\0';
    //str[strlen(str) - 1] = ' ';

    char res[MAXN];
    strcat(res, str);
    strcat(res, city);
    strcat(res, ".");

    return res;
}

int strsize(char s[]) {
    int n = 0;
    int cnt = 0;
    while (s[n] != '\0') {
        char c = s[n];
        if (0 <= c && c < 256) cnt++;
        n++;
    }
    if (s[n] == '\n') cnt++;
    n = strlen(s);
    n -= cnt;
    n /= 2;
    n += cnt;
    return n;
}

char* reverse_str(char str[]) {
    int n = strsize(str);
    fori(strsize(str) / 2) {
        char c = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = c;
    }
    return str;
}

char* to_string(int n) {
    char res[MAXN] = { 0 };
    char digit[1];
    int negative = (n < 0);
    n = abs(n);
    while (n) {
        char c;
        c = n % 10;
        c += '0';
        strncat(res, &c, 1);
        n /= 10;
    }
    if (negative) strcat(res, "-");

    return reverse_str(res);
}

char* insert_data(char s[], int n) {
    int len = strsize(s);
    char num[MAXN] = { 0 };
    strcpy(num, to_string(n));
    char res[MAXN] = { 0 };
    fori(len) {
        if (s[i] == '$') {
            forj(i) strncat(res, &s[j], 1);
            strcat(res, num);
            FOR(j, i + 1, len) strncat(res, &s[j], 1);
            strcpy(s, res);
        }
    }
    return s;
}

char* get_message_for_temperature(FILE* In_Temp, weatherStruct weather) {
    int cnt;
    fscanf(In_Temp, "%d", &cnt);

    int ind = rand() % cnt;
    char str_night[MAXN] = { 0 };
    fori(ind) fgets(str_night, MAXN, In_Temp);

    strcpy(str_night, insert_data(str_night, weather.temperature.low_temp_night));
    strcpy(str_night, insert_data(str_night, weather.temperature.high_temp_night));

    ind = rand() % cnt + 5;
    char str_day[MAXN] = { 0 };
    fori(ind) fgets(str_day, MAXN, In_Temp);

    strcpy(str_day, insert_data(str_day, weather.temperature.low_temp_day));
    strcpy(str_day, insert_data(str_day, weather.temperature.high_temp_day));

    strcat(str_night, str_day);

    return str_night;
}

char* get_forecast(FILE *Input_City, FILE *Input_Temp) {

    char forecast[MAXN];

    // Приветствие
    char welcome_city[MAXN];
    char city[MAXN];
    strcpy(city, "Москва");
    strcpy(welcome_city, get_message_for_city(Input_City, city));

    strcat(forecast, welcome_city);
    strcat(forecast, "\n");
    // Дата
    // Горокоп

    // Температура

    weatherStruct weather;
    weather.temperature.high_temp_day = 50;
    weather.temperature.high_temp_night = 10;
    weather.temperature.low_temp_night = -39;
    weather.temperature.low_temp_day = 25;

    char message_temperature[MAXN];
    strcpy(message_temperature, get_message_for_temperature(Input_Temp, weather));
    strcat(forecast, "\n");
    strcat(forecast, message_temperature);

    return forecast;
}

int main() {
#ifdef FILEINOUT
    FILE *In, *Out;
    In = fopen("Input.txt", "r");
    Out = fopen("Output.txt", "w");
    FILE *Input_City;
    Input_City = fopen("City.txt", "r");
    FILE *Input_Temp;
    Input_Temp = fopen("Temperature.txt", "r");
#endif
    srand(time(0));
    setlocale(LC_ALL, "Rus");

    char forecast[MAXN];
    strcpy(forecast, get_forecast(Input_City, Input_Temp));

    fprintf(Out, "%s", forecast);

#ifdef FILEINOUT
    fclose(In);
    fclose(Out);

    fclose(Input_City);
#endif

    return 0;
}