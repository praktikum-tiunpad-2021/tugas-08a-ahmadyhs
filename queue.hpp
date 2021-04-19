#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  int data;
  int priority;
  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> Q;

  Q.head = nullptr;
  Q.tail = nullptr;

  return Q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> help = q.head, pre;
  Element<T>* baru = new Element<T>;
  baru->data = value;
  baru->priority = priority;
  baru->next = nullptr;

  if(q.head==nullptr && q.tail==nullptr){
    q.head = baru;
    q.tail= baru;
  } else{ 
    while (baru->priority <= help->priority){
      if(help->next == nullptr) {break;}
      pre = help;
      help = help->next;
    }

    if(help==q.head && baru->priority > help->priority){
      baru->next = help;
      q.head = baru;
    } else if (help==q.tail && baru->priority < help->priority){
      help->next = baru;
      q.tail = baru; 
    } else {
      pre->next = baru;
      baru->next = help;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
   Element<T>* del= new Element<T>;
   if(q.head==nullptr && q.tail==nullptr){
     del = nullptr;
   } else if (q.head->next == nullptr){
     del = q.head;
     q.head = q.tail = nullptr;
   }  else {
     del = q.head;
     q.head = q.head->next;
     del->next = nullptr;
   }
   delete del;
}

}  // namespace priority_queue

}  // namespace strukdat
