// Algoritma Spanning Tree (MST). Programnya adalah
// untuk representasi matriks adjacency dari grafik
#include <stdio.h> 
#include <limits.h> 
#include<stdbool.h> 
// Jumlah simpul dalam grafik
#define V 5 

// Fungsi utilitas untuk menemukan titik dengan
// nilai kunci minimum, dari himpunan simpul
// belum termasuk dalam MST
int minKey(int key[], bool mstSet[]) 
{ 
// Inisialisasi nilai min
int min = INT_MAX, min_index; 

for (int v = 0; v < V; v++) 
	if (mstSet[v] == false && key[v] < min) 
		min = key[v], min_index = v; 

return min_index; 
} 

// Fungsi utilitas untuk mencetak
// membuat MST yang disimpan dalam induk []
int printMST(int parent[], int n, int graph[V][V]) 
{ 
printf("Edge \tWeight\n"); 
for (int i = 1; i < V; i++) 
	printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 

// Berfungsi untuk membuat dan mencetak MST untuk
// grafik diwakili menggunakan adjacency
// representasi matriks 
void primMST(int graph[V][V]) 
{ 
// Array untuk menyimpan MST yang dibangun
int parent [V];
// Nilai kunci yang digunakan untuk memilih batas bobot minimum dalam pemotongan
int key [V];
// Untuk mewakili set simpul yang belum termasuk dalam 
MSTbool mstSet [V];
// Inisialisasi semua kunci sebagai INFINITE	
for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

// Selalu sertakan simpul pertama pertama dalam MST.
// Buat kunci 0 sehingga simpul ini diambil sebagai simpul pertama.	

key[0] = 0;	 
	parent[0] = -1; // Node pertama selalu root dari MST
	
	// MST akan memiliki simpul V 
	for (int count = 0; count < V-1; count++) 
	{ 
		// Pilih simpul kunci minimum dari
		// set simpul yang belum termasuk dalam MST
		int u = minKey(key, mstSet); 

		// Tambahkan simpul yang dipilih ke Set MST
		mstSet[u] = true; 

		// Perbarui nilai kunci dan indeks induk dari
		// simpul yang berdekatan dari simpul yang dipetik.
		// Pertimbangkan hanya simpul-simpul yang bukan
		// belum termasuk dalam MST
		for (int v = 0; v < V; v++) 

		// grafik [u] [v] bukan nol hanya untuk simpul yang berdekatan dari m
		// mstSet [v] adalah false untuk simpul yang belum termasuk dalam MST
		// Perbarui kunci hanya jika grafik [u] [v] lebih kecil dari kunci [v]
		if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
			parent[v] = u, key[v] = graph[u][v]; 
	} 

	// cetak MST yang dibuat
	printMST(parent, V, graph); 
} 


// program driver untuk menguji fungsi di atas
int main() 
{ 
/* Mari kita buat grafik berikut 
		2 3 
	(0)--(1)--(2) 
	| / \ | 
	6| 8/ \5 |7 
	| /	 \ | 
	(3)-------(4) 
			9		 */
int graph[V][V] = {{0, 2, 0, 6, 0}, 
					{2, 0, 3, 8, 5}, 
					{0, 3, 0, 0, 7}, 
					{6, 8, 0, 0, 9}, 
					{0, 5, 7, 9, 0}}; 

	// Cetak solusinya
	primMST(graph); 

	return 0; 
} 
