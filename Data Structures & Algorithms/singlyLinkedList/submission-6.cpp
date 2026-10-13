class Node {
public:
    int data;
    Node* next;
    Node(int val)  {
        this->data = val;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {
        if (index < 0) return -1;
        Node* listHead = head;
        while(listHead && index > 0) {
            listHead = listHead->next;
            index--;
        }
        if(listHead)    {
            return listHead->data;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = head;
        head = newHead;
    }
    
    void insertTail(int val) {
        if(!head)   {
            head = new Node(val);
            return;
        }
        Node* tail = new Node(val);
        Node* iterator = head;
        while(iterator->next) {
            iterator = iterator->next;
        }
        iterator->next = tail;
    }

    bool remove(int index) {
        if(!head || index < 0) return false;
        
        if(index == 0)  {
            Node* temp = head; 
            head = head->next; 
            delete temp;       
            return true;
        }
        
        Node* iterator = head;
        Node* prev = nullptr;
        
        // FIXED: Loop safely up to the index, ensuring iterator doesn't become null
        while(iterator && index > 0)    {
            prev = iterator;
            iterator = iterator->next;
            index--;
        }
        
        // FIXED: If iterator is null, it means index was completely out of bounds!
        if(!iterator) {
            return false;
        }
        
        // Safely bridge the gap and delete the isolated node
        prev->next = iterator->next;
        delete iterator; 
        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node* iterator = head;
        while(iterator) {
            result.push_back(iterator->data);
            iterator = iterator->next;
        }
        return result;
    }
};