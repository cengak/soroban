#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include "./include/color.hpp"
using namespace std;

int result[13];
int step_result, result_control,  value1_bs, value2_bs, result_bs, quo_bs;
int colour_control = 13;
string exp_step;

void print_soroban(int result[])
{
    int result_p[13];
    int control;
    char board[8][13];


    for (int x=0; x<13; x++)
    {
        result_p[x] = result[x];

    }


    std::cout << endl << dye::blue("Adim :") << step_result << endl;
    std::cout <<dye::yellow(exp_step) << endl;


    for (int x=0; x<13; x++)
    {
        if(colour_control == x)
        {
            std::cout << dye::red(result_p[x]) << "  " ;
        }
        else
        {
            cout << result_p[x] << "  ";


        }


    }
    cout << endl;
    for(int x=0; x<37; x++)
    {
        cout << "-";
    }

    if (result_control<10)
    {

        ///Convert Soroban Start

        for (int x = 0; x < 13; ++x)
        {
            //Çizgi Üstü Start
            if(result_p[x]>=5)
            {
                board[0][x] = '|';
                board[1][x] = 'O';
                result_p[x] = result_p[x] - 5;
            }

            else if(result_p[x]<5)
            {
                board[0][x] = 'O';
                board[1][x] = '|';
            }

//Çizgi Üstü End

// Ara çizgi
            board[2][x] = '-';

//Çizgi Altý Start
            // if(result_p[x]>=0)
            // {

            for(int y=3; y<8; y++)
            {
                control = y-3;

                if(control<result_p[x])
                {
                    board[y][x] = 'O';
                }

                else if(control==result_p[x])
                {
                    board[y][x] = '|';
                }

                else if(control>result_p[x])
                {
                    board[y][x] = 'O';
                }
            }
            //}
//Çizgi Altý End

        }
        cout << endl;
///Convert Soroban End

///Print Soroban Start
        for (int x = 0; x < 8; x++)
        {
            for (int y = 0; y < 13; y++)
                cout << board[x][y] << "  " ;
            cout << endl;
        }
        cout << endl;
///Print Soroban End
    }


}


void print_soroban_divide(int result[], int start_value_bs, int result_value_bs )
{
    int result_p[13];
    int control;
    char board[8][13];
    for (int x=0; x<13; x++)
        for (int x=0; x<13; x++)
        {
            result_p[x] = result[x];

        }


    std::cout << endl << dye::blue("Adim :") << step_result << endl;
    std::cout <<dye::yellow(exp_step) << endl;

    for (int x=0; x<13; x++)
    {
        if(colour_control == x)
        {
            std::cout << dye::red(result_p[x]) << "  " ;
        }
        else
        {
            cout << result_p[x] << "  ";


        }


    }
    cout << endl;
    for(int x=0; x<37; x++)
    {
        cout << "-";
    }



    if(result_control<10)
    {
        ///Convert Soroban Start
        for (int x = 0; x < 13; ++x)
        {

//Çizgi Üstü Start
            if(result_p[x]>=5)
            {
                board[0][x] = '|';
                board[1][x] = 'O';
                result_p[x] = result_p[x] - 5;
            }

            else if(result_p[x]<5)
            {
                board[0][x] = 'O';
                board[1][x] = '|';
            }

//Çizgi Üstü End

// Ara çizgi
            board[2][x] = '-';

//Çizgi Alti Start

            for(int y=3; y<8; y++)
            {
                control = y-3;

                if(control<result_p[x])
                {
                    board[y][x] = 'O';
                }

                else if(control==result_p[x])
                {
                    board[y][x] = '|';
                }

                else if(control>result_p[x])
                {
                    board[y][x] = 'O';
                }
            }

//Çizgi Alti End

        }
//Arabolme Start
        //sütun döngüsü



        for(int y=start_value_bs; y<=12-result_value_bs; y++)
        {

            for(int x=0; x<8; x++)
            {
                board[x][y] = ' ';
            }
        }

//Arabolme End
        cout << endl;
///Convert Soroban End
///Print Soroban Start
        for (int x = 0; x < 8; ++x)
        {
            for (int y = 0; y < 13; ++y)
                cout << board[x][y] << "  " ;
            cout << endl;


        }
///Print Soroban End




    }


}




void add(int value_1d[], int value_2d[])
{
    int step_for; // döngüye kaçtan başlayacak
    int elde;   // Basamakların toplamı 9'dan buyuk ise toplamın onlar basamağı

    // Girilen birinci sayıyı main içinde value_1d dizine aktarmıştık.  Bunu tekrar result dizisine aktarıyoruz
    // işlemler resuld dizisi üzerinde kademe kedeme yapılacak ve gösterilecek
    for (int i=0; i<13; i++)
    {
        result[i] = value_1d[i];

    }

    // döngünün kaçıncı elemandan başlayacağını belirliyoruz
    step_for=13-value2_bs;


    ///ADD START
    // Başlangıç değerini yazdırıyoruz
    step_result = 0;
    exp_step = "Baslangic";
    step_result++;
    result_control = 0;
    colour_control = 13;
    print_soroban(result);
    system("pause");
    //Toplama işlemine başladık

    //Eklenen sayının basamak sayısı kadar döngü sağlanır
    for (int i=step_for; i<13; i++)
    {
        // Basamak basamak soldan sağa toplama işlemi yapılıyor.
        exp_step = "Islem yap";
        step_result++;
        result[i] = result[i] + value_2d[i];
        result_control = result[i];
        colour_control = i;
        print_soroban(result);
        colour_control = 13;
        result_control = 0 ;
        system("pause");

        // Basamakların toplamı sonucunda basamak değeri 9'dan büyük ise eldeyi soldaki basamağa ekle.
        //Soldaki basamağın değeri de  9'dan küçük oluncaya kadar  sıra ile devam et
        if(result[i]>9)
        {
            // döngü işlem yapılan basamaktan en soldaki basamağa kadar devam eder.
            // dizide en soldaki basamak result[0] dır.
            for (int j=i; j>=0; j--)
            {

                //Henüz bir önceki basamağa gitmedi ise yazdırma
                if(i!=j)
                {
                    exp_step = "Eldeyi soldaki basamaga ekle";
                    step_result++;
                    result_control = result[j];
                    colour_control = j;
                    print_soroban(result);
                    colour_control = 13;
                    result_control = 0 ;
                    system("pause");
                }

                // Basamak değeri 9'dan büyük ise eldeyi bir sonraki basamağa yazdır
                if(result[j]>9)
                {
                    elde = result[j]/10;
                    result[j] = result[j]%10;
                    result[j-1]  = result[j-1] + elde;
                }

                //Basamak değeri )9'dan küçük ise döngüyü durdur.
                else if (result[j]<=9)
                {
                    break;
                }

            }


        }


    }
    cout << "Islem tamamlandi" << endl;


///ADD END

}



void subtract(int value_1d[], int value_2d[])
{

    int step_for; //Ana döngünün belirleyen  değişken. Döngü step_for'dan 13'ten küçük olana kadar devam eder

    for (int i=0; i<13; i++)
    {
        result[i] = value_1d[i];

    }

    // step for 13 - çıkarılanın basamak sayısı olarak değer atanır
    step_for=13-value2_bs;

    ///SUBTRACT START
    exp_step = "Baslangic";
    step_result++;
    result_control = 0;
    colour_control = 13;
    print_soroban(result);
    system("pause");

    for(int i=step_for; i<13; i++)
    {
        // çıkarılan basamak çıkan basamaktan küçük ise soldaki sıfırdan büyük ilk basamaktan bir onluk al
        if(result[i] < value_2d[i])
        {

            // soldaki ve sıfırdan büyük ilk basamaktan bir onluk al
            int k=0;
            for (int j=i-1; j>0; j--)
            {
                if(result[j]>0)
                {
                    exp_step = "Soldan ve sifidan buyuk ilk degerden bir onluk al";
                    step_result++;
                    result[j] = result[j] - 1;
                    result_control = result[j];
                    colour_control = j;
                    print_soroban(result);
                    system("pause");
                    // dizide hangi basamaktan sıfırı aldı ise bir yandakine eklenmesi için belirlendi. Sonraki döngüde kullanılacak
                    k=j+1;
                    break;
                }

            }



            // alinan onlugu "0" olan yan basamağa ekle ve yan basamaga eklemek icin bir onluk al
            // onluk alirken kac basamak sola gittiysek dongu o kadar devam eder
            // Döngü onluk alınan basamaktan sonraki basamaktan başlar. Onluk isteyen basamaktan önce biter
            for(int j=k; j<i; j++)
            {
                exp_step = "Alinan onlugu ekle ve Yana eklemek icin bir onluk al";
                step_result++;
                result[j] = result[j] + 10 - 1;
                result_control = result[j];
                colour_control = j;
                print_soroban(result);
                system("pause");


            }


            //Onluk isteyen basamağa onluğu ekle
            exp_step = "Alinan onlugu ekle";
            step_result++;
            result[i] = result[i]+10;
            result_control = result[i];
            colour_control = i;
            print_soroban(result);
            result_control = 0 ;
            system("pause");

            //Onluk eklendikten sonra işlemi yap
            exp_step = "Islemi yap";
            step_result++;
            result[i] = result[i]-value_2d[i];
            result_control = result[i];
            colour_control = i;
            print_soroban(result);
            result_control = 0 ;
            system("pause");
        }

        // Çıkarılan basamak, çıkan basamaktan büyük ise işlemi doğrudan yap
        else if (result[i] >= value_2d[i])
        {
            exp_step = "Islemi yap";
            step_result++;
            result[i] = result[i] - value_2d[i];
            result_control = result[i];
            colour_control = i;
            print_soroban(result);
            result_control = 0 ;
            system("pause");
        }

    }

///SUBTRACT END
    cout << "Islem tamamlandi" << endl;

}



void multiply (int value_1d[], int value_2d[])
{
    int elde, step_for, k;

    //Döngünün çıkarılan disizinin hangi basamağından başlayacağını belirle
    step_for=13-value2_bs;

    ///MULTIPLAY  START
    // Resul değişkenine varsayılan değer olarak value_1d yani çarpılanı ata
    k=0; // Çarpılan solda yazacağından k=00 yani result[0] 'dan başlayarak elemanları diziye aktar
    for(int i=13-value1_bs; i<13; i++)
    {
        result[k] = value_1d[i];
        k++;

    }

    step_result=0;
    // burada int L = 0 dikkat
    int l=0;
    exp_step = "Baslangic";
    step_result++;
    result_control = 0;
    colour_control = 13;
    print_soroban_divide(result, value1_bs, result_bs);
    system("pause");

    //çarpan döngüsü  Çarpanın her bir basamağı sağdan sola alınır
    for(int i=12; i>12-value2_bs; i--)
    {
        k=12-l;
        //çarpılan döngüsü Çarpanın alınan basamağı çarpılan basamağının her biri ile çarpılır
        //çarpanın baxamağı değiştikçe her seferinde bir sola kaydırılark toplanır
        for(int j=value1_bs-1; j>=0; j--)
        {
            exp_step = "Islem yap";
            result[k] = result[k]+result[j]*value_2d[i];
            step_result++;
            result_control = result[k];
            colour_control = k;
            print_soroban_divide(result, value1_bs, result_bs);
            result_control = 0 ;
            system("pause");

            // Toplamadaki gibi işlem gören basamağın değeri 9'dan büyük olduğunda eldeyi soldaki basamağa ekle
            if(result[k]>9)
            {
                for (int m=k; m>0; m--)
                {

                    if(k!=m)
                    {
                        exp_step =  "Eldeyi soldaki basamaga ekle";
                        step_result++;
                        result_control = result[m];
                        colour_control = m;
                        print_soroban_divide(result, value1_bs, result_bs);
                        result_control = 0 ;
                        system("pause");
                    }

                    if(result[m]>9)
                    {
                        //cout << result[i] << "--";
                        elde = result[m]/10;
                        //cout << elde << "---";
                        result[m] = result[m]%10;
                        //cout << result[i] << "--";
                        result[m-1]  = result[m-1] + elde;
                        //cout << result[i-1] << endl;

                    }

                    else if (result[m]<=9)
                    {
                        break;
                    }

                }


            }
            k--;
        }
        l++;
    }


///MULTIPLAY END

    cout << "Islem tamamlandi" << endl;

}



void divide(int value_1d[], int value_2d[])
{
    int k, step,  elde, times, quo_step;
    int result_val, divisor_value;
    int divisor[value2_bs];

    // result deðiþkenine varsayýlan deðer aktarma
    k=0;
    for(int i=13-value1_bs; i<13; i++)
    {
        result[k] = value_1d[i];
        k++;
    }


//bölen deðiþkenine veriyi aktarma aktarma başlangıç
    k=0;
    for(int i=13-value2_bs; i<13; i++)
    {
        divisor[k] = value_2d[i];
        k++;
    }


/// Bolme Baslangic

    exp_step = "Baslangic";
    result_control = 0;
    colour_control = 13;
    print_soroban(result);
    system("pause");

    //Bolenin değerini hesaplama
    times=1;
    divisor_value=0;
    for(int i=value2_bs-1; i>=0; i--)
    {
        divisor_value = divisor_value + divisor[i]*times;
        times = times*10;
    }

    step = value1_bs-value2_bs+1; // Sağa kaydırılarak kaç defa sıralı çıkarma işleminin yapılacağını bul
    quo_step = 12-quo_bs; // Bölümün sorabanda ve result dizisinde kaçıncı elemandan başlanarak yazılacağını bul
    for (int a=0; a<step; a++)
    {
        //Bölünenin, bölenin basamak sayısı kadar ilk basamakları değeri
        result_val = 0; // O an yapılan sıralı çıkarma işleminin bölenin birler basamağına denk gelen result basamağından solda kalan basamakların sayı değeri sıfırlanır
        times=1;

        // O an yapılan sıralı çıkarma işleminin bölenin birler basamağına denk gelen result basamağından solda kalan basamakların sayı değeri bulunur
        for(int i=a+value2_bs-1; i>=0; i--)
        {
            result_val = result_val + result[i]*times;
            times = times*10;
        }

        // Divisor sayı değeri result_val dan küçükse çıkarma işlemi yapılamaz. Bunun açıklaması
        if (divisor_value>result_val && a+1<step)
        {
            step_result++;
            std::cout << endl << dye::blue("Adim :") << step_result << endl;
            std::cout <<dye::yellow("Cikarilan, cikandan buyuk oldugundan islem yapilamaz. Bolen 1 basamak saga kaydirildi") << endl;


        }

        // Sağa kaydırma işleminde divisor_value, result_val'dan küçükse veya işlemin ilk ana adımı değilse bir sağa kaydırma işlemi yapılır
        if (divisor_value<=result_val || a>0)
        {
            quo_step++;
        }

        // divisor_value, result_val'den küçük oluncaya kadar döngü devam eder ve sıralı çıkarma işlemi yapılır
        while(divisor_value<=result_val)
        {

            ///SUBTRACT START

            for(int i=0; i<value2_bs; i++)
            {
                // çıkarılan basamak çıkan basamaktan büyük ise soldaki sıfırdan büyük ilk basamaktan bir onluk al
                if(result[i+a] < divisor[i] && i+a>=0)
                {

                    // soldaki sıfırdan büyük ilk basamaktan bir onluk al
                    k=0;
                    for (int j=i+a-1; j>=0; j--)
                    {
                        if(result[j]>0)
                        {
                            exp_step = "Soldan ve sifidan buyuk ilk degerden bir onluk al";
                            step_result++;
                            result[j] = result[j] - 1;
                            result_control = result[j];
                            colour_control = j;
                            print_soroban_divide(result,value1_bs,quo_bs);
                            system("pause");
                            k=j+1;
                            break;
                        }

                    }



                    // alinan onlugu "0" olan yan basamağa ekle ve yan basamaga eklemek icin bir onluk al
                    // onluk alirken kac basamak sola gittiysek dongu o kadar devam eder
                    for(int j=k; j<i+a; j++)
                    {
                        exp_step = "Alinan onlugu ekle ve Yana eklemek icin bir onluk al";
                        step_result++;
                        result[j] = result[j] + 10 - 1;
                        result_control = result[j];
                        colour_control = j;
                        print_soroban_divide(result,value1_bs,quo_bs);
                        system("pause");
                    }


                    exp_step = "Alinan onlugu ekle";
                    step_result++;
                    result[i+a] = result[i+a]+10;
                    result_control = result[i+a];
                    colour_control = i+a;
                    print_soroban_divide(result, value1_bs, result_bs);
                    result_control = 0 ;
                    system("pause");



                    exp_step = "Islemi yap(Bolunenden cikarma)";
                    step_result++;
                    result[i+a] = result[i+a]-divisor[i];
                    result_control = result[i+a];
                    colour_control = i+a;
                    print_soroban_divide(result,value1_bs,quo_bs);
                    result_control = 0 ;
                    system("pause");
                }

                // result[i+a] >= divisor[i] ise doğrudan basamak basamak çıkarma işlemini yap
                else if (result[i+a] >= divisor[i])
                {
                    exp_step = "Islemi yap(Bolunenden cikarma)";
                    step_result++;
                    result[i+a] = result[i+a] - divisor[i];
                    result_control = result[i+a];
                    colour_control = i+a;
                    print_soroban_divide(result,value1_bs,quo_bs);
                    result_control = 0 ;
                    system("pause");

                }
            }
            ///SUBTRACT END


            // Yapılan her çıkarma işleminden sonra bölümün ilgili basamağını 1 artır
            exp_step = "Islem yap (Bolume Ekleme)";
            step_result++;
            result[quo_step]++;
            result_control = result[quo_step];
            colour_control = quo_step;
            print_soroban_divide(result,value1_bs,quo_bs);
            result_control = 0 ;
            system("pause");

            //Bölünenin, bölenin basamak sayısı kadar ilk basamakları değerini
            // işlem yapıldıktan sonra yeni adıma geçmeden önce, while döngüsü koşulunda kullanmak üzere yeniden hesapla
            result_val = 0;
            times=1;

            for(int b=a+value2_bs-1; b>=0; b--)
            {
                result_val = result_val + result[b]*times;
                times = times*10;
            }

            //9'dan buyukse eldeyi soldaki basamağa ekle
            //bu islem eldenin eklendiği basamak 9'dan buyuk olmayana kadar devam eder
            if(result[step]>9)
            {
                for (int m=quo_step; m>12-quo_bs; m--)
                {

                    if(quo_step!=m)
                    {
                        exp_step = "Eldeyi soldaki basamaga ekle";
                        step_result++;
                        result_control = result[m];
                        colour_control = m;
                        print_soroban_divide(result, value1_bs, result_bs);
                        result_control = 0 ;
                        system("pause");
                    }

                    if(result[m]>9)
                    {
                        //cout << result[i] << "--";
                        elde = result[m]/10;
                        //cout << elde << "---";
                        result[m] = result[m]%10;
                        //cout << result[i] << "--";
                        result[m-1]  = result[m-1] + elde;
                        //cout << result[i-1] << endl;

                    }

                    else if (result[m]<=9)
                    {
                        break;
                    }

                }


            }

            if (divisor_value>result_val && a+1<step)
            {
                step_result++;
                std::cout << endl << dye::blue("Adim :") << step_result << endl;
                std::cout <<dye::yellow("Cikarilan, cikandan buyuk oldugundan islem yapilamaz. Bolen 1 basamak saga kaydirildi") << endl;


            }

        }



    }


    cout << "Islem tamamlandi" << endl;


}



int main()
{

    int value_1d[13];
    int value_2d[13];
    long long value_1, value_2;
    char op;
    int  remaind;



opAsk:
    cout << "Yapmak istediginiz islem (+ - * /):" << endl;
    cin>>op;


    switch (op)
    {
    case '+' :
        cout << "Toplama islemi"<< endl;
        break;

    case '-' :
        cout << "Cikarma islemi"<< endl;
        break;

    case '*' :
        cout << "Carpma islemi"<< endl;
        break;

    case '/' :
        cout << "Bolme islemi" << endl;
        break;

    default:
        cout << "Gecerli bir islem secmediniz. Yeniden giris yapin.";
        goto opAsk;
    }
/// Birinci sayının girişini iste ve kontrol et
askValue_1:
    cout << "Toplanan, Cikarilan, Capilan veya Bolunen" << endl;
    cout << "1. Deger. Lutfen pozitif bir tamsayi girin..." << endl;
    std::cin>>value_1;

    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto askValue_1;
    }
    if(value_1>9999999999999)
    {
        cout << "Lutfen yeniden deneyin" << endl;
        goto askValue_1;
    }


/// İkinci sayının girişini iste ve kontrol et
askValue_2:
    cout << "Toplanan, Cikan, Carpilan veya Bolunen" << endl;
    cout << "2. Deger. Lutfen pozitif bir tamsayi girin..." << endl;
    std::cin>>value_2;

    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto askValue_2;
    }

    if(value_2>9999999999999)
    {
        cout << "Lutfen yeniden deneyin" << endl;
        goto askValue_2;
    }



    ///Değerleri 13 elemanlı diziye çevir
    long long value_1ch = value_1;
    long long value_2ch = value_2;
    long long value1_bsch = value_1;
    long long value2_bsch = value_2;
    for(int i = 12; i >=0 ; i--)
    {
        remaind = value_1 % 10;
        value_1d[i] = remaind;
        value_1 = value_1/10;
    }

    for(int i = 12; i >=0 ; i--)
    {
        remaind = value_2 % 10;
        value_2d[i] = remaind;
        value_2 = value_2/10;
    }

    //Deger 1 basamak sayisini bul
    value1_bs=0;
    while(value1_bsch>0)
    {
        value1_bsch=value1_bsch/10;
        value1_bs++;
    }

    //Deger 2 basamak sayisini bul
    value2_bs=0;
    while(value2_bsch>0)
    {
        value2_bsch=value2_bsch/10;
        value2_bs++;
    }




    /// işlemleri kontrol et ve çağır

    //toplama
    if(op == '+')
    {
        if(value_1ch+value_2ch>9999999999999)
        {
            cout << "Sonuc 13 basamaktan fazla oldugundan Sorobanda gösterilemez. Lutfen yeniden deneyin..." << endl;
            goto opAsk;
        }
        else
            add(value_1d,value_2d);

    }

    //çıkarma
    if(op == '-')
    {
        if(value_1ch<value_2ch)
        {
            cout << "2. deger, 1. degerden buyuk oldugundan cikarma islemi yapilamaz. Lutfen yeniden deneyin..." << endl;
            goto opAsk;
        }
        else
            subtract(value_1d,value_2d);

    }

    // çarpma
    if(op == '*')
    {
        long long result_ch = value_1ch*value_2ch;
        result_bs=0;
        while(result_ch>0)
        {
            result_ch=result_ch/10;
            result_bs++;
        }

        if(value1_bs+result_bs>12)
        {
            cout << "Sonuc ve carpilanin basamak sayilari toplami 12' den buyuk oldugundan, islem sorobanda yapilamaz. Lutfen yeniden deneyin..." << endl;
            goto opAsk;
        }
        else
            multiply(value_1d,value_2d);

    }

    //bölme
    if(op == '/')
    {
        if (value_1ch<value_2ch)
        {
            cout << "Bolen, bolunenden buyuk oldugundan bolme islemi yapilamaz" << endl;
            goto opAsk;
        }

        int quo = value_1ch/value_2ch;
        int soroban_ch;

        //bölüm basamak sayisini bul
        quo_bs=0;
        while(quo>0)
        {
            quo=quo/10;
            quo_bs++;
        }

        soroban_ch = value1_bs + quo_bs;

        if(soroban_ch>12)
        {
            cout << "Bolum ve bolunen(islem bittikten sonra kalan) basamak sayilari toplami 12'den fazla oldugundan bu islemin sonucu sorobanda gosterilemez" << endl;
            goto opAsk;
        }
        else
            divide(value_1d,value_2d);
    }

    system("pause");
}
