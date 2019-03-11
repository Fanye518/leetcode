class Node{
    private:
        int key,val;
        Node *prev,*next;
    public:
        Node(int k,int v):key(k),val(v),prev(NULL),next(NULL){}
        friend class LRUCache;
        friend ostream& operator<<(ostream& os, Node* head);
};

ostream& operator<<(ostream& os, Node* head){
    Node* tmp=head;
    while(tmp){
        os<<tmp->key;
        tmp=tmp->next;
    }
    return os;
}

class LRUCache {
    private:
    int capacity;
    Node *head,*tail;
    unordered_map<int,Node*>key_pos;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }
    void insertKey(int key, int value){
        // cout<<"insert:"<<key<<endl;
        Node *tmp = new Node(key,value);
        if(key_pos.size()==0){
            head = tmp;
            tail = head;
        }
        else{
            tail->next=tmp;
            tmp->prev=tail;
            tail=tmp;
        }
        key_pos[key]=tmp;
    }
    void deleteKey(){
        // cout<<"delete:"<<head->val<<endl;
        key_pos.erase(head->key);
        Node *tmp=head;
        head=head->next;
        delete tmp;
        // tmp=NULL;
        
    }
    void updateKey(int key){
        // cout<<"update:"<<key<<endl;
        if(head == tail)return ;
        Node *tmp=key_pos[key];
        if(tmp == head){
            head = head->next;
            head->prev=NULL;
            tail->next = tmp;
            tmp->prev=tail;
            tmp->next = NULL;
            tail = tmp;
        }
        else if(tmp != tail){
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tail->next = tmp;
            tmp->prev=tail;
            tmp->next = NULL;
            tail = tmp;
        }
    }
    
    int get(int key) {
        // cout<<"get("<<key<<")"<<endl;
        if(key_pos.find(key)==key_pos.end())return -1;
        updateKey(key);
        // cout<<head<<":"<<tail->val<<endl;
        return key_pos[key]->val;
    }
    
    void put(int key, int value) {
        // cout<<"put("<<key<<")"<<endl;
        if(key_pos.find(key)!=key_pos.end()){
            updateKey(key);
            key_pos[key]->val = value;
        }
        else{
            if(key_pos.size()<capacity){
                insertKey(key,value);
            }
            else{
                deleteKey();
                insertKey(key,value);
            }
        }
        // cout<<head<<":"<<tail->val<<endl;
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
