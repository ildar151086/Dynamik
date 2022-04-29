#include<iostream>


using namespace std;

class First {
public:
	int* arr;
	int size;

	First(int valueSize){
		size = valueSize;
		arr = new int[size];		
		for (int i = 0; i < size; i++) {
			*(arr + i) = rand() % 10 + 1;
		}
		//cout << "\nКонструктор" << endl;
		cout << "\nВыделили память под массвссылка c адресом\t" << arr << endl;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << *(arr + i) << " ";
		}
		cout << endl;
	}

	First &operator= ( First const &second) {
		//cout << "Оператор копирования" << endl;
		cout << "\nУдалили память под массив c адресом\t" << arr << endl;
		delete[] arr;

		arr = new int[second.size];
		size = second.size;

		//cout << "\nКонструктор" << endl;
		cout << "\nВыделили память под массив c адресом\t" << arr << endl;

		for (int i = 0; i < second.size; i++) {
			// Переприсваевыем занчения массива
			*(arr + i) = *(second.arr + i);
		}

		return *this;
	}

	 First &operator+ (First const &second) {
		
		First temp(size + second.size);

		for (int i = 0; i < second.size; i++) {
			temp.arr[i] = *(second.arr + i);
		}

		for (int i = 0; i < size; i++) {
			temp.arr[i + second.size] = *(arr + i);
		}

		return temp;
	}

	 void plusDynamik (First const &first, First const &second) {

		 //First temp(first.size + second.size);
		 cout << "Удалили память под массв c адресом\t" << arr << endl;
		 delete[] arr;

		 size = second.size + first.size;

		 arr = new int[size];
		 cout << "Выделили память под массв c адресом\t" << arr << endl;

		 for (int i = 0; i < second.size; i++) {
			 arr[i] = *(second.arr + i);
		 }

		 for (int i = 0; i < first.size; i++) {
			 arr[i + second.size] = *(first.arr + i);
		 }
	 }

	~First() {
			//cout << "\nДеструктор" << endl;
			cout << "Удалили память под массв c адресом\t" << arr << endl;
			delete[] arr;
	}

};




int main() {
	setlocale(LC_ALL, "RUS");
	int size = 10;

	First first(size * 3), second(size), summ(1);
	first.print();
	second.print();

	//summ = first + second;
	summ.plusDynamik(first, second);

	summ.print();

	return 0;
}