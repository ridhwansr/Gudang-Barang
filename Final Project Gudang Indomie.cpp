#include <iostream>
#include <conio.h>
#include <stdlib.h> //menggunakan sistem cls
#define MAX 10

using namespace std;


// Deklarasi Queue
struct queue {
	int nomer[MAX];
	int head=-1;
	int tail=-1;
	int t[MAX];
	int b[MAX];
	int th[MAX];
	int tgl[MAX];
	string kode[MAX];
	string nama[MAX];
}q;

// Deklarasi Stack
struct stak{
	int atas = -1;
	int t[MAX];
	int b[MAX];
	int th[MAX];
	string kode[MAX];
	string nama[MAX];
}s;


// Fungsi Stack


bool isPenuh(){
	if(s.atas == MAX-1){
		return true;
	}else return false;
}

bool isKosong(){
	if(s.atas == -1){
		return true;
	}else return false;
}
// Memasukkan barang
void Push(string kode, int t, int b, int th, string nama){
		s.atas++;
		s.kode[s.atas] = kode;
		s.t[s.atas] = t;
		s.b[s.atas] = b;
		s.th[s.atas] = th;
		s.nama[s.atas] = nama;
}
// Mengeluarkan Barang
void Pop(){
	if(isKosong()){
		cout<<"Stok Barang kosong ! ";
		getch();
	}else{
		cout<< "=============================================="
			<< "\nKode      : "<< s.kode[s.atas]
			<< "\nTanggal   : "<< s.t[s.atas] <<"/" << s.b[s.atas] <<"/" << s.th[s.atas]
			<< "\nNama      : "<< s.nama[s.atas]
			<< "\n==============================================" <<endl
			<< "\n     Barang Berhasil Diambil";
		s.atas--;
	}
}
// Menampilkan
void Tampil(){
	if(isKosong()){
		cout<<" Stok Barang Kosong !";
	}else{
		system("cls");
		for(int i=0; i<=s.atas; i++){
			cout<<"============================"
			    <<"\n >> Tumpukan ke : [" <<i+1<< "]"
			    <<"\n >> Kode        : "<< s.kode[i]
			    <<"\n >> Tanggal     : "<< s.t[i]<<"/"<<s.b[i]<<"/"<<s.th[i]
			    <<"\n >> Nama Barang : "<< s.nama[i]
			    <<"\n============================"<<endl;
		}
	}
}
//5. Menghapus isi
void Clear(){
	s.atas=-1;
}


//    Fungsi Queue


//1. Cek Kosong?
bool IsEmpty(){
	if(q.tail == -1){
		return true;
	}else{
		return false;
	}
}
//2. Cek Penuh?
bool IsFull(){ //fungsi untuk menunjukkan jika tail= max-1
	if(q.tail == MAX-1){
		return true;
	}else{
		return false;
	}
}
//3. Memasukkan Antrian
void AntrianMasuk(int no){
	if(IsEmpty()){
		q.head=q.tail=0;
	}else{
		q.tail++;
	}
	q.nomer[q.tail]=no;
	cout <<"\n==========================\n";
	cout <<"Kode Barang : ";cin >> q.kode[q.tail];
	cout <<"Nama Barang : ";cin >> q.nama[q.tail];
	cout <<"Tanggal EXP : ";cin >> q.t[q.tail];
	cout <<"Bulan EXP   : ";cin >> q.b[q.tail];
	cout <<"Tahun EXP   : ";cin >> q.th[q.tail];
	
	q.tgl[q.tail] = q.b[q.tail] * 31 + q.t[q.tail] + q.th[q.tail] * q.th[q.tail];
}
//4. Memanggil Antrian
void AntrianKeluar(){
	for(int a=q.head; a<q.tail; a++){		
		q.nomer[a]=q.nomer[a+1];
		q.kode[a]=q.kode[a+1];
		q.t[a]=q.t[a+1];
		q.b[a]=q.b[a+1];
		q.th[a]=q.th[a+1];
		q.tgl[a]=q.tgl[a+1];
		q.nama[a]=q.nama[a+1];
	}
	q.tail--;
	if(q.tail == -1){
		q.head = -1;
	}
}
//6. Memanggil Antrian
void View(){
	if(IsEmpty()){
		cout<<"Antrian Barang Kosong ! ";
		
	}else{
		system("cls");
		for(int a=q.head;a<=q.tail;a++){
			cout<<"============================"
			    <<"\n >> No. Antri : [" <<q.nomer[a]<< "]"
			    <<"\n >> Kode      : "<< q.kode[a]
			    <<"\n >> Tanggal   : "<< q.t[a]<<"/"<<q.b[a]<<"/"<<q.th[a]
			    <<"\n >> Nama      : "<< q.nama[a]
			    <<"\n============================"<<endl;
		}
	}
}


//    Sorting

void Sorting()
{
	int temp;
	string temp2;
	
	for(int i=q.head; i<=q.tail; i++)
	{
		for(int j=q.head; j<q.tail; j++)
		{
			if(q.tgl[j+1] > q.tgl[j])
			{
				temp = q.tgl[j+1] ;
				q.tgl[j+1] = q.tgl[j];
				q.tgl[j]=temp;
				
				temp2 = q.kode[j+1] ;
				q.kode[j+1] = q.kode[j];
				q.kode[j]=temp2;
				
				temp = q.t[j+1] ;
				q.t[j+1] = q.t[j];
				q.t[j]=temp;
				
				temp = q.b[j+1] ;
				q.b[j+1] = q.b[j];
				q.b[j]=temp;
				
				temp = q.th[j+1] ;
				q.th[j+1] = q.th[j];
				q.th[j]=temp;
				
				temp2 = q.nama[j+1] ;
				q.nama[j+1] = q.nama[j];
				q.nama[j]=temp2;
			}
		}
	}
	View();
}


//   Searching


void Searching()
{
	int i;
	string kd;
	cout<<"\n==============================================\n";
	cout << "Masukkan Kode Barang yang dicari : ";
	cin >> kd;
	
	for(i=0; i<=s.atas; i++)
	{
		if (s.kode[i]==kd)
		{
			cout<<"\n==============================================\n";
			cout << "Kode Barang Ditemukan dan berada di tumpukkan ke : "<< i+1;
		}
	}
}


//    Fungsi Utama


int main(){
	int choose, p=1, urut; //deklarasi untuk pilihan user dan nomer urut antrian
	do{
		system("cls");
		cout<< "\n=============================================="
		    << "\n                   PROGRAM                    "
		    << "\n            GUDANG INDOMIE KLATEN             "
		    << "\n=============================================="
		    << "\n1. Tambah Barang                "
		    << "\n2. Lihat Antrian Barang         "
			<< "\n3. Sorting Antrian              "
			<< "\n4. Masukkan Barang Ke Gudang    "
			<< "\n5. Lihat Barang di Gudang       "
			<< "\n6. Cari Kode Barang             "
			<< "\n7. Ambil Barang                 "
		    << "\n8. Keluarkan Semua Barang Dari Gudang"
			<< "\n9. Exit                         "
		    << "\n==============================================";
		cout<< "\nPilih! "; cin>>choose;
		cout<< "\n\n";
		if(choose == 1){
			if(IsFull()) {
				cout<<"Antrian Barang sudah penuh";
			}
			else{
				urut=p;
				AntrianMasuk(urut);
				cout <<"\n==========================\n"<<endl;
				cout<< "BARANG BERHASIL DIMASUKKAN\n" <<endl;
				cout <<"==========================\n";
				p++;
			}
		}
		else if(choose == 2){
			View();
		}
		else if(choose == 3){	
			Sorting();
		}
		else if(choose == 4){
			if(IsEmpty()){
				cout<<" Antrian Masih Kosong";
			}
			else if(isPenuh()){
				cout<<" Stok Penuh";
			}
			else{
				cout<< "==============================================" <<endl;
				cout<< "No. Antri : [" <<q.nomer[q.head] << "]"
					<< "\nKode      : "<< q.kode[q.head]
					<< "\nTanggal   : "<< q.t[q.head] <<"/" << q.b[q.head] <<"/" << q.th[q.head]
					<< "\nNama      : "<< q.nama[q.head];
				cout<< "\n==============================================" <<endl;
				cout<< "\n     Barang Berhasil Dimasukkan";
				Push(q.kode[q.head], q.t[q.head], q.b[q.head], q.th[q.head], q.nama[q.head]);
				AntrianKeluar();
			}
		}
		else if(choose == 5){
			Tampil();
		}
		else if(choose==6){
			if(isKosong()){
				cout<<" Belum Ada Barang";
			}else{
				Searching();
			}
		}
		else if(choose==7){
			Pop();
		}
		else if(choose==8){
			Clear();
			cout<<" Semua Barang DiKeluarkan";
		}
		else if(choose==9){
			cout<<"EXIT ->";
		}
		else{
			cout<<" Angka yang anda masukkan tidak tersedia ! \n"<<endl;
		}
		getch();
	}while(choose!=9);
	cout<<"\nProgram Selesai";
}
