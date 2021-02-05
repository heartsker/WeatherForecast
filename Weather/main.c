#define FILEINOUT
#define _CRT_SECURE_NO_WARNINGS
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
const int MAXN = 2005;
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
    int count_of_messages;
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

typedef struct dataPredictionStruct {
    int temperature;
    windStruct wind;
    int pressure;
} dataPredictionStruct;

typedef struct forecastPredictionStruct {
    int count_of_messages;
    char date[MAXN];
    char temperature[MAXN];
    char wind[MAXN];
    char pressure[MAXN];
    char other[MAXN];
} forecastPredictionStruct;


dataStruct data;
forecastStruct forecast;
dataPredictionStruct data_prediction;
forecastPredictionStruct forecast_prediction;

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
    strcat(forecast.horoscope, "\n");

    char output_array[forecast.count_of_messages][MAXN];

    strcpy(output_array[0], forecast.city);
    strcpy(output_array[1], forecast.date);
    strcpy(output_array[2], forecast.horoscope);

    strcpy(output_array[3], forecast.temperature);
    strcpy(output_array[4], forecast.pressure);
    strcpy(output_array[5], forecast.cloudiness);
    strcpy(output_array[6], forecast.wind);
    strcpy(output_array[7], forecast.precipitation);
    strcpy(output_array[8], forecast.phenomena);

    strcpy(output_array[9], forecast.joke);
    strcpy(output_array[10], forecast.news);

    fori(10) {
        int l = rand() % 5 + 4;
        int r = rand() % 5 + 4;
        if (l == r) continue;
        char tmp[MAXN] = { 0 };
        strcpy(tmp, output_array[l]);
        strcpy(output_array[l], output_array[r]);
        strcpy(output_array[r], tmp);
    }

    if (rand() % 2) {
        char tmp[MAXN] = { 0 };
        strcpy(tmp, output_array[9]);
        strcpy(output_array[9], output_array[10]);
        strcpy(output_array[10], tmp);
    }

    strcat(output_array[8], "\n");
    strcat(output_array[9], "\n");

    fori(forecast.count_of_messages) {
        fprintf(Output, "%s\n", output_array[i]);
    }
}

void output_prediction(FILE* Output) {

    fprintf(Output, "\n");
    switch (rand() % 3) {
        case 0: { fprintf(Output, "Разрешите попробовать предсказать будущее. Вот вам примерный прогноз погоды на ближайший день:\n"); break; }
        case 1: { fprintf(Output, "Метеорологи в нашем центре научились предсказывать погоду заранее:\n"); break; }
        case 2: { fprintf(Output, "Массоны раскрыли тайну погоды на следующий день:\n"); break; }
    }


    char output_array[forecast_prediction.count_of_messages][MAXN];

    strcpy(output_array[0], forecast_prediction.date);
    strcpy(output_array[1], forecast_prediction.temperature);
    strcpy(output_array[2], forecast_prediction.pressure);
    //strcpy(output_array[5], forecast.cloudiness);
    strcpy(output_array[3], forecast_prediction.wind);
    strcpy(output_array[4], forecast_prediction.other);
    //strcpy(output_array[7], forecast.precipitation);
    //strcpy(output_array[8], forecast.phenomena);

    fori(forecast_prediction.count_of_messages) {
        fprintf(Output, "%s\n", output_array[i]);
    }
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
char* get_random_phrase_for_block(FILE* Input, int block) {

    char *str[MAXN] = { 0 };
    fori(block) {
        int cnt; fscanf(Input, "%d\n", &cnt);
        forj(cnt) fgets(str, MAXN, Input);
    }

    int cnt;
    fscanf(Input, "%d\n", &cnt);

    int ind = rand() % cnt + 1;
    strcpy(str, "");
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

// do not touch!
int neighbour_value(int value, int delt) {
    return (value + rand() % (2 * delt) - delt);
}

// generates message for city {+}[-]
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
    forecast.count_of_messages++;
}

// generates message for date {+}[-]
void get_message_for_date(FILE* Input) {

    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    char wc = str[0];
    fori(strlen(str)) str[i] = str[i + 1];

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

    insert_string(str, date_str);

    strcpy(forecast.date, str);
    forecast.count_of_messages++;
}

// generates message for horoscope {+}[+]
void get_message_for_horoscope(FILE* Input, FILE* Input_Prognosis) {
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

    char prog[MAXN] = { 0 };
    strcpy(prog, get_random_phrase(Input_Prognosis));
    prog[strlen(prog) - 1] = '\0';

    strcat(str, " ");
    strcat(str, prog);

    strcpy(forecast.horoscope, str);
    forecast.count_of_messages++;
}

// generates message for temperature {+}[-]
void get_message_for_temperature(FILE* Input_day, FILE* Input_night) {

    int block = 0;
    int aver_night = (data.temperature.high_temp_night + data.temperature.low_temp_night) / 2;

    if (aver_night <= -30) block = 0;
    else if (aver_night <= -15) block = 1;
    else if (aver_night <= -5) block = 2;
    else if (aver_night <= 0) block = 3;
    else if (aver_night <= 5) block = 4;
    else if (aver_night <= 10) block = 5;
    else if (aver_night <= 20) block = 6;
    else if (aver_night <= 30) block = 7;
    else block = 8;

    char str_night[MAXN] = { 0 };
    strcpy(str_night, get_random_phrase_for_block(Input_night, block));
    str_night[strlen(str_night) - 1] = '\0';

    char tmp[MAXN] = { 0 };
    strcpy(tmp, insert_number(str_night, data.temperature.low_temp_night));
    strcpy(str_night, tmp);
    strcpy(tmp, "");
    strcpy(tmp, insert_number(str_night, data.temperature.high_temp_night));
    strcpy(str_night, tmp);

    block = 0;
    int aver_day = (data.temperature.high_temp_day + data.temperature.low_temp_day) / 2;

    if (aver_day <= -30) block = 0;
    else if (aver_day <= -15) block = 1;
    else if (aver_day <= -5) block = 2;
    else if (aver_day <= 0) block = 3;
    else if (aver_day <= 5) block = 4;
    else if (aver_day <= 10) block = 5;
    else if (aver_day <= 20) block = 6;
    else if (aver_day <= 30) block = 7;
    else block = 8;

    data_prediction.temperature = data.temperature.high_temp_day;

    char str_day[MAXN] = { 0 };
    strcpy(str_day, get_random_phrase_for_block(Input_day, block));
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
    forecast.count_of_messages++;
}

// generates message for pressure {+}[-]
void get_message_for_pressure(FILE* Input) {

    int block = 0;

    if (data.pressure <= 700) block = 0;
    else if (data.pressure <= 750) block = 1;
    else if (data.pressure <= 770) block = 2;
    else if (data.pressure <= 790) block = 3;
    else block = 4;

    data_prediction.pressure = data.pressure;

    char str[MAXN] = { 0 };

    strcpy(str, get_random_phrase_for_block(Input, block));
    str[strlen(str) - 1] = '\0';

    char tmp[MAXN] = { 0 };
    strcpy(tmp, insert_number(str, data.pressure));
    strcpy(str, tmp);

    strcpy(forecast.pressure, str);
    forecast.count_of_messages++;
}

// generates message for cloudiness {+}[-]
void get_message_for_cloudiness(FILE* Input) {
    int block = 0;

    switch (data.cloudiness) {
        case clear:         { block = 0; break; }
        case shiny:         { block = 1; break; }
        case little_cloudy: { block = 2; break; }
        case cloudy:        { block = 3; break; }
        case rainy:         { block = 4; break; }
    }

    char str[MAXN] = { 0 };

    strcpy(str, get_random_phrase_for_block(Input, block));
    str[strlen(str) - 1] = '\0';
    strcpy(forecast.cloudiness, str);
    forecast.count_of_messages++;
}

// generates message for wind {+}[+][-][-]
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

    int block = 0;

    if (data.wind.velocity <= 3) block = 0;
    else if (data.wind.velocity <= 6) block = 1;
    else if (data.wind.velocity <= 10) block = 2;
    else if (data.wind.velocity <= 24) block = 3;
    else if (data.wind.velocity <= 32) block = 4;
    else block = 5;

    data_prediction.wind = data.wind;

    char str_velocity[MAXN] = { 0 };
    strcpy(str_velocity, get_random_phrase_for_block(Input_velocity, block));
    str_velocity[strlen(str_velocity) - 1] = '\0';

    strcpy(tmp, "");
    strcpy(tmp, insert_number(str_velocity, data.wind.velocity));
    strcpy(str_velocity, tmp);

    block = 0;

    if (data.wind.dash <= 4) block = 0;
    else if (data.wind.dash <= 10) block = 1;
    else if (data.wind.dash <= 20) block = 2;
    else block = 3;

    char str_dash[MAXN] = { 0 };
    strcpy(str_dash, get_random_phrase_for_block(Input_dash, block));
    str_dash[strlen(str_dash) - 1] = '\0';

    strcpy(tmp, "");
    strcpy(tmp, insert_number(str_dash, data.wind.dash));
    strcpy(str_dash, tmp);

    if (data.wind.velocity <= 3 && data.wind.dash >= 4) {
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
    forecast.count_of_messages++;
}

// generates message for precipitation {+}[-]
void get_message_for_precipitation(FILE* Input) {
    int block = 0;

    switch (data.precipitation) {
        case no_precipitation:  { block = 0; break; }
        case rain:              { block = 1; break; }
        case snow:              { block = 2; break; }
        case hail:              { block = 3; break; }
        case acid_rain:         { block = 4; break; }
    }

    char str[MAXN] = { 0 };

    strcpy(str, get_random_phrase_for_block(Input, block));
    str[strlen(str) - 1] = '\0';
    strcpy(forecast.precipitation, str);
    forecast.count_of_messages++;
}

// generates message for phenomena {+}[+]
void get_message_for_phenomena(FILE* Input) {
    int block = 0;

    switch (data.phenomena) {
        case hurricane:     { block = 0; break; }
        case no_phenomena:  { block = 1; break; }
        case tornado:       { block = 2; break; }
        case storm:         { block = 3; break; }
        case naked_ice:     { block = 4; break; }
        case fog:           { block = 5; break; }
        case eruption:      { block = 6; break; }
        case sand_storm:    { block = 7; break; }
        case revolution:    { block = 8; break; }
    }

    char str[MAXN] = { 0 };
    strcpy(str, get_random_phrase_for_block(Input, block));
    str[strlen(str) - 1] = '\0';

    strcpy(forecast.phenomena, str);
    forecast.count_of_messages++;
}

// generates message for jokes {+}[+]
void get_message_for_jokes(FILE* Input_cold, FILE* Input_hot, FILE* Input_wind) {
    char str[MAXN] = { 0 };
    strcat(str, "Шутка дня:\n");

    int flag = 0;

    if (data.temperature.low_temp_day <= -5) {
        strcat(str, get_random_phrase(Input_cold));
        str[strlen(str) - 1] = '\0';
        flag = 1;
    }
    if (data.temperature.high_temp_day > 15) {
        strcat(str, get_random_phrase(Input_hot));
        str[strlen(str) - 1] = '\0';
        flag = 1;
    }

    if (data.wind.dash >= 15) {
        if (flag) strcat(str, "");
        strcat(str, get_random_phrase(Input_wind));
        str[strlen(str) - 1] = '\0';
        flag = 1;
    }

    if (!flag) {
        strcat(str, "Никаких шуток, Россия для грустных.");
    }

    strcpy(forecast.joke, str);
    forecast.count_of_messages++;
}

// generates message for news {+}[+]
void get_message_for_news(FILE* Input) {
    char str[MAXN] = { 0 };
    strcat(str, "Новости дня:\n");
    strcat(str, get_random_phrase(Input));
    strcat(str, get_random_phrase(Input));
    str[strlen(str) - 1] = '\0';

    strcpy(forecast.news, str);
    forecast.count_of_messages++;
}

// generates forecast for 2morrow
void predict_forecast_4_2morrow(FILE *Input_City,
                                FILE* Input_Date, FILE* Input_Horoscope, FILE* Input_Horoscope_Prognosis,
                                FILE *Input_Temp_day, FILE* Input_Temp_night,
                                FILE* Input_Pressure,
                                FILE* Input_Cloudiness,
                                FILE* Input_Wind_direction, FILE* Input_Wind_velocity, FILE* Input_Wind_dash,
                                FILE* Input_Precipitation,
                                FILE* Input_Phenomena,
                                FILE* Input_Jokes_cold, FILE* Input_Jokes_hot, FILE* Input_Jokes_wind,
                                FILE* Input_News,
                                FILE* Input_Prediction) {
    char str[MAXN] = { 0 };
    char tmp[MAXN] = { 0 };
    data.date.day++;
    strcpy(str, "Завтра - ");
    strcat(str, transform_date(nominative));
    strcat(str, ".");
    strcpy(forecast_prediction.date, str);
    forecast_prediction.count_of_messages++;

    //----------------------------------------------------------------//

    strcpy(str, "");
    data_prediction.wind.velocity = abs(neighbour_value(data_prediction.wind.velocity, 7));
    char str_velocity[MAXN] = { 0 };

    strcpy(str_velocity, "Скорость ветра $ на $ м/с и составит $ метров в секунду.");
    strcpy(tmp, "");
    if (data_prediction.wind.velocity > data.wind.velocity)
        strcpy(tmp, insert_string(str_velocity, "повысится"));
    else strcpy(tmp, insert_string(str_velocity, "понизится"));

    strcpy(tmp, insert_number(str_velocity, abs(data_prediction.wind.velocity - data.wind.velocity)));
    strcpy(tmp, insert_number(str_velocity, data_prediction.wind.velocity));
    strcpy(str_velocity, tmp);

    strcpy(str, str_velocity);

    strcpy(forecast_prediction.wind, str);
    forecast_prediction.count_of_messages++;

    //----------------------------------------------------------------//

    strcpy(str, "");
    data_prediction.temperature = neighbour_value(data_prediction.temperature, 7);
    char str_temp[MAXN] = { 0 };

    strcpy(str_temp, "Столбик термометра $ на $°C и остановится на отметке $° Цельсия.");
    strcpy(tmp, "");
    if (data_prediction.temperature > data.temperature.high_temp_day)
        strcpy(tmp, insert_string(str_temp, "поднимется"));
    else strcpy(tmp, insert_string(str_temp, "опустится"));

    strcpy(tmp, insert_number(str_temp, abs(data_prediction.temperature - data.temperature.high_temp_day)));
    strcpy(tmp, insert_number(str_temp, data_prediction.temperature));
    strcpy(str_temp, tmp);
    strcpy(str, str_temp);

    strcpy(forecast_prediction.temperature, str);
    forecast_prediction.count_of_messages++;

    //----------------------------------------------------------------//

    strcpy(str, "");
    data_prediction.pressure = neighbour_value(data_prediction.pressure, 10);
    char str_pressure[MAXN] = { 0 };

    strcpy(str_pressure, "Значение на барометре $ на $. Давление завтра составит $.");
    strcpy(tmp, "");
    if (data_prediction.pressure > data.pressure)
        strcpy(tmp, insert_string(str_pressure, "увеличится"));
    else strcpy(tmp, insert_string(str_pressure, "уменьшится"));

    strcpy(tmp, insert_number(str_pressure, abs(data_prediction.pressure - data.pressure)));
    strcpy(tmp, insert_number(str_pressure, data_prediction.pressure));
    strcpy(str_pressure, tmp);
    strcpy(str, str_pressure);

    strcpy(forecast_prediction.pressure, str);
    forecast_prediction.count_of_messages++;

    //----------------------------------------------------------------//

    strcpy(str, "");

    char all[11][MAXN];
    fori(11) fgets(all[i], MAXN, Input_Prediction);

    if ((data.cloudiness == rainy || data.precipitation == rain) && data.precipitation != acid_rain) {
        int cnt = rand() % 3;
        strcat(str, all[cnt]);
    }

    if (data.precipitation == snow) {
        int cnt = rand() % 3 + 3;
        strcat(str, all[cnt]);
    }

    if (data.cloudiness == clear ||
        data.cloudiness == shiny) {
        int cnt = rand() % 3 + 6;
        strcat(str, all[cnt]);
    }

    if (data.precipitation == acid_rain) {
        int cnt = rand() % 1 + 9;
        strcat(str, all[cnt]);
    }

    if (data.phenomena == revolution) {
        int cnt = rand() % 1 + 10;
        strcat(str, all[cnt]);
    }

    strcpy(forecast_prediction.other, str);
    forecast_prediction.count_of_messages++;
}

// generates whole forecast
void get_forecast(FILE *Input_City,
                  FILE* Input_Date, FILE* Input_Horoscope, FILE* Input_Horoscope_Prognosis,
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

    get_message_for_horoscope(Input_Horoscope, Input_Horoscope_Prognosis);

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
    FILE *Input_Horoscope_Prognosis;
    Input_Horoscope_Prognosis = fopen("Horoscope_Prognosis.txt", "r");
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
    FILE *Input_Prediction;
    Input_Prediction = fopen("Prediction.txt", "r");
#endif
    srand(time(0));
    setlocale(LC_ALL, "Rus");

    input(In);

    get_forecast(Input_City,
                 Input_Date, Input_Horoscope, Input_Horoscope_Prognosis,
                 Input_Temp_day, Input_Temp_night,
                 Input_Pressure,
                 Input_Cloudiness,
                 Input_Wind_direction, Input_Wind_velocity, Input_Wind_dash,
                 Input_Precipitation,
                 Input_Phenomena,
                 Input_Jokes_cold, Input_Jokes_hot, Input_Jokes_wind,
                 Input_News);

    predict_forecast_4_2morrow(Input_City,
                 Input_Date, Input_Horoscope, Input_Horoscope_Prognosis,
                 Input_Temp_day, Input_Temp_night,
                 Input_Pressure,
                 Input_Cloudiness,
                 Input_Wind_direction, Input_Wind_velocity, Input_Wind_dash,
                 Input_Precipitation,
                 Input_Phenomena,
                 Input_Jokes_cold, Input_Jokes_hot, Input_Jokes_wind,
                 Input_News,
                 Input_Prediction);

    output(Out);
    output_prediction(Out);

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
