#include<stdio.h>
#include"controlUser.h" // girilen kullanıcı bilgisini kontrol etmek için oluşturulan kütüphane

int main(){
    
    printf ("%s","Merhaba\n");

    while(true){
        printf ("%s","Kullanici adinizi giriniz:");
        scanf("%s",user);

        printf("%s","Sifrenizi giriniz:");
        scanf ("%d",&password);

        if(strcmp(defuser,user) == 0 && defpass == password) // giriş başarılı ise;
        {
            userCheck(SUCCED); // kullanıcı bilgileri doğru ise fonksiyona girişin başarılı olduğu bildirilir.
            break;
        }
        
        if(strcmp(defuser,user) != 0 && defpass != password) // kullanıcı adı ve şifre hatalı ise;
            userCheck(FAILED1); // kullanıcı bilgilerinin hatalı olduğunu fonksiyona bildirir.

        if(strcmp(defuser,user) == 0 && defpass != password) // girilen şifre hatalı ise;
            userCheck(FAILED2); // kullanıcı tarafından girilen şifresinin hatalı olduğunu fonksiyona bildirir.
    }
     
    return 0;
}
