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

const ld ZERO = 1e-15;
const ld EPS = 1e-10;
const int MAXN = 1005;
const int INF9 = 2 * 1e9;
const ll INF18 = 4 * 1e18;
const ll L0 = 0;

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
    little_cloudy,
    cloudy,
    rainy
} cloudCase;

typedef enum precipitation {
    no_precipitation,
    rain,
    snow,
    hail,
    acid_rain
} precipitationCase;

typedef enum phenomenaCase {
    hurricane,
    no_phenomena,
    tornado,
    storm,
    naked_ice,
    fog,
    eruption,
    sand_storm,
    revolution
} phenomenaCase;

typedef struct windStruct {
    int velocity;
    int dash;
    char direction[MAXN];
} windStruct;

typedef struct temperatureStruct {
    int low_temp_night;
    int high_temp_night;
    int low_temp_day;
    int high_temp_day;
} temperatureStruct;

// ------------------    CODE    ------------------ //

typedef struct dataStruct {
    dateStruct date;
    char city[MAXN];
    temperatureStruct temperature;
    windStruct wind;
    int pressure;
    cloudCase cloudiness;
    precipitationCase precipitation;
    phenomenaCase phenomena;
} dataStruct;

typedef struct forecastStruct {
    char city[MAXN];
    char date[MAXN];
    char horoscope[MAXN];
    char temperature[MAXN];
    char wind[MAXN];
    char pressure[MAXN];
    char cloudiness[MAXN];
    char precipitation[MAXN];
    char phenomena[MAXN];
    char joke[MAXN];
    char news[MAXN];
} forecastStruct;

dataStruct data;
forecastStruct forecast;

void input(FILE* Input) {
    fscanf(Input, "%d.%d.%d\n", &data.date.day, &data.date.month, &data.date.year);

    fgets(data.city, MAXN, Input);
    data.city[strlen(data.city) - 1] = '\0';

    fscanf(Input, "%d/%d\n", &data.temperature.low_temp_day, &data.temperature.high_temp_day);
    fscanf(Input, "%d/%d\n", &data.temperature.low_temp_night, &data.temperature.high_temp_night);

    fscanf(Input, "%s\n", data.wind.direction);
    fscanf(Input, "%d\n", &data.wind.velocity);
    fscanf(Input, "%d\n", &data.wind.dash);

    fscanf(Input, "%d\n", &data.pressure);

    char tmp[MAXN] = { 0 };
    fgets(tmp, MAXN, Input);
    tmp[strlen(tmp) - 1] = '\0';
    if (!strcmp(tmp, "Солнечно")) data.cloudiness = shiny;
    if (!strcmp(tmp, "Ясно")) data.cloudiness = clear;
    if (!strcmp(tmp, "Малая облачность")) data.cloudiness = little_cloudy;
    if (!strcmp(tmp, "Облачно")) data.cloudiness = cloudy;
    if (!strcmp(tmp, "Пасмурно")) data.cloudiness = rainy;

    fgets(tmp, MAXN, Input);
    tmp[strlen(tmp) - 1] = '\0';
    if (!strcmp(tmp, "Нет")) data.precipitation = no_precipitation;
    if (!strcmp(tmp, "Дождь")) data.precipitation = rain;
    if (!strcmp(tmp, "Снег")) data.precipitation = snow;
    if (!strcmp(tmp, "Град")) data.precipitation = hail;
    if (!strcmp(tmp, "Кислотный дождь")) data.precipitation = acid_rain;

    fgets(tmp, MAXN, Input);
    tmp[strlen(tmp) - 1] = '\0';
    if (!strcmp(tmp, "Нет")) data.phenomena = no_phenomena;
    if (!strcmp(tmp, "Ураган")) data.phenomena = hurricane;
    if (!strcmp(tmp, "Смерч")) data.phenomena = tornado;
    if (!strcmp(tmp, "Гроза")) data.phenomena = storm;
    if (!strcmp(tmp, "Туман")) data.phenomena = fog;
    if (!strcmp(tmp, "Гололедица")) data.phenomena = naked_ice;
    if (!strcmp(tmp, "Извержение вулкана")) data.phenomena = eruption;
    if (!strcmp(tmp, "Песчаная буря")) data.phenomena = sand_storm;
    if (!strcmp(tmp, "Великая Октябрьская Революция")) data.phenomena = revolution;
    // Pizdets ebaniy zhest'
}

void output(FILE* Output) {
    fprintf(Output, "%s\n\n", forecast.city);

    fprintf(Output, "%s\n\n", forecast.date);

    fprintf(Output, "%s\n\n", forecast.horoscope);

    fprintf(Output, "%s\n\n", forecast.temperature);

    fprintf(Output, "%s\n\n", forecast.pressure);

    fprintf(Output, "%s\n\n", forecast.cloudiness);

    fprintf(Output, "%s\n\n", forecast.wind);

    fprintf(Output, "%s\n\n", forecast.precipitation);

    fprintf(Output, "%s\n\n", forecast.phenomena);

    fprintf(Output, "%s\n\n", forecast.joke);

    fprintf(Output, "%s\n\n", forecast.news);
}

// Transform dd.mm.yyyy to text
char* transform_date(wordCase word_case) {
    char *res[MAXN] = { 0 };
    char day_str[MAXN] = { 0 };
    char month_str[MAXN] = { 0 };
    char year_str[MAXN] = { 0 };
    int day = data.date.day;
    int month = data.date.month;
    int year = data.date.year;

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
            // MARK:  make individual case for digit 3 break;
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
int is_leap_year() {
    return (data.date.year % 4 == 0 && data.date.year % 100 != 0 || data.date.year % 400 == 0 ? 1 : 0);
}

// Returns number of the day in the year
int get_day_number() {
    int len[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (is_leap_year(data.date)) len[1]++;

    int num = 0;

    fori(data.date.month - 1) num += len[i];

    num += data.date.day + 1;

    return num;
}

// Returns horoscope sign for date
char* get_horoscope() {
    int number = get_day_number(data.date);

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
        char res[MAXN] = { 0 };
        strcpy(res, "Козерог");
        return res;
    }

    int ind = 0;

    char str[MAXN] = { 0 };



    ind = number / 31;

    strcpy(str, signs[ind]);

    return (char*)str;
}

// do not touch!
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

// do not touch!
char* get_random_phrase(FILE* Input) {
    int cnt;
    fscanf(Input, "%d\n", &cnt);

    int ind = rand() % cnt + 1;
    char *str[MAXN] = { 0 };
    fori(ind) {
        fgets(str, MAXN, Input);
    }

    return str;
}

// do not touch!
char* reverse_str(char str[]) {
    fori(strsize(str) / 2) {
        char c = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = c;
    }
    return str;
}

// do not touch!
char* to_string(int n) {
    char res[MAXN] = { 0 };
    if (!n) strcpy(res, "0");
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

// do not touch!
char* insert_number(char *s, int n) {
    int len = strlen(s);
    char num[MAXN] = { 0 };
    strcpy(num, to_string(n));
    char res[MAXN] = { 0 };
    fori(len) {
        char c = s[i];
        if (c == '$') {
            forj(i) strncat(res, &s[j], 1);
            strcat(res, num);
            FOR(j, i + 1, len) strncat(res, &s[j], 1);
            strcpy(s, res);
            return s;
        }
    }
    return s;
}

// do not touch!
char* insert_string(char *s, char *n) {
    int len = strlen(s);
    char num[MAXN] = { 0 };
    strcpy(num, n);
    char res[MAXN] = { 0 };
    fori(len) {
        char c = s[i];
        if (c == '$') {
            forj(i) strncat(res, &s[j], 1);
            strcat(res, num);
            FOR(j, i + 1, len) strncat(res, &s[j], 1);
            strcpy(s, res);
            return s;
        }
    }
    return s;
}

// generates message for city
void get_message_for_city(FILE* Input) {
    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';
    strcat(str, " ");

    char res[MAXN] = { 0 };
    strcat(res, str);
    strcat(res, data.city);
    strcat(res, ".");

    strcpy(forecast.city, res);
}

// generates message for date
void get_message_for_date(FILE* Input) {
    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    char wc = str[0];
    fori(strlen(str)) str[i] = str[i + 1];

    char res[MAXN] = { 0 };
    strcat(res, str);

    char date_str[MAXN] = { 0 };

    switch (wc) {
        case '0': { strcat(date_str, transform_date(nominative));       break; }
        case '1': { strcat(date_str, transform_date(genitive));         break; }
        case '2': { strcat(date_str, transform_date(dative));           break; }
        case '3': { strcat(date_str, transform_date(accusative));       break; }
        case '4': { strcat(date_str, transform_date(instrumental));     break; }
        case '5': { strcat(date_str, transform_date(prepositional));    break; }
        default:                                                        break;
    }

    insert_string(res, date_str);

    strcat(res, ".");

    strcpy(forecast.date, res);
}

// generates message for horoscope
void get_message_for_horoscope(FILE* Input) {
    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    char tmp[MAXN] = { 0 };
    char horoscope_str[MAXN] = { 0 };
    strcpy(horoscope_str, get_horoscope());
    strcpy(tmp, insert_string(str, horoscope_str));
    strcpy(str, tmp);

    int number = get_day_number();
    if (number == 186) {
        strcat(str, " Сегодня день рождения празднует великолепный преподаватель из НИУ ВШЭ, выпускница школы номер 7, НГТУ им. Алексеева и просто хороший человек - Лупанова Елена Александровна!");
    }

    strcpy(forecast.horoscope, str);
}

// generates message for temperature
void get_message_for_temperature(FILE* Input_day, FILE* Input_night) {
    char str_night[MAXN] = { 0 };
    strcpy(str_night, get_random_phrase(Input_night));
    str_night[strlen(str_night) - 1] = '\0';

    char tmp[MAXN] = { 0 };
    strcpy(tmp, insert_number(str_night, data.temperature.low_temp_night));
    strcpy(str_night, tmp);
    strcpy(tmp, "");
    strcpy(tmp, insert_number(str_night, data.temperature.high_temp_night));
    strcpy(str_night, tmp);

    char str_day[MAXN] = { 0 };
    strcpy(str_day, get_random_phrase(Input_day));
    str_day[strlen(str_day) - 1] = '\0';

    strcpy(tmp, "");
    strcpy(tmp, insert_number(str_day, data.temperature.low_temp_day));
    strcpy(str_day, tmp);
    strcpy(tmp, "");
    strcpy(tmp, insert_number(str_day, data.temperature.high_temp_day));
    strcpy(str_day, tmp);

    strcat(str_night, " ");
    strcat(str_night, str_day);

    strcpy(forecast.temperature, str_night);
}

// generates message for pressure
void get_message_for_pressure(FILE* Input) {
    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    char tmp[MAXN] = { 0 };
    strcpy(tmp, insert_number(str, data.pressure));
    strcpy(str, tmp);

    strcpy(forecast.pressure, str);
}

// generates message for cloudiness
void get_message_for_cloudiness(FILE* Input) {
    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    char ins[MAXN] = { 0 };

    switch (data.cloudiness) {
        case clear:         { strcpy(ins, "ясно"); break; }
        case shiny:         { strcpy(ins, "солнечно"); break; }
        case little_cloudy: { strcpy(ins, "малая облачность"); break; }
        case cloudy:        { strcpy(ins, "облачно"); break; }
        case rainy:         { strcpy(ins, "пасмурно"); break; }
    }

    char tmp[MAXN] = { 0 };

    strcpy(tmp, insert_string(str, ins));
    strcpy(str, tmp);

    strcpy(forecast.cloudiness, str);
}

// generates message for wind
void get_message_for_wind(FILE* Input_direction, FILE* Input_velocity, FILE* Input_dash) {
    char str_direction[MAXN] = { 0 };
    strcpy(str_direction, get_random_phrase(Input_direction));
    str_direction[strlen(str_direction) - 1] = '\0';

    char dir[MAXN] = { 0 };
    if (!strcmp(data.wind.direction, "С"))  strcpy(dir, "cеверный");
    if (!strcmp(data.wind.direction, "Ю"))  strcpy(dir, "южный");
    if (!strcmp(data.wind.direction, "З"))  strcpy(dir, "западный");
    if (!strcmp(data.wind.direction, "В"))  strcpy(dir, "восточный");
    if (!strcmp(data.wind.direction, "СЗ")) strcpy(dir, "cеверо-западный");
    if (!strcmp(data.wind.direction, "СВ")) strcpy(dir, "cеверо-восточный");
    if (!strcmp(data.wind.direction, "ЮЗ")) strcpy(dir, "юго-западный");
    if (!strcmp(data.wind.direction, "ЮВ")) strcpy(dir, "юго-восточный");

    char tmp[MAXN] = { 0 };
    strcpy(tmp, insert_string(str_direction, dir));
    strcpy(str_direction, tmp);

    char str_velocity[MAXN] = { 0 };
    strcpy(str_velocity, get_random_phrase(Input_velocity));
    str_velocity[strlen(str_velocity) - 1] = '\0';

    char ins[MAXN] = { 0 };

    if (2 <= data.wind.velocity && data.wind.velocity <= 3) strcpy(ins, "тихого ");
    if (4 <= data.wind.velocity && data.wind.velocity <= 6) strcpy(ins, "легкого ");
    if (7 <= data.wind.velocity && data.wind.velocity <= 10) strcpy(ins, "слабого ");
    if (11 <= data.wind.velocity && data.wind.velocity <= 14) strcpy(ins, "умеренного ");
    if (15 <= data.wind.velocity && data.wind.velocity <= 24) strcpy(ins, "сильного ");
    if (25 <= data.wind.velocity && data.wind.velocity <= 32) strcpy(ins, "очень сильного ");
    if (33 <= data.wind.velocity) strcpy(ins, "ураганного ");

    strcpy(tmp, "");
    strcpy(tmp, insert_string(str_velocity, ins));
    strcpy(str_velocity, tmp);


    if (data.wind.velocity <= 1) {
        switch (rand() % 3) {
            case 0: strcat(str_velocity, " В городе штиль.");
            case 1: strcat(str_velocity, " Краткий прогноз - в городе штиль.");
            case 2: strcat(str_velocity, " Метеорологи называют такой ветер штилем.");
        }
    }

    strcpy(tmp, "");
    strcpy(tmp, insert_number(str_velocity, data.wind.velocity));
    strcpy(str_velocity, tmp);

    char str_dash[MAXN] = { 0 };
    strcpy(str_dash, get_random_phrase(Input_dash));
    str_dash[strlen(str_dash) - 1] = '\0';

    strcpy(tmp, "");
    strcpy(tmp, insert_number(str_dash, data.wind.dash));
    strcpy(str_dash, tmp);

    if (data.wind.velocity <= 1 && data.wind.dash >= 2) {
        strcpy(str_dash, "");
        strcpy(str_dash, "Как мы знаем, при штиле ветер ведет себя спокойно, несмотря на то, что горе-метеорологи передают порывы до $ м/с.");
        strcpy(tmp, "");
        strcpy(tmp, insert_number(str_dash, data.wind.dash));
        strcpy(str_dash, tmp);
    }

    char str[MAXN] = { 0 };

    switch (rand() % 3) {
        case 0: { strcat(str, str_velocity);    strcat(str, " ");   strcat(str, str_dash);      strcat(str, " ");   strcat(str, str_direction); break; }
        case 1: { strcat(str, str_direction);   strcat(str, " ");   strcat(str, str_velocity);  strcat(str, " ");   strcat(str, str_dash);      break; }
        case 2: { strcat(str, str_velocity);    strcat(str, " ");   strcat(str, str_direction); strcat(str, " ");   strcat(str, str_dash);      break; }
    }

    strcpy(forecast.wind, str);
}

// generates message for precipitation
void get_message_for_precipitation(FILE* Input) {
    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    char prec[MAXN] = { 0 };
    switch (data.precipitation) {
        case no_precipitation:  { strcpy(prec, "безосадочно"); break; }
        case rain:              { strcpy(prec, "дождливно"); break; }
        case snow:              { strcpy(prec, "снегопадно"); break; }
        case hail:              { strcpy(prec, "градно"); break; }
        case acid_rain:         { strcpy(prec, "кислотно-дождливно"); break; }
    }

    char tmp[MAXN] = { 0 };
    strcpy(tmp, insert_string(str, prec));
    strcpy(str, tmp);

    strcpy(forecast.precipitation, str);
}

// generates message for phenomena
void get_message_for_phenomena(FILE* Input) {
    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    char prec[MAXN] = { 0 };
    switch (data.phenomena) {
        case hurricane:     { strcpy(prec, "ураган"); break; }
        case no_phenomena:  { strcpy(prec, "скупой на наличие явлений день"); break; }
        case tornado:       { strcpy(prec, "торнадо"); break; }
        case storm:         { strcpy(prec, "буря"); break; }
        case naked_ice:     { strcpy(prec, "гололедица"); break; }
        case fog:           { strcpy(prec, "туман"); break; }
        case eruption:      { strcpy(prec, "извержение вулкана"); break; }
        case sand_storm:    { strcpy(prec, "песчаная буря"); break; }
        case revolution:    { strcpy(prec, "Великая Революция"); break; }
    }

    char tmp[MAXN] = { 0 };
    strcpy(tmp, insert_string(str, prec));
    strcpy(str, tmp);

    strcpy(forecast.phenomena, str);
}

// generates message for jokes
void get_message_for_jokes(FILE* Input_cold, FILE* Input_hot, FILE* Input_wind) {
    char str[MAXN] = { 0 };

    if (data.temperature.low_temp_day <= 0) {
        strcpy(str, get_random_phrase(Input_cold));
        str[strlen(str) - 1] = '\0';
    }
    if (data.temperature.high_temp_day > 0) {
        strcpy(str, get_random_phrase(Input_hot));
        str[strlen(str) - 1] = '\0';
    }

    if (data.wind.dash >= 15) {
        strcpy(str, " ");
        strcpy(str, get_random_phrase(Input_wind));
        str[strlen(str) - 1] = '\0';
    }

    strcpy(forecast.joke, str);
}

// generates message for news
void get_message_for_news(FILE* Input) {
    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    strcpy(forecast.news, str);
}

// generates whole forecast
void get_forecast(FILE *Input_City,
                  FILE* Input_Date, FILE* Input_Horoscope,
                  FILE *Input_Temp_day, FILE* Input_Temp_night,
                  FILE* Input_Pressure,
                  FILE* Input_Cloudiness,
                  FILE* Input_Wind_direction, FILE* Input_Wind_velocity, FILE* Input_Wind_dash,
                  FILE* Input_Precipitation,
                  FILE* Input_Phenomena,
                  FILE* Input_Jokes_cold, FILE* Input_Jokes_hot, FILE* Input_Jokes_wind,
                  FILE* Input_News) {

    get_message_for_city(Input_City);

    get_message_for_date(Input_Date);

    get_message_for_horoscope(Input_Horoscope);

    get_message_for_temperature(Input_Temp_day, Input_Temp_night);

    get_message_for_pressure(Input_Pressure);

    get_message_for_cloudiness(Input_Cloudiness);

    get_message_for_wind(Input_Wind_direction, Input_Wind_velocity, Input_Wind_dash);

    get_message_for_precipitation(Input_Precipitation);

    get_message_for_phenomena(Input_Phenomena);

    get_message_for_jokes(Input_Jokes_cold, Input_Jokes_hot, Input_Jokes_wind);

    get_message_for_news(Input_News);
}

int main() {
#ifdef FILEINOUT
    FILE *In, *Out;
    In = fopen("Input.txt", "r");
    Out = fopen("Output.txt", "w");
    FILE *Input_City;
    Input_City = fopen("City.txt", "r");
    FILE *Input_Date;
    Input_Date = fopen("Date.txt", "r");
    FILE *Input_Horoscope;
    Input_Horoscope = fopen("Horoscope.txt", "r");
    FILE *Input_Temp_day;
    Input_Temp_day = fopen("Temperature_day.txt", "r");
    FILE *Input_Temp_night;
    Input_Temp_night = fopen("Temperature_night.txt", "r");
    FILE *Input_Pressure;
    Input_Pressure = fopen("Pressure.txt", "r");
    FILE *Input_Cloudiness;
    Input_Cloudiness = fopen("Cloudiness.txt", "r");
    FILE *Input_Wind_direction;
    Input_Wind_direction = fopen("Wind_direction.txt", "r");
    FILE *Input_Wind_velocity;
    Input_Wind_velocity = fopen("Wind_velocity.txt", "r");
    FILE *Input_Wind_dash;
    Input_Wind_dash = fopen("Wind_dash.txt", "r");
    FILE *Input_Precipitation;
    Input_Precipitation = fopen("Precipitation.txt", "r");
    FILE *Input_Phenomena;
    Input_Phenomena = fopen("Phenomena.txt", "r");
    FILE *Input_Jokes_cold;
    Input_Jokes_cold = fopen("Jokes_cold.txt", "r");
    FILE *Input_Jokes_hot;
    Input_Jokes_hot = fopen("Jokes_hot.txt", "r");
    FILE *Input_Jokes_wind;
    Input_Jokes_wind = fopen("Jokes_wind.txt", "r");
    FILE *Input_News;
    Input_News = fopen("News.txt", "r");
#endif
    srand(time(0));
    setlocale(LC_ALL, "Rus");

    input(In);

    get_forecast(Input_City,
                 Input_Date, Input_Horoscope,
                 Input_Temp_day, Input_Temp_night,
                 Input_Pressure,
                 Input_Cloudiness,
                 Input_Wind_direction, Input_Wind_velocity, Input_Wind_dash,
                 Input_Precipitation,
                 Input_Phenomena,
                 Input_Jokes_cold, Input_Jokes_hot, Input_Jokes_wind,
                 Input_News);

    output(Out);

#ifdef FILEINOUT
    fclose(In);
    fclose(Out);

    fclose(Input_City);
    fclose(Input_Temp_day);
    fclose(Input_Temp_night);
    fclose(Input_Date);
    fclose(Input_Horoscope);
    fclose(Input_Pressure);
    fclose(Input_Cloudiness);
    fclose(Input_Wind_direction);
    fclose(Input_Wind_velocity);
    fclose(Input_Wind_dash);
    fclose(Input_Precipitation);
    fclose(Input_Phenomena);
#endif

    return 0;
}