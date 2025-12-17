#include <iostream>
using namespace std;

struct Buku {
    int book_id;
    string title;
    string author;
    int year;
    bool status_available;
};

struct Node {
    Buku data;
    Node* left;
    Node* right;
};

Node* root = NULL;

// 1. Tambah Buku ke BST
Node* tambahBuku(Node* node, Buku bk) {
    if (node == NULL) {
        Node* baru = new Node;
        baru->data = bk;
        baru->left = baru->right = NULL;
        return baru;
    }
    if (bk.book_id < node->data.book_id)
        node->left = tambahBuku(node->left, bk);
    else
        node->right = tambahBuku(node->right, bk);
    return node;
}

// 2. Cari Buku berdasarkan ID
Node* cariBuku(Node* node, int id) {
    if (node == NULL || node->data.book_id == id)
        return node;
    if (id < node->data.book_id)
        return cariBuku(node->left, id);
    return cariBuku(node->right, id);
}

// 3. Tampilkan Semua Buku (Inorder)
void tampilkanSemuaBuku(Node* node) {
    if (node != NULL) {
        tampilkanSemuaBuku(node->left);
        cout << node->data.book_id << " | "
             << node->data.title << " | "
             << node->data.author << " | "
             << node->data.year << endl;
        tampilkanSemuaBuku(node->right);
    }
}

// 4. Tampilkan Buku Tersedia
void tampilkanBukuTersedia(Node* node) {
    if (node != NULL) {
        tampilkanBukuTersedia(node->left);
        if (node->data.status_available) {
            cout << node->data.book_id << " | "
                 << node->data.title << " (Tersedia)" << endl;
        }
        tampilkanBukuTersedia(node->right);
    }
}

// 5. Hitung Jumlah Buku
int hitungJumlahBuku(Node* node) {
    if (node == NULL) return 0;
    return 1 + hitungJumlahBuku(node->left) + hitungJumlahBuku(node->right);
}

// Menu
void menu() {
    cout << "\n=== MENU PERPUSTAKAAN ===\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Cari Buku\n";
    cout << "3. Tampilkan Semua Buku\n";
    cout << "4. Tampilkan Buku Tersedia\n";
    cout << "5. Hitung Jumlah Buku\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

int main() {
    int pilihan;
    do {
        menu();
        cin >> pilihan;

        if (pilihan == 1) {
            Buku bk;
            cout << "ID Buku: ";
            cin >> bk.book_id;
            cout << "Judul: ";
            cin >> bk.title;
            cout << "Penulis: ";
            cin >> bk.author;
            cout << "Tahun: ";
            cin >> bk.year;
            cout << "Status tersedia (1=ya, 0=tidak): ";
            cin >> bk.status_available;

            root = tambahBuku(root, bk);
        } 
        else if (pilihan == 2) {
            int id;
            cout << "Masukkan ID Buku: ";
            cin >> id;
            Node* hasil = cariBuku(root, id);
            if (hasil != NULL)
                cout << "Buku ditemukan: " << hasil->data.title << endl;
            else
                cout << "Buku tidak ditemukan\n";
        } 
        else if (pilihan == 3) {
            tampilkanSemuaBuku(root);
        } 
        else if (pilihan == 4) {
            tampilkanBukuTersedia(root);
        } 
        else if (pilihan == 5) {
            cout << "Total buku: " << hitungJumlahBuku(root) << endl;
        }

    } while (pilihan != 0);

    return 0;
}
