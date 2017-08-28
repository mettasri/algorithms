struct node // a structure to represent tree nodes 
{
    char* key;
    int len;
    node* link;
    node* next;
    node(char* x, int n) : len(n), link(0), next(0) 
    { 
        key = new char[n]; 
        strncpy(key,x,n);       
    }
    ~node() { delete[] key; }
};

int prefix(char* x, int n, char* key, int m) // length of the biggest common prefix of x and key strings 
{
    for( int k=0; k<n; k++ )
        if( k==m || x[k]!=key[k] ) 
            return k;
    return n;
}

node* find(node* t, char* x, int n=0) // x key search in t tree 
{
    if( !n ) n = strlen(x)+1; 
    if( !t ) return 0;
    int k = prefix(x,n,t->key,t->len);
    if( k==0 ) return find(t->next,x,n); // let’s look for the child’s node 
    if( k==n ) return t;
    if( k==t->len ) return find(t->link,x+k,n-k); // let’s look for at the child’s node 
    return 0; 
}

void split(node* t, int k) // dividing t node according to k key symbol 
{
    node* p = new node(t->key+k,t->len-k);
    p->link = t->link;
    t->link = p;
    char* a = new char[k];
    strncpy(a,t->key,k);
    delete[] t->key;
    t->key = a;
    t->len = k;
}

node* insert(node* t, char* x, int n=0) // inserting x key in t tree 
{
    if( !n ) n = strlen(x)+1;
    if( !t ) return new node(x,n);
    int k = prefix(x,n,t->key,t->len);
    if( k==0 ) t->next = insert(t->next,x,n);
    else if( k<n )
    {
        if( k<t->len ) // cut or not to cut?
            split(t,k);
        t->link = insert(t->link,x+k,n-k);
    }
    return t;
}


void join(node* t) // t and t->link nodes merge
{
    node* p = t->link;
    char* a = new char[t->len+p->len];
    strncpy(a,t->key,t->len);
    strncpy(a+t->len,p->key,p->len);
    delete[] t->key;
    t->key = a;
    t->len += p->len;
    t->link = p->link;
    delete p;
}

node* remove(node* t, char* x, int n=0) // deleting x key from t tree 
{
    if( !n ) n = strlen(x)+1;
    if( !t ) return 0;
    int k = prefix(x,n,t->key,t->len);
    if( k==n ) // deleting a leaf
    {
        znode* p = t->next;
        delete t;
        return p;
    }
    if( k==0 ) t->next = remove(t->next, x, n);
    else if( k==t->len ) 
    {
        t->link = remove(t->link, x+k, n-k);
        if( t->link && !t->link->next ) // does t node have just one sister node?
            join(t);
    }
    return t;
}


