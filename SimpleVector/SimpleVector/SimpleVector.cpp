#include <iostream>
#include <algorithm>
using namespace std;

//클래스 선언 이름은 SimpleVector
template <typename T>//템플릿 사용을 위한 추가.
class SimpleVector {
private:
    T* data;//템플릿 타입 data
    //다른 변수도 추가.
    int currentSize;
    int currentCapacity;
public:
    //생성자 매개변수 X
    SimpleVector() {
        data = new T[10];
        this->currentSize = 10;
        this->currentCapacity = 0;
    }
    //생성자 매개변수 : 크기
    SimpleVector(int capacity) {
        data = new T[capacity];
        this->currentSize = capacity;
        this->currentCapacity = 0;
    }

    //생성자 매개변수 : 다른 벡터
    SimpleVector(const SimpleVector& other) {
        data = new T[other.currentSize];
        for (int i = 0; i < other.currentCapacity; i++) {
            data[i] = other.data[i];
        }
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
    }


    //소멸자. 선언한 배열 삭제
    ~SimpleVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        //현재 내부 갯수가 전체 사이즈보다 많다면
        if (currentCapacity >= currentSize) {
            // 크기가 5 큰 벡터 생성
            SimpleVector<T> newdata(currentSize + 5);
            // 현재 데이터 값 새로운 벡터에 넣기
            for (int i = 0; i < currentCapacity; i++) {
                newdata.data[i] = data[i];
            }
            newdata.currentCapacity = currentCapacity;
            // 새로운 값 추가.
            newdata.push_back(value);
            // 현재 배열 제거
            delete[] data;

            //data 교체
            data = newdata.data;
            currentSize = newdata.currentSize;
            currentCapacity = newdata.currentCapacity;

            // newdata가 소멸자에서 배열 삭제하지 않도록 null 처리
            newdata.data = nullptr;
        }

        //내부 갯수가 없다면
        else if (currentCapacity <= 0) {
            //내부 갯수를 0으로 만들고
            currentCapacity = 0;
            //값을 넣고
            data[currentCapacity] = value;
            //내부 갯수 늘리기
            currentCapacity++;
        }
        else {
            //값을 넣고
            data[currentCapacity] = value;
            //내부 갯수 늘리기
            currentCapacity++;
        }
    }

    void pop_back() {
        //현재 내부 갯수가 전체 사이즈보다 많다면
        if (currentCapacity <= 0) {

        }
        //내부 갯수가 없다면
        else if (currentCapacity >= currentSize - 1) {
            //내부 갯수를 배열 크기로 만들고
            currentCapacity = currentSize - 1;
            //값을 삭제하고
            data[currentCapacity] = T();
            //내부 갯수 줄이기
            currentCapacity--;
        }
        else {
            //값을 삭제하고
            data[currentCapacity] = T();
            //내부 갯수 줄이기
            currentCapacity--;
        }
    }

    void resize(int newCapacity) {
        cout << "change size " << currentSize << " -> " << newCapacity << endl;
        if (currentSize < newCapacity) {
            // 크기 조장할 벡터 생성
            SimpleVector<T> newdata(newCapacity);
            // 현재 데이터 값 새로운 벡터에 넣기
            for (int i = 0; i < currentCapacity; i++) {
                newdata.data[i] = data[i];
            }
            newdata.currentCapacity = currentCapacity;
            // 현재 배열 제거
            delete[] data;
            //data 교체
            data = newdata.data;
            currentSize = newdata.currentSize;
            currentCapacity = newdata.currentCapacity;

            // newdata가 소멸자에서 배열 삭제하지 않도록 null 처리
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


