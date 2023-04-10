#include <stdio.h>
#include "loginstatus.h" // girilen kullanıcı bilgisini kontrol etmek için oluşturulan kütüphane


int main()
{
    printf ("%s","Welcome!\n");

#ifdef LOGIN_STATUS_H
    while(true)
    {
        printf ("%s","Enter username:");
        scanf("%s",user);

        printf("%s","Enter password: ");
        scanf ("%d",&password);

        if(strcmp(defuser,user) == 0 && defpass == password) // giriş başarılı ise;
        {
            userCheck(LOGIN_SUCCESS); // kullanıcı bilgileri doğru ise fonksiyona girişin başarılı olduğu bildirilir.
            break;
        }
        else if((strcmp(defuser,user) != 0 && defpass != password) || (strcmp(defuser,user) != 0 && defpass == password)) // kullanıcı adı ve şifre hatalı ise;
            userCheck(LOGIN_FAILURE_BAD_CREDENTIALS); // kullanıcı bilgilerinin hatalı olduğunu fonksiyona bildirir.

        else if(strcmp(defuser,user) == 0 && defpass != password) // girilen şifre hatalı ise;
            userCheck(LOGIN_FAILURE_BAD_PASSWORD); // kullanıcı tarafından girilen şifresinin hatalı olduğunu fonksiyona bildirir.
    }
#else
    printf("ControlUser.h is not defined or not located");
#endif // LOGIN_STATUS_H

    return 0;
}

