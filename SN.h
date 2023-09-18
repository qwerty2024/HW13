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
    struct Human { // ����� ��������
        Human();
        Human(const Name _name, int _id);
        Human& operator=(const Human& other);
        Human(const Human& other);

        bool operator==(const Human& other);

        Name name; // ���

        friend class SocialNetwork;

    public:
        int id; // ���������� id

    };
    SN();
    // ���������� ������ �������� � ����
    void addnewMan(const Name name);
    // �������� �������� �� ����
    void delMan(const Name name);
    // ��������� ������ ����� ����� ������
    void addFriendship(const Name name_1, const Name name_2);
    // �������� ������ ���
    void showThreeHandshakes();

private: // �������
    // ������ ��������?
    bool are_friends(const Human& m1, const Human& m2);
    // ���� �� ������� � man_id
    bool man_exists_with_id(int man_id);
    // ����� �� �����
    Human findManByName(const Name name);
private: // ���
    int friend_matrix[SIZE][SIZE]; // ������� ������
    StaticArray<Human> people; // ������ ����� ������ ����
    StaticArray<bool> busyids; // ������� id

};

