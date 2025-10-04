# Laporan Praktikum Stuktur Data MODUL 2 x Pengenalan Bahasa C++ Bagian2


Nama : Rifa Cahya Ariby 
NIM : 103112400268
Kelas : S1 IF12 07

---
## Dasar Teori

- Array dalam C++ adalah struktur data yang menyimpan sekumpulan data dengan tipe yang sama dalam satu variabel. Setiap data dalam array disebut elemen dan dapat diakses menggunakan indeks, yang dimulai dari angka 0. Array membantu mengelola data secara terorganisir dan efisien, terutama saat banyak nilai yang perlu disimpan.

- Pointer dalam C++ adalah variabel khusus yang menyimpan alamat memori dari variabel lain. Setiap variabel dalam program memiliki alamat memori unik di RAM, dan pointer menyimpan nomor alamat tersebut sehingga program dapat mengakses nilai variabel lain secara tidak langsung melalui alamat memorinya. Operator utama dalam penggunaan pointer adalah:
  - Operator alamat (&) untuk mendapatkan alamat variabel.
  - Operator dereference () untuk mengakses nilai yang tersimpan pada alamat memori yang ditunjuk pointer.*

- Fungsi (Function) adalah subprogram yang memiliki tipe data pengembalian (return value). Fungsi mengolah data dan mengembalikan hasilnya ke pemanggil menggunakan perintah return. Fungsi dapat langsung dipakai dalam ekspresi atau disimpan di variabel. 

- Prosedur (Procedure) adalah subprogram yang tidak mengembalikan nilai apa pun dan biasanya menggunakan tipe void untuk deklarasinya. Prosedur hanya menjalankan perintah tanpa menghasilkan nilai balik, sehingga pemanggil tidak mendapatkan hasil kembalian secara langsung

| Aspek          | Fungsi                                      | Prosedur                              |
| -------------- | ------------------------------------------- | ------------------------------------- |
| Tipe Return    | Memiliki tipe data return (int, float, dsb) | Tipe void (tidak mengembalikan nilai) |
| Return Value   | Ada nilai balik menggunakan return          | Tidak ada nilai balik                 |
| Pemakaian Nama | Nama fungsi dapat dipakai sebagai nilai     | Nama prosedur dipanggil saja          |
| Contoh Sintaks | int luas(int p, int l) { return p*l; }      | void cetakLuas() { cout << ...; }     |

## Guided
### 1.  Array

``` cpp
#include <iostream>

using namespace std;

  

int main ()

{

    int nilai [5] = {1,2,3,4,5};

    for (int i = 0; i < 5; i++)

    {

        cout << "elemen ke-" << i << " = " << nilai[i] << endl;

    }

}

```

### Output 

![Output](o1m2.png)

Program ini membuat sebuah array berisi 5 angka, lalu mencetak tiap angka beserta posisinya menggunakan perulangan for dari indeks 0 sampai 4. Jadi, program menampilkan semua isi array dengan urutan dan nomor indeksnya


### 2. Matriks

``` cpp
#include <iostream>

using namespace std;

  

int main ()

{

    int matriks[3][3] = {

        {1,2,3},

        {4,5,6},

        {7,8,9}};

    for (int i = 0; i < 3; i++)

    {

        for (int j = 0; j < 3; j++)

        {

            cout << matriks[i][j] << " ";

        }

        cout << endl;

    }

}
```

### Output

![Output](o2m2.png)

Program ini membuat matriks 3x3 dengan array dua dimensi yang berisi angka 1 sampai 9. Lalu, menggunakan dua loop bersarang untuk mencetak setiap elemen matriks per baris dan kolom. Outputnya menampilkan matriks dalam bentuk baris dan kolom.


### 3. Pointer

``` cpp
#include <iostream>

using namespace std;

  

int main ()

{

    int umur = 25;

    int *p_umur;

  
  

    p_umur = &umur;

  

    cout << "Nilai 'umur': " << umur << endl;

    cout << "Alamat memori 'umur' : " << &umur << endl;

    cout << "Nilai 'pUmur' (alamat): " << p_umur << endl;

    cout << "Nilai yang diakses 'p_umur': " << *p_umur << endl;

    cout << "Alamat memori dari 'p_umur' itu sendiri: " << &p_umur << endl;

  

    return 0;

}

```

### Output

![Ouput](o3m2.png)

Program ini mengimplementasikan penggunaan pointer di C++. Variabel `umur` bertipe int disimpan nilai 25, kemudian pointer `p_umur` menyimpan alamat memori dari umur. Program menampilkan nilai umur, alamat memori umur, nilai pointer `p_umur` yang berisi alamat umur, nilai yang ditunjuk oleh `p_umur` (yaitu isi `umur`), dan alamat memori pointer `p_umur` itu sendiri.


### 4. Array pointer


``` cpp
#include <iostream>

using namespace std;

int main ()

{

    int data [5] = {10,20,30,40,50};

    int *p_data = data;

  

        cout << "Mengakses elemen array cara normal : " << endl;

        {

        for (int i = 0; i < 5; i++)

        cout << " Nilai elemen ke-" << i << " = " << data[i] << endl;

        }

  

        cout << "Mengakses elemen array menggunakan pointer : " << endl;

        {

        for (int i = 0; i < 5; i++)

        cout << " Nilai elemen ke-" << i << " = " << *(data + i) << endl;

        }

  

        return 0;

}
```
### Output

![Output](o4m2.png)

Program ini menunjukkan dua cara mengakses isi array, yaitu dengan langsung menggunakan indeks dan dengan pointer yang menunjuk ke alamat elemen pertama array sehingga kita bisa mengakses elemen satu per satu menggunakan pointer, memperlihatkan bahwa nama array di C++ sebenarnya adalah alamat pertama array dan pointer dapat digunakan untuk mengakses isi array sama seperti indeks.

### 5. String Pointer


``` cpp
#include <iostream>

using namespace std;

  

int main ()

{

    char pesan_array []= "Nasi Padang";

    char *pesan_pointer = "Ayam Bakar 23";

  

    cout << "String Array:" << pesan_array << endl;

    cout << "String Pointer:" << pesan_pointer << endl;

  
  

    // Mengubah karakter dalam array diperbolehkan

    pesan_array[0] = 'K';

    cout << "String Array setelah diubah:" << pesan_array << endl;

  

    // Pointer dapat diubah untuk menunjuk string lain

    pesan_pointer = "Sariman";

    cout << "String Pointer setelah diubah:" << pesan_pointer << endl;

  

    return 0;

}
```


### Output 

![Output](o5m2.png)

Program diatas menunjukkan perbedaan antara string yang disimpan dalam array karakter dan string yang disimpan melalui pointer. String dalam array karakter bisa diubah isinya karena disimpan langsung dalam memori, sedangkan pointer menunjuk ke string literal yang tidak bisa diubah isinya, tapi pointer itu bisa diarahkan ke string lain. Jadi, array string bisa dimodifikasi, sedangkan pointer string dapat menunjuk string yang berbeda.


### 6. Fungsi prosedur


``` cpp
#include <iostream>

using namespace std;

  

int hitungjumlah(int a, int b)

{

    int total = a + b;

    return total;

}

void tampilkanHasil(int hasil)

{

    std::cout << "Hasil penjumlahannya adalah: " << hasil << std::endl;

}

  

int main()

{

    int angka1 = 15;

    int angka2 = 10;

    int hasiljumlah;

  

    hasiljumlah = hitungjumlah(angka1, angka2);

    tampilkanHasil(hasiljumlah);

  

    return 0;

}
```

### Output

![Output](o6m2.png)

Fungsi `hitungjumlah` menerima dua parameter `a` dan `b`, menjumlahkannya, lalu mengembalikan totalnya. Fungsi `tampilkanHasil` menerima hasil penjumlahan dan mencetaknya ke layar. Di fungsi utama `main`, dua angka didefinisikan yaitu 15 dan 10, kemudian fungsi `hitungjumlah` dipanggil untuk mendapatkan hasil jumlahnya, yang kemudian dicetak menggunakan `tampilkanHasil`. Program dijalankan dan selesai dengan mengembalikan nilai 0. Kode ini sudah benar dan akan menampilkan "Hasil penjumlahannya adalah: 25" ketika dijalankan.

### 7.  Call by pointer


``` cpp
#include <iostream>

using namespace std;

  
  

void tukar(int *px, int *py)

{

    int temp = *px;

    *px = *py;

    *py = temp;

}

int main()

{

    int a = 10, b = 20;

    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;

    tukar(&a, &b);

    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    return 0;

}

```

### Output

![Output](o7m2.png)

Program ini berfungsi untuk menukar nilai dua variabel menggunakan pointer. Fungsi tukar menerima alamat kedua variabel sebagai parameter pointer, lalu menukar nilai yang ditunjuk pointer-pointer tersebut dengan menggunakan variabel sementara. Dengan cara ini, nilai variabel asli berubah setelah fungsi dipanggil karena operasi terjadi langsung di alamat memori variabel tersebut.


### 8. Call by reference


``` cpp
#include <iostream>

using namespace std;

  

int main()

{

    int a = 10, b = 20;

    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;

    tukar(a, b);

    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    return 0;

}

  

void tukar(int &x, int &y)

{

    int temp = x;

    x = y;

    y = temp;

}

```

### Output

![Output](o8m2.png)

Program tersebut berfungsi untuk menukar nilai dua variabel dengan menggunakan call by reference. Variabel a dan b yang semula bernilai 10 dan 20 dikirim ke fungsi `tukar` melalui referensi, sehingga perubahan yang dilakukan di dalam fungsi langsung memengaruhi nilai asli variabel tersebut. Akibatnya, setelah fungsi dijalankan, nilai a berubah menjadi 20 dan nilai b menjadi 10.

## Unguided

### Soal 1

> 1. Buatlah sebuah program untuk melakukan transpose pada sebuah matriks persegi berukuran 3x3. Operasi transpose adalah mengubah baris menjadi kolom dan sebaliknya. Inisialisasi matriks awal di dalam kode, kemudian buat logika untuk melakukan transpose dan simpan hasilnya ke dalam matriks baru. Terakhir, tampilkan matriks awal dan matriks hasil transpose.
> 
> Contoh Output:
> 
> Matriks Awal:
> 1 2 3
> 4 5 6
> 7 8 9
> 
> Matriks Hasil Transpose:
> 1 4 7
> 2 5 8
> 3 6 9




``` cpp
#include <iostream>

using namespace std;

  

int main() {

    int A[3][3] = {

        {1,1,1},

        {5,5,5},

        {8,8,8}};

    cout << "Matriks Awal:\n";

  

    for (int i=0;i<3;i++, cout<<endl)

        for (int j=0;j<3;j++) cout<<A[i][j]<<" ";

    cout << "\nMatriks Hasil Transpose:\n";

    for (int i=0;i<3;i++, cout<<endl)

        for (int j=0;j<3;j++) cout<<A[j][i]<<" ";

}

```


### Output

![Output](o9m2.png)

Program diatas membuat matriks 3x3, lalu menampilkan isi matriks tersebut. Setelah itu program menampilkan hasil transpose, yaitu menukar posisi baris menjadi kolom. Akhirnya baris pertama menjadi kolom pertama, baris kedua menjadi kolom kedua, dan baris ketiga menjadi kolom ketiga.


###  Soal 2

> 2. Buatlah program yang menunjukkan penggunaan call by reference. Buat sebuah prosedur bernama kuadratkan yang menerima satu parameter integer secara referensi (&). Prosedur ini akan mengubah nilai asli variabel yang dilewatkan dengan nilai kuadratnya. Tampilkan nilai variabel di main() sebelum dan sesudah memanggil prosedur untuk membuktikan perubahannya. 
> 
> Contoh Output:
> 
> Nilai awal: 5
> Nilai setelah dikuadratkan: 25



``` cpp
#include <iostream>

using namespace std;

  

// Prosedur kuadratkan

void kuadratkan(int &x) {

    x = x * x;

}

  

int main() {

    int angka = 5;

  

    cout << "Nilai awal: " << angka << endl;

    kuadratkan(angka); // dipanggil by reference

    cout << "Nilai setelah dikuadratkan: " << angka << endl;

  

    return 0;

}

```

### Output

![Output](o10m2.png)

Program ini mendefinisikan prosedur kuadratkan yang menerima parameter dengan referensi. Variabel angka bernilai 5, lalu ditampilkan sebagai nilai awal. Setelah dipanggil ke prosedur, nilai angka berubah menjadi hasil kuadratnya (25) karena referensi mengubah nilai asli variabel. Program kemudian menampilkan nilai setelah dikuadratkan.


## Referensi

1. https://www.dicoding.com/blog/memahami-esensi-bahasa-pemrograman-c/ 
2. https://codepolitan.com/blog/belajar-pointer-c-dasardasar-fungsi-dan-contoh-kode
3. https://www.materidosen.com/2017/01/perbedaan-fungsi-dan-prosedur-dalam.html
4. https://www.petanikode.com/cpp-array/
5. https://www.petanikode.com/cpp-pointer/