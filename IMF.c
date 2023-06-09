#include <stdio.h>
#include <stdlib.h>

// Ülke ekonomi yapısı (struct)
typedef struct 
{
    char isim[50];
    int nufus;
    struct 
    {
        float gelir;
        float gider;
    } ekonomi;
} Ulke;

// En zengin ülkeyi bulan fonksiyon
void EnZenginUlke(Ulke ulkeler[], int n) 
{
    float maxGelir = 0;
    int maxIndex = 0;

    for (int i = 0; i < n; i++) 
    {
        float UlkeBasiGelir = (ulkeler[i].ekonomi.gelir - ulkeler[i].ekonomi.gider) / ulkeler[i].nufus;
        if (UlkeBasiGelir > maxGelir) 
        {
            maxGelir = UlkeBasiGelir;
            maxIndex = i;
        }
    }

    printf("Richest country: %s\n", ulkeler[maxIndex].isim);
}

int main() {
    int n = 3; // Ülke sayısı
    Ulke ulkeler[n];

    // Kullanıcıdan ülke bilgilerini alma ve depolama
    for (int i = 0; i < n; i++) 
    {
        printf("Country %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", ulkeler[i].isim);
        printf("Population: ");
        scanf("%d", &ulkeler[i].nufus);
        printf("Income: ");
        scanf("%f", &ulkeler[i].ekonomi.gelir);
        printf("Expense: ");
        scanf("%f", &ulkeler[i].ekonomi.gider);
    }

    // Verilerin dosyaya kaydedilmesi İşlemi
    FILE *file = fopen("ulkeler.txt", "w");
    if (file == NULL) 
    {
        printf("file could not opened!");
        return 1;
    }
    fprintf(file,"Name\tpopulation\tincome\texpense:\n");

    for (int i = 0; i < n; i++) 
    {
        fprintf(file, "%s %d %.2f %.2f\n", ulkeler[i].isim, ulkeler[i].nufus, ulkeler[i].ekonomi.gelir, ulkeler[i].ekonomi.gider);
    }

    fclose(file);

    // En zengin ülkeyi bulma ve görüntüleme
    EnZenginUlke(ulkeler, n);

    return 0;
}
