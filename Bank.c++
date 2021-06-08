#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
class Bank
{
private:
    int total;
    struct person
    {
        string Name, ID, Address;
        int Contact, Cash;
    } person[100];

public:
    Bank()
    {
        total = 0;
    }
    void Choice();
    void Perdata();
    void Show();
    void update();
    void search();
    void Transaction();
    void del();
};
void Bank::Choice()
{
    char ch;
    while (1)
    {
        cout << "\n\nPRESS...!!" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. View customers list" << endl;
        cout << "3. Update information of existing account" << endl;
        cout << "4. Check the details of an existing account" << endl;
        cout << "5. For transactions" << endl;
        cout << "6. Remove existing account" << endl;
        cout << "7. Exit" << endl;
        cout<<"Enter your Number : "<<endl;
        ch = getch();
        switch (ch)
        {
        case '1':
            Bank::Perdata();
            break;
        case '2':
            Bank::Show();
            break;
        case '3':
            Bank::update();
            break;
        case '4':
            Bank::search();
            break;
        case '5':
            Bank::Transaction();
            break;
        case '6':
            Bank::del();
            break;
        }
    }
}
void Bank::Perdata()
{
    cout << "Enter the data of Person " << total + 1 << endl;
    cout << "Enter Name :"<<endl;
    cin >> person[total].Name;
    cout << "Enter ID :"<<endl;
    cin >> person[total].ID;
    cout << "Enter Address :"<<endl;
    cin >> person[total].Address;
    cout << "Enter Contact :"<<endl;
    cin >> person[total].Contact;
    cout << "Enter Cash :"<<endl;
    cin >> person[total].Cash;
    total++;
}
void Bank::Show(){
    for (int i = 0; i < total; i++)
    {
        cout<<"Data of Person "<<i+1<<endl;
        cout<<"Name :"<<person[i].Name<<endl;
        cout<<"ID :"<<person[i].ID<<endl;
        cout<<"Address :"<<person[i].Address<<endl;
        cout<<"Contact :"<<person[i].Contact<<endl;
        cout<<"Cash :"<<person[i].Cash<<endl;
    }   
}
void Bank::update(){
    string id;
    cout<<"Enter ID of person whose Data you want to Update :"<<endl;
    cin>>id;
    for (int i = 0; i < total; i++)
    {
        if (id==person[i].ID){
            cout<<"Previous Data :"<<endl;
            cout<<"Name :"<<person[i].Name<<endl;
            cout<<"ID :"<<person[i].ID<<endl;
            cout<<"Address :"<<person[i].Address<<endl;
            cout<<"Contact :"<<person[i].Contact<<endl;
            cout<<"Cash :"<<person[i].Cash<<endl;
            cout<<"\nEnter new data :\n"<<endl;
            cout << "Enter Name :"<<endl;
            cin >> person[i].Name;
            cout << "Enter ID :"<<endl;
            cin >> person[i].ID;
            cout << "Enter Address :"<<endl;
            cin >> person[i].Address;
            cout << "Enter Contact :"<<endl;
            cin >> person[i].Contact;
            cout << "Enter Cash :"<<endl;
            cin >> person[i].Cash;
            break;
        }
        if (i==total-1){
        cout<<"No such Record Found"<<endl;
        }
    }
    
}
void Bank::search(){
    string id;
    cout<<"Enter ID of person whose Data you want to Search :"<<endl;
    cin>>id;
    for (int i = 0; i < total; i++)
    {
        if (id==person[i].ID)
        {
            cout<<"Data of Person "<<i+1<<endl;
            cout<<"Name :"<<person[i].Name<<endl;
            cout<<"ID :"<<person[i].ID<<endl;
            cout<<"Address :"<<person[i].Address<<endl;
            cout<<"Contact :"<<person[i].Contact<<endl;
            cout<<"Cash :"<<person[i].Cash<<endl;
            break;
        }
        if (i==total-1){
        cout<<"No such Record Found"<<endl;
        }
        
    }
    
}
void Bank::Transaction(){
    string id;
    char ch;
    int cash;
    cout<<"Enter ID of person who is doing transaction :"<<endl;
    cin>>id;
    for (int i = 0; i < total; i++)
    {
        if (id==person[i].ID)
        {
            cout<<"Name :"<<person[i].Name<<endl;
            cout<<"Address :"<<person[i].Address<<endl;
            cout<<"Contact :"<<person[i].Contact<<endl;
            cout<<"Existing Cash :"<<person[i].Cash<<endl;
            cout<<"Press 1 to deposit :"<<endl;        
            cout<<"Press 2 to withdraw :"<<endl; 
            ch=getch();
            switch (ch)
            {
            case '1':
                cout<<"How much cash you want to Deposit :"<<endl;
                cin>>cash;
                person[i].Cash=person[i].Cash+cash;
                cout<<"Your new cash is :"<<person[i].Cash<<endl;
                break;
            case '2':
                back:
                cout<<"How much cash you want to withdraw :"<<endl;
                cin>>cash;
                if (cash>person[i].Cash){
                    Sleep(2000);
                    cout<<"cash in your account is "<<person[i].Cash<<" enter less than that amount "<<endl;
                    goto back;
                }
                person[i].Cash=person[i].Cash-cash;
                cout<<"Your new cash is :"<<person[i].Cash<<endl;
                break;
            default:
                cout<<"Invalid Input"<<endl;
                break;
            }
        break;
        }
        if (i==total-1){
        cout<<"No such Record Found"<<endl;
        }
    }
    
}
void Bank::del(){
    char ch;
    string id;
    cout<<"Press 1 to remove specific record"<<endl; 
    cout<<"Press 2 to remove full record record"<<endl; 
    ch=getch();
    switch (ch)
    {
    case '1':
        cout<<"Enter ID of person whose specific data you want to delete : "<<endl;
        cin>>id;
        for (int i = 0; i < total; i++)
        {
            if (id==person[i].ID)   
            {
                for (int j = i; j < total; j++)
                {
                    person[j].Name=person[j+1].Name;
                    person[j].ID=person[j+1].ID;
                    person[j].Address=person[j+1].Address;
                    person[j].Contact=person[j+1].Contact;
                    person[j].Cash=person[j+1].Cash;
                    total--;
                }
                break;
            }
            if (i==total-1){
                cout<<"No such Record Found"<<endl;
            }   
        }
        break;
    
    case '2':
        total=0;
        cout<<"ALl data record is deleted"<<endl;
        break;
    default:
        cout<<"Invalid input"<<endl;
        break;
    }
    
}

int main() {
    Bank b;
    b.Choice();
    return 0;
}