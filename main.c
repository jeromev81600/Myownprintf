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
    double f;
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
        } else if (fmt[a] == 'f') {
            f = va_arg(arg, double); // Utilisez va_arg pour récupérer l'argument de type double
            printf("%f", f);
        }
        a++;
    }
    va_end(arg);
}

// Fonction main pour tester ft_printf
int main() {
float temp_ext=19.564;
    ft_printf("Bonjour, il fait %f degrés, j'ai créé mon %der printf \n dans le cadre de mon entretien avec la %s .\n", temp_ext, 1, "Holberton school de Toulouse");
    return 0;
}
