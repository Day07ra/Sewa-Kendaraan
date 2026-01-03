#include <stdio.h>
#include <string.h>

// 1. STRUKTUR DATA 
struct Sewa {
    char namaPenyewa[50];
    char telpPenyewa[20]; 
    char jenisKendaraan[20];
    int hargaSewa;
    int lamaSewa;
    int subTotal;
    int diskon;
    int totalBayar;
};
// 2. VARIABEL GLOBAL
struct Sewa data[50]; 
int jumlah = 0;
// 3. FUNGSI CETAK STRUK
void cetakStruk(int i) {
    printf("\n");
    printf("========================================\n");
    printf("           RENTAL MAJU JAYA             \n");
    printf("       Jl. Merdeka No. 45, Jakarta      \n");
    printf("         Telp: 0812-3456-7890           \n");
    printf("========================================\n");
    printf("Nama      : %s\n", data[i].namaPenyewa);
    printf("No. HP    : %s\n", data[i].telpPenyewa); 
    printf("Kendaraan : %s\n", data[i].jenisKendaraan);
    printf("Lama Sewa : %d hari\n", data[i].lamaSewa);
    printf("Harga     : Rp %d/hari\n", data[i].hargaSewa);
    printf("----------------------------------------\n");
    printf("Subtotal  : Rp %d\n", data[i].subTotal);
    printf("Diskon    : Rp %d\n", data[i].diskon);
    printf("----------------------------------------\n");
    printf("TOTAL     : Rp %d\n", data[i].totalBayar);
    printf("========================================\n");
    printf("    Terima Kasih Atas Kunjungan Anda    \n");
    printf("========================================\n");
}
// 4. FUNGSI INPUT DATA
void tambahData() {
    int pilihan;
    printf("\n--- INPUT DATA PENYEWA ---\n");
   
    printf("Masukkan Nama: ");
    getchar(); 
    fgets(data[jumlah].namaPenyewa, 50, stdin);
    data[jumlah].namaPenyewa[strcspn(data[jumlah].namaPenyewa, "\n")] = 0;

    printf("Masukkan No HP: ");
    fgets(data[jumlah].telpPenyewa, 20, stdin);
    data[jumlah].telpPenyewa[strcspn(data[jumlah].telpPenyewa, "\n")] = 0;
  
    printf("Pilih Kendaraan:\n");
    printf("1. Motor (Rp 50.000)\n");
    printf("2. Mobil (Rp 300.000)\n");
    printf("Pilihan (1/2): ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        strcpy(data[jumlah].jenisKendaraan, "Motor");
        data[jumlah].hargaSewa = 50000;
    } else {
        strcpy(data[jumlah].jenisKendaraan, "Mobil");
        data[jumlah].hargaSewa = 300000;
    }
    printf("Lama Sewa (hari): ");
    scanf("%d", &data[jumlah].lamaSewa);

    data[jumlah].subTotal = data[jumlah].hargaSewa * data[jumlah].lamaSewa;
    
    if (data[jumlah].lamaSewa > 2) {
        data[jumlah].diskon = data[jumlah].subTotal * 10 / 100; 
    } else {
        data[jumlah].diskon = 0;
    }
    data[jumlah].totalBayar = data[jumlah].subTotal - data[jumlah].diskon;
    
    cetakStruk(jumlah);
    jumlah++; 
}
// 5. FUNGSI LAPORAN
void lihatLaporan() {
    int i; 
    if (jumlah == 0) {
        printf("\nBelum ada data transaksi.\n");
    } else {
        printf("\n--- LAPORAN HARIAN ---\n");
        for (i = 0; i < jumlah; i++) {
            printf("%d. %s (%s) - %s : Rp %d\n", 
                i + 1, 
                data[i].namaPenyewa, 
                data[i].telpPenyewa, 
                data[i].jenisKendaraan, 
                data[i].totalBayar);
        }
    }
}
// 6. MAIN PROGRAM
int main() {
    int menu;
    do {
        printf("\n==================================\n");
        printf("    SISTEM RENTAL MAJU JAYA       \n");
        printf("==================================\n");
        printf("1. Sewa Kendaraan \n");
        printf("2. Lihat Laporan Harian\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                tambahData();
                break;
            case 2:
                lihatLaporan();
                break;
            case 3:
                printf("Terima kasih.\n");
                break;
            default:
                printf("Pilihan salah.\n");
        }
    } while (menu != 3);
    return 0;
}
