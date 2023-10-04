#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iso646.h>
#include <windows.h>

typedef char* String;
typedef const char* Const_String;
typedef enum Boolean{
    False = 0,
    True = 1
}Boolean;

#define null ""
#define echo printf
#define PRINT printf
#define Begin {	
#define end }
#define Init main
#define Word char

#define OUTPUT(value) \
    _Generic((value), \
        int: printf("%d",&value), \
        float: printf("%f",&value), \
        double: printf("%lf",&value), \
        char*: printf("%s", value), \
        const char*: printf("%s", value), \
        default: printf("Unknown")\
    )

#define INPUT(value) \
    _Generic((value), \
        int:  scanf("%d",&value), \
        float: scanf("%f",&value), \
        double: scanf("%lf",&value), \
        char*: scanf("%s",value = (char*)malloc(255 * sizeof(char))), \
        default: PRINT("Unknown type") \
    )


#define Var(value) \
    _Generic((value), \
        int: "int", \
        float: "float", \
        double: "double", \
        char*: "char*", \
        const char*: "const char*", \
        default: "Unknown" \
    )
    
typedef enum Week {
    Sunday = 1,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
} Week;

 // Função auxiliar para imprimir o dia da semana
void printWeekday(Week weekday) {
    switch (weekday) {
        case Sunday:
            printf("Sunday\n");
            break;
        case Monday:
            printf("Monday\n");
            break;
        case Tuesday:
            printf("Tuesday\n");
            break;
        case Wednesday:
            printf("Wednesday\n");
            break;
        case Thursday:
            printf("Thursday\n");
            break;
        case Friday:
            printf("Friday\n");
            break;
        case Saturday:
            printf("Saturday\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

typedef enum Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
} Months;

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

// Função para criar uma data
Date createDate(int day, int month, int year) {
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

// Função para comparar duas datas
int compareDates(Date date1, Date date2) {
    if (date1.year < date2.year)
        return -1;
    else if (date1.year > date2.year)
        return 1;

    if (date1.month < date2.month)
        return -1;
    else if (date1.month > date2.month)
        return 1;

    if (date1.day < date2.day)
        return -1;
    else if (date1.day > date2.day)
        return 1;

    return 0;
}

// Função para verificar se um ano é bissexto
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

// Função para adicionar dias a uma data
Date addDays(Date date, int days) {
    int daysInMonth;

    while (days > 0) {
        daysInMonth = getDaysInMonth(date.month, date.year);

        if (date.day + days <= daysInMonth) {
            date.day += days;
            days = 0;
        } else {
            days -= (daysInMonth - date.day + 1);
            date.day = 1;

            if (date.month == December) {
                date.month = January;
                date.year++;
            } else {
                date.month++;
            }
        }
    }

    return date;
}

// Função para subtrair dias de uma data
Date subtractDays(Date date, int days) {
    while (days > 0) {
        if (date.day - days >= 1) {
            date.day -= days;
            days = 0;
        } else {
            days -= date.day;
            if (date.month == January) {
                date.month = December;
                date.year--;
            } else {
                date.month--;
            }
            date.day = getDaysInMonth(date.month, date.year);
        }
    }

    return date;
}

// Função para obter o dia da semana de uma data
Week getWeekday(Date date) {
    int dayOfWeek;

    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + 12 * a - 2;
    dayOfWeek = (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

    // Ajuste para retornar o valor correto da enumeração Week
    if (dayOfWeek == 0)
        return Sunday;
    else
        return (Week)dayOfWeek;
}

// Função para obter o número do dia no ano
int getDayOfYear(Date date) {
    int days = date.day;
    for (int i = 1; i < date.month; i++) {
        days += getDaysInMonth(i, date.year);
    }
    return days;
}

// Função para obter o número de dias em um mês
int getDaysInMonth(int month, int year) {
    switch (month) {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            return 31;
        case April:
        case June:
        case September:
        case November:
            return 30;
        case February:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

#ifdef CLOVE_WINDOWS_MODE
    #define GRAPHICS_MODE_WARNING \
        _Pragma("message(\"Warning: You are using a graphics function. Consider compiling with -mwindows flag.\")")
#else
    #define GRAPHICS_MODE_WARNING
#endif


void showMessageDialog(const char *message) {
	GRAPHICS_MODE_WARNING
    MessageBox(NULL, message, "Message Dialog", MB_OK | MB_ICONINFORMATION);
}

int showOptionDialog(const char *message) {
	GRAPHICS_MODE_WARNING
    int choice = MessageBox(NULL, message, "Option Dialog", MB_OKCANCEL | MB_ICONQUESTION);

    // Retorna 1 para OK, 2 para Cancel
    return choice == IDOK ? 1 : 2;
}

#define ID_EDIT 101
#define ID_OK   102

HWND hEdit;
char* userInput;  // Variável global para armazenar o input do usuário

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, 
                                   10, 10, 200, 20, hwnd, (HMENU)ID_EDIT, GetModuleHandle(NULL), NULL);
            CreateWindow("BUTTON", "OK", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         10, 40, 50, 20, hwnd, (HMENU)ID_OK, GetModuleHandle(NULL), NULL);
            break;
        }
        case WM_COMMAND: {
            if (LOWORD(wParam) == ID_OK) {
                char buffer[256];
                GetWindowText(hEdit, buffer, sizeof(buffer));
                userInput = malloc(strlen(buffer) + 1);
                strcpy(userInput, buffer);
                DestroyWindow(hwnd);  // Fecha a janela ao pressionar OK
            }
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

char* inputDialog(const char *input, int width, int height) {
    GRAPHICS_MODE_WARNING;
    userInput = NULL;  // Inicializa a variável global

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "MyClass";

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, "MyClass", input, WS_OVERLAPPEDWINDOW, 
                               CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                               NULL, NULL, GetModuleHandle(NULL), NULL);

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return userInput;
}
  
// Função genérica para converter um valor para uma string
String valueToString(const void *value, const char *format) {
    char buffer[256];
    String result = NULL;

    if (strcmp(format, "Integer") == 0) {
        snprintf(buffer, sizeof(buffer), "%d", *(const int*)value);
    } else if (strcmp(format, "Float") == 0) {
        snprintf(buffer, sizeof(buffer), "%f", *(const float*)value);
    } else if (strcmp(format, "Double") == 0) {
        snprintf(buffer, sizeof(buffer), "%lf", *(const double*)value);
    } else if (strcmp(format, "String") == 0) {
        const char *stringValue = (const char*)value;
        snprintf(buffer, sizeof(buffer), "%s", stringValue);
    } else {
        // Formato desconhecido
        PRINT("Unknown format");
        return NULL;
    }

    result = malloc(strlen(buffer) + 1);
    if (result != NULL) {
        strcpy(result, buffer);
    } else {
        PRINT("Memory allocation failed");
    }

    return result;
}

// Função genérica para exibir os resultados em um showMessageDialog
void showResultsDialog(const void *results, int size, size_t elementSize, const char *format) {
    String message = malloc(1);  // String vazia
    if (message == NULL) {
        PRINT("Memory allocation failed");
        return;
    }
    message[0] = '\0';

    // Concatenar os resultados na mensagem
    for (int i = 0; i < size; ++i) {
        String valueString = valueToString((const char*)results + i * elementSize, format);
        if (valueString != NULL) {
            message = realloc(message, strlen(message) + strlen(valueString) + 2);  // +2 para a vírgula e espaço
            strcat(message, valueString);
            if (i < size - 1) {
                strcat(message, ",");
            }
            free(valueString);
        } else {
            // Falha na conversão para string
            PRINT("Conversion to string failed");
            free(message);
            return;
        }
    }

    showMessageDialog(message);

    free(message);
}
/*

void createButton(HWND hwnd){
	// Criar um botão
    CreateWindow("BUTTON", "Click me", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 40, 100, 20, hwnd, NULL, NULL, NULL);
}
void createLabelControls(HWND hwnd) {
    // Criar uma label
    CreateWindow("STATIC", "Hello, World!", WS_VISIBLE | WS_CHILD, 10, 10, 100, 20, hwnd, NULL, NULL, NULL);

}
*/
