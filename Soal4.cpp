#include <iostream>
#include <queue>
using namespace std;

struct Pelanggan {
    int nomor;
    int waktuLayanan;
};

class Queue {
public:
    void enqueue(Pelanggan p) { data.push(p); }
    void dequeue() { if (!data.empty()) data.pop(); }
    bool isEmpty() { return data.empty(); }
    Pelanggan front() { return data.front(); }
private:
    queue<Pelanggan> data;
};

int main() {
    Queue q;
    q.enqueue({1, 10});
    q.enqueue({2, 15});
    cout << "Pelanggan dengan nomor antrian: " << q.front().nomor << endl;
    q.dequeue();
    return 0;
}
