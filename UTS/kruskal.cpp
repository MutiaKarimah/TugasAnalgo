// Program C ++ untuk algoritma Kruskal untuk menemukan Minimum Spanning Tree
// dari grafik terhubung, tidak diarahkan, dan berbobot tertentu
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// struktur untuk merepresentasikan tepi tertimbang dalam grafik
struct Edge 
{ 
	int src, dest, weight; 
}; 

// sebuah struktur untuk mewakili yang terhubung, tidak diarahkan
// dan grafik berbobot 
struct Graph 
{ 
	//V->  Jumlah simpul, E-> Jumlah tepi 
	int V, E; 

	// grafik direpresentasikan sebagai larik tepi.
	// Karena grafiknya tidak terarah, ujungnya
	// dari src ke dest juga edge dari dest
	// ke src. Keduanya dihitung sebagai 1 edge di sini. 
	struct Edge* edge; 
}; 

// Membuat grafik dengan simpul V dan tepi E 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 

	graph->edge = new Edge[E]; 

	return graph; 
} 

// // Struktur yang merepresentasikan subset untuk union-find 
struct subset 
{ 
	int parent; 
	int rank; 
}; 

// Fungsi utilitas untuk menemukan set elemen i
// (menggunakan teknik kompresi jalur)
int find(struct subset subsets[], int i) 
{ 
// temukan root dan buat root sebagai parent dari i
// (kompresi jalur)
	if (subsets[i].parent != i) 
		subsets[i].parent = find(subsets, subsets[i].parent); 

	return subsets[i].parent; 
} 

// Fungsi yang menggabungkan dua set x dan y
// (menggunakan union berdasarkan pangkat) 
void Union(struct subset subsets[], int x, int y) 
{ 
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y); 

// Pasang pohon peringkat yang lebih kecil di bawah akar tinggi
// pohon peringkat (union berdasarkan Peringkat)
	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 

	// Jika peringkatnya sama, maka jadikan sebagai root dan
	// meningkatkan peringkatnya satu per satu 
	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 

// Bandingkan dua sisi menurut bobotnya.
// Digunakan dalam qsort () untuk mengurutkan array tepi 
int myComp(const void* a, const void* b) 
{ 
	struct Edge* a1 = (struct Edge*)a; 
	struct Edge* b1 = (struct Edge*)b; 
	return a1->weight > b1->weight; 
} 

// Fungsi utama untuk membangun MST menggunakan algoritma Kruskal 
void KruskalMST(struct Graph* graph) 
{ 
	int V = graph->V; 
	struct Edge result[V]; // Tnis akan menyimpan MST yang dihasilkan
	int e = 0; // Variabel indeks, digunakan untuk hasil []
	int i = 0; // Variabel indeks, digunakan untuk tepi yang diurutkan 

	// Langkah 1: Urutkan semua tepi dalam non-menurun
	// urutan beratnya. Jika kami tidak diizinkan
	// ubah grafik yang diberikan, kita bisa membuat salinan
	// susunan tepi 
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 

	// Alokasikan memori untuk membuat subset V 
	struct subset *subsets = 
		(struct subset*) malloc( V * sizeof(struct subset) ); 

	// Buat himpunan bagian V dengan elemen tunggal 
	for (int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 

	// Jumlah tepi yang akan diambil sama dengan V-1 
	while (e < V - 1) 
	{ 
		// Langkah 2: Pilih tepi terkecil. Dan kenaikan
		// indeks untuk iterasi berikutnya 
		struct Edge next_edge = graph->edge[i++]; 

		int x = find(subsets, next_edge.src); 
		int y = find(subsets, next_edge.dest); 

		// Jika memasukkan tepi ini tidak menyebabkan siklus,
		// sertakan dalam hasil dan tambahkan indeks
		// hasil untuk tepi berikutnya 
		if (x != y) 
		{ 
			result[e++] = next_edge; 
			Union(subsets, x, y); 
		} 
		// Else discard the next_edge 
	} 

	// cetak isi hasil [] untuk menampilkan
	// membangun MST 
	printf("Following are the edges in the constructed MST\n"); 
	for (i = 0; i < e; ++i) 
		printf("%d -- %d == %d\n", result[i].src, result[i].dest, 
												result[i].weight); 
	return; 
} 

// Program driver untuk menguji fungsi-fungsi di atas 
int main() 
{ 
	/* Mari kita buat grafik tertimbang berikut 
			10 
		0--------1 
		| \	 | 
	6| 5\ |15 
		|	 \ | 
		2--------3 
			4	 */
	int V = 4; // Jumlah simpul dalam grafik
	int E = 5; // Jumlah tepi dalam grafik 
	struct Graph* graph = createGraph(V, E); 


	// add edge 0-1 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 
	graph->edge[0].weight = 10; 

	// add edge 0-2 
	graph->edge[1].src = 0; 
	graph->edge[1].dest = 2; 
	graph->edge[1].weight = 6; 

	// add edge 0-3 
	graph->edge[2].src = 0; 
	graph->edge[2].dest = 3; 
	graph->edge[2].weight = 5; 

	// add edge 1-3 
	graph->edge[3].src = 1; 
	graph->edge[3].dest = 3; 
	graph->edge[3].weight = 15; 

	// add edge 2-3 
	graph->edge[4].src = 2; 
	graph->edge[4].dest = 3; 
	graph->edge[4].weight = 4; 

	KruskalMST(graph); 

	return 0; 
} 
