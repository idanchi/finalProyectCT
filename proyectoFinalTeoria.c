#include <stdio.h>
#include <unistd.h>

int animationFinal();
int printVendingMachine();
int printVendingMachineMid();
int printVendingMachineMid2();
int printVendingMachineFinal();
int pressKeyboard();
void screenClear();
float selectSoda(float *soda);
float selectCoin(float *monedaIngreso);

int main()
{
    float soda, monedaIngreso;

    // Primera impresión de la vending machine
    printVendingMachine();
    pressKeyboard();
    screenClear();

    // Selección de la bebida
    printVendingMachine();
    selectSoda(&soda);
    screenClear();

    // Automata implementado de forma básica con un do while
    float suma = 0;
    float cambio = 0;
    do
    {
        screenClear();
        printVendingMachine();
        printf("               Monto acumulado: %.2f\n", suma);
        printf("               Precio de la bebida seleccionada: %.2f\n", soda);
        selectCoin(&monedaIngreso);
        suma += monedaIngreso;

        printf("               Monto acumulado: %.2f\n", suma);
    } while (suma < soda);

    cambio = suma - soda;

    if (cambio != 0.00)
    {
        printf("               Su cambio sería: %.2f\n", cambio);
    }

    animationFinal();

    return 0;
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

float selectCoin(float *monedaIngreso) // Selección de monedas
{
    int aux;
    printf("               Ingrese una moneda:\n");
    printf("               1:            0.25$\n");
    printf("               2:            0.50$\n");
    printf("               3:            1.00$\n");
    printf("              : ");

    scanf("%d", &aux);
    if (aux == 1)
    {
        *monedaIngreso = 0.25;
    }
    else if (aux == 2)
    {
        *monedaIngreso = 0.50;
    }
    else if (aux == 3)
    {
        *monedaIngreso = 1.00;
    }
    else
    {
        printf("Selección no válida. Intente nuevamente.\n");
        *monedaIngreso = 0.0; // Si la selección es inválida, no se agrega nada.
    }
    return *monedaIngreso;
}

float selectSoda(float *soda) // Selección de soda
{
    int aux;
    printf("               Seleccione su bebida ingresando el número:\n");
    printf("               1: CocaCola      2$\n");
    printf("               2: Fresca        2$\n");
    printf("               3: Agua          1$\n");
    printf("               4: Cerveza       3$\n");
    printf("              : ");

    scanf("%d", &aux);
    if (aux == 1 || aux == 2)
    {
        *soda = 2.0;
    }
    else if (aux == 3)
    {
        *soda = 1.0;
    }
    else if (aux == 4)
    {
        *soda = 3.0;
    }
    else
    {
        printf("Selección no válida. Intente nuevamente.\n");
        *soda = 0.0; // Si la selección es inválida, no se establece ningún precio.
    }
    return *soda;
}

int pressKeyboard() // Primera impresión para confirmar estar en el "juego"
{
    printf("               Deberia comprar una bebida?:\n               Presione cualquier tecla para continuar");
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

int printVendingMachineFinal()
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