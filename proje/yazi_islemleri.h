#ifndef YAZI_ISLEMLERI_H_INCLUDED
#define YAZI_ISLEMLERI_H_INCLUDED
#include<string.h>
#include <windows.h>

void gotoxy(int sutun,int satir)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD position= {sutun,satir};
    SetConsoleCursorPosition(h,position);
}


int satir=0;
int sutun=-1;
int imlec_satir=0;
int imlec_sutun=-1;
int min_sutun=80;
int sabit=0;
int sayac=0;

struct liste
{
    int satir;
    int sutun;
    int karakter;
    struct liste *sonraki;
    struct liste *onceki;
};

typedef struct liste Liste;

Liste *kok=NULL;
Liste *head=NULL;
Liste *degisken=NULL;
Liste *bas=NULL;
Liste *ekle=NULL;
Liste *kopyala=NULL;
Liste *ikinci_kopya=NULL;

void yaz()
{


   int a=0;

   for(a=0;a<15;a++)
    printf("\n");

   for(a=0;a<25;a++)
    printf(" ");

   printf("METIN EDITORU");


     Sleep(500);

     system("cls");

     int karakter;

     char dosya_ad[30];

      printf("Dosyanini adini girin:");
      fgets(dosya_ad,30,stdin);
      fflush(stdin);

      int eleman=strlen(dosya_ad);

      dosya_ad[eleman-1]='\0';

      strcat(dosya_ad,".txt");

      system("cls");

      FILE *dosya=fopen(dosya_ad,"r");

      if(dosya==NULL)
      {
          FILE *dosya=fopen(dosya_ad,"w+");
      }

      else
      {

          karakter=fgetc(dosya);

          if(karakter!=EOF)
          {
              imlec_satir=0;
              imlec_sutun=0;

              Liste *liste=(Liste*)malloc(sizeof(Liste));
              liste->onceki=NULL;
              liste->sonraki=NULL;
              liste->karakter=karakter;
              liste->satir=imlec_satir;
              liste->sutun=imlec_sutun;

              printf("%c",liste->karakter);

                  if(liste->karakter==10)
                  {
                      sutun=-1;
                      imlec_sutun=-1;
                      satir++;
                      imlec_satir++;
                  }

           degisken=liste;
           Liste *gecis=liste;
           bas=liste;


          while(karakter!=EOF)
          {
              sutun++;
              imlec_sutun++;

              karakter=fgetc(dosya);

           liste->sonraki=(Liste*)malloc(sizeof(Liste));
           liste=liste->sonraki;
           liste->sonraki=NULL;
           liste->onceki=gecis;
           gecis=gecis->sonraki;

           liste->karakter=karakter;
           liste->satir=imlec_satir;
           liste->sutun=imlec_sutun;


                  if(liste->karakter==10)
                  {
                      sutun=-1;
                      imlec_sutun=-1;
                      satir++;
                      imlec_satir++;
                  }

                  else if(sutun==78)
                  {
                      printf("\n");
                      sutun=-1;
                      imlec_sutun=-1;
                      satir++;
                      imlec_satir++;
                  }

              ///printf("satir:%d imlec satir:%d ksatir:%d sutun:%d imlec sutun:%d ksuutn:%d !%c!\n",satir,imlec_satir,liste->satir,sutun,imlec_sutun,liste->sutun,liste->karakter);ou
              printf("%c",liste->karakter);
          }

          imlec_satir=0;
          imlec_sutun=0;
          gotoxy(imlec_sutun,imlec_satir);

          sabit=1;



          }

      }

    while(1)
    {
        karakter=getch();

        if(karakter==19)///Ctrl+S KAYDETME ISLEMI
        {
            FILE *dosya=fopen(dosya_ad,"w+");

            Liste *kaydet=bas;

            while(kaydet!=NULL)
            {
                fputc(kaydet->karakter,dosya);
                kaydet=kaydet->sonraki;
            }

            sayac=0;
        }

         else if(karakter==27)///ESC tuşuna basılıp çıkış işlemleri yapılıyor.
         {


             if(sayac==1){


             while(1){

                 system("cls");

                 printf("       ___________________________________________________\n");
                 printf("      |                                                   |\n");
                 printf("      |  %-12s icin olan degisiklikleri kaydetmek  |\n",dosya_ad);
                 printf("      |     degisiklikleri kaydetmek  istiyor musunuz?    |\n");
                 printf("      |                                                   |\n");
                 printf("      |      |Kaydet|   |Kaydetme|    |Iptal|             |\n");
                 printf("      |       Ctrl+S       ESC         Ctrl+A             |\n");
                 printf("      |___________________________________________________|\n");


             karakter=getch();

             if(karakter==19)
                break;
             else if(karakter==1)
                break;

                else if(karakter==27)
                    break;
             }

             system("cls");

             if(karakter==19)///Ctrl+S KAYDEDEREK PROGRAMDAN ÇIKMA ISLEMI
        {
            FILE *dosya=fopen(dosya_ad,"w+");

            Liste *kaydet=bas;

            while(kaydet!=NULL)
            {
                printf("%c",kaydet->karakter);
                fputc(kaydet->karakter,dosya);
                kaydet=kaydet->sonraki;
            }

            int i=0;

            for(i=0;i<25;i++)
            {
                printf("\n");
            }
            exit(0);

        }
         else if(karakter==27)///KAYDETMEDEN PROGRAMDAN CIKMA
         {
            Liste *kaydetme=bas;

            while(kaydetme!=NULL)
            {
                printf("%c",kaydetme->karakter);
                kaydetme=kaydetme->sonraki;
            }
            int i=0;

            for(i=0;i<25;i++)
            {
                printf("\n");
            }
            exit(0);

         }

         else if(karakter==1)
         {
             Liste *iptal=bas;

             while(iptal!=NULL)
             {
                 printf("%c",iptal->karakter);
                 iptal=iptal->sonraki;
             }
             gotoxy(imlec_sutun,imlec_satir);

             degisken=bas;

             while(degisken->satir!=imlec_satir)
             {
                 degisken=degisken->sonraki;
             }
             while(degisken->sutun!=imlec_sutun)
             {
                 degisken=degisken->sonraki;
             }
             ///printf("!%c! satir:%d sutun:%d\n",degisken->karakter,degisken->satir,degisken->sutun);
         }



             }

             if(sayac==0){

             system("cls");

                 Liste *esc=bas;

                 while(esc!=NULL)
                 {
                     printf("%c",esc->karakter);
                     esc=esc->sonraki;
                 }

                 int i=0;

            for(i=0;i<25;i++)
            {
                printf("\n");
            }
            exit(0);

             }

         }

        if((karakter>='A' && karakter<='Z')||(karakter>='a'&&karakter<='z')||(karakter>='0'&&karakter<='9')||karakter==13||(karakter>=32 && karakter<=47)||(karakter>=58 && karakter<=63)||(karakter>=91 && karakter<=95)||(karakter>=123 && karakter<=126))
        {
            sayac=1;
            if(karakter==13)
                karakter=10;

            if(sabit!=1)
            {

                if(kok==NULL)
                {
                    sutun++;
                    imlec_sutun++;

                    kok=(struct liste*)malloc(sizeof(struct liste));
                    kok->karakter=karakter;
                    printf("%c",kok->karakter);
                    kok->sonraki=NULL;
                    kok->onceki=NULL;
                    kok->satir=imlec_satir;
                    kok->sutun=imlec_sutun;

                    head=kok;
                    bas=kok;

                    if(kok->karakter==10)
                    {
                        sutun=-1;
                        imlec_sutun=-1;
                        satir++;
                        imlec_satir++;
                    }

                    else if(sutun==78)
                    {
                        printf("\n");
                        sutun=-1;
                        imlec_sutun=-1;
                        satir++;
                        imlec_satir++;
                    }
                }

                else if(kok!=NULL)
                {
                    sutun++;
                    imlec_sutun++;

                    kok->sonraki=(struct liste*)malloc(sizeof(struct liste));
                    kok=kok->sonraki;
                    kok->karakter=karakter;
                    printf("%c",kok->karakter);
                    kok->sonraki=NULL;
                    kok->onceki=head;
                    kok->satir=imlec_satir;
                    kok->sutun=imlec_sutun;

                    head=head->sonraki;



                    if(kok->karakter==10)
                    {
                        sutun=-1;
                        imlec_sutun=-1;
                        satir++;
                        imlec_satir++;
                    }

                    else  if(sutun==78)
                    {
                        printf("\n");
                        sutun=-1;
                        imlec_sutun=-1;
                        satir++;
                        imlec_satir++;
                    }

                }
                ///Eleman ekleme işlemi hiç yapılmadığında yön işlemleri için listenin sonuna kadar gidiliyor
                degisken=head;

            }
            if(sabit==1)///ELEMAN EKLEME ISLEMI
            {

                ekle=(Liste*)malloc(sizeof(Liste));
                ekle->onceki=NULL;
                ekle->sonraki=NULL;

                ekle->karakter=karakter;

                if(degisken==NULL)///Degisken eğer NULL olursa
                {
                    degisken=ekle;
                    degisken->satir=0;
                    degisken->sutun=0;

                    satir=0;
                    sutun=0;
                    imlec_satir=0;
                    imlec_sutun=0;
                }

                else if(degisken!=NULL)
                {

                    ///ilk eleman ekleme durumu
                    if(ekle->karakter!=10 && degisken->sutun==0 && degisken->satir==0)
                    {
                        if(satir==0)
                            sutun++;

                        ekle->satir=imlec_satir;
                        ekle->sutun=0;

                        ekle->sonraki=degisken;
                        degisken->onceki=ekle;

                        bas=ekle;

                        Liste *ilk=degisken;
                        degisken=ekle;



                        while(ilk->sonraki!=NULL && ilk->karakter!=10 && ilk->sutun!=78)
                        {
                            ilk->sutun++;
                            ilk=ilk->sonraki;
                        }
                        ilk->sutun++;

                        system("cls");
                        ekle=bas;

                        //printf("satir:%d sutun:%d\n",satir,sutun);
                        //printf("degisken satir:%d sutun:%d !%c!\n\n",degisken->satir,degisken->sutun,degisken->karakter);


                        while(ekle!=NULL)
                        {

                            ///printf("satir:%d sutun:%d !%c!\n",ekle->satir,ekle->sutun,ekle->karakter);
                            printf("%c",ekle->karakter);
                            ekle=ekle->sonraki;
                        }

                        gotoxy(imlec_sutun,imlec_satir);
                    }
                    else if(ekle->karakter!=10 && imlec_satir==satir && degisken->sonraki==NULL)///son eleman ekleme durumu
                    {
                        sutun++;

                        ekle->sutun=sutun;
                        ekle->satir=satir;

                        degisken->sonraki=ekle;
                        ekle->onceki=degisken;



                        //degisken=degisken->sonraki;

                        //printf("degisken !%c! satir:%d sutun:%d\n",degisken->karakter,degisken->satir,degisken->sutun);


                        ekle=bas;



                        system("cls");
                        while(ekle!=NULL)
                        {
                            ///printf("satir:%d sutun:%d !%c!\n",ekle->satir,ekle->sutun,ekle->karakter);
                            printf("%c",ekle->karakter);
                            ekle=ekle->sonraki;
                        }
                    }
                    else if(ekle->karakter!=10 && degisken->sutun!=78)///Araya eleman ekleme durumu
                    {
                        if(imlec_satir==satir)
                            sutun++;

                        ekle->satir=imlec_satir;
                        ekle->sutun=imlec_sutun;

                        degisken=degisken->onceki;
                        ekle->onceki=degisken;
                        ekle->sonraki=degisken->sonraki;
                        degisken->sonraki=ekle;
                        //degisken->sonraki->onceki=ekle;

                        degisken=ekle;



                        Liste *ara=degisken->sonraki;

                        while(ara->sonraki!=NULL && ara->karakter!=10 && ara->sutun!=78)
                        {
                            ara->sutun++;
                            ara=ara->sonraki;
                        }
                        ara->sutun++;

                        system("cls");

                        //printf("degiiskem  satir:%d sutun:%d !%c!\n",degisken->satir,degisken->sutun,degisken->karakter);

                        ekle=bas;

                        ///printf("\n\n\n\n\n");

                        while(ekle!=NULL)
                        {
                            ///printf("satir:%d sutun:%d !%c!\n",ekle->satir,ekle->sutun,ekle->karakter);
                            printf("%c",ekle->karakter);
                            ekle=ekle->sonraki;

                        }
                        gotoxy(imlec_sutun,imlec_satir);

                    }
                    else if(ekle->karakter==10)///Enter ekleme durumu
                    {
                        Liste *enter;

                        if(degisken->sutun==0)
                        {
                            satir++;
                            if(imlec_satir==0)
                            {
                                ekle->satir=0;
                                ekle->sutun=0;

                                ekle->sonraki=degisken;
                                degisken->onceki=ekle;

                                degisken=ekle;
                                bas=ekle;

                                enter=degisken->sonraki;
                            }
                            else if(imlec_satir!=0)
                            {
                                ekle->satir=imlec_satir;
                                ekle->sutun=0;

                                degisken=degisken->onceki;
                                ekle->onceki=degisken;
                                ekle->sonraki=degisken->sonraki;
                                degisken->sonraki=ekle;
                                degisken=ekle;

                                enter=degisken->sonraki;


                            }

                            while(enter!=NULL)
                            {
                                enter->satir++;
                                enter=enter->sonraki;
                            }
                            system("cls");

                            ekle=bas;

                            while(ekle!=NULL)
                            {
                                ///printf("satir:%d sutun:%d !%c!\n",ekle->satir,ekle->sutun,ekle->karakter);
                                printf("%c",ekle->karakter);
                                ekle=ekle->sonraki;
                            }
                            gotoxy(imlec_sutun,imlec_satir);
                        }

                        else if(degisken->sutun!=0)
                        {
                            satir++;

                            ekle->satir=imlec_satir;
                            ekle->sutun=imlec_sutun;

                            degisken=degisken->onceki;
                            ekle->onceki=degisken;
                            ekle->sonraki=degisken->sonraki;
                            degisken->sonraki=ekle;
                            degisken=ekle;


                            enter=degisken->sonraki;

                            while(enter!=NULL)
                            {
                                enter->satir++;
                                enter=enter->sonraki;
                            }

                            enter=degisken->sonraki;

                            int sayac=0;

                            while(enter->sonraki!=NULL && enter->karakter!=10 && enter->sutun!=78)
                            {
                                enter->sutun=sayac;
                                sayac++;
                                enter=enter->sonraki;
                            }
                            enter->sutun=sayac;

                            ekle=bas;

                            system("cls");

                            while(ekle!=NULL)
                            {
                                ///printf("satir:%d sutun:%d !%c!\n",ekle->satir,ekle->sutun,ekle->karakter);
                                printf("%c",ekle->karakter);
                                ekle=ekle->sonraki;
                            }

                            gotoxy(imlec_sutun,imlec_satir);
                        }
                    }

                }
            }
        }

        else if(karakter==8 && degisken!=NULL)///SILME ISLEMI
        {
            Liste *sil;
            Liste *yok_et;

            if(degisken->sonraki!=NULL && degisken->satir==0 && degisken->sutun==0)///İlk elemanı silme işlemi
            {
                ///printf("ilk elemani sil");

                if(degisken->karakter!=10 && degisken->sutun!=78)
                {
                    yok_et=degisken;

                    degisken=degisken->sonraki;
                    degisken->onceki=NULL;
                    sil=degisken;

                    bas=degisken;

                    while(sil->sonraki!=NULL && sil->karakter!=10 && sil->sutun!=78)
                    {
                        sil->sutun--;
                        sil=sil->sonraki;
                    }
                    sil->sutun--;

                    sil=bas;

                    system("cls");

                    while(sil!=NULL)
                    {
                        printf("%c",sil->karakter);
                        sil=sil->sonraki;
                    }

                    gotoxy(imlec_sutun,imlec_satir);

                    free(yok_et);
                }
                else if(degisken->karakter==10)
                {
                    yok_et=degisken;
                    degisken=degisken->sonraki;
                    degisken->onceki=NULL;

                    sil=degisken;
                    bas=degisken;

                    while(sil!=NULL)
                    {
                        sil->satir--;
                        sil=sil->sonraki;
                    }

                    sil=bas;
                    system("cls");

                    ///printf("degisken !%c! satir:%d sutun:%d\n",degisken->karakter,degisken->satir,degisken->sutun);

                    while(sil!=NULL)
                    {
                        printf("%c",sil->karakter);
                        sil=sil->sonraki;
                    }

                    free(yok_et);

                    gotoxy(imlec_sutun,imlec_satir);
                }

            }
            else if(degisken->onceki==NULL && degisken->sonraki==NULL && degisken->satir==0 && degisken->sutun==0)///Tek karakteri silme durumu
            {
                yok_et=degisken;
                degisken=NULL;

                imlec_sutun=0;
                imlec_satir=0;
                free(yok_et);
                gotoxy(imlec_sutun,imlec_satir);
                system("cls");
                ///printf("imlec sutuun:%d imlec satir:%d\n",imlec_sutun,imlec_satir);
                gotoxy(imlec_sutun,imlec_satir);
            }

            else if(degisken->sonraki==NULL && imlec_satir==satir)///Son elemanı silme işlemi
            {
                ///printf("son elemani sil");

                ///printf("degisken !%c! satir:%d stutun:%d\n",degisken->karakter,degisken->satir,degisken->sutun);

                if(degisken->sonraki==NULL && satir!=0 && degisken->satir!=degisken->onceki->satir)///Son satırda tek eleman olması durumu
                {


                    yok_et=degisken;
                    degisken=degisken->onceki;
                    degisken->sonraki=NULL;

                    satir--;
                    imlec_satir--;
                    int say=0;
                    sil=degisken;

                    while(sil->onceki!=NULL && sil->onceki->satir==sil->satir)
                    {
                        say++;
                        sil=sil->onceki;
                    }
                    sutun=say;
                    imlec_sutun=sutun;

                    sil=bas;

                    system("cls");

                    while(sil!=NULL)
                    {
                        printf("%c",sil->karakter);
                        sil=sil->sonraki;
                    }

                    gotoxy(imlec_sutun,imlec_satir);

                    free(yok_et);

                }

                else if(degisken->onceki!=NULL && degisken->sonraki==NULL && degisken->satir==degisken->onceki->satir)
                {
                    yok_et=degisken;
                    degisken=degisken->onceki;
                    degisken->sonraki=NULL;

                    sutun--;

                    sil=bas;

                    system("cls");

                    while(sil!=NULL)
                    {
                        printf("%c",sil->karakter);
                        sil=sil->sonraki;
                    }

                    free(yok_et);
                }

            }
            ///Herhangi bir elemanı silme işlemi
            else if(degisken->onceki!=NULL && degisken->sonraki!=NULL)
            {
                if(degisken->karakter!=10)
                {

                    yok_et=degisken;

                    degisken=degisken->onceki;
                    degisken->sonraki=degisken->sonraki->sonraki;
                    degisken->sonraki->onceki=degisken;
                    degisken=degisken->sonraki;
                    sil=degisken;

                    if(imlec_satir==satir)
                        sutun--;

                    while(sil->sonraki!=NULL && sil->karakter!=10 && sil->sutun!=78)
                    {
                        sil->sutun--;
                        sil=sil->sonraki;
                    }

                    sil->sutun--;

                    sil=bas;

                    system("cls");

                    while(sil!=NULL)
                    {
                        ///printf("satir:%d sutun:%d !%c!\n",sil->satir,sil->sutun,sil->karakter);
                        printf("%c",sil->karakter);
                        sil=sil->sonraki;
                    }


                    gotoxy(imlec_sutun,imlec_satir);

                    ///printf("\n\n\n\n\nimlec satir:%d imlec sutun:%d\n",imlec_satir,imlec_sutun);

                    free(yok_et);

                }
            }
        }

        else if(karakter==1)///Ctrl+A Kopyalama işlemi
        {

            if(kopyala==NULL)
            {
                kopyala=(Liste*)malloc(sizeof(Liste));
                kopyala->karakter=degisken->karakter;
                kopyala->onceki=NULL;
                kopyala->sonraki=NULL;

                ikinci_kopya=kopyala;
            }
            else if(kopyala!=NULL)
            {
                kopyala->onceki=(Liste*)malloc(sizeof(Liste));
                kopyala=kopyala->onceki;
                kopyala->onceki=NULL;
                kopyala->karakter=degisken->karakter;
                kopyala->sonraki=ikinci_kopya;

                ikinci_kopya=ikinci_kopya->onceki;
            }
        }
        else if(karakter==3)///Ctrl+C Kopyalama işleminin devamı
        {
             int ikinci_sayac=0;

             ikinci_kopya=kopyala;

            while(kopyala->sonraki!=NULL)
            {

                kopyala->sutun=ikinci_sayac;

                ///printf("!%c! %d\n",kopyala->karakter,kopyala->sutun);

                ikinci_sayac++;

                kopyala=kopyala->sonraki;
            }
            kopyala->sutun=ikinci_sayac;
        }

        else if(karakter==22)///Ctrl+V Yapıştırma işlemi
        {
            int yapistir_sutun=degisken->sutun;

            Liste *kopyayi_tut=ikinci_kopya;

            kopyala->sonraki=degisken->sonraki;
            degisken->sonraki->sutun+=kopyala->sutun;
            degisken->onceki=kopyala;

            degisken->sonraki=ikinci_kopya;
            ikinci_kopya->onceki=degisken;

            while(ikinci_kopya!=kopyala)
            {
                ikinci_kopya->sutun+=yapistir_sutun;
                ikinci_kopya->satir=degisken->satir;
                ikinci_kopya=ikinci_kopya->sonraki;

            }
            ikinci_kopya->sutun+=yapistir_sutun;
            ikinci_kopya->satir=degisken->satir;

            system("cls");

            Liste *eklenmis=bas;

            while(eklenmis!=NULL)
            {
                printf("%c",eklenmis->karakter);
                eklenmis=eklenmis->sonraki;
            }
            gotoxy(imlec_sutun,imlec_satir);

            kopyala=kopyayi_tut;

        }


        else if(karakter==224)///YON TUSLARI ILE HAREKET
        {
            karakter=getch();

            sabit=1;

            if(degisken!=NULL)
            {

                if(karakter==80)///asagi
                {

                    ///printf("\n\n\n\n\n");
                    ///printf("satir:%d asagi Degisken satir:%d sutun:%d !%c!\n",satir,degisken->satir,degisken->sutun,degisken->karakter);

                    ///printf(" degisken satir:%d sutun:%d !%c!\n",degisken->satir,degisken->sutun,degisken->karakter);

                    if(imlec_satir<satir)
                    {

                        int sayi1=-1,sayi2=-1;

                        Liste *asagi=degisken,*asagi2=degisken->sonraki;
                        ///printf("asagi:!%c! sonraki:!%c!\n",degisken->karakter,degisken->sonraki->karakter);

                        ///printf("\n\n\n");

                        while(asagi->onceki!=NULL && asagi->onceki->satir==asagi->satir)///üstteki satırın elemanları sayılıyor.
                        {
///printf("imlec satir:%d imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_satir,imlec_sutun,asagi->satir,asagi->sutun,asagi->karakter);

                            sayi1++;
                            asagi=asagi->onceki;
                        }
                        sayi1++;
///printf("imlec satir:%d imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_satir,imlec_sutun,asagi->satir,asagi->sutun,asagi->karakter);
                        imlec_satir++;

///printf("\n*******************************************************************************\n\n");



                        while(asagi2->sonraki!=NULL && asagi2->sonraki->satir!=imlec_satir)
                        {

///printf("2. imlec satir:%d imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_satir,imlec_sutun,asagi2->satir,asagi2->sutun,asagi2->karakter);

                            asagi2=asagi2->sonraki;
                        }

                        if(asagi2->onceki->karakter!=10 && asagi2->onceki->sutun!=78)
                        {

                            asagi2=asagi2->sonraki;
                        }

                        ///printf("2. imlec satir:%d imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_satir,imlec_sutun,asagi2->satir,asagi2->sutun,asagi2->karakter);

                        while(asagi2!=NULL && asagi2->sonraki!=NULL && asagi2->sonraki->satir==asagi2->satir)
                        {
                            ///printf("2. imlec satir:%d imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_satir,imlec_sutun,asagi2->satir,asagi2->sutun,asagi2->karakter);
                            sayi2++;
                            asagi2=asagi2->sonraki;
                        }
                        sayi2++;

                        ///printf("2. imlec satir:%d imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_satir,imlec_sutun,asagi2->satir,asagi2->sutun,asagi2->karakter);


                        ///printf("\n\nsayi1:%d sayi2:%d\n\n",sayi1,sayi2);

                        if(sayi1>sayi2)
                        {

                            if(min_sutun>sayi2)
                            {
                                min_sutun=sayi2;
                            }
                            imlec_sutun=min_sutun;

                        }

                        else if(sayi1<=sayi2)
                        {
                            if(min_sutun>sayi1)
                            {
                                min_sutun=sayi1;
                            }
                            imlec_sutun=min_sutun;

                        }

                        asagi=bas;

                        while(asagi->sonraki!=NULL && asagi->satir!=imlec_satir)
                            asagi=asagi->sonraki;


                        if(asagi->karakter!=10 && asagi->sutun!=0)
                            asagi=asagi->sonraki;


                        while(asagi->sonraki!=NULL && asagi->sutun!=imlec_sutun)
                            asagi=asagi->sonraki;

                        ///printf("\n\n\n\n\n\n\n\n\n\n\nilk degisken karakter:!%c! onceki!%c!\n",degisken->karakter,degisken->onceki->karakter);


                        degisken=asagi;

                        ///printf("\n\n\n\n\n\ndegisken: satir:%d sutun:%d !%c!\n",degisken->satir,degisken->sutun,degisken->karakter);

                        ///printf("imlec satir:%d imlec sutun:%d\n",imlec_satir,imlec_sutun);


                        ///printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\ndegisken satir:%d sutun:%d !%c!\n",degisken->satir,degisken->sutun,degisken->karakter);

                        gotoxy(imlec_sutun,imlec_satir);

                    }

                }
                else if(karakter==72)///yukari
                {
                    if(imlec_satir>0)
                    {

                        int sayi1=-1,sayi2=-1;

                        Liste *yukari=degisken;

                        ///printf("\n\n\n\n\n\n\n\n\n\n\n\n");


                        ///printf("\n\n\n\n\nyukari: imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_sutun,yukari->satir,yukari->sutun,yukari->karakter);

                        ///printf("\n\n\n");

                        while(yukari->onceki!=NULL && yukari->onceki->satir==yukari->satir)
                        {
                            ///printf("yukari: imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_sutun,yukari->satir,yukari->sutun,yukari->karakter);
                            sayi1++;
                            yukari=yukari->onceki;
                        }

                        /// printf("sag karsi");
                        sayi1++;

                        ///printf("yukari: imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_sutun,yukari->satir,yukari->sutun,yukari->karakter);

                        yukari=yukari->onceki;

                        ///printf("\n\n***********\n\n\n");



                        imlec_satir--;

                        while(yukari->onceki!=NULL && yukari->onceki->satir==yukari->satir)
                        {

///printf("yukari1: imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_sutun,yukari->satir,yukari->sutun,yukari->karakter);
                            sayi2++;
                            yukari=yukari->onceki;
                        }
///printf("yukari: imlec sutun:%d satir:%d sutun:%d !%c!\n",imlec_sutun,yukari->satir,yukari->sutun,yukari->karakter);
                        sayi2++;

                        ///printf("\nimlec satir:%d sayi1:%d sayi2:%d\n",imlec_satir,sayi1,sayi2);

                        if(sayi1>sayi2)
                        {

                            if(min_sutun>sayi2)
                            {
                                min_sutun=sayi2;
                            }
                            imlec_sutun=min_sutun;

                        }

                        else if(sayi1<=sayi2)
                        {
                            if(min_sutun>sayi1)
                            {
                                min_sutun=sayi1;
                            }
                            imlec_sutun=min_sutun;

                        }

                        yukari=bas;

                        while(yukari->sonraki!=NULL && yukari->satir!=imlec_satir)
                            yukari=yukari->sonraki;


                        if(yukari->karakter!=10 && yukari->sutun!=0)
                            yukari=yukari->sonraki;


                        while(yukari->sonraki!=NULL && yukari->sutun!=imlec_sutun)
                            yukari=yukari->sonraki;

                        ///printf("\n\n\n\n\n\n\n\n\n\n\nilk degisken karakter:!%c! onceki!%c!\n",degisken->karakter,degisken->onceki->karakter);


                        degisken=yukari;

                        ///printf("\n\n yukari degisken: satir:%d sutun:%d !%c!\n",degisken->satir,degisken->sutun,degisken->karakter);

                        ///printf("imlec satir:%d imlec sutun:%d\n",imlec_satir,imlec_sutun);


                        gotoxy(imlec_sutun,imlec_satir);
                    }
///printf("\n\n yukari degisken: satir:%d sutun:%d !%c!\n",degisken->satir,degisken->sutun,degisken->karakter);
                }

                else if(karakter==77 && degisken->sonraki!=NULL)///sag
                {
                    //Değişkenin sonrakinin null'e eşit olup olmadığının kontorlünün yapılmasının sebebi değişkeni
                    // nulle eşitlemeyip değişkeni kaybetmemek

///printf("\n\n\n\n sag1: imlec sutun: %d imlec satir:%d satir:%d sutun:%d !%c!\n",imlec_sutun,imlec_satir,degisken->satir,degisken->sutun,degisken->karakter);
                    if(imlec_satir<satir)
                    {
                        if(degisken->sutun!=78 && degisken->karakter!=10)
                        {
                            imlec_sutun++;
                        }
                        else if(degisken->sutun==78)
                        {
                            imlec_sutun=0;
                            imlec_satir++;
                        }
                        else if(degisken->karakter==10)
                        {
                            imlec_sutun=0;
                            imlec_satir++;
                        }

                    }
                    else if(imlec_satir==satir && degisken!=NULL)
                    {
                        imlec_sutun++;
                    }
                    ///printf("imlec satir:%d\n",imlec_satir);
                    gotoxy(imlec_sutun,imlec_satir);
                    degisken=degisken->sonraki;

///printf("\n\n\n\n sag: imlec sutun: %d satir:%d sutun:%d !%c!\n",imlec_sutun,degisken->satir,degisken->sutun,degisken->karakter);
                    min_sutun++;

                }

                else if(karakter==75)///sol
                {
                    ///printf("\n\n\n\n sol: imlec sutun: %d imlec satir:%d satir:%d sutun:%d !%c!\n",imlec_sutun,imlec_satir,degisken->satir,degisken->sutun,degisken->karakter);

                    if(imlec_satir>=0)
                    {
                        if(imlec_sutun>0)
                        {

                            imlec_sutun--;
                            if(degisken->karakter && degisken->onceki!=NULL && degisken->onceki->satir==degisken->satir)
                                degisken=degisken->onceki;
                            gotoxy(imlec_sutun,imlec_satir);
                        }
                        else if(imlec_sutun==0)
                        {

                            if(imlec_satir!=0)
                            {

                                int sayi1=-1;

                                degisken=degisken->onceki;

                                Liste *degisken2=degisken;

                                while(degisken2->onceki!=NULL && degisken2->satir==degisken2->onceki->satir)
                                {
                                    sayi1++;

                                    degisken2=degisken2->onceki;
                                }
                                sayi1++;


                                imlec_sutun=sayi1;
                                imlec_satir--;


                                gotoxy(imlec_sutun,imlec_satir);
                            }
                        }

                        ///printf("\n\n\n\n sol: imlec sutun: %d imlec satir:%d satir:%d sutun:%d !%c!\n",imlec_sutun,imlec_satir,degisken->satir,degisken->sutun,degisken->karakter);

                        min_sutun++;

                    }
                }
            }
        }
    }

}

#endif // YAZI_ISLEMLERI_H_INCLUDED
