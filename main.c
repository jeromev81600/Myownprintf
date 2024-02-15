#include <stdarg.h>
#include <stdio.h>

// Définition des fonctions putchar et puts si elles ne sont pas définies
void ft_putchar(char c) {
    putchar(c);
}

void ft_putstr(char *s) {
    puts(s);
}

// La fonction ft_printf simplifiée
void ft_printf(char *fmt, ...) {
    va_list arg;
    va_start(arg, fmt);

    char *s;
    int i;
    char *str;
    int a = 0;

    while (fmt[a]) {
        while (fmt[a] == ' ' || fmt[a] == '\t')
            a++;

        while (fmt[a] != '%') {
            ft_putchar(fmt[a]);
            a++;
        }
        a++;
        if (fmt[a] == 'c') {
            i = va_arg(arg, int);
            ft_putchar(i);
        } else if (fmt[a] == 'd') {
            i = va_arg(arg, int);
            printf("%d", i);
        } else if (fmt[a] == 's') {
            s = va_arg(arg, char *);
            ft_putstr(s);
        }
        a++;
    }
    va_end(arg);
}

// Fonction main pour tester ft_printf
int main() {
float temp_ext=19.564;
    ft_printf("Voici mon %der printf réalisé dans le cadre de \nmon entretien avec la %s .\n Float: %0.2f \n", 1, "Holberton school de Toulouse", temp_ext);
    return 0;
}
