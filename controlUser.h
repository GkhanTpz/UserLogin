#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef enum control {SUCCED, FAILED1, FAILED2} Control; // Control sadece SUCCED, FAILED1 ve FAILED2 değerini alabilir.


int password, newpass, defpass=1234;
char answer, user[15], defuser[15]="gokhan";

void userCheck(Control Status) // kullanıcı girişini kontrol eden fonksiyon
{ 
    while (true){ 
        if(Status == SUCCED)
        {
            printf("Basarili Giris.\nHosgeldiniz %s",user);  
            break;
        }       
        if(Status == FAILED1)
        {
            printf("%s","Hatali Giris Yaptiniz, Lutfen Tekrar Deneyiniz.\n");
            break;
        }
        if(Status == FAILED2)
        {
            printf("%s","Hatali Sifre! Sifrenizi Degistirmek Ister misiniz? E/H:\n");
            scanf(" %c",&answer);

                if (answer == 'E' || answer == 'e')
                {
                    printf ("%s","Yeni Sifrenizi Giriniz:");
                    scanf("%d",&newpass);
                    defpass = newpass;
                    printf("%s","Sifreniz Degistirildi. Tekrar Giris Yapabilirsiniz.\n");
                }
            break;
        }  
    }
}
