#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera(float r, float* area, float* volume);
int raizes(float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int*vet);
double avalia(double* poli, int grau, double x);

// 2.1
int main(){
    float r, a, v;
    float* area;
    float* volume;
    
    area = &a;
    volume = &v;
    
    printf("Digite o raio da esfera: ");
    scanf("%f", &r);

    calc_esfera(r, area, volume);
    printf("area: %.2f\nvolume: %.2f", a, v);
    
    return 0;
}

// 2.2
// int main(){
//     float a, b, c, n1, n2;
//     float* x1;
//     float* x2;

//     x1 = &n1;
//     x2 = &n2;

//     printf("Digite os coeficientes: ");
//     scanf("%f %f %f", &a, &b, &c);

//     if(raizes(a, b, c, x1, x2) == 1){ // Se possui raízes
//         printf("x1 = %.2f\nx2 = %.2f", n1, n2);
    
//     } else{
//         printf("Nao ha raizes");
//     }

//     return 0;
// }

// 2.3
// int main(){
//     int n;
//     printf("Insira o tamanho do vetor: ");
//     scanf("%d", &n);

//     int* vet = (int*) malloc(sizeof(int) * n);
//     printf("Insira os elementos do vetor: ");
//     for(int i = 0; i < n; i++){
//         scanf("%d", &vet[i]);
//     }

//     int par = pares(n, vet);
//     printf("Quantidade de pares: %d", par);

//     free(vet);
//     return 0;
// }

// 2.4
// int main(){
//     int n;
//     printf("Insira o tamanho do vetor: ");
//     scanf("%d", &n);

//     int* vet = (int*) malloc(sizeof(int) * n);

//     printf("Insira os elementos do vetor: ");
//     for(int i = 0; i < n; i++){
//         scanf("%d", &vet[i]);
//     }

//     inverte(n, vet);

//     printf("Vetor invertido: ");
//     for(int i = 0; i < n; i++){
//         printf("%d ", vet[i]);
//     }

//     free(vet);
//     return 0;
// }

// 2.5
// int main(){
//     int grau;
//     double x;
//     printf("Insira o grau do polinomio: ");
//     scanf("%d", &grau);

//     double* poli = (double*) malloc(sizeof(double) * (grau + 1));

//     printf("Insira os coeficientes do polinomio (do menor para o maior grau):\n");
//     for(int i = 0; i < grau + 1; i++){
//         scanf("%lf", &poli[i]);
//     }

//     printf("Insira x para avaliar o polinomio: ");
//     scanf("%lf", &x);

//     double result = avalia(poli, grau, x);

//     printf("Polinomio aplicado em x: %.2lf", result);

//     free(poli);
//     return 0;
// }

void calc_esfera(float r, float* area, float* volume){
    *area = 4.0 * M_PI * r * r;
    *volume = (4.0 * M_PI * r * r * r) / 3.0;
}

int raizes(float a, float b, float c, float* x1, float* x2){
    float delta = b * b - 4.0 * a * c;

    if(delta < 0){
        return 0; // Não possui raízes
    }

    *x1 = (-b + sqrt(delta)) / (2.0 * a);
    *x2 = (-b - sqrt(delta)) / (2.0 * a);

    return 1; // Possui raízes
}

int pares(int n, int* vet){
    int par = 0;
    for(int i = 0; i < n; i++){
        if(vet[i] % 2 == 0){
            par++;
        }
    }

    return par;
}

void inverte(int n, int* vet){
    int aux;
    for(int i = 0; i < n / 2; i++){
        aux = vet[i];
        vet[i] = vet[n - 1 - i];
        vet[n - 1 - i] = aux;
    }
}

double avalia(double* poli, int grau, double x){
    double result = poli[0];

    for(int i = 1; i < grau + 1; i++){
        result += poli[i] * pow(x, i);
    }

    return result;
}