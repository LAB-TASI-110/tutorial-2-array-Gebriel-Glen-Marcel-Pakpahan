#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN

int main() {
    int n;

    // Baca baris pertama (jumlah baris masukan berikutnya)
    printf("Masukkan jumlah baris masukan berikutnya (n): ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Input tidak valid. Harap masukkan bilangan bulat positif untuk n.\n");
        return 1; // Keluar dengan kode error
    }

    // Validasi n harus bilangan bulat positif
    if (n <= 0) {
        fprintf(stderr, "n harus merupakan bilangan bulat positif.\n");
        return 1; // Keluar dengan kode error
    }

    int min_val = INT_MAX; // Inisialisasi dengan nilai maksimum integer
    int max_val = INT_MIN; // Inisialisasi dengan nilai minimum integer
    int current_val;

    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);

    // Baca n baris masukan berikutnya
    for (int i = 0; i < n; i++) {
        printf("Masukkan bilangan ke-%d: ", i + 1);
        if (scanf("%d", &current_val) != 1) {
            fprintf(stderr, "Input tidak valid. Harap masukkan bilangan bulat.\n");
            return 1; // Keluar dengan kode error
        }

        // Validasi nilai harus antara -100 dan 100
        if (current_val < -100 || current_val > 100) {
            fprintf(stderr, "Nilai masukan harus berada dalam rentang -100 hingga 100.\n");
            return 1; // Keluar dengan kode error
        }

        if (current_val < min_val) {
            min_val = current_val;
        }
        if (current_val > max_val) {
            max_val = current_val;
        }
    }

    // Output hasil
    printf("%d\n", min_val); // Nilai terkecil
    printf("%d\n", max_val); // Nilai terbesar

    return 0; // Berhasil
}