
//Name: Isac Canedo

#include<iostream>
#include<math.h>

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

//Binary Serach Tree class
class BST 
{
   public:
   BSTNode *root;
   int levcount;
   
   BST()
   {
        root=NULL;
        levcount=0;
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
         
        cout<<"\nIf you want to know whether the tree is perfectly balanced or not, press '1'\nChoice: ";  
        cin>>c;
         
        switch(c) 
        { 
             
           case 1:
               cout << endl; 
               if(IsBalanced(root)==true) 
                 cout << "Tree is perfectly Balanced." << endl;
               else 
                 cout << "Tree is not perfectly Balanced." << endl;
               break;
           default: 
               cout << endl << "Not a valid choice." << endl;     
        } 
   }
    
   //Function to calculate height of the tree 
   int Height(BSTNode *t)
   {
       int lheight=-1,rheight=-1;
       if(t==NULL)
          return 0;
       else
       {
          
          if(t->right!=NULL)
          {
             lheight=Height(t->left);
          }
          if(t->left!=NULL)
          {
             rheight=Height(t->right);
          }
          
         
          if(rheight>lheight)
             return (rheight+1);
          else
             return (lheight+1);
       }
   }
   
   
   //Function to count the nodes of each level of tree
   //We will use this function in our IsBalanced() function later.
   int Count_Level_nodes(BSTNode *t,int level,int current_level=0)
   {
       if(t!=NULL)
       {
          if(level == current_level)
             levcount++;
          else
          {
             Count_Level_nodes(t->left,level,current_level+1);
             Count_Level_nodes(t->right,level,current_level+1);
          }
       }
       
       return levcount;
   }
   


   
   //Function to check whether the tree is perfectly balanced or not.
   bool IsBalanced(BSTNode *t)
   {
        int level=0;
        
        if(t==NULL)
          return true;
        
        bool isbal;
        isbal=true;
              
        while(level<(Height(t)-1))
        {         
            if((int) pow(2,level)!=Count_Level_nodes(t,level))  //Checking the specified condition.
            {   
               isbal = false;
               break;
            }
            
            level++;
        }
        
        return isbal;
   }
   
};

//Main Function
int main()
{
    BST B1;
    
    int data[]={8,6,9,5,7,10};
        for(int i=0;i<7;i++)
           B1.insert(data[i]);
           
        B1.Choice();
    
    
    system("pause");
    return 0;
} 
            
