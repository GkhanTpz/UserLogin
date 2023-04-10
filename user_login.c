#include <stdio.h>
#include "loginstatus.h" // girilen kullanıcı bilgisini kontrol etmek için oluşturulan kütüphane


int main()
{
    printf ("%s","Welcome!\n");

#ifdef LOGIN_STATUS_H
    while(true)
    {
        printf ("%s","Enter username:");
        scanf("%s",username);

        printf("%s","Enter password: ");
        scanf ("%d",&password);

        if(strcmp(DEFAULT_USERNAME,username) == 0 && DEFAULT_PASSWORD == password) // giriş başarılı ise;
        {
            userCheck(LOGIN_SUCCESS); // kullanıcı bilgileri doğru ise fonksiyona girişin başarılı olduğu bildirilir.
            break;
        }
        else if((strcmp(DEFAULT_USERNAME,username) != 0 && DEFAULT_PASSWORD != password) || (strcmp(DEFAULT_USERNAME,username) != 0 && DEFAULT_PASSWORD == password)) // kullanıcı adı ve şifre hatalı ise;
            userCheck(LOGIN_FAILURE_BAD_CREDENTIALS); // kullanıcı bilgilerinin hatalı olduğunu fonksiyona bildirir.

        else if(strcmp(DEFAULT_USERNAME,username) == 0 && DEFAULT_PASSWORD != password) // girilen şifre hatalı ise;
            userCheck(LOGIN_FAILURE_BAD_PASSWORD); // kullanıcı tarafından girilen şifresinin hatalı olduğunu fonksiyona bildirir.
    }
#else
    printf("loginstatus.h is not defined or not located");
#endif // LOGIN_STATUS_H

    return 0;
}

