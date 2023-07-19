#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
typedef struct Node* listnode;
// cấp phát động 1 node mới với dữ liệu là số nguyên x;
listnode newNode(int x) {
    listnode temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    return temp;
}

// kiem tra rong:
bool empty(listnode head) {
    return head == nullptr;
}

// size
int size(listnode head) {
    int cnt = 0;
    while (head != nullptr)
    {
        ++cnt;
        head = head->next;
    }
    return cnt;   
}


// hiển thị các phần tử trong danh sách:
void showNode(listnode head) {
    while (head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

// chèn 1 phần tử vào đầu danh sách;
listnode insertFirst(listnode &head, int data) {
    listnode temp = newNode(data);
    if (head == nullptr) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    return head;
}

// chen phan tu vao cuoi danh sach:
listnode insertLast(listnode &head, int data) {
    listnode temp = newNode(data);
    listnode newnode = head;
    if (head == nullptr) {
        head = temp;
    } else {
        while (newnode->next != nullptr) {
            newnode = newnode->next;
        }
        newnode->next = temp;
    }
    return newnode;
}

// chen phan tu vao giua danh sach:
listnode insertMiddle(listnode &head, int data, int pos) {
    int n = size(head);
    listnode temp = newNode(data);
    listnode p = head;
    if (pos <=0 || pos > n-1) {
        cout<<"Vi tri chen ko hop le"<<endl;
    } else if (pos == 1) {
        insertFirst(head, data);
    } else if (pos == n-1) {
        insertLast(head, data);
    } else {
        for (int i = 1;i<pos-1;i++) {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    return p;
}

// xoa 1 phan tu o giua danh sach:
listnode deleteNode(listnode &a, int pos) {
    int n = size(a);

}

void menu() {
    cout<<"--------------Menu----------------"<<endl;
    cout<<"1. Chen phan tu vao dau danh sach"<<endl;
    cout<<"2. Chen phan tu vao cuoi danh sach"<<endl;
    cout<<"3. Chen phan tu vao giua danh sach"<<endl;
    cout<<"4. xoa 1 phan tu"<<endl;
    cout<<"5. in phan tu ra terminal"<<endl;
    cout<<"6. thoat menu"<<endl;
    cout<<"0. show menu"<<endl;
    cout<<"---------------------------------"<<endl;
    // cout<<"--------------Menu----------------"<<endl;
    // cout<<"--------------Menu----------------"<<endl;
}

int main() {
    listnode head = nullptr;

    menu();
    while (1)
    {
        int lc; cin>>lc;
        if (lc == 1) {
            int data; cout<<"nhap phan tu chen: "; cin>>data;
            insertFirst(head, data);
        } else if (lc == 2) {
            int data; cout<<"nhap phan tu chen: "; cin>>data;
            insertLast(head,data);
        } else if (lc == 3) {
            int data; cout<<"nhap phan tu chen: "; cin>>data;
            int pos; cout<<"nhap vi tri chen: "; cin>>pos;
            insertMiddle(head, data, pos);
        } else if (lc == 4) {
            // code
        } else if (lc == 5) {
            showNode(head);
        }else if (lc == 6) {
            return;
        } else if (lc == 0) {
            menu();
        }
    }
    
    return 0;
}