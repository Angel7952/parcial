#include <iostream>

using namespace std;

int main() {
    int danoBase, armadura, tipoBala;

    cout << "Ingrese el daño base: ";
    cin >> danoBase;
    
    cout << "Ingrese la armadura del objetivo: ";
    cin >> armadura;

    cout << "Ingrese el tipo de bala (1 = Normal, 2 = Perforante, 3 = Explosiva): ";
    cin >> tipoBala;

    float danoFinal = danoBase;

    string nombreBala;
    if (tipoBala == 1) {
        nombreBala = "Bala normal";
    } else if (tipoBala == 2) {
        nombreBala = "Bala perforante";
    } else if (tipoBala == 3) {
        nombreBala = "Bala explosiva";
    } else {
        cout << "Error: Tipo de bala inválido." << endl;
        return 1; 
    }

    cout << "Tipo de bala seleccionada: " << nombreBala << endl;
    
    if (tipoBala == 1) { 
        danoFinal -= armadura;
    } else if (tipoBala == 2) { 
        danoFinal -= armadura / 2;
    } else if (tipoBala == 3) { 
        danoFinal = danoBase * 2 - armadura;
    }

    if (danoFinal < 0) {
        danoFinal = 0;
    }

    bool esCritico = false;
    if (danoBase > 50) {
        if (armadura < 20) {
            esCritico = true;
        }
    }

    if (esCritico) {
        danoFinal *= 2; 
        if (danoFinal > 100) {
            danoFinal = 100; 
        }
    }
    
    if (esCritico) {
        cout << "¡GOLPE CRÍTICO!" << endl;
    }
    cout << "Daño recibido: " << danoFinal << ".00" << endl;

    return 0;
}