#include <stdio.h>
#include <unistd.h>

int animationFinal();
int printVendingMachine();
int printVendingMachineMid();
int printVendingMachineMid2();
int printVendingMachineFinal();
int pressKeyboard();
void screenClear();

// Definición de los estados de la máquina
typedef enum
{
    STATE_0,
    STATE_25,
    STATE_50,
    STATE_75,
    STATE_100,
    STATE_125,
    STATE_150,
    STATE_175,
    STATE_200,
    STATE_225,
    STATE_250,
    STATE_275,
    STATE_300,
    STATE_325,
    STATE_350,
    STATE_375,
    STATE_400,
    STATE_425,
    STATE_450,
    STATE_475
} State;

// Declaración de la función process_input
void process_input(State *state, float input);
float state_to_value(State state);

int main()
{
    State state = STATE_0;
    float input;

    printVendingMachine();
    pressKeyboard();

    while (state != STATE_400 && state != STATE_425 && state != STATE_450 && state != STATE_475)
    {
        screenClear();
        printVendingMachine();
        printf("               Dinero ingresado: $%.2f\n", state_to_value(state));
        printf("               Ingrese una moneda ($0.25, $0.50, $1.00): ");
        scanf("%f", &input);

        if (input != 0.25 && input != 0.50 && input != 1.00)
        {
            printf("Por favor ingrese solamente $0.25, $0.50, or $1.00.\n");
            continue;
        }

        process_input(&state, input);
    }

    printf("               Dinero ingresado: $%.2f\n", state_to_value(state));
    printf("               Transaccion completa.\n");

    animationFinal();

    return 0;
}

// Definición de la función process_input
void process_input(State *state, float input)
{
    switch (*state)
    {
    case STATE_0:
        if (input == 0.25)
            *state = STATE_25;
        else if (input == 0.50)
            *state = STATE_50;
        else if (input == 1.00)
            *state = STATE_100;
        break;
    case STATE_25:
        if (input == 0.25)
            *state = STATE_50;
        else if (input == 0.50)
            *state = STATE_75;
        else if (input == 1.00)
            *state = STATE_125;
        break;
    case STATE_50:
        if (input == 0.25)
            *state = STATE_75;
        else if (input == 0.50)
            *state = STATE_100;
        else if (input == 1.00)
            *state = STATE_150;
        break;
    case STATE_75:
        if (input == 0.25)
            *state = STATE_100;
        else if (input == 0.50)
            *state = STATE_125;
        else if (input == 1.00)
            *state = STATE_175;
        break;
    case STATE_100:
        if (input == 0.25)
            *state = STATE_125;
        else if (input == 0.50)
            *state = STATE_150;
        else if (input == 1.00)
            *state = STATE_200;
        break;
    case STATE_125:
        if (input == 0.25)
            *state = STATE_150;
        else if (input == 0.50)
            *state = STATE_175;
        else if (input == 1.00)
            *state = STATE_225;
        break;
    case STATE_150:
        if (input == 0.25)
            *state = STATE_175;
        else if (input == 0.50)
            *state = STATE_200;
        else if (input == 1.00)
            *state = STATE_250;
        break;
    case STATE_175:
        if (input == 0.25)
            *state = STATE_200;
        else if (input == 0.50)
            *state = STATE_225;
        else if (input == 1.00)
            *state = STATE_275;
        break;
    case STATE_200:
        if (input == 0.25)
            *state = STATE_225;
        else if (input == 0.50)
            *state = STATE_250;
        else if (input == 1.00)
            *state = STATE_300;
        break;
    case STATE_225:
        if (input == 0.25)
            *state = STATE_250;
        else if (input == 0.50)
            *state = STATE_275;
        else if (input == 1.00)
            *state = STATE_325;
        break;
    case STATE_250:
        if (input == 0.25)
            *state = STATE_275;
        else if (input == 0.50)
            *state = STATE_300;
        else if (input == 1.00)
            *state = STATE_350;
        break;
    case STATE_275:
        if (input == 0.25)
            *state = STATE_300;
        else if (input == 0.50)
            *state = STATE_325;
        else if (input == 1.00)
            *state = STATE_375;
        break;
    case STATE_300:
        if (input == 0.25)
            *state = STATE_325;
        else if (input == 0.50)
            *state = STATE_350;
        else if (input == 1.00)
            *state = STATE_400;
        break;
    case STATE_325:
        if (input == 0.25)
            *state = STATE_350;
        else if (input == 0.50)
            *state = STATE_375;
        else if (input == 1.00)
            *state = STATE_425;
        break;
    case STATE_350:
        if (input == 0.25)
            *state = STATE_375;
        else if (input == 0.50)
            *state = STATE_400;
        else if (input == 1.00)
            *state = STATE_450;
        break;
    case STATE_375:
        if (input == 0.25)
            *state = STATE_400;
        else if (input == 0.50)
            *state = STATE_425;
        else if (input == 1.00)
            *state = STATE_475;
        break;
    case STATE_400:
    case STATE_425:
    case STATE_450:
    case STATE_475:
        printf("Product dispensed\n");
        break;
    }
}

int animationFinal() // Simplemente hace la impresión de la animación final cuando la bebida está suelta
{
    sleep(1);
    screenClear();
    printVendingMachineMid();
    sleep(1);
    screenClear();
    printVendingMachineMid2();
    sleep(1);
    screenClear();
    printVendingMachineFinal();
    printf("               Bebida dispensada!\n");
}

// Definición de la función state_to_value
float state_to_value(State state)
{
    switch (state)
    {
    case STATE_0:
        return 0.00;
    case STATE_25:
        return 0.25;
    case STATE_50:
        return 0.50;
    case STATE_75:
        return 0.75;
    case STATE_100:
        return 1.00;
    case STATE_125:
        return 1.25;
    case STATE_150:
        return 1.50;
    case STATE_175:
        return 1.75;
    case STATE_200:
        return 2.00;
    case STATE_225:
        return 2.25;
    case STATE_250:
        return 2.50;
    case STATE_275:
        return 2.75;
    case STATE_300:
        return 3.00;
    case STATE_325:
        return 3.25;
    case STATE_350:
        return 3.50;
    case STATE_375:
        return 3.75;
    case STATE_400:
        return 4.00;
    case STATE_425:
        return 4.25;
    case STATE_450:
        return 4.50;
    case STATE_475:
        return 4.75;
    default:
        return 0.00;
    }
}

int pressKeyboard() // Primera impresión para confirmar estar en el "juego"
{
    printf("               Deberia comprar una bebida de $4?:\n               Presione cualquier tecla para continuar");
    char buf[5];
    scanf("%c", buf);
    return 0;
}

void screenClear() // Limpieza de pantalla
{
    printf("\033[H\033[J");
}

int printVendingMachine()
{
    printf("                _______________________________________\n");
    printf("               |                                       |\n");
    printf("               |    _______________________________    |\n");
    printf("               |   |                               |   |\n");
    printf("               |   |            VENDING            |   |\n");
    printf("               |   |            MACHINE            |   |\n");
    printf("               |   |_______________________________|   |\n");
    printf("               |                                       |\n");
    printf("               |   __    __    __    __    __    __    |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |                                       |\n");
    printf("               |   _________________________________   |\n");
    printf("               |  |     ___________                 |  |\n");
    printf("               |  |    |           |                |  |\n");
    printf("               |  |    |           |                |  |\n");
    printf("               |  |    |___________|                |  |\n");
    printf("               |  |_________________________________|  |\n");
    printf("               |                                       |\n");
    printf("               |   _________________________________   |\n");
    printf("               |  |    __                           |  |\n");
    printf("               |  |    ||     INSERT COIN           |  |\n");
    printf("               |  |_________________________________|  |\n");
    printf("               |_______________________________________|\n");
    return 0;
}

int printVendingMachineMid()
{
    printf("                _______________________________________\n");
    printf("               |                                       |\n");
    printf("               |    _______________________________    |\n");
    printf("               |   |                               |   |\n");
    printf("               |   |            VENDING            |   |\n");
    printf("               |   |            MACHINE            |   |\n");
    printf("               |   |_______________________________|   |\n");
    printf("               |                                       |\n");
    printf("               |   __    __    __    __    __    __    |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |                                       |\n");
    printf("               |   _________________________________   |\n");
    printf("               |  |     ___________                 |  |\n");
    printf("               |  |    |███████████|                |  |\n");
    printf("               |  |    |           |                |  |\n");
    printf("               |  |    |___________|                |  |\n");
    printf("               |  |_________________________________|  |\n");
    printf("               |                                       |\n");
    printf("               |   _________________________________   |\n");
    printf("               |  |    __                           |  |\n");
    printf("               |  |    ||     INSERT COIN           |  |\n");
    printf("               |  |_________________________________|  |\n");
    printf("               |_______________________________________|\n");
    return 0;
}

int printVendingMachineMid2()
{
    printf("                _______________________________________\n");
    printf("               |                                       |\n");
    printf("               |    _______________________________    |\n");
    printf("               |   |                               |   |\n");
    printf("               |   |            VENDING            |   |\n");
    printf("               |   |            MACHINE            |   |\n");
    printf("               |   |_______________________________|   |\n");
    printf("               |                                       |\n");
    printf("               |   __    __    __    __    __    __    |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |                                       |\n");
    printf("               |   _________________________________   |\n");
    printf("               |  |     ___________                 |  |\n");
    printf("               |  |    |██D█SODA███|                |  |\n");
    printf("               |  |    |███████████|                |  |\n");
    printf("               |  |    |___________|                |  |\n");
    printf("               |  |_________________________________|  |\n");
    printf("               |                                       |\n");
    printf("               |   _________________________________   |\n");
    printf("               |  |    __                           |  |\n");
    printf("               |  |    ||     INSERT COIN           |  |\n");
    printf("               |  |_________________________________|  |\n");
    printf("               |_______________________________________|\n");
    return 0;
}

int printVendingMachineFinal() // Estado final
{
    printf("                _______________________________________\n");
    printf("               |                                       |\n");
    printf("               |    _______________________________    |\n");
    printf("               |   |                               |   |\n");
    printf("               |   |            VENDING            |   |\n");
    printf("               |   |            MACHINE            |   |\n");
    printf("               |   |_______________________________|   |\n");
    printf("               |                                       |\n");
    printf("               |   __    __    __    __    __    __    |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |  |__|  |__|  |__|  |__|  |__|  |__|   |\n");
    printf("               |                                       |\n");
    printf("               |   _________________________________   |\n");
    printf("               |  |     ___________                 |  |\n");
    printf("               |  |    |███████████|                |  |\n");
    printf("               |  |    |██D█SODA███|                |  |\n");
    printf("               |  |    |███████████|                |  |\n");
    printf("               |  |_________________________________|  |\n");
    printf("               |                                       |\n");
    printf("               |   _________________________________   |\n");
    printf("               |  |    __                           |  |\n");
    printf("               |  |    ||     INSERT COIN           |  |\n");
    printf("               |  |_________________________________|  |\n");
    printf("               |_______________________________________|\n");
    return 0;
}