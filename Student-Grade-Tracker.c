#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void addRegistry(); //Kayit ekleme fonksiyonu.
void listRegistry(); // Ogrenci bilgilerini listeleme fonksiyonu.
void Grade(); // Basari notu hesaplama fonksiyonu.
void listGrade(); // Basari notu listeleme fonksiyonu. (Siralanmamis hali ile.)
void letterGrade() ; //Harf notu hesaplama fonksiyonu.
void passFail(); // Gecti - Kaldi - Sartli Gecti denetimi yapan fonskiyon.
void sortGrades(); // Notlari siralama fonksiyonu. (Yuksekten dusuge dogru.)
void statistics(); // Istatistik hesaplama fonskiyonu.
void abbreviation(); // Soyad kisaltma fonksiyonu.


// Ogrenci bilgilerini toplu bir sekilde saklamak icin struct yapisi kullanildi.
struct Student {
    double midterm1; // 1. Midterm notlarinin saklandigi degisken.
    double midterm2; // 2. Midterm notlarinin saklandigi degisken.
    double final; // Final notlarinin saklandigi degisken.
    double Grade; // Basari notlarinin saklandigi degisken.
    char name[10]; // Ogrenci isimlerinin saklandigi degisken.
    char surname[10]; // Ogrenci soyadlarinin saklandigi degisken.
    char abvSurname[10]; //abvSurname: Abbreviated Surname. "abbreviation" adli fonskiyon ile ilk harfleri alinip yanina nokta eklenerek kisaltilan soyadlar bu degisken icerisinde saklanir.
    char letterGrade[10]; // Harf notlarinin saklandigi degisken.
    char passFail[10]; // Gecti - Kaldi - Sartli Gecti durumlarinin saklandigi degisken.
}s[10];

#define length 10 // Ogrenci sayisi belirlemek icin #define yapisi kullanildi.
int registryStatus = 0; // Kayit surecini tekrar baslatmamak ve kayit durumunu kontrol edebilmek icin yaratilmis degisken.

int main() {
    int operator = 0;
    printf("\nMENU\n1 - Add Registry\n2 - List Registry\n3 - Calculate Grades\n4 - Sort Grades\n5 - Statistics\n6 - Exit\n");


    while (operator < 6){ // Menudeki islemlerin tekrarlanabilmesi icin 6 dan kucuk olma sarti saglanmali.

        while (operator != 1 && operator != 6){
                printf("\nChoose an operation: ");
                scanf(" %d", &operator);
                if (operator == 1){ // Ilk secilen operator 1 ise diger donguye gecer, degil ise uyari mesaji verir.
                    break;
                } else {
                    printf("Please select the 1st operator to add registry first!\n");
                }
        }

        while (operator < 6){
            if (operator == 1){
                if (registryStatus == length){ // Istenen ogrenci sayisi kadar kayit alindiysa uyari verir.
                    printf("You already entered registries!\n");
                    printf("\nChoose an operation: ");
                    scanf(" %d", &operator);
                } else { // Kayit kapasitesi dolmadiysa kayit alma fonksiyonuna gecilir.
                    printf("\n --(0_0)-- --(0o0)-- --(^-^)-- |Add Registry| --(0_0)-- --(0o0)-- --(^-^)-- \n");
                    addRegistry();
                    printf("\nMENU\n1 - Add Registry\n2 - List Registry\n3 - Calculate Grades\n4 - Sort Grades\n5 - Statistics\n6 - Exit\n");
                    printf("\nChoose an operation: ");
                    scanf(" %d", &operator);
                }
                while (operator == 1){ // Kayit alindiktan sonra tekrar kayit alma islemi secilirse uyari verir.
                    printf("You already entered registries!\n");
                    printf("\nChoose an operation: ");
                    scanf(" %d", &operator);
                }
                while (operator != 2 && operator != 6 && operator < 6){ // Kayit almadan sonra listelenmezse uyari verir. (if (operator == 1) sartinin alt katmanina yerlestirilerek 1 den sonra 2 ye basma sarti saglandi.)
                        printf("Please select 2nd operator to list the registry first!\n");
                        printf("\nChoose an operation: ");
                        scanf(" %d", &operator);
                }
                while (operator == 2){
                    printf("\n --(0_0)-- --(0o0)-- --(^-^)-- |List Registry| --(0_0)-- --(0o0)-- --(^-^)-- \n");
                    Grade();
                    letterGrade();
                    abbreviation();
                    passFail();
                    listRegistry();
                    printf("\nMENU\n1 - Add Registry\n2 - List Registry\n3 - Calculate Grades\n4 - Sort Grades\n5 - Statistics\n6 - Exit\n");
                    printf("\nChoose an operation: ");
                    scanf(" %d", &operator);
                }
                }
        // 1 isleminden sonra 2 ye gecilme sarti saglandiktan sonra fonksiyonlar arasi ozgurce gecis saglanir.
        while (operator == 2){
                printf("\n --(0_0)-- --(0o0)-- --(^-^)-- |List Registry| --(0_0)-- --(0o0)-- --(^-^)-- \n");
                Grade();
                letterGrade();
                abbreviation();
                passFail();
                listRegistry();
                printf("\nMENU\n1 - Add Registry\n2 - List Registry\n3 - Calculate Grades\n4 - Sort Grades\n5 - Statistics\n6 - Exit\n");
                printf("\nChoose an operation: ");
                scanf(" %d", &operator);
        }
        while (operator == 3){
                printf("\n --(0_0)-- --(0o0)-- --(^-^)-- |Calculate Grades| --(0_0)-- --(0o0)-- --(^-^)-- \n");
                Grade();
                letterGrade();
                abbreviation();
                listGrade();
                printf("\nMENU\n1 - Add Registry\n2 - List Registry\n3 - Calculate Grades\n4 - Sort Grades\n5 - Statistics\n6 - Exit\n");
                printf("\nChoose an operation: ");
                scanf(" %d", &operator);
        }
        while (operator == 4){
                printf("\n --(0_0)-- --(0o0)-- --(^-^)-- |Sort Grades| --(0_0)-- --(0o0)-- --(^-^)-- \n");
                Grade();
                letterGrade();
                passFail();
                sortGrades();
                abbreviation();
                listRegistry();
                printf("\nMENU\n1 - Add Registry\n2 - List Registry\n3 - Calculate Grades\n4 - Sort Grades\n5 - Statistics\n6 - Exit\n");
                printf("\nChoose an operation: ");
                scanf(" %d", &operator);
        }
        while (operator == 5){
                printf("\n --(0_0)-- --(0o0)-- --(^-^)-- |Statistics| --(0_0)-- --(0o0)-- --(^-^)-- \n");
                Grade();
                statistics();
                printf("\nMENU\n1 - Add Registry\n2 - List Registry\n3 - Calculate Grades\n4 - Sort Grades\n5 - Statistics\n6 - Exit\n");
                printf("\nChoose an operation: ");
                scanf(" %d", &operator);
        }
        while (operator > 6 || operator < 0){ // Eger menudeki operatorlerden farkli bir sayi girilirse uyari verir.
            printf("Please select an operator in range of 1 - 6!\n");
            printf("\nChoose an operation: ");
            scanf(" %d", &operator);
            }
        }
    }
    if (operator == 6){
        exit(0);
    }

    return 0;
}
//Kayit ekleme fonksiyonu.
void addRegistry() {

    int i;
    for (i = 0; i < length; i++){

        printf("\nName: ");
        scanf(" %s", s[i].name);

        printf("Surname: ");
        scanf(" %s", s[i].surname);

        printf("1st Midterm, 2nd Midterm, Final: ");
        scanf("%lf %lf %lf", &s[i].midterm1, &s[i].midterm2, &s[i].final);

        registryStatus++; // Kayit surecini tekrar baslatmamak ve kayit durumunu kontrol edebilmek icin yaratilmis degisken.

        while (s[i].midterm1 > 100 || s[i].midterm2 > 100 || s[i].final > 100 || s[i].midterm1 < 0 || s[i].midterm2 < 0 || s[i].final < 0){ // Notlar istenen deger araligi (0 - 100) disinda ise degerlerin terkar girilmesi istenir.
            printf("\nPlease enter grades in range of 0 - 100.\n");
            printf("1st Midterm, 2nd Midterm, Final: ");
            scanf("%lf %lf %lf", &s[i].midterm1, &s[i].midterm2, &s[i].final);
        }
    }
    printf("\nClass size is full!\n");

}

// Ogrenci bilgilerini listeleme fonksiyonu.
void listRegistry() {
    char name[10] = "Name";
    char surname[10] = "Surname";
    char Midterm1[15] = "1st Midterm";
    char Midterm2[15] = "2nd Midterm";
    char Final[10] = "Final";
    char grade[10] = "Grade";
    char letterG[10] = "Letter G.";
    char status[10] = "Status";

    printf("\n%-10s%-15s%-15s%-15s%-15s%-15s%-14s%-15s\n", name, surname, Midterm1, Midterm2, Final, grade, letterG, status);

    int i;
    for (i = 0; i < length; i++){
        printf("%-10s%-15.2s%-15.0lf%-15.0lf%-15.0lf%-15.0lf%-14s%-15s\n", s[i].name, s[i].abvSurname, s[i].midterm1, s[i].midterm2, s[i].final, s[i].Grade, s[i].letterGrade, s[i].passFail);
    }
}

// Basari notu hesaplama fonksiyonu.
void Grade() {

    double mid1Grade; // Son 1. midterm degeri. (%20'si alindi.)
    double mid2Grade; // Son 2. midterm degeri. (%30'u alindi.)
    double finGrade; // Son final degeri. (%50'si alindi.)


    int i;
    for (i = 0; i < length; i++){

        mid1Grade = (s[i].midterm1 * 20) / 100;
        mid2Grade = (s[i].midterm2 * 30) / 100;
        finGrade = (s[i].final * 50) / 100;
        s[i].Grade = round(mid1Grade + mid2Grade + finGrade); // Butun notlar toplanarak structure yapisindaki notlar degiskeninde saklandi.
    }

}

// Basari notu listeleme fonksiyonu. (Siralanmamis hali ile.)
void listGrade(){
    char name[10] = "Name";
    char surname[10] = "Surname";
    char grade[10] = "Grade";

    printf("\n%-10s %-15s %-15s\n", name, surname, grade);

    int i;
    for (i = 0; i < length; i++){
        printf("%-10s %-15.2s %-15.0lf\n", s[i].name, s[i].abvSurname, s[i].Grade);
    }
}

//Harf notu hesaplama fonksiyonu.
void letterGrade(){

    int i, j;
    char gradeTypes[9][2] = {"AA", "BA", "BB", "CB", "CC", "DC", "DD", "FD", "FF"};

    for (i = 0; i < length; i++){
        for (j = 0; j < 2; j++) {
            if (s[i].Grade <= 100 && s[i].Grade >= 90){
                s[i].letterGrade[j] = gradeTypes[0][j];
            }
            if (s[i].Grade <= 89 && s[i].Grade >= 85){
                s[i].letterGrade[j] = gradeTypes[1][j];
            }
            if (s[i].Grade <= 84 && s[i].Grade >= 80){
                s[i].letterGrade[j] = gradeTypes[2][j];
            }
            if (s[i].Grade <= 79 && s[i].Grade >= 75){
                s[i].letterGrade[j] = gradeTypes[3][j];
            }
            if (s[i].Grade <= 74 && s[i].Grade >= 70){
                s[i].letterGrade[j] = gradeTypes[4][j];
            }
            if (s[i].Grade <= 69 && s[i].Grade >= 56){
                s[i].letterGrade[j] = gradeTypes[5][j];
            }
            if (s[i].Grade <= 64 && s[i].Grade >= 60){
                s[i].letterGrade[j] = gradeTypes[6][j];
            }
            if (s[i].Grade <= 59 && s[i].Grade >= 50){
                s[i].letterGrade[j] = gradeTypes[7][j];
            }
            if (s[i].Grade <= 49 && s[i].Grade >= 0){
                s[i].letterGrade[j] = gradeTypes[8][j];
            }
        }
    }
}

// Gecti - Kaldi - Sartli Gecti denetimi yapilir.
void passFail(){

    int i, j, k; // Sayac degiskenleri.

    char gradeTypes[9][2] = {"AA", "BA", "BB", "CB", "CC", "DC", "DD", "FD", "FF"};
    char passed[6] = "PASSED";
    char failed[6] = "FAILED";
    char conditionallyPassed[20] ="CONDITIONALLY PASSED";

    for (i = 0; i < length; i++){

        if (s[i].letterGrade[0] == gradeTypes[7][0] && s[i].letterGrade[1] == gradeTypes[7][1]){
            for (k = 0; k < 20; k++){
                s[i].passFail[k] = conditionallyPassed[k];
            }
        }
        else if (s[i].letterGrade[0] == gradeTypes[8][0] && s[i].letterGrade[1] == gradeTypes[8][1]){
            for (k = 0; k < 6; k++){
                s[i].passFail[k] = failed[k];
            }
        } else {
            for (j = 0; j < 6; j++){
                s[i].passFail[j] = passed[j];
                }
            }
        }
    }


// Notlari siralama fonksiyonu. (Yuksekten dusuge dogru.)
void sortGrades(){
    int i;
    int j;
    struct Student temp; // (temp: temporary.) Degerler yer degistiriken kullanilan gecici degisken.

    for (i = 0; i < length; i++){
        for (j = i + 1; j < length; j++){
            if (s[j].Grade > s[i].Grade){ // i de tutulan degisken sirayla, listedeki tum sayilarla kiyaslanir. i den buyuk bir sayi var ise, buyuk sayi i ile yer degistirir.
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
    }
}

// Istatistik hesaplama fonskiyonu.
void statistics(){

    // Sinif ortalamasi hesaplama.
    int i;
    double sum1 = 0;
    for (i = 0; i < length; i++){
        sum1 += s[i].Grade;
    }
    double average = (sum1 / length); // average: Average. (Ortalama)


    // Ortalama ustu ogrenci sayisi hesaplama.
    double count = 0;
    for (i = 0; i < length; i++){
        if (s[i].Grade > average){
            count++;
        } else {
            continue;
        }
    }


    // Standard sapma hesaplama.
    double sum2 = 0; 
    for (i = 0; i < length; i++){
        double diff = fabs(average - s[i].Grade);
        sum2 += pow(diff, 2);
    }
    double standardDeviation = sqrt((sum2 / (length - 1)));

    // Basari orani hesaplama.
    double successRate;
    char percent = '%';
    successRate = (count * 100) / length;

    printf("\nHighest grade: %.0lf\n", s[0].Grade);
    printf("Lowest grade: %.0lf\n", s[length - 1].Grade);
    printf("Average grade of the class: %.0lf\n", average);
    printf("Number of students that performed higher than the average: %.0lf - Success rate: %c%.0lf\n", count, percent, successRate);
    printf("Standard deviation: %.2lf\n", standardDeviation);
}

// Soyad kisaltma fonksiyonu. (Soyad listesindeki soyadlarin ilk harfleri alinir ve yanina nokta eklenerek soyad kisaltmalarinin oldugu ayri bir listeye yerlestirilir.
void abbreviation(){
    int i;
    for (i = 0; i < length; i++){
        s[i].abvSurname[0] = s[i].surname[0];
        s[i].abvSurname[1] = '.';
    }
}
