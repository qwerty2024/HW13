#pragma once
#define SIZE 50
#define NAMELENGTH 30

typedef char Name[NAMELENGTH];

template <class T>
class StaticArray {
public:
    StaticArray(int size = 0) {
        count = size;
        if (size > 0) {
            for (int i = 0; i < size; i++)
                array[i] = T();
        }
    }
    void add(T newval) {
        if (count < SIZE) {
            array[count++] = newval;
        }
    }
    void del(int index) {
        if (index < 0 || index >= count)
            return;
        count--;
        for (int i = index; i < count; i++) {
            array[i] = array[i + 1];
        }
    }
    T& operator [](int index) {
        if (index < 0 || index >= count)
            throw 0;
        return array[index];
    }

    int find(const T& val) {
        for (int i = 0; i < count; i++)
            if (array[i] == val)
                return i;
        return -1;
    }

    int size() {
        return count;
    }

private:
    T array[SIZE];
    int count;
};

class SN
{
public:
    struct Human { // класс человека
        Human();
        Human(const Name _name, int _id);
        Human& operator=(const Human& other);
        Human(const Human& other);

        bool operator==(const Human& other);

        Name name; // имя

        friend class SocialNetwork;

    public:
        int id; // внутренний id

    };
    SN();
    // добавление нового человека в сеть
    void addnewMan(const Name name);
    // удаление человека из сети
    void delMan(const Name name);
    // установка дружбы между двумя людьми
    void addFriendship(const Name name_1, const Name name_2);
    // алгоритм поиска пар
    void showThreeHandshakes();

private: // функции
    // ¤вл¤ютс¤ друзь¤ми?
    bool are_friends(const Human& m1, const Human& m2);
    // есть ли человек с man_id
    bool man_exists_with_id(int man_id);
    // поиск по имени
    Human findManByName(const Name name);
private: // пол¤
    int friend_matrix[SIZE][SIZE]; // матрица дружбы
    StaticArray<Human> people; // список людей внутри сети
    StaticArray<bool> busyids; // занятые id

};

