#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Musik {
  string lagu;
  string namaPenyanyi;
  Musik* next;
};

Musik* top = NULL;
Musik* front = NULL;
Musik* rear = NULL;

bool isEmptyStack() { return top == NULL; }

bool isEmptyQueue() { return front == NULL; }

void push(string lagu, string namaPenyanyi) {
  Musik* newNode = new Musik;
  newNode->lagu = lagu;
  newNode->namaPenyanyi = namaPenyanyi;
  newNode->next = top;
  top = newNode;
}

void pop(string& lagu, string namaPenyanyi) {
  if (!isEmptyStack()) {
    Musik* temp = top;
    lagu = top->lagu;
    namaPenyanyi = top->namaPenyanyi;
    top = top->next;
    delete temp;
  }
}

void displaystack() {
  if (isEmptyStack()) {
    cout << "Kosong bang" << endl;
    return;
  }
  cout << "\n==== HISTORY PEMUTARAN (STACK) ===" << endl;
  Musik* current = top;
  while (current != 0) {
    cout << "- " << current->lagu << "|" << current->namaPenyanyi << endl;
    current = current->next;
  }
}

void enqueue(string lagu, string namaPenyanyi) {
  Musik* newNode = new Musik;
  newNode->lagu = lagu;
  newNode->namaPenyanyi = namaPenyanyi;
  newNode->next = NULL;

  if (isEmptyQueue()) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

void dequeue(string& lagu, string& namaPenyayi) {
  if (!isEmptyQueue()) {
    Musik* temp = front;
    lagu = front->lagu;
    namaPenyayi = front->namaPenyanyi;
    front = front->next;
    if (front == NULL) {
      rear = NULL;
    }
    delete temp;
  }
}

void peekQueue(string& lagu, string& namaPenyanyi) {
  if (!isEmptyQueue()) {
    lagu = front->lagu;
    namaPenyanyi = front->namaPenyanyi;
  }
}

void displayQueue() {
  if (!isEmptyQueue) {
    cout << "masih kosong bang" << endl;
    return;
  }
  cout << "\n==== Playlist (QUEUE) ===" << endl;
  Musik* current = front;
  while (current != 0) {
    cout << "- " << current->lagu << "|" << current->namaPenyanyi << endl;
    current = current->next;
  }
}

void inputPlaylist() {
  string lagu;
  string namaPenyanyi;
  cout << "Masukkan Judul Lagu: ";
  cin >> lagu;
  cin.ignore();
  cout << "Masukkan Penyayi: ";
  getline(cin, namaPenyanyi);
  push(lagu, namaPenyanyi);
  cout << "Berhasil Ditambahkan" << endl;
  cout << endl;
}

void visit() {
  if (isEmptyStack()) {
    cout << "Kosong bang" << endl;
    return;
  }
  string lagu;
  string namaPenyanyi;
  Musik* current = top;
  while (current != 0) {
    cout << "Memainkan lagu: " << current->lagu << "|" << current->namaPenyanyi
         << endl;
    current = current->next;
  }
  cout << endl;
}

void playPop() {
  if (isEmptyStack()) {
    cout << "Kosong bang" << endl;
  } else {
    string lagu;
    string namaPenyanyi;
    pop(lagu, namaPenyanyi);
    enqueue(lagu, namaPenyanyi);
    cout << "Memainkan dan menghapus lagu: " << lagu << "|" << namaPenyanyi
         << endl;
  }
  cout << endl;
}

void cekPlaylist() {
  if (isEmptyQueue()) {
    cout << "Kosong Bang" << endl;
    return;
  } else {
    string lagu;
    string namaPenyanyi;
    peekQueue(lagu, namaPenyanyi);
    push(lagu, namaPenyanyi);
    displayQueue();
  }
  cout << endl;
}

void cekHistory() { displaystack(); }

int main() {
  int pilihan;

  do {
    cout << "===== Music Player =====" << endl;
    cout << "1. Input Playlist" << endl;
    cout << "2. Play Lagu (Visit)" << endl;
    cout << "3. Play & Pop Playlist" << endl;
    cout << "4. Cek Playlist" << endl;
    cout << "5. Cek History" << endl;
    cout << "6. Exit" << endl;
    cout << "Pilihan Menu : ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        inputPlaylist();
        break;
      case 2:
        visit();
        break;
      case 3:
        playPop();
        break;
      case 4:
        cekPlaylist();
        break;
      case 5:
        cekHistory();
        break;
      case 6:
        cout << "TyTyTy >_<" << endl;
        break;
      default:
        cout << "Input tidak valid" << endl;
    }

  } while (pilihan != 6);
  return 0;

}
