# Laporan Praktikum Stuktur Data MODUL 12 x Multi Linked List


Nama : Rifa Cahya Ariby 

NIM : 103112400268

Kelas : S1 IF12 07

---

## Dasar Teori

##  Multi Linked List 

Multi linked list didefinisikan sebagai struktur data yang menggabungkan beberapa linked list saling terkait, setiap node punya >1 pointer untuk relasi 1-N (satu parent banyak child) atau hirarkis seperti pohon. 

## Karakteristik Utama:

- Dinamis: ukuran bertambah/menyusut runtime tanpa ukuran awal
- Insert/delete efisien (ubah pointer saja, tidak geser elemen)
- Akses lambat (harus traverse dari head)
- Memory ekstra untuk multiple pointer


## Multi Linked List

## Guided
 ``` cpp
 #include <iostream>

#include <string>

  

using namespace std;

  

struct ChildNode{

    string info;

    ChildNode *next;  

};

  

struct ParentNode {

    string info;

    ChildNode *child;

    ParentNode *next;

};

  

ParentNode *createParent (string info){

    ParentNode *newNode = new ParentNode;

    newNode->info = info;

    newNode->child = NULL;

    newNode->next = NULL;

    return newNode;

}

  

ChildNode *createChild(string info) {

    ChildNode *newNode = new ChildNode;

    newNode -> info = info;

    newNode -> next = NULL;

    return newNode;

}

  

void insertParent(ParentNode *&head, string info) {

    ParentNode *newNode = createParent(info);

    if (head == NULL) {

        head = newNode;

    } else {

        ParentNode *temp = head;

        while (temp->next != NULL) {

            temp = temp->next;

        }

        temp->next = newNode;

    }

}

  

void insertChild (ParentNode *head, string parentinfo, string childinfo) {

    ParentNode *p = head;

    while (p != NULL && p -> info != parentinfo) {

        p = p->next;

    }

  

    if (p != NULL) {

        ChildNode *newChild = createChild(childinfo);

        if (p->child == NULL) {

            p->child = newChild;

        } else {

            ChildNode *c = p->child;  

            while (c->next != NULL) {

                c = c->next;

            }

            c->next = newChild;

        }

    }

}

  

void printA11(ParentNode *head) {

    ParentNode *p = head;

    while (p != NULL) {

        cout << p->info;

        ChildNode *c = p->child;      

        if (c != NULL) {

            while (c != NULL) {

                cout << " -> " << c->info;

                c = c->next;

            }

        }

        cout << endl;

        p = p->next;

     }

}

  

int main () {

    ParentNode *list = NULL;

  

    insertParent(list, "Parent Node 1");

    insertParent(list, "Parent Node 2");

  

    printA11(list);

    cout << "\n";

  

    insertChild(list, "Parent Node 1", "Child Node A");

    insertChild(list, "Parent Node 1", "Child Node B");

    insertChild(list, "Parent Node 2", "Child Node C");

  

    printA11(list);

  

    return 0;

}
 ```
## Output

![Output](LAPRAK/LAPRAK%20SEM%203/MODUL%2011%20x%20Multi%20Linked%20List/output/o1m11.png)

Program ini mengimplementasikan linked list bertingkat (hierarchical) di C++ menggunakan dua struct: `ParentNode` (dengan field `info`, pointer ke `ChildNode`, dan `next`) serta `ChildNode` (dengan `info` dan `next`). Setiap parent bisa punya banyak child dalam bentuk singly linked list.
Fungsi utama mencakup `createParent`/`createChild` untuk alokasi node baru, `insertParent` untuk tambah parent di akhir list, serta `insertChild` yang mencari parent berdasarkan `info` lalu tambah child di akhir child-listnya. Fungsi `printA11` mencetak setiap parent diikuti child-nya (misal: "Parent Node 1 -> Child Node A -> Child Node B").
Di `main`, program buat dua parent, cetak awal, tambah child (A/B ke Parent 1, C ke Parent 2), lalu cetak hasil akhir yang menunjukkan struktur hirarkis.

## Unguided

### Soal 1-3

### multilist.h
``` h
#ifndef MULTILIST_H_INCLUDED

#define MULTILIST_H_INCLUDED

  

#include <iostream>

using namespace std;

  

// Nil untuk penunjuk kosong

#define Nil NULL

typedef bool boolean;

  

// Tipe data untuk anak dan induk

typedef int infotypeanak;

typedef int infotypeinduk;

  

// Pointer (alamat) untuk node induk dan anak

typedef struct elemen_list_induk *address;

typedef struct elemen_list_anak *address_anak;

  

// Struktur node untuk list anak (double linked list)

struct elemen_list_anak{

    infotypeanak info;   // data anak

    address_anak next;   // pointer ke node anak berikutnya

    address_anak prev;   // pointer ke node anak sebelumnya

};

  

// Struktur list anak

struct listanak{

    address_anak first;  // elemen pertama anak

    address_anak last;   // elemen terakhir anak

};

  

// Struktur node untuk list induk (double linked list)

struct elemen_list_induk{

    infotypeinduk info;  // data induk

    listanak lanak;       // list anak milik induk ini

    address next;         // pointer ke induk berikutnya

    address prev;         // pointer ke induk sebelumnya

};

  

// Struktur list induk

struct listinduk{

    address first;        // elemen pertama induk

    address last;         // elemen terakhir induk

};

  

// Mengecek apakah list induk kosong

boolean ListEmpty(listinduk L);

  

// Mengecek apakah list anak kosong

boolean ListEmptyAnak(listanak L);

  

// Membuat list induk baru

void CreateList(listinduk &L);

  

// Membuat list anak baru

void CreateListAnak(listanak &L);

  

// Mengalokasikan node induk baru

address alokasi(infotypeinduk P);

  

// Mengalokasikan node anak baru

address_anak alokasiAnak(infotypeanak P);

  

// Dealokasi node induk

void dealokasi(address P);

  

// Dealokasi node anak

void dealokasiAnak(address_anak P);

  

// Mencari elemen induk berdasarkan info

address findElm(listinduk L, infotypeinduk X);

  

// Mencari elemen anak berdasarkan info

address_anak findElm(listanak Lanak, infotypeanak X);

  

// Mengecek apakah alamat induk ada di dalam list

boolean fFindElm(listinduk L, address P);

  

// Mengecek apakah alamat anak ada di dalam list anak

boolean fFindElmanak(listanak Lanak, address_anak P);

  

// Mencari elemen sebelum P di list induk

address findBefore(listinduk L, address P);

  

// Mencari elemen sebelum P di list anak

address_anak findBeforeAnak(listanak Lanak, infotypeinduk X, address_anak P);

  

// Insert node induk di awal list

void insertFirst(listinduk &L, address P);

  

// Insert node induk setelah node tertentu

void insertAfter(listinduk &L, address P, address Prec);

  

// Insert node induk di akhir list

void insertLast(listinduk &L, address P);

  

// Insert node anak di awal list anak

void insertFirstAnak(listanak &L, address_anak P);

  

// Insert node anak setelah node tertentu

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);

  

// Insert node anak di akhir list anak

void insertLastAnak(listanak &L, address_anak P);

  

// Hapus node pertama dari list induk

void delFirst(listinduk &L, address &P);

  

// Hapus node terakhir dari list induk

void delLast(listinduk &L, address &P);

  

// Hapus node setelah node tertentu

void delAfter(listinduk &L, address &P, address Prec);

  

// Hapus node induk berdasarkan info

void delP (listinduk &L, infotypeinduk X);

  

// Hapus node pertama dari list anak

void delFirstAnak(listanak &L, address_anak &P);

  

// Hapus node terakhir dari list anak

void delLastAnak(listanak &L, address_anak &P);

  

// Hapus node anak setelah node tertentu

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);

  

// Hapus node anak berdasarkan info

void delPAnak (listanak &L, infotypeanak X);

  

// Menampilkan semua data induk dan anak

void printInfo(listinduk L);

  

// Menghitung jumlah node induk

int nbList(listinduk L);

  

// Menampilkan data anak

void printInfoAnak(listanak Lanak);

  

// Menghitung jumlah anak

int nbListAnak(listanak Lanak);

  

// Menghapus semua isi list

void delAll(listinduk &L);

  

#endif
```

### multilist.cpp
``` cpp
#include "multilist.h"

  

// Mengecek list induk kosong atau tidak

boolean ListEmpty(listinduk L){

    return (L.first == Nil && L.last == Nil);

}

  

// Mengecek list anak kosong atau tidak

boolean ListEmptyAnak(listanak L){

    return (L.first == Nil && L.last == Nil);

}

  

// Membuat list induk kosong

void CreateList(listinduk &L){

    L.first = Nil;

    L.last = Nil;

}

  

// Membuat list anak kosong

void CreateListAnak(listanak &L){

    L.first = Nil;

    L.last = Nil;

}

  

// Alokasi node induk

address alokasi(infotypeinduk P){

    address Q = new elemen_list_induk;

    Q->info = P;

    Q->next = Nil;

    Q->prev = Nil;

    CreateListAnak(Q->lanak);

    return Q;

}

  

// Alokasi node anak

address_anak alokasiAnak(infotypeanak P){

    address_anak Q = new elemen_list_anak;

    Q->info = P;

    Q->next = Nil;

    Q->prev = Nil;

    return Q;

}

  

// Dealokasi node induk

void dealokasi(address P){

    delete P;

}

  

// Dealokasi node anak

void dealokasiAnak(address_anak P){

    delete P;

}

  

// Mencari elemen di list induk

address findElm(listinduk L, infotypeinduk X){

    address P = L.first;

    while (P != Nil){

        if (P->info == X)

            return P;

        P = P->next;

    }

    return Nil;

}

  

// Mencari elemen di list anak

address_anak findElm(listanak Lanak, infotypeanak X){

    address_anak P = Lanak.first;

    while (P != Nil){

        if (P->info == X)

            return P;

        P = P->next;

    }

    return Nil;

}

  

// Mengecek apakah suatu address ada di list induk

boolean fFindElm(listinduk L, address P){

    address Q = L.first;

    while (Q != Nil){

        if (Q == P)

            return true;

        Q = Q->next;

    }

    return false;

}

  

// Mengecek apakah suatu address ada di list anak

boolean fFindElmanak(listanak Lanak, address_anak P){

    address_anak Q = Lanak.first;

    while (Q != Nil){

        if (Q == P)

            return true;

        Q = Q->next;

    }

    return false;

}

  

// Mencari node sebelum P di list induk

address findBefore(listinduk L, address P){

    address Q = L.first;

    while (Q != Nil && Q->next != P){

        Q = Q->next;

    }

    return Q;

}

  

// Mencari node sebelum P di list anak

address_anak findBeforeAnak(listanak Lanak, infotypeinduk X, address_anak P){

    address_anak Q = Lanak.first;

    while (Q != Nil && Q->next != P){

        Q = Q->next;

    }

    return Q;

}

  

// Insert di awal list induk

void insertFirst(listinduk &L, address P){

    if (ListEmpty(L)){

        L.first = P;

        L.last = P;

    } else {

        P->next = L.first;

        L.first->prev = P;

        L.first = P;

    }

}

  

// Insert setelah node tertentu

void insertAfter(listinduk &L, address P, address Prec){

    if (Prec != Nil){

        P->next = Prec->next;

        P->prev = Prec;

  

        if (Prec->next != Nil){

            Prec->next->prev = P;

        } else {

            L.last = P;

        }

  

        Prec->next = P;

    }

}

  

// Insert di akhir list induk

void insertLast(listinduk &L, address P){

    if (ListEmpty(L)){

        L.first = P;

        L.last = P;

    } else {

        P->prev = L.last;

        L.last->next = P;

        L.last = P;

    }

}

  

// Insert di awal list anak

void insertFirstAnak(listanak &L, address_anak P){

    if (ListEmptyAnak(L)){

        L.first = P;

        L.last = P;

    } else {

        P->next = L.first;

        L.first->prev = P;

        L.first = P;

    }

}

  

// Insert setelah node anak

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec){

    if (Prec != Nil){

        P->next = Prec->next;

        P->prev = Prec;

  

        if (Prec->next != Nil){

            Prec->next->prev = P;

        } else {

            L.last = P;

        }

  

        Prec->next = P;

    }

}

  

// Insert di akhir list anak

void insertLastAnak(listanak &L, address_anak P){

    if (ListEmptyAnak(L)){

        L.first = P;

        L.last = P;

    } else {

        P->prev = L.last;

        L.last->next = P;

        L.last = P;

    }

}

  

// Hapus node pertama induk

void delFirst(listinduk &L, address &P){

    if (!ListEmpty(L)){

        P = L.first;

        if (L.first == L.last){

            L.first = Nil;

            L.last = Nil;

        } else {

            L.first = P->next;

            L.first->prev = Nil;

            P->next = Nil;

        }

    }

}

  

// Hapus node terakhir induk

void delLast(listinduk &L, address &P){

    if (!ListEmpty(L)){

        P = L.last;

        if (L.first == L.last){

            L.first = Nil;

            L.last = Nil;

        } else {

            L.last = P->prev;

            L.last->next = Nil;

            P->prev = Nil;

        }

    }

}

  

// Hapus setelah prec

void delAfter(listinduk &L, address &P, address Prec){

    if (Prec != Nil && Prec->next != Nil){

        P = Prec->next;

        Prec->next = P->next;

  

        if (P->next != Nil){

            P->next->prev = Prec;

        } else {

            L.last = Prec;

        }

  

        P->next = Nil;

        P->prev = Nil;

    }

}

  

// Hapus induk berdasarkan info

void delP (listinduk &L, infotypeinduk X){

    address P = findElm(L, X);

  

    if (P != Nil){

        if (P == L.first){

            delFirst(L, P);

        } else if (P == L.last){

            delLast(L, P);

        } else {

            address Prec = P->prev;

            delAfter(L, P, Prec);

        }

        dealokasi(P);

    }

}

  

// Hapus anak pertama

void delFirstAnak(listanak &L, address_anak &P){

    if (!ListEmptyAnak(L)){

        P = L.first;

        if (L.first == L.last){

            L.first = Nil;

            L.last = Nil;

        } else {

            L.first = P->next;

            L.first->prev = Nil;

            P->next = Nil;

        }

    }

}

  

// Hapus anak terakhir

void delLastAnak(listanak &L, address_anak &P){

    if (!ListEmptyAnak(L)){

        P = L.last;

        if (L.first == L.last){

            L.first = Nil;

            L.last = Nil;

        } else {

            L.last = P->prev;

            L.last->next = Nil;

            P->prev = Nil;

        }

    }

}

  

// Hapus anak setelah node tertentu

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec){

    if (Prec != Nil && Prec->next != Nil){

        P = Prec->next;

        Prec->next = P->next;

  

        if (P->next != Nil){

            P->next->prev = Prec;

        } else {

            L.last = Prec;

        }

  

        P->next = Nil;

        P->prev = Nil;

    }

}

  

// Hapus anak berdasarkan info

void delPAnak (listanak &L, infotypeanak X){

    address_anak P = findElm(L, X);

  

    if (P != Nil){

        if (P == L.first){

            delFirstAnak(L, P);

        } else if (P == L.last){

            delLastAnak(L, P);

        } else {

            address_anak Prec = P->prev;

            delAfterAnak(L, P, Prec);

        }

        dealokasiAnak(P);

    }

}

  

// Menampilkan semua induk dan anaknya

void printInfo(listinduk L){

    address P = L.first;

    while (P != Nil){

        cout << "Induk: " << P->info << endl;

        printInfoAnak(P->lanak);

        P = P->next;

    }

}

  

// Menghitung jumlah induk

int nbList(listinduk L){

    int count = 0;

    address P = L.first;

    while (P != Nil){

        count++;

        P = P->next;

    }

    return count;

}

  

// Menampilkan anak-anak dari satu induk

void printInfoAnak(listanak Lanak){

    address_anak P = Lanak.first;

    while (P != Nil){

        cout << "  Anak: " << P->info << endl;

        P = P->next;

    }

}

  

// Menghitung jumlah anak

int nbListAnak(listanak Lanak){

    int count = 0;

    address_anak P = Lanak.first;

    while (P != Nil){

        count++;

        P = P->next;

    }

    return count;

}

  

// Menghapus semua isi list

void delAll(listinduk &L){

    address P;

    while (!ListEmpty(L)){

        delFirst(L, P);

        dealokasi(P);

    }

}
```

### main.cpp
``` cpp
#include "multilist.h"

#include <iostream>

using namespace std;

  

int main(){

    listinduk L;

    CreateList(L);

  

    // Tambah induk

    address I1 = alokasi(10);

    address I2 = alokasi(20);

    address I3 = alokasi(30);

  

    insertLast(L, I1);

    insertLast(L, I2);

    insertLast(L, I3);

  

    // Tambah anak ke induk 10

    insertLastAnak(I1->lanak, alokasiAnak(1));

    insertLastAnak(I1->lanak, alokasiAnak(2));

    insertLastAnak(I1->lanak, alokasiAnak(3));

  

    // Tambah anak ke induk 20

    insertLastAnak(I2->lanak, alokasiAnak(5));

    insertLastAnak(I2->lanak, alokasiAnak(6));

  

    cout << "Data Multilist:\n";

    printInfo(L);

  

    cout << "\nJumlah Induk = " << nbList(L) << endl;

    cout << "Jumlah Anak Induk 10 = " << nbListAnak(I1->lanak) << endl;

  

    // Hapus induk 20

    delP(L, 20);

  

    cout << "\nSetelah menghapus induk 20:\n";

    printInfo(L);

  

    return 0;

}
```

## Output

![Output](LAPRAK/LAPRAK%20SEM%203/MODUL%2011%20x%20Multi%20Linked%20List/output/o2m11.png)

`multilist.h` = struktur + deklarasi  
`multilist.cpp` = logika/implementasi  
`main.cpp` = tempat uji coba (pemanggilan fungsi)
Program ini menunjukkan cara mengelola **data bertingkat (induk–anak)** menggunakan **Multi Linked List di C++**.

### Soal 4

### circularlist.cpp
``` cpp
#include "circularlist.h"

  

// Membuat list kosong

void createList(List &L){

    L.First = Nil;

}

  

// Alokasi node baru

address alokasi(infotype x){

    address P = new ElmList;

    P->info = x;

    P->next = Nil;

    return P;

}

  

// Dealokasi node

void dealokasi(address &P){

    delete P;

    P = Nil;

}

  

// Insert pertama

void insertFirst(List &L, address P){

    if(L.First == Nil){

        L.First = P;

        P->next = P;

    } else {

        address last = L.First;

        while(last->next != L.First){

            last = last->next;

        }

        P->next = L.First;

        last->next = P;

        L.First = P;

    }

}

  

// Insert setelah Prec

void insertAfter(List &L, address Prec, address P){

    if(Prec != Nil){

        P->next = Prec->next;

        Prec->next = P;

    }

}

  

// Insert terakhir

void insertLast(List &L, address P){

    if(L.First == Nil){

        insertFirst(L,P);

    } else {

        address last = L.First;

        while(last->next != L.First){

            last = last->next;

        }

        last->next = P;

        P->next = L.First;

    }

}

  

// Delete pertama

void deleteFirst(List &L, address &P){

    if(L.First != Nil){

        if(L.First->next == L.First){

            P = L.First;

            L.First = Nil;

        } else {

            address last = L.First;

            while(last->next != L.First){

                last = last->next;

            }

            P = L.First;

            L.First = P->next;

            last->next = L.First;

            P->next = Nil;

        }

    }

}

  

// Delete setelah Prec

void deleteAfter(List &L, address Prec, address &P){

    if(Prec != Nil && Prec->next != L.First){

        P = Prec->next;

        Prec->next = P->next;

        P->next = Nil;

    }

}

  

// Delete terakhir

void deleteLast(List &L, address &P){

    if(L.First != Nil){

        if(L.First->next == L.First){

            P = L.First;

            L.First = Nil;

        } else {

            address last = L.First;

            address prec = Nil;

  

            while(last->next != L.First){

                prec = last;

                last = last->next;

            }

  

            P = last;

            prec->next = L.First;

            P->next = Nil;

        }

    }

}

  

// Mencari data berdasarkan NIM

address findElm(List L, infotype x){

    if(L.First != Nil){

        address P = L.First;

        do{

            if(P->info.nim == x.nim){

                return P;

            }

            P = P->next;

        } while(P != L.First);

    }

    return Nil;

}

  

// Menampilkan isi list

void printInfo(List L){

    if(L.First != Nil){

        address P = L.First;

        cout << "Isi Data Mahasiswa :" << endl;

        do{

            cout << "Nama  : " << P->info.nama << endl;

            cout << "NIM   : " << P->info.nim << endl;

            cout << "L/P    : " << P->info.jenis_kelamin << endl;

            cout << "IPK   : " << P->info.ipk << endl;

            cout << "----------------------" << endl;

            P = P->next;

        } while(P != L.First);

    } else {

        cout << "List kosong" << endl;

    }

}
```

### circular.h
``` h
#ifndef CIRCULARLIST_H_INCLUDED

#define CIRCULARLIST_H_INCLUDED

  

#include <iostream>

using namespace std;

  

#define Nil NULL

  

// Struktur data mahasiswa

typedef struct mahasiswa {

    string nama;

    string nim;

    char jenis_kelamin;

    float ipk;

} infotype;

  

// Pointer ke elemen list

typedef struct ElmList *address;

  

// Struktur elemen list

struct ElmList {

    infotype info;

    address next;

};

  

// Struktur list

struct List {

    address First;

};

  

// Membuat list kosong

void createList(List &L);

  

// Membuat node baru

address alokasi(infotype x);

  

// Menghapus node

void dealokasi(address &P);

  

// Insert data di awal list

void insertFirst(List &L, address P);

  

// Insert data setelah node tertentu

void insertAfter(List &L, address Prec, address P);

  

// Insert data di akhir list

void insertLast(List &L, address P);

  

// Hapus data pertama

void deleteFirst(List &L, address &P);

  

// Hapus data setelah node tertentu

void deleteAfter(List &L, address Prec, address &P);

  

// Hapus data terakhir

void deleteLast(List &L, address &P);

  

// Mencari data berdasarkan NIM

address findElm(List L, infotype x);

  

// Menampilkan seluruh isi list

void printInfo(List L);

  

#endif
```

### main.cpp
``` cpp
#include "circularlist.h"

  

// Fungsi create sesuai soal

address createData(string nama, string nim, char jenis_kelamin, float ipk)

{

    infotype x;

    address P;

  

    x.nama = nama;

    x.nim = nim;

    x.jenis_kelamin = jenis_kelamin;

    x.ipk = ipk;

  

    P = alokasi(x);

    return P;

}

  

int main()

{

    List L, A, B, L2;

    address P1 = Nil;

    address P2 = Nil;

    infotype x;

  

    createList(L);

  

    cout<<"coba insert first, last, dan after"<<endl;

  

    P1 = createData("Danu", "04", 'l', 4.0);

    insertFirst(L,P1);

  

    P1 = createData("Fahmi", "06", 'l',3.45);

    insertLast(L,P1);

  

    P1 = createData("Bobi", "02", 'l',3.71);

    insertFirst(L,P1);

  

    P1 = createData("Ali", "01", 'l', 3.3);

    insertFirst(L,P1);

  

    P1 = createData("Gita", "07", 'p', 3.75);

    insertLast(L,P1);

  

    x.nim = "07";

    P1 = findElm(L,x);

  

    P2 = createData("Cindi", "03", 'p', 3.5);

    insertAfter(L, P1, P2);

  

    x.nim = "02";

    P1 = findElm(L,x);

  

    P2 = createData("Hilmi", "08", 'p', 3.3);

    insertAfter(L, P1, P2);

  

    x.nim = "04";

    P1 = findElm(L,x);

  

    P2 = createData("Eli", "05", 'p', 3.4);

    insertAfter(L, P1, P2);

  

    printInfo(L);

  

    return 0;

}
```

## Output

![Output](LAPRAK/LAPRAK%20SEM%203/MODUL%2011%20x%20Multi%20Linked%20List/output/o3m11.png)

![Output](o4m11.png)
Program ini membuat ADT Circular Linked List untuk menyimpan data mahasiswa (nama, NIM, jenis kelamin, dan IPK). Struktur datanya terdiri dari node (`ElmList`) yang saling terhubung membentuk lingkaran, di mana elemen terakhir menunjuk kembali ke elemen pertama.
File circularlist.h berisi definisi struktur data dan deklarasi semua fungsi.  
File circularlist.cpp berisi implementasi fungsi-fungsi seperti membuat list, menambah data di awal/akhir/tengah, menghapus data, mencari data berdasarkan NIM, dan menampilkan seluruh isi list.  
File main.cpp digunakan untuk menguji fungsi dengan cara menambahkan beberapa data mahasiswa, menyisipkan data setelah NIM tertentu, lalu menampilkan hasilnya.
Kesimpulannya, program ini menunjukkan cara mengelola data mahasiswa menggunakan Circular Linked List di C++.

## Referensi

1. Modul Praktikum
2. https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html
3. http://firmaninformatika.blogspot.com/2014/11/referensi-multiple-linked-list-multi.html
