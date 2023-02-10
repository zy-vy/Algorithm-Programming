#include <stdio.h>

 struct data {
    char nama[101],nim[101],umur[101],kodepos[101],tempatlahir[101],tanggallahir[101],sma[101],saudara[101],tinggi[1001],norek[101];
    int dt;
};
 struct data mhs;

int main (){
    int n;
    scanf ("%d",&n);
    getchar();
    for (int i=1;i<=n;i++){
        scanf ("%[^\n]*c",&mhs.nama);
    getchar();
        scanf ("%[^\n]*c",&mhs.nim);
    getchar();
        scanf ("%[^\n]*c",&mhs.umur);getchar();
        scanf ("%[^\n]*c",&mhs.kodepos);getchar();
        scanf ("%[^\n]*c",&mhs.tempatlahir);getchar();
        scanf ("%[^\n]*c",&mhs.tanggallahir);getchar();
        scanf ("%[^\n]*c",&mhs.sma);getchar();

        scanf ("%[^\n]*c",&mhs.saudara);getchar();
        scanf ("%[^\n]*c",&mhs.tinggi);
        getchar();
        scanf ("%[^\n]*c",&mhs.norek);
        getchar();
        printf ("Mahasiswa ke-%d:\n",i);
        printf ("Nama: %s\nNIM: %s\nUmur: %s\nKode Pos: %s\nTempat Lahir: %s\nTanggal Lahir: %s\nAlmamater SMA: %s\nJumlah Saudara Kandung: %s\nTinggi Badan: %s\nNOMOR REKENING: %s\n",mhs.nama,mhs.nim,mhs.umur,mhs.kodepos,mhs.tempatlahir,mhs.tanggallahir,mhs.sma,mhs.saudara,mhs.tinggi,mhs.norek);

    }
return 0;
}
//• Nama • NIM • Umur • Kode Pos • Tempat Lahir • Tanggal Lahir • Almamater SMA • Jumlah Saudara kandung • Tinggi Badan • Nomor Rekening
//Mahasiswa ke-1: Nama: Lili NIM: 123456789 Umur: 13 Kode Pos: 786431 Tempat Lahir: Jakarta Tanggal Lahir: 14SEPT2010 Almamater SMA: Bina Nusantara School Jumlah Saudara Kandung: 7 Tinggi Badan: 123 NOMOR REKENING: 968543769 Mahasiswa ke-2: Nama: Jojo NIM: 125676789 Umur: 22 Kode Pos: 711111 Tempat Lahir: Bekasi Tanggal Lahir: 1JANUARY2018 Almamater SMA: Bina Nusantara School Jumlah Saudara Kandung: 99 Tinggi Badan: 12 NOMOR REKENING: 890234789
