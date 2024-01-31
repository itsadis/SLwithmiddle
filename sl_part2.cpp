#include <iostream>
#include <string>

using namespace std;

// Deklarasi single linked list
struct Buku {
    // Komponen / sumber
    string judul, pengarang;
    int tahunTerbit;

    Buku* next;

};

Buku *head, *tail, *cur, *newNode, *del, *before;

//create single Linked list
void createSingleLinkedList(string judul,string pengarang, int tB){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

//tambahAwal Single linked list
void addFirst(string judul,string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;
}

// tambahAkhir single linked list
void addLast(string judul,string pengarang, int tB){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode; 
    tail = newNode;
}

// tambah tengah single linked list
void addMiddle(string judul, string pengarang, int tB, int posisi){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;

    // tranversing
    cur = head;
    int nomor = 1;
    while( nomor < posisi -1 ){
        cur = cur->next;
        nomor++;
    }

    newNode->next = cur->next;
    cur->next = newNode;

}


// Remove First
void removeFirst(){
    del = head;
    head = head->next;
    delete del;
}

// Remove Last
void removeLast(){
    del = tail;
    cur = head;
    while( cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

// remove middle 
void removeMiddle(int posisi){
    if( posisi < 1 || posisi > countSingleLinkedList() ){
        cout << "Posisi diluar jangkauan" << endl;
    } else if( posisi == 1 || posisi == countSingleLinkedList() ){
        cout << "Posisi bukan tengah" << endl;
    } else {
        int nomor = 1;
        cur = head;
        while( nomor <= posisi){
            if( nomor == posisi-1 ){
                before = cur;
            }
            if( nomor == posisi){
                del = cur;
            }
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
    }
}

// ubahAwal Single linked list
void changeFirst(string judul,string pengarang, int tB){
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
}

// ubahAkhir Single linked list
void changeLast(string judul,string pengarang, int tB){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;
}

// print single linked list
int countSingleLinkedList(){
    cur = head;
    int jumlah = 0;
    while(cur != NULL){
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

// print single linked list
void printSingleLinkedList(){
    cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
    cur = head;
    while(cur != NULL){
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Pengarang Buku : " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

        cur = cur->next;
    }
}

int main() {
    
createSingleLinkedList("Kata", "Geez & Aan", 2018);

printSingleLinkedList();

cout << "\n\n" << endl;

addFirst("Dia adalah Kakakku", "Tere Liye", 2009);

printSingleLinkedList();

cout << "\n\n" << endl;

addLast("Aroma Karsa", "Dee Lestari", 2018);

printSingleLinkedList();

cout << "\n\n" << endl;

removeFirst();

printSingleLinkedList();

cout << "\n\n" << endl;

addLast("11.11", "Fiersa Besari", 2018);

printSingleLinkedList();

cout << "\n\n" << endl;

removeLast();

printSingleLinkedList();

cout << "\n\n" << endl;

changeFirst("Berhenti di Kamu", "Gia Pratama", 2018);

printSingleLinkedList();

cout << "\n\n" << endl;

addMiddle("Bumi Manusia", "Pramoedya Ananta Toer", 2005, 2);

printSingleLinkedList();

cout << "\n\n" << endl;

addMiddle("Negeri 5 Menara", "Ahmad Fuadi", 2009, 3);

printSingleLinkedList();

cout << "\n\n" << endl;

removeMiddle(2);

printSingleLinkedList();

cout << "\n\n" << endl;

}
