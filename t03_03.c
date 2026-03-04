#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk FLT_MAX dan FLT_MIN

int main() {
    int n;

    // Baca baris pertama (jumlah baris masukan berikutnya)
    // Tanpa prompt, sesuai instruksi terbaru
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Input tidak valid. Harap masukkan bilangan bulat positif untuk n.\n");
        return 1; // Keluar dengan kode error
    }

    // Validasi n harus bilangan bulat positif
    if (n <= 0) {
        fprintf(stderr, "n harus merupakan bilangan bulat positif.\n");
        return 1; // Keluar dengan kode error
    }

    // Jika n=1, tidak ada pasangan berturut, jadi rata-rata tidak relevan
    if (n == 1) {
        fprintf(stderr, "Untuk menghitung rata-rata dua nilai berturut, n harus lebih dari 1.\n");
        return 1;
    }

    int min_val = INT_MAX; // Inisialisasi dengan nilai maksimum integer
    int max_val = INT_MIN; // Inisialisasi dengan nilai minimum integer

    float min_avg_consecutive = FLT_MAX; // Inisialisasi dengan nilai maksimum float
    float max_avg_consecutive = FLT_MIN; // Inisialisasi dengan nilai minimum float

    int prev_val; // Untuk menyimpan nilai sebelumnya
    int current_val;

    // Baca n baris masukan berikutnya tanpa prompt
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &current_val) != 1) {
            fprintf(stderr, "Input tidak valid. Harap masukkan bilangan bulat.\n");
            return 1; // Keluar dengan kode error
        }

        // Validasi nilai harus antara -100 dan 100
        if (current_val < -100 || current_val > 100) {
            fprintf(stderr, "Nilai masukan harus berada dalam rentang -100 hingga 100.\n");
            return 1; // Keluar dengan kode error
        }

        // Update min_val dan max_val
        if (current_val < min_val) {
            min_val = current_val;
        }
        if (current_val > max_val) {
            max_val = current_val;
        }

        // Untuk perhitungan rata-rata berturut, mulai dari elemen kedua
        if (i > 0) {
            float current_avg = (float)(prev_val + current_val) / 2.0f;

            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
        }

        prev_val = current_val; // Simpan nilai saat ini untuk iterasi berikutnya
    }

    // Output hasil
    printf("%d\n", min_val);                     // Nilai terkecil
    printf("%d\n", max_val);                     // Nilai terbesar
    printf("%.2f\n", min_avg_consecutive);       // Rata-rata terendah dari dua nilai berturut dengan 2 digit presisi
    printf("%.2f\n", max_avg_consecutive);       // Rata-rata tertinggi dari dua nilai berturut dengan 2 digit presisi

    return 0; // Berhasil
}