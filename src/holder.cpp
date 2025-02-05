#include "../src/holder.h"

ostream& operator << (ostream & out, Stack & L){L.print(out); return out;}
// AS
ArrayStack::ArrayStack(int cap):Stack("ArrayStack"), capacity(cap), size(0), buf(new string[cap]){}
ArrayStack::~ArrayStack(){delete [] buf;}

void ArrayStack::print(ostream& out){
    for(int i=size-1; i>=0; --i){out<<buf[i]<<" ";} out<<"\n";}
string ArrayStack::top(){return buf[size-1];}
bool ArrayStack::is_empty(){return size==0;}
bool ArrayStack::is_full(){return size==capacity;}

void ArrayStack::push(const string & word){buf[size++] = word;}
void ArrayStack::pop(){--size;}

// AQ
ArrayQueue::ArrayQueue(int cap):Queue("ArrayQueue"),capacity(cap), front(0), rear(0), buf(new string[cap]){}
ArrayQueue::~ArrayQueue(){delete [] buf;}
string ArrayQueue::next(){return buf[front];}
bool ArrayQueue::is_empty(){return front==rear;}
bool ArrayQueue::is_full(){return (rear+1)%capacity==front;}

void ArrayQueue::enq(const string& word){ buf[rear]=word; rear=(rear+1)%capacity;}
void ArrayQueue::deq(){ front=(front+1)%capacity; }
void ArrayQueue::print(ostream & out){int i=front; for(; i != rear; i=(i+1)%capacity){out<<buf[i]<<" ";} }

// LS
LinkedStack::LinkedStack():Stack("LinkedStack"),head(nullptr){}

void ListNode::delete_list(ListNode * L){while(L!=nullptr){ListNode* temp=L; L=L->next; delete temp;}}
LinkedStack::~LinkedStack(){ListNode::delete_list(head);}

string LinkedStack::top(){return head->data;}
bool LinkedStack::is_empty(){return head==nullptr;}
bool LinkedStack::is_full(){return false;}
void ListNode::print(ostream& out, ListNode* L){for(ListNode* p=L;p!=nullptr;p=p->next){out<<p->data<<" ";} }
void LinkedStack::print(ostream& out){ListNode::print(out, head);}

void LinkedStack::push(const string& word){head = new ListNode(word, head);}
void LinkedStack::pop(){if(LinkedStack::is_empty()) return; ListNode* temp=head; head=head->next; delete temp;}


// LQ
LinkedQueue::LinkedQueue(): Queue("LinkedQueue"),head(nullptr), tail(nullptr){}

string LinkedQueue::next(){return head->data;}
bool LinkedQueue::is_empty(){return head==nullptr && tail==nullptr;}
bool LinkedQueue::is_full(){return false;}
void LinkedQueue::print(ostream & out){ListNode::print(out, head); }
LinkedQueue::~LinkedQueue(){ ListNode::delete_list(head); }

void LinkedQueue::enq(const string & word){
    ListNode* temp = new ListNode(word, nullptr);
    if(is_empty()){head=tail=temp;}
    else{tail->next=temp; temp->next=head; tail=temp;}}
void LinkedQueue::deq(){
    if(is_empty()) return;
    ListNode *temp = head;
    if(head==tail){head=tail=nullptr;}
    else{head=head->next;}
    delete temp;
}
    

void error(string word, string msg) {
    cerr << "Error Word: " << word << "\n"
         << "Error Message: " << msg << "\n"; }
void insert_all_words(int K, string file_name, Holder& L){
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = K * NWORDS / 10;
    t.start();
    for(string word; (in >> word) && limit > 0; --limit) { L.insert(word); }
    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tI = " << eTime << endl; 
    //all_words(L.name, eTime, 'i');
}

void remove_all_words(int K, string file_name, Holder& L){
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = K * NWORDS / 10;
    t.start();
    for(string word; (in >> word) && limit > 0; --limit) { L.remove(); }
    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tI = " << eTime << endl;
    //all_words(L.name, eTime, 'r');
    

    
    }
void measure_holder(string file_name, Holder& L) {
    cout << L.name << endl;
    for(int K = 1; K <= 10; ++K) {
        cout << "\tK = " << K << endl;
        insert_all_words(K, file_name, L);
        remove_all_words(K, file_name, L);
    } }

void measure_holders(string input_file) {

    ArrayStack as;
    ArrayQueue aq;
    LinkedStack ls;
    LinkedQueue lq;
    measure_holder(input_file, as);
    measure_holder(input_file, aq);
    measure_holder(input_file, ls);
    measure_holder(input_file, lq); 
}
