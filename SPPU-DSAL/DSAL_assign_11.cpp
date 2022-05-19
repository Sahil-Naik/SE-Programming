#include<iostream>
#include<string>
using namespace std;

class NODE
{
public:
    string WORD;
    string MEANING;

    NODE *left, *right;

    NODE()
    {
        left = NULL;
        right = NULL;
    }

    NODE(string WORD, string MEANING)
    {
        this->WORD=WORD;
        this->MEANING=MEANING;
        left=NULL;
        right=NULL;
    }
};

class Dict
{
    NODE *root;
public:
    Dict()
    {
        root = NULL;
    }

    void Create_Node();
    bool Insert_Data(string word, string meaning);
    void Print_Data_A(NODE *P_nodes);
    void Print_Data_D(NODE *P_nodes);
    void Print()
    {
        string how;
        cout<<"\nA=Ascending\nD=Descending\nEnter how: ";
        cin>>how;
        if(how=="A" || how=="a")
        {
            cout<<"\nEntered elements are: "<<endl;
            Print_Data_A(root);
        }
        else if(how=="D" || how=="d")
        {
            cout<<"\nEntered elements are: "<<endl;
            Print_Data_D(root);
        }
        else
        {
            cout<<"\nInvalid Choice!";
        }
    }

    int Search(string word);
};

void Dict::Create_Node()
{
    int number;
    string key, meant;
    cout<<"\nHow many elements to insert: ";
    cin>>number;
    for(int i=0;i<number;i++)
    {
        cout<<"\nEnter Key: ";
        cin>>key;
        cout<<"Enter meaning: ";
        cin>>meant;
        Insert_Data(key,meant);
    }
}

bool Dict::Insert_Data(string word, string meaning)
{
    NODE *pointer = new NODE(word, meaning);
    if(root==NULL)
    {
        root = pointer;
        return true;
    }

    NODE *temp1 = root;
    NODE *temp2 = root;
    while(temp1!=NULL)
    {
        if(word>temp1->WORD)
        {
            temp2=temp1;
            temp1=temp1->right;
        }
        else if(word<temp1->WORD)
        {
            temp2=temp1;
            temp1=temp1->left;
        }
        else
        {
            cout<<"\nKey already Exist!";
            return false;
        }
    }
    if(word>temp2->WORD)
    {
        temp2->right=pointer;
        return true;
    }
    else
    {
        temp2->left=pointer;
        return true;
    }
}

void Dict::Print_Data_A(NODE *P_nodes)
{
    if(P_nodes)
    {
        Print_Data_A(P_nodes->left);
        cout<<P_nodes->WORD<<" : "<<P_nodes->MEANING<<endl;
        Print_Data_A(P_nodes->right);
    }
}

void Dict::Print_Data_D(NODE *P_nodes)
{
    if(P_nodes)
    {
        Print_Data_D(P_nodes->right);
        cout<<P_nodes->WORD<<" : "<<P_nodes->MEANING<<endl;
        Print_Data_D(P_nodes->left);
    }
}

int Dict::Search(string key)
{
    NODE *temp = root;
    int cnt;
    if(temp==NULL)
    {
        return -1;
    }
    if(root->WORD==key)
    {
        return 1;
    }
    while(temp!=NULL)
    {
        if((temp->WORD)>key)
        {
            temp=temp->left;
            cnt++;
        }
        else if((temp->WORD)<key)
        {
            temp=temp->right;
            cnt++;
        }
        else if((temp->WORD)==key)
        {
            return ++cnt;
        }
    }
    return -1;
}
int main()
{
    string key;
    string meant;
    string srch;
    string del;
    int chc;
    int exit=0;

    Dict DN;
    while(exit!=1)
    {
        cout<<"\n1 = Insert\t2 = Display\n3 = Search\t4 = Exit\nEnter Choice: ";
        cin>>chc;
        if(chc == 1)
        {
            DN.Create_Node();
        }
        else if(chc == 2)
        {
            DN.Print();
        }
        else if(chc == 3)
        {
            cout<<"Enter word to search: ";
            cin>>srch;
            int cmp = DN.Search(srch);
            if(cmp==-1)
            {
                cout<<"\nNo word found!"<<endl;
            }
            else
            {
                cout<<"\nWord found in "<<cmp<<" comparisons."<<endl;
            }
        }
        else if(chc == 4)
        {
            cout<<"\nExiting...\n";
            exit++;
        }
        else
        {
            cout<<"\nInvalid Choice!";
        }
    }
    return 0;
}
