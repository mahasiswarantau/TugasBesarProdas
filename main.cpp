#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <conio2.h>
#include <conio.h>
#define maks 2

using namespace std;

typedef struct{
	char tujuan[16];
	char jam[8];
	int harga;
}struct_jadwal;

typedef struct{
   char paket[16];
   int hari;
   int diskon;
}struct_paket;

typedef struct{
   int tgl;
   int bln;
   int thn;        
}struct_tanggal;

typedef struct{
   char nama[31];
   struct_tanggal st;
   char tujuan[16];
   char paket[16];
   int jumlah;
   float diskon;
   int subharga;
   float total;
   float potongan;
   float bayar;
   float kembali;
}struct_pembelian;

struct_jadwal input_jadwal(int i)
{
	struct_jadwal sj[maks];
	
	system("cls");
	cout<<"Data Ke-"<<i+1<<endl;
	cout<<"--------------"<<endl;
	cout<<"Masukkan Tujuan   : ";
	fflush(stdin);
	cin.get(sj[i].tujuan, 15);
	cout<<"Jam Keberangkatan : ";
	fflush(stdin);
	cin.get(sj[i].jam, 7);
	cout<<"Harga Tiket       : Rp.";
	cin>>sj[i].harga;
	return sj[i];
}

void output_jadwal(int i, struct_jadwal sj[maks])
{
	
	system("cls");
	cout<<"Jadwal Keberangkatan"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"|  No  |   Tujuan   | Keberangkatan  |     Harga      |"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	for(i=0;i<2;i++){
		gotoxy(1,5+i);cout<<"|  "<<i+1;
        gotoxy(8,5+i);cout<<"|  "<<sj[i].tujuan;
        gotoxy(21,5+i);cout<<"|     "<<sj[i].jam;
        gotoxy(38,5+i);cout<<"|  "<<"Rp."<<sj[i].harga;
        gotoxy(55,5+i);cout<<"|  "<<endl;
	}
	gotoxy(1,5+i);cout<<"-------------------------------------------------------"<<endl;
}

struct_paket input_paket(int i)
{
   struct_paket sp[maks];
   
   system("cls");
   cout<<"Data Paket Ke-"<<i+1<<endl;
   cout<<"-------------------"<<endl;
   cout<<"Paket              : ";
   fflush(stdin);
   cin.get(sp[i].paket, 15);
   cout<<"Lama Paket (Hari)  : ";cin>>sp[i].hari;
   cout<<"Diskon             : Rp.";cin>>sp[i].diskon;
   return sp[i];
}

void output_paket(int i, struct_paket sp[maks]){
  system("cls");
  cout<<"Daftar Promo Paket"<<endl;
  cout<<"-----------------------------------------------"<<endl;
  cout<<"|   Paket   |    Lama Paket    |    Diskon    |"<<endl;
  cout<<"-----------------------------------------------"<<endl;
  for(i=0;i<2;i++){
     gotoxy(1,5+i);cout<<"|  "<<sp[i].paket;
     gotoxy(13,5+i);cout<<"|      "<<sp[i].hari<<" Hari";
     gotoxy(32,5+i);cout<<"|  Rp."<<sp[i].diskon;
     gotoxy(47,5+i);cout<<"|"<<endl;
  }
  gotoxy(1,5+i );cout<<"-----------------------------------------------"<<endl;     
}

void output_paket2(int i,struct_jadwal sj[maks], struct_paket sp[maks]){
  system("cls");
  cout<<"Jadwal Keberangkatan"<<endl;
  cout<<"-------------------------------------------------------"<<endl;
  cout<<"|  No  |   Tujuan   | Keberangkatan  |     Harga      |"<<endl;
  cout<<"-------------------------------------------------------"<<endl;
	for(i=0;i<2;i++){
		gotoxy(1,5+i);cout<<"|  "<<i+1;
        gotoxy(8,5+i);cout<<"|  "<<sj[i].tujuan;
        gotoxy(21,5+i);cout<<"|     "<<sj[i].jam;
        gotoxy(38,5+i);cout<<"|  "<<"Rp."<<sj[i].harga;
        gotoxy(55,5+i);cout<<"|  "<<endl;
	}
  gotoxy(1,5+i);cout<<"-------------------------------------------------------"<<endl;
  
  gotoxy(1,8);cout<<"Daftar Promo Paket"<<endl;
  gotoxy(1,9);cout<<"-----------------------------------------------"<<endl;
  gotoxy(1,10);cout<<"|   Paket   |    Lama Paket    |    Diskon    |"<<endl;
  gotoxy(1,11);cout<<"-----------------------------------------------"<<endl;
  for(i=0;i<2;i++){
     gotoxy(1,12+i);cout<<"|  "<<sp[i].paket;
     gotoxy(13,12+i);cout<<"|      "<<sp[i].hari<<" Hari";
     gotoxy(32,12+i);cout<<"|  Rp."<<sp[i].diskon;
     gotoxy(47,12+i);cout<<"|"<<endl;
  }
  gotoxy(1,12+i );cout<<"-----------------------------------------------"<<endl;    
}

struct_pembelian input_pembelian(){
  struct_pembelian pem;
  
  cout<<"Pembelian"<<endl;
  cout<<"---------------"<<endl;
  cout<<"Nama             : ";
  fflush(stdin);
  cin.get(pem.nama, 30);
  cout<<"Tanggal          : ";
  gotoxy(20,19);cin>>pem.st.tgl;
  gotoxy(1,20);cout<<"Bulan            : ";
  gotoxy(20,20);cin>>pem.st.bln;
  gotoxy(1,21;cout<<"Tahun           : ";
  gotoxy(20,21);cin>>pem.st.thn;
  gotoxy(1,22);cout<<"Tujuan           : ";
  gotoxy(20,22);fflush(stdin);cin.get(pem.tujuan, 15);
  gotoxy(1,23);cout<<"Jumlah Tiket     : ";
  gotoxy(20,23);cin>>pem.jumlah;
  gotoxy(1,24);cout<<"Paket            : ";
  gotoxy(20,24);fflush(stdin);cin.get(pem.paket, 15);
  return pem;
}

void output_pembelian(struct_jadwal sj[maks], struct_paket sp[maks], struct_pembelian pem){

  int banding1;
  int banding2;
                 
  banding1 = strcmp(pem.tujuan, sj[0].tujuan);
  banding2 = strcmp(pem.tujuan, sj[1].tujuan);
                 
  if(banding1 == 0){
      pem.subharga = pem.jumlah * sj[0].harga;
  }else if(banding2 == 0){
      pem.subharga = pem.jumlah * sj[1].harga;
  }else{
      pem.subharga = 0;
  }
                 
  //diskon
  int paket1;
  int paket2;
                 
  paket1 = strcmp(pem.paket, sp[0].paket);
  paket2 = strcmp(pem.paket, sp[1].paket);
                 
  if(paket1 == 0){
      pem.diskon = sp[0].diskon;
  }else if(banding2 == 0){
      pem.diskon = sp[1].diskon;
  }else{
      pem.diskon = 0;
  }
                 
  //potongan
                 
  if(pem.jumlah == 3){
      pem.potongan = (float)((0.1 * pem.subharga) - pem.diskon);
  }else if((pem.jumlah <=10)||(pem.jumlah >= 5)){
      pem.potongan = (float)((0.2 * pem.subharga) - pem.diskon);
  }else if(pem.jumlah > 10){
      pem.potongan = (float)((0.3 * pem.subharga) - pem.diskon);
  }else{
      pem.potongan = 0;
  }
  system("cls");
  pem.total = pem.subharga - pem.potongan;
  cout<<"Nama             : "<<pem.nama<<endl;
  cout<<"Tanggal          : ";
  gotoxy(20,2);cout<<pem.st.tgl<<"/";
  gotoxy(23,2);cout<<pem.st.tgl<<"/";
  gotoxy(26,2);cout<<pem.st.tgl;
  gotoxy(1,3);cout<<"Tujuan           : "<<pem.tujuan;
  gotoxy(1,4);cout<<"Paket            : "<<pem.paket;                 
  gotoxy(1,5);cout<<"Jumlah           : "<<pem.jumlah<<" Buah";                 
  gotoxy(1,6);cout<<"Subharga         : Rp."<<pem.subharga;                 
  gotoxy(1,7);cout<<"Potongan         : Rp."<<pem.potongan;                 
  gotoxy(1,8);cout<<"Total Harga      : Rp."<<pem.total;                 
  gotoxy(1,9);cout<<"Bayar            : Rp.";gotoxy(23,9);cin>>pem.bayar;
                 
  //Kembalian
  pem.kembali =  pem.bayar - pem.total;
                 
  system("cls");
  textcolor(YELLOW);             
  gotoxy(28,5);cout<<"Kembali      : ";
  gotoxy(43,5);cout<<"Rp."<<pem.kembali;
}

int main(int argc, char *argv[])
{
    int menu;
    int sub;
    struct_jadwal sj[maks];
    struct_paket sp[maks];
    struct_pembelian pem;
    int i;
    
    do{
        textcolor(WHITE);
        system("cls");
        cout<<"Menu Pilihan"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"1. Jadwal Keberangkatan"<<endl;
        cout<<"2. Daftar Promo Paket"<<endl;
        cout<<"3. Pembelian Tiket"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"Pilih Menu Pilihan : ";
        cin>>menu;
        
        switch(menu){
            case 1:
                 
                 do{
                     textcolor(WHITE);
                     system("cls");
                     cout<<"Jadwal Keberangkatan"<<endl;
                     cout<<"------------------------"<<endl;
                     cout<<"1. Input Data"<<endl;
                     cout<<"2. Output Data"<<endl;
                     cout<<"3. Kembali ke menu utama"<<endl;
                     cout<<"------------------------"<<endl;                     
                     cout<<"Masukkan Pilihan : ";
                     cin>>sub;
                     
                     switch(sub){
                         case 1:
                              for(i=0;i<2;i++){
	                              sj[i] = input_jadwal(i);
                              }
                              break;
                         case 2:
                              output_jadwal(i, sj);
                              getch();
                              break;
                         case 3:
                              textcolor(RED);cout<<"Tekan sembarang tombol untuk kembali ke manu utama!!"<<endl;                              
                              getch();
                              break;
                         default:
                              textcolor(RED);cout<<"Pilihan tidak terdaftar\nTekan sembarang tombol untuk kembali ke sub menu!!"<<endl;
                              getch();
                              break;
                     }                     
                 }while(sub != 3);
                 break;
                 
            case 2:
                 do{
                     textcolor(WHITE);
                     system("cls");
                     cout<<"Daftar Promo Paket"<<endl;
                     cout<<"------------------------"<<endl;
                     cout<<"1. Input Data"<<endl;
                     cout<<"2. Output Data"<<endl;
                     cout<<"3. Kembali ke menu utama"<<endl;
                     cout<<"------------------------"<<endl;                     
                     cout<<"Masukkan Pilihan : ";
                     cin>>sub;
                     
                     switch(sub){
                         case 1:
                              for(i=0;i<2;i++){
                                  sp[i] = input_paket(i);
                              }
                              break;
                              
                         case 2:
                              output_paket(i, sp);
                              getch();
                              break;
                              
                         case 3:
                              textcolor(RED);cout<<"Tekan sembarang tombol untuk kembali ke manu utama"<<endl;                              
                              getch();
                              break;
                              
                         default:
                              textcolor(RED);cout<<"Pilihan tidak terdaftar\nTekan sembarang tombol untuk kembali ke sub menu!!"<<endl;
                              getch();
                              break;
                     }                     
                 }while(sub != 3);
                 break;
                 
            case 3:
                 do{
                     textcolor(WHITE );
                     system("cls");
                     cout<<"Pembelian"<<endl;
                     cout<<"------------------------"<<endl;
                     cout<<"1. Input Data"<<endl;
                     cout<<"2. Output Data"<<endl;
                     cout<<"3. Kembali ke menu utama"<<endl;
                     cout<<"------------------------"<<endl;                     
                     cout<<"Masukkan Pilihan : ";
                     cin>>sub;
                     
                     switch(sub){
                         case 1:
                              system("cls");
                              output_paket2(i, sj, sp);
                              cout<<endl;
                              pem = input_pembelian();
                              break;
                         case 2:
                              output_pembelian(sj, sp, pem);
                              getch();
                              break;
                         case 3:
                              textcolor(RED);cout<<"Tekan sembarang tombol untuk kembali ke sub menu!!r"<<endl;                              
                              getch();
                              break;
                         default:
                              textcolor(RED);cout<<"Pilihan tidak terdaftar\nTekan sembarang tombol untuk kembali ke sub menu!!"<<endl;
                              getch();
                              break;
                     }                     
                 }while(sub != 3);         
                 break;
                 
            case 4:
                 textcolor(RED);cout<<"Tekan sembarang tombol untuk keluar!!"<<endl;
                 getch();
                 break;
                 
            default:
                 textcolor(RED);cout<<"Pilihan tidak terdaftar\nTekan sembarang tombol untuk kembali ke menu!!"<<endl;
                 getch();
                 break;
        }
    }while(menu != 4);

    return EXIT_SUCCESS;
}
