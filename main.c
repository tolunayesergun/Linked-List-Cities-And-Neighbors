#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>


struct Komsu
{

    int plakaKodu;

    struct Komsu *right;

};


struct node
{
    int   SehirPlaka;
    int   SehirKomsuSayisi;
    char *SehirAd;
    char *SehirBolge;

    struct node *next;
    struct node *prev;
    struct Komsu *right;

};



struct node *ilkPlaka=NULL;
struct node *sonPlaka=NULL;

struct node *ilkSehir=NULL;
struct node *sonSehir=NULL;

struct node *ilkBolge=NULL;
struct node *sonBolge=NULL;

struct node *ilkKomsuSayisi=NULL;
struct node *sonKomsuSayisi=NULL;

char sehirdondur[256];
char bolgedondur[256];


void SonaPlakaEkle(int a);
void SonaKomsuSayisiEkle(int a);
void SonaSehirEkle(char *a);
void SonaBolgeEkle(char *a);
void Listele();
void DosyaOku();
void hidecursor();
void showcursor();
void gotoxy(int x,int y);
void Giris();
int PlakaKodKontrol(int x);
int SehirAdKontrol(char x[256]);
void AdaGoreSehirBilgiGetir(char x[256]);
int PlakaBul(char x[256]);
void PlakayaGoreSehirBilgiGetir(int x);
void BolgeyeGoreSehirBilgiGetir(char x[256]);
void KomsuSayisinaGoreListele(int x,int y, int op);
void SayacaGoreBilgiCagir(int sayac);
void KullaniciSehirEkle();
void SehirSil();
void SehirArama();
void DugumdenSil(int x);
void Sirala();
int komsuEkle(int Plaka_Kodu, int Komsu_Plaka_Kodu);
void KullaniciKomsuEkle();
void KomsuSayisiArttir(int x);
void BolgeBul(int x);
void KullaniciKomsuEkle();
int KomsuSil(int Plaka_Kodu, int Komsu_Plaka_Kodu);
void CiktiVer();
void KullaniciKomsuSil();
void KomsuSayisiAzalt(int x);

// Struct icine plaka numaralarini eklemek icin fonksiyon
void SonaPlakaEkle(int a)
{
    struct node *yeni = (struct node*) malloc(sizeof(struct node));
    yeni->SehirPlaka=a;
    if(ilkPlaka==NULL)
    {
        ilkPlaka=yeni;
        sonPlaka=yeni;
        sonPlaka->next=NULL;
        sonPlaka->prev=NULL;
        sonPlaka->right=NULL;
    }
    else
    {

        yeni->prev=sonPlaka;
        sonPlaka->next=yeni;
        sonPlaka=yeni;
        sonPlaka->next=NULL;
        sonPlaka->right=NULL;
    }
}
// Struct icine komsu sayisini eklemek icin gerekli fonksiyon
void SonaKomsuSayisiEkle(int a)
{
    struct node *yeni = (struct node*) malloc(sizeof(struct node));
    yeni->SehirKomsuSayisi=a;
    if(ilkKomsuSayisi==NULL)
    {
        ilkKomsuSayisi=yeni;
        sonKomsuSayisi=yeni;
        sonKomsuSayisi->next=NULL;
        sonKomsuSayisi->prev=NULL;
    }
    else
    {
        yeni->prev=sonKomsuSayisi;
        sonKomsuSayisi->next=yeni;
        sonKomsuSayisi=yeni;
        sonKomsuSayisi->next=NULL;
    }
}
// Struct icine sehir isimlerini eklemek icin gerekli fonksiyon
void SonaSehirEkle(char *a)
{
    if(ilkSehir==NULL)
    {
        ilkSehir = (struct node*) malloc(sizeof(struct node));
        ilkSehir->SehirAd = malloc(256);
        strcpy(ilkSehir->SehirAd, a);

        sonSehir=ilkSehir;
        sonSehir->next=NULL;
        sonSehir->prev=NULL;
    }
    else
    {

        sonSehir->next = (struct node*) malloc(sizeof(struct node));
        sonSehir->next->SehirAd = malloc(256);
        strcpy(sonSehir->next->SehirAd, a);
        sonSehir->next->prev=sonSehir;
        sonSehir=sonSehir->next;
        sonSehir->next=NULL;
    }
}
// Struct icine Cografi bolgesini eklemek icin gerekli fonksiyon
void SonaBolgeEkle(char *a)
{
    if(ilkBolge==NULL)
    {
        ilkBolge = (struct node*) malloc(sizeof(struct node));
        ilkBolge->SehirBolge = malloc(256);
        strcpy(ilkBolge->SehirBolge, a);

        sonBolge=ilkBolge;
        sonBolge->next=NULL;
        sonBolge->prev=NULL;
    }
    else
    {
        sonBolge->next = (struct node*) malloc(sizeof(struct node));
        sonBolge->next->SehirBolge = malloc(256);
        strcpy(sonBolge->next->SehirBolge, a);
        sonBolge->next->prev=sonBolge;
        sonBolge=sonBolge->next;
        sonBolge->next=NULL;
    }
}
// Sirali Bir sekilde sehirlerin komsularini ekleyen fonksiyon
int komsuEkle(int shPlakaKodu, int KomsuPlakaKodu)
{
    struct node *PlakaListe =ilkPlaka;
    struct Komsu *yeni=(struct Komsu*)malloc(sizeof(struct Komsu));

    yeni->plakaKodu=KomsuPlakaKodu;

    while(PlakaListe!=NULL && PlakaListe->SehirPlaka!=shPlakaKodu)
    {

        PlakaListe=PlakaListe->next;
    }

    if(PlakaListe->right==NULL)
    {
        yeni->right=NULL;
        PlakaListe->right=yeni;



    }
    else if(PlakaListe->right->plakaKodu>KomsuPlakaKodu)
    {



        struct Komsu *gecici=PlakaListe->right;

        yeni->right=gecici;
        PlakaListe->right=yeni;
    }
    else
    {
        struct Komsu *geziyormu=PlakaListe->right;

        while(geziyormu->right != NULL && geziyormu->right->plakaKodu < KomsuPlakaKodu)
        {
            geziyormu = geziyormu->right;
        }
        if(geziyormu->plakaKodu == KomsuPlakaKodu || (geziyormu->right != NULL && geziyormu->right->plakaKodu == KomsuPlakaKodu))
        {

            return 5;
        }

        struct Komsu *sayac=PlakaListe->right;
        while(sayac->right!=NULL && sayac->right->plakaKodu<KomsuPlakaKodu)
        {
            sayac=sayac->right;
        }
        yeni->right=sayac->right;
        sayac->right=yeni;

    }


    return 4;
}
// Komsu silmeyi saglayan fonksiyon
int KomsuSil(int shPlakaKodu, int KomsuPlakaKodu)
{
    struct node *sehiryer=ilkPlaka;
    struct Komsu *yerbulucu;

    while(sehiryer!=NULL && sehiryer->SehirPlaka!=shPlakaKodu)
    {
        sehiryer=sehiryer->next;
    }
    yerbulucu=sehiryer->right;

    if(yerbulucu->plakaKodu==KomsuPlakaKodu)
    {
        struct Komsu *Gecici=yerbulucu;
        sehiryer->right=Gecici->right;
        free(Gecici);
    }
    else
    {
        while(yerbulucu->right!=NULL && yerbulucu->right->plakaKodu!=KomsuPlakaKodu)
        {
            yerbulucu=yerbulucu->right;
        }
        if(yerbulucu->right == NULL)
        {

            return 5;
        }
        struct Komsu *Gecermi=yerbulucu->right;
        yerbulucu->right=Gecermi->right;
        free(Gecermi);

    }

    return 4;
}
// Sehir sturctinda ki datalari listeleyen fonksiyon
void Listele()
{
    struct node *KomsuSayisiListe=ilkKomsuSayisi;
    struct node *Plakaliste=ilkPlaka;
    struct node *Sehirliste=ilkSehir;
    struct node *BolgeListe=ilkBolge;

    struct Komsu *KomsularListe = Plakaliste->right;

    int toplamkayit=1;
    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
    system("@cls||clear");
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c         Sehir Listesi         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);
    printf("\n\n\n");
    printf("\n [Plaka]           [Sehir Adi]          [Bolge]      [Komsu Sayisi]        [Komsu Sehirlerin Plaka Kodlari]\n");
    printf("\n");
    printf("%5d%23s%16s%16d",Plakaliste->SehirPlaka,Sehirliste->SehirAd,BolgeListe->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
    printf("            ");
    while(KomsularListe!=NULL)
    {
        printf("%5d",KomsularListe->plakaKodu);
        KomsularListe=KomsularListe->right;
    }
    printf("\n");
    while(Plakaliste->next!=NULL)
    {

        Plakaliste=Plakaliste->next;
        Sehirliste=Sehirliste->next;
        BolgeListe=BolgeListe->next;
        KomsuSayisiListe=KomsuSayisiListe->next;

        printf("%5d%23s%16s%16d",Plakaliste->SehirPlaka,Sehirliste->SehirAd,BolgeListe->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);

        KomsularListe=Plakaliste->right;
        printf("            ");
        while(KomsularListe!=NULL)
        {

            printf("%5d",KomsularListe->plakaKodu);
            KomsularListe=KomsularListe->right;

        }
        printf("\n");
        toplamkayit++;
    }
    printf("\n\n Toplam kayit = %d",toplamkayit);

}
// Txt olusturan fonksiyon
void CiktiVer()
{

    FILE *Dosya;
    Dosya=fopen("cikti.txt","w");

    struct node *Plakaliste=ilkPlaka;
    struct node *Sehirliste=ilkSehir;
    struct node *BolgeListe=ilkBolge;
    struct node *KomsuSayisiListe=ilkKomsuSayisi;
    struct Komsu *KomsularListe = Plakaliste->right;


    int toplamkayit=1;

    fprintf(Dosya,"\n                                                                             ");
    fprintf(Dosya,"\n                                                                             ");
    fprintf(Dosya,"\n                                                    [ Sehir Listesi ]        ");
    fprintf(Dosya,"\n                                                                             ");
    fprintf(Dosya,"\n                                                                             ");
    fprintf(Dosya,"\n");

    fprintf(Dosya,"\n [Plaka]           [Sehir Adi]          [Bolge]      [Komsu Sayisi]        [Komsu Sehirlerin Plaka Kodlari]\n");
    fprintf(Dosya,"\n");
    fprintf(Dosya,"%5d%23s%16s%16d",Plakaliste->SehirPlaka,Sehirliste->SehirAd,BolgeListe->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
    fprintf(Dosya,"            ");
    while(KomsularListe!=NULL)
    {
        fprintf(Dosya,"%5d",KomsularListe->plakaKodu);
        KomsularListe=KomsularListe->right;
    }
    fprintf(Dosya,"\n");
    while(Plakaliste->next!=NULL)
    {
        Plakaliste=Plakaliste->next;
        Sehirliste=Sehirliste->next;
        BolgeListe=BolgeListe->next;
        KomsuSayisiListe=KomsuSayisiListe->next;

        fprintf(Dosya,"%5d%23s%16s%16d",Plakaliste->SehirPlaka,Sehirliste->SehirAd,BolgeListe->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);

        KomsularListe=Plakaliste->right;
        fprintf(Dosya,"            ");
        while(KomsularListe!=NULL)
        {

            fprintf(Dosya,"%5d",KomsularListe->plakaKodu);
            KomsularListe=KomsularListe->right;

        }
        fprintf(Dosya,"\n");
        toplamkayit++;

    }
    fprintf(Dosya,"\n\n Toplam kayit = %d",toplamkayit);

    fclose(Dosya);

    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
    system("@cls||clear");
    printf("\n\n\n");
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c           Veriler             %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c         Cikti.txt'ye          %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        Yazdirilmistir         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");

}
// Txt deki datalari cekildigi ve onlari structin icine atma islemlerinin gerceklestiren fonksiyon
void DosyaOku(int ilk,int komsularalindi)
{
    int temp=0;
    FILE *fp = fopen("sehirler.txt","r");


    if(fp == NULL)
    {
        perror("Unable to open file!");
        exit(1);
    }

    char chunk[1024];

    while(fgets(chunk, sizeof(chunk), fp) != NULL)
    {
        char *  pt;
        int pointPt = 0;
        char delimit[]="\t\r\n\v\f,";
        int verikontrol=0;
        pt = strtok (chunk,delimit);
        while (pt != NULL)
        {


            if(pointPt == 0)
            {

                if(ilk==1)
                {

                    SonaPlakaEkle(atoi(pt));
                    ilk=2;
                    temp=atoi(pt);


                }

                else
                {

                    if (PlakaKodKontrol(atoi(pt))==1)
                    {
                        temp=atoi(pt);
                        verikontrol=5;

                    }
                    else
                    {

                        SonaPlakaEkle(atoi(pt));
                        temp=atoi(pt);
                    }
                }
            }
            else if(pointPt == 1)
            {
                if(verikontrol==0)
                {
                    SonaSehirEkle(pt);
                }
            }
            else if(pointPt == 2)
            {
                if(verikontrol==0)
                {
                    SonaBolgeEkle(pt);
                }
            }
            else
            {
                if(verikontrol==5)
                {
                    char ctemp[256];
                    strcpy(ctemp,pt);
                    komsuEkle(temp,PlakaBul(ctemp));
                }
            }


            pointPt++;
            pt = strtok (NULL,delimit);
        }
        if(verikontrol==0)
        {
            SonaKomsuSayisiEkle(pointPt-3);
        }
    }


    fclose(fp);

    if(komsularalindi==0)
    {
        DosyaOku(2,2);
    }

}
//Imleci kapamak icin gerekli fonksiyon
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
//Imleci tekrar goruntulemek icin gerekli fonksiyon
void showcursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 10;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
// Yazilarin kordinatlarýný ayarlamak icin gerekli fonksiyon
void gotoxy(int x,int y)
{

    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
// Program acildiginda cikan yazilarin geldigi Fonksiyon
void Giris()
{
    system("@cls||clear");
    int islem=0;
    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
    printf("\n                                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c           1) Sehirleri Listele         %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c           2) Sehir Ekle                %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c           3) Sehir Ara                 %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c           4) Sehir Sil                 %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c           5) Komsu Ekle                %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c           6) Komsu Sil                 %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c           7) Yazdir                    %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c           8) Cikis                     %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c      Yapilacak islemi seciniz          %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);
    hidecursor();

    islem=getch();
    showcursor();

    if(islem==49)
    {
        Listele();
    }
    else if(islem==50)
    {
        KullaniciSehirEkle();
    }
    else if(islem==51)
    {
        SehirArama();
    }
    else if(islem==52)
    {
        SehirSil();

    }
    else if(islem==53)
    {
        KullaniciKomsuEkle();

    }
    else if(islem==54)
    {
        KullaniciKomsuSil();

    }
    else if(islem==55)
    {
        CiktiVer();

    }
    else if(islem==56)
    {
        exit(0);

    }

    else
    {
        printf("\n\n\n\n Lutfen Tabloda Yer Alan Islem Numaralarindan Birine Basiniz\n ");


    }
}
// Kullanicinin komsu eklemesini saglayan fonksiyon
void KullaniciKomsuEkle()
{

    int islemsec=0;
    system("@cls||clear");
    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        1) Plaka Koduna Gore Ekle       %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        2) Sehir Adina Gore Ekle        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        3) Ana Sayfaya Geri Don         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);
    hidecursor();
    islemsec=getch();
    showcursor();
    if(islemsec==49)
    {
        int plakakodu=0,plakakodu2=0;
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c         Plaka Koduna Gore Ekle         %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Komsu Ekliyeceginiz Sehirin Plaka Kodunu Giriniz = ");
        scanf("%d",&plakakodu);
        if(PlakaKodKontrol(plakakodu)==2)
        {
            printf("\n Bu plaka koduna sahipr bir sehir kayitlarda bulunmamaktadir");
        }
        else
        {
            printf("\n\n Eklemek Istediginiz Komsu Sehirin plakasini giriniz = ");
            scanf("%d",&plakakodu2);
            if(PlakaKodKontrol(plakakodu2)==2)
            {
                printf("\n Bu plaka koduna sahipr bir sehir kayitlarda bulunmamaktadir");
            }
            else
            {
                if(komsuEkle(plakakodu,plakakodu2)==5)
                {
                    printf("\n Bu plaka kodunda bir komsuluk mevcut.\n");
                }
                else
                {
                    printf("\n %d Plakali Sehir %d Plakali Sehirin Komsularina Eklenmistir",plakakodu2,plakakodu);
                    KomsuSayisiArttir(plakakodu);
                }
            }
        }
    }
    else if(islemsec==50)
    {
        char sehiradi[256],komsuadi[256];
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c      Sehir Adina Koduna Gore Ekle      %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Komsu Ekliyeceginiz Sehirin Adini Giriniz = ");
        scanf("%s",sehiradi);
        if(SehirAdKontrol(sehiradi)==2)
        {
            printf("\n Bu Sehir adina sahip bir sehir kayitlarda bulunmamaktadir");
        }
        else
        {
            printf("\n\n Eklemek Istediginiz Komsu Sehirin adini giriniz = ");
            scanf("%s",komsuadi);

            if(SehirAdKontrol(sehiradi)==2)
            {
                printf("\n Bu Sehir adina sahip bir sehir kayitlarda bulunmamaktadir");
            }
            else
            {
                if(komsuEkle( PlakaBul(sehiradi), PlakaBul(komsuadi))==5)
                {
                    printf("\n Bu isimde bir komsuluk mevcut.\n");
                }
                else
                {
                    printf("\n %s Adli Sehir %s Adli Sehirin Komsularina Eklenmistir",sehiradi,komsuadi);
                    KomsuSayisiArttir(PlakaBul(sehiradi));
                }

            }
        }

    }
    else if(islemsec==51)
    {
        Giris();
    }




}
// structtan komsu silen fonksiyon
void KullaniciKomsuSil()
{

    int islemsec=0;
    system("@cls||clear");
    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        1) Plaka Koduna Gore Sil        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        2) Sehir Adina Gore Sil         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        3) Ana Sayfaya Geri Don         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);
    hidecursor();
    islemsec=getch();
    showcursor();
    if(islemsec==49)
    {
        int plakakodu=0,plakakodu2=0;
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c         Plaka Koduna Gore Sil          %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Komsusunu Sileceginiz Sehirin Plaka Kodunu Giriniz = ");
        scanf("%d",&plakakodu);
        if(PlakaKodKontrol(plakakodu)==2)
        {
            printf("\n Bu plaka koduna sahip bir sehir kayitlarda bulunmamaktadir");
        }
        else
        {
            printf("\n\n Silmek Istediginiz Komsu Sehirin plakasini giriniz = ");
            scanf("%d",&plakakodu2);
            if(PlakaKodKontrol(plakakodu2)==2)
            {
                printf("\n Bu plaka koduna sahipr bir sehir kayitlarda bulunmamaktadir");
            }
            else
            {


                if(KomsuSil(plakakodu,plakakodu2)==5)
                {
                    printf("\n\n Bu Sehirin Boyle Bir Komsusu Bulunmamakta.");
                }
                else
                {
                    printf("\n\n %d Plakali Sehir %d Plakali Sehirin Komsularindan Silinmistir",plakakodu2,plakakodu);
                    KomsuSayisiAzalt(plakakodu);
                }
            }
        }
    }
    else if(islemsec==50)
    {
        char sehiradi[256],komsuadi[256];
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c      Sehir Adina Koduna Gore Sil       %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Komsusunu Sileceginiz Sehirin Adini Giriniz = ");
        scanf("%s",sehiradi);
        if(SehirAdKontrol(sehiradi)==2)
        {
            printf("\n Bu Sehir adina sahip bir sehir kayitlarda bulunmamaktadir");
        }
        else
        {
            printf("\n\n Silmek Istediginiz Komsu Sehirin  adini giriniz = ");
            scanf("%s",komsuadi);

            if(SehirAdKontrol(sehiradi)==2)
            {
                printf("\n Bu Sehir adina sahip bir sehir kayitlarda bulunmamaktadir");
            }
            else
            {

                if(KomsuSil( PlakaBul(sehiradi), PlakaBul(komsuadi))==5)
                {
                    printf("\n\n Bu Sehirin Boyle Bir Komsusu Bulunmamakta.");
                }
                else
                {
                    printf("\n %s Adli Sehir %s Adli Sehirin Komsularindan Silinmistir",sehiradi,komsuadi);
                    KomsuSayisiAzalt(PlakaBul(sehiradi));
                }
            }
        }

    }
    else if(islemsec==51)
    {
        Giris();
    }




}
// Plaka daha once kullanilmis mi kontrol eden fonksiyon (kullanilmissa 1, kullanilmamissa 2 donduruyor)
int PlakaKodKontrol(int x)
{
    struct node *Plakaliste=ilkPlaka;
    if(x==Plakaliste->SehirPlaka)
    {

        return 1;
    }
    else
    {

        while(Plakaliste->next!=NULL)
        {
            Plakaliste=Plakaliste->next;
            if(x==Plakaliste->SehirPlaka)
            {
                return 1;
            }


        }
        return 2;
    }
}
// Sehir adi daha once kullanilmis mi kontrol eden fonksiyon (kullanilmissa 1, kullanilmamissa 2 donduruyor)
int SehirAdKontrol(char x[256])
{
    struct node *Sehirliste=ilkSehir;
    if(strcmp(strupr(x),strupr(Sehirliste->SehirAd))==0)
    {
        return 1;
    }
    while(Sehirliste->next!=NULL)
    {
        Sehirliste=Sehirliste->next;
        if(strcmp(strupr(x),strupr(Sehirliste->SehirAd))==0)
        {
            return 1;
        }
    }
    return 2;
}
// Ada gore arama yapildiktan sonra, isimle uyusan sehirin diger bilgilerini ceken fonksiyon
void AdaGoreSehirBilgiGetir(char x[256])
{
    int sayac=0;
    struct node *Sehirliste=ilkSehir;
    if(strcmp(strupr(x),strupr(Sehirliste->SehirAd))==0)
    {


    }
    else
    {
        while(Sehirliste->next!=NULL)
        {

            if(strcmp(strupr(x),strupr(Sehirliste->SehirAd))==0)
            {
                break;
            }
            Sehirliste=Sehirliste->next;
            sayac++;

        }
    }
    SayacaGoreBilgiCagir(sayac);

}
// Girilen Sehir Adinin Plakasini Donduren Fonksiyon
int PlakaBul(char x[256])
{
    int sayac=0;
    struct node *Sehirliste=ilkSehir;
    struct node *Plakaliste=ilkPlaka;
    if(strcmp(strupr(x),strupr(Sehirliste->SehirAd))==0)
    {
        sayac=Plakaliste->SehirPlaka;


    }
    else
    {
        while(Sehirliste->next!=NULL)
        {


            Sehirliste=Sehirliste->next;
            Plakaliste=Plakaliste->next;

            if(strcmp(strupr(x),strupr(Sehirliste->SehirAd))==0)
            {
                sayac=Plakaliste->SehirPlaka;

                return sayac;
            }


        }
    }
    return sayac;
}
// Aranan Sehirin ismini sehirdondur degiskenine atan fonksiyon
void SehirBul(int x)
{

    struct node *Sehirliste=ilkSehir;
    struct node *Plakaliste=ilkPlaka;

    if(x==Plakaliste->SehirPlaka)
    {
        strcpy(sehirdondur,Sehirliste->SehirAd);

    }
    else
    {
        while(Plakaliste->next!=NULL)
        {
            Sehirliste=Sehirliste->next;
            Plakaliste=Plakaliste->next;
            if(x==Plakaliste->SehirPlaka)
            {
                strcpy(sehirdondur,Sehirliste->SehirAd);

            }



        }
    }
}
//Komsu eklendiginde artis yapan fonksiyon.
void KomsuSayisiArttir(int x)
{

    struct node *KomsuSayisiListe=ilkKomsuSayisi;
    struct node *Plakaliste=ilkPlaka;

    if(x==Plakaliste->SehirPlaka)
    {
        KomsuSayisiListe->SehirKomsuSayisi=KomsuSayisiListe->SehirKomsuSayisi+1;

    }
    else
    {
        while(Plakaliste->next!=NULL)
        {
            KomsuSayisiListe=KomsuSayisiListe->next;
            Plakaliste=Plakaliste->next;
            if(x==Plakaliste->SehirPlaka)
            {
                KomsuSayisiListe->SehirKomsuSayisi=KomsuSayisiListe->SehirKomsuSayisi+1;

            }

        }
    }
}
//Komsu Eklendiginde azaltma yapan fonksiyon
void KomsuSayisiAzalt(int x)
{

    struct node *KomsuSayisiListe=ilkKomsuSayisi;
    struct node *Plakaliste=ilkPlaka;

    if(x==Plakaliste->SehirPlaka)
    {
        KomsuSayisiListe->SehirKomsuSayisi=KomsuSayisiListe->SehirKomsuSayisi-1;

    }
    else
    {
        while(Plakaliste->next!=NULL)
        {
            KomsuSayisiListe=KomsuSayisiListe->next;
            Plakaliste=Plakaliste->next;
            if(x==Plakaliste->SehirPlaka)
            {
                KomsuSayisiListe->SehirKomsuSayisi=KomsuSayisiListe->SehirKomsuSayisi-1;

            }

        }
    }
}
// Bolge Kontrol Fonksiyonu
void BolgeBul(int x)
{

    struct node *BolgeListe=ilkBolge;
    struct node *Plakaliste=ilkPlaka;

    if(x==Plakaliste->SehirPlaka)
    {
        strcpy(bolgedondur,BolgeListe->SehirBolge);

    }
    else
    {
        while(Plakaliste->next!=NULL)
        {

            BolgeListe=BolgeListe->next;
            Plakaliste=Plakaliste->next;
            if(x==Plakaliste->SehirPlaka)
            {
                strcpy(bolgedondur,BolgeListe->SehirBolge);

            }



        }
    }
}
// Plakaya gore arama yapilmissa, plaka ile uyusan sehirin diger bilgilerini ceken fonksiyon
void PlakayaGoreSehirBilgiGetir(int x)
{
    int sayac=0;
    struct node *Plakaliste=ilkPlaka;

    if(x==Plakaliste->SehirPlaka)

    {

    }
    else
    {
        while(Plakaliste->next!=NULL)
        {

            if(x==Plakaliste->SehirPlaka)
            {
                break;
            }
            Plakaliste=Plakaliste->next;
            sayac++;

        }
    }
    SayacaGoreBilgiCagir(sayac);

}
// Bolgeye gore arama yapilmissa, Bolge ile uyusan sehirin diger bilgilerini ceken fonksiyon
void BolgeyeGoreSehirBilgiGetir(char x[256])
{
    struct node *Plakaliste=ilkPlaka;
    struct node *Sehirliste2=ilkSehir;
    struct node *BolgeListe2=ilkBolge;
    struct node *KomsuSayisiListe=ilkKomsuSayisi;
    int toplamkayit=0;

    printf("\n [Plaka]           [Sehir Adi]          [Bolge]      [Komsu Sayisi]\n\n");
    if (strcmp(strupr(x),strupr(BolgeListe2->SehirBolge))==0)
    {
        printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
        toplamkayit++;
    }
    while(BolgeListe2->next!=NULL)
    {
        Plakaliste=Plakaliste->next;
        Sehirliste2=Sehirliste2->next;
        BolgeListe2=BolgeListe2->next;
        KomsuSayisiListe=KomsuSayisiListe->next;

        if(strcmp(strupr(x),strupr(BolgeListe2->SehirBolge))==0)
        {
            printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
            toplamkayit++;
        }


    }

    printf("\n Toplam Kayit = %d ",toplamkayit);
}
// Komsu Sayisina gore arama yapilmissa, Komsu Sayisi ile uyusan sehirin diger bilgilerini ceken fonksiyon
void KomsuSayisinaGoreListele(int x,int y,int op)
{
    struct node *Plakaliste=ilkPlaka;
    struct node *Sehirliste2=ilkSehir;
    struct node *BolgeListe2=ilkBolge;
    struct node *KomsuSayisiListe=ilkKomsuSayisi;
    int toplamkayit=0;

    printf("\n [Plaka]           [Sehir Adi]          [Bolge]      [Komsu Sayisi]\n\n");

    if(op==1)
    {


        if (x>(KomsuSayisiListe->SehirKomsuSayisi))
        {
            printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
            toplamkayit++;
        }
        while(Plakaliste->next!=NULL)
        {
            Plakaliste=Plakaliste->next;
            Sehirliste2=Sehirliste2->next;
            BolgeListe2=BolgeListe2->next;
            KomsuSayisiListe=KomsuSayisiListe->next;

            if (x>(KomsuSayisiListe->SehirKomsuSayisi))
            {
                printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
                toplamkayit++;
            }


        }
    }
    else if(op==2)
    {


        if (x<(KomsuSayisiListe->SehirKomsuSayisi))
        {
            printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
            toplamkayit++;
        }
        while(Plakaliste->next!=NULL)
        {
            Plakaliste=Plakaliste->next;
            Sehirliste2=Sehirliste2->next;
            BolgeListe2=BolgeListe2->next;
            KomsuSayisiListe=KomsuSayisiListe->next;

            if (x<(KomsuSayisiListe->SehirKomsuSayisi))
            {
                printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
                toplamkayit++;
            }


        }
    }

    else if(op==3)
    {


        if (x==(KomsuSayisiListe->SehirKomsuSayisi))
        {
            printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
            toplamkayit++;
        }
        while(Plakaliste->next!=NULL)
        {
            Plakaliste=Plakaliste->next;
            Sehirliste2=Sehirliste2->next;
            BolgeListe2=BolgeListe2->next;
            KomsuSayisiListe=KomsuSayisiListe->next;

            if (x==(KomsuSayisiListe->SehirKomsuSayisi))
            {
                printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
                toplamkayit++;
            }

        }


    }

    else if(op==4)
    {


        if (x<(KomsuSayisiListe->SehirKomsuSayisi) &&  y>(KomsuSayisiListe->SehirKomsuSayisi))
        {
            printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
            toplamkayit++;
        }
        while(Plakaliste->next!=NULL)
        {
            Plakaliste=Plakaliste->next;
            Sehirliste2=Sehirliste2->next;
            BolgeListe2=BolgeListe2->next;
            KomsuSayisiListe=KomsuSayisiListe->next;

            if (x<(KomsuSayisiListe->SehirKomsuSayisi) &&  y>(KomsuSayisiListe->SehirKomsuSayisi))
            {
                printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
                toplamkayit++;
            }


        }
    }

    printf("\n Toplam Kayit = %d ",toplamkayit);
}
// Diger fonksiyonlardan gelen donme sayisina gore, struct icinde donen ve eslesen seheirleri ekrana basan fonksiyon
void SayacaGoreBilgiCagir(int sayac)
{
    int kontrolsayac=0;
    struct node *Plakaliste=ilkPlaka;
    struct node *Sehirliste2=ilkSehir;
    struct node *BolgeListe=ilkBolge;
    struct node *KomsuSayisiListe=ilkKomsuSayisi;
    struct Komsu *KomsularListe = Plakaliste->right;

    if (sayac==0)
    {
        printf("%5d%23s%16s%16d\n\n\n\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
        printf("                      [ %s Sehirinin Komsulari ]\n",Sehirliste2->SehirAd);
        printf("\n [Plaka]                    [Sehir Adi]                [Bolge]     \n\n");
        KomsularListe=Plakaliste->right;
        while(KomsularListe!=NULL)
        {
            SehirBul(KomsularListe->plakaKodu);
            BolgeBul(KomsularListe->plakaKodu);
            printf("%5d%32s%22s\n",KomsularListe->plakaKodu,sehirdondur,bolgedondur);
            KomsularListe=KomsularListe->right;

        }
        printf("\n");
    }
    else
    {


        while(Plakaliste->next!=NULL)
        {

            Plakaliste=Plakaliste->next;
            Sehirliste2=Sehirliste2->next;
            BolgeListe=BolgeListe->next;
            KomsuSayisiListe=KomsuSayisiListe->next;


            if(kontrolsayac==sayac-1)
            {
                printf("%5d%23s%16s%16d\n\n\n\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
                printf("                      [ %s Sehirinin Komsulari ]\n",Sehirliste2->SehirAd);
                printf("\n [Plaka]                    [Sehir Adi]                [Bolge]     \n\n");
                KomsularListe=Plakaliste->right;
                while(KomsularListe!=NULL)
                {
                    SehirBul(KomsularListe->plakaKodu);
                    BolgeBul(KomsularListe->plakaKodu);
                    printf("%5d%32s%22s\n",KomsularListe->plakaKodu,sehirdondur,bolgedondur);
                    KomsularListe=KomsularListe->right;

                }
                printf("\n");
            }
            kontrolsayac++;


        }
    }

}
// Kullanicinin sehir eklemesini saglayan fonksiyon
void KullaniciSehirEkle()
{
    int plaka,Komsusayisi,komsuplaka;
    char Sehir[256],bolge[256];
    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
    system("@cls||clear");
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                          %c                              %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                              %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c         Sehir Ekleme         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                              %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                              %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

PlakaSor:
    printf("\n\n Sehirin Plakasini Giriniz = ");
    scanf("%d",&plaka);
    if(PlakaKodKontrol(plaka)==1)
    {
        printf("\n Bu plaka kodu kullanilmakta, Baska bir plaka kodu giriniz \n");
        goto PlakaSor;
    }
SehirSor:
    printf("\n Sehirin Adini Giriniz = ");
    scanf("%s",Sehir);
    if(SehirAdKontrol(Sehir)==1)
    {
        printf("\n Bu Sehir Adi kullanilmakta, Baska bir Sehir Adi giriniz \n");
        goto SehirSor;
    }
    printf("\n Sehirin Bolgesini Giriniz = ");
    scanf("%s",bolge);
    printf("\n Sehirin Komsu Sayisini Giriniz = ");
    scanf("%d",&Komsusayisi);



    SonaSehirEkle(Sehir);
    SonaPlakaEkle(plaka);
    SonaBolgeEkle(bolge);
    SonaKomsuSayisiEkle(Komsusayisi);

    for(int i=0; i<Komsusayisi; i++)
    {
        printf("\n %d. Komsunun Plakasini Giriniz = ",i+1);
        scanf("%d",&komsuplaka);
        komsuEkle(plaka,komsuplaka);
    }

    printf("\n\n %s Sehiri Basariyla Eklenmistir.",Sehir);
}
// Sehir sil ekrani icerigini tutan fonksiyon
void SehirSil()
{
    int islemsec=0;
    system("@cls||clear");
    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        1) Plaka Koduna Gore Sil        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        2) Sehir Adina Gore Sil         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c        3) Ana Sayfaya Geri Don         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);
    hidecursor();
    islemsec=getch();
    showcursor();
    if(islemsec==49)
    {
        int plakakodu=0;
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c         Plaka Koduna Gore Sil          %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Plaka Kodunu Giriniz = ");
        scanf("%d",&plakakodu);
        if(PlakaKodKontrol(plakakodu)==2)
        {
            printf("\n Bu plaka koduna sahipr bir sehir kayitlarda bulunmamaktadir");
        }
        else
        {
            DugumdenSil(plakakodu);
            printf("\n %d Plakali Sehir Basariyla Silinmistir",plakakodu);
        }
    }
    else if(islemsec==50)
    {
        char sehiradi[256];
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c      Sehir Adina Koduna Gore Sil       %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Sehir Adini Giriniz = ");
        scanf("%s",sehiradi);
        if(SehirAdKontrol(sehiradi)==2)
        {
            printf("\n Bu isimde bir sehir kayitlarda bulunmamaktadir");
        }
        else
        {
            DugumdenSil(PlakaBul(sehiradi));
            printf("\n %s Sehiri Basariyla Silinmistir",sehiradi);
        }

    }
    else if(islemsec==51)
    {
        Giris();
    }

}
// Sehir arama fonksiyonu
void SehirArama()
{
    int islem=0;
basa:


    system("@cls||clear");
    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c      1) Sehir Adina Gore Arama         %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c      2) Plaka Koduna Gore Arama        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c      3) Bolgeye Gore Arama             %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c      4) Komsu Sayisina Gore Arama      %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c      5) Bonus                          %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c      6) Ana Sayfaya Geri Don           %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c         Arama Seklini Seciniz          %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);
    hidecursor();
    islem=getch();
    showcursor();
    if(islem==49)
    {
        char sehir[256];
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c         Sehir Adina Gore Arama         %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Aranicak Sehirin Adini Giriniz = ");
        scanf("%s",sehir);
        if(SehirAdKontrol(sehir)==2)
        {
            int yeniislem=0;
            printf("\n Boyle Bir Sehir Mevcut Degildir.\n");
            printf("\n 1) Yeni Sehir Ekle\n");
            printf(" 2) Devam Et");
            printf("\n\n Yaplicak islemi seciniz...");
            yeniislem=getch();
            if(yeniislem==49)
            {
                KullaniciSehirEkle();
            }
            else
            {
                Giris();
            }


        }
        else
        {
            printf("\n [Plaka]           [Sehir Adi]          [Bolge]      [Komsu Sayisi]\n\n");
            AdaGoreSehirBilgiGetir(sehir);
        }
    }
    else if(islem==50)
    {

        int plaka;
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c        Plaka Koduna Gore Arama         %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Aranicak Plaka Kodunu Adini Giriniz = ");
        scanf("%d",&plaka);
        if(PlakaKodKontrol(plaka)==2)
        {
            int yeniislem2=0;
            printf("\n Boyle Bir Plaka Kayidi Mevcut Degildir.\n");
            printf("\n 1) Yeni Sehir Ekle\n");
            printf(" 2) Devam Et");
            printf("\n\n Yaplicak islemi seciniz...");
            yeniislem2=getch();
            if(yeniislem2==49)
            {
                KullaniciSehirEkle();
            }
            else
            {
                Giris();
            }

        }
        else
        {
            printf("\n [Plaka]           [Sehir Adi]          [Bolge]      [Komsu Sayisi]\n\n");
            PlakayaGoreSehirBilgiGetir(plaka);
        }

    }
    else if(islem==51)
    {
        char bolge[256];
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c          Bolgeye Gore Arama            %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c                                        %c",dikeycizgi,dikeycizgi);
        printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

        printf("\n\n Bolge Kodunu Giriniz = ");
        scanf("%s",bolge);
        BolgeyeGoreSehirBilgiGetir(bolge);
    }
    else if(islem==52)
    {

        int KomsuSayisi=0,KomsuSayisi2=0,islem2=0,op=0;
basa2:
        system("@cls||clear");
        int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;
        printf("\n                                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c  1) Komsu Sayisi X'ten Buyuk Olan Sehirleri Bul       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c  2) Komsu Sayisi X'ten Kucuk Olan Sehirleri Bul       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c  3) Komsu Sayisi X'e Esit Olan Sehirleri Bul          %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c  4) Komsu Sayisi X ile Y arasinda Olan Sehirleri Bul  %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c  5) Arama Sayfasina Geri Don                          %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c  6) Ana Sayfaya Geri Don                              %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c               Arama Kosulunu Seciniz                  %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c                                                       %c",dikeycizgi,dikeycizgi);
        printf("\n                                       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);
        hidecursor();
        islem2=getch();
        showcursor();



        if(islem2==49)
        {

            system("@cls||clear");
            int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;

            printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c  Komsu Sayisi X'ten Buyuk Olan Sehirleri Bul  %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

            printf("\n\n X Degerini Giriniz = ");
            scanf("%d",&KomsuSayisi);
            op=2;
            KomsuSayisinaGoreListele(KomsuSayisi,KomsuSayisi2,op);
        }



        else if(islem2==50)
        {
            system("@cls||clear");
            int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;

            printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c  Komsu Sayisi X'ten Kucuk Olan Sehirleri Bul  %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

            printf("\n\n X Degerini Giriniz = ");
            scanf("%d",&KomsuSayisi);
            op=1;
            KomsuSayisinaGoreListele(KomsuSayisi,KomsuSayisi2,op);
        }
        else if(islem2==51)
        {
            system("@cls||clear");
            int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;

            printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c    Komsu Sayisi X'e Esit Olan Sehirleri Bul   %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                               %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

            printf("\n\n X Degerini Giriniz = ");
            scanf("%d",&KomsuSayisi);
            op=3;
            KomsuSayisinaGoreListele(KomsuSayisi,KomsuSayisi2,op);
        }
        else if(islem2==52)
        {
            system("@cls||clear");
            int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;

            printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
            printf("\n                                          %c                                                    %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                                    %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                                    %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c  Komsu Sayisi X ile Y arasinda Olan Sehirleri Bul  %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                                    %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                                    %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c                                                    %c",dikeycizgi,dikeycizgi);
            printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

            printf("\n\n X Degerini Giriniz = ");
            scanf("%d",&KomsuSayisi);
            printf("\n Y Degerini Giriniz = ");
            scanf("%d",&KomsuSayisi2);
            if(KomsuSayisi>KomsuSayisi2)
            {
                int temp=KomsuSayisi2;
                KomsuSayisi2=KomsuSayisi;
                KomsuSayisi=temp;
            }
            op=4;
            KomsuSayisinaGoreListele(KomsuSayisi,KomsuSayisi2,op);

        }
        else if(islem2==53)
        {
            SehirArama();
        }
        else if(islem2==54)
        {
            Giris();
        }
        else
        {
            printf("\n\n\n\n Lutfen Tabloda Yer Alan Islem Numaralarindan Birine Basiniz\n ");
            getch();
            goto basa2;
        }
    }
    else if(islem==53)
    {
        Bonus();
    }
    else if(islem==54)
    {
        Giris();
    }
    else
    {
        printf("\n\n\n\n Lutfen Tabloda Yer Alan Islem Numaralarindan Birine Basiniz\n ");
        getch();
        goto basa;
    }

}
// Bonus isterlerle alakali gerekli fonksiyon.
void Bonus()
{
    int xaralik=0,yaralik=0,sehirsayisi=0,toplamkayit=0,sayac=0;
    int sehirplakatut[256];
    char sehir[256];



    system("@cls||clear");
    int solustkose=201,dikeycizgi=186,solaltkose=200,duzcizgi=205,sagustkose=187,sagaltkose=188;



    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solustkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagustkose);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c             Bonus             %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c                               %c",dikeycizgi,dikeycizgi);
    printf("\n                                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",solaltkose,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,duzcizgi,sagaltkose);

    printf("\n\n X Degerini Giriniz = ");
    scanf("%d",&xaralik);
    printf("\n Y Degerini Giriniz = ");
    scanf("%d",&yaralik);
    printf("\n Girilecek Sehir Sayisini Yaziniz = ");
    scanf("%d",&sehirsayisi);

    for(int i=0; i<sehirsayisi; i++)
    {
        printf("\n %d.Sehirin Adini Giriniz = ",i+1);
        scanf("%s",sehir);
        sehirplakatut[i]= PlakaBul(sehir);
    }
    printf("\n");
    printf("\n [Plaka]           [Sehir Adi]          [Bolge]      [Komsu Sayisi]      \n\n");
    if(xaralik>yaralik)
    {
        int temp=yaralik;
        yaralik=xaralik;
        xaralik=temp;
    }



    struct node *Plakaliste=ilkPlaka;
    struct node *Sehirliste2=ilkSehir;
    struct node *BolgeListe2=ilkBolge;
    struct node *KomsuSayisiListe=ilkKomsuSayisi;
    struct node *SehirGez=ilkPlaka;
    struct Komsu *KomsuGez;

    if (xaralik<(KomsuSayisiListe->SehirKomsuSayisi) &&  yaralik>(KomsuSayisiListe->SehirKomsuSayisi))
    {
        sayac=0;
        KomsuGez=SehirGez->right;

        while(KomsuGez!=NULL)
        {
            if(KomsuGez->plakaKodu==sehirplakatut[sayac])
            {
                sayac++;
             KomsuGez=SehirGez->right;
            }
            else
            {
                 KomsuGez=KomsuGez->right;
            }

        }
        if(sayac==sehirsayisi)
        {
            printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
            toplamkayit++;
        }

    }
    while(Plakaliste->next!=NULL)
    {
        sayac=0;

        SehirGez=SehirGez->next;
        Plakaliste=Plakaliste->next;
        Sehirliste2=Sehirliste2->next;
        BolgeListe2=BolgeListe2->next;
        KomsuSayisiListe=KomsuSayisiListe->next;
        KomsuGez=SehirGez->right;

        if (xaralik<(KomsuSayisiListe->SehirKomsuSayisi) &&  yaralik>(KomsuSayisiListe->SehirKomsuSayisi))
        {




            while(KomsuGez!=NULL)
            {
                  if(KomsuGez->plakaKodu==sehirplakatut[sayac])
            {
                sayac++;
                KomsuGez=SehirGez->right;
            }
            else
            {
                 KomsuGez=KomsuGez->right;
            }
            }
            if(sayac==sehirsayisi)
            {
                printf("%5d%23s%16s%16d\n",Plakaliste->SehirPlaka,Sehirliste2->SehirAd,BolgeListe2->SehirBolge,KomsuSayisiListe->SehirKomsuSayisi);
                toplamkayit++;
            }


        }


    }


    printf("\n\n Toplam kayit = %d",toplamkayit);







}
// Structtan verinin cikarilmasini saglayan fonksiyon
void DugumdenSil(int x)
{
    struct node *PlakaSil=ilkPlaka;
    struct node *SehirSil=ilkSehir;
    struct node *BolgeSil=ilkBolge;
    struct node *KomsuSayisiSil=ilkKomsuSayisi;




    while(PlakaSil!=NULL)
    {
        if(PlakaSil->SehirPlaka==x)
            break;
        else
        {
            PlakaSil=PlakaSil->next;

            SehirSil=SehirSil->next;

            BolgeSil=BolgeSil->next;

            KomsuSayisiSil=KomsuSayisiSil->next;
        }
    }



    if(PlakaSil!=NULL)
    {
        if(PlakaSil==ilkPlaka)
        {
            PlakaSil->next->prev=PlakaSil->prev;

            SehirSil->next->prev=SehirSil->prev;

            BolgeSil->next->prev=BolgeSil->prev;

            KomsuSayisiSil->next->prev=KomsuSayisiSil->prev;

            ilkPlaka=ilkPlaka->next;
            ilkSehir=ilkSehir->next;
            ilkBolge=ilkBolge->next;
            ilkKomsuSayisi=ilkKomsuSayisi->next;
        }
        else if(PlakaSil==sonPlaka)
        {
            PlakaSil->prev->next=PlakaSil->next;

            SehirSil->prev->next=SehirSil->next;

            BolgeSil->prev->next=BolgeSil->next;

            KomsuSayisiSil->prev->next=KomsuSayisiSil->next;

            sonPlaka=sonPlaka->prev;
            sonSehir=sonSehir->prev;
            sonBolge=sonBolge->prev;
            sonKomsuSayisi=sonKomsuSayisi->prev;
        }
        else
        {
            PlakaSil->prev->next=PlakaSil->next;
            PlakaSil->next->prev=PlakaSil->prev;

            SehirSil->prev->next=SehirSil->next;
            SehirSil->next->prev=SehirSil->prev;

            BolgeSil->prev->next=BolgeSil->next;
            BolgeSil->next->prev=BolgeSil->prev;

            KomsuSayisiSil->prev->next=KomsuSayisiSil->next;
            KomsuSayisiSil->next->prev=KomsuSayisiSil->prev;
        }


        free(PlakaSil);
        free(SehirSil);
        free(BolgeSil);
        free(KomsuSayisiSil);
    }
}
// Plaka numarasina gore kucukten buyuge siralama yapan fonksiyon
void Sirala()
{
    struct node *SiraliListePlaka;
    struct node *SiraliListeSehir;
    struct node *SiraliListeBolge;
    struct node *SiraliListeKomsuSayisi;
    struct node *PlakaListe=ilkPlaka;

    while(PlakaListe!=sonPlaka)
    {
        SiraliListePlaka=ilkPlaka;
        SiraliListeSehir=ilkSehir;
        SiraliListeBolge=ilkBolge;
        SiraliListeKomsuSayisi=ilkKomsuSayisi;

        while(SiraliListePlaka!=sonPlaka)
        {
            if(SiraliListePlaka->SehirPlaka>SiraliListePlaka->next->SehirPlaka)
            {
                int temp=SiraliListePlaka->SehirPlaka;
                SiraliListePlaka->SehirPlaka=SiraliListePlaka->next->SehirPlaka;
                SiraliListePlaka->next->SehirPlaka=temp;

                struct Komsu *gecici = SiraliListePlaka->right;
                SiraliListePlaka->right=SiraliListePlaka->next->right;
                SiraliListePlaka->next->right=gecici;


                char temp2[256];
                strcpy((temp2),(SiraliListeSehir->SehirAd));
                strcpy((SiraliListeSehir->SehirAd),(SiraliListeSehir->next->SehirAd));
                strcpy((SiraliListeSehir->next->SehirAd),(temp2));

                char temp3[256];
                strcpy((temp3),(SiraliListeBolge->SehirBolge));
                strcpy((SiraliListeBolge->SehirBolge),(SiraliListeBolge->next->SehirBolge));
                strcpy((SiraliListeBolge->next->SehirBolge),(temp3));


                int temp4=SiraliListeKomsuSayisi->SehirKomsuSayisi;
                SiraliListeKomsuSayisi->SehirKomsuSayisi=SiraliListeKomsuSayisi->next->SehirKomsuSayisi;
                SiraliListeKomsuSayisi->next->SehirKomsuSayisi=temp4;




            }
            SiraliListePlaka=SiraliListePlaka->next;
            SiraliListeSehir=SiraliListeSehir->next;
            SiraliListeBolge=SiraliListeBolge->next;
            SiraliListeKomsuSayisi=SiraliListeKomsuSayisi->next;

        }
        PlakaListe=PlakaListe->next;
    }
}
int main()
{

    DosyaOku(1,0);
tekrar:
    Sirala();
    Giris();
    printf("\n\n\n Devam Etmek Icin Bir Tusa Basiniz...\n ");
    getch();
    system("@cls||clear");
    goto tekrar;

    return 0;
}













