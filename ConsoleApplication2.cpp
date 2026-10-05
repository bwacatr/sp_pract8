#include <iostream>

using namespace std;

struct Track
{
    string title;
    string artist;
    int duration;

    void Info()
    {

        cout << "\n" << "название трека: " << title << endl;
        cout << "Имя исполнителя: " << artist << endl;
        cout << "Длительность: " << duration << "\n" << endl;
    }
};

struct Node
{
    Track track;
    Node* next;
    Node* prev;

    Node(Track song) : track(song), next(nullptr), prev(nullptr) {};


};

class LinkedList
{
private:
    Node* head = nullptr; //Начало списка
    Node* tail = nullptr; //Конец списка

public:

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    

    void clear()
    {
        if (head != nullptr)
        {
            cout << "\n \n Список очищается. \n" << endl;

            Node* node = head;
            Node* temp = head;
            while (node != nullptr)
            {
                temp = node;
                if (node->next != nullptr)
                {
                    node = node->next;
                }

                
                delete temp;

            }
        }
        else
        {
            cout << "\n \n Список пуст. \n" << endl;
        }
    }

    Node* Search(string title)
    {
        if (head == nullptr)
        {
            std::cout << "Нет данных" << std::endl;

            return nullptr;
        }
        Node* node = head;
        while (true)
        {
            
            if (title == node->track.title)
            {
                std::cout << "\n \n"  << "выдача указателя композиции: " << node->track.title << "\n" << std::endl;
                return node;
            }

            if (node->next == nullptr)
            {
                return nullptr;
            }
            else
            {
                node = node->next;
            }
        }
    }

    Node* SearchMaxDuration()
    {
        if (head == nullptr)
        {
            std::cout << "Нет данных" << std::endl;

            return nullptr;
        }
        Node* node = head;
        Node* nodeMax = nullptr;
        int maxDuration = 0;
        while (true)
        {
            int trackDuration = node->track.duration;
            if (maxDuration < trackDuration)
            {
                maxDuration = trackDuration;
                nodeMax = node;
            }

            if (node->next == nullptr)
            {
                std::cout << "\n \n" << "выдача самой длинной композиции в списке: " << node->track.title << "\n" << std::endl;
                return nodeMax;
            }
            else
            {
                node = node->next;
            }
        }
    }

    void DeleteNodesShorterThan(int duration)
    {
        if (head == nullptr)
        {
            std::cout << "Нет данных" << std::endl;

            return;
        }
        Node* node = head;
        Node* prevNode;
        Node* nextNode;

        while (true)
        {
            prevNode = node->prev;
            nextNode = node->next;
            int trackDuration = node->track.duration;

            if (trackDuration < duration)
            {
                std::cout << "\n \n" << node->track.title << " Удаляется" << "\n" << std::endl;

                
                if (prevNode == nullptr)
                {
                    nextNode->prev = nullptr;
                    
                }
                else if (nextNode == nullptr)
                {
                    prevNode->next = nullptr;

                }
                else
                {
                    nextNode->prev = prevNode;
                    prevNode->next = nextNode;
                }
                
                    
                

                delete node;

                if (nextNode != nullptr)
                {
                    node = nextNode;
                }
                else
                    break;
                
                
                
            }
            else if (nextNode != nullptr)
            {
                node = nextNode;
            }
            else
                break;

            
        }
    }

    void SwitchNodeWithHead(string title)
    {
        Node* switchedNode = Search(title);

        if (switchedNode != nullptr)
        {
            if (switchedNode != head)
            {


                if (head != nullptr)
                {
                    Node* switchedNodePrev = switchedNode->prev;
                    Node* switchedNodeNext = switchedNode->next;

                    Node* headPrev = head->prev;
                    Node* headNext = head->next;

                    Node* temp = head;

                    switchedNodePrev->next = temp;

                    if (switchedNodeNext != nullptr)
                    {
                        switchedNodeNext->prev = temp;
                    }
                    else
                    {
                        tail = temp;
                    }
                    

                    headNext->prev = switchedNode;
                    

                    switchedNode->next = headNext;
                    switchedNode->prev = headPrev;

                    head = switchedNode;

                    

                    temp->next = switchedNodeNext;
                    temp->prev = switchedNodePrev;

                    

                    


                }
            }
        }
        
    }

    void SearchDelete(string title)
    {
        if (head == nullptr)
        {
            std::cout << "Нет данных" << std::endl;

            return;
        }
        Node* node = head;
        while (true)
        {
            if (title == node->track.title)
            {
                std::cout << "\n \n" << node->track.title << " Удаляется" << "\n" << std::endl;

                if (node->prev != nullptr && node->next != nullptr)
                {
                    Node* prevNode = node->prev;
                    Node* nextNode = node->next;

                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                }
                
                delete node;
                break;
            }

            if (node->next == nullptr)
            {
                break;
            }
            else
            {
                node = node->next;
            }
        }
    }



    void pop_front()
    {
        if (head != nullptr)
        {
            Node* temp = nullptr;
            if (head->next != nullptr)
                temp = head->next;

            cout << "\n \n" << "Удаление композиции: " << head->track.title << "\n" << endl;

            delete head;

            

            if (temp != nullptr)
            {
                head = temp;
                head->prev = nullptr;
            }
            
        }
    }

    void pop_back()
    {
        if (tail != nullptr)
        {
            Node* temp = nullptr;
            if (tail->prev != nullptr)
                temp = tail->prev;

            cout << "\n \n" << "Удаление композиции: " << tail->track.title << "\n" << endl;

            delete tail;

            if (temp != nullptr)
            {
                tail = temp;
                tail->next = nullptr;
            }
            

        }
    }

    void display_backward()
    {
        if (tail == nullptr)
        {
            std::cout << "Нет данных" << std::endl;

            return;
        }
        Node* node = tail;
        while (true)
        {
            node->track.Info();
            if (node->prev == nullptr)
            {
                break;
            }
            else
            {
                node = node->prev;
            }
        }
    }

    void display_forward()
    {
        if (head == nullptr)
        {
            std::cout << "Нет данных" << std::endl;
           
            return;
        }
        Node* node = head;
        while (true)
        {
            node->track.Info();
            if (node->next == nullptr)
            {
                break;
            }
            else
            {
                node = node->next;
            }
        }
        //if (head != nullptr)
        //{
        //   // Node* node = head;

        //    /*while (true)
        //    {
        //        cout << node->track.title << endl;
        //        if (node->next == nullptr)
        //        {
        //            break;
        //        }
        //        else
        //        {
        //            node = node->next;
        //        }
        //    }*/
        //}
        //else
        //{
        //    cout << "Нет данных" << endl;
        //}





    }

    Node* push_front(Track song) //добавление в начало списка
    {
        Node* ptr = new Node(song); //выделение памяти под структуру Node

        Node* temp = nullptr;

        if (head == nullptr)
        {
            head = ptr;

        }
        else
        {
            
            temp = head;
            if (tail->prev == nullptr)
                tail->prev = temp;

            ptr->next = temp;
            temp->prev = ptr;
            
            head = ptr;



        }

        if (tail == nullptr)
        {
            tail = ptr;
        }
        

        return ptr;

    }

    Node* push_back(Track song) //добавление в начало списка
    {
        Node* ptr = new Node(song); //выделение памяти под структуру Node

        Node* temp = nullptr;

        /*if (tail == nullptr)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            temp = tail;
            head->next = temp;
            ptr->prev = temp;
            temp->next = ptr;
            tail = ptr;
        }

        return ptr;*/

        if (tail == nullptr)
        {
            tail = ptr;

        }
        else
        {

            temp = tail;
            if (head->next == nullptr)
                head->next = temp;
            ptr->prev = temp;
            temp->next = ptr;
            
            tail = ptr;



        }

        if (head == nullptr)
        {
            head = ptr;
        }


        return ptr;



    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    LinkedList list;

    Track track;

    cout << " \n \nВведите имя исполнителя, название композиции и её длительность \n" << endl;

    cin >> track.artist;
    cin >> track.title;
    cin >> track.duration;

    list.push_front(track);


    

    cout << " \n \nВведите имя исполнителя, название композиции и её длительность \n" << endl;

    cin >> track.artist;
    cin >> track.title;
    cin >> track.duration;

    list.push_front(track);

    list.display_forward();

    bool cont = true;
    while (cont)
    {
        cout << "\n\n1. Добавить элемент в начало\n" <<
            "2. Добавить элемент в конец\n" <<
            "3. Удалить первый элемент\n" <<
            "4. Удалить последний элемент\n" <<
            "5. Вывести список\n" <<
            "6. Вывести список в обратном порядке\n" <<
            "7. Найти элемент\n" <<
            "8. Найти самую длинную композицию №1\n" <<
            "9. Удалить композиции короче заданной продолжительности №2\n" <<
            "10. Переместить композицию в начало списка №3\n" <<
            "11. Выход\n\n" << endl;

        int choiceNum;
        cin >> choiceNum;

        switch (choiceNum)
        {
        case 1:
            

            cout << " \n \nВведите имя исполнителя, название композиции и её длительность \n" << endl;

            cin >> track.artist;
            cin >> track.title;
            cin >> track.duration;

            list.push_front(track);
            break;
        case 2:
            

            cout << " \n \nВведите имя исполнителя, название композиции и её длительность \n" << endl;

            cin >> track.artist;
            cin >> track.title;
            cin >> track.duration;

            list.push_back(track);
            break;
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            list.display_forward();
            break;
        case 6:
            list.display_backward();
            break;
        case 7:
            cout << " \n \nВведите название композиции \n" << endl;
            char title1[60];
            cin >> title1;
            list.Search(title1)->track.Info();
            break;
        case 8:
            list.SearchMaxDuration()->track.Info();
            break;
        case 9:
            cout << " \n \nВведите минимальную длительность композиции\n" << endl;
            int minDuration;
            cin >> minDuration;
            list.DeleteNodesShorterThan(minDuration);
            break;
        case 10:
            cout << " \n \nВведите название композиции \n" << endl;
            char title2[60];
            cin >> title2;

            list.SwitchNodeWithHead(title2);
            break;
        case 11:
            list.clear();
            cont = false;
            break;
        default:
            break;
        }
    }


    /*
    list.deleteNodes();*/
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
