#include <iostream>
#include <algorithm>
using namespace std;

//Ŭ���� ���� �̸��� SimpleVector
template <typename T>//���ø� ����� ���� �߰�.
class SimpleVector {
private:
    T* data;//���ø� Ÿ�� data
    //�ٸ� ������ �߰�.
    int currentSize;
    int currentCapacity;
public:
    //������ �Ű����� X
    SimpleVector() {
        data = new T[10];
        this->currentSize = 10;
        this->currentCapacity = 0;
    }
    //������ �Ű����� : ũ��
    SimpleVector(int capacity) {
        data = new T[capacity];
        this->currentSize = capacity;
        this->currentCapacity = 0;
    }

    //������ �Ű����� : �ٸ� ����
    SimpleVector(const SimpleVector& other) {
        data = new T[other.currentSize];
        for (int i = 0; i < other.currentCapacity; i++) {
            data[i] = other.data[i];
        }
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
    }


    //�Ҹ���. ������ �迭 ����
    ~SimpleVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        //���� ���� ������ ��ü ������� ���ٸ�
        if (currentCapacity >= currentSize) {
            // ũ�Ⱑ 5 ū ���� ����
            SimpleVector<T> newdata(currentSize + 5);
            // ���� ������ �� ���ο� ���Ϳ� �ֱ�
            for (int i = 0; i < currentCapacity; i++) {
                newdata.data[i] = data[i];
            }
            newdata.currentCapacity = currentCapacity;
            // ���ο� �� �߰�.
            newdata.push_back(value);
            // ���� �迭 ����
            delete[] data;

            //data ��ü
            data = newdata.data;
            currentSize = newdata.currentSize;
            currentCapacity = newdata.currentCapacity;

            // newdata�� �Ҹ��ڿ��� �迭 �������� �ʵ��� null ó��
            newdata.data = nullptr;
        }

        //���� ������ ���ٸ�
        else if (currentCapacity <= 0) {
            //���� ������ 0���� �����
            currentCapacity = 0;
            //���� �ְ�
            data[currentCapacity] = value;
            //���� ���� �ø���
            currentCapacity++;
        }
        else {
            //���� �ְ�
            data[currentCapacity] = value;
            //���� ���� �ø���
            currentCapacity++;
        }
    }

    void pop_back() {
        //���� ���� ������ ��ü ������� ���ٸ�
        if (currentCapacity <= 0) {

        }
        //���� ������ ���ٸ�
        else if (currentCapacity >= currentSize - 1) {
            //���� ������ �迭 ũ��� �����
            currentCapacity = currentSize - 1;
            //���� �����ϰ�
            data[currentCapacity] = T();
            //���� ���� ���̱�
            currentCapacity--;
        }
        else {
            //���� �����ϰ�
            data[currentCapacity] = T();
            //���� ���� ���̱�
            currentCapacity--;
        }
    }

    void resize(int newCapacity) {
        cout << "change size " << currentSize << " -> " << newCapacity << endl;
        if (currentSize < newCapacity) {
            // ũ�� ������ ���� ����
            SimpleVector<T> newdata(newCapacity);
            // ���� ������ �� ���ο� ���Ϳ� �ֱ�
            for (int i = 0; i < currentCapacity; i++) {
                newdata.data[i] = data[i];
            }
            newdata.currentCapacity = currentCapacity;
            // ���� �迭 ����
            delete[] data;
            //data ��ü
            data = newdata.data;
            currentSize = newdata.currentSize;
            currentCapacity = newdata.currentCapacity;

            // newdata�� �Ҹ��ڿ��� �迭 �������� �ʵ��� null ó��
            newdata.data = nullptr;
        }
    }

    void sortData() {
        sort(data,  data + currentCapacity);
    }

    int size() {
        return currentSize; 
    }

    int capacity() {
        return currentCapacity;
    }
    void print() {
        for (int i = 0; i < currentCapacity; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

};


int main() {
    SimpleVector<int> vec(3);
    std::cout << "push_back 3:" << std::endl;
    vec.push_back(30);
    vec.push_back(20);
    vec.push_back(10);

    vec.print();

    SimpleVector<int> copyvec(vec);
       
    std::cout << "copyvec :" << std::endl;

    copyvec.print();
    std::cout << "Before resize:" << vec.size() << std::endl;
    vec.resize(4);
    std::cout << "After resize:" <<vec.size()<< std::endl;

    vec.push_back(40);

    vec.push_back(50);

    std::cout << "push_back 5:" << std::endl;
    vec.print();

    vec.sortData();

    std::cout << "After sort Data:" << std::endl;
    vec.print();

    return 0;
}


