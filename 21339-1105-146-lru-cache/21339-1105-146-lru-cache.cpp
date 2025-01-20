class LRUCache {
public:

    // firstly made a class for the node
    class node{
        public:
        int key;
        int value;
        node* next;
        node* prev;
        node(int key,int value){
            this->key=key;
            this->value=value;

        }
    };

    //map bana lo--> in ordeer to get the key and doubly linked list
    unordered_map<int,node*>mp;
    int capacity;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void insertAtHead(node* newNode){
        node* temp=head->next;
        head->next=newNode;
        newNode->next=temp;
        newNode->prev=head;
        temp->prev=newNode;
    }

    void deleteNode(node* newNode){
        node* prevNode=newNode->prev;
        node* nextNode=newNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){ //for checking whether the key exits in map or not
           return -1;
        }
        else{
            //node mil gaya hai ab usko starting par laga do
            node* newNode=mp[key];

            //ab uss node ko delete kar do or usko starting me attach kar do
            deleteNode(newNode);
            insertAtHead(newNode);
            return newNode->value;
        }
    }
    
    void put(int key, int value) {
        //if map me woh key pehle se present hai
        if(mp.find(key)!=mp.end()){ //it means that value is present
            
            node* newNode=mp[key];
            
            //ab uss node ko delete kar do or usko starting me attach kar do
            deleteNode(newNode);
            newNode->value = value;  // update value
            insertAtHead(newNode);
        }
        else{
            //agar map ka size capacity ke size ke barabar aa jaye uss case me sabse pehle jo aaya tha usko hata do
            if(mp.size()==capacity){
                node* lruNode=tail->prev;
                mp.erase(lruNode->key); //last node ko map se bhi remove kar dia
                deleteNode(lruNode);
            }
            node* newNode=new node(key,value);
            mp[key]=newNode;
            insertAtHead(newNode);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */