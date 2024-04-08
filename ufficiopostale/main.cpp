#include <istream>
#include "coda.cpp"
using namespace std;

int main() {
    UfficioPostale up = UfficioPostale("Saliceto");
    up.NuovoCliente('r');
    up.NuovoCliente('s');
    up.NuovoCliente('r');
    up.NuovoCliente('r');
    up.NuovoCliente('f');
    up.NuovoCliente('f');
    up.ChiamaCliente('s');
    up.NuovoCliente('r');
    up.NuovoCliente('r');
    up.NuovoCliente('r');
    up.ChiamaCliente('f');
}