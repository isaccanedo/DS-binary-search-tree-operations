
//Name: Isac Canedo

#include<iostream>
#include<cmath>

using namespace std;

//BSTNode class
class BSTNode
{
   public:
   int key;
   BSTNode *left, *right;
   
   BSTNode()
   {
      left=right=NULL;
   }
   BSTNode(int n, BSTNode *lft=NULL, BSTNode *r=NULL)
   {
       key=n;
       left=lft;
       right=r;
   }
};

//Binary Search Tree class
class BST 
{
   public:
   BSTNode *root;
   int nodecount,leafnodecount,nonleafnodecount;
   
   BST()
   {
        root=NULL;
        nodecount=0;
        leafnodecount=0;
        nonleafnodecount=0;
   }
   
   bool isEmpty() const
   {
        return root==NULL;
   }
   
   void visit(BSTNode* p)
   {
        cout<<p->key<<' ';
   }
   
   
   void insert(int el)
   {
        BSTNode *p=root, *prev=NULL;
        
        while(p!=NULL)
        {
            prev=p;
            if(p->key<el)
               p=p->right;
            else p=p->left;
        }
        
        if(root==NULL)
            root =new BSTNode(el);
        else if(prev->key<el)
            prev->right = new BSTNode(el);
        else prev->left = new BSTNode(el);
   }
   
   void Choice() 
   { 
        int c;
         
        cout<<"\n1.Find Height\n2.Count Nodes\n3.Count Leaf nodes\n4.Count NonLeaf nodes\n5.Count no. of right children\n6.Delete all leaf nodes\n7.Print nodes of a given level\nChoice: ";  
        cin>>c;
         
        switch(c) 
        { 
           case 1: 
              cout << endl << "Height of tree is " << Height(root) << endl; 
              break; 
           case 2: 
              cout << endl << "Number of nodes in tree is " << Count_Nodes(root) << endl; 
              break; 
           case 3: 
              cout << endl << "Number of leaf nodes in tree is " << Count_leafnodes(root) << endl; 
              break; 
           case 4: 
              cout << endl << "Number of non leaf nodes in tree is " << Count_Nonleafnodes(root) << endl; 
              break; 
           case 5: 
              cout << endl << "Number of nodes in right tree is " << Count_right_children(root) << endl; 
              break;
           case 6:
              cout << endl << "Inorder traversal of tree before deleting leaves" << endl;                       
              inorder(root);   
              delete_leaves(root);
              cout << endl << "Inorder traversal of tree after deleting leaves" << endl;
              inorder(root);
              break;
           case 7:
               int lev; 
               cout << endl << "Enter Level: ";
               cin >> lev;
               Print_Level_nodes(root,lev);
               break;
           default: 
               cout << endl << "Not valid choice." << endl;      
        } 
   }
   
   //Function to count total nodes in tree
   int Count_Nodes(BSTNode *t)
   {
        
        if(t!=NULL)
        {
            nodecount++;
            
            Count_Nodes(t->right);
            Count_Nodes(t->left);
        }
        
        return nodecount;
   }
   
   //Function to count leaf nodes in tree
   int Count_leafnodes(BSTNode *t)
   {
        
        if(t!=NULL)
        {
            if(!t->right && !t->left)
            {                            
               leafnodecount++;
            }
            else
            {
               Count_leafnodes(t->right);
               Count_leafnodes(t->left);
            }
        }
        
        return leafnodecount;
   }
   
   //Function to find height of tree
   int Height(BSTNode *t)
   {
       int rightheight=-1;
       int leftheight=-1;
       
       if(t!=NULL)
       {
           if(t->right!=NULL)
           {
               rightheight=Height(t->right);
           }
           if(t->left!=NULL)
           {
               leftheight=Height(t->left);
           }
           
           if(rightheight>leftheight)
           {
               return(rightheight+1);
           }
           else
           {
               return(leftheight+1);
           }
       }           
   }
   
   //Function to count nodes in right tree
   int Count_right_children(BSTNode *t)
   {
       Count_Nodes(t->right);
   }
   
   //Function to count non leaf nodes in tree
   int Count_Nonleafnodes(BSTNode *t)
   {
       if((t==NULL) || (t->right==NULL && t->left==NULL))
       {
           return 0;
       }
       else
       {
           nonleafnodecount++;
           Count_Nonleafnodes(t->right);
           Count_Nonleafnodes(t->left);
           
           return nonleafnodecount;
       }
   }
   
   //Inorder traversal of tree
   void inorder(BSTNode *p)
   {
       if(p!=NULL)
       {
          inorder(p->left);
          visit(p);  
          inorder(p->right);
       }        
   }       
   
   //Function to delete all leaf nodes in tree
   void delete_leaves(BSTNode *t)
   {
       BSTNode *temp=t;
       BSTNode *prev;
   
       if(temp!=NULL)
       { 
        prev=temp;
        
        if(temp->right)
        {
           temp=temp->right;
           
           if(temp->right || temp->left)
             delete_leaves(temp);
           else
           {  
             prev->right=NULL;
             delete temp;
           }
         }
         
         if(prev->left)
         {
           temp=prev->left;
           
           if(temp->right || temp->left)
             delete_leaves(temp);  
           else
           {
               prev->left=NULL;
               delete temp;
           }
         }
       }
   }
   
   //Function to print all nodes of the tree at given level
   void Print_Level_nodes(BSTNode *t,int level,int current_level=0)
   {
       if(t!=NULL)
       {
          if(level == current_level)
             visit(t);
          else
          {
             Print_Level_nodes(t->left,level,current_level+1);
             Print_Level_nodes(t->right,level,current_level+1);
          }
       }
   }
                                 
};

//Main Function   
int main()
{
    BST B1;
    
    int data[]={8,6,9,5,7,10,11};
        for(int i=0;i<7;i++)
           B1.insert(data[i]);
    B1.Choice();
    
    cout<<endl;
    
    system("pause");
    return 0;
} 
