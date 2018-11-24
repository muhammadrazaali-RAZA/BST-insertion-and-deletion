#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node
{
  int info;
  node *left,*right;
};
class bin_search_tree
{
   private :
	    node *temp;
   public  :
	    node *root;
	    int number;
	    bin_search_tree();
	    ~bin_search_tree();
	    void options();
	    void b_search_tree(node *);
	    void in_order(node *);
	    void b_delete(node *);
	    void destory(node *);
		
};
int main()
{
  char ch;
  bin_search_tree obj;
  while( 4 )
  {
    obj.options();
    ch=getch();
    switch(ch)
     {
       	case '0':
			exit(0);
			break;
		
		case '1':
			obj.in_order(obj.root);
			break;
			
		case '2':
			cout<<"\n Enter number to add in a tree... \n";
			cin>>obj.number;
			obj.b_search_tree( obj.root );
			break;
		
		case '3':
			cout<<"\n Enter number to delete in a tree... \n";
			cin>>obj.number;
			obj.b_delete(obj.root);
			break;
		case '4':
			//cout<<"\n Destory all tree tree... \n";
			//cin>>obj.number;
			//obj.destory(obj.root);
			break;
       	default :
			exit(0);
			break;
     } // end of switch.
  } // end of while.
}//-----------------------------------------------

bin_search_tree :: bin_search_tree()
{
  root=temp=NULL;
}
//--------------------------------------------------------
void bin_search_tree :: b_search_tree(node *temp)
{
  if( root==NULL )
   {
     temp=new node;
     temp->info = number;
     temp->left=NULL;
     temp->right=NULL;
     root=temp;
     return;
   }

  	if( temp->info==number )
   	{
      cout<<" \n Given number is already present in tree.\n";
      return;
    }
	if(temp->info > number)
	{
    	if( temp->left!=NULL )
       	{
			b_search_tree(temp->left);
		 	return;
       	}
      	else
       	{
	 		temp->left=new node;
	 		temp->left->info = number;
	 		temp->left->left=NULL;
	 		temp->left->right=NULL;
	 		return;
       	}
   	}
   	if(temp->info < number)
   	{
		if( temp->right!=NULL )
       	{
			b_search_tree( temp->right );
			return;
       	}
      	else
       	{
	 		temp->right=new node;
	 		temp->right->info = number;
	 		temp->right->left=NULL;
	 		temp->right->right=NULL;
	 		return;
       	}
   	}

} //--------------------    Insertion Function  Ends    --------------------------

//----------------------- Deletting Function Start  ----------------------

void bin_search_tree::b_delete(node *temp){
	if(temp==NULL)
		return;
		
		
	///////////////////  ----------------  Root  ------------------   ////////////////////////
	
	if(root->info == number){
		if(root->left==NULL && root->right==NULL){            // ----------- Case 1 Start ----------
			delete root;
			root=NULL;
			return;
		}													    		 // ----------- Case 1 Ends  ----------
		if(root->left!=NULL && root->right==NULL){           // ----------- Case 2 Start ----------
			node *t;
			t=root;
			root=t->left;
			delete t;
			return;
		}
		if(root->left==NULL && root->right!=NULL){
			node *t;
			t=root;
			root=t->right;
			delete t;
			return;
		}																// ----------- Case 2 Ends -----------
		if(root->left!=NULL && root->right!=NULL){          // ----------- Case 3 Start ----------
			node *t=root->right;
			if(t->left!=NULL){
				while(t->left->left!=NULL){
					t=t->left;
				}
				root->info=t->left->info;
				number=t->left->info;
				b_delete(t);
				return;
			}
			root->info=t->info;
			number=t->info;
			root->right=t->right;
			delete t;
			return;
		}																// ----------- Case 3 Ends ------------
	}
	
	///////////////////  ----------------  Root  ------------------   ////////////////////////	
	
				
	if(temp->info > number){
		if(temp->left->info == number){
			if(temp->left->left==NULL && temp->left->right==NULL){            // ----------- Case 1 Start ----------
				delete temp->left;
				temp->left=NULL;
				return;
			}													    		 // ----------- Case 1 Ends  ----------
			if(temp->left->left!=NULL && temp->left->right==NULL){           // ----------- Case 2 Start ----------
				node *t;
				t=temp->left;
				temp->left=t->left;
				delete t;
				return;
			}
			if(temp->left->left==NULL && temp->left->right!=NULL){
				node *t;
				t=temp->left;
				temp->left=t->right;
				delete t;
				return;
			}																// ----------- Case 2 Ends -----------
			if(temp->left->left!=NULL && temp->left->right!=NULL){          // ----------- Case 3 Start ----------
				node *t=temp->left->right;
				if(t->left!=NULL){
					while(t->left->left!=NULL){
						t=t->left;
					}
					temp->left->info=t->left->info;
					number=t->left->info;
					b_delete(t);
					return;
				}
				temp->left->info=t->info;
				number=t->info;
				b_delete(temp->left);
				return;
			}																// ----------- Case 3 Ends ------------
		}else{
			b_delete(temp->left);
			return;
		}
	}else{
		if(temp->right->info == number){
			if(temp->right->left==NULL && temp->right->right==NULL){        // ----------- Case 1 Start ----------
				delete temp->right;
				temp->right=NULL;
				return;
			}				   	        								   // ----------- Case 1 Ends  ----------
			if(temp->right->left!=NULL && temp->right->right==NULL){           // ----------- Case 2 Start ----------
				node *t;
				t=temp->right;
				temp->right=t->left;
				delete t;
				return;
			}
			if(temp->right->left==NULL && temp->right->right!=NULL){
				node *t;
				t=temp->right;
				temp->right=t->right;
				delete t;
				return;
			}																// ----------- Case 2 Ends -----------
			if(temp->right->left!=NULL && temp->right->right!=NULL){          // ----------- Case 3 Start ----------
				node *t=temp->right->right;
				if(t->left!=NULL){
					while(t->left->left!=NULL){
						t=t->left;
					}
					temp->right->info=t->left->info;
					number=t->left->info;
					b_delete(t);
					return;
				}
				temp->right->info=t->info;
				number=t->info;
				b_delete(temp->right);
				return;
			}																// ----------- Case 3 Ends ------------
		}else{
			b_delete(temp->right);
			return;
		}
	}
	cout<<"no number exits"<<endl;
	return;
}//----------------------- Deletting Function Ends  -----------------------




//----------------------- destory tree Function Starts  -----------------------

bin_search_tree::~bin_search_tree(){
	destory(root);
	cout<<"Done "<<endl;
}

void bin_search_tree::destory(node *temp){
	if(temp->left!=NULL && temp->right!=NULL){
		destory(temp->left);
		destory(temp->right);
		delete temp;
		temp=NULL;
		return;
	}

	
	else if(temp->left!=NULL && temp->right==NULL){
		destory(temp->left);
		delete temp;
		temp=NULL;
		return;
	}

	else if(temp->left==NULL && temp->right!=NULL){
		destory(temp->right);
		delete temp;
		temp=NULL;
		return;
	}
	
	else{
		delete temp;
		temp=NULL;
		return;
	}
	root=NULL;
}

//----------------------- destory tree Function Ends  -----------------------

void bin_search_tree :: options()
{
 	cout<<"\n\n ************** Select Option *****************.\n";
 	cout<<"\n Enter any of choices.\n";
 	cout<<"\n 0 : Quitting the Program.\n";
 	cout<<"\n 1 : Print the whole BST .\n";
 	cout<<"\n 2 : Adding (inserting) node in BST.\n";
 	cout<<"\n 3 : Deletting (deleshion) node in BST.\n";
 	cout<<"\n 4 : Destory all tree tree...\n";
}//--------------------------------------------------------------
void bin_search_tree :: in_order(node *temp)
{
  if(root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  if( temp->left!=NULL )
    		 in_order(temp->left);
  cout<<temp->info<<"  ";
  if( temp->right!=NULL )
		 in_order(temp->right);
  return;
}//----------------------------    PROGRAM ENDS HERE  ---------------------------------------



