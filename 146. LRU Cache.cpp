class Node{
    private:
        int val;
        Node *prev,*next;
    public:
        Node(int v):val(v),prev(NULL),next(NULL){}
        friend class LRUCache;
        friend ostream& operator<<(ostream& os, Node* head);
};

ostream& operator<<(ostream& os, Node* head){
    Node* tmp=head;
    while(tmp){
        os<<tmp->val;
        tmp=tmp->next;
    }
    return os;
}

class LRUCache {
    private:
    int capacity;
    unordered_map<int,int> record;
    Node *head,*tail;
    unordered_map<int,Node*>key_pos;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }
    void insertKey(int key){
        // cout<<"insert:"<<key<<endl;
        Node *tmp = new Node(key);
        if(record.size()==0){
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
        key_pos.erase(head->val);
        Node *tmp=head;
        head=head->next;
        delete tmp;
        // tmp=NULL;
        
    }
    void updateKey(int key){
        // cout<<"update:"<<key<<endl;
        if(head == tail)return ;
        Node *tmp = key_pos[key];
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
        if(record.find(key)==record.end())return -1;
        updateKey(key);
        // cout<<head<<":"<<tail->val<<endl;
        return record[key];
    }
    
    void put(int key, int value) {
        // cout<<"put("<<key<<")"<<endl;
        if(record.find(key)!=record.end()){
            updateKey(key);
            record[key]=value;
        }
        else{
            if(record.size()<capacity){
                insertKey(key);
                record[key]=value;
            }
            else{
                record.erase(head->val);
                deleteKey();
                insertKey(key);
                record[key]=value;
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