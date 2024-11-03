#include <iostream>
using namespace std;


class Node {
public:
    int data;      
    Node* next;     

   
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;  

public:
    
    LinkedList() {
        head = nullptr;
    }

   
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);  
        newNode->next = head;            
        head = newNode;                  
    }

   
    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        Node* newNode = new Node(data); 
        if (position == 1) {
            newNode->next = head;         
            head = newNode;               
            return;
        }

        Node* temp = head;
        
        for (int i = 1; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

      
        if (temp == nullptr) {
            cout << "Position is out of bounds." << endl;
            return;
        }

        newNode->next = temp->next;  
        temp->next = newNode;        
    }

   
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);  
        if (head == nullptr) {
            
            head = newNode;
        } else {
           
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;  
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

  
    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

      
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

      
        if (temp == nullptr) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        
        prev->next = temp->next;
        delete temp;
    }

  
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;  
            }
            temp = temp->next;
        }
        return false;  
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(40);

    cout << "Initial Linked List: ";
    list.display();

    list.insertAtBeginning(5); // Insert at the beginning
    cout << "After inserting 5 at the beginning: ";
    list.display();

    list.insertAtPosition(15, 2); // Insert at position 2
    cout << "After inserting 15 at position 2: ";
    list.display();

    list.insertAtPosition(25, 5); // Insert at position 5 (end)
    cout << "After inserting 25 at position 5: ";
    list.display();

    cout << "Deleting node with value 20" << endl;
    list.deleteNode(20);
    list.display();

    cout << "Searching for value 30: " << (list.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for value 40: " << (list.search(40) ? "Found" : "Not Found") << endl;

    return 0;
}
