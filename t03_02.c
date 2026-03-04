#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk FLT_MAX

int main() {
    int n;

    // Baca baris pertama (jumlah baris masukan berikutnya)
    // Tidak ada prompt di sini karena umumnya input n diberikan terlebih dahulu dalam format script/pipeline,
    // dan permintaan "angka keberapa dimasukkan" lebih merujuk pada input nilai setelah n.
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

    int prev_val; // Untuk menyimpan nilai sebelumnya
    int current_val;

    // Baca n baris masukan berikutnya dengan prompt
    for (int i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i + 1); // Prompt input sesuai permintaan
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
        }

        prev_val = current_val; // Simpan nilai saat ini untuk iterasi berikutnya
    }

    // Output hasil ("hasilnya berapa" diinterpretasikan sebagai tampilan hasil akhir sesuai contoh)
    printf("%d\n", min_val);                     // Nilai terkecil
    printf("%d\n", max_val);                     // Nilai terbesar
    printf("%.2f\n", min_avg_consecutive);       // Rata-rata terendah dari dua nilai berturut dengan 2 digit presisi

    return 0; // Berhasil
}