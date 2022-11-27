#include "exp22.h"

int main(){
    int mas1[5][5];
    masGen(mas1);
    masOutput(mas1);
    std::cout << masCheck(mas1) << std::endl;
    return 0;
}
