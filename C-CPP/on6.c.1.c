#include <stdio.h>


 struct keluarga {
    char ayah[101],ibu[101],saudara[101];
};
struct mahasiswa {
    char kodemhs[101],namamhs[101],gendermhs[101];
    struct keluarga kel;
};
 struct dosen {
    char kodedos[101],namados[101],genderdos[101];
    int jumMhs;
    struct mahasiswa mhs[101];
};

struct dosen dos[101];


int main (){
    int n;
    scanf ("%d",&n);
    getchar();
    for (int i=0;i<n;i++){
        scanf ("%[^\n]*c",&dos[i].kodedos);getchar();
        scanf ("%[^\n]*c",&dos[i].namados);getchar();
        scanf ("%[^\n]*c",&dos[i].genderdos);getchar();
        scanf ("%d",&dos[i].jumMhs);getchar();
       // printf ("%s %s %s %d",dos[i].kodedos,dos[i].namados,dos[i].genderdos,dos[i].jumMhs);
       for (int j=0;j<dos[i].jumMhs;j++){
            scanf("%[^\n]*c",&dos[i].mhs[j].kodemhs);getchar();
            scanf ("%[^\n]*c",&dos[i].mhs[j].namamhs);getchar();
            scanf ("%[^\n]*c",&dos[i].mhs[j].gendermhs);getchar();
            scanf ("%[^\n]*c",&dos[i].mhs[j].kel.ayah);getchar();
            scanf ("%[^\n]*c",&dos[i].mhs[j].kel.ibu);getchar();
            scanf ("%[^\n]*c",&dos[i].mhs[j].kel.saudara);getchar();

       }

    }
    int a;
   scanf ("%d",&a);
   a--;
        printf ("Kode Dosen: %s\n",dos[a].kodedos);
        printf ("Nama Dosen: %s\n",dos[a].namados);
        printf ("Gender Dosen: %s\n",dos[a].genderdos);
        printf ("Jumlah Mahasiswa: %d\n",dos[a].jumMhs);
       for (int j=0;j<dos[a].jumMhs;j++){
            printf ("Kode Mahasiswa: %s\n",&dos[a].mhs[j].kodemhs);
            printf ("Nama Mahasiswa: %s\n",&dos[a].mhs[j].namamhs);
            printf ("Gender Mahasiswa: %s\n",&dos[a].mhs[j].gendermhs);
            printf ("Nama Ayah: %s\n",&dos[a].mhs[j].kel.ayah);
            printf ("Nama Ibu: %s\n",&dos[a].mhs[j].kel.ibu);
            printf ("Jumlah Saudara Kandung: %s\n",&dos[a].mhs[j].kel.saudara);

       }


return 0;
}
