#include <iostream>
#include <vector>
using namespace std;

// Struktur Node untuk anggota keluarga
struct Node {
    string nama;
    vector<Node*> children;
};

// Fungsi untuk membuat node baru
Node* newNode(const string& nama) {
    Node* node = new Node;
    node->nama = nama;
    return node;
}

// Fungsi untuk menambahkan anak ke parent
void addChild(Node* parent, Node* child) {
    if (parent != nullptr) {
        parent->children.push_back(child);
    }
}

// Fungsi traversal preorder
void preorder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->nama << " ";
    for (int i = 0; i < root->children.size(); i++) {
        Node* child = root->children[i];
        preorder(child);
    }
}

//fungsi untuk mencetak anggota keluarga pada level tertentu
void cetakLevel(Node* root, int target, int level = 0) {
    if (root == nullptr) return;
    if (level == target) {
        cout << root->nama << " ";
    }
    for (int i = 0; i < root->children.size(); i++) {
        Node* child = root->children[i];
        cetakLevel(child, target, level + 1);
    }
}

// Fungsi untuk menghitung jumlah keturunan dari sebuah node
int hitungKeturunan(Node* root) {
    if (root == nullptr) return 0;

    int total = root->children.size();
    for (int i = 0; i < root->children.size(); i++) {
        Node* child = root->children[i];
        total += hitungKeturunan(child);
    }
    return total;
}

int main() {
    // Membuat struktur silsilah keluarga

    Node* kakek = newNode("Kakek");
    Node* paman = newNode("Paman");
    Node* ayah  = newNode("Ayah");
    Node* saya  = newNode("Saya");
    Node* sepupu = newNode("Sepupu");

    // Menambahkan hubungan antar anggota keluarga
    addChild(kakek, paman);
    addChild(kakek, ayah);
    addChild(ayah, saya);
    addChild(paman, sepupu);

    // Menampilkan hasil preorder traversal
    cout << "Traversal Preorder Silsilah Keluarga:\n";
    preorder(kakek);
    cout << endl;

    // Contoh penggunaan: cetak anggota di level tertentu
    cout << "Anggota keluarga di level 1:\n";
    cetakLevel(kakek, 1); 
    cout << endl;

    // Contoh penggunaan: hitung jumlah keturunan dari Kakek
    cout << "Jumlah keturunan Kakek: " << hitungKeturunan(kakek) << endl;

    return 0;
}