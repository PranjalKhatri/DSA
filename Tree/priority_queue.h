#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include"tree.h"
#include<vector>
#include<math.h>
namespace pop {

    template<class T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
    class max_pq
    {
    private:
        std::vector<int> heap;
        std::size_t m_capacity;
        std::size_t m_last_index;
        int empty_value;
    public:
        max_pq(std::size_t capacity, int empty_value = -1) : m_capacity(capacity), m_last_index(0), empty_value(empty_value) { heap.resize(m_capacity, empty_value); }
        bool is_empty() { return m_capacity == 0; }
        std::size_t get_capacity() { return m_capacity; }
        void insert(int x) {
            m_last_index++;
            if (m_last_index == m_capacity) {
                heap.push_back(x);
                m_capacity = heap.capacity();
            }
            else {
                heap[m_last_index] = x;
            }
            swim(m_last_index);//heapify
        }
        void show() { for (int i = 0;i <= m_last_index;++i)std::cout << heap[i] << " "; }

        void deletemax() {
            if (m_last_index == 0) {
                // Heap is empty
                return;
            }

            int c_idx = 1;
            swap(heap[1], heap[m_last_index]);
            std::clog << "Deleted " << heap[m_last_index] << " at index " << m_last_index << std::endl;
            heap[m_last_index] = empty_value;
            m_last_index--;

            while (2 * c_idx <= m_last_index) {
                int max_child_idx = 2 * c_idx; // Start with the left child
                if (2 * c_idx + 1 <= m_last_index && heap[2 * c_idx + 1] > heap[2 * c_idx]) {
                    max_child_idx = 2 * c_idx + 1; // Right child is greater
                }

                if (heap[c_idx] >= heap[max_child_idx]) {
                    break; // The heap property is restored
                }

                std::clog << "Max child is " << heap[max_child_idx] << " at " << max_child_idx << std::endl;
                swap(heap[c_idx], heap[max_child_idx]);
                c_idx = max_child_idx;
            }
        }

        ~max_pq() = default;
    private:
        void swim(int idx) {
            int k = (idx / 2);
            while (k > 0 && heap[k] < heap[idx])
            {
                swap<int>(heap[idx], heap[k]);
                idx = k;
                k /= 2;
            }
        }
    };

};

#endif