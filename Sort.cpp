#include <bits/stdc++.h>
#include <chrono>

using namespace std;

const int StartNumber = 1000;
const int EndNumber = 1000000;
const int Upgrade = 1000;
const int MaxNumber = 1000000;

typedef std::chrono::duration<double, std::milli> milli_sec_t;

class Array
{
private:
    int *val;
    int size;

public:
    Array(const int size) : size(size)
    {
        val = new int[size];
    }
    Array(const Array &t)
    {
        this->size = t.size;
        this->val = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->val[i] = t.val[i];
    }
    ~Array()
    {
        delete[] val;
    }
    Array &operator=(Array &t)
    {
        this->size = t.size;
        if (this->val != nullptr)
            delete[] this->val;

        this->val = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->val[i] = t.val[i];

        return *this;
    }

public:
    void get_element();
    void get_Random_element();
    void Quick_sort(int l, int r);
    void Heap_sort();
    void Merge_sort(int l, int r);
    void Print();
};

void Array::get_element()
{
    //printf("Please input all of the number:\n");
    for (int i = 0; i < this->size; i++)
        scanf("%d", &this->val[i]);
}
void Array::get_Random_element()
{
    for (int i = 0; i < this->size; i++)
        this->val[i] = rand() % MaxNumber;
}
void Array::Quick_sort(int l, int r)
{
    int mid = this->val[(l + r) >> 1];
    int i = l, j = r;
    do
    {
        while (this->val[i] < mid)
            i++;
        while (this->val[j] > mid)
            j--;
        if (i <= j)
        {
            swap(this->val[i], this->val[j]);
            i++, j--;
        }
    } while (i <= j);
    if (l < j)
        this->Quick_sort(l, j);
    if (i < r)
        this->Quick_sort(i, r);
}
void Array::Heap_sort()
{
    priority_queue<int> Heap;
    for (int i = 0; i < this->size; i++)
        Heap.push(this->val[i]);

    while (!Heap.empty())
    {
        // printf("%d ",Heap.top());
        Heap.pop();
    }
}
void Array::Merge_sort(int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;
    Merge_sort(l, mid);
    Merge_sort(mid + 1, r);

    int i = l, k = l, j = mid + 1;
    int ii[EndNumber];

    while (i <= mid && j <= r)
    {
        if (val[i] > val[j])
        {
            ii[k] = val[j];
            k++, j++;
        }
        else
        {
            ii[k] = val[i];
            k++, i++;
        }
    }
    while (i <= mid)
    {
        ii[k] = val[i];
        i++, k++;
    }
    while (j <= r)
    {
        ii[k] = val[j];
        j++, k++;
    }
    for (int i = l; i <= r; i++)
        val[i] = ii[i];
}
void Array::Print()
{
    for (int i = 0; i < this->size; i++)
        printf("%d ", this->val[i]);
    puts("");
}

void Solve()
{
    //printf("Please input the amount of the number to sort:\n");
    FILE *fp = fopen("TimeOut.csv", "w");

    srand(time(0));
    //auto start_time, end_time;
    for (int i = StartNumber; i <= EndNumber; i += Upgrade)
    {
        Array A(i), B(i), C(i);
        A.get_Random_element();
        B = A, C = A;

        auto start_time = std::chrono::steady_clock::now();
        A.Quick_sort(0, i - 1);
        auto end_time = std::chrono::steady_clock::now();
        double Interval_qs = (std::chrono::time_point_cast<milli_sec_t>(end_time) - std::chrono::time_point_cast<milli_sec_t>(start_time)).count();

        start_time = std::chrono::steady_clock::now();
        B.Heap_sort();
        end_time = std::chrono::steady_clock::now();
        double Interval_hs = (std::chrono::time_point_cast<milli_sec_t>(end_time) - std::chrono::time_point_cast<milli_sec_t>(start_time)).count();

        start_time = std::chrono::steady_clock::now();
        C.Merge_sort(0, i - 1);
        end_time = std::chrono::steady_clock::now();
        double Interval_ms = (std::chrono::time_point_cast<milli_sec_t>(end_time) - std::chrono::time_point_cast<milli_sec_t>(start_time)).count();

        fprintf(fp, "%d,%.3lf,%.3lf,%.3lf\n", i, Interval_qs, Interval_hs, Interval_ms);
    }
    fprintf(fp, "\n");

    fclose(fp);
}

int main()
{
    Solve();

    return 0;
}
