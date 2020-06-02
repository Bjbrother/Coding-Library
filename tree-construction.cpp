

struct node
    {
         int data;                 //Data element
         struct node * left;          //Pointer to left node
         struct node * right;         //Pointer to right node
    };

struct node * newnode(int element)
    {
        struct node * temp=(node * )malloc(sizeof(node));
        temp->data=element;
        temp->left=temp->right=NULL;
        return temp;
    }

void insertBST(struct node*root,int data)
{
    
    if(data>root->data)
    {
        if(root->right==NULL)
        root->right=newnode(data);				
        else
        insertBST(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        root->left=newnode(data);
        else
        insertBST(root->left,data);
    }
}

void insertBST(node * root ,int x)
{
    node *p = root, *q = NULL;
    while(p != NULL)
    {
        q = p;
        if(p->data < x) p = p->right;
        else p = p->left;
    }
    
    if(q->data < x) q->right = newnode(x);
    else q->left = newnode(x);
}


struct node * insertLevelOrder(int arr[], node* root, int i, int n)                     
{ 
    if (i < n) 
    { 
        if(i!=0)
        {
                node* temp = newnode(arr[i]); 
                root = temp; 
        }
  
        // insert left child 
        root->left = insertLevelOrder(arr, 
                   root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insertLevelOrder(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
} 


int height(struct node* root,int count)
{
    if(root!=NULL)
    {
        count++;
        int h1=height(root->left,count);
        int h2=height(root->right,count);
        if(h2>h1)
        return h2;
        return h1;
    }
        return count;
}

struct node * find(struct node*root,int dest)
{
    if(root->data==dest)
    {
        return root;
    }
    else if(dest>root->data)
    {
        find(root->right,dest);
    }
    else
    {
        find(root->left,dest);
    }
}


void preorder(struct node*root)
    {
        if(root)
        {
          	cout<<root->data<<endl;    //Printf root->data
            preorder(root->left);    //Go to left subtree
            preorder(root->right);     //Go to right subtree
        }
    }

void postorder(struct node*root)
    {
        if(root)
        {
            postorder(root->left);    //Go to left sub tree
            postorder(root->right);     //Go to right sub tree
            cout<<root->data<<endl;    //Printf root->data   //Printf root->data
        }
    }


 void inorder(struct node*root)
    {
        if(root)
        {
            inorder(root->left);    //Go to left subtree
            cout<<root->data<<endl;    //Printf root->data
            inorder(root->right);     //Go to right subtree
        }
    }

void levelOrderTraversal(node *root)
{
    if(root==NULL)
    {
        return;
    }

    queue<node * >q;

    q.push(root);

    while(!q.empty())
    {
        node * tmp = q.front();
        q.pop();

        cout<<tmp->data<<endl;

        if(tmp->left!=NULL)
        {
            q.push(tmp->left);
        }
        if(tmp->right!=NULL)
        {
            q.push(tmp->right);
        }
    }

}





